// MergeSortedLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

std::ostream& operator <<(std::ostream& st, ListNode* pNode)
{
    if (pNode == nullptr)
        return st;

    st << pNode->data;
    if (pNode->next == nullptr)
        st << std::endl;
    else
    {
        st << ", " << pNode->next;
    }

    return st;
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* MergeTwoSortedList(ListNode* firstList, ListNode* secondList)
{
    if (firstList == nullptr)
        return secondList;
    if (secondList == nullptr)
        return firstList;

    ListNode* newHead = firstList;
    if (newHead->data > secondList->data)
    {
        newHead = secondList;
        secondList = secondList->next;
    }
    else
        firstList = firstList->next;

    ListNode* newCurrent = newHead;

    while (firstList != nullptr && secondList != nullptr)
    {
        if (firstList->data < secondList->data)
        {
            newCurrent->next = firstList;
            firstList = firstList->next;
        }
        else
        {
            newCurrent->next = secondList;
            secondList = secondList->next;
        }
        newCurrent = newCurrent->next;
    }

    if (firstList != nullptr)
    {
        newCurrent->next = firstList;
    }

    if (secondList != nullptr)
    {
        newCurrent->next = secondList;
    }

    return newHead;
}

int main()
{
    while (true)
    {
        int countA = 0, countB = 0;
        std::cout << "Number of nodes in listA and listB: ";
        std::cin >> countA >> countB;
        if (countA == 0 && countB == 0)
            break;

        ListNode* pAHead = nullptr, *pBHead = nullptr;
        ListNode* pATail = GetListFromInput(&pAHead, countA);
        ListNode* pBTail = GetListFromInput(&pBHead, countB);

        ListNode* pMerged = MergeTwoSortedList(pAHead, pBHead);

        std::cout << "Merged: ";
        std::cout << pMerged;
        FreeList(pMerged);
    }
}
