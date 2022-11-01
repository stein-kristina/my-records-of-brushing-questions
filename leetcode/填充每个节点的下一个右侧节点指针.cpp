//
// Created by 86189 on 2022/7/22.
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()){
            int size=Q.size();

            for(int i=0;i<size;i++){
                Node* bit=Q.front();
                Q.pop();
                if(i<size-1){
                    bit->next=Q.front();
                }
                if(bit->left){
                    Q.push(bit->left);
                }
                if(bit->right){
                    Q.push(bit->right);
                }
            }
        }
        return root;
    }
};
class Solution {
public Node connect(Node root) {
        if (root == null) {
            return root;
        }

        // 从根节点开始
        Node leftmost = root;

        while (leftmost.left != null) {

            // 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
            Node head = leftmost;

            while (head != null) {

                // CONNECTION 1
                head.left.next = head.right;

                // CONNECTION 2
                if (head.next != null) {
                    head.right.next = head.next.left;
                }

                // 指针向后移动
                head = head.next;
            }

            // 去下一层的最左的节点
            leftmost = leftmost.left;
        }

        return root;
    }
}
