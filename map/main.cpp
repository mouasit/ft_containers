#include "map.hpp"

int main(){
    Tree     myTree;
    myTree.insert(8);
    myTree.insert(7);
    myTree.insert(9);
    myTree.insert(20);
    myTree.insert(25);
    myTree.printTree(myTree.root);
}