#include<bits/stdc++.h>
using namespace std;
const int maxN=100;
int arr[maxN];
int front=-1,rear=-1;
void fun()
{
	cout<<"1.insert "<<endl;
	cout<<"2.delete"<<endl;
	cout<<"3.display element at front"<<endl;
	cout<<"4.all the element in queue"<<endl;
	cout<<"5.quit"<<endl;
}
void insert()
{
	if(rear==maxN-1){
		cout<<"Queue overflow\n";
		return;
	}
	int data;
	cin>>data;
	if(front==-1)
	{
		front++;
	}
	rear++;
	arr[rear]=data;
}
int del()
{
	if(front==-1 || rear+1==front)
	{
		cout<<"queue underflow\n";
		return -1;
	}
	int data=arr[front];
	front++;
	return data;
}
int top()
{
	if(front==-1 || rear+1==front)
	{
		cout<<"queue underflow\n";
		return -1;
	}
	int data=arr[front];
	return data;
}
void display()
{
	for(int i=front;i<=rear;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
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