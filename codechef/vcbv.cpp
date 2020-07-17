#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *root=NULL;
void append(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	temp->prev=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *t=root;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
		temp->prev=t;
		return;
	}
}

void display()
{
	struct node *temp=root;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		//cout<<endl;
		temp=temp->next;
	}
	
	cout<<endl;
}

void reverse()
{
	struct node *p1,*p2;
	p1=root;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	root=p1;
}
int main()
{
	int arr[5]={1,2,3,4,5};
	for(int i=0;i<5;i++)
	{
		append(arr[i]);
	}
	display();
	reverse();
	display();
	
}
