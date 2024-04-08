#include "repo.h"
#include <iostream>

Repo::Repo() {
    inventory = {};
}


std::vector<Med> Repo::getInventory() const {
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


void Repo::updateMed(int id, Med newMed) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getId() == id) {
            it->setName(newMed.getName());
            it->setPrice(newMed.getPrice());
            it->setProducer(newMed.getProducer());
            it->setActiveSubstance(newMed.getActiveSubstance());
            return;
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Repo& r) {
    os << "Inventory: {\n";
    for (const auto& med : r.inventory) {
        os << med << "-------------------------------\n";
    }
    os << "}\n";
    return os;
}


Repo::~Repo() {}
