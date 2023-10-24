
#include <iostream>
#include <fstream>
#include "argumentum.h"
#include "argh.h"
#include <parse_csv.hpp>
#include <stored_table.hpp>
int main(int argc, char *argv[]) {
  std::cout << "I am just a code template, you need to implement the "
               "functionality you want to use yourself!"
            << std::endl;

  std::cout << "We were passed " << argc
            << " command line arguments, the first of which was " << argv[0]
            << std::endl;
  std::cout << "With a good CLI library, we could use the command line "
               "arguments to make a useful program."
            << std::endl;

   commata::stored_table table;

  commata::parse_csv(std::ifstream("test.csv"), commata::make_stored_table_builder(table));
  std::cout << table[1][1] << std::endl;
  return 0;
}
