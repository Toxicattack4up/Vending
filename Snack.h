#pragma once
#include <string>

class Snack
{
private:
	std::string name;
	int calories;
	double price;
	
public:
	Snack(std::string name, int calories = 0, double price = 0.0);
	std::string getName() const;
	int getCalories() const;
	double getPrice() const;
};