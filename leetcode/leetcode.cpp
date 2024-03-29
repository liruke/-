#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    struct ListNode* next;
    int val;
};

//1.分隔链表
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* EH = NULL;
    struct ListNode* ET = NULL;
    struct ListNode* MH = NULL;
    struct ListNode* MT = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    while (cur)
    {
        next = cur->next;
        if (cur->val < x)
        {
            if (EH == NULL && ET == NULL)
            {
                EH = ET = cur;
                ET->next = NULL;
            }
            else
            {
                ET->next = cur;
                ET = cur;
                ET->next = NULL;
            }
        }
        else {
            if (MH == NULL && MT == NULL)
            {
                MH = MT = cur;
                MT->next = NULL;
            }
            else {
                MT->next = cur;
                MT = cur;
                MT->next = NULL;
            }
        }
        cur = next;
    }
    if (EH == NULL)
    {
        return MH;
    }
    ET->next = MH;
    return EH;
}
//旋转链表
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    int size = 0;
    while (cur)
    {
        size++;
        cur = cur->next;
    }
    k %= size;
    cur = head;
    for (int i = 0;i < k;i++)
    {
        while (cur->next)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        cur->next = head;
        head = cur;
    }
    return head;
}
//两两交换链表中的节点
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* fast = head;
    while (fast != NULL)
    {
        if (fast->next == NULL)
        {
            break;
        }
        int tmp = fast->val;
        fast->val = fast->next->val;
        fast->next->val = tmp;
        fast = fast->next->next;
    }
    return head;
}
//删除链表的倒数第N个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size = 0;
    struct ListNode* cur = head;
    while (cur)
    {
        cur = cur->next;
        size++;
    }
    if (n == size)
    {
        struct ListNode* newhead = head->next;
        free(head);
        return newhead;
    }
    int i = size - (n - 1);
    struct ListNode* prev = NULL;
    cur = head;
    while (i != 1)
    {
        prev = cur;
        cur = cur->next;
        i--;
    }
    struct ListNode* next = cur->next;
    free(cur);
    prev->next = next;
    return head;
}
//