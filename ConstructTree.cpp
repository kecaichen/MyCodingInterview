#include "TreeCommon.hpp"

int main()
{
    BinaryTreeNode<int> *pNode1 = CreateTreeNode(1);
    BinaryTreeNode<int> *pNode2 = CreateTreeNode(2);
    BinaryTreeNode<int> *pNode3 = CreateTreeNode(3);
    BinaryTreeNode<int> *pNode4 = CreateTreeNode(4);
    BinaryTreeNode<int> *pNode5 = CreateTreeNode(5);
    BinaryTreeNode<int> *pNode6 = CreateTreeNode(6);
    BinaryTreeNode<int> *pNode7 = CreateTreeNode(7);
    BinaryTreeNode<int> *pNode8 = CreateTreeNode(8);

    ConnectTreeNode(pNode1, pNode2, pNode3);
    //ConnectTreeNode(pNode2, pNode4, NullptrNode);
    ConnectTreeNode(pNode3, pNode5, pNode6);
    //ConnectTreeNode(pNode4, nullptr, pNode7);
    //ConnectTreeNode(pNode6, pNode8, nullptr);
    PrintTree(pNode1);
    std::cout << std::endl; 

    return 0;
}