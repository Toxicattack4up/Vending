#pragma once
#include<vector>
#include "SnackSlot.h"

class VendingMachine
{
private:
	std::vector<std::vector<SnackSlot*>> slots;

public:
	VendingMachine(int row, int col);

	bool addSlot(int row, int col, SnackSlot* slot);

	int getEmptySlotsCount() const;
	void display();
	const std::vector<std::vector<SnackSlot*>>& getSlots() const;
};