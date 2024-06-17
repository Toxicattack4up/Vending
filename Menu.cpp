#include "Menu.h"
#include "VendingMachine.h"
#include <iostream>

void Menu::displayMainMenu()
{
	std::cout << "На балансе сейчас: " << AccountBalance << std::endl;
	std::cout << "Выберите нужную цифру: " << std::endl;
	std::cout << "1. Пополнить баланс." << std::endl;
	std::cout << "2. Купить вкусняшку." << std::endl;
	std::cout << "3. Меню администратора" << std::endl;
	std::cin >> choice;
	handleMainMenuChoice(choice);
}

void Menu::handleMainMenuChoice(int choice)
{
	switch (choice)
	{
	case 1: //пополнение баланса
		TopUpBalance();
		break;
	case 2: //покупка вкусняшки
		displayPurchaseMenu();
		break;
	case 3: //Вызов меню администратора
		displayAdminMenu();
		break;
	default:
		break;
	}
}

void Menu::displayPurchaseMenu()
{
	std::cout << "Выберите ряд и колонку для покупки:" << std::endl;
	vendingMachine->display();

	int row, cols;
	std::cout << "Введите номер ряда: ";
	std::cin >> row;
	std::cout << "Введите номер голонки: ";
	std::cin >> cols;

	handlePurchase(row, cols);
}

void Menu::handlePurchase(int row, int cols)
{

}

void Menu::displayAdminMenu()
{
	std::cout << "Введите пароль администратора: ";
	std::string inputPassword;
	std::cin >> inputPassword;

	if (inputPassword == password)
	{
		std::cout << "1. Пополнение лотков." << std::endl;
		std::cout << "2. Вернуться в главное меню." << std::endl;
		std::cin >> choice;
		handleAdminMenuChoice(choice);
	}
	else 
	{
		std::cerr << "Ошибка: Введен неверный пароль" << std::endl;
	}
	
}

void Menu::handleAdminMenuChoice(int choice)
{
	switch (choice)
	{
	case 1:
		std::cout << "Пополнение лотков.." << std::endl;
		break;
	case 2:

	default:
		std::cerr << "Ошибка: Неправильный выбор, попробуйте ещё раз." << std::endl;
		break;
	}
}

int Menu::TopUpBalance()
{
	int amount;
	std::cout << "Введите сумму пополнения: ";
	std::cin >> amount;
	AccountBalance += amount;
	std::cout << "Баланс успешно пополнен. На балансе сейчас: " << AccountBalance << std::endl;
	displayMainMenu();
	return	AccountBalance;
	
}