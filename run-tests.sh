#!/bin/bash

# domain
ccov src/domain/med.cpp tests/test_domain.cpp

# repo
echo -e "y\nsrc/domain/med.cpp src/vector/vector.cpp\n" | ccov src/repository/repo.cpp tests/test_repo.cpp

# service
echo -e "y\nsrc/domain/med.cpp src/vector/vector.cpp src/repository/repo.cpp\n" | ccov src/service/service.cpp tests/test_service.cpp

# prescription
echo -e "y\nsrc/domain/med.cpp src/repository/repo.cpp src/medDTO/medDTO.cpp\n" | ccov src/prescription/prescription.cpp tests/test_prescription.cpp