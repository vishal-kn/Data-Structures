#include <iostream>
#include <stack>
#include <list>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};

void preorderIterative(Node* root)
{
    if (root== nullptr)
		return;
    Node *curr =root;
	stack<Node*> stack;
	stack.push(root);
    cout<<"Pre-order Traversal"<<endl;

	while (!stack.empty())
	{
         curr=stack.top();
	     stack.pop();
         cout<<curr->data<<" ";
         if(curr->right!=NULL)
         stack.push(curr->right);
         if(curr->left!=NULL)
         stack.push(curr->left);	
	}
    cout<<"\n";
}

void inorderIterative(Node *root)
{
    if(root==NULL)
    return;

    Node *curr=root;
    stack <Node*> stack;
    cout<<"Inorder Traversal"<<endl;
    while(1)
    {
        while(curr->left!=NULL)
        {
            stack.push(curr);
            curr=curr->left;
        }
        while(curr->right==NULL)
        {
            cout<<curr->data<<" ";
            curr=stack.top();
            if(stack.empty())
            return;
            stack.pop();
            
        }
    }
cout<<"\n";
}

void postorderIterative(Node *root)
{
    if(root==NULL)
    return;

    Node *curr=root;
    stack<Node*> s;
    s.push(root);
    stack<int> out;
    while (!s.empty())
    {
        Node* curr = s.top();
        s.pop();
        out.push(curr->data);
        if (curr->left) {
            s.push(curr->left);
        }
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    cout<<"Post-order Traversal"<<"\n";

    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
    cout<<"\n";
}
void levelorder(Node *root)
{
    if(root==NULL)
    {
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


int main()
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

	preorderIterative(root);
    cout<<"\n";
    inorderIterative(root);
    cout<<"\n";
    postorderIterative(root);
    cout<<"\n";
    levelorder(root);



	return 0;
}