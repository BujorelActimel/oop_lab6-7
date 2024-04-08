#include <iostream>
#include "domain/med.h"
#include "repository/repo.h"
#include "ui/ui.h"

class App {
private:
    UI ui;
    Repo repo;

public:
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
                repo.addMed(med);
                ui.pressAnyKey("Medicament adaugat cu succes!");
            }
            else if (cmd == 2) {
                int id = ui.inputInt("Id: ");
                repo.removeMed(id);
                ui.pressAnyKey("Medicament sters cu succes!");
            }
            else if (cmd == 3) {
                int id = ui.inputInt("Id: ");
                std::string name = ui.inputString("Nume: ");
                float price = ui.inputPrice("Pret: ");
                std::string producer = ui.inputString("Producator: ");
                std::string activeSubstance = ui.inputString("Substanta activa: ");

                Med med{name, price, producer, activeSubstance};
                repo.updateMed(id, med);
                ui.pressAnyKey("Medicament modificat cu succes!");
            }
            else if (cmd == 4) {
                std::cout << repo;
                ui.pressAnyKey("");
            }
            else if (cmd == 5) {
                std::cout << "Neimplementat\n";
                ui.pressAnyKey("");
            }
            else if (cmd == 6) {
                std::cout << "Neimplementat\n";
                ui.pressAnyKey("");
            }
            else if (cmd == 7) {
                std::cout << "Neimplementat\n";
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
