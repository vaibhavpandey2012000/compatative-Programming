#include<bits/stdc++.h>
using namespace std;

const int maxN=100;

struct node{
	struct node *ll;
	char data;
	struct node *rr;
};

struct node  *arr[maxN];
int top=-1;

void push_stack(struct node  *item)
{
	if(top==maxN-1)
	{
		cout<<"Overflow"<<endl;
		return;
	}
	top++;
	arr[top]=item;
}

struct node  *pop_stack()
{
	if(top==-1)
	{
		cout<<"Underflow"<<endl;
		exit(1);
	}
	struct node  *pp=arr[top];
	top--;
	return pp;
}

int stack_empty()
{
	if(top==-1)
	return 1;
	else
	return 0; 
}
struct node *root=NULL;

struct node *createnode(int item)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->ll=temp->rr=NULL;
}

void preorder(struct node *root)
{
	node *p=root;
	if(p==NULL)
	{
		cout<<"tree is empty";
		return;
	}
//	push_stack(p);
	while(1)
	{
		while(p->ll!=NULL)
		{
			push_stack(p);
			p=p->ll;
		}
		while(p->rr==NULL)
		{
			cout<<p->data<<" ";
			if(stack_empty())
			return;
			p=pop_stack();
		}
		cout<<p->data<<" ";
		p=p->rr;
	}
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
	
	preorder(root);
	
}