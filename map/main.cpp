#include "map.hpp"
#include <cstddef>
#include <map>
#include "../utils/pair.hpp"
int main(){
        std::map<int,int> mymap;
        std::map<int,int>::iterator it;

        size_t size;
        mymap.insert(std::pair<int,int>(20,5));
        mymap.insert(std::pair<int,int>(13,5));
        mymap.insert(std::pair<int,int>(25,5));
        mymap.insert(std::pair<int,int>(12,5));

        size = mymap.erase(20);
        size = mymap.erase(13);
        size = mymap.erase(13);

        std::cout << size << std::endl;
}