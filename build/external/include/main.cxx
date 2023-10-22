
main.cxx
#include "Rectangle.h"
#include "GeometryIO.h"
#include <iostream>
#include <string>


int main(int argc, char *argv[]) {
  bool hasthreearguments = (argc == 3);
  if (hasthreearguments) {
    std::string programName{argv[0]};
    char firstCharacter{*(argv[1])};
    size_t lengthofstring{programName.size()};
    int thirdArgument{std::atoi(argv[2])};
    int sumofCharacters{0};
    int currentindex{0};
    std::string secondargument{argv[1]};
    std::cout << "We were passed " << argc << " command line arguments, the first of which was " << argv[0] << std::endl;
    while (true) {
      sumofCharacters += secondargument[currentindex++];
      if (currentindex >= static_cast<int>(secondargument.size())) {
        break;
      }
    }
    int result = (sumofCharacters ^ firstCharacter * 3) << (lengthofstring & 0x1f);
    if (result == thirdArgument){
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
  std::cout << "Please enter the width and height of a rectangle\n";
    Geometry::Rectangle r{};
    std::cin >> r;
    std::cout << "The rectangle: " << r << " has area: " << r.area() << std::endl;
    std::cout << "Please enter the radius of a circle\n";
    return 0;
}
