#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string ss;
		cin>>ss;
		vector<int>v(3,0);
		int s=0,e=0,ans=INT_MAX;
		for(int e=0;e<ss.length();e++)
		{
			v[ss[e]-'0']++;
			if(v[0]!=0 && v[1]!=0 && v[2]!=0)
			{
				while(v[0]!=0 && v[1]!=0 && v[2]!=0)
				{
					v[ss[s]-'0']--;
					s++;
				}
				ans=min(ans,e-s-1);
			}
		}
		cout<<ans<<endl;
	}
}
