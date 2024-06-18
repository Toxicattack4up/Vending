#include "SnackSlot.h"

SnackSlot::SnackSlot(int capacity) : capacity(capacity) {}

void SnackSlot::addSnack(Snack* snack)
{
	if (snacks.size() < capacity)
	{
		snacks.push_back(snack);
	}
}

void SnackSlot::removeSnack()
{
	if (!snacks.empty())
	{
		snacks.pop_back(); //Удаление снека
	}
}

std::string SnackSlot::getSnackName() const
{
	if (snacks.empty())
	{
		return "Пусто";
	}
	return snacks.back()->getName();
}

int SnackSlot::getSnackCalories() const
{
	if (snacks.empty())
	{
		return 0;
	}
	return snacks.back()->getCalories();
}

double SnackSlot::getSnackPrice() const
{
	if (snacks.empty())
	{
		return 0.0;
	}
	return snacks.back()->getPrice();
}

bool SnackSlot::isEmpty() const
{
	return snacks.empty();
}
