#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){

        ft::map<int, int> mymap;
        ft::map<int,int>::iterator it;
        mymap.insert(pair<int,int>(5,1));
        mymap.insert(pair<int,int>(4,8));
        mymap.insert(pair<int,int>(6,6));
        
        it = mymap.end();
       std::cout << "ft: " <<  it->first  << std::endl;
}