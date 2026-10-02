#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int day, isEvening;
    double price = 0;

    cout << "Введите день недели (1-7): ";
    cin >> day;
    cout << "Вечерний сеанс (1 - да, 0 - нет): ";
    cin >> isEvening;

    if (day < 1 || day > 7) {
        cout << "Ошибка: неверный день недели!" << endl;
        return 1;
    }

    switch (day) {
        case 1: case 2: case 3: case 4:
            price = 10; 
            break;
        case 5:
            price = 12; 
            break;
        case 6: case 7:
            price = 15; 
            break;
    }

    if (isEvening == 1 && day != 3) {
        price += 3;
    }

    if (day >= 1 && day <= 4) {
        cout << "Категория дня: Будний" << endl;
    } else if (day == 5) {
        cout << "Категория дня: Пятница" << endl;
    } else {
        cout << "Категория дня: Выходной" << endl;
    }

    cout << "Итоговая цена: " << price << endl;
    return 0;
}
