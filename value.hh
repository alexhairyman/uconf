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

#include <vector>
// #include <iostream>
// #include <iomanip>

#include "storage.template.hh"

namespace aval
{
#define STORAGE_TEMPLATE 0
#if STORAGE_TEMPLATE == 1
  template <class T> class Storage{}; ///< Parent Storage class template
  template <> class Storage<int>{}; ///< Storage for integer
  template <> class Storage<double>{}; ///< storage class for a double
  template <> class Storage<std::string>{}; ///< Storage for string values
  template <> class Storage<bool> {};
  typedef Storage<int> SInt;
  typedef Storage<double> SDouble;
  typedef Storage<std::string> SString;
  typedef Storage<bool> SBool;
#endif

  enum Value_t
    {
      VALUE,
      ARRAY,
      DICT
      //,CHILD ///< still berry much in flux right now
    };
  const std::string TOK_CHARS = "abcdefghijklmnopqrstuvwxyz_1234567890";

  class UValue
  {
  protected:
    Value_t vtype_;
  public:
    virtual char* ToRawData(); ///< function for getting at the pure raw data of whatever the contents are, may not be pretty though
    // TO BE IMPLEMENTED
  };

  /// array child element
  /// @warning probably not going to continue to exist, or will inherit from Value
  class Child : public UValue
  {


  };

  /// An array for storage of values
  class Array : public UValue
  {
  private:
    std::vector<UValue*> childs_;
    // TO BE IMPLEMENTED
  };

  /// a dictionary for storage of keyvals
  /// @todo probably use plain Value for this, would make things helluva lot easier
  class Dict : public UValue
  {
  private:
    std::vector<UValue*> childs_;
    // TO BE IMPLEMENTED
  };
  /**
   * @brief The Value class
   * @todo I think I should change the key value to a void* (in a template)
   */
  class Value : public UValue
  { 
  private:
    bool has_name_;
    bool has_val_;

    std::string name_;
    std::string keyval_;
    static int AsInteger(std::string value);
    static double AsDouble(std::string value);

  public:
    
    /** creates a 'broken' Value, but allows on the fly init later */
    Value();
    /** this will be used when actually parseing(spelling?) and such */
    Value(std::string name, std::string valstr);
    std::string GetName(); ///< get name of class
    void SetValue(std::string* valstr); ///< Set value string of class
    void SetName(std::string* name); ///< Set name of class
    bool HasName(); ///< check to make sure the name is set
    


    std::string AsString(); ///< return value string
    int AsInt(); /**< attempt to return as string
                    @warning may fail */
    const char* AsCString(); ///< return as a const char*
    bool AsBool(); /**< attempt to return as bool
                      @warning may fail */
    // operators
    void operator ()(std::string valstr); ///< set value string
    std::string operator()(); ///< return string value

  };
  
}

#endif
