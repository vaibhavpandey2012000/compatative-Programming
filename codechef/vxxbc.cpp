#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *root;
void append(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	if(root==NULL)
	root=temp;
	else{
		struct node *p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
}
void display()
{
	struct node *temp=root;
	int cnt=0;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
		cnt++;
	}
	cout<<endl;
}
void reverse()
{
	struct node *prev,*ptr,*next;
	prev=NULL;
	ptr=root;
	while(ptr!=NULL)
	{
		next=ptr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=next;
	}
	root=prev;
}
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<10;i++)
	append(arr[i]);
	display();
	reverse();
	display();
	
}
