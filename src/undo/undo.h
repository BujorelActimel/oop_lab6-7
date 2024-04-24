#include "../domain/Med.h"
#include "../repository/Repo.h"

// UndoAction.h
class UndoAction {
public:
    virtual void doUndo() = 0;
    virtual ~UndoAction() {}
};

class UndoAdd : public UndoAction {
    Med med;
    Repo& repo;
public:
    UndoAdd(Repo& repo, const Med& med);
    void doUndo() override;
};

class UndoDelete : public UndoAction {
    Med med;
    Repo& repo;
public:
    UndoDelete(Repo& repo, const Med& med);
    void doUndo() override;
};

class UndoUpdate : public UndoAction {
    Med oldMed;
    Med newMed;
    Repo& repo;
public:
    UndoUpdate(Repo& repo, const Med& oldMed, const Med& newMed);
    void doUndo() override;
};