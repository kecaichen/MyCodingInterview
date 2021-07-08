#include "TreeCommon.hpp"

template<typename T>
BinaryTreeNode<T> *ConstructTree(const std::vector<T>& vecPreOrder, const std::vector<T>& vecInOrder)
{
    if (vecPreOrder.empty() || vecInOrder.empty() || vecPreOrder.size() != vecInOrder.size())
    {
        return nullptr;
    }
    

}

// template<typename T>
// BinaryTreeNode<T> *ConstructTree(std::vector<int>::iterator iterPreOrder, std::vector<int>::iterator iterInOrder)
// {
//     return nullptr;
// }

void Test()
{
    // std::vector<int> vecPreOrder{1, 2, 4, 7, 3, 5, 6, 8};
    // std::vector<int> vecInOrder{4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode<int> *pNode1 = CreateTreeNode(1);
    BinaryTreeNode<int> *pNode2 = CreateTreeNode(2);
    BinaryTreeNode<int> *pNode3 = CreateTreeNode(3);
    BinaryTreeNode<int> *pNode4 = CreateTreeNode(4);
    BinaryTreeNode<int> *pNode5 = CreateTreeNode(5);
    BinaryTreeNode<int> *pNode6 = CreateTreeNode(6);
    BinaryTreeNode<int> *pNode7 = CreateTreeNode(7);
    BinaryTreeNode<int> *pNode8 = CreateTreeNode(8);

    ConnectTreeNode(pNode1, pNode2, pNode3);
    ConnectTreeNode(pNode2, pNode4, (BinaryTreeNode<int> *)nullptr);
    ConnectTreeNode(pNode3, pNode5, pNode6);
    ConnectTreeNode(pNode4, (BinaryTreeNode<int> *)nullptr, pNode7);
    ConnectTreeNode(pNode6, pNode8, (BinaryTreeNode<int> *)nullptr);

    std::vector<int> vecPreOrder;
    PreOrder(pNode1, vecPreOrder);

    std::cout << "---------------------------------Preorder---------------------------------" << std::endl;
    for (const auto& value : vecPreOrder)
    {
        std::cout << value << ", ";
    }
    std::cout << std::endl;
    

    std::vector<int> vecInOrder;
    InOrder(pNode1, vecInOrder);

    std::cout << "---------------------------------Inorder---------------------------------" << std::endl;
    for (const auto& value : vecInOrder)
    {
        std::cout << value << ", ";
    }
    std::cout << std::endl;



}

int main()
{
    Test();
    return 0;
}