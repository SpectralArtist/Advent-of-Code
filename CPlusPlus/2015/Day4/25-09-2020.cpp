#include <iostream>
#include "md5.h"

int main()
{
  const std::string SECRET_KEY = "iwrupvqb";
  const std::string FIRST_SEARCH = "00000";
  const std::string SECOND_SEARCH = "000000";
  long index = 0;

  while (md5(SECRET_KEY + std::to_string(index)).substr(0, 5) != FIRST_SEARCH)
  {
    ++index;
  }

  std::cout << index << std::endl;

  while (md5(SECRET_KEY + std::to_string(index)).substr(0, 6) != SECOND_SEARCH)
  {
    ++index;
  }

  std::cout << index << std::endl;

  return 0;
}