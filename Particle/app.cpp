//app.cpp
#include "Particle.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"

int main() {
  float mass = 11;
  float x[3] = {1,1,1};
  float v[3] = {2,2,2};
  Particle* myParticle = new Particle(mass, x, v);
  myParticle->print();
  delete myParticle;

  int N = 1000;
  Ensemble* myEnsemble = new Ensemble(N, "normal", 10, 0.5, 5, 1, 20, 4);
  myEnsemble->print();

  //Now let's create the graphs for the distributions with ROOT
  TH1F h1("h1","Mass distribution",100,7.0,13.0);
  h1.GetXaxis()->SetTitle("Mass [kg]");
  h1.GetYaxis()->SetTitle("Events");

  TH1F h2("h2","X distribution",100,0,10.0);
  h2.GetXaxis()->SetTitle("X [m]");
  h2.GetYaxis()->SetTitle("Events");

  TH1F h3("h3","V distribution",100,10.0,30.0);
  h2.GetXaxis()->SetTitle("V [m/s]");
  h2.GetYaxis()->SetTitle("Events");

  for(int i = 0; i < N; i++){
    Particle aParticle = myEnsemble->getParticle(i);
    h1.Fill(aParticle.getMass());
    h2.Fill(aParticle.getx(1));
    h3.Fill(aParticle.getv(1));
  }

  TCanvas c1("c1","my canvas",1024,800);
  h1.Fit("gaus");
  h1.Draw();
  c1.SaveAs("Mass.pdf");
  TCanvas c2("c2","my canvas",1024,800);
  h2.Fit("gaus");
  h2.Draw();
  c2.SaveAs("X.pdf");
  TCanvas c3("c3","my canvas",1024,800);
  h3.Fit("gaus");
  h3.Draw();
  c3.SaveAs("V.pdf");

  TString rootfname("./data.root");
  TFile* orootfile = new TFile( rootfname, "RECREATE");
  // Create a new TTree object
  TTree* tree = new TTree("datatree", "tree containing our data");
  tree->Branch("value", &(*myEnsemble),  "value/D");

  tree->Fill();
  // Actually write tree in file on disk
  tree->Write();
  // Print some info about the tree
  tree->Print();
  // ==== Done using the TTree
  delete tree;
  // Critical to close the file!
  orootfile->Close();

  delete myEnsemble;

  return 0;
}
