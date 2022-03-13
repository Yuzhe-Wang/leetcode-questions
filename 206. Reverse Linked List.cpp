/*
Description:
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

// basic idea: use three pointers, prev, curr, next

// Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nex = head -> next;
        while(nex != nullptr) {
            curr -> next = prev;
            prev = curr;
            curr = nex;
            nex = nex -> next;
        }
        curr -> next = prev;
        head = curr;
        return head;
    }
};