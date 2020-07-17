#include<bits/stdc++.h>
using namespace std;
struct node{
	struct node *ll;
	char data;
	struct node *rr;
};
struct node *root=NULL;
struct node *createnode(int item)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->ll=temp->rr=NULL;
}
void order(struct node *ptr)
{
	if(ptr==NULL)
	return;
	//cout<<ptr->data<<",";   //preorder
	preorder(ptr->ll);
	//cout<<ptr->data<<",";	  //inorder
	preorder(ptr->rr);
	//cout<<ptr->data<<",";   //postorder
}
int main()
{
	int data;
	struct node *p=createnode('A');
	root=p;
	p=createnode('B');
	root->ll=p;
	p=createnode('C');
	root->rr=p;
	p=createnode('D');
	root->ll->ll=p;
	p=createnode('E');
	root->ll->rr=p;
	p=createnode('F');
	root->rr->ll=p;
	p=createnode('G');
	root->rr->rr=p;
	p=createnode('J');
	root->rr->rr->ll=p;
	p=createnode('H');
	root->ll->rr->ll=p;
	p=createnode('I');
	root->ll->rr->rr=p;
	
	order(root);
	
}