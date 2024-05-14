#include <iostream>
#include <fstream>
#include <vector>
#include "prj_3_Konstantynov.h"
#include "prj_3_Kokish.h"
#include "prj_3_Lytvyn.h"

int main() {
    std::vector<BusSchedule> schedule;
    std::string filename = "bus_schedule.txt";

    std::ifstream file(filename);
    if (file.is_open()) {
        int number;
        char comma;
        while (file >> number) {
            BusSchedule bus;
            bus.number = number;
            file >> comma >> std::ws;
            std::getline(file, bus.route, ',');
            std::getline(file, bus.frequency, ',');
            std::getline(file, bus.days, ',');
            std::getline(file, bus.arrivalTime, ',');
            std::getline(file, bus.finalStationArrivalTime);
            schedule.push_back(bus);
        }
        file.close();
    }
    else {
        std::cout << "Не удалось открыть файл с расписанием. Проверьте файл." << std::endl;
    }

    int choice;
    do {
        std::cout << "\nМеню:\n1. Поиск по названию остановки\n2. Вывод расписания\n3. Добавление нового автобуса\n4. Удаление автобуса\n5. Сохранение расписания в файл\n";
        std::cout << "Введите номер: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string stationName;
            std::cout << "Введите название остановки: ";
            std::cin.ignore();
            std::getline(std::cin, stationName);
            searchByStation(schedule, stationName);
            break;
        }
        case 2:
            printSchedule(schedule);
            break;
        case 3:
            addNewBus(schedule);
            break;
        case 4: {
            int number;
            std::cout << "Введите номер автобуса для удаления: ";
            std::cin >> number;
            deleteBus(schedule, number);
            break;
        }
        case 5:
            saveScheduleToFile(schedule, filename);
            std::cout << "Расписание успешно сохранено. До свидания!" << std::endl;
            break;
        default:
            std::cout << "Некорректный выбор. Пожалуйста, выберите еще раз." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
