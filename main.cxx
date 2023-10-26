
#include <iostream>
#include <fstream>
#include <parse_csv.hpp>
#include <stored_table.hpp>
#include <table_scanner.hpp>
#include <set>
#include <TFile.h>
#include <TH1D.h>
#include "TCanvas.h"


int main( ) { 
  std::vector<std::string> day; 
  std::vector<std::string> time;
  std::vector<double> temperature;
    //create vectors to store the data when parsed
  commata::table_scanner scanner(0); //start parsing in first line (no header line)
  scanner.set_field_scanner(0, commata::make_field_translator(day));
  scanner.set_field_scanner(1, commata::make_field_translator(time));
  scanner.set_field_scanner(2, commata::make_field_translator(temperature));
    // the first entry in each line is put in the *day*, the second in the *time* and 
    // the third in the temperature vector
    commata::parse_csv(std::ifstream("datasets/processed_data.csv"), std::move(scanner));
    // parse through the processed_data dataset, based on the scanner specified above
  TCanvas *canvas = new TCanvas("temp", "temperature", 10, 10, 700, 500); // create a new Canvas to plot the histogram on
auto histogram = new TH1I{"temperature data", 
"Temperatures in Lund throughout 1780;Air Temperature [#circC];Entries", 300, -20, 40}; // create histogram, name axis

  for (int i = 0; i < 767; i++) { // loop through the first 767 entries in the temperature vector (1 year) 
    histogram->Fill(temperature[i]); // and fill the histogram with it
  }

  histogram->SetFillColor(kRed + 1);
histogram->Draw();
  canvas->SaveAs("temp.pdf");


   std::vector<std::string> dayavg; // repeat the steps for the Extrated_data dataset
   std::vector<double> temperatureavg;

  commata::table_scanner scanneravg(0); 
  scanneravg.set_field_scanner(0, commata::make_field_translator(dayavg)); 
  scanneravg.set_field_scanner(1, commata::make_field_translator(temperatureavg));
    
  commata::parse_csv(std::ifstream("datasets/Extracted_data.csv"), std::move(scanneravg));

  TCanvas *canvasavg = new TCanvas("tempavg", "temperature", 10, 10, 700, 500); 
auto histogramavg= new TH1I{"temperaturedata",
"Temperatures in Lund throughout 1780;Air Temperature, daily averages [#circC];Entries", 300, -20, 40}; 

  for (int i = 0; i < 365; i++) {   // loop through the first 365 entries in the temperatureavg vector (1 year) 
    histogramavg->Fill(temperatureavg[i]); // and fill the histogram with it
  }

  histogramavg->SetFillColor(kRed + 1);
histogramavg->Draw(); //draw the histogram and save it to tempAvg.pdf
  canvasavg->SaveAs("tempAvg.pdf");
}

  
