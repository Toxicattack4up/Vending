#pragma once
#include <string>
#include "VendingMachine.h"

class Menu
{
private:
	int AccountBalance = 0;
	std::string password = "administrator";
	VendingMachine* vendingMachine; // ”казатель на вендинговый аппарат
public:
	int choice = 0;
	Menu(VendingMachine* vm) : vendingMachine(vm) {}
	void displayMainMenu();
	void handleMainMenuChoice(int choice);
	void displayPurchaseMenu();
	void handlePurchase(int row, int col);
	void displayAdminMenu();
	void handleAdminMenuChoice(int choice);
	int TopUpBalance();
};