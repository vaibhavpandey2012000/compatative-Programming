#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node *link;
};
struct node *last=NULL;
void fun()
{
	cout<<"1.insert in begin"<<endl;
	cout<<"2.insert in last"<<endl;
	cout<<"3.display"<<endl;
	cout<<"4.insert betwwen"<<endl;
}
void insert_begin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	if(last==NULL)
	{
		last=temp;
		last->link=last;
	}
	else
	{
		temp->link=last->link;
		last->link=temp;
	}
}
void display()
{
	struct node *p=last->link;
	do{
		cout<<p->data<<" ";
		p=p->link;
	}
	while(p!=last->link);
	cout<<endl;
}
void insert_end()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cin>>temp->data;
	if(last==NULL)
	{
		last=temp;
		last->link=last;
	}
	else{
		temp->link=last->link;
		last->link=temp;
		last=temp;
	}
	
}
void insert_between()
{
	int data,after;
	cin>>data>>after;
	struct node *p=last;
	do{
		if(p->data==after)
		{
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=data;
			temp->link=p->link;
			p->link=temp;
			if(p==last)
			last=temp;
			return;
		}
	}
	while(p!=last->link);
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
				insert_begin();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				display();
				break;
			case 4:
				insert_between();
				break;
		}
	}
	
}