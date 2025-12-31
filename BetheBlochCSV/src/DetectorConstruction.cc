

#include "DetectorConstruction.hh"
#include <G4NistManager.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4SystemOfUnits.hh>

DetectorConstruction::DetectorConstruction(int matID)
: materialID(matID) {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    auto nist = G4NistManager::Instance();

    G4Material* material = nullptr;
    if (materialID == 0) material = nist->FindOrBuildMaterial("G4_Si");
    if (materialID == 1) material = nist->FindOrBuildMaterial("G4_Pb");
    if (materialID == 2) material = nist->FindOrBuildMaterial("G4_H");
    if (materialID == 3) material = nist->FindOrBuildMaterial("G4_W");


    auto worldMat = nist->FindOrBuildMaterial("G4_AIR");

    auto worldBox = new G4Box("World", 1*m, 1*m, 1*m);
    auto worldLV  = new G4LogicalVolume(worldBox, worldMat, "World");
    auto worldPV  = new G4PVPlacement(nullptr, {}, worldLV, "World", nullptr, false, 0);

    auto detBox = new G4Box("Detector", 5*cm, 5*cm, 0.5*cm);
    auto detLV  = new G4LogicalVolume(detBox, material, "Detector");

    new G4PVPlacement(nullptr, {}, detLV, "Detector", worldLV, false, 0);

    return worldPV;
}
