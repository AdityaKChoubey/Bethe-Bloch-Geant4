

#include <G4UserSteppingAction.hh>

class EventAction;

class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction(EventAction*);
    void UserSteppingAction(const G4Step*) override;

private:
    EventAction* eventAction;
};


