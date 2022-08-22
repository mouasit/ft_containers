#include <vector>
#include "vector.hpp"

int main()
{
    /*
    ft::Vector<char> myVector(5);
    std::vector<char> vector(5);

    std::cout << std::endl;

    std::cout << "myVector :";

    std::cout << std::endl<< std::endl;

    std::cout << "size() : " << myVector.size();

    std::cout << std::endl;

    std::cout << "capacity() : " << myVector.capacity();

    std::cout << std::endl << std::endl;

    std::cout << "--------------------------";

    std::cout << std::endl << std::endl;

    std::cout << "vector :";

    std::cout << std::endl << std::endl;

    std::cout << "size() : " << vector.size();

    std::cout << std::endl;

    std::cout << "capacity() : " << vector.capacity();

    std::cout << std::endl << std::endl;*/

      ft::vector<int> myvector(10);

  // set some initial content:
  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);
  std::cout << "capacity: " << myvector.capacity() << std::endl;


  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.capacity();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  std::cout << myvector.at(12) << std::endl;

  /*
  std::cout << myvector.capacity() << std::endl;
    for (size_t i=0;i<myvector.capacity();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  myvector.reserve(11);
  std::cout << myvector.capacity() << std::endl;*/
}