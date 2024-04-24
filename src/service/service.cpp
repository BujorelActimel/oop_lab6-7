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

void Service::addMed(const Med& med) {
    repo.addMed(med);
    undoActions.push_back(new UndoAdd(repo, med));
}

void Service::removeMed(const Med& med) {
    repo.removeMed(med.getId());
    undoActions.push_back(new UndoDelete(repo, med));
}

void Service::updateMed(const Med& oldMed, std::string name, float price, std::string producer, std::string activeSubstance) {
    Med originalMed = repo.getMed(oldMed.getId());
    repo.updateMed(
        oldMed.getId(), 
        name,
        price,
        producer,
        activeSubstance
    );
    Med updatedMed = repo.getMed(oldMed.getId());
    undoActions.push_back(new UndoUpdate(repo, originalMed, updatedMed));
}

void Service::performUndo() {
    if (!undoActions.empty()) {
        undoActions.back()->doUndo();
        delete undoActions.back();
        undoActions.pop_back();
    }
}

Service::~Service() {
    for (UndoAction* action : undoActions) {
        delete action;
    }
}