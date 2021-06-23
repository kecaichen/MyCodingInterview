#include <stack>
#include <iostream>

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

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

void PrintListReversingly(ListNode* pHead)
{
    std::stack<int> stack;

    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        stack.push(pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    while(!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
    
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

    PrintListReversingly(pHead);
}

int main()
{
    Test1();
    return 0;
}
