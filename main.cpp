#include <iostream>
#include <limits>
#include "Queue1Public.h"
#include "Queue1Protected.h"
#include "Queue1Private.h"

using namespace std;

static bool readDouble(const char* prompt, double& value) {
    while (true) {
        cout << prompt;
        if (cin >> value) return true;
        if (cin.eof()) return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода, введите число.\n";
    }
}

static bool readInt(const char* prompt, int& value) {
    while (true) {
        cout << prompt;
        if (cin >> value) return true;
        if (cin.eof()) return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода, введите целое число.\n";
    }
}

template <class T>
void runMenu() {
    T a, b;   // a - основная очередь, b - вторая (копия / для слияния)
    int choice;

    while (true) {
        cout << "\n1 - Добавить элемент в очередь\n"
                "2 - Извлечь элемент из очереди\n"
                "3 - Вывести очередь на экран\n"
                "4 - Среднее арифметическое элементов с нечётными номерами\n"
                "5 - Создать копию очереди (копия сохраняется во вторую очередь)\n"
                "6 - Слить первую и вторую очереди\n"
                "7 - Добавить элемент во вторую очередь\n"
                "8 - Вывести вторую очередь\n"
                "0 - Выход\n";
        if (!readInt("Ваш выбор: ", choice)) return;

        switch (choice) {
        case 1: {
            double v;
            if (!readDouble("Введите значение: ", v)) return;
            a.enqueue(v);
            break;
        }
        case 2: {
            double v;
            if (a.dequeue(v)) cout << "Извлечён элемент: " << v << '\n';
            else cout << "Очередь пуста\n";
            break;
        }
        case 3:
            a.print();
            break;
        case 4:
            a.showAverageOdd();
            break;
        case 5:
            b = a.makeCopy();
            cout << "Копия создана. Вторая очередь: ";
            b.print();
            break;
        case 6: {
            T c = a.merge(b);
            cout << "Результат слияния. ";
            c.print();
            break;
        }
        case 7: {
            double v;
            if (!readDouble("Введите значение: ", v)) return;
            b.enqueue(v);
            break;
        }
        case 8:
            b.print();
            break;
        case 0:
            return;
        default:
            cout << "Нет такого пункта меню\n";
        }
    }
}

int main() {
    int type;
    cout << "Выберите тип наследования:\n"
            "1 - public\n2 - protected\n3 - private\n";
    if (!readInt("Ваш выбор: ", type)) return 0;

    switch (type) {
    case 1: runMenu<Queue1Public>();    break;
    case 2: runMenu<Queue1Protected>(); break;
    case 3: runMenu<Queue1Private>();   break;
    default: cout << "Неверный выбор\n";
    }
    return 0;
}
