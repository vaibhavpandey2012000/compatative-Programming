#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct node *root=NULL;
void fun()
{
	cout<<"1.insert"<<endl;
	cout<<"2.display"<<endl;
	cout<<"3.search"<<endl;
	cout<<"4.exit"<<endl;
}
void insert()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	if(root==NULL||temp->data<root->data)
	{
		temp->next=root;
		root=temp;
		return;
	}
	else
	{
		struct node *p=root;
		while(p->next!=NULL && p->next->data<temp->data)
		{
			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
	}
}
void display()
{
	struct node *p=root;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void search()
{
	int val;
	cin>>val;
	struct node *p=root;
	int cnt=1;
	while(p!=NULL)
	{
		if(p->data==val)
		{
			cout<<"found at:"<<cnt<<endl;
			return;
		}
		else if(p->data>val)
		break;
		p=p->next;
		cnt++;
	}
	cout<<"NOt found"<<endl;
	return;
}
int main()
{
	while(1)
	{
		fun();
		int tt;
		cin>>tt;
		switch(tt)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				exit(0);
		}
	}
}