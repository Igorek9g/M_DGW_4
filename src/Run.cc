//
// Created by student on 29.04.17.
//#include <G4Run.hh>


#include "Run.hh"

Run::Run()
{ }

Run::~Run()
{ }

void Run::SetEnergyDeposit(G4double protonEn,G4double tritonEn) {
    G4double EnergyDep = (static_cast<G4int>((protonEn + tritonEn) * 10000)) / 10;

    for (auto it = hist.begin(); it != hist.end(); ++it) {
        if (it->first == EnergyDep) {
            it->second++;
            return;
        }
    }
    //std::cout<<EnergyDep<<std::endl;
    hist.insert(std::pair<G4double, G4int>(EnergyDep, 1));
}