#include "value.hh"
#include "valerr.hh"
#include "valtree.hh"
#include <string>
#include <iostream>

using namespace std;
using namespace aval;

int main()
{

  /*************** OLD AND BROKEN ***************/
  // string s1 = 
  // "Name=theboss\n#that is my name\n   \nand you can't have it\n";
  // string s2 = "";
  // aval::ValueError ve1 ("just a test", "NULL", false);
  // aval::Value v1;
  // aval::ValueSet vs1;
  // std::vector<std::string> vec1 = vs1.SplitByLine(s1);
  // std::vector<std::string> gvec1 = vs1.Strip(vec1);
  // vs1.ParseConfigs(gvec1);
  

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
  alexsec.AddValue(new Value("age", "16"));
  alexsec.AddValue(new Value("uses_linux", "TRUE"));

  cout << "first as bool:" << alexsec.GetValue("first")->AsBool() << endl;
  cout << "last as string:" << alexsec.GetValue("last")->AsString() << endl;
  cout << "age as int:" << alexsec.GetValue("age")->AsInt() << endl;
  cout << "first as int:" << alexsec.GetValue("first")->AsInt() << endl;
  cout << "uses_linux as bool:" << alexsec.GetValue("uses_linux")->AsBool() << endl;

  rootsec.AddSubSection(&alexsec);
  cout << "root has alex? returns index or -1 if nonexistant:" << rootsec.SectionExists("ALEX") << endl;
  alexsec.AddSubSection(&mesec);
  cout << "root has alex which has mysec?:" << rootsec.GetSection("ALEX")->SectionExists("mysec") << endl;

  cout << "root has alexsec which has nick?:" << rootsec.GetSection("ALEX")->GetValue("nick")->AsString() << endl;

  //  std::cout << alexsec
  return 0;
}
