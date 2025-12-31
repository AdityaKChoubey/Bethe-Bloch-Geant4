



#include <G4UserEventAction.hh>

class RunAction;

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction*, int);
    void BeginOfEventAction(const G4Event*) override;
    void EndOfEventAction(const G4Event*) override;

    void Add(double edep, double dx);

private:
    double totalE, totalL;
    RunAction* run;
    int materialID;
};
