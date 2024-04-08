#pragma once

#include <string>

class Med {
private:
    static int nextId;
    int id;
    std::string name;
    float price;
    std::string producer;
    std::string activeSubstance;

public:
    Med();

    Med(std::string name, float price, std::string producer, std::string activeSubstance);

    Med(const Med& m);

    int getId() const;
    std::string getName() const;
    float getPrice() const;
    std::string getProducer() const;
    std::string getActiveSubstance() const;

    void setName(std::string name);
    void setPrice(float price);
    void setProducer(std::string producer);
    void setActiveSubstance(std::string activeSubstance);

    friend std::ostream& operator<<(std::ostream& os, const Med& med);

    bool operator==(const Med& other) const;

    ~Med();
};
