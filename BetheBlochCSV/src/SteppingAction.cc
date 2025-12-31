




#include "SteppingAction.hh"
#include "EventAction.hh"
#include <G4Step.hh>

SteppingAction::SteppingAction(EventAction* ea)
: eventAction(ea) {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    auto edep = step->GetTotalEnergyDeposit();
    auto dx   = step->GetStepLength();
    if (dx > 0) eventAction->Add(edep, dx);
}
