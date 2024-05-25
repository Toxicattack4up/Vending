#pragma once
#include<vector>
#include "SnackSlot.h"

class VendingMachine
{
private:
	std::vector<SnackSlot*> slots;

public:
	VendingMachine(int slotCount);
	bool addSlot(SnackSlot* slot);
	int getEmptySlotsCount() const;
};