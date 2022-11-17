#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        ft::map<int,int> mymap;
        ft::map<int,int> anothermap;
        ft::map<int,int>::iterator it;
        ft::map<int,int>::reverse_iterator reverse_it;

        ft::pair<ft::map<int,int>::iterator,ft::map<int,int>::iterator> ret;
        
        mymap.insert(ft::pair<int,int>(20,5));
        mymap.insert(ft::pair<int,int>(13,3));
        mymap.insert(ft::pair<int,int>(25,5));
        mymap.insert(ft::pair<int,int>(12,5));
        mymap.insert(ft::pair<int,int>(11,5));

        ret = mymap.equal_range(13);
        std::cout << ret.first->first << std::endl;
        std::cout << ret.second->first << std::endl;

        

}