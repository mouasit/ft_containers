#include <vector>
#include "vector.hpp"

int main(){
  ft::vector<int> myvector(5);
  ft::vector<int> myvectorSwap(10);

  myvector.swap(myvectorSwap);

  std::cout << "swap01: ";
  for (size_t i = 0; i < myvectorSwap.capacity(); i++)
  {
    std::cout << myvectorSwap[i] << " ";
  }

  std::cout << std::endl;
  
  std::cout << "swap02: ";

  for (size_t i = 0; i < myvector.capacity(); i++)
  {
    std::cout << myvector[i] << " ";
  }

  std::cout << std::endl;

/*
  for (size_t i = 0; i < myvector.capacity(); i++)
  {
    std::cout << myvector[i];
  }

  std::cout  << std::endl;
  
  for (size_t i = 0; i < myvectorSwap.capacity(); i++)
  {
    std::cout << myvectorSwap[i];
  }

   std::cout << std::endl;
  */

}