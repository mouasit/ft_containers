#include <vector>
#include "vector.hpp"

int main ()
{

  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  int myarray = 8;
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it < myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}