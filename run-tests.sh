#!/bin/bash

ccov src/domain/med.cpp tests/test_domain.cpp
echo -e "y\nsrc/domain/med.cpp\n" | ccov src/repository/repo.cpp tests/test_repo.cpp
echo -e "y\nsrc/domain/med.cpp\n" | ccov src/vector/vector.cpp tests/test_vector.cpp
