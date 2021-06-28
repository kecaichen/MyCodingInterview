#include<iostream>

using namespace std;

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

ListNode *ReverseList(ListNode *pHead)
{
    ListNode *listNode = pHead;
    ListNode *pReverseList = nullptr;
    ListNode *PreList = nullptr;

    while (listNode != nullptr)
    {
        ListNode* pNext = listNode->m_pNext;
        if(pNext == nullptr)
        {
            pReverseList = listNode;
        }

        listNode->m_pNext = PreList;
        PreList = listNode;
        listNode = pNext;
    }
    return pReverseList;  
}

void Test1()
{
    ListNode *pHead = nullptr;

    AddToTail(&pHead, 4);
    AddToTail(&pHead, 3);
    AddToTail(&pHead, 4);
    AddToTail(&pHead, 9);
    AddToTail(&pHead, 5);
    AddToTail(&pHead, 6);
    AddToTail(&pHead, 8);

    ListNode *pReverse = ReverseList(pHead);
    PrintList(pReverse);
}

int main()
{
    Test1();
    return 0;
}