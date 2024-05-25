#include <iostream>
#include "Snack.h"
#include "SnackSlot.h"
#include "VendingMachine.h"

int main()
{
    // Создаем несколько снеков
    Snack* bounty = new Snack("Bounty");
    Snack* snickers = new Snack("Snickers");

    // Создаем слот с вместимостью 10 снеков
    SnackSlot* slot = new SnackSlot(10);

    // Добавляем снеки в слот
    slot->addSnack(bounty);
    slot->addSnack(snickers);

    // Создаем вендинговый аппарат с 5 слотами
    VendingMachine* machine = new VendingMachine(5);

    // Добавляем слот в аппарат
    machine->addSlot(slot);

    // Выводим количество пустых слотов в аппарате
    std::cout << machine->getEmptySlotsCount() << std::endl; // Ожидаем 4, потому что один слот заполнен

    // Чистим память
    delete machine;
    delete slot;
    delete snickers;
    delete bounty;

    return 0;
}