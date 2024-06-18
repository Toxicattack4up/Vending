#include "Menu.h"
#include <iostream>
#include "SnackSlot.h"

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
    case 1: // пополнение баланса
        TopUpBalance();
        break;
    case 2: // покупка вкусняшки
        displayPurchaseMenu();
        break;
    case 3: // Вызов меню администратора
        displayAdminMenu();
        break;
    default:
        std::cerr << "Ошибка: Неправильный выбор, попробуйте снова." << std::endl;
        displayMainMenu(); // Вернуться в главное меню после ошибки
        break;
    }
}

void Menu::displayPurchaseMenu()
{
    std::cout << "Выберите ряд и колонку для покупки:" << std::endl;
    vendingMachine->display();

    int row, col;
    std::cout << "Введите номер ряда: ";
    std::cin >> row;
    std::cout << "Введите номер колонки: ";
    std::cin >> col;

    handlePurchase(row, col);
}

void Menu::handlePurchase(int row, int col)
{
    // Получаем доступ к слотам
    const auto& slots = vendingMachine->getSlots();

    // Проверка на корректность введенных данных
    if (row >= slots.size() || col >= slots[row].size())
    {
        std::cerr << "Ошибка: Некорректный выбор ряда или колонки." << std::endl;
        displayMainMenu(); // Вернуться в главное меню после ошибки
        return;
    }

    SnackSlot* slot = slots[row][col];
    if (slot == nullptr || slot->isEmpty())
    {
        std::cerr << "Ошибка: Выбранный слот пуст или не существует." << std::endl;
        displayMainMenu(); // Вернуться в главное меню после ошибки
        return;
    }

    double price = slot->getSnackPrice();
    if (AccountBalance >= price)
    {
        AccountBalance -= price;
        std::cout << "Вы купили: " << slot->getSnackName() << std::endl;
        std::cout << "Оставшийся баланс: " << AccountBalance << std::endl;

        // Удалить снэк из слота после покупки
        slot->removeSnack();
    }
    else
    {
        std::cerr << "Ошибка: Недостаточно средств на балансе." << std::endl;
    }

    displayMainMenu(); // Вернуться в главное меню после покупки или ошибки
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
        std::cerr << "Ошибка: Введен неверный пароль, попробуйте снова." << std::endl;
        displayAdminMenu();
    }
}

void Menu::handleAdminMenuChoice(int choice)
{
    switch (choice)
    {
    case 1:
        std::cout << "Пополнение лотков..." << std::endl;
        // Реализуйте пополнение лотков здесь
        break;
    case 2:
        displayMainMenu();
        break;
    default:
        std::cerr << "Ошибка: Неправильный выбор, попробуйте ещё раз." << std::endl;
        displayAdminMenu(); // Вернуться в админ меню после ошибки
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
    return AccountBalance;
}