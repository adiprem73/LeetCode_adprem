/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy  = new Node(-1);
        Node* ptr = dummy;
        Node* temp = head;
        unordered_map<Node*, Node*> mp;
        while(temp!=nullptr){
            Node* copytemp = new Node(temp->val);
            ptr->next = copytemp;
            ptr = copytemp;

            mp[temp] = copytemp;
            temp = temp->next;
        }
        temp = head;
        while(temp!= nullptr){
            if(mp.find(temp) != mp.end()){
                auto copyNode = mp[temp];
                copyNode->random = mp[temp->random];
            }
            temp=temp->next;
        }

        return dummy->next;
    }
};