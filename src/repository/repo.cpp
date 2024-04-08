#include "repo.h"
#include <iostream>

Repo::Repo() {
    inventory = Vector<Med>();
}


Vector<Med>& Repo::getInventory() {
    return inventory;
}


void Repo::setInventory(Vector<Med> newInventory) {
    inventory = newInventory;
}


void Repo::addMed(Med m) {
    // inventory.push_back(m);
    inventory.push(m);
}


void Repo::removeMed(int id) {
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory.get(i).getId() == id) {
            inventory.pop(i);
            return;
        }
    }
}


void Repo::updateMed(int id, std::string new_name, double new_price, std::string new_producer, std::string new_active_substance) {
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory.get(i).getId() == id) {
            inventory.get(i).setName(new_name);
            inventory.get(i).setPrice(new_price);
            inventory.get(i).setProducer(new_producer);
            inventory.get(i).setActiveSubstance(new_active_substance);
            return;
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Repo& r) {
    os << "Inventory: {\n";
    for (int i = 0; i < r.inventory.size(); ++i) {
        os << r.inventory.get(i) << "-------------------------------\n";
    }
    os << "}\n";
    return os;
}


Repo::~Repo() {}
