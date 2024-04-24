#include <iostream>
#include "../domain/med.h"
#include "ui.h"

void UI::printMenu() const {
    system("clear");
    std::cout << "Meniu:\n";
    std::cout << "1. Adauga medicament\n";
    std::cout << "2. Sterge medicament\n";
    std::cout << "3. Modifica medicament\n";
    std::cout << "4. Afiseaza medicamente\n";
    std::cout << "5. Cauta medicament\n";
    std::cout << "6. Filtrare medicamente\n";
    std::cout << "7. Sortare medicamente\n";
    std::cout << "8. Reteta\n";
    std::cout << "9. Undo\n";
    std::cout << "0. Exit\n";
}


int UI::getCommand() const {
    std::string command;

    while (true) {
        std::cout << "\n>>> ";
        std::cin >> command;

        try {
            int cmd = std::stoi(command);
            if (cmd < 0 || cmd > 9) {
                throw std::exception();
            }
            return cmd;
        } catch (std::exception& e) {
            std::cout << "Comanda invalida. Incercati din nou.\n";
        }
    }

}


void UI::exit() const {
    system("clear");
    std::cout << "La revedere!\n";
}


std::string UI::inputString(const std::string& message) {
    std::string input;
    std::cout << message;
    std::cin >> input;
    return input;
}


int UI::inputInt(const std::string& message) {
    int number;
    while (true) {
        std::cout << message;
        std::string input;
        std::cin >> input;
        try {
            number = std::stoi(input);
            if (number < 0) {
                throw std::exception();
            }
            return number;
        } catch (std::exception& e) {
            std::cout << "Numarul trebuie sa fie un numar natural. Incercati din nou.\n";
        }
    }
}


float UI::inputPrice(const std::string& message) {
    float price;
    while (true) {
        std::cout << message;
        std::string input;
        std::cin >> input;
        try {
            price = std::stof(input);
            if (price < 0) {
                throw std::exception();
            }
            return price;
        } catch (std::exception& e) {
            std::cout << "Pretul trebuie sa fie un numar. Incercati din nou.\n";
        }
    }
}


void UI::pressAnyKey(const std::string& message) const {
    std::cout << message << "\n";
    std::cout << "Apasati orice tasta pentru a continua...";
    std::cin.get();
    std::cin.get();
}

void UI::printMedVector(const std::vector<Med> meds) const {
    std::cout << "[\n";
    for (auto med : meds) {
        std::cout << med << "-------------------------------\n";
    }
    std::cout << "]\n";
}
