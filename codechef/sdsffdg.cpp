#include<bits/stdc++.h>
using namespace std;
const int maxN=5;
int arr[maxN];
int front=-1,back=-1;
void fun()
{
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.top"<<endl;
	cout<<"4.display"<<endl;
}
void pushing()
{
	if(back==maxN-1&&front==0 || front==back+1)
	{
		cout<<"queue overflow"<<endl;
		return;
	}
	int data;
	cin>>data;
	if(back==-1)
	{
		back=front=0;
		arr[back]=data;
	}
	else{
		back=(back+1)%maxN;
		arr[back]=data;
	}
}
int poping()
{
	if(back==-1 )
	{
		cout<<"queue underflow"<<endl;
		return -1;
	}
	int data=arr[front];
	if(front==back)
	{
		front=back=-1;
	}
	front=(front+1)%maxN;
	return data;
}
int toping()
{
	if(back==-1 )
	{
		cout<<"queue underflow"<<endl;
		return -1;
	}
	int data=arr[front];
	return data;
}
void display()
{
	for(int i=front;i<=back;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	while(1)
	{
		fun();
		int tt;
		cin>>tt;
		int val;
		switch(tt)
		{
			case 1:
				pushing();
				break;
			case 2:
				val=poping();
				if(val!=-1)
				cout<<val<<endl;
				break;
			case 3:
				val=toping();
				if(val!=-1)
				cout<<val<<endl;
				break;
			case 4:
				display();
				break;
			default:
				exit(0);
				
		}
	}
}
