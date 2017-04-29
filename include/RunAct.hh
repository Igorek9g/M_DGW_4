//
// Created by student on 29.04.17.
//

#ifndef M_DGW_4_RUNACT_HH
#define M_DGW_4_RUNACT_HH

#include <G4UserRunAction.hh>

class RunAct : public G4UserRunAction{
    RunAct(){}
    ~RunAct(){}
    EndOfRunAction(){};
    ~EndOfRunAction(){};
};


#endif //M_DGW_4_RUNACT_HH
