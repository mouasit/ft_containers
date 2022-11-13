#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){

        ft::map<int,int> mymap;
        pair<ft::map<int,int>::iterator,bool> mypair;

        mypair = mymap.insert(pair<int,int>(5,1));
        mypair = mymap.insert(pair<int,int>(9,1));
        mypair = mymap.insert(pair<int,int>(6,1));
        mypair = mymap.insert(pair<int,int>(7,1));
        mypair = mymap.insert(pair<int,int>(9,1));
        std::cout << mypair.first->first << std::endl;
        std::cout << mypair.second << std::endl;
}