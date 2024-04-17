#include <iostream>
#include <assert.h>
#include "../src/prescription/prescription.h"
#include "../src/repository/repo.h"
#include "../src/domain/med.h"
#include "../src/medDTO/medDTO.h"


void test_add_prescripted_med() {
    Repo repo;
    Med med1 = Med("a", 10, "a", "a");
    repo.addMed(med1);

    Prescription prescription(repo);
    assert(prescription.getPrescriptedMeds().size() == 0);

    prescription.add_prescripted_med("a");
    assert(prescription.getPrescriptedMeds().size() == 1);

    // permite duplicate
    prescription.add_prescripted_med("a");
    assert(prescription.getPrescriptedMeds().size() == 2);

    // not in repo
    try {
        prescription.add_prescripted_med("b");
        assert(false);
    }
    catch (std::exception) {
        assert(true);
    }
}

void test_empty() {
    Repo repo;
    Med med1 = Med("a", 10, "a", "a");
    repo.addMed(med1);

    Prescription prescription(repo);
    prescription.add_prescripted_med("a");
    assert(prescription.getPrescriptedMeds().size() == 1);

    prescription.empty();
    assert(prescription.getPrescriptedMeds().size() == 0);
}

void test_generate_random() {
    Repo repo;
    Med med1 = Med("a", 10, "a", "a");
    Med med2 = Med("b", 10, "b", "b");
    repo.addMed(med1);
    repo.addMed(med2);

    Prescription prescription(repo);
    assert(prescription.getPrescriptedMeds().size() == 0);

    prescription.generate_random_prescription(3);
    assert(prescription.getPrescriptedMeds().size() != 0);
    // for (auto elem : prescription.getPrescriptedMeds()) {
    //     std::cout << elem << ' ';
    // }
}

void test_raport() {
    Repo repo;
    Med med1 = Med("a", 10, "a", "a");
    Med med2 = Med("b", 10, "b", "b");
    repo.addMed(med1);
    repo.addMed(med2);

    Prescription prescription(repo);
    prescription.add_prescripted_med("a");
    prescription.add_prescripted_med("a");
    prescription.add_prescripted_med("b");

    std::vector<MedDTO> occurr = prescription.raport();

    assert(occurr[0].count == 2);
    assert(occurr[1].count == 1);
}

int main() {
    test_add_prescripted_med();
    test_empty();
    test_generate_random();
    test_raport();

    std::cout << "All prescription tests passed!\n";
    return 0;
}