// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

#include<bits/stdc++.h>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class compare
{
    bool operator()(ListNode* a, ListNode *b)
    {
        return a->val > b->val;   // min heap  
    }
};
ListNode* mergeKLists(vector<ListNode*>&arr) {
    priority_queue<ListNode*, vector<ListNode*>, compare>pq;   
    for(int i = 0;i<arr.size();i++){
        if(arr[i] != NULL)
            pq.push(arr[i]);
    }
    
    ListNode *mergeH = new ListNode(0);
    ListNode *last = mergeH;
    while(!pq.empty())
    {
        ListNode* curr = pq.top();
        pq.pop();
        
        last->next = curr;
        last = last->next;
        
        if(curr != NULL && curr->next != NULL){
            pq.push(curr->next);
        }
        
    }
    return mergeH->next;
}