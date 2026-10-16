#include "Queue1Public.h"
#include <iostream>
#include <utility>

Queue1Public::Queue1Public(Queue&& base) : Queue(std::move(base)) {}

double Queue1Public::averageOdd(bool& ok) const {
    double sum = 0;
    std::size_t cnt = 0;
    std::size_t n = getSize();
    // порядковые номера 1, 3, 5... -> индексы 0, 2, 4...
    for (std::size_t i = 0; i < n; i += 2) {
        sum += getValueAt(i);
        ++cnt;
    }
    ok = (cnt > 0);
    return ok ? sum / cnt : 0.0;
}

void Queue1Public::showAverageOdd() const {
    bool ok;
    double avg = averageOdd(ok);
    if (ok)
        std::cout << "Среднее арифметическое элементов с нечётными номерами: " << avg << '\n';
    else
        std::cout << "Очередь пуста, среднее посчитать нельзя\n";
}

Queue1Public Queue1Public::makeCopy() const {
    return Queue1Public(Queue::copy());
}

Queue1Public Queue1Public::merge(const Queue1Public& other) const {
    return Queue1Public(Queue::merge(*this, other));
}
