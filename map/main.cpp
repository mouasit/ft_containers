#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        ft::map<int,char> mymap;

        mymap.insert(ft::pair<int,char>(1,2));
        mymap.insert(ft::pair<int,char>(2,2));
        mymap.insert(ft::pair<int,char>(3,2));

        ft::map<int, char>::reverse_iterator my_rit2(mymap.end());
        ft::map<int, char>::const_reverse_iterator c_it;

        c_it = my_rit2;
        std::cout << c_it->first << std::endl;
}