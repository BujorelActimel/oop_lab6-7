#include <iostream>
#include "domain/med.h"
#include "repository/repo.h"
#include "service/service.h"
#include "ui/ui.h"

class App {
private:
    UI ui;
    Repo repo;
    Service service;

public:
    App() : ui(), repo(), service(repo) {}

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
                    Vector<Med> filtered_by_price = filterMed(
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
                    Vector<Med> filtered_by_activeSubstance = filterMed(
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
                    Vector<Med> sorted_by_name = sortedMed(
                        service.getRepo(),
                        [](const Med& med1, const Med& med2) {
                            return med1.getName() > med2.getName();
                        }
                    );
                    std::cout << "Medicamente sortate dupa nume:\n";
                    ui.printMedVector(sorted_by_name);
                }
                else if (option == 2) {
                    Vector<Med> sorted_by_price = sortedMed(
                        service.getRepo(),
                        [](const Med& med1, const Med& med2) {
                            return med1.getPrice() > med2.getPrice();
                        }
                    );
                    std::cout << "Medicamente sortate dupa pret:\n";
                    ui.printMedVector(sorted_by_price);
                }
                else if (option == 3) {
                    Vector<Med> sorted_by_producer = sortedMed(
                        service.getRepo(),
                        [](const Med& med1, const Med& med2) {
                            return med1.getProducer() > med2.getProducer();
                        }
                    );
                    std::cout << "Medicamente sortate dupa producator:\n";
                    ui.printMedVector(sorted_by_producer);
                }
                else if (option == 4) {
                    Vector<Med> sorted_by_activeSubstance = sortedMed(
                        service.getRepo(),
                        [](const Med& med1, const Med& med2) {
                            return med1.getActiveSubstance() > med2.getActiveSubstance();
                        }
                    );
                    std::cout << "Medicamente sortate dupa substanta activa:\n";
                    ui.printMedVector(sorted_by_activeSubstance);
                }
                ui.pressAnyKey("");
            }
        }
    }
};


int main() {
    App app;
    app.run();
    return 0;
}
