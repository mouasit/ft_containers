
// inserting into a vector
#include <iostream>
#include <vector>
#include "vector.hpp"

int main ()
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::reverse_iterator it;
  
  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  2 + it;
  return 0;
}