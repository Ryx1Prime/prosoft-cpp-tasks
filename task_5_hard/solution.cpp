#include <iostream>
#include <vector>
#include <queue>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareNodes{
    bool operator()(const ListNode* a, const ListNode* b) const{
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNodes> min_heap;

        for (ListNode* head : lists){
            if (head != nullptr){
                min_heap.push(head);
            }
        }

        ListNode fictional(0);
        ListNode* tail = &fictional;

        while (!min_heap.empty()){
            ListNode* smallest = min_heap.top();
            min_heap.pop();
            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr){
                min_heap.push(smallest->next);
            }
        }            
        return fictional.next;
        
    }
};

ListNode* createList(const std::vector<int>& values) {
    ListNode fictional(0);
    ListNode* tail = &fictional;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return fictional.next;
}

// функция для печати списка в формате "1 -> 2 -> 3"
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val;
        if (curr->next != nullptr) {
            std::cout << " -> ";
        }
        curr = curr->next;
    }
    std::cout << "\n";
}

int main(){
    Solution solver;
    
    std::vector<ListNode*> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };

    std::cout << "Merged list:\n";
    ListNode* result = solver.mergeKLists(lists);
    printList(result);

    return 0;
}