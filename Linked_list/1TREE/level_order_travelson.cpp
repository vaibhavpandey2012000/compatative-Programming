#include<bits/stdc++.h>
using namespace std;

const int maxN=100;

struct node{
	struct node *ll;
	char data;
	struct node *rr;
};

struct node  *arr[maxN];
int front=-1,rear=-1;

void insert_queue(struct node  *item)
{
	if(rear==maxN-1)
	{
		cout<<"Queue overflow"<<endl;
		return;
	}
	if(front==-1)
	front=0;
	rear++;
	arr[rear]=item;
}

struct node  *pop_queue()
{
	struct node *item;
	if(front==-1 || front==rear+1)
	{
		cout<<"Queue underflow"<<endl;
		return 0;
	}
	item=arr[front];
	front=front+1;
	return item;
}

int queue_empty()
{
	if(front==rear+1||front==-1)
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

void levelorder_travelson(struct node *root)
{
	struct node *ptr=root;
	if(ptr==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	insert_queue(root);
	while(!queue_empty())
	{
		ptr=pop_queue();
		cout<<ptr->data<<" ";
		if(ptr->ll!=NULL)
		insert_queue(ptr->ll);
		if(ptr->rr!=NULL)
		insert_queue(ptr->rr);
	}
	cout<<endl;
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
	
	levelorder_travelson(root);
	
}