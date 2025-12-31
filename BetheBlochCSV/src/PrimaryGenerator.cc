


#include "PrimaryGenerator.hh"

#include <G4MuonMinus.hh>
#include <G4SystemOfUnits.hh>
#include <cmath>

// 🔹 Constructor
PrimaryGenerator::PrimaryGenerator(double pGeV)
{
    gun = new G4ParticleGun(1);

    gun->SetParticleDefinition(G4MuonMinus::Definition());
    gun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));

    // Convert GeV → internal Geant4 units (MeV)
    p = pGeV * GeV;
}

// 🔹 Generate event
void PrimaryGenerator::GeneratePrimaries(G4Event* event)
{
    auto mass = gun->GetParticleDefinition()->GetPDGMass(); // MeV
    auto E = std::sqrt(p * p + mass * mass);

    gun->SetParticleEnergy(E - mass); // kinetic energy
    gun->GeneratePrimaryVertex(event);
}

