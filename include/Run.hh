//
// Created by student on 29.04.17.
//

#include <G4Run.hh>
#include <map>

#ifndef CPROJECT_RUN_HH
#define CPROJECT_RUN_HH

class Run : public G4Run
{
public:
    Run();
    ~Run();
    void SetEnergyDeposit(G4double protonEn,G4double tritonEn);
    std::map <G4double ,G4int> GetHist() const { return hist;};
private:
    std::map <G4double ,G4int> hist;
    G4int result;
    void SetNewEvent(){result++;}
    int GetResult () const {return result;}
};




#endif //CPROJECT_RUN_HH