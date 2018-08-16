#include "myadd.hpp"
#include "./util/util.hpp"
#include <iostream>

int main()
{

  MyAdd my_obj;
  Util my_util;

  my_util.help();

  std::cout << my_obj.add(2, 3) << "\n";
  return 0;
}


