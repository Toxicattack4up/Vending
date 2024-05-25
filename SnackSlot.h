#pragma once
#include <vector>
#include "Snack.h"

class SnackSlot
{
private:
	std::vector<Snack*> snacks;
	int capacity;

public:
	SnackSlot(int capacity);

	bool addSnack(Snack* snack);

	bool isFull() const;

	int getSnackCount() const;
};