





#ifndef RunAction_h
#define RunAction_h

#include <G4UserRunAction.hh>
#include <fstream>
class G4Event;

class RunAction : public G4UserRunAction {
public:
    RunAction();
    ~RunAction();

    void Write(const G4Event*, double, double, int);

private:
    std::ofstream out;
};

#endif

