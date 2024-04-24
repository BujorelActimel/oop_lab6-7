#include "undo.h"

// undo adauga
UndoAdd::UndoAdd(Repo& repo, const Med& med) : repo(repo), med(med) {}

void UndoAdd::doUndo() {
    repo.removeMed(med.getId());
}

//undo sterge
UndoDelete::UndoDelete(Repo& repo, const Med& med) : repo(repo), med(med) {}

void UndoDelete::doUndo() {
    repo.addMed(med);
}

//undo modifica
UndoUpdate::UndoUpdate(Repo& repo, const Med& oldMed, const Med& newMed) : repo(repo), oldMed(oldMed), newMed(newMed) {}

void UndoUpdate::doUndo() {
    repo.updateMed(
        oldMed.getId(), 
        oldMed.getName(), 
        oldMed.getPrice(),
        oldMed.getProducer(),
        oldMed.getActiveSubstance()
    );
}