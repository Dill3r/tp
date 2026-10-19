#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

class Queue {
private:
    struct Node {
        double data;
        Node*  prev;   // предыдущий элемент (стоящий ближе к голове очереди)
        Node(double d, Node* p) : data(d), prev(p) {}
    };

    Node*       head;   // откуда извлекаем
    Node*       tail;   // куда добавляем
    std::size_t count;

    void init();                       // инициализация пустой очереди
    void clear();                      // освобождение всей памяти
    void appendAll(const Queue& src);  // добавить копии всех элементов src в конец

public:
    Queue();
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;
    Queue& operator=(const Queue& other);
    Queue& operator=(Queue&& other) noexcept;
    ~Queue();

    void enqueue(double value);        // добавить элемент
    bool dequeue(double& value);       // извлечь элемент (false, если очередь пуста)
    bool isEmpty() const;
    void print() const;                // вывод очереди на экран

protected:
    std::size_t getSize() const;
    double getValueAt(std::size_t index) const;   // index с 0, от головы очереди
    Queue copy() const;                            // копия очереди
    static Queue merge(const Queue& a, const Queue& b);  // слияние: a, затем b
};

#endif
