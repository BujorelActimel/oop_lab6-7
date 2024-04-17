#include <iostream>
#include <vector>
#include <algorithm>
#include "domain/med.h"
#include "repository/repo.h"
#include "service/service.h"
#include "prescription/prescription.h"
#include "ui/ui.h"
#include "medDTO/medDTO.h"

class App {
private:
    UI ui;
    Repo repo;
    Service service;
    Prescription prescription;

public:
    App() : ui(), repo(), service(repo), prescription(service.getRepo()) {}

    void run() {
        while (true) {
            ui.printMenu();

            int cmd = ui.getCommand();

            if (cmd == 0) {
                ui.exit();
                break;
            }
            else if (cmd == 1) {

                std::string name = ui.inputString("Nume: ");
                float price = ui.inputPrice("Pret: ");
                std::string producer = ui.inputString("Producator: ");
                std::string activeSubstance = ui.inputString("Substanta activa: ");

                Med med{name, price, producer, activeSubstance};
                service.getRepo().addMed(med);
                ui.pressAnyKey("Medicament adaugat cu succes!");
            }
            else if (cmd == 2) {
                int id = ui.inputInt("Id: ");
                service.getRepo().removeMed(id);
                ui.pressAnyKey("Medicament sters cu succes!");
            }
            else if (cmd == 3) {
                int id = ui.inputInt("Id: ");
                std::string name = ui.inputString("Nume: ");
                float price = ui.inputPrice("Pret: ");
                std::string producer = ui.inputString("Producator: ");
                std::string activeSubstance = ui.inputString("Substanta activa: ");

                service.getRepo().updateMed(
                    id, 
                    name, 
                    price, 
                    producer, 
                    activeSubstance
                );
                ui.pressAnyKey("Medicament modificat cu succes!");
            }
            else if (cmd == 4) {
                std::cout << service.getRepo();
                ui.pressAnyKey("");
            }
            else if (cmd == 5) {
                std::string name = ui.inputString("Nume: ");

                try {
                    Med& med = service.searchMed(name);
                    std::cout << med;
                    ui.pressAnyKey("");
                } catch (std::exception& e) {
                    ui.pressAnyKey("Medicamentul nu exista!");
                }
            }
            else if (cmd == 6) {
                int option = ui.inputInt("Criteriu: \n1. Pret\n2. Substanta activa\n>>> ");
                if (option == 1) {
                    float price = ui.inputPrice("Pret: ");
                    std::vector<Med> filtered_by_price = filterMed(
                        service.getRepo(),
                        [price](const Med& med) {
                            return med.getPrice() < price;
                        }
                    );
                    std::cout << "Medicamente cu pret mai mic de " << price << ":\n";
                    ui.printMedVector(filtered_by_price);
                }
                else if (option == 2) {
                    std::string activeSubstance = ui.inputString("Substanta activa: ");
                    std::vector<Med> filtered_by_activeSubstance = filterMed(
                        service.getRepo(),
                        [activeSubstance](const Med& med) {
                            return med.getActiveSubstance() == activeSubstance;
                        }
                    );
                    std::cout << "Medicamente cu substanta activa " << activeSubstance << ":\n";
                    ui.printMedVector(filtered_by_activeSubstance);
                }
                ui.pressAnyKey("");
            }
            else if (cmd == 7) {
                int option = ui.inputInt("Criteriu: \n1. Nume\n2. Pret\n3. Producator\n4. Substanta activa\n>>> ");
                if (option == 1) {
                    std::vector<Med>& inventory = service.getRepo().getInventory();
                    std::sort(inventory.begin(), inventory.end(), [](const Med& a, const Med& b) {
                        return a.getName() < b.getName();
                    });
                    std::vector<Med>& sorted_by_name = inventory;
                    std::cout << "Medicamente sortate dupa nume:\n";
                    ui.printMedVector(sorted_by_name);
                }
                else if (option == 2) {
                    std::vector<Med> inventory = service.getRepo().getInventory();
                    std::sort(inventory.begin(), inventory.end(), [](const Med& a, const Med& b) {
                        return a.getPrice() < b.getPrice();
                    });
                    std::vector<Med> sorted_by_price = inventory;
                    std::cout << "Medicamente sortate dupa pret:\n";
                    ui.printMedVector(sorted_by_price);
                }
                else if (option == 3) {
                    std::vector<Med> inventory = service.getRepo().getInventory();
                    std::sort(inventory.begin(), inventory.end(), [](const Med& a, const Med& b) {
                        return a.getProducer() < b.getProducer();
                    });
                    std::vector<Med> sorted_by_producer = inventory;
                    std::cout << "Medicamente sortate dupa producator:\n";
                    ui.printMedVector(sorted_by_producer);
                }
                else if (option == 4) {
                    std::vector<Med> inventory = service.getRepo().getInventory();
                    std::sort(inventory.begin(), inventory.end(), [](const Med& a, const Med& b) {
                        return a.getActiveSubstance() < b.getActiveSubstance();
                    });
                    std::vector<Med> sorted_by_activeSubstance = inventory;
                    std::cout << "Medicamente sortate dupa substanta activa:\n";
                    ui.printMedVector(sorted_by_activeSubstance);
                }
                else {
                    std::cout << "Optiune invalida\n";
                }
                ui.pressAnyKey("");
            }
            else if (cmd == 8) {
                int option = ui.inputInt("Optiuni reteta: \n1. Adauga\n2. Goleste\n3. Genereaza reteta random\n4. Raport\n>>> ");
                if (option == 1) {
                    std::string med_name = ui.inputString("Numele medicamentului: ");
                    try {
                        prescription.add_prescripted_med(med_name);
                        ui.pressAnyKey("Medicament adaugat cu succes!");
                    }
                    catch (std::exception) {
                        ui.pressAnyKey("Nu exista acest medicament");
                    }
                }
                else if (option == 2) {
                    prescription.empty();
                    ui.pressAnyKey("Reteta golita cu succes");
                }
                else if (option == 3) {
                    int num_of_meds = ui.inputInt("Numarul de medicamente: ");
                    prescription.generate_random_prescription(num_of_meds);
                    ui.pressAnyKey("Reteta generata cu succes");
                }
                else if (option == 4) {
                    for (auto elem : prescription.raport()) {
                        std::cout << elem.name << ": " << elem.count << '\n';
                    }
                    ui.pressAnyKey("");
                }
            }
        }
    }
};


int main() {
    App app;
    app.run();
    return 0;
}
