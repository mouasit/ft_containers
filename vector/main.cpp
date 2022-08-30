#include <vector>
#include "vector.hpp"

int main(){
  
  ft::vector<int> myvector;
  ft::vector<int>::iterator it;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  it = myvector.end();

  std::cout << *it << std::endl;

}