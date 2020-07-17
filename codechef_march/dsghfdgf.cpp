#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll a[n],b[n];
		int val=0;
		map<ll,ll> mpa, mpb;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			mpa[a[i]]++;
			val^=a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			mpa[b[i]]++;
			val^=b[i];
		}
		if(val!=0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		sort(a,a+n);
		sort(b,b+n);
		vector<ll>av,bv;
		for(auto x:mpa)
		{
			if(mpb.find(x.first)!=mpb.end())
			{
				if(mpb[x.first]>=x.second)
				{
					mpb[x.first]-=x.second;
					mpb[x.first]/=2;
					while(mpb[x.first]--)
					{
						av.push_back(x.first);
					}
				}
				else{
					x.second-=mpb[x.first];
					mpb[x.first]=0;
					x.second=(x.second>>1);
					while(x.second--)
					{
						av.push_back(x.first);
					}
				}
			}
			else{
				x.second/=2;
				while(x.second--)
				{
					av.push_back(x.first);
				}
			}	
		}
		for(auto x:mpb)
		{
			if(x.second!=0)
			{
				x.second=(x.second>>1);
				while(x.second--)
				{
					bv.push_back(x.first);
				}
			}
		}
		
		 if(av.size()==0 || bv.size()==0){
            cout<<0<<endl;
            continue;
        }
        
		sort(av.begin(),av.end());
		sort(bv.begin(),bv.end());
		
		ll ele=min(a[0],b[0]);
		
		reverse(av.begin(),av.end());
		
		ll ans=0;
		
		for(int i=0;i<av.size();i++)
		{
			if(min(av[i],bv[i])>2*ele)
			{
				ans+=(ele<<2);
			}
			else{
				ans+=min(av[i],bv[i]);
			}
		}
		cout<<ans<<endl;
	}
}
