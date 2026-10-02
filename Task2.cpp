#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int age, is3D, isVIP;
    double basePrice = 12, finalPrice;

    cout << "Введите возраст: ";
    cin >> age;
    cout << "Формат 3D (1 - да, 0 - нет): ";
    cin >> is3D;
    cout << "VIP-место (1 - да, 0 - нет): ";
    cin >> isVIP;

    if (age < 0) {
        cout << "Ошибка: отрицательный возраст!" << endl;
        return 1;
    }

    if (age < 6) {
        finalPrice = 0;
    } else {
        double discount = 0;
        if (age < 12) discount = 0.4;
        else if (age >= 65) discount = 0.3;

        finalPrice = basePrice * (1 - discount);

        if (is3D == 1) finalPrice += 4;
        if (isVIP == 1) finalPrice += 6;
    }

    cout << "Итоговая цена: " << finalPrice << endl;
    return 0;
}
