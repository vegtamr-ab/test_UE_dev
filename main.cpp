#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

int main()
{
  try
  {
    //Create a string and read it from console
    std::string str;
    getline(std::cin, str);

    //Make all characters in the string lowercase to count the number of symbols in the string properly
    std::transform(str.cbegin(), str.cend(),
                   str.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    //Count how many of each character is in the string and put it in vector
    std::map<const char, std::size_t> symbols;
    for (const char symbol: str)
    {
      const std::size_t num = std::count(str.cbegin(), str.cend(), symbol);
      symbols[symbol] = num;
    }

    //Transform the string as it is said in the task directly into output stream
    std::transform(str.cbegin(), str.cend(),
                   std::ostream_iterator<std::string>(std::cout, ""),
                   [&](const char c){
                     if (1 < symbols[c])
                     {
                       return ")";
                     }
                     else
                     {
                       return "(";
                     }
                   });

    std::cout << '\n';
  }
  catch(const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';

    return 1;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';

    return 2;
  }
  
  return 0;
}
