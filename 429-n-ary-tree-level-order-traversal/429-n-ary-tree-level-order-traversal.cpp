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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<Node*>q;
        q.push(root);
        while(q.size()){
            vector<int>temp;
            int sz=q.size();
            while(sz--){
                Node *t=q.front();
                temp.push_back(t->val);
                for(Node* cur:t->children){
                    q.push(cur);
                }
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};