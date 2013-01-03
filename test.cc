#include "value.hh"
#include <string>
using namespace std;

int main()
{
  string s1 = 
  "Name=theboss\n#that is my name\n   \nand you can't have it\n";
  string s2 = "";
  aval::Value v1;
  aval::ValueSet vs1;
  std::vector<std::string> vec1 = vs1.SplitByLine(s1);
  std::vector<std::string> gvec1 = vs1.Strip(vec1);
  vs1.ParseConfigs(gvec1);
  
  return 0;
}
