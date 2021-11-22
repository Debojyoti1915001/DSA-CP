// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

The Idea is As They Given us Inorder and Postorder

as we Know Inorder Fallow --> Left_subtree => Root_Node => Right_subtree Traverse
   ans   Postorder Fallow --> Left_subtree => Right_subtree =>Root_Nodetraverse
using Postorder_array We can Find Root_Node Which always lay in Postorder_array last Possition
After Finding That Root_Node ,First we are going to divide Inorder_array Into Two Part and Postorder Array
into Two part .

Then We are going to use Both of the arrays left part to Figur Out Left_subtree
                     and Both of the arraysRigth Part to Figur out Right_subtree

We are going to recursively do so until One Of the array dose not got empty
Lets take an Example

    inorder   = [4 2 5 1 6 3 7]
    postorder = [4 5 2 6 7 3 1]

    So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
    so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]

    using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part
    [4 5 2] and [6 7 3]


    1st Phase=>        
	                   1

                   /        \

                [4 2 5]   [6 3 7]       <= inorder array
                [4 5 2]   [6 7 3]       <= postorder array

Now we have new freash problem like need to make tree by using inorder = [4 2 5] && postorder =  [4 5 2] for left subtree 
AND inorder = [6 3 7] && postorder = [6 7 3] for right  subtree 
**now same process we need to do again and again  until One Of the array dose not got empty
Rest of the Process show in a diagram Form :)

    2nd Phase =>
                           1

                      /        \
                     2          3
                [4]    [5]   [6]   [7]       <= inorder array
                [4]    [5]   [6]   [7]       <= postorder array


3rd Phase =>  
	             1

               /    \
              2      3
 
            /  \    /  \             <==== Answer
 
           4    5  6    7 
class Solution {
public:
    TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x > y || a > b)return nullptr;
        TreeNode *node = new TreeNode(po[b]);
        int SI = x;  
        while(node->val != in[SI])SI++;
        node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
        node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        return Tree(in,0,in.size()-1,po,0,po.size()-1);
    }
};