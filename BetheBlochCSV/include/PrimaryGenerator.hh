


#ifndef PrimaryGenerator_h
#define PrimaryGenerator_h

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGenerator(double pGeV);
    void GeneratePrimaries(G4Event*) override;

private:
    G4ParticleGun* gun;
    double p;
};

#endif
