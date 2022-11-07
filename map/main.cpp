#include "map.hpp"
#include <functional>

int main(){
    ft:: pair<int,int> pair6(5,2);

    ft::avlTree<std::string, int> avlTree;

    avlTree.insert(ft::pair<std::string,int>("mustapha",20));
    avlTree.insert(ft::pair<std::string,int>("ayoub",5));
    avlTree.insert(ft::pair<std::string,int>("hamid",2));

    avlTree.printTree(avlTree.root);

    avlTree.earse("ayoub");

    avlTree.printTree(avlTree.root);

}