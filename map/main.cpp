#include "map.hpp"

int main(){
    Tree     myTree;

    myTree.insert(8);
    myTree.insert(6);
    myTree.insert(7);
    myTree.insert(5);
    myTree.insert(9);
    myTree.insert(10);
    myTree.earse(5);
    myTree.earse(7);
    myTree.earse(9);
    myTree.printTree(myTree.root);

}