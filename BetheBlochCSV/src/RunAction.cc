#include "RunAction.hh"
#include <G4Event.hh>
#include <G4PrimaryVertex.hh>
#include <cmath>

RunAction::RunAction() {
   bool file_exists = std::ifstream("bethe_bloch.csv").good();
   out.open("bethe_bloch.csv", std::ios::app);

   if (!file_exists) {
     out << "p_GeV,beta,gamma,betagamma,dEdx_MeV_per_mm,materialID\n";
   }


}

RunAction::~RunAction() {
    out.close();
}

void RunAction::Write(const G4Event* evt, double E, double L, int matID) {
    auto prim = evt->GetPrimaryVertex(0)->GetPrimary(0);
    double p = prim->GetMomentum().mag();
    double m = prim->GetMass();
    double E0 = std::sqrt(p*p + m*m);

    double beta = p / E0;
    double gamma = E0 / m;

    out << p << ","
        << beta << ","
        << gamma << ","
        << beta*gamma << ","
        << (E/L) << ","
        << matID << "\n";
}
