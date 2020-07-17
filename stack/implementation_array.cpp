#include<bits/stdc++.h>
using namespace std;
const int maxN=21;
int arr[maxN];
int top=-1;
void fun()
{
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.Top"<<endl;
	cout<<"4.exit"<<endl;
}
void push()
{
	if(top==maxN-1)
	{
		cout<<"Overflow case cant enter"<<endl;
		return;
	}
	cout<<"enter the data:"<<endl;
	top++;
	cin>>arr[top];
}
int pop()
{
	if(top==-1)
	{
		cout<<"underflow case no element"<<endl;
		return -1;
	}
	int data=arr[top];
	top--;
	return data;
}
int topp()
{
	if(top==-1)
	{
		cout<<"underflow case no element"<<endl;
		return -1;
	}
	int data=arr[top];
	return data;
}
int main()
{
	while(1)
	{
		fun();
		int tt;
		cin>>tt;
		int val,vl;
		switch(tt)
		{
			case 1:
				push();
				break;
			case 2:
				val=pop();
				if(val!=-1)
				cout<<"poped item:"<<val<<endl;
				break;
			case 3:
				vl=topp();
				if(vl!=-1)
				cout<<"top item:"<<vl<<endl;
				break;
			case 4:
				exit(0);
		}
	}
}