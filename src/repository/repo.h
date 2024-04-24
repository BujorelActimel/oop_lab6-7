#pragma once

#include "../domain/med.h"
#include <vector>
// #include "../vector/vector.h"

class Repo {
private:
    std::vector<Med> inventory;
    std::string file_name;
    // Vector<Med> inventory;

public:
    Repo();
    Repo(std::string file_name);
    std::vector<Med>& getInventory();
    void setInventory(std::vector<Med> newInventory);

    /**
     * @brief Adds a Med object to the repository's
     * @param m Med object that gets added
    */
    void addMed(Med m);

    /**
     * @brief Removes Med Object from the inventory via the Med id
     * @param id id of the Med that will get removed
    */
    void removeMed(int id);

    /**
     * @brief Updates a Med object's attriubutes with another's
     * @param id id of the Med object that will get updated
     * @param newMed the Med object that will be mimiced
    */
    void updateMed(int id, std::string new_name, double new_price, std::string new_producer, std::string new_active_substance);

    void saveToFile();

    void loadFromFile();

    Med& getMed(int id);

    friend std::ostream& operator<<(std::ostream& os, const Repo& r);

    ~Repo();
};
