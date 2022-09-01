#include <vector>
#include "vector.hpp"

int main ()
{
  ft::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  ft::vector<int>::reverse_iterator rit = myvector.rbegin();

  for (; rit != myvector.rend(); ++rit)
  {
    *rit = ++i;
    if (i == 3)
      break;
  }

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}