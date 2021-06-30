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

ListNode *FindKthToTail(ListNode *pHead, int k)
{
    if (pHead == nullptr || k == 0)
    {
        return nullptr;
    }

    ListNode *pSlow = nullptr;
    ListNode *pQuick = pHead;
    
    for (size_t i = 1; i < k; i++)
    {
        // pQuick = pQuick->m_pNext;

        // if (pQuick == nullptr)
        // {
        //     return nullptr;
        // }
        if (pQuick->m_pNext)
        {
            pQuick = pQuick->m_pNext;
        }
        else
        {
            return nullptr;
        }
        
    }

    pSlow = pHead;
    while (pQuick->m_pNext)
    {
        pQuick = pQuick->m_pNext;
        pSlow = pSlow->m_pNext;
    }

    return pSlow;
}

void Test()
{
    ListNode *pHead = nullptr;

    AddToTail(&pHead, 4);
    AddToTail(&pHead, 3);
    AddToTail(&pHead, 4);
    AddToTail(&pHead, 9);
    AddToTail(&pHead, 5);
    AddToTail(&pHead, 6);
    AddToTail(&pHead, 8);

    for (size_t i = 0; i < 8; i++)
    {
        ListNode *pNode = FindKthToTail(pHead, i+1);

        if (pNode)
        {
            std::cout << pNode->m_nValue << std::endl;
        }      
    }    
}

int main()
{
    Test();
}