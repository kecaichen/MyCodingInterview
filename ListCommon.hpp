#include<iostream>

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
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