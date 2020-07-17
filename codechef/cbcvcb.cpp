#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node *link;
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
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->link=NULL;
	if(root==NULL||root->data>temp->data){
		temp->link=root;
		root=temp;	
		return;
	}
	struct node *p=root;
	while(p->link!=NULL && p->link->data>temp->data)
	{
		p=p->link;
	}
	temp->link=p->link;
	p->link=temp->link;
}
void display()
{
	struct node *p=root;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->link;
	}
	cout<<endl;
}
void search()
{
	
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
				break;
		}
	}
	
}
