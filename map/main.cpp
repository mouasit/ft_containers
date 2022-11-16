#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        ft::map<int,int> mymap;
        ft::map<int,int> anothermap;
        ft::map<int,int>::iterator it;
        ft::map<int,int>::reverse_iterator reverse_it;
        
        mymap.insert(ft::pair<int,int>(20,5));
        mymap.insert(ft::pair<int,int>(13,5));
        mymap.insert(ft::pair<int,int>(25,5));
        mymap.insert(ft::pair<int,int>(12,5));

        it = mymap.find(0);
        std::cout << it->second << std::endl;

}