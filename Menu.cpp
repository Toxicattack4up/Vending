#include "Menu.h"
#include <iostream>
#include "SnackSlot.h"

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
    case 1: // ���������� �������
        TopUpBalance();
        break;
    case 2: // ������� ���������
        displayPurchaseMenu();
        break;
    case 3: // ����� ���� ��������������
        displayAdminMenu();
        break;
    default:
        std::cerr << "������: ������������ �����, ���������� �����." << std::endl;
        displayMainMenu(); // ��������� � ������� ���� ����� ������
        break;
    }
}

void Menu::displayPurchaseMenu()
{
    std::cout << "�������� ��� � ������� ��� �������:" << std::endl;
    vendingMachine->display();

    int row, col;
    std::cout << "������� ����� ����: ";
    std::cin >> row;
    std::cout << "������� ����� �������: ";
    std::cin >> col;

    handlePurchase(row, col);
}

void Menu::handlePurchase(int row, int col)
{
    // �������� ������ � ������
    const auto& slots = vendingMachine->getSlots();

    // �������� �� ������������ ��������� ������
    if (row >= slots.size() || col >= slots[row].size())
    {
        std::cerr << "������: ������������ ����� ���� ��� �������." << std::endl;
        displayMainMenu(); // ��������� � ������� ���� ����� ������
        return;
    }

    SnackSlot* slot = slots[row][col];
    if (slot == nullptr || slot->isEmpty())
    {
        std::cerr << "������: ��������� ���� ���� ��� �� ����������." << std::endl;
        displayMainMenu(); // ��������� � ������� ���� ����� ������
        return;
    }

    double price = slot->getSnackPrice();
    if (AccountBalance >= price)
    {
        AccountBalance -= price;
        std::cout << "�� ������: " << slot->getSnackName() << std::endl;
        std::cout << "���������� ������: " << AccountBalance << std::endl;

        // ������� ���� �� ����� ����� �������
        slot->removeSnack();
    }
    else
    {
        std::cerr << "������: ������������ ������� �� �������." << std::endl;
    }

    displayMainMenu(); // ��������� � ������� ���� ����� ������� ��� ������
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
        std::cerr << "������: ������ �������� ������, ���������� �����." << std::endl;
        displayAdminMenu();
    }
}

void Menu::handleAdminMenuChoice(int choice)
{
    switch (choice)
    {
    case 1:
        std::cout << "���������� ������..." << std::endl;
        // ���������� ���������� ������ �����
        break;
    case 2:
        displayMainMenu();
        break;
    default:
        std::cerr << "������: ������������ �����, ���������� ��� ���." << std::endl;
        displayAdminMenu(); // ��������� � ����� ���� ����� ������
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
    return AccountBalance;
}