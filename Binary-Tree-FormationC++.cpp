#include <bits/stdc++.h>
using namespace std;
class  Node
{
    public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data=data;
        this->right = this->left=nullptr;

    }
};

void levelorder(Node *root)
{
    if(root==NULL){
    cout<<"Empty Structure!"<<endl;
    return;
    }
    
    list<Node*> queue;
    queue.push_back(root);
    Node *curr=nullptr;
    while(queue.size())
    {
        curr=queue.front();
        queue.pop_front();
        cout<<curr->data<<" ";
        if(curr->left)
        queue.push_back(curr->left);
        if(curr->right)
        queue.push_back(curr->right);
    }
}

main()
{
    /* Construct the following tree
			   1
			 /   \
			/     \
		   2       3
		  /      /   \
		 /      /     \
		4      5       6
			  / \
			 /   \
			7     8
	*/
   	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);                                         
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);
    levelorder(root);


}