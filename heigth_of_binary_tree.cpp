// height_of_binaryTree


//******************************************
// Leetcode solution
//******************************************
// 104. Maximum Depth of Binary Tree
// ANALYSIS :-
// Time Complexity :- BigO(N)
// Space Complexity :- BigO(N)

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==NULL)
//             return 0;
//         int leftheight  = maxDepth(root->left);
//         int rightheight = maxDepth(root->right);
        
        
//         return  max(leftheight ,rightheight) + 1;
//     }
// };


// ********** you can run this code in your pc for better understanding ***********
#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int height_of_tree(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left_max = height_of_tree(root->left);
    int right_max = height_of_tree(root->right);
    int ans =  max(left_max,right_max) + 1;
    return ans;
}
int main()
{
     node *root = new node(0);
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);
    node *n6 = new node(6);
    
    root->left = n1;
    root->right = n4;
    n1->left = n2;
    n1->right = n3;
    n4->left = n5;
    n4->right = n6;
 cout<<"\nInorder Tranversal   : ";inorder(root);
 cout<<"Heigt of the tree : "<<height_of_tree(root);
    return 0;
}