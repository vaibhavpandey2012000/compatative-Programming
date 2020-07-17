#include<bits/stdc++.h>
using namespace std;
const int maxN=5;
int arr[maxN];
int front=-1,rear=-1;
void insert()
{
	if((front==0 && rear==maxN-1) || rear+1==front)
	{
		cout<<"queue if full"<<endl;
		return;
	}
	else
	{
		if(front==-1)
		{
			front++;
			rear++;
			cin>>arr[rear];
		}
		else{
			rear=(rear+1)%maxN;
			cin>>arr[rear];
		}
	}
}
int del()
{
	if(front==-1 )
	{
		cout<<"queue is empty"<<endl;
		return -1;
	}
	int item=arr[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else{
		front=(front+1)%maxN;
	}
	return item;
}
int top()
{
	if(front==-1 )
	{
		cout<<"queue is empty"<<endl;
		return -1;
	}
	int item=arr[front];
	return item;
}
void display()
{
	int i=front;
	if(front<=rear)
	{
		while(i<=rear)
		cout<<arr[i++]<<" ";
		cout<<endl;
	}
	else
	{
		while(i<=maxN-1)
		cout<<arr[i++]<<" ";
		i=0;
		while(i<=rear)
		cout<<arr[i++]<<" ";
		cout<<endl;
	}
}
void fun()
{
	cout<<"1.insert "<<endl;
	cout<<"2.delete"<<endl;
	cout<<"3.display element at front"<<endl;
	cout<<"4.all the element in queue"<<endl;
	cout<<"5.quit"<<endl;
}

int main()
{
	while(1)
	{
		int tt;
		fun();
		cin>>tt;
		int pp;
		switch(tt)
		{
			case 1:
				insert();
				break;
			case 2:
				pp=del();
				if(pp!=-1)
				cout<<"element:"<<pp<<endl;
				break;
			case 3:
				pp=top();
				if(pp!=-1)
				cout<<"element:"<<pp<<endl;
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
		}
		
	}
}