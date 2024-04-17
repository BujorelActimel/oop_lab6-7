#include "service.h"
#include <exception>
#include <iostream>
#include <algorithm>

Service::Service(Repo& repo)
    : repo(repo) {}

Repo& Service::getRepo() {
    return repo;
}

Med& Service::searchMed(const std::string& name) {
    std::vector<Med>& inventory = getRepo().getInventory();
    auto it = std::find_if(inventory.begin(), inventory.end(), [&name](const Med& med) {
        return med.getName() == name;
    });

    if (it != inventory.end()) {
        return *it;
    }

    throw std::exception();
}

std::vector<Med> filterMed(Repo& repo, std::function<bool(const Med&)> filterFunc) {
    std::vector<Med>& inventory = repo.getInventory();
    std::vector<Med> filtered;
    std::copy_if(inventory.begin(), inventory.end(), std::back_inserter(filtered), filterFunc);
    return filtered;
}