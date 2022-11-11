#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){

        ft::map<int, int> mymap;
        ft::map<int,int>::iterator it;
        mymap.insert(pair<int,int>(5,1));
        mymap.insert(pair<int,int>(3,1));
        mymap.insert(pair<int,int>(8,1));
        
        it = mymap.begin();
        it--;
       std::cout << "ft: " <<  it->first  << std::endl;
}