
#include <iostream>
#include <argh.h>
#include <argumentum/argparse.h>
#include <fstream>
#include <parse_csv.hpp>
#include <stored_table.hpp>
using namespace std;
using namespace argumentum;
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

   //argumentum code for main function
   //In this example the program accepts integers and 
   //finds the largest one. If the option --sum is passed 
   //to the program, the numbers are summed, instead.
   
   vector<int> numbers;
   bool isSum = false;

   auto parser = argument_parser{};
   auto params = parser.params();
   parser.config().program( argv[0] ).description( "Accumulator" );
   params.add_parameter( numbers, "N" ).minargs( 1 ).metavar( "INT" ).help( "Integers" );
   params.add_parameter( isSum, "--sum", "-s" )
         .nargs( 0 )
         .help( "Sum the integers (default: find the max)" );

   if ( !parser.parse_args( argc, argv, 1 ) )
      return 1;

   auto mmax = []( auto&& a, auto&& b ) { return max( a, b ); };
   auto acc = isSum ? accumulate( numbers.begin(), numbers.end(), 0 )
                    : accumulate( numbers.begin(), numbers.end(), INT_MIN, mmax );
   cout << acc << "\n";

//csv code  
   commata::stored_table table;

  commata::parse_csv(std::ifstream("test.csv"), commata::make_stored_table_builder(table));
  std::cout << table[1][1] << std::endl;
  return 0;
}
