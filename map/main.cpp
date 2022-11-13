#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        ft::map<int,int> mymap;
        ft::map<int,int>::iterator it;
        
        mymap.insert(ft::pair<int,int>(20,5));
        mymap.insert(ft::pair<int,int>(13,5));
        mymap.insert(ft::pair<int,int>(25,5));
        mymap.insert(ft::pair<int,int>(12,5));

        mymap.erase(mymap.begin(),mymap.end());
        it = mymap.begin();
        std::cout << it->first << std::endl;
}