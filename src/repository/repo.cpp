#include "repo.h"
#include <iostream>

Repo::Repo() {
    inventory = std::vector<Med>();
}


std::vector<Med>& Repo::getInventory() {
    return inventory;
}


void Repo::setInventory(std::vector<Med> newInventory) {
    inventory = newInventory;
}


void Repo::addMed(Med m) {
    inventory.push_back(m);
}


void Repo::removeMed(int id) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getId() == id) {
            inventory.erase(it);
            return;
        }
    }
}


void Repo::updateMed(int id, std::string new_name, double new_price, std::string new_producer, std::string new_active_substance) {
    for (auto& elem : inventory) {
        if (elem.getId() == id) {
            elem.setName(new_name);
            elem.setPrice(new_price);
            elem.setProducer(new_producer);
            elem.setActiveSubstance(new_active_substance);
            return;
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Repo& r) {
    os << "Inventory: {\n";
    for (auto& elem : r.inventory) {
        os << elem << "-------------------------------\n";
    }
    os << "}\n";
    return os;
}


Repo::~Repo() {}
