#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        std::map<int,int> mymap;
        std::map<int,int>::iterator it;
        std::map<int,int>::reverse_iterator reverse_it;
        

        
        mymap.insert(std::pair<int,int>(20,5));
        mymap.insert(std::pair<int,int>(13,5));
        mymap.insert(std::pair<int,int>(25,5));
        mymap.insert(std::pair<int,int>(12,5));

        reverse_it = mymap.rbegin();
        std::cout << (*reverse_it).first << std::endl;
}