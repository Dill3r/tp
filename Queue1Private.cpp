#include "Queue1Private.h"
#include <iostream>
#include <utility>

Queue1Private::Queue1Private(Queue&& base) : Queue(std::move(base)) {}

double Queue1Private::averageOdd(bool& ok) const {
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

void Queue1Private::showAverageOdd() const {
    bool ok;
    double avg = averageOdd(ok);
    if (ok)
        std::cout << "Среднее арифметическое элементов с нечётными номерами: " << avg << '\n';
    else
        std::cout << "Очередь пуста, среднее посчитать нельзя\n";
}

Queue1Private Queue1Private::makeCopy() const {
    return Queue1Private(Queue::copy());
}

Queue1Private Queue1Private::merge(const Queue1Private& other) const {
    return Queue1Private(Queue::merge(*this, other));
}
