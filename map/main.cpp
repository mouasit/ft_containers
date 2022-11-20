#include "map.hpp"
#include <map>
#include <iterator>
#include "../utils/pair.hpp"
int main(){
        std::map<char, int> m;
        ft::map<char, int> ft_m;
        std::map<char, int>::iterator it;
        ft::map<char, int>::iterator ft_it;

        ft_m['a'] = 10;
        ft_m['b'] = 20;
        ft_m['c'] = 30;
        ft_m['d'] = 40;
        ft_m['e'] = 50;
        ft_m['f'] = 60;

        m['a'] = 10;
        m['b'] = 20;
        m['c'] = 30;
        m['d'] = 40;
        m['e'] = 50;
        m['f'] = 60;

        it = m.find('b');
        ft_it = ft_m.find('b');

        m.erase(it);
        ft_m.erase(ft_it);
        
        it = m.end();
        ft_it = ft_m.end();

        std::cout << "m: " << it->first << " ft_m: " << ft_it->first << std::endl;

}
        
