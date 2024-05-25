#include "Menu.h"
#include <iostream>

void Menu::displayMainMenu()
{

	std::cout << "На балансе сейчас: " << AccountBalance << std::endl;
	std::cout << "Выберите нужную цифру: " << std::endl;
	std::cout << "1. Пополнить баланс." << std::endl;
	std::cout << "2. Купить вкусняшку." <<  std::endl;
	std::cout << "Другие настройки..." << displayAdminMenu << std::endl;
	std::cin >> choice;
}

void Menu::handleMainMenuChoice(int choice)
{
	switch (choice)
	{
	case1: //пополнение баланса
		TopUpBalance;
		break;
	case2: //покупка вкусняшки
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