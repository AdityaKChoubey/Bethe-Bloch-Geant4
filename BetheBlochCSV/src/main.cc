

#include <G4RunManager.hh>
#include <G4UImanager.hh>

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGenerator.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

#include <cstdlib>   // for atof, atoi

int main(int argc, char** argv)
{
    // Defaults
    double pGeV = 1.0;      // momentum in GeV
    int materialID = 0;     // 0=Si,1=Ar,2=Fe,3=Pb

    // Read from command line
    if (argc > 1) {
        pGeV = atof(argv[1]);
    }
    if (argc > 2) {
        materialID = atoi(argv[2]);
    }

    auto runManager = new G4RunManager();

    runManager->SetUserInitialization(
        new DetectorConstruction(materialID));

    runManager->SetUserInitialization(
        new PhysicsList());

    auto runAction   = new RunAction();
    auto eventAction = new EventAction(runAction, materialID);

    runManager->SetUserAction(
        new PrimaryGenerator(pGeV));

    runManager->SetUserAction(runAction);
    runManager->SetUserAction(eventAction);
    runManager->SetUserAction(
        new SteppingAction(eventAction));

    runManager->Initialize();
    runManager->BeamOn(100);

    delete runManager;
    return 0;
}

