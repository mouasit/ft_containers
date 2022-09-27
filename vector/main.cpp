#include <vector>
#include "vector.hpp"

int main ()
{

  ft::vector<int> myvector(5,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();

  myvector.insert(it,20,50);

  for (size_t i = 0; i < myvector.size(); i++)
  {
    std::cout << myvector[i] << " ";
  }

  std::cout << std::endl;
  

  return 0;
}