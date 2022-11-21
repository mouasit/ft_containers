#include "map.hpp"
#include <map>
#include <iterator>
#include "../utils/pair.hpp"
int main(){
        ft::map<int,int> mymap;

        mymap.insert(ft::pair<int,int>(1,2));
        mymap.insert(ft::pair<int,int>(2,2));
        mymap.insert(ft::pair<int,int>(3,2));
        mymap.insert(ft::pair<int,int>(4,2));
}
        
