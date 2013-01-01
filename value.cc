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
  Value::Value()
  {
    this->has_name_ = false;
  }

  Value::Value(std::string name, std::string valstr)
  {
    this->has_name_ = false;
    this->SetName(&name);
    this->SetValue(&valstr);
  }

  std::string Value::GetName()
  {
    return this->name_;
  }

  /** @todo why the pointer? should I make the private variables pointers? */
  void Value::SetName(std::string* name)
  {
    this->name_ = *name;
    this->has_name_ = true;
  }

  /** @todo same, why the pointer */
  void Value::SetValue(std::string *valstr)
  {
    this->keyval_ = *valstr;
  }

  void Value::operator()(std::string valstr)
  {
    this->SetValue(&valstr);
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
