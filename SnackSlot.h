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

	void addSnack(Snack* snack);
	void removeSnack();
	std::string getSnackName() const;
	int getSnackCalories() const;
	double getSnackPrice() const;
	bool isEmpty() const;
};