#include<iostream>

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

struct  ComplexListNode
{
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};


void PrintList(ListNode *pListHead)
{
    ListNode *pListNode = pListHead;

    while (pListNode)
    {
        std::cout << pListNode->m_nValue << ", ";
        pListNode = pListNode->m_pNext;
    }

    std::cout << std::endl;
}

ListNode *AddToTail(ListNode **pHead, int nValue)
{
    ListNode *pNode = new ListNode;
    pNode->m_nValue = nValue;
    pNode->m_pNext = nullptr;

    if (*pHead == nullptr)
    {
        *pHead = pNode;
        return *pHead;
    }
    else
    {
        ListNode *pLastNode = *pHead;

        while (pLastNode->m_pNext != nullptr)
        {
            pLastNode = pLastNode->m_pNext;
        }

        pLastNode->m_pNext = pNode;
        return pNode;        
    }
}

ComplexListNode *AddToTail(ComplexListNode **pHead, int nValue)
{
    ComplexListNode *pNode = new ComplexListNode;
    pNode->m_nValue = nValue;
    pNode->m_pNext = nullptr;
    pNode->m_pSibling = nullptr;

    if (*pHead == nullptr)
    {
        *pHead = pNode;
        return *pHead;
    }
    else
    {
        ComplexListNode *pLastNode = *pHead;

        while (pLastNode->m_pNext != nullptr)
        {
            pLastNode = pLastNode->m_pNext;
        }

        pLastNode->m_pNext = pNode;
        return pNode;        
    }
}

ComplexListNode *AddSibling(ComplexListNode *pListNode, ComplexListNode *pSibling)
{
    if (pListNode == nullptr)
    {
        return nullptr;
    }

    pListNode->m_pSibling = pSibling;

    return pListNode;    
}

void PrintComplexList(ComplexListNode *pListHead)
{
    ComplexListNode *pListNode = pListHead;

    while (pListNode)
    {
        std::cout << pListNode->m_nValue << ", ";
        if (pListNode->m_pSibling)
        {
            std::cout << pListNode->m_pSibling->m_nValue;
        }
        else
        {
            std::cout << "null";
        }
        std::cout << std::endl;

        pListNode = pListNode->m_pNext;
    }
}

   