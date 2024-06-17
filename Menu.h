#pragma once
#include <string>

class Menu
{
private:
	int AccountBalance = 0;
	std::string password = "administratorArtemix1488";
	VendingMachine* vendingMachine; // ”казатель на вендинговый аппарат
public:
	int choice = 0;
	Menu(VendingMachine* vm) : vendingMachine(vm) {}
	void displayMainMenu();
	void handleMainMenuChoice(int choice);
	void displayPurchaseMenu();
	void handlePurchase(int row, int cols);
	void displayAdminMenu();
	void handleAdminMenuChoice(int choice);
	int TopUpBalance();
};