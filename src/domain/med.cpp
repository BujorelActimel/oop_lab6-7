#include <iostream>
#include "med.h"

int Med::nextId = 1;

Med::Med() 
    : name(""), price(0.0), producer(""), activeSubstance("") {}

Med::Med(std::string name, float price, std::string producer, std::string activeSubstance) 
    : id(nextId++), name(name), price(price), producer(producer), activeSubstance(activeSubstance) {}


Med::Med(const Med& m) 
    : id(m.id), name(m.name), price(m.price), producer(m.producer), activeSubstance(m.activeSubstance) {
    // std::cout << "copie\n"; 
}


Med::~Med() {}


int Med::getId() const {
    return id;
}


std::string Med::getName() const {
    return name;
}


float Med::getPrice() const {
    return price;
}


std::string Med::getProducer() const {
    return producer;
}


std::string Med::getActiveSubstance() const {
    return activeSubstance;
}


void Med::setName(std::string name) {
    this->name = name;
}


void Med::setPrice(float price) {
    this->price = price;
}


void Med::setProducer(std::string producer) {
    this->producer = producer;
}


void Med::setActiveSubstance(std::string activeSubstance) {
    this->activeSubstance = activeSubstance;
}


std::ostream& operator<<(std::ostream& os, const Med& med) {
    os << "Id: " << med.id << "\n";
    os << "Name: " << med.getName() << "\n";
    os << "Price: " << med.getPrice() << "\n";
    os << "Producer: " << med.getProducer() << "\n";
    os << "Active substance: " << med.getActiveSubstance() << "\n";
    return os;
}

bool Med::operator==(const Med& other) const {
    return name == other.name && price == other.price && producer == other.producer && activeSubstance == other.activeSubstance;
}