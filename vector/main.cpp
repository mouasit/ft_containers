#include <vector>
#include "vector.hpp"

int main ()
{
  ft::vector<int> myvector;
  ft::vector<int>::iterator it;

  std::cout << "capacity before: " << myvector.capacity() << std::endl;

  it = myvector.end();

  myvector.insert(it,40);
  std::cout << "capacity after: " << myvector.capacity() << std::endl;

  for (size_t i = 0; i < myvector.capacity(); i++)
  {
    std::cout << myvector[i] << " "; 
  }

  std::cout << std::endl;
  /*
  

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
*/
  return 0;
}