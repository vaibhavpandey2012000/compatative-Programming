//1.st solution
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll ct[101]={0};
int main()
{
	ct[0]=1;
	ct[1]=1;
	for(int i=2;i<=100;i++)
	{
		for(int j=0;j<i;j++)
		{
			ct[i]+=ct[j]*ct[i-j-1];
		}
	//	cout<<endl;
	}
	int n;
	cin>>n;
	cout<<ct[n]<<endl;
}


//2nd solution
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll ct[101]={0};
int main()
{
	ct[0]=1,ct[1]=1;
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		ct[i]=0;
		for(int j=0;j<i;j++)
		{
			ct[i]+=ct[j]*ct[i-j-1];
		}
	}
	cout<<ct[n]<<endl;
}

//3rd solution
import math
n=int(input())
ans=math.factorial(2*n)//math.factorial(n+1)
ans//=math.factorial(n)
res=int(ans)
print(res)