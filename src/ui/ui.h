#pragma once

#include <string>
#include <vector>

class UI {
public:
    UI() = default;
    void printMenu() const;
    int getCommand() const;
    std::string inputString(const std::string& message);
    float inputPrice(const std::string& message);
    int inputInt(const std::string& message);
    void exit() const;
    void pressAnyKey(const std::string& message) const;
    ~UI() = default;
    void printMedVector(const std::vector<Med> meds) const;
};
