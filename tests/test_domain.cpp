#include <assert.h>
#include <iostream>
#include <sstream>

#include "../src/domain/med.h"

void test_getters() {
    Med med1("Paracetamol", 10.5, "Zentiva", "Paracetamol");

    assert(med1.getId() == 1);
    assert(med1.getName() == "Paracetamol");
    assert(med1.getPrice() == 10.5);
    assert(med1.getProducer() == "Zentiva");
    assert(med1.getActiveSubstance() == "Paracetamol");

    Med med2("Nurofen", 15.5, "Reckitt Benckiser", "Ibuprofen");

    assert(med2.getId() == 2);
    assert(med2.getName() == "Nurofen");
    assert(med2.getPrice() == 15.5);
    assert(med2.getProducer() == "Reckitt Benckiser");
    assert(med2.getActiveSubstance() == "Ibuprofen");
}

void test_setters() {
    Med med3("Paracetamol", 10.5, "Zentiva", "Paracetamol");

    med3.setName("Nurofen");
    med3.setPrice(15.5);
    med3.setProducer("Reckitt Benckiser");
    med3.setActiveSubstance("Ibuprofen");

    assert(med3.getId() == 3);
    assert(med3.getName() == "Nurofen");
    assert(med3.getPrice() == 15.5);
    assert(med3.getProducer() == "Reckitt Benckiser");
    assert(med3.getActiveSubstance() == "Ibuprofen");
}

void test_stringify() {
    Med med4("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    std::stringstream ss;
    ss << med4;
    std::string expected = "Id: 4\nName: Paracetamol\nPrice: 10.5\nProducer: Zentiva\nActive substance: Paracetamol\n";
    assert(ss.str() == expected);
}

void test_copy() {
    Med med1("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med2 = med1;
    assert(med2.getName() == "Paracetamol");
}

void test_eq() {
    Med med1("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med2("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    assert(med1 == med2);
}

void test_default_constructor() {
    Med med;
    assert(med == Med("", 0.0, "", ""));
}

int main() {
    test_getters();
    test_setters();
    test_stringify();
    test_copy();
    test_eq();
    test_default_constructor();

    std::cout << "All domain tests passed!\n";
    return 0;
}
