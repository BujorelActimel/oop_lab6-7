#include "../repository/repo.h"
#include "../domain/med.h"
#include <functional>

class Service {
private:
    Repo repo;

public:
    Service(Repo& repo);

    Repo& getRepo();

    Med& searchMed(const std::string& name);
};

Vector<Med> filterMed(Repo& repo, std::function<bool(const Med&)> filterFunc);

Vector<Med> sortedMed(Repo& repo, std::function<bool(const Med&, const Med&)> sortFunc);