#pragma once
#include<vector>
#include "SnackSlot.h"

class VendingMachine
{
private:
	std::vector<std::vector<SnackSlot*>> slots;

public:
	VendingMachine(int row, int cols);

	bool addSlot(int row, int cols, SnackSlot* slot);

	int getEmptySlotsCount() const;
	void display();
};