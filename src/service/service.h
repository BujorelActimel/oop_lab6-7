#include "../repository/repo.h"
#include "../domain/med.h"
#include "../undo/undo.h"
#include <functional>

class Service {
private:
    Repo& repo;
    std::vector<UndoAction*> undoActions;

public:
    Service(Repo& repo);
    ~Service();

    void addMed(const Med& med);
    void removeMed(const Med& med);
    void updateMed(const Med& oldMed, std::string name, float price, std::string producer, std::string activeSubstance);

    void performUndo();

    Repo& getRepo();

    Med& searchMed(const std::string& name);
};

std::vector<Med> filterMed(Repo& repo, std::function<bool(const Med&)> filterFunc);