#include "value.hh"
#include "valerr.hh"

#define scti SingCharToInt
int SingleCharToInt(char c)
{
  char* d = &c;
  int i = atoi(d);
  return i;
}

namespace aval
{
  char* UValue::ToRawData()
  {
    const char* return_message = "Nothing here yet boys";
    return (char*) return_message;
  }

  Value::Value()
  {
    this->has_name_ = false;
    this->has_val_ = false;
  }

  Value::Value(std::string name, std::string valstr)
  {
    this->has_name_ = true;
    this->has_val_ = true;
    this->SetName(&name);
    this->SetValue(&valstr);
  }

  bool Value::HasName()
  {
    return this->has_name_;
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
    this->has_val_ = true;
    this->keyval_ = *valstr;
  }

#ifdef I_WANT_TO_FAIL_NOW_PLZ
  std::string Value::GetStrVal()
  {
    return this->keyval_;
  }
#endif

  std::string Value::operator()()
  {
    return this->keyval_;
  }

  void Value::operator()(std::string valstr)
  {
    this->SetValue(&valstr);
  }

  // Value::operator std::string()
  std::string Value::AsString()
  {
    return this->keyval_;
  }

  // Value::operator int()
  int Value::AsInt()
  {
    int tint;
    for(int i = 0; i < this->keyval_.length(); i++)
      if (std::isdigit(this->keyval_.at(i)) == 0) {
        ValueError ERR("INCORRECT INT ARG", this->keyval_.substr(i, i+1), false); break;}
      else
        tint = Value::AsInteger(this->keyval_);
    
    return tint;
  }

  /// @todo make this accept lower case trues and falses, and 1 or 0
  // Value::operator bool()
  bool Value::AsBool()
  {
    bool tbool;
    if(this->keyval_ == "TRUE" || this->keyval_ == "true" || this->keyval_ == "1")
      tbool = true;
    else if(this->keyval_ == "FALSE" || this->keyval_ == "false" || this->keyval_ == "0")
      tbool = false;
    else{
      ValueError ERR ("INCORRECT BOOL ARG", this->keyval_, false); return NULL;}

    return tbool;
  }

  const char* Value::AsCString()
  {
    return this->keyval_.c_str();
  }

  int Value::AsInteger(std::string value)
  {
    return atoi(value.c_str());
  }

}
