#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int age, isStudent;
    double basePrice, finalPrice;

    cout << "Введите возраст зрителя: ";
    cin >> age;
    cout << "Введите базовую цену билета: ";
    cin >> basePrice;
    cout << "Признак студента (1 - да, 0 - нет): ";
    cin >> isStudent;

    if (age < 0 || basePrice < 0) {
        cout << "Ошибка: отрицательный возраст или цена!" << endl;
        return 1;
    }

    if (age < 6) {
        finalPrice = 0;
        cout << "Категория: Ребенок до 6 лет" << endl;
    } else if (age <= 17) {
        finalPrice = basePrice * 0.5;
        cout << "Категория: Ребенок/Школьник" << endl;
    } else if (isStudent == 1) {
        finalPrice = basePrice * 0.8;
        cout << "Категория: Взрослый студент" << endl;
    } else {
        finalPrice = basePrice;
        cout << "Категория: Взрослый" << endl;
    }

    cout << "Итоговая цена: " << finalPrice << endl;
    return 0;
}
