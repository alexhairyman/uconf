#include <string>
namespace aval
{
  /// Parent Storage class template
  template <class T> class Storage
  {
  protected:
    T storage_type_;

  public:
    char* template_test() {return (char*)"To be or not to be";}
    void FillType(T setas)
    {
      storage_type_ = setas;
    }

    T AsType()
    {
      return storage_type_;
    }
  };
  //template <> class Storage<int> {}; ///< storage class for integer
  //template <> class Storage<double> {}; ///< storage class for a double
  //template <> class Storage<std::string>{}; ///< Storage for string values
  //template <> class Storage<bool> {}; ///< storage class for integers
  typedef Storage<int> SInt;
  typedef Storage<double> SDouble;
  typedef Storage<std::string> SString;
  typedef Storage<bool> SBool;
}
