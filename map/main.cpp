#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){

        ft::map<int,int> mymap;
        pair<ft::map<int,int>::iterator,bool> mypair;

        mypair = mymap.insert(pair<int,int>(5,1));
        mypair = mymap.insert(pair<int,int>(9,1));
        mypair.first--;
        std::cout << mypair.first->first << std::endl;
        std::cout << mypair.first->second << std::endl;
}