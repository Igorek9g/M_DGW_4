//
// Created by student on 29.04.17.
//

#ifndef M_DGW_4_EVENTACT_HH
#define M_DGW_4_EVENTACT_HH

 #ifndef CPROJECT_EVENTACT_HH
#define CPROJECT_EVENTACT_HH

#include "G4UserEventAction.hh"
#include "G4RunManager.hh"
#include "Run.hh"

class EventAct : public G4UserEventAction
{
public:
    EventAct();
    ~EventAct();
    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
    void SetProtonSE(G4double energy){protonSEnergy = energy;}
    void SetTritonSE(G4double energy){tritonSEnergy = energy;}
    void SetProtonEE(G4double energy){protonEEnergy = energy;}
    void SetTritonEE(G4double energy){tritonEEnergy = energy;}

private:
    G4double protonEEnergy, tritonEEnergy, protonSEnergy, tritonSEnergy;
    bool flag;
protected:


};

#endif //CPROJECT_EVENTACT_HH
#endif //M_DGW_4_EVENTACT_HH
