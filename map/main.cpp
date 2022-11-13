#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        std::map<int,int> mymap;
        std::map<int,int>::iterator it;

        mymap.insert(std::pair<int,int>(5,5));
        mymap.insert(std::pair<int,int>(4,5));
        mymap.insert(std::pair<int,int>(8,5));

        it = mymap.begin();
        std::cout << it->first << std::endl;
        /*------------------------*/
        mymap.insert(it,std::pair<int,int>(9,5));

        it = mymap.begin();
        it++;
        it++;
        it++;
        std::cout << it->first << std::endl;
}