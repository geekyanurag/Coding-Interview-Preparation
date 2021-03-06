/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>res;
        func(res, root);
        return res;
    }
    void func(vector<int> &res, Node* root){
        if(!root)
            return;
        res.push_back(root->val);
        for(int i =0; i<root->children.size(); i++){
            func(res, root->children[i]);
        }
    }
};