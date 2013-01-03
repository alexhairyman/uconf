#ifndef VERR_HH
#define VERR_HH

#include <string>

namespace aval
{
  class ValueError
  {
  private:
    std::string why_;
    std::string offending_data_;
    bool isrecoverable_;
  public:
    ValueError(std::string why, std::string offendingdata, bool isrecoverable);
    static void ErrorString(std::string tstr);

  };
}

#endif
