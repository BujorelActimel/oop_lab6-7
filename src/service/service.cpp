#include "service.h"
#include <exception>
#include <iostream>

Service::Service(Repo& repo)
    : repo(repo) {}

Repo& Service::getRepo() {
    return repo;
}

Med& Service::searchMed(const std::string& name) {
    Vector<Med> &inventory = getRepo().getInventory();
    for (int i = 0; i < inventory.size(); i++) {
        Med &med = inventory.get(i);
        if (med.getName() == name) {
            return med;
        }
    }
    throw std::exception();
}

Vector<Med> filterMed(Repo& repo, std::function<bool(const Med&)> filterFunc) {
    Vector<Med> &inventory = repo.getInventory();
    Vector<Med> filtered;
    for (int i = 0; i < inventory.size(); i++) {
        Med &med = inventory.get(i);
        if (filterFunc(med)) {
            Med med_cp = med;
            filtered.push(med_cp);
        }
    }
    return filtered;
}

Vector<Med> sortedMed(Repo& repo, std::function<bool(const Med&, const Med&)> sortFunc) {
    Vector<Med> &inventory = repo.getInventory();
    Vector<Med> sorted;
    for (int i = 0; i < inventory.size(); i++) {
        Med &med = inventory.get(i);
        sorted.push(med);
    }
    for (int i = 0; i < sorted.size(); i++) {
        for (int j = i + 1; j < sorted.size(); j++) {
            if (sortFunc(sorted.get(i), sorted.get(j))) {
                Med med_cp = sorted.get(i);
                sorted.get(i) = sorted.get(j);
                sorted.get(j) = med_cp;
            }
        }
    }
    return sorted;
}