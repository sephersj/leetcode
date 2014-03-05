//============================================================================
// Reorder List
//
// Given a singly linked list L: L0->L1->...->Ln-1->Ln,
// reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
//
// You must do this in-place without altering the nodes' values.
//
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.
//
// Complexity:
// Random Access Cache, O(n) time, O(n) space
// Split, Reverse, Merge, O(n) time, O(1) space
//============================================================================

#include <iostream>

using namespace std;


/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        reorderList2(head);
    }

    void reorderList1(ListNode *head) {
        if (head == NULL) return;
        vector<ListNode*> vs;
        ListNode * curNode = head;
        while (curNode != NULL) {
            vs.push_back(curNode);
            curNode = curNode->next;
        }

        int i = 0, j = vs.size() - 1;
        while (i < j) {
            vs[i]->next = vs[j];
            vs[j]->next = vs[i + 1];
            i++, j--;
        }
        vs[i]->next = NULL;
    }

    void reorderList2(ListNode *head) {
        if (head == NULL || head->next == NULL) return;
        ListNode * frontHead, *backHead;
        split(head, frontHead, backHead);
        backHead = reverse(backHead);
        merge(frontHead, backHead);
    }

    void split(ListNode * head, ListNode *& frontHead, ListNode *& backHead) {
        ListNode * fastNode = head, *slowNode = head;
        for (; fastNode->next != NULL && fastNode->next->next != NULL; fastNode = fastNode->next->next) slowNode = slowNode->next;
        backHead = slowNode->next;
        slowNode->next = NULL;
        frontHead = head;
    }

    ListNode * reverse(ListNode * head) {
        ListNode * preNode = NULL, *curNode = head;
        while (curNode) {
            ListNode * nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        return preNode;
    }

    void merge(ListNode * frontHead, ListNode * backHead) {
        ListNode * head = pushDummy(NULL), *curNode = head;
        while (frontHead || backHead) {
            if (frontHead) curNode->next = frontHead, frontHead = frontHead->next, curNode = curNode->next;
            if (backHead) curNode->next = backHead, backHead = backHead->next, curNode = curNode->next;
        }
        head = popDummy(head);
    }

    ListNode * pushDummy(ListNode * head) {
        ListNode * newNode = new ListNode(-1);
        newNode->next = head;
        return newNode;
    }

    ListNode * popDummy(ListNode * head) {
        ListNode * delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }
};

int main() {
    Solution sol;

    {
        ListNode * head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        sol.reorderList(head);

        while (head != NULL) {
            cout << head->val << endl;
            head = head->next;
        }
    }

    return 0;
}