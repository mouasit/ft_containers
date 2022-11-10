#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
    {
        std::map<int, int> mymap;
        std::map<int,int>::iterator it;
        mymap.insert(std::pair<int,int>(5,1));
        mymap.insert(std::pair<int,int>(2,4));
        mymap.insert(std::pair<int,int>(6,6));
        
        it = mymap.begin();
        std::cout << "std: " << mymap.size() << std::endl;
    }

    {
        ft::map<int, int> mymap;
        ft::map<int,int>::iterator it;
        mymap.insert(pair<int,int>(5,1));
        mymap.insert(pair<int,int>(4,4));
        mymap.insert(pair<int,int>(6,6));
        
        it = mymap.begin();
        std::cout << "ft: " << mymap.size() << std::endl;
    }
}