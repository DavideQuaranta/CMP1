//
//  main.cpp
//  lab_session_2
//
//  Created by Andrea Rocchi on 07/11/22.


#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "TH1F.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TRandom.h"
#include "TLorentzVector.h"
#include <cstdlib>
#include "TFile.h"
#include "TTree.h"
#include "TLegend.h"
#include "TString.h"
#include <fstream>
#include <iomanip>

using namespace std;

Double_t TwoBodyMomentum(float M, float m1, float m2){
    return sqrt(pow(M, 4) + pow(m1,4) + pow(m2,4) -2*pow(M*m1,2) -2*pow(M*m2,2) -2*pow(m2*m1,2))/(2*M);
}
TLorentzVector NewMomentum(TLorentzVector Old, double new_norm, float mass){

    TLorentzVector New;
    double px, py, pz, E;
    double norm = Old.Vect().Mag();
    px = new_norm*(Old.Px()/norm);
    py = new_norm*(Old.Py()/norm);
    pz = new_norm*(Old.Pz()/norm);
    E = sqrt(px*px + py*py + pz*pz + mass*mass);
    New.SetPxPyPzE(px,py,pz,E);
    return New;

}

// Main Application
int main(){

    float B_mass = 5279, pi_mass = 140, K_mass = 500, p_B = 300; // Measured in MeV
    int N = 10000; // decay number
    double measure_Pi, measure_K;
    std::vector<Double_t> inv_mass, angle, inv_mass_meas;
    Particle Pi(pi_mass, "Pion Meson"), K(K_mass, "K Meson"), B(B_mass, "B meson");
    Detector Det(0.03);
    TLorentzVector Pi_Meas, K_Meas;
    Double_t p_cms, x, y, z;

    B.setMomentum(p_B, 0, 0);


    // create histogram
    TH1F h1("h1","True Invariant Mass",500,5278-100,5278+100);
    TH1F h2("h2","Angle Distribution",500,0,2*M_PI);
    TH1F h3("h3","Measured Invariant Mass",70,5278-500,5278+500);
    TH1F *h4 = new TH1F("h4","0.01",70,5278-1500,5278+1500);
    TH1F *h5 = new TH1F("h5","0.05",70,5278-1500,5278+1500);
    TH1F *h6 = new TH1F("h6","0.1",70,5278-1500,5278+1500);
    THStack *hs = new THStack("hs","Measured Invariant Mass");


    for(int i = 0; i<N; i++){

        TwoBodyDecay(B, Pi, K);

        inv_mass.push_back((Pi.getMomentum()+K.getMomentum()).Mag());
        h1.Fill(inv_mass[i]);

        angle.push_back(Pi.getMomentum().Angle(K.getMomentum().Vect()));
        h2.Fill(angle[i]);

        Det.setSigma(0.03);
        measure_Pi=Det.measure(Pi.getMomentum().Vect());
        measure_K=Det.measure(K.getMomentum().Vect());

        Pi_Meas = NewMomentum(Pi.getMomentum(), measure_Pi, pi_mass);
        K_Meas = NewMomentum(K.getMomentum(), measure_K, K_mass);

        inv_mass_meas.push_back((Pi_Meas + K_Meas).Mag());
        h3.Fill(inv_mass_meas[i]);

        Det.setSigma(0.01);
        measure_Pi=Det.measure(Pi.getMomentum().Vect());
        measure_K=Det.measure(K.getMomentum().Vect());

        Pi_Meas = NewMomentum(Pi.getMomentum(), measure_Pi, pi_mass);
        K_Meas = NewMomentum(K.getMomentum(), measure_K, K_mass);
        h4->Fill((Pi_Meas + K_Meas).Mag());

        Det.setSigma(0.05);
        measure_Pi=Det.measure(Pi.getMomentum().Vect());
        measure_K=Det.measure(K.getMomentum().Vect());

        Pi_Meas = NewMomentum(Pi.getMomentum(), measure_Pi, pi_mass);
        K_Meas = NewMomentum(K.getMomentum(), measure_K, K_mass);
        h5->Fill((Pi_Meas + K_Meas).Mag());

        Det.setSigma(0.1);
        measure_Pi=Det.measure(Pi.getMomentum().Vect());
        measure_K=Det.measure(K.getMomentum().Vect());

        Pi_Meas = NewMomentum(Pi.getMomentum(), measure_Pi, pi_mass);
        K_Meas = NewMomentum(K.getMomentum(), measure_K, K_mass);
        h6->Fill((Pi_Meas + K_Meas).Mag());


    }


    // add labels to axis
    h1.GetXaxis()->SetTitle("Invariant mass");
    h1.GetYaxis()->SetTitle("Counts");
    // create a canvas to draw tower histogram
    TCanvas c1("c1","my canvas",1024,800);
    // change fill color to blue
    h1.SetFillColor(kBlue);
    // draw again the histogram
    h1.Draw();
    c1.SaveAs("invariant_mass.pdf");



    h2.GetXaxis()->SetTitle("Angle (rad)");
    h2.GetYaxis()->SetTitle("Counts ");
    // create a canvas to draw tower histogram
    TCanvas c2("c2","my canvas",1024,800);
    // draw the histogram
    h2.SetFillColor(kRed);
    // draw again the histogram
    h2.Draw();
    c2.SaveAs("angle_distribution.pdf");



    h3.GetXaxis()->SetTitle("Measured Invariant Mass");
    h3.GetYaxis()->SetTitle("Counts ");
    // create a canvas to draw tower histogram
    TCanvas c3("c3","my canvas",1024,800);
    // draw the histogram
    h3.Draw();
    c3.SaveAs("Meas_invariant_mass.pdf");


    h4->SetFillColor(kGreen);
    h5->SetFillColor(kBlue);
    h6->SetFillColor(kRed);
    auto legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->SetHeader("","C"); // option "C" allows to center the header
    legend->AddEntry(h4,"Resolution : 0.01","f");
    legend->AddEntry(h5,"Resolution : 0.05","f");
    legend->AddEntry(h6,"Resolution : 0.1","f");

    hs->Add(h6);
    hs->Add(h5);
    hs->Add(h4);
    TCanvas c4("c2","my canvas",1024,800);
    hs->Draw();
    legend->Draw();

    c4.SaveAs("sum.pdf");



    return 0;
}
