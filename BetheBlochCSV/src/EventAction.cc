



#include "EventAction.hh"
#include "RunAction.hh"
#include <G4Event.hh>

EventAction::EventAction(RunAction* r, int m)
: run(r), materialID(m) {}

void EventAction::BeginOfEventAction(const G4Event*) {
    totalE = 0;
    totalL = 0;
}

void EventAction::Add(double e, double l) {
    totalE += e;
    totalL += l;
}

void EventAction::EndOfEventAction(const G4Event* evt) {
    run->Write(evt, totalE, totalL, materialID);
}

