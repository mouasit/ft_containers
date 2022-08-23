#include <vector>
#include "vector.hpp"

int main()
{
  ft::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  for (size_t i = 0; i < myvector.capacity(); i++)
  {
    std::cout << myvector[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "---------------" << std::endl;

myvector.pop_back();

  for (size_t i = 0; i < myvector.capacity(); i++)
  {
    std::cout << myvector[i] << " ";
  }
  std::cout << std::endl;

  

  return 0;
}