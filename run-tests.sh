#!/bin/bash

cppcov() {
    python3 /mnt/c/Users/delia/OneDrive/Documente/Bujor/tomfulery/cppcov/cppcov.py "$@"
}

# domain
cppcov src/domain/med.cpp tests/test_domain.cpp

# repo
echo -e "y\nsrc/domain/med.cpp\n" | cppcov src/repository/repo.cpp tests/test_repo.cpp

# service
echo -e "y\nsrc/domain/med.cpp src/repository/repo.cpp\n" | cppcov src/service/service.cpp tests/test_service.cpp

# prescription
echo -e "y\nsrc/domain/med.cpp src/repository/repo.cpp src/medDTO/medDTO.cpp\n" | cppcov src/prescription/prescription.cpp tests/test_prescription.cpp