//
// Created by student on 29.04.17.
//

#include "StepAction.hh"
//#include "debugf.hh"

SteppingAction::SteppingAction(EventAct * event):EvAct(event)  { }

void SteppingAction::UserSteppingAction(const G4Step * aStep) {
    G4String pname = aStep->GetTrack()->GetDefinition()->GetParticleName();
    G4String volname = aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName();
    G4Track *secTrack;
    G4double energy{0};
    if (pname == "neutron" && volname == "LogGasVol" && aStep->GetNumberOfSecondariesInCurrentStep()) {
        for (unsigned int i = 0; i < aStep->GetNumberOfSecondariesInCurrentStep(); i++) {
            secTrack = aStep->GetSecondary()->at(i);
            if(secTrack->GetDefinition()->GetParticleName()=="proton")
                EvAct->SetProtonSE(secTrack->GetKineticEnergy());
            else
                EvAct->SetTritonSE(secTrack->GetKineticEnergy());
            energy+=secTrack->GetKineticEnergy();
        }
    }
    G4String LastLayername = aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName();
    if (aStep->GetTrack()->GetNextVolume()) {
        G4String Layername = aStep->GetTrack()->GetNextVolume()->GetLogicalVolume()->GetName();
        G4String VolMatName =  aStep->GetTrack()->GetNextVolume()->GetLogicalVolume()->GetMaterial()->GetName();
        if (LastLayername != Layername && (pname == "proton" || pname == "triton") && VolMatName == "WallMat") {
            if (pname == "proton")EvAct->SetProtonEE(aStep->GetTrack()->GetKineticEnergy());
            else EvAct->SetTritonEE(aStep->GetTrack()->GetKineticEnergy());
        }
    }
}