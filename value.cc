#include "value.hh"

#define scti SingCharToInt
int SingleCharToInt(char c)
{
  char* d = &c;
  int i = atoi(d);
  return i;
}

namespace aval
{

  void Value::operator()(std::string valstr)
  {
    this->keyval_ = valstr;
  }

  Value::operator std::string()
  {
    return this->keyval_;
  }

  Value::operator int()
  {
    return Value::AsIntegral(this->keyval_);
  }

  int Value::AsIntegral(std::string value)
  {
    return atoi(value.c_str());
  }
}
