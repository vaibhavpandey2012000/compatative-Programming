#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *root=NULL;
void insert()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	cin>>temp->data;
	temp->next=NULL;
	if(root==NULL)
	{
		root=temp;
		return;
	}
	else{
		temp->next=root;
		root=temp;
		return;
	}
	
}
void sorting()
{
	struct node *ptr,*cpt;
	ptr=root;
	while(ptr->next!=NULL)
	{
		cpt=ptr->next;
		while(cpt!=NULL)
		{
			if(ptr->data>cpt->data)
			{
				swap(ptr->data,cpt->data);
			}
			cpt=cpt->next;
		}
		ptr=ptr->next;
	}
}
void sorting_link()
{
	
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
void fun()
{
	cout<<"1.insert"<<endl;
	cout<<"21.sorting by data transfer"<<endl;
	cout<<"22.sorting by link transfrt"<<endl;
	cout<<"3.display"<<endl;
	cout<<"4.exit"<<endl;
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
			case 21:
				sorting_data();
				break;
			case 22:
				sorting_link();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
}