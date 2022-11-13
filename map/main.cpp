#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        ft::map<int,int> mymap;
        ft::map<int,int> another_map;
        ft::map<int,int>::iterator it;
        ft::map<int,int>::iterator it2;

        mymap.insert(pair<int,int>(20,5));
        mymap.insert(pair<int,int>(13,5));
        mymap.insert(pair<int,int>(25,5));
        mymap.insert(pair<int,int>(12,5));

        
        another_map.insert(mymap.begin(),mymap.end());
        
        it = another_map.begin();
        std::cout << it->first << std::endl;
        //std::cout << it->first << std::endl;
}