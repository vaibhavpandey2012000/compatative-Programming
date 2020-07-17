#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *root=NULL;
void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	temp->prev=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *t=root;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
		temp->prev=t;
		return;
	}
}

void display()
{
	struct node *temp=root;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		//cout<<endl;
		temp=temp->next;
	}
	
	cout<<endl;
}
void insertbeg()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	temp->prev=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else{
		root->prev=temp;
		temp->next=root;
		root=temp;
	}
	return;
}
void insertend()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	temp->prev=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *t=root;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
		temp->prev=t;
		return;
	}
}
void add_after()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter data and after witch node"<<endl;
	int cc;
	cin>>temp->data>>cc;
	temp->next=NULL;
	temp->prev=NULL;
	
	struct node *p=root;
	while(p!=NULL)
	{
		if(p->data==cc)
		{
			temp->prev=p;
			temp->next=p->next;
			if(p->next!=NULL)
			p->next->prev=temp;
			p->next=temp;
			return;
		}
		p=p->next;
	}
}
void add_before()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter data and after witch node"<<endl;
	int cc;
	cin>>temp->data>>cc;
	temp->next=NULL;
	temp->prev=NULL;
	
	struct node *p=root;
	if(p==NULL)
	p=temp;
	if(p->data==cc)
	{
		temp->next=p;
		p->prev=temp;
		root=temp;
		return;
	}
	while(p!=NULL)
	{
		if(p->data==cc)
		{
			temp->prev=p->prev;
			temp->next=p;
			p->prev->next=temp;
			p->prev=temp;
			return;
		}
		p=p->next;
	}
	p->next=temp;
	temp->prev=p;
	return;
}
void func()
{
	cout<<"1.append the data into list"<<endl;
	cout<<"2.diplay the list"<<endl;
	cout<<"3.enter in begning"<<endl;
	cout<<"4.enter in end"<<endl;
	cout<<"6.add after a node"<<endl;
	cout<<"7.add before a node"<<endl;
	cout<<"5.exit"<<endl;
}
int main()
{
	while(1)
	{
		func();
		cout<<"Enter your choice:";
		int t;
		cin>>t;
		switch(t)
		{
			case 1:
				append();
				break;
			case 2:
				display();
				break;
			case 3:
				insertbeg();
				break;
			case 4:
				insertend();
				break;
			case 5:
				exit(0);
				break;
			case 6:
				add_after();
				break;
			case 7:
				add_before();
				break;
		}
	}
}