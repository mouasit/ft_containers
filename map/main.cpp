#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        std::map<int,int> mymap;
        std::map<int,int> another_map;
        std::map<int,int>::iterator it;
        std::map<int,int>::iterator it2;

        mymap.insert(std::pair<int,int>(20,5));
        mymap.insert(std::pair<int,int>(13,5));
        mymap.insert(std::pair<int,int>(25,5));
        mymap.insert(std::pair<int,int>(12,5));

        another_map.insert(mymap.begin(),mymap.find(25));
        
        it = another_map.begin();
        std::cout << it->first << std::endl;
}