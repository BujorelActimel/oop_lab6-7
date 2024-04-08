#pragma once

template <typename T>
class Vector {
private:
    T* arr;
    int capacity;
    int current;

public:
    Vector();

    void push(T data);

    void pop();

    void pop(int index);

    T& get(int index) const;

    int size() const;

    int get_capacity() const;
};