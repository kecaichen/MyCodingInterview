#include "TreeCommon.hpp"

using namespace std;

template<typename T> using cItr = typename vector<T>::iterator;

template<typename T> using Size = typename vector<T>::size_type;

template<typename T, typename It = cItr<T>, typename Sz = Size<T>>
BinaryTreeNode<T> *Construct(It iterPreBegin, It iterInBegin, Sz size);

template<typename T>
BinaryTreeNode<T> *ConstructTree(vector<T>& vecPreOrder, vector<T>& vecInOrder)
{
    if (vecPreOrder.empty() || vecInOrder.empty() || vecPreOrder.size() != vecInOrder.size())
    {
        return nullptr;
    }

    BinaryTreeNode<T>  *pRet = Construct<T, cItr<T>, Size<T>>(vecPreOrder.begin(), vecInOrder.begin(), vecPreOrder.size());
    
    return pRet;
}

template<typename T, typename It = cItr<T>, typename Sz = Size<T>>
BinaryTreeNode<T> *Construct(It iterPreBegin, It iterInBegin, Sz n)
{
    const auto rootValue = *iterPreBegin;
    BinaryTreeNode<T> *pRoot = CreateTreeNode(rootValue);


    Sz i = 0;
    for (; i != n; i++)
    {
        if (*iterInBegin == rootValue)
        {
            break;
        }
    }

    if (i == n)
    {
        return nullptr;
    }

    auto l = i;
    auto r = n-i-1;
    
    if (l != 0)
    {
        pRoot->m_pLeft = Construct<T, cItr<T>, Size<T>>(iterPreBegin+1, iterInBegin, l);
    }

    if (r != 0)
    {
        pRoot->m_pRight = Construct<T, cItr<T>, Size<T>>(iterInBegin+i+1, iterPreBegin+i+1, r);
    }
    
    return pRoot;     
}

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

    vector<int> vecPreOrder;
    PreOrder(pNode1, vecPreOrder);

    cout << "---------------------------------Preorder---------------------------------" << endl;
    for (const auto& value : vecPreOrder)
    {
        cout << value << ", ";
    }
    cout << endl;
    

    vector<int> vecInOrder;
    InOrder(pNode1, vecInOrder);

    cout << "---------------------------------Inorder---------------------------------" << endl;
    for (const auto& value : vecInOrder)
    {
        cout << value << ", ";
    }
    cout << endl;

    BinaryTreeNode<int> *pBuildRoot = ConstructTree(vecPreOrder, vecInOrder);

    vector<int>::iterator Pre = vecPreOrder.begin();vector<int>::iterator PreEnd = vecPreOrder.end();
    vector<int>::iterator In = vecInOrder.begin();

    PrintVector(vecInOrder);

    //BinaryTreeNode<int> *pRet =  Construct<int>(Pre, In);

}

int main()
{
    Test();
    return 0;
}