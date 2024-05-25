#pragma once
#include <string>

class Menu
{
private:
	int AccountBalance = 0;
	std::string password = "administratorArtemix1488";
public:
	int choice = 0;
	void displayMainMenu();
	void handleMainMenuChoice(int choice);
	void displayPurchaseMenu();
	void handlePurchase(int slotIndex);
	void displayAdminMenu();
	void handleAdminMenuChoice(int choice);
	int TopUpBalance();
};