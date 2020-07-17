#include<bits/stdc++.h>
using namespace std;
void parmute(char *arr,int i)
{
	if(arr[i]=='\0')
	{
		cout<<arr<<",";
		return;
	}
	for(int j=i;arr[j]!='\0';j++)
	{
		swap(arr[i],arr[j]);
		parmute(arr,i+1);
		swap(arr[i],arr[j]);
	}
}
int main()
{
	char arr[100];
	cin>>arr;
	parmute(arr,0);
}
