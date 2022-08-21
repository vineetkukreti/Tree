#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *createTree(Node *root)
{
    cout << "Enter the data :";
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    printf("Enter the data in the left of %d ->  ", data);
    root->left = createTree(root->left);
    printf("Enter the data in the right of %d->  ", data);
    root->right = createTree(root->right);
    return root;
}

// level order traversal;
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
       
        q.pop();
        if (temp == NULL) // to beautify output
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
             cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node *root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if(root==NULL)
    return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node *buildfromLevelOrder(Node *root)
{
    queue<Node *> q;
    cout<<"Enter data for root : ";
    int info;
    cin>>info;
    root = new Node(info);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
         cout<<"Enter left node for "<<temp->data<<endl;
         int leftdata;
         cin>>leftdata;

         if(leftdata!=-1)
         {
            temp->left = new Node(leftdata);
         }

          int rightdata;
          cin>>rightdata;

         if(rightdata!=-1)
         {
            temp->right = new Node(rightdata);
         }
    }
    
}
void  find(Node *root,int &count)
{
    if(root == NULL)
     return ;
     find(root->left,count);
     find(root->right,count);
     if(root->left==NULL && root->right==NULL)
     count++;

}
int count_no_of_leafnode(Node *root)
{
    int count = 0;
    find(root,count);
    return count;
}
int main()
{
    Node *root = new Node(90);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    root->left = n1;
    root->right = n4;
    n1->left = n2;
    n1->right = n3;
    n4->left = n5;
    n4->right = n6;
    int n = count_no_of_leafnode(root);
cout<<n;
    // create tree
    // root = createTree(root);

    // create tree using level oreder

    


    // Types of traversal
    //1.level order traversal
    //2.Inorder traversal LNR
    //3.preorder traversal NLR
    //4.post order traversal LRN

    // here are the is_function
   //  inorder(root);
   //  preorder(root);
   //  postorder(root);


   // levelOrderTraversal(root);


    return 0;
}