#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *root=NULL;
void append()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the data:";
	cin>>temp->data;
	temp->next=NULL;
	if(root==NULL)
	root=temp;
	else{
		struct node *p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
}
int display()
{
	struct node *temp=root;
	int cnt=0;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
		cnt++;
	}
	cout<<endl;
	return cnt;
}
void addbegin()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the data:";
	cin>>temp->data;
	if(root==NULL)
	root=temp;
	else
	{
		temp->next=root;
		root=temp;
	}
}
void addend()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the data:";
	cin>>temp->data;
	temp->next=NULL;
	if(root==NULL)
	root=temp;
	else{
		struct node *p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
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
void addafter()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data to enter and after the node:";
	int after;
	cin>>temp->data>>after;
	struct node *p=root;
	if(root==NULL)
	{
		root=temp;
	}
	else{
		while(p->data==after || p->next!=NULL)
		{
			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
	}
}
void addbefore()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data to enter and after the node:";
	int before;
	cin>>temp->data>>before;
	struct node *p=root;
	if(p==NULL)
	{
		p=temp;
		root=p;
	}
	else if(p->data==before)
	{
		temp->next=root;
		p=temp;
		root=p;
	}
	
	else {
		int f=1;
		while(p->next->data!=before)
		{
			p=p->next;
			if(p->next==NULL) {
				f=0;
				break;
			}
		}
		if(f){
			temp->next=p->next;
			p->next=temp;
		}
		
	}
	
}
int main()
{
	while(1)
	{
		func();
		cout<<"Enter your choice:";
		int t;
		cin>>t;
		int len;
		switch(t)
		{
			case 1:
				append();
				break;
			case 2:
				len=display();
				cout<<"Length of linked list:"<<len<<endl;
				break;
			case 3:
				addbegin();
				break;
			case 4:
				addend();
				break;
			case 5:
				exit(0);
			case 6:
				addafter();
				break;
			case 7:
				addbefore();
				break;	
		}
		cout<<endl;
	}
}
