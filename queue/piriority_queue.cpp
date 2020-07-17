#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *root=NULL;
void fun()
{
	cout<<"1.Insertion"<<endl;
	cout<<"2.deletion"<<endl;
	cout<<"3.diplay"<<endl;
	cout<<"4.Quit"<<endl;
}
void insertion()
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	int item;
	cin>>item;
	temp->data=item;
	temp->next=NULL;
	if(root==NULL || item<root->data)
	{
		temp->next=root;
		root=temp;
	}
	else{
		struct node *pp=root;
		while(pp->next!=NULL && pp->next->data<item)
		pp=pp->next;
		temp->next=pp->next;
		pp->next=temp;
	}
	
}
void display()
{
	struct node *pp=root;
	while(pp!=NULL)
	{
		cout<<pp->data<<" ";
		pp=pp->next;
	}
	cout<<endl;
}
int deletion()
{
	if(root==NULL)
	{
		cout<<"queue underflow"<<endl;
		return -1;
	}
	else{
		int data=root->data;
		root=root->next;
		return data;
	}
}
int main()
{
	while(1)
	{
		fun();
		int tt, dd;
		cin>>tt;
		switch(tt)
		{
			case 1:
				insertion();
				break;
			case 2:
				dd=deletion();
				if(dd!=-1)
				cout<<"val:"<<dd<<endl;
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
		
	}
}