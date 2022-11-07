#include "map.hpp"
#include <functional>

int main(){
    ft:: pair<int,int> pair6(5,2);

    ft::Tree<std::string, int> myTree;

    myTree.insert(ft::pair<std::string,int>("mustapha",20));
    myTree.insert(ft::pair<std::string,int>("ayoub",5));
    myTree.insert(ft::pair<std::string,int>("hamid",2));

    myTree.printTree(myTree.root);

    myTree.earse("mustapha");

    myTree.printTree(myTree.root);

}