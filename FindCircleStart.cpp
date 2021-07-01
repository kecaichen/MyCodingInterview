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

void InjoinNode(ListNode *pPre, ListNode *pNext)
{
    if (pPre)
    {
        pPre->m_pNext = pNext;
    }
}

ListNode *findNodeOnCircle(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;        
    }

    ListNode *pQuick = pHead;
    ListNode *pSlow = pHead;
    do
    {
        pQuick = pQuick->m_pNext;
        if (pQuick)
        {
            pQuick = pQuick->m_pNext;
        }
        else
        {
            return nullptr;
        }

        pSlow = pSlow->m_pNext;

        if (pQuick == pSlow)
        {
            return pQuick;
        }  
    } while ((pQuick != nullptr) && (pSlow != nullptr));

    return nullptr;   
}

ListNode *FindStartNode(ListNode *pHead)
{
    ListNode *pCircleNode = findNodeOnCircle(pHead);
    if (pCircleNode == nullptr)
    {
        return nullptr;
    }

    //count circle nummber
    size_t n = 0;
    ListNode *pNode = pCircleNode;
    do
    {
        n++;
        pNode = pNode->m_pNext;
    } while (pCircleNode != pNode);

    //Find start node
    ListNode *pQuick = pHead;
    for (size_t i = 0; i < n; i++)
    {   
        pQuick = pQuick->m_pNext;
    }

    ListNode *pSlow = pHead;
    while (pQuick != pSlow)
    {
        pQuick = pQuick->m_pNext;
        pSlow = pSlow->m_pNext;
    }
    
    return pQuick;
}

void Test()
{
    ListNode *pHead = nullptr;

    AddToTail(&pHead, 4);
    AddToTail(&pHead, 3);
    AddToTail(&pHead, 4);
    AddToTail(&pHead, 9);
    ListNode *pNext = AddToTail(&pHead, 5);
    AddToTail(&pHead, 6);
    ListNode *pPre = AddToTail(&pHead, 8);
    InjoinNode(pPre, pNext);

    ListNode *pStart = FindStartNode(pHead);
    if (pStart)
    {
        std::cout << pStart->m_nValue << std::endl;
    }
    else
    {
        std::cout << "No circle" << std::endl;
    }
}

int main()
{
    Test();
}