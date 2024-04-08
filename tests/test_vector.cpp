#include "../src/vector/vector.h"
#include "../src/domain/med.h"
#include <iostream>
#include <assert.h>

void test_create_vector() {
    Vector<int> v;
    assert(v.size() == 0);
    assert(v.get_capacity() == 1);
}

void test_push_pop_get_vector() {
    Vector<int> v;
    v.push(1);
    v.push(2);
    v.push(3);
    assert(v.size() == 3);
    assert(v.get_capacity() == 4);
    assert(v.get(0) == 1);
    assert(v.get(1) == 2);
    assert(v.get(2) == 3);

    v.pop();
    assert(v.size() == 2);
    assert(v.get_capacity() == 4);
    assert(v.get(0) == 1);
    assert(v.get(1) == 2);

    v.pop();
    v.pop();
    assert(v.size() == 0);
    assert(v.get_capacity() == 4);
    try {
        v.get(0);
        assert(false);
    } catch (const char* msg) {
        assert(true);
    }

    Vector<Med> v2;
    v2.push(Med("a", 1, "a", "a"));
    v2.push(Med("b", 2, "b", "b"));
    assert(v2.size() == 2);
    assert(v2.get_capacity() == 2);
    assert(v2.get(0) == Med("a", 1, "a", "a"));
    assert(v2.get(1) == Med("b", 2, "b", "b"));

    v2.pop();
    assert(v2.size() == 1);
    assert(v2.get_capacity() == 2);
    assert(v2.get(0) == Med("a", 1, "a", "a"));

    v2.pop();
    assert(v2.size() == 0);
    assert(v2.get_capacity() == 2);
    try {
        v2.get(0);
        assert(false);
    } catch (const char* msg) {
        assert(true);
    }

    Vector<Med> v3;
    v3.push(Med("a", 1, "a", "a"));
    v3.push(Med("b", 2, "b", "b"));
    v3.push(Med("c", 3, "c", "c"));
    assert(v3.size() == 3);
    v3.pop(0);
    assert(v3.size() == 2);
    assert(v3.get(0) == Med("b", 2, "b", "b"));

    Vector<int> v4;
    v4.push(1);
    v4.push(2);
    v4.push(3);
    v4.pop(1);
    assert(v4.size() == 2);
    assert(v4.get(0) == 1);
}

int main() {
    test_create_vector();
    test_push_pop_get_vector();

    std::cout << "All vector tests passed!\n";
    return 0;
}