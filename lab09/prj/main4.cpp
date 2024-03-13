#include <iostream>
#include <conio.h>

void SoftwareDeveloper(){
    setlocale(LC_ALL, "ukr");
    std::cout << "\n -------------------------------------\n"
    << "| Lytvyn Maksym, CUNTU, opd@kntu.kr.ua |\n" << "| Литвин Максим, ЦНТУ, opd@kntu.kr.ua |\n" << "\n ------ (c) All Rights Reserved ------\n\n";
}

void task_9_1() {
    std::cout << "Виклик функції задачі 9.1\n";
}

void task_9_2() {
    std::cout << "Виклик функції задачі 9.2\n";
}

void task_9_3() {
    std::cout << "Виклик функції задачі 9.3\n";
}

void calculation() {
    std::cout << "Виклик функції calculation\n";
}

int main() {
    SoftwareDeveloper();

    char choice;
    char repeat = 'y';

    do {
        std::cout << "Введіть символ (з, !, д, h): ";
        choice = _getch();
        std::cout << choice << std::endl;

        switch (choice) {
            case 'з':
                calculation();
                break;
            case '!':
                task_9_1();
                break;
            case 'д':
                task_9_2();
                break;
            case 'h':
                task_9_3();
                break;
            default:
                std::cout << "\a"; // Відтворення звукового сигналу про помилкове введення
                break;
        }

        std::cout << "Бажаєте продовжити (у або j для виходу): ";
        std::cin >> repeat;

    } while (repeat != 'у' && repeat != 'j');

    return 0;
}
