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
        vec.push_back(pRoot->m_nodeValue);

        PreOrder(pRoot->m_pLeft, vec);

        PreOrder(pRoot->m_pRight, vec);
    }
}

template<typename T>
void InOrder(BinaryTreeNode<T> *pRoot, std::vector<T>& vec)
{
    if (pRoot)
    {
        InOrder(pRoot->m_pLeft, vec);

        vec.push_back(pRoot->m_nodeValue);

        InOrder(pRoot->m_pRight, vec);
    }
}

template<typename T>
void PostOrder(BinaryTreeNode<T> *pRoot, std::vector<T>& vec)
{
    if (pRoot)
    {
        PostOrder(pRoot->m_pLeft, vec);

        PostOrder(pRoot->m_pRight, vec);

        vec.push_back(pRoot->m_nodeValue);
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
void ConnectTreeNode(BinaryTreeNode<T> *pRoot, BinaryTreeNode<T> *pLeft, BinaryTreeNode<T> *pRight)
{
    if (pRoot)
    {
        pRoot->m_pLeft = pLeft;
        pRoot->m_pRight = pRight;
    }
}

template<typename T>
void InPrintTree(BinaryTreeNode<T> *pRoot)
{
    if (pRoot)
    {
        InPrintTree(pRoot->m_pLeft);

        std::cout << pRoot->m_nodeValue << ",";

        InPrintTree(pRoot->m_pRight);
    }  
}

template<typename T>
void PrePrintTree(BinaryTreeNode<T> *pRoot)
{
    if (pRoot)
    {
        std::cout << pRoot->m_nodeValue << ",";
        
        PrePrintTree(pRoot->m_pLeft);

        PrePrintTree(pRoot->m_pRight);
    }  
}

template<typename T>
void PostPrintTree(BinaryTreeNode<T> *pRoot)
{
    if (pRoot)
    {
        PostPrintTree(pRoot->m_pLeft);
        
        PostPrintTree(pRoot->m_pRight);

        std::cout << pRoot->m_nodeValue << ",";
    }  
}

template<typename T>
void PrintVector(std::vector<T> vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}


