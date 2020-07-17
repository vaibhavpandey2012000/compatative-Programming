#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *front=NULL,*rear=NULL;
void insert()
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	if(rear==NULL)
	{
		front=rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
int del()
{
	if(front==rear && front==NULL)
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	if(front==rear)
	{
		int val=front->data;
		front=rear=NULL;
		return val;
	}
	else
	{
		int val=front->data;
		front=front->next;
		return val;
	}
}
int top()
{
	if(front==rear && front==NULL)
	{
		cout<<"underflow"<<endl;
		return -1;
	}
	return front->data;
}
void display()
{
	struct node *ss=front;
	while(ss!=NULL)
	{
		cout<<ss->data<<" ";
		ss=ss->next;
	}
	cout<<endl;
}
void fun()
{
	cout<<"1.insert "<<endl;
	cout<<"2.delete"<<endl;
	cout<<"3.display element at front"<<endl;
	cout<<"4.all the element in queue"<<endl;
	cout<<"5.quit"<<endl;
}

int main()
{
	while(1)
	{
		int tt;
		fun();
		cin>>tt;
		int pp;
		switch(tt)
		{
			case 1:
				insert();
				break;
			case 2:
				pp=del();
				if(pp!=-1)
				cout<<"element:"<<pp<<endl;
				break;
			case 3:
				pp=top();
				if(pp!=-1)
				cout<<"element:"<<pp<<endl;
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
		}
		
	}
}