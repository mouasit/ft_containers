#include "map.hpp"
#include <map>
#include "../utils/pair.hpp"
int main(){
        ft::map<int,int> mymap;
        ft::map<int,int>::reverse_iterator it;
        


        it = mymap.rbegin(); 
        
       if(it != mymap.rend())
        std::cout << "hello" << std::endl;
}