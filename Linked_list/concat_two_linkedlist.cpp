#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *root1=NULL,*last1,*root2=NULL,*last2;
void insert1()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	if(root1==NULL)
	{
		root1=last1=temp;
		return;
	}
	else{
		last1->next=temp;
		last1=temp;
	}
	
}
void insert2()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	if(root2==NULL)
	{
		root2=last2=temp;
		return;
	}
	else{
		last2->next=temp;
		last2=temp;
	}
	
}
void display1()
{
	struct node *p=root1;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;	
	}	
	cout<<endl;
}
void display2()
{
	struct node *p=root2;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;	
	}	
	cout<<endl;
}
void fun()
{
	cout<<"11.insert in 1st link list"<<endl;
	cout<<"12.insert in 2nd link list"<<endl;
	cout<<"21.display 1st linked list"<<endl;
	cout<<"21.display 2nd linked list"<<endl;
	cout<<"3.concatnate 2nd in 1st"<<endl;
	cout<<"4.exit"<<endl;
}
void concat()
{
	last1->next=root2;
	last1=last2;
	root2=NULL;
	last2=NULL;
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
			case 11:
				insert1();
				break;
			case 12:
				insert2();
				break;
			case 21:
				display1();
				break;
			case 22:
				display2();
				break;
			case 3:
				concat();
				break;
			case 4:
				exit(0);
		}
	}
}