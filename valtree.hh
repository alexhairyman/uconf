

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

    std::string name_;
    bool has_name_;
    bool has_sub_sections_;
    std::vector<ValueSection> sub_sections_;
    
    bool has_values_;
    std::vector<Value> values_;

  public:

    ValueSection();
    std::string GetName();
    void SetName(std::string name);
    bool HasName();

    void AddValue(Value* value_to_add);
    void AddSubSection(ValueSection* section_to_add);

    void AddValue(Value value_to_add); ///< takes the pointer and uses the above function
    void AddSubSection(ValueSection section_to_add); ///< same here

    ValueSection* GetSection(std::string name);
    Value* GetValue(std::string name);

    int ValueExists(std::string name);
    int SectionExists(std::string name);

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
