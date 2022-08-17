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


std::vector<int> myVector(2);

myVector.resize(11);
std::cout << "size: " << myVector.size() << std::endl;
std::cout << "capacity: " << myVector.capacity() << std::endl;
for (size_t i=0;i<myVector.size();i++)
    std::cout << ' ' << myVector[i];
std::cout << '\n';

ft::vector<int> vector(2);

vector.resize(11);
std::cout << "size: " << vector.size() << std::endl;
std::cout << "capacity: " << vector.capacity() << std::endl;

}