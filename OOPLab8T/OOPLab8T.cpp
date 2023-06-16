#include <iostream>

void task1();
void task2();
void task3();
void task4();

int main() {
    int choice;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1.T1" << std::endl;
        std::cout << "2.T2" << std::endl;
        std::cout << "3.T3" << std::endl;
        std::cout << "4.T4" << std::endl;
        std::cout << "0.Exit" << std::endl;
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        default:
            std::cout << "Wrong imput" << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}