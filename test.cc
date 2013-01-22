#include "value.hh"
#include "valerr.hh"
#include "valtree.hh"
#include <string>
#include <iostream>

using namespace std;
using namespace aval;

int main()
{
  string s1 = 
  "Name=theboss\n#that is my name\n   \nand you can't have it\n";
  string s2 = "";
  aval::ValueError ve1 ("just a test", "NULL", false);
  aval::Value v1;
  aval::ValueSet vs1;
  std::vector<std::string> vec1 = vs1.SplitByLine(s1);
  std::vector<std::string> gvec1 = vs1.Strip(vec1);
  vs1.ParseConfigs(gvec1);
  

  // here comes the *really good stuff*

  aval::ValueSection rootsec;
  rootsec.SetName("ROOT");
  aval::ValueSection alexsec;
  alexsec.SetName("ALEX");
  aval::ValueSection mesec;
  mesec.SetName("mysec");

  rootsec.AddValue(new Value("enabled", "true"));
  rootsec.AddValue(new Value("author", "alexhairyman"));

  alexsec.AddValue(new Value("first", "alex"));
  alexsec.AddValue(new Value("last", "herrmann"));
  alexsec.AddValue(new Value("nick", "alexhairyman"));
  cout << alexsec.GetValue("first")->AsBool() << endl;
  cout << alexsec.GetValue("last")->AsString() << endl;

  rootsec.AddSubSection(&alexsec);

  //  std::cout << alexsec
  return 0;
}
