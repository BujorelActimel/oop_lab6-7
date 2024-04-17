#include <vector>
#include <string>
#include <map>
#include "../repository/repo.h"

class Prescription {
private:
    std::vector<std::string> prescripted_meds; 
    Repo& repo;

public:
    Prescription(Repo& repo);

    std::vector<std::string> getPrescriptedMeds();
    
    void add_prescripted_med(std::string name);
    
    void empty();
    
    void generate_random_prescription(int num_of_meds);
    
    void export_prescription();
    
    friend std::ostream& operator<<(std::ostream& os, const Med& med);

    std::vector<MedDTO> raport();
    
    ~Prescription();
};