#include "VendingMachine.h"
#include <iostream>

VendingMachine::VendingMachine(int row, int col)
{
	slots.resize(row, std::vector<SnackSlot*>(col, nullptr));
}

bool VendingMachine::addSlot(int row, int col, SnackSlot* slot)
{
	if (row >= slots.size() || col >= slots[0].size())
	{
		return false;
	}

	if (slots[row][col] == nullptr)
	{
		slots[row][col] = slot;
		return true;
	}
	return false;
}

int VendingMachine::getEmptySlotsCount() const
{
	int emptyCount = 0;
	for (const auto& row : slots)
	{
		for (const auto& slot : row)
		{
			if (slot == nullptr)
			{
				++emptyCount;
			}
		}
	}
	return emptyCount;
}

void VendingMachine::display()
{
    for (const auto& row : slots)
    {
        for (const auto& slot : row)
        {
            if (slot != nullptr && !slot->isEmpty())
            {
                std::cout << slot->getSnackName() << "\t";
            }
            else
            {
                std::cout << "Empty\t";
            }
        }
        std::cout << std::endl;

        for (const auto& slot : row)
        {
            if (slot != nullptr && !slot->isEmpty())
            {
                std::cout << slot->getSnackPrice() << "\t";
            }
            else
            {
                std::cout << "\t";
            }
        }
        std::cout << std::endl;
    }
}

const std::vector<std::vector<SnackSlot*>>& VendingMachine::getSlots() const
{
    return slots;
}
