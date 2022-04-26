#include <bits/stdc++.h>
using namespace std;

///--------------------Structure of Node---------------------------//

struct Node
{
    int value;
    struct Node *left, *right;
    struct Node *root;

};

///------------End of structure------------//

///------------To create a node and assign data to each section of node------------//

struct Node *create ( int val )
{
    struct Node *p = new Node;      //New Node
    p->value = val;
    p->left = p->right = NULL;
    p->root = NULL;
    return p;
}

///-----------------------------------------------------------------------------------------//

///-------------------To create and assign nodes in the binary according values--------------//

struct Node* tree(Node* t, int v){
	 if (t == NULL)
        return create(v);

    if (v < t->value)
        t->left = tree(t->left, v);
    else
        t->right = tree(t->right, v);

    return t;
}

///------------------------------------------------------------------------------------------//

///------------Number of Internal nodes in the binary tree------------///

int internal_nodes( struct Node* p )
{
    if ( p == NULL )
        return 0;
    if ( p->left == NULL && p->right == NULL )
        return 0;
    else
        return 1 + internal_nodes( p->left ) + internal_nodes( p->right );
}

///---------------------------------------------------------------//


///-------------------Driver function----------------------------//

int main()
{
   int size;
	Node *root = new Node;
	root = NULL;

	cout<<"Enter the size of array : ";
	cin>>size;          //size of array

    int a[size];        //'a' is an array to store values

	cout<<"Enter the elements in array : ";
	for(int i=0;i<size;i++)
    {
        cin>>a[i];      //Taking inputs
    }

	for(int i = 0; i < size; i++)
	{
	    root = tree(root, a[i]);        //calling tree function to assign nodes in tree according to values
	}

    cout << "\n No. of internal nodes in tree: "<<internal_nodes( root ) << endl;

    return 0;
}

///------------------End of driver function----------------------//
