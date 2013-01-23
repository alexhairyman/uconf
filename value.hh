// This is an uber simple file K boiz?

#define VAL_DBG 0
#if VAL_DBG
#define ifdbg(a) a
#else
#define ifdbg(a) 
#endif

#ifndef VAL_HH
#define VAL_HH


#include <cstdlib>
#include <string>
#include <cctype>
// #include <iostream>
// #include <iomanip>

namespace aval
{
  const std::string TOK_CHARS = "abcdefghijklmnopqrstuvwxyz_1234567890";

  class UValue
  {
    // TO BE IMPLEMENTED
  };

  class Array : public UValue
  {
    // TO BE IMPLEMENTED
  };

  class Dict : public UValue
  {
    // TO BE IMPLEMENTED
  };

  class Value : public UValue
  { 
  private:
    bool has_name_;
    std::string name_;
    std::string keyval_;
    static int AsIntegral(std::string value);
    static double AsDouble(std::string value);

  public:
    
    /** creates a 'broken' Value, but allows on the fly init later */
    Value();
    /** this will be used when actually parseing(spelling?) and such */
    Value(std::string name, std::string valstr);
    std::string GetName();
    void SetValue(std::string* valstr);
    void SetName(std::string* name);
    bool HasName();
    
    /// @todo replace with AsString
    std::string GetStrVal();
    
    
    std::string AsString();
    int AsInt();
    const char* AsCString();
    bool AsBool();
    // operators
    void operator ()(std::string valstr);
    std::string operator()();

  };
  
}

#endif
