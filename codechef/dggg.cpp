#include<bits/stdc++.h>
using namespace std;
const int maxN=5;
int arr[maxN];
int top=-1;
struct node{
	int data;
	struct node *next;
};
struct node *root=NULL;
void fun()
{
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.top"<<endl;
}
void insert()
{
	int item;
	cin>>item;
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->next=root;
		root=temp;
	}
}
int poping()
{
	if(root==NULL)
	{
		cout<<"stack underflow"<<endl;
		return -1;
	}
	else{
		int val=root->data;
		root=root->next;
		return val;
	}
}
int toping()
{
	if(root==NULL)
	{
		cout<<"stack underflow"<<endl;
		return -1;
	}
	else{
		int val=root->data;
		//root=root->next;
		return val;
	}
}
int display()
{
	struct node* p=root;
	for( ;p!=NULL;p=p->next)
	cout<<p->data<<" ";
	cout<<endl;
}
int main()
{
	while(1)
	{
		fun();
		int tt,pp;
		cin>>tt;
		switch(tt)
		{
			case 1:
				insert();
				break;
			case 2:
				pp=poping();
				if(pp!=-1)
				cout<<"pop:"<<pp<<endl;
				break;
			case 3:
				pp=toping();
				if(pp!=-1)
				cout<<"top:"<<pp<<endl;
				break;
			case 4:
				display();
				break;
			default:
				exit(0);
		}
	}
}
