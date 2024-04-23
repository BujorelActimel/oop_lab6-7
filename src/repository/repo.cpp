#include "repo.h"
#include <iostream>
#include <fstream>
#include <sstream>

Repo::Repo(std::string file_name) : file_name(file_name), inventory() {
    loadFromFile();
}


std::vector<Med>& Repo::getInventory() {
    return inventory;
}


void Repo::setInventory(std::vector<Med> newInventory) {
    inventory = newInventory;
}


void Repo::addMed(Med m) {
    inventory.push_back(m);
    saveToFile();
}


void Repo::removeMed(int id) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getId() == id) {
            inventory.erase(it);
            return;
        }
    }
    saveToFile();
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
    saveToFile();
}


std::ostream& operator<<(std::ostream& os, const Repo& r) {
    os << "Inventory: {\n";
    for (auto& elem : r.inventory) {
        os << elem << "-------------------------------\n";
    }
    os << "}\n";
    return os;
}

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Repo::saveToFile() {
    std::ofstream out(file_name);
    for (const auto& med : getInventory()) {
        out << med.getName() << ',' << med.getPrice() << ',' << med.getProducer() << ',' << med.getActiveSubstance() << "\n";
    }
    out.close();
}

void Repo::loadFromFile() {
    std::ifstream in(file_name);
    std::string line;
    while (std::getline(in, line)) {
        std::vector<std::string> line_split = split(line, ',');
        Repo::addMed(Med(
            line_split[0], // std::string name;
            std::stof(line_split[1]), // float price;
            line_split[2], // std::string producer;
            line_split[3] // std::string activeSubstance;
        ));
    }
    in.close();
}


Repo::~Repo() {}
