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
    static void ThrowString(std::string tstr);

  };
}
