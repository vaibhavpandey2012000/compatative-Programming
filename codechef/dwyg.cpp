#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *link;
};

struct node *addend(struct node *start,int val)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->link=NULL;
	p=start;
	while(p->link!=NULL)
	{
		p=p->link;
	}
	p->link=temp;
	temp->link=NULL;
	return start;
}
struct node *addbeg(struct node *start,int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->link=start;
	start=temp;
	return start;
}
void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		cout<<"Link is empty"<<endl;
		return;
	}
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->link;
	}
	cout<<endl;
}
int main()
{
	struct node *start;
	start=NULL;
	while(1)
	{
		int data;
		cout<<"1. insertion at end"<<endl;
		cout<<"2. insertion at beg"<<endl;
		cout<<"Default for printing"<<endl;
		cout<<"Enter your choice:";
		int pp;
		cin>>pp;
		switch(pp)
		{
			case 1:
				cout<<"Enter your data:";
				cin>>data;
				start=addend(start,data);
				break;
			case 2:
				cout<<"Enter your Data:";
				cin>>data;
				start=addbeg(start,data);
			//	break;
			case 3:
				display(start);
		}
	}
	
}
