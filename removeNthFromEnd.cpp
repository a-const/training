#include <iostream>
#include <vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class list{
public:
         list() = default;
         ListNode* head;
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;
        ListNode* node = head;
        std::vector<ListNode*> vec_list;
        while (node){
            vec_list.push_back(node);
            node = node->next;
        }
        int pos = vec_list.size() - n;
        if (n == vec_list.size()){
            if (head->next){
                node = head->next;
                delete head;
                return node;
            }
            else{
                delete head;
                return nullptr;
            }
        }
        if (vec_list[pos]->next)
            vec_list[pos-1]->next = vec_list[pos]->next;
        else{
            vec_list[pos-1]->next = nullptr;
            delete vec_list[pos];
        }
        return head;
    }
};

int main(int argc, char *argv[])
{    
    list* List = new list();
    List->head = new ListNode(0);
    ListNode* node = List->head;
    std::cout << node->val << " ";
    for (int i = 0; i < 5; i++){
        node->next = new ListNode(i+1);
        node = node->next;
        std::cout << node->val << " ";
    }
    std::cout << '\n';
    node = List->head;
    Solution sol;
    node = sol.removeNthFromEnd(node,2);
    while(node){
        std::cout << node->val << " ";
        node = node->next;
    }
    return 0;
}
