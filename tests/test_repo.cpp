#include <assert.h>
#include <iostream>
#include <sstream>
#include "../src/repository/repo.h"
#include "../src/domain/med.h"

void test_create() {
    Repo r;
    assert(r.getInventory().size() == 0);

    Med med1("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    r.addMed(med1);

    assert(r.getInventory().size() == 1);
    assert(r.getInventory()[0].getId() == 1);
    assert(r.getInventory()[0].getName() == "Paracetamol");
    assert(r.getInventory()[0].getPrice() == 10.5);
    assert(r.getInventory()[0].getProducer() == "Zentiva");
    assert(r.getInventory()[0].getActiveSubstance() == "Paracetamol");
}

void test_setter() {
    Repo r;

    Med med2("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med3("Nurofen", 15.5, "Zentiva", "Ibuprofen");

    r.addMed(med2);

    std::vector<Med> newInventory = {med2, med3};
    r.setInventory(newInventory);

    assert(r.getInventory().size() == 2);
}

void test_remove() {
    Repo r;

    Med med4("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med5("Nurofen", 15.5, "Zentiva", "Ibuprofen");

    r.addMed(med4);
    r.addMed(med5);

    r.removeMed(4);

    assert(r.getInventory().size() == 1);
    assert(r.getInventory()[0].getId() == 5);
}

void test_update() {
    Repo r;

    Med med6("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med7("Nurofen", 15.5, "Zentiva", "Ibuprofen");

    r.addMed(med6);
    r.addMed(med7);

    Med med8("Nurofen", 15.5, "Zentiva", "Ibuprofen");
    r.updateMed(6, med8);

    assert(r.getInventory().size() == 2);
    assert(r.getInventory()[0].getName() == "Nurofen");
}

void test_stringify() {
    Repo r;

    Med med9("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med10("Nurofen", 15.5, "Zentiva", "Ibuprofen");

    r.addMed(med9);
    r.addMed(med10);

    std::stringstream ss;
    ss << r;

    std::string expected = "Inventory: {\n";
    expected += "Id: 9\nName: Paracetamol\nPrice: 10.5\nProducer: Zentiva\nActive substance: Paracetamol\n-------------------------------\n";
    expected += "Id: 10\nName: Nurofen\nPrice: 15.5\nProducer: Zentiva\nActive substance: Ibuprofen\n-------------------------------\n";
    expected += "}\n";

    assert(ss.str() == expected);
}

int main() {
    test_create();
    test_setter();
    test_remove();
    test_update();
    test_stringify();

    std::cout << "All repository tests passed!\n";
    return 0;
}
