
#include <iostream>
#include <fstream>
#include <parse_csv.hpp>
#include <stored_table.hpp>
#include <table_scanner.hpp>
#include <set>
#include <TFile.h>
#include <TH1D.h>
#include "TCanvas.h"


int main( ) { std::set<std::string> day;
  std::vector<std::string> time;
  std::vector<double> temperature;

  commata::table_scanner scanner(0);
  scanner.set_field_scanner(0, commata::make_field_translator(day));
  scanner.set_field_scanner(1, commata::make_field_translator(time));
  scanner.set_field_scanner(2, commata::make_field_translator(temperature));
    
  commata::parse_csv(std::ifstream("datasets/processed_data.csv"), std::move(scanner));
  std::cout << temperature[1] << std::endl;

  TCanvas *canvas = new TCanvas("temp", "temperature", 10, 10, 700, 500);
auto histogram = new TH1I{"temperature",
"Temperature;Temperature [#circC];Entries", 300, -20, 40};

  for (int i = 0; i < 150; i++) {
    histogram->Fill(temperature[i]);
  }

  histogram->SetFillColor(kRed + 1);
histogram->Draw();
  canvas->SaveAs("temp.pdf");
}

  
