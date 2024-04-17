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
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i].getId() == id) {
            inventory.erase(inventory.begin() + i);
            return;
        }
    }
}


void Repo::updateMed(int id, std::string new_name, double new_price, std::string new_producer, std::string new_active_substance) {
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i].getId() == id) {
            inventory[i].setName(new_name);
            inventory[i].setPrice(new_price);
            inventory[i].setProducer(new_producer);
            inventory[i].setActiveSubstance(new_active_substance);
            return;
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Repo& r) {
    os << "Inventory: {\n";
    for (int i = 0; i < r.inventory.size(); ++i) {
        os << r.inventory[i] << "-------------------------------\n";
    }
    os << "}\n";
    return os;
}


Repo::~Repo() {}
