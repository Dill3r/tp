#ifndef QUEUE1PUBLIC_H
#define QUEUE1PUBLIC_H

#include "Queue.h"

class Queue1Public : public Queue {
public:
    Queue1Public() = default;

    using Queue::enqueue;
    using Queue::dequeue;
    using Queue::isEmpty;
    using Queue::print;

    double averageOdd(bool& ok) const;   // нахождение
    void showAverageOdd() const;         // отображение
    Queue1Public makeCopy() const;
    Queue1Public merge(const Queue1Public& other) const;

private:
    explicit Queue1Public(Queue&& base);
};

#endif
