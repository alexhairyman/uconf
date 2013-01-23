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

  ValueError::ValueError(std::string why, std::string offendingdata, bool isrecoverable)
  {
    std::cout << std::endl << std::setfill('~') << std::setw(25) << "" << std::endl <<
      "ERROR:[" << why << "]" << std::endl << "OFFENDING DATA [NULL IF INTERNAL]:[" << offendingdata << "]" << 
      std::endl << "IS RECOVERABLE [NO]: " << isrecoverable << std::endl <<
      std::setw(25) << "" << std::endl;

  }

}
