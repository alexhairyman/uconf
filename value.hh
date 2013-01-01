// This is an uber simple file K boiz?

#define VAL_DBG 1
#if VAL_DBG
  #define ifdbg(a) a
#else
  #define ifdbg(a) 
#endif

#ifndef VAL_HH
#define VAL_HH


#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

namespace aval
{
  const std::string TOK_CHARS = "abcdefghijklmnopqrstuvwxyz_1234567890";
  class Value
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
    void operator ()(std::string valstr);
    operator std::string();
    operator int();
    // operator long(); // not quite yet
    //operator double();
    operator char*();
    
  };

  class ValueSet
  {
  private:
    std::map<std::string, Value> value_list_; ///< this is the list of values @NOTE the key includes the section as a .
    
  public:
    std::vector<std::string> SplitByLine(std::string alldata);
    std::vector<std::string> Strip(std::vector <std::string> linelist);
    void ParseConfigs(std::vector<std::string> goodlinelist);
    Value GetValue(std::string keypath);
    // std::string SetValue();
    
  };
  //#include "valuetree.hh"
}

#endif
