#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct node *root1=NULL,*root2=NULL,*root=NULL,*tail=NULL;
void fun()
{
	cout<<"10.insert in 1st"<<endl;
	cout<<"11.insert in 2nd"<<endl;
	cout<<"20.display in 1st"<<endl;
	cout<<"21.display in 2nd"<<endl;
	cout<<"3.marging"<<endl;
	cout<<"4.exit"<<endl;
}
void insert1()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	if(root1==NULL||temp->data<root1->data)
	{
		temp->next=root1;
		root1=temp;
		return;
	}
	else
	{
		struct node *p=root1;
		while(p->next!=NULL && p->next->data<temp->data)
		{
			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
	}
}
void insert2()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	if(root2==NULL||temp->data<root2->data)
	{
		temp->next=root2;
		root2=temp;
		return;
	}
	else
	{
		struct node *p=root2;
		while(p->next!=NULL && p->next->data<temp->data)
		{
			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
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
void display3()
{
	struct node *p=root;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void marging()
{
	struct node *p1,*p2;
	p1=root1;
	p2=root2;
	while(p1!=NULL && p2!=NULL)
	{
		cout<<"work for:";
		if(p1->data>p2->data)
		{
			cout<<"1"<<endl;
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=p2->data;
			temp->next=NULL;
			p2=p2->next;
			if(root==NULL && tail==NULL)
			{
				root=tail=temp;
				continue;
			}
			tail->next=temp;
			tail=temp;
		}
		else
		{
			cout<<"2"<<endl;
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=p1->data;
			temp->next=NULL;
			p1=p1->next;
			if(root==NULL && tail==NULL)
			{
				root=tail=temp;
				continue;
			}
			tail->next=temp;
			tail=temp;
		}
	}
	while(p1!=NULL)
	{
		cout<<"2"<<endl;
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=p1->data;
		temp->next=NULL;
		p1=p1->next;
		if(root==NULL && tail==NULL)
		{
			root=tail=temp;
			continue;
		}
		tail->next=temp;
		tail=temp;
	}
	while(p2!=NULL)
	{
		cout<<"1"<<endl;
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=p2->data;
		temp->next=NULL;
		p2=p2->next;
		if(root==NULL && tail==NULL)
		{
			root=tail=temp;
			continue;
		}
		tail->next=temp;
		tail=temp;
	}
	display3();
	
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
			case 10:
				insert1();
				break;
			case 11:
				insert2();
				break;
			case 20:
				display1();
				break;
			case 21:
				display2();
				break;
			case 3:
				marging();
				break;
			case 4:
				exit(0);
		}
	}
}