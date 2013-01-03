#include "valerr.hh"
#include <cstdlib>

#include <iostream>
#include <iomanip>

namespace aval
{
  void ValueError::ErrorString(std::string tstr)
  {
    std::cout << "ERROR: " << std::setw(10) << std::left << tstr << std::endl;
    exit(1);
    return ;
  }

}
