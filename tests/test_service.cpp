#include "../src/service/service.h"
#include "../src/repository/repo.h"
#include "../src/domain/med.h"
#include <assert.h>
#include <iostream>

void test_searchMed() {
    Repo repo;
    Service service(repo);

    Med med1("a", 1, "a", "a");
    Med med2("b", 2, "b", "b");

    service.getRepo().addMed(med1);
    service.getRepo().addMed(med2);

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

    service.getRepo().addMed(Med(
        "a", 
        10, 
        "a", 
        "a"
    ));
    service.getRepo().addMed(Med(
        "b", 
        20, 
        "b", 
        "b"
    ));

    Vector<Med> filtered_by_price = filterMed(
        service.getRepo(), 
        [](const Med& med) {
            return med.getPrice() < 20;
        }
    );
    assert(filtered_by_price.size() == 1);

    Vector<Med> filtered_by_activeSubstance = filterMed(
        service.getRepo(), 
        [](const Med& med) {
            return med.getActiveSubstance() == "a";
        }
    );
    assert(filtered_by_activeSubstance.size() == 1);
}

void test_sort() {
    Repo repo;
    Service service(repo);

    service.getRepo().addMed(Med(
        "b", 
        20, 
        "b", 
        "b"
    ));
    service.getRepo().addMed(Med(
        "a", 
        10, 
        "a", 
        "a"
    ));
    assert(service.getRepo().getInventory().get(0).getName() == "b");

    Vector<Med> sorted_by_name = sortedMed(
        service.getRepo(), 
        [](const Med& med1, const Med& med2) {
            return med1.getName() > med2.getName();
        }
    );

    assert(sorted_by_name.get(0).getName() == "a");
}

int main() {
    test_searchMed();
    test_filter();
    test_sort();
    
    std::cout << "All service tests passed!\n";
    return 0;
}