#pragma once

#include <string>

class MedDTO {
public:
    std::string name;
    int count;

    MedDTO(const std::string& name, int count);

    void incCount();
};