#ifndef VTREE_HH
#define VTREE_HH
#include <map>

//try to take this out
#include <vector>
#include "value.hh"

namespace aval
{
  /** Base value section, it's like a node, and can have subsections, etc. */
  class ValueSection
  {
  private:
    std::string name_; ///< name
    bool has_name_; ///< is it named?
    bool has_sub_sections_; /**< does it have subsections?
                               @todo is this used anywhere */
    std::vector<ValueSection*> sub_sections_; /**< vector of subsections */
    
    bool has_values_; ///< does the ValueSection have values
    std::vector<UValue*> values_; ///< values stored

  public:
    
    ValueSection();
    std::string GetName();
    void SetName(std::string name);
    bool HasName();

    ValueSection* GetSection(std::string name);
    void AddSubSection(ValueSection* section_to_add);
    int SectionExists(std::string name);

    void AddUValue(UValue* uval_to_add);
    UValue* GetUValue(std::string name);
    int UValueExists(std::string name);

    // old stuff for plain Value instead of UVale
    void AddValue(Value* value_to_add); ///< helper function that adds a Value as a UValue
    Value* GetValue(std::string name); ///< same thing, but for getting Values rather than UValues
    int ValueExists(std::string name); ///< you guessed it....


  };

  /** @todo should I remove this brah? Do I really need it */
  class ValueTree
  {
  private:
    ValueSection root_section_;
    
  public:
    /// if valpath.txt exists, refer to it for usage and syntax
    Value RetrieveValPath(std::string valpath);

  };
}
#endif
