#include "../src/service/service.h"
#include "../src/repository/repo.h"
#include "../src/domain/med.h"
#include <vector>
#include <assert.h>
#include <iostream>

void test_crud_undo() {
    Repo repo;
    Service service(repo);

    Med med1("a", 1, "a", "a");
    Med med2("b", 2, "b", "b");

    service.addMed(med1);
    service.addMed(med2);
    assert(service.getRepo().getInventory().size() == 2);

    service.performUndo();
    assert(service.getRepo().getInventory().size() == 1);

    service.removeMed(service.getRepo().getMed(1));
    assert(service.getRepo().getInventory().size() == 0);
    service.performUndo();
    assert(service.getRepo().getInventory().size() == 1);

    service.updateMed(med1, "d", 10, "d", "d");
    assert(service.getRepo().getMed(1).getName() == "d");
    service.performUndo();
    assert(service.getRepo().getMed(1).getName() != "d");
}

void test_searchMed() {
    Repo repo;
    Service service(repo);

    Med med1("a", 1, "a", "a");
    Med med2("b", 2, "b", "b");

    service.addMed(med1);
    service.addMed(med2);

    assert(service.searchMed("a").getName() == "a");
    assert(service.searchMed("b").getName() == "b");
    
    try {
        service.searchMed("c");
        assert(false);
    } catch (std::exception& e) {
        assert(true);
    }
}

void test_filter() {
    Repo repo;
    Service service(repo);

    service.addMed(Med(
        "a", 
        10, 
        "a", 
        "a"
    ));
    service.addMed(Med(
        "b", 
        20, 
        "b", 
        "b"
    ));

    std::vector<Med> filtered_by_price = filterMed(
        service.getRepo(), 
        [](const Med& med) {
            return med.getPrice() < 20;
        }
    );
    assert(filtered_by_price.size() == 1);

    std::vector<Med> filtered_by_activeSubstance = filterMed(
        service.getRepo(), 
        [](const Med& med) {
            return med.getActiveSubstance() == "a";
        }
    );
    assert(filtered_by_activeSubstance.size() == 1);
}

int main() {
    test_crud_undo();
    test_searchMed();
    test_filter();
    
    std::cout << "All service tests passed!\n";
    return 0;
}