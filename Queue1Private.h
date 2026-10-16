#ifndef QUEUE1PRIVATE_H
#define QUEUE1PRIVATE_H

#include "Queue.h"

class Queue1Private : private Queue {
public:
    Queue1Private() = default;

    using Queue::enqueue;
    using Queue::dequeue;
    using Queue::isEmpty;
    using Queue::print;

    double averageOdd(bool& ok) const;   // нахождение
    void showAverageOdd() const;         // отображение
    Queue1Private makeCopy() const;
    Queue1Private merge(const Queue1Private& other) const;

private:
    explicit Queue1Private(Queue&& base);
};

#endif
