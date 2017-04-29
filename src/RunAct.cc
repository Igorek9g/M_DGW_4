//
// Created by student on 29.04.17.
//

#include <G4ios.hh>
#include <EventAct.hh>
#include "RunAct.hh"
#include "Run.hh"
#include "G4UserSteppingAction.hh"
#include "StepAction.hh"

void RunAct::EndOfRunAction (const G4Run *aRun){
    G4int result;
    G4cout<<"number of threads = "<<result<<"\n";

}

class StepAct: public G4UserSteppingAction {
    StepAct(EventAct *act) {}

    ~StepAct() {}

    void UserSteppingAction(const G4Step *step) {
        G4String vname = step->GetTrack()->GetVolume()->GetLogicalVolume()->GetName();
    if(vname =="Log_Tubs")
        Act->SetFlag();
    }
};