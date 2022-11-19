#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        ft::map<int,int> mymap;
        ft::map<int,int>::const_reverse_iterator it;
        


        it = mymap.rbegin(); 
        
       if(it != mymap.rend())
        std::cout << "hello" << std::endl;
}