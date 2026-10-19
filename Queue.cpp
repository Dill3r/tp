#include "Queue.h"
#include <iostream>
#include <utility>

void Queue::init() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

void Queue::clear() {
    double tmp;
    while (dequeue(tmp)) {}
}

void Queue::appendAll(const Queue& src) {
    for (std::size_t i = 0; i < src.count; ++i)
        enqueue(src.getValueAt(i));
}

Queue::Queue() { init(); }

Queue::Queue(const Queue& other) {
    init();
    appendAll(other);
}

Queue::Queue(Queue&& other) noexcept {
    head = other.head;
    tail = other.tail;
    count = other.count;
    other.init();
}

Queue& Queue::operator=(const Queue& other) {
    if (this != &other) {
        clear();
        appendAll(other);
    }
    return *this;
}

Queue& Queue::operator=(Queue&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        count = other.count;
        other.init();
    }
    return *this;
}

Queue::~Queue() { clear(); }

void Queue::enqueue(double value) {
    Node* n = new Node(value, tail);   // prev нового элемента - бывший хвост
    if (head == nullptr)
        head = n;
    tail = n;
    ++count;
}

bool Queue::dequeue(double& value) {
    if (head == nullptr)
        return false;

    value = head->data;
    Node* old = head;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        // ищем элемент, который ссылается на head
        Node* cur = tail;
        while (cur->prev != head)
            cur = cur->prev;
        cur->prev = nullptr;
        head = cur;
    }

    delete old;
    --count;
    return true;
}

bool Queue::isEmpty() const { return head == nullptr; }

void Queue::print() const {
    if (isEmpty()) {
        std::cout << "Очередь пуста\n";
        return;
    }
    std::cout << "Очередь (от головы к хвосту): ";
    for (std::size_t i = 0; i < count; ++i)
        std::cout << getValueAt(i) << ' ';
    std::cout << '\n';
}

std::size_t Queue::getSize() const { return count; }

double Queue::getValueAt(std::size_t index) const {
    // идём от хвоста назад по ссылкам prev
    Node* cur = tail;
    for (std::size_t steps = count - 1 - index; steps > 0; --steps)
        cur = cur->prev;
    return cur->data;
}

Queue Queue::copy() const {
    Queue result;
    result.appendAll(*this);
    return result;
}

Queue Queue::merge(const Queue& a, const Queue& b) {
    Queue result;
    result.appendAll(a);
    result.appendAll(b);
    return result;
}
