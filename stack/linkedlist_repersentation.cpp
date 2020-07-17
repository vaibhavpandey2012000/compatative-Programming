#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
void fun()
{
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.Top"<<endl;
	cout<<"4.exit"<<endl;
}
void push(){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}
int pop()
{
	if(start==NULL)
	{
		cout<<"overflow no data in stack"<<endl;
		return -1;
	}
	else{
		int val=start->data;
		start=start->next;
		return val;
	}
}
int topp()
{
	if(start==NULL)
	{
		cout<<"overflow no data in stack"<<endl;
		return -1;
	}
	else{
		int val=start->data;
		return val;
	}
}
int main()
{
	while(1)
	{
		fun();
		int tt;
		cin>>tt;
		int val,vl;
		switch(tt)
		{
			case 1:
				push();
				break;
			case 2:
				val=pop();
				if(val!=-1)
				cout<<"poped item:"<<val<<endl;
				break;
			case 3:
				vl=topp();
				if(vl!=-1)
				cout<<"top item:"<<vl<<endl;
				break;
			case 4:
				exit(0);
		}
	}
}