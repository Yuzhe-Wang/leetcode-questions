/*
Description:
Given the head of a linked list, return the list after sorting it in ascending order.
*/

/*
sort ascending order
return the head of the sorted list
4,2,1,3

common sorting algorithms:
bubble sort
if curr -> val > next -> val, swap curr and next

merge sort
quick sort

linked list -> no fast random access []

*/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void swap(ListNode* curr, ListNode* next) {
        int temp = curr -> val;
        curr -> val = next -> val;
        next -> val = temp;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* a = left;
        ListNode* b = right;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(a != nullptr && b != nullptr) {
            if(a -> val < b -> val) {
                curr -> next = a;
                a = a -> next;
            } else {
                curr -> next = b;
                b = b -> next;
            }
            curr = curr -> next;
        }
        if(b != nullptr) {
            curr -> next = b;
            b = b -> next;
        }
        if(a != nullptr) {
            curr -> next = a;
            a = a -> next;
        }
        return head -> next;
    }
    
    ListNode* sortList(ListNode* head) {
        // // bubble sort: each iteration, place curr in the right place, O(n^2)
        // if(head == nullptr || head -> next == nullptr) return head;
        // ListNode* i = head;
        // while(i -> next != nullptr) {
        //     ListNode* j = head;
        //     while(j -> next != nullptr) {
        //         if(j -> val > j -> next -> val) {
        //             swap(j, j->next);
        //         }
        //         j = j -> next;
        //     }
        //     i = i -> next;
        // }
        // return head;
        
        // merge sort: divid and conquer O(nlogn)
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* half = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // head will be head, half will be the end of the first half
        // slow will be the head of the second half, and fast will be the end of the second half
        while(fast != nullptr && fast -> next != nullptr) {
            half = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        half -> next = nullptr;
        
        //recurrsive call
        ListNode* leftSide = sortList(head);
        ListNode* rightSide = sortList(slow);
        
        return merge(leftSide, rightSide);
    }
};
