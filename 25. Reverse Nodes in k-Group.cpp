/*
Description:
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/

// idea: 1. have a helper function that reverses the first k nodes of a linked list
// 2.prev points to a dummy node, tail points to the head, and curr points to the k+1st node
// prev = reverseK(tail), tail -> next = curr
// prev = tial, tail = curr, find new curr, loop

#include <iostream>
using namespace std;

    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };



class Solution {
public:
    // helper function for reversing the first k nodes in a linked list
    ListNode* reverseK(ListNode* a, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = a;
        ListNode* next = a -> next;
        int count = 1;
        while(count < k) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = curr -> next;
            count ++;
        }
        curr -> next = prev;
        return curr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        // create a dummy node of value 0 pointing to the head
        ListNode* prev = new ListNode(0);
        prev -> next = head;

        ListNode* tail = head;
        ListNode* curr = head;
        ListNode* newHead = prev;

        int count = 0;
        bool ended = false;
        while(!ended) {
            // locate the new curr
            count = 0;
            while(count < k) {
                if(curr == nullptr) {
                    ended = true;
                    break;
                }
                curr = curr -> next;
                count ++;
            }
            if(!ended) {
                prev -> next = reverseK(tail,k);
                tail -> next = curr;
                prev = tail;
                tail = curr;
            }
        }
        return newHead -> next;
    }
};