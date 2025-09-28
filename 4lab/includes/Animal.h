#pragma once
#include "Mammal.h"
// ����� "��������" � ����������� �� Mammal
class Animal : public Mammal {
protected:
	int age;
public:
	Animal(const std::string& name = "Unnamed", int age = 0);
	virtual ~Animal();
	// �� ��������� �������� ��� ������� �������� � ����� ��������������
	virtual void describe() const override;
	int getAge() const { return age; }
};