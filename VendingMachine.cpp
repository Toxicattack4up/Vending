#include "VendingMachine.h"
#include <iostream>

VendingMachine::VendingMachine(int row, int cols)
{
	slots.resize(row, std::vector<SnackSlot*>(cols, nullptr));
}

bool VendingMachine::addSlot(int row, int cols, SnackSlot* slot)
{
	if (row >= slots.size() || cols >= slots[0].size())
	{
		return false;
	}

	if (slots[row][cols] == nullptr)
	{
		slots[row][cols] = slot;
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
