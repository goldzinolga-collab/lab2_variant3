#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int day, age, isStudent;
    char format;
    double basePrice = 0, finalPrice;
    string rule = "";

    cout << "Введите день недели (1-7): ";
    cin >> day;
    cout << "Введите возраст: ";
    cin >> age;
    cout << "Формат (N - обычный, I - IMAX): ";
    cin >> format;
    cout << "Признак студента (1 - да, 0 - нет): ";
    cin >> isStudent;

    if (day < 1  day > 7  age < 0 || (format != 'N' && format != 'n' && format != 'I' && format != 'i')) {
        cout << "Ошибка ввода данных!" << endl;
        return 1;
    }

    switch (day) {
        case 1: case 2: case 3: case 4: basePrice = 11; break;
        case 5: basePrice = 13; break;
        case 6: case 7: basePrice = 16; break;
    }

    if (format == 'I' || format == 'i') {
        basePrice += 5;
    }

    if (age < 7) {
        finalPrice = 0;
        rule = "Бесплатный детский билет";
    } else {
        double discount = 0;
        
        // Скидки не складываются, выбираем одну
        if (age >= 7 && age <= 17) {
            discount = 0.5;
            rule = "Скидка 50% (по возрасту)";
        } else if (isStudent == 1) {
            discount = 0.2;
            rule = "Скидка 20% (студенческая)";
        } else {
            rule = "Без скидки";
        }

        finalPrice = basePrice * (1 - discount);

        if (finalPrice < 5) {
            finalPrice = 5;
            rule += " (цена не может быть меньше 5)";
        }
    }

    cout << "Итоговая цена: " << finalPrice << endl;
    cout << "Применённое правило: " << rule << endl;
    return 0;
}
