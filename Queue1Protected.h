#ifndef QUEUE1PROTECTED_H
#define QUEUE1PROTECTED_H

#include "Queue.h"

class Queue1Protected : protected Queue {
public:
    Queue1Protected() = default;

    using Queue::enqueue;
    using Queue::dequeue;
    using Queue::isEmpty;
    using Queue::print;

    double averageOdd(bool& ok) const;   // нахождение
    void showAverageOdd() const;         // отображение
    Queue1Protected makeCopy() const;
    Queue1Protected merge(const Queue1Protected& other) const;

private:
    explicit Queue1Protected(Queue&& base);
};

#endif
