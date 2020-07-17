#include<bits/stdc++.h>
using namespace std;
const int len=100005;
int tree[26][len];
void update(int ind,int n,int val,int ch)
{
	while(ind<=n)
	{
		tree[ch][ind]+=val;
		ind+=(ind&(-ind));
	}
}
int quary(int i,int j)
{
	int sum=0;
	while(j>0)
	{
		sum+=tree[i][j];
		j-=(j&(-j));
	}
	return sum;
}
int main()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		update(i+1,n,1,(int)(s[i]-'a'));
	}
	while(q--)
	{
		int pp;
		cin>>pp;
		if(pp==1)
		{
			int ind; char ch;
			cin>>ind>>ch;
			update(ind+1,n,-1,(int)(s[ind-1]-'a'));
			update(ind+1,n,+1,(int)(ch-'a'));
			s[ind-1]=ch;
		}
		else{
			int l,r;
			cin>>l>>r;
			int e=0,o=0;
			for(int i=0;i<26;i++)
			{
				int left=quary(i,r);
				int right=quary(i,l-1);
				if((left-right)%2==0) e++;
				else o++;	
			}
			if(o==1 || o==0)
			{
				cout<<"yes"<<endl;
			}
			else
			{
				cout<<"no"<<endl;
			}
			
		}
	}
}