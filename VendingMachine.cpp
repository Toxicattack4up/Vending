#include "VendingMachine.h"

VendingMachine::VendingMachine(int slotCount)
{
	slots.resize(slotCount, nullptr);
}

bool VendingMachine::addSlot(SnackSlot* slot)
{
	for (size_t i = 0; i < slots.size(); ++i)
	{
		if (slots[i] == nullptr)
		{
			slots[i] = slot;
			return true;
		}
	}
	return false;
}

int VendingMachine::getEmptySlotsCount() const
{
	int emptyCount = 0;
	for (const auto& slot : slots)
	{
		if (slot == nullptr)
		{
			++emptyCount;
		}
	}
	return emptyCount;
}
