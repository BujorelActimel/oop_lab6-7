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

    T get(int index);

    int size();

    int get_capacity();
};