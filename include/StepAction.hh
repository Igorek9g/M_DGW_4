//
// Created by student on 29.04.17.
//
#ifndef HE3_STEPACTION_HH
#define HE3_STEPACTION_HH

#include "EventAct.hh"
#include "G4UserSteppingAction.hh"
#include "G4SystemOfUnits.hh"

class EventAct;

class SteppingAction : public G4UserSteppingAction
{
public:
    SteppingAction(EventAct*);
    virtual ~SteppingAction(){}
    void UserSteppingAction(const G4Step*);
private:
    EventAct*                       EvAct;
};

#endif //HE3_STEPACTION_HH