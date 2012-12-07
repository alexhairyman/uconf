#include "value.hh"

#define scti SingCharToInt
int SingleCharToInt(char c)
{
  char* d = &c;
  int i = atoi(d);
  return i;
}

namespace aval
{

  void Value::operator()(std::string valstr)
  {
    this->keyval_ = valstr;
  }

  Value::operator std::string()
  {
    return this->keyval_;
  }

  Value::operator int()
  {
    return Value::AsIntegral(this->keyval_);
  }

  int Value::AsIntegral(std::string value)
  {
    return atoi(value.c_str());
  }

  // ValueSet functions

  /* 1. [PopulateSet] First we split it up by line
   * 2. [Strip] then we strip all the comments and blank/whitespace only lines also does a check for '='
   * 3. [ParseConfigs] then we go through each line and parse, whenever a section is hit, it is added as prefix
   *    to the key value */
  std::vector<std::string> ValueSet::PopulateSet(std::string alldata)
  {
    ifdbg(std::cout << "beginning to populate" << std::endl;)
    std::vector<std::string> strings;
    unsigned int cpos = 0;
    unsigned int bpos = 0;
    for(unsigned int i = 0; i < alldata.length(); i++)
    {
      if (alldata[i] != '\n')
        cpos = i;
      else
      {
        cpos = i;
        strings.push_back(alldata.substr(bpos, (cpos - bpos)));
        ifdbg(std::cout << "[" << bpos << "] [" << cpos << "] " << alldata.substr(bpos, (cpos - bpos)) << std::endl;)
        bpos = cpos + 1;
      }
    }
    return strings;
  }

  std::vector<std::string> ValueSet::Strip(std::vector <std::string> linelist)
  {
    std::vector<std::string> tll;
    for(unsigned short i = 0; i < linelist.size(); i++)
    {
      ifdbg(std::cout << "~~~~~~~~~~\n" << linelist[i] << std::endl;)
      if (linelist[i].find_first_of(TOK_CHARS.c_str()) < linelist[i].find_first_of("#"))
      {
        ifdbg(std::cout << "passed: not comment/whitespace" << std::endl;)

        if(linelist[i].find_first_of("=") != std::string::npos)
        {
          ifdbg(std::cout << "  passed: has '=' sign" << std::endl;)
          tll.push_back(linelist[i]);
        }
        else
        {
          ifdbg(std::cout << "  failed: doesn't have '=' sign" << std::endl;)
        }

      }
      else if (linelist[i].find_first_not_of(" \n\r\t\v") == std::string::npos)
      {
        ifdbg(std::cout << "failed: whitespace" << std::endl;)
      }
      else
      {
        ifdbg(std::cout << "failed: comment" << std::endl;)
      }
    }
    return tll;
  }

}
