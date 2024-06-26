#include "prescription.h"
// #include "../medDTO/medDTO.h"
#include <cstdlib>
#include <ctime>
#include <fstream>


Prescription::Prescription(Repo& repo) : repo(repo), prescripted_meds() {}

std::vector<std::string> Prescription::getPrescriptedMeds() {
    return prescripted_meds;
}

void Prescription::add_prescripted_med(std::string name) {
    for (auto elem : repo.getInventory()) {
        if (elem.getName() == name) {
            prescripted_meds.push_back(name);
            return;
        }
    }
    throw std::exception();
}

void Prescription::empty() {
    prescripted_meds = std::vector<std::string>();
}

void Prescription::generate_random_prescription(int num_of_meds) {
    srand(time(0));

    std::vector<Med>& inventory = repo.getInventory();

    // if (inventory.size() < 1) {
    //     throw std::runtime_error("There are no meds in the inventory");
    // }

    this->empty();
    for (int i = 0; i < num_of_meds; ++i) {
        int random_index = rand() % inventory.size();
        prescripted_meds.push_back(inventory[random_index].getName());
    }
}

std::vector<MedDTO> Prescription::raport() {
    std::map<std::string, MedDTO> occurrences;
    for (auto med : getPrescriptedMeds()) {
        if (occurrences.find(med) != occurrences.end()) {
            occurrences[med].incCount();
        } else {
            occurrences[med] = MedDTO(med, 1);
        }
    }

    std::vector<MedDTO> result;
    for (const auto& pair : occurrences) {
        result.push_back(pair.second);
    }

    return result;
}

void Prescription::export_prescription(std::string file_name) {
    std::ofstream file(file_name);
    auto meds = getPrescriptedMeds();
    int i = 1;
    for (auto med : meds) {
        file << i++ << ": " << med << '\n';
    }
    file.close();
}

Prescription::~Prescription() {}

// std::ostream& operator<<(std::ostream& os, const Med& med);