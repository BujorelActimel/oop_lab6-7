#include "medDTO.h"

MedDTO::MedDTO(const std::string& name, int count) : name(name), count(count) {}

void MedDTO::incCount() {
    count++;
}


