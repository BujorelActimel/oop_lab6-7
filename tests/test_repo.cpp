#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdio>
#include "../src/repository/repo.h"
#include "../src/domain/med.h"

void test_create() {
    Repo r;
    std::vector<Med>& inv = r.getInventory();
    assert(inv.size() == 0);

    Med med1("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    r.addMed(med1);

    assert(inv.size() == 1);
    Med med = inv[0];
    assert(med.getId() == 1);
    assert(med.getName() == "Paracetamol");
    assert(med.getPrice() == 10.5);
    assert(med.getProducer() == "Zentiva");
    assert(med.getActiveSubstance() == "Paracetamol");
}

void test_setter() {
    Repo r;

    Med med2("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med3("Nurofen", 15.5, "Zentiva", "Ibuprofen");

    r.addMed(med2);

    std::vector<Med> newInventory = std::vector<Med>();
    newInventory.push_back(med2);
    newInventory.push_back(med3);

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
    r.updateMed(6, "Nurofen", 15.5, "Zentiva", "Ibuprofen");

    assert(r.getInventory().size() == 2);
    assert(r.getInventory()[0].getName() == "Nurofen");
}

void test_stringify() {
    Repo r;

    Med med8("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med9("Nurofen", 15.5, "Zentiva", "Ibuprofen");

    r.addMed(med8);
    r.addMed(med9);

    std::stringstream ss;
    ss << r;

    std::string expected = "Inventory: {\n";
    expected += "Id: 8\nName: Paracetamol\nPrice: 10.5\nProducer: Zentiva\nActive substance: Paracetamol\n-------------------------------\n";
    expected += "Id: 9\nName: Nurofen\nPrice: 15.5\nProducer: Zentiva\nActive substance: Ibuprofen\n-------------------------------\n";
    expected += "}\n";

    assert(ss.str() == expected);
}

void test_saveToFile() {
    Repo r("test.csv");

    Med med1("Paracetamol", 10.5, "Zentiva", "Paracetamol");
    Med med2("Nurofen", 15.5, "Zentiva", "Ibuprofen");

    r.addMed(med1);
    r.addMed(med2);

    r.saveToFile();

    std::ifstream file("test.csv");
    std::string line;
    std::getline(file, line);
    assert(line == "Paracetamol,10.5,Zentiva,Paracetamol");
    std::getline(file, line);
    assert(line == "Nurofen,15.5,Zentiva,Ibuprofen");
    file.close();
}

void test_loadFromFile() {
    Repo r("test.csv");

    std::vector<Med>& inv = r.getInventory();
    assert(inv.size() == 2);

    assert(inv[0].getName() == "Paracetamol");
    assert(inv[0].getPrice() == 10.5);
    assert(inv[0].getProducer() == "Zentiva");
    assert(inv[0].getActiveSubstance() == "Paracetamol");

    assert(inv[1].getName() == "Nurofen");
    assert(inv[1].getPrice() == 15.5);
    assert(inv[1].getProducer() == "Zentiva");
    assert(inv[1].getActiveSubstance() == "Ibuprofen");
    std::remove("test.csv");
}

void test_getMed() {
    Repo r;

    Med med("Paracetamol", 10.5, "Zentiva", "Paracetamol");

    r.addMed(med);

    Med& med_refference = r.getMed(14);
    assert(med_refference.getName() == "Paracetamol");

    try {
        Med& not_found = r.getMed(100);
        assert(false);
    } catch (std::exception& e) {
        assert(true);
    }
}

int main() {
    test_create();
    test_setter();
    test_remove();
    test_update();
    test_stringify();
    test_saveToFile();
    test_loadFromFile();
    test_getMed();

    std::cout << "All repository tests passed!\n";
    return 0;
}
