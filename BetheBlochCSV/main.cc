

#include <G4RunManagerFactory.hh>
#include <G4UImanager.hh>
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGenerator.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

int main(int argc,char** argv) {

    int materialID = 0;        // 0=Si,1=Ar,2=Fe,3=Pb
    double pGeV = 1.0;         // momentum

    auto runManager = G4RunManagerFactory::CreateRunManager();

    runManager->SetUserInitialization(new DetectorConstruction(materialID));
    runManager->SetUserInitialization(new PhysicsList());

    auto run = new RunAction();
    auto event = new EventAction(run, materialID);

    runManager->SetUserAction(new PrimaryGenerator(pGeV));
    runManager->SetUserAction(run);
    runManager->SetUserAction(event);
    runManager->SetUserAction(new SteppingAction(event));

    runManager->Initialize();
    runManager->BeamOn(1000);

    delete runManager;
}
