#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

std::vector<ListNode*> splitLinkedList(ListNode* head, int k) {
    std::vector<ListNode*> result;
    
    // Step 1: Find the length of the linked list
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    
    // Step 2: Calculate size of each part and the number of extra elements
    int partSize = length / k;
    int extra = length % k;
    
    current = head;
    ListNode* prev = nullptr;
    
    // Step 3: Split the linked list into parts
    for (int i = 0; i < k; i++) {
        result.push_back(current);
        
        int partLength = partSize + (extra > 0 ? 1 : 0);
        extra--;
        
        for (int j = 0; j < partLength; j++) {
            prev = current;
            current = current->next;
        }
        
        if (prev != nullptr) {
            prev->next = nullptr; // Disconnect the previous part
        }
    }
    
    return result;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);

    int k = 5;
    std::vector<ListNode*> result = splitLinkedList(head, k);

    // Print the resulting linked lists
    for (ListNode* part : result) {
        while (part != nullptr) {
            std::cout <<"["<< part->val << "]";
            part = part->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    return 0;
}
