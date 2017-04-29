//
// Created by student on 29.04.17.
//

#include "EventAct.hh"

EventAct::EventAct()
{
    G4cout<<"Event generator is created successfully\t\t\t\t\tOK!!!"<<G4endl;
}

EventAct::~EventAct()
{ G4cout<<G4endl;}

void EventAct::BeginOfEventAction(const G4Event *event)
{
    protonEEnergy = 0;
    protonSEnergy = 0;
    tritonSEnergy = 0;
    tritonEEnergy = 0;
}

void EventAct::EndOfEventAction(const G4Event *event)
{
    Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    run->SetEnergyDeposit(protonSEnergy-protonEEnergy,tritonSEnergy-tritonEEnergy);
}