#include "Menu.h"
#include <iostream>

void Menu::displayMainMenu()
{

	std::cout << "�� ������� ������: " << AccountBalance << std::endl;
	std::cout << "�������� ������ �����: " << std::endl;
	std::cout << "1. ��������� ������." << std::endl;
	std::cout << "2. ������ ���������." <<  std::endl;
	std::cout << "������ ���������..." << displayAdminMenu << std::endl;
	std::cin >> choice;
}

void Menu::handleMainMenuChoice(int choice)
{
	switch (choice)
	{
	case1: //���������� �������
		TopUpBalance;
		break;
	case2: //������� ���������
		displayPurchaseMenu();
		break;
	case3:
		displayAdminMenu();
		break;
	
	default:
		break;
	}
}

void Menu::displayPurchaseMenu()
{

}

void Menu::handlePurchase(int slotIndex)
{

}

void Menu::displayAdminMenu()
{
	
}

void Menu::handleAdminMenuChoice(int choice)
{
	/*switch (choice)
	{
	default:
		break;
	}*/
}

int Menu::TopUpBalance()
{
	return 0;
}