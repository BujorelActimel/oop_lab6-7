#include "service.h"
#include <exception>
#include <iostream>

Service::Service(Repo& repo)
    : repo(repo) {}

Repo& Service::getRepo() {
    return repo;
}

Med& Service::searchMed(const std::string& name) {
    std::vector<Med> &inventory = getRepo().getInventory();
    for (int i = 0; i < inventory.size(); i++) {
        Med &med = inventory[i];
        if (med.getName() == name) {
            return med;
        }
    }
    throw std::exception();
}

std::vector<Med> filterMed(Repo& repo, std::function<bool(const Med&)> filterFunc) {
    std::vector<Med> &inventory = repo.getInventory();
    std::vector<Med> filtered;
    for (int i = 0; i < inventory.size(); i++) {
        Med &med = inventory[i];
        if (filterFunc(med)) {
            Med med_cp = med;
            filtered.push_back(med_cp);
        }
    }
    return filtered;
}

std::vector<Med> sortedMed(Repo& repo, std::function<bool(const Med&, const Med&)> sortFunc) {
    std::vector<Med> &inventory = repo.getInventory();
    std::vector<Med> sorted;
    for (int i = 0; i < inventory.size(); i++) {
        Med &med = inventory[i];
        sorted.push_back(med);
    }
    for (int i = 0; i < sorted.size(); i++) {
        for (int j = i + 1; j < sorted.size(); j++) {
            if (sortFunc(sorted[i], sorted[j])) {
                Med med_cp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = med_cp;
            }
        }
    }
    return sorted;
}