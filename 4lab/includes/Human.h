#pragma once
#include "Mammal.h"
//  ласс "„еловек" Ч производный от Mammal
class Human : public Mammal {
	std::string profession;
public:
	Human(const std::string& name = "Unnamed", const std::string& profession
		= "None");
	virtual ~Human();
	void describe() const override;
};
