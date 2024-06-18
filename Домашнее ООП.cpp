#include <iostream>
#include "Snack.h"
#include "SnackSlot.h"
#include "VendingMachine.h"
#include "Menu.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    VendingMachine machine(3, 3);

    // Создание снеков
    Snack Snikers("Snikers", 150, 100.0);
    Snack Bounty("Bounty", 100, 80.0);
    Snack ChipsLayskrab("Lays с крабом", 200, 120.0);
    Snack LaysSmetana("Lays сметана", 200, 120.0);
    Snack Sendvich("Сендвич", 130, 180.0);
    Snack Buter("Бутерброд", 145, 150.0);

    // Создание слотов
    SnackSlot slot1(10);
    SnackSlot slot2(10);
    SnackSlot slot3(10);
    SnackSlot slot4(10);
    SnackSlot slot5(10);
    SnackSlot slot6(10);
    SnackSlot slot7(10);
    SnackSlot slot8(10);
    SnackSlot slot9(10);

    // Добавление снеков в слоты
    slot1.addSnack(&Snikers);
    slot2.addSnack(&Bounty);
    slot3.addSnack(&ChipsLayskrab);
    slot4.addSnack(&LaysSmetana);
    slot5.addSnack(&Sendvich);
    slot6.addSnack(&Buter);

    // Добавление слотов в вендинговый аппарат
    machine.addSlot(0, 0, &slot1);
    machine.addSlot(0, 1, &slot2);
    machine.addSlot(0, 2, &slot3);
    machine.addSlot(1, 0, &slot4);
    machine.addSlot(1, 1, &slot5);
    machine.addSlot(1, 2, &slot6);

    // Создание меню с указателем на вендинговый аппарат
    Menu menu(&machine);
    menu.displayMainMenu();

    return 0;
}