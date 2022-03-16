/*
Description:
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.
*/

// solution one: cost more but easy to think of, move the current node all the way to the tail and delete, just like doing vector deletion in O(1) time
/*
delete a node in a linked list without knowing the head
the given node could never be the tail

4->5->1->9
4->1->5->9
4->1->9->5->nullptr
5 is tail
prev -> next = nullptr
delete tail
*/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        node = node -> next;
        int temp = prev -> val;
        prev -> val = node -> val;
        node -> val = temp;
        while( (node -> next) != nullptr) {
            prev = node;
            node = node -> next;
            int temp = prev -> val;
            prev -> val = node -> val;
            node -> val = temp;
        }
        prev -> next = nullptr;
        delete node;
    }
};


// solution 2: a better solution, swap the current node and the next node, delete the next node 
class Solution2 {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        ListNode* temp = node -> next;
        node -> next = node -> next -> next;
        delete temp;
    }
};