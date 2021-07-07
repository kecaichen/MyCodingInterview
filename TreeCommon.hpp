#include<vector>
#include<iostream>

template <typename T>
struct BinaryTreeNode
{
    T m_nodeValue;
    BinaryTreeNode<T> *m_pLeft;
    BinaryTreeNode<T> *m_pRight;
};

template<typename T>
void PreOrder(BinaryTreeNode<T> *pRoot, std::vector<T>& vec)
{
    if (pRoot)
    {
        PreOrder(pRoot->m_pLeft, vec);

        vec.push_back(pRoot->m_nodeValue);

        PreOrder(pRoot->m_pRight, vec);
    }
}

template<typename T>
BinaryTreeNode<T> *CreateTreeNode(T nodeValue)
{
    BinaryTreeNode<T> *pNode = new BinaryTreeNode<T>;
    pNode->m_nodeValue = nodeValue;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

template<typename T>
BinaryTreeNode<T> *NullptrNode()
{
    return nullptr;
}

template<typename T>
BinaryTreeNode<T> *ConnectTreeNode(BinaryTreeNode<T> *pRoot, BinaryTreeNode<T> *pLeft, BinaryTreeNode<T> *pRight)
{
    if (pRoot)
    {
        pRoot->m_pLeft = pLeft;
        pRoot->m_pRight = pRight;

        return pRoot;
    }
    else
    {
        return nullptr;
    }
}

template<typename T>
void PrintTree(BinaryTreeNode<T> *pRoot)
{
    if (pRoot)
    {
        std::cout << pRoot->m_nodeValue << ",";

        PrintTree(pRoot->m_pLeft);;
        PrintTree(pRoot->m_pRight);;
    }  
}


