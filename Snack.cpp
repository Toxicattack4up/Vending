#include "Snack.h"

Snack::Snack(std::string name, int calories, double price)
		: name(name), calories(calories), price(price) {}

std::string Snack::getName() const
{
	return name;
}

int Snack::getCalories() const
{
	return calories;
}

double Snack::getPrice() const
{
	return price;
}
