#include "CarFile.h"
#include <iostream>
#include <format>
#include <ios>

namespace {
    constexpr std::ios_base::openmode FILE_MODE = std::ios::in | std::ios::out | std::ios::binary | std::ios::app;
}

CarFile::CarFile(const std::string& fn)
    : fileStream_(nullptr), filename_(fn) {
    openFile(filename_);
}

CarFile::~CarFile() noexcept {
    closeFileSafely();
}

CarFile::CarFile(const CarFile& other)
    : filename_(other.filename_) {
    openFile(filename_);
}

CarFile& CarFile::operator=(const CarFile& other) {
    if (this != &other) {
        filename_ = other.filename_;
        openFile(filename_);
    }
    return *this;
}

CarFile::CarFile(CarFile&& other) noexcept
    : fileStream_(std::move(other.fileStream_)),
    filename_(std::move(other.filename_)),
    fileSize_(other.fileSize_) {
    other.fileSize_ = 0;
}

CarFile& CarFile::operator=(CarFile&& other) noexcept {
    if (this != &other) {
        fileStream_ = std::move(other.fileStream_);
        filename_ = std::move(other.filename_);
        fileSize_ = other.fileSize_;
        other.fileSize_ = 0;
    }
    return *this;
}

void CarFile::openFile(const std::string& filePath) {
    fileStream_ = std::make_unique<std::fstream>(filePath, FILE_MODE);
    validateFileOpen();
    fileStream_->seekg(0, std::ios::end);
    fileSize_ = static_cast<std::size_t>(fileStream_->tellg());
    fileStream_->seekg(0, std::ios::beg);
}

CarFile& CarFile::operator<<(const Car& car) {
    ensureFileIsOpen();
    fileStream_->seekp(0, std::ios::end);
    car.writeTo(*fileStream_);
    fileStream_->flush();
    if (!fileStream_->good()) {
        throw std::ios_base::failure("Failed to write car to file");
    }
    fileSize_ = static_cast<std::size_t>(fileStream_->tellp());
    return *this;
}

CarFile& CarFile::operator>>(Car& car) {
    ensureFileIsOpen();
    car.readFrom(*fileStream_);
    if (!fileStream_->good()) {
        fileStream_->setstate(std::ios::failbit);
    }
    return *this;
}

CarFile::operator bool() const {
    return fileStream_ && fileStream_->good();
}

int CarFile::countByYear(int year) {
    ensureFileIsOpen();
    fileStream_->clear();
    fileStream_->seekg(0, std::ios::beg);
    int count = 0;
    Car car;
    while (fileStream_->good()) {
        car.readFrom(*fileStream_);
        if (fileStream_->good() && car.year == year) {
            ++count;
        }
    }
    fileStream_->clear();
    return count;
}

void CarFile::showAll() {
    ensureFileIsOpen();
    fileStream_->clear();
    fileStream_->seekg(0, std::ios::beg);
    Car car;
    while (fileStream_->good()) {
        car.readFrom(*fileStream_);
        if (fileStream_->good()) {
            std::cout << car << std::endl;
        }
    }
    fileStream_->clear();
}

void CarFile::validateFileOpen() const {
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::ios_base::failure(std::format("Failed to open file '{}'", filename_));
    }
}

void CarFile::ensureFileIsOpen() const {
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::ios_base::failure("File is not open");
    }
}

void CarFile::closeFileSafely() noexcept {
    if (fileStream_) {
        try {
            fileStream_->exceptions(std::ios::goodbit);
            if (fileStream_->is_open()) {
                fileStream_->close();
            }
        }
        catch (...) {
            std::fputs("Warning: failed to close file.\n", stderr);
        }
    }
}