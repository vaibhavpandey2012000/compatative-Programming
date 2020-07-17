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
void delete_start()
{
	if(root==NULL)
	return;
	else 
	root=root->next;
}
void delete_end(){
	if(root==NULL)
	return;
	struct node *p=root;
	if(p==NULL || p->next==NULL)
	{
		root=NULL;
		return;
	}
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	cout<<p->data<<" "<<p->next->data<<endl;
	p->next=NULL;
	
}

void delete_particular()
{
	cout<<"delete particular the elment:";
	int cc;
	cin>>cc;
	struct node *p=root;
	if(p->data==cc){
		p=p->next;
		root=p;
		return;
	} 
	while(p->next->data!=cc|| p->next==NULL)
	{
		p=p->next;
	}
	if(p->next==NULL)return;
	else{
		p->next=p->next->next;
	}
}

void delete_before(){
	cout<<"enter the element before witch delete:";
	int cc;
	cin>>cc;
	struct node *p=root;
	if(p->data==cc)
	return;
	while(p->next->data!=cc || p->next==NULL)
	{
		p=p->next;
	}
	if(p->next==NULL){
		return;
	}
	else{
		
	}
}

void delete_after(){
	cout<<"enter the element after which data is delete:";
	int cc;
	cin>>cc;
	struct node *p=root;
	while(p->data!=cc)
	{
		if(p->next==NULL) break;
		p=p->next;
	}
	if(p->next==NULL)return;
	else
	{
		p->next=p->next->next;
	}
}
void fun()
{
	cout<<"1.delete from start"<<endl;
	cout<<"2.delete from end"<<endl;
	cout<<"3.delete particular"<<endl;
	cout<<"4.delete from before of elemnt"<<endl;
	cout<<"5.delete from after of element"<<endl;
	cout<<"6.display"<<endl;
}
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<10;i++)
	append(arr[i]);
//	display();
	while(1)
	{
		fun();
		cout<<endl;
		int tt;
		cin>>tt;
		switch(tt)
		{
			case 1:
				delete_start();
				break;
			case 2:
				delete_end();
				break;
			case 3:
				delete_particular();
				break;
			case 4:
				delete_before();
				break;
			case 5:
				delete_after();
				break;
			case 6:
				display();
				break;
			default:
				exit(0);
		}
	}
	
}