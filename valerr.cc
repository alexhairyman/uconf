#include "valerr.hh"
#include <iostream>
#include <iomanip>

namespace aval
{
  void ValueError::ThrowString(std::string tstr)
  {
    std::cout << "ERROR: " << std::setw(10) << std::left << tstr << std::endl;
    return ;
  }

}
