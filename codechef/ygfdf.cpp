#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *link;
};

struct node  *addend(struct node *start,int val)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	
	temp->data=val;
	p=start;
	cout<<"PP"<<endl;
	while(p->link!=NULL)
		p=p->link;
	p->link=temp;
	temp->link=NULL;
	return start;
}

void print(struct node *start)
{
	struct node *p=start;
	if(p==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	while(p!=NULL)
	{
		cout<<p->data<<" ";
	}
	cout<<endl;
}

int main()
{
	struct node *start;
	start=NULL;
	while(1)
	{
		cout<<"1. insert at end"<<endl;
		cout<<"default is printing"<<endl;
		int tt;
		cout<<"Enter the Choice:";
		
		cin>>tt;
		switch(tt)
		{
			case 1:
				int pp;
				cout<<" Enter the data:";
				cin>>pp;
				start=addend(start,pp);
				break;
			default:
				print(start);
		}
	}
}
