









#include <G4VUserDetectorConstruction.hh>

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    DetectorConstruction(int matID);
    G4VPhysicalVolume* Construct() override;

private:
    int materialID;
};
