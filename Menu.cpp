#include "Menu.h"
#include "VendingMachine.h"
#include <iostream>

void Menu::displayMainMenu()
{
	std::cout << "�� ������� ������: " << AccountBalance << std::endl;
	std::cout << "�������� ������ �����: " << std::endl;
	std::cout << "1. ��������� ������." << std::endl;
	std::cout << "2. ������ ���������." << std::endl;
	std::cout << "3. ���� ��������������" << std::endl;
	std::cin >> choice;
	handleMainMenuChoice(choice);
}

void Menu::handleMainMenuChoice(int choice)
{
	switch (choice)
	{
	case 1: //���������� �������
		TopUpBalance();
		break;
	case 2: //������� ���������
		displayPurchaseMenu();
		break;
	case 3: //����� ���� ��������������
		displayAdminMenu();
		break;
	default:
		break;
	}
}

void Menu::displayPurchaseMenu()
{
	std::cout << "�������� ��� � ������� ��� �������:" << std::endl;
	vendingMachine->display();

	int row, cols;
	std::cout << "������� ����� ����: ";
	std::cin >> row;
	std::cout << "������� ����� �������: ";
	std::cin >> cols;

	handlePurchase(row, cols);
}

void Menu::handlePurchase(int row, int cols)
{

}

void Menu::displayAdminMenu()
{
	std::cout << "������� ������ ��������������: ";
	std::string inputPassword;
	std::cin >> inputPassword;

	if (inputPassword == password)
	{
		std::cout << "1. ���������� ������." << std::endl;
		std::cout << "2. ��������� � ������� ����." << std::endl;
		std::cin >> choice;
		handleAdminMenuChoice(choice);
	}
	else 
	{
		std::cerr << "������: ������ �������� ������" << std::endl;
	}
	
}

void Menu::handleAdminMenuChoice(int choice)
{
	switch (choice)
	{
	case 1:
		std::cout << "���������� ������.." << std::endl;
		break;
	case 2:

	default:
		std::cerr << "������: ������������ �����, ���������� ��� ���." << std::endl;
		break;
	}
}

int Menu::TopUpBalance()
{
	int amount;
	std::cout << "������� ����� ����������: ";
	std::cin >> amount;
	AccountBalance += amount;
	std::cout << "������ ������� ��������. �� ������� ������: " << AccountBalance << std::endl;
	displayMainMenu();
	return	AccountBalance;
	
}