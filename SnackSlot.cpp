#include "SnackSlot.h"

SnackSlot::SnackSlot(int capacity) : capacity(capacity) {}

bool SnackSlot::addSnack(Snack* snack)
{
	if (snacks.size() < capacity)
	{
		snacks.push_back(snack);
		return true;
	}
	return false;
}

bool SnackSlot::isFull() const
{
	return snacks.size() >= capacity;
}

int SnackSlot::getSnackCount() const
{
	return snacks.size();
}
