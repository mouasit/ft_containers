#include <vector>
#include "vector.hpp"

int main ()
{
  ft::vector<int> first(7,100);
  ft::vector<int> second;


  ft::vector<int>::iterator it;

  it = first.begin() + 1;

  second.assign(it,first.end() - 1);
  for (size_t i = 0; i < second.size(); i++)
  {
    std::cout << second[i] << std::endl;
  }
  
/*
 std::vector<int> first(7,100);
  std::vector<int> second;
  std::vector<int> third;
           // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin() + 1;

  second.assign (it,first.end() - 1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';*/
  return 0;
}