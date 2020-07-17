#include<bits/stdc++.h>
using namespace std;
const int maxN=105;
int arr[maxN];
int h_size=0;
void fun()
{
	cout<<"1.crearte heap"<<endl;
	cout<<"2.insert into heap"<<endl;
	cout<<"3.delete max element from heap"<<endl;
	cout<<"4.max element"<<endl;
	cout<<"5.display"<<endl;
	cout<<"default.exit"<<endl;
}
void restore(int i)
{
	int k=arr[i];
	int par=i/2;
	while(par>=1 && arr[par]<k)
	{
		arr[i]=arr[par];
		i=par;
		par=i/2;
	}
	arr[i]=k;
}
void restoreDown(int i)
{
	int lc=2*i,rc=lc+1;
	int num=arr[i];
	while(rc<=h_size)
	{
		if(num>=arr[lc] && num>=arr[rc])
		{
			arr[i]=num;
			return;
		}
		else if(arr[lc]>arr[rc])
		{
			arr[i]=arr[lc];
			i=lc;
		}
		else{
			arr[i]=arr[rc];
			i=rc;
		}
		lc=2*i;
		rc=lc+1;
	}
	if(lc==h_size && num<arr[lc])
	{
		arr[i]=arr[lc];
		i=lc;
	}
	arr[i]=num;
}
void create_heap()
{
	cin>>h_size;
	for(int i=1;i<=h_size;i++)
	cin>>arr[i];
/*
 // this will take o(nlogn) time total 
	for(int i=2;i<=h_size;i++)
	{
		restore(i);
	}
*/
// restoreDown take o(n) time call at all nonleaf node
	for(int i=h_size/2;i>=1;i--)
	{
		restoreDown(i);
	}
}
void display()
{
	for(int i=1;i<=h_size;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}
void insert_heap()
{
	int val;
	cin>>val;
	h_size++;
	arr[h_size]=val;
	restore(h_size);
}
int max_element()
{
	if(h_size==0)
	{
		cout<<"heap is empty"<<endl;
		return -1;
	}
	else
	return arr[1];
}
int delete_max()
{
	if(h_size==0)
	{
		cout<<"heap is empty"<<endl;
		return -1;
	}
	else{
		int num=arr[1];
		arr[1]=arr[h_size];
		h_size--;
		restoreDown(1);
		return num;
	}
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
				create_heap();
				break;
			case 2:
				insert_heap();
				break;
			case 3:
				val=delete_max();
				if(val!=-1)
				cout<<val<<endl;
				break;
			case 4:
				val=max_element();
				if(val!=-1)
				cout<<val<<endl;
				break;
			case 5:
				display();
				break;
			default:
				exit(0);
		}
	}
}
