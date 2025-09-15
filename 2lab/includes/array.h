#pragma once
#include <iostream>

using namespace std;

class MyArray {
private:
    int* data;
    int size;

public:
    MyArray(int s = 0);                    
    MyArray(const MyArray& other);         
    ~MyArray();                         

    MyArray& operator=(const MyArray& other);   
    MyArray operator+(const MyArray& other) const; 

    int getSize() const { return size; }

    friend istream& operator>>(istream& in, MyArray& arr);
    friend ostream& operator<<(ostream& out, const MyArray& arr);
};
