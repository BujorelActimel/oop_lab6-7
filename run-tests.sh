#!/bin/bash

# domain
# ccov src/domain/med.cpp tests/test_domain.cpp

# repo
# echo -e "y\nsrc/domain/med.cpp src/vector/vector.cpp\n" | ccov src/repository/repo.cpp tests/test_repo.cpp

# vector
# echo -e "y\nsrc/domain/med.cpp\n" | ccov src/vector/vector.cpp tests/test_vector.cpp

# service
echo -e "y\nsrc/domain/med.cpp src/vector/vector.cpp src/repository/repo.cpp\n" | ccov src/service/service.cpp tests/test_service.cpp