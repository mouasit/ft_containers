#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        std::map<int,int> mymap;
        std::map<int,int>::iterator it;

        mymap.insert(std::pair<int,int>(20,5));
        mymap.insert(std::pair<int,int>(13,5));
        mymap.insert(std::pair<int,int>(25,5));
        mymap.insert(std::pair<int,int>(12,5));
        it = mymap.begin();
        std::cout << it->first << std::endl;
        mymap.erase(it);
        it = mymap.begin();
        std::cout << it->first << std::endl;
}