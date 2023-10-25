
#include <iostream>
#include <fstream>
#include <parse_csv.hpp>
#include <stored_table.hpp>

int main() {
// test if csv library works
   commata::stored_table table;

  commata::parse_csv(std::ifstream("test.csv"), commata::make_stored_table_builder(table));
  std::cout << table[1][2] << std::endl;
  return 0;
}
