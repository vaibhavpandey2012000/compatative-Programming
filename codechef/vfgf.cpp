#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<s.length();i++)
	{
		if(s[0]==s[i])
		{
			string sb1=s.substr(0,i);
		//	cout<<sb1<<endl;
			string sb2=s.substr(i,i);
		//	cout<<sb2<<endl;
			if(sb1==sb2){
				for(int j=2*i+1;j<s.length();j++)
				{
					if(s[2*i]==s[j])
					{
						//cout<<"aaaaaa"<<endl;
						int len=j-2*i;
						string sb3=s.substr(2*i,len);
					//	cout<<sb3<<endl;
						string sb4=s.substr(j,len);
					//	cout<<sb4<<endl;
						if(sb1==sb2 && sb3==sb4)
						cnt++;
					}
				}
				
			}
				
		}
	}
	cout<<cnt<<endl;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
}
