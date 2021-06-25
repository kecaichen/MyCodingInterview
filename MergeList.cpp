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

void AddToTail(ListNode **pHead, int nValue)
{
    ListNode *pNode = new ListNode;
    pNode->m_nValue = nValue;
    pNode->m_pNext = nullptr;

    if (*pHead == nullptr)
    {
        *pHead = pNode;
    }
    else
    {
        ListNode *pLastNode = *pHead;

        while (pLastNode->m_pNext != nullptr)
        {
            pLastNode = pLastNode->m_pNext;
        }

        pLastNode->m_pNext = pNode;        
    }
    
}

ListNode *MergeList(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr)
    {
        return pHead2;
    }
    else if (pHead2 == nullptr)
    {
        return pHead1;
    }
    
    ListNode *pMergeList = nullptr;

    if (pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergeList = pHead1;
        pMergeList->m_pNext = MergeList(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergeList = pHead2;
        pMergeList->m_pNext = MergeList(pHead2->m_pNext, pHead1);
    }
    
    return pMergeList;
}

void Test1()
{
    ListNode *pHead1 = nullptr;

    AddToTail(&pHead1, 2);
    AddToTail(&pHead1, 3);
    AddToTail(&pHead1, 5);
    AddToTail(&pHead1, 8);
    AddToTail(&pHead1, 9);
    AddToTail(&pHead1, 12);
    AddToTail(&pHead1, 15);

    ListNode *pHead2 = nullptr;

    AddToTail(&pHead2, 1);
    AddToTail(&pHead2, 4);
    AddToTail(&pHead2, 6);
    AddToTail(&pHead2, 7);
    AddToTail(&pHead2, 10);
    AddToTail(&pHead2, 11);
    AddToTail(&pHead2, 18);


    ListNode *pMergeList = MergeList(pHead1, pHead2);

    PrintList(pMergeList);
}

int main()
{
    Test1();
    return 0;
}