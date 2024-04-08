#include "vector.h"
#include "../domain/med.h"
#include <iostream>

template <typename T>
Vector<T>::Vector() {
    arr = new T[1];
    capacity = 1;
    current = 0;
}

template <typename T>
void Vector<T>::push(T data) {
    if (current == capacity) {
        T* temp = new T[2 * capacity];

        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        capacity *= 2;
        arr = temp;
    }

    arr[current] = data;
    current++;
}

template <typename T>
void Vector<T>::pop() {
    current--;
}

template <typename T>
void Vector<T>::pop(int index) {
    if (index < current) {
        for (int i = index; i < current - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        current--;
    }
}

template <typename T>
T& Vector<T>::get(int index) const {
    if (index < current) {
        return arr[index];
    }
    throw "Index out of bounds";
}

template <typename T>
int Vector<T>::size() const {
    return current;
}

template <typename T>
int Vector<T>::get_capacity() const {
    return capacity;
}

template class Vector<int>;
template class Vector<Med>;