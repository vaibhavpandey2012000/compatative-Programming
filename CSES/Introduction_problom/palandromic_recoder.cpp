#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	map<char,int>mp;
	for(auto e:s)
	{
		mp[e]++;
	}
	string s1="",s2="",s3="";
	int cnt=0;
	for(auto e:mp)
	{
		if(!(e.second&1)) 
		{
			for(int i=0;i<e.second;i+=2)
			s1+=e.first,s2+=e.first;
		}
		else{
			cnt++;
			if(cnt==2)
			{
				cout<<"NO SOLUTION"<<endl;
				return 0;
			}
			for(int i=0;i<e.second;i++)
			s3+=e.first;
		}
	}
	sort(s1.begin(),s1.end());
	sort(s2.rbegin(),s2.rend());
	cout<<s1<<" "<<s2<<" "<<s3<<" ";
	cout<<s1+s3+s2<<endl;
}