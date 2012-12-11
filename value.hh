// This is an uber simple file K boiz?
//#define VAL_DBG

#ifdef VAL_DBG
  #define ifdbg(a) a
#else
  #define ifdbg(a) 
#endif

#ifndef VAL_HH
#define VAL_HH


#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace aval
{
  static std::string TOK_CHARS = "qwertyiopasdfghjklzxcvbnm";
  class Value
  {
  private:
    std::string keyval_;
    static int AsIntegral(std::string value);
    static double AsDouble(std::string value);
    
  public:
    void operator ()(std::string valstr);
    operator std::string();
    operator int();
    // operator long(); // not quite yet
    operator double();
    operator char*();
    
  };

  class ValueSet
  {
  private:
    std::map<std::string, Value> value_list_; ///< this is the list of values @NOTE the key includes the section as a .
    
  public:
    std::vector<std::string> PopulateSet(std::string alldata);
    std::vector<std::string> Strip(std::vector <std::string> linelist);
    void ParseConfigs(std::string goodlinelist);
    Value GetValue(std::string keypath);
    // std::string SetValue();
    
  };
}

#endif
