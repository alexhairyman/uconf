#include "valtree.hh"

#include "valerr.hh"


namespace aval
{

  ValueSection::ValueSection()
  {
    this->has_name_ = false;
    this->has_sub_sections_ = false;
    this->has_values_ = false;
  }

  std::string ValueSection::GetName()
  {
    return this->name_;
  }

  bool ValueSection::HasName()
  {
    return this->has_name_;
  }

  void ValueSection::SetName(std::string name)
  {
    this->name_ = name;
    this->has_name_ = true;
  }

  bool ValueSection::ValueExists(std::string name)
  {
    bool tbool = false;
    for(short i = 0; i < this->values_.size(); i++)
    {
      if(this->values_[i].GetName() == name)
      {
        tbool = true;
        break;
      }
    }
    return tbool;
  }

  void ValueSection::AddValue(Value *value_to_add)
  {
    if(!value_to_add->HasName())
      ValueError::ThrowString("NO NAME FOR VALUE");
    else {
      this->values_.push_back(*value_to_add);
      this->has_values_ = true;}
  }

  void ValueSection::AddSubSection(ValueSection *section_to_add)
  {
    if (!section_to_add->HasName())
      ValueError::ThrowString("NO NAME FOR SECTION");
    else {
      this->sub_sections_.push_back(*section_to_add);
      this->has_sub_sections_ = true;}
  }

}
