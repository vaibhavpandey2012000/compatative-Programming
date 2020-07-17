#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0)); 
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,p;
		cin>>n>>p;
		int a=1,b=1,aa=n,bb=n;
		int arr[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				arr[i][j]=rand()%2;
			}
		}
		for(int i=0;i<n;i++)
		{
			//cout<<"kk"<<endl;
			int temp;
			cout<<1<<" "<<a<<" "<<b<<" "<<aa<<" "<<bb<<endl;
			cin>>temp;
			int c1=0;
			vector<pair<int,int> >vp,vz;
			for(int i=a-1;i<aa-1;i++)
			{
				for(int j=b-1;j<bb-1;j++)
				{
					if(arr[i][j])
					c1++,vz.push_back({i,j});
					else
					vp.push_back({i,j});
				}
			}
			if(c1>temp){
			//	cout<<"pp"<<endl;
				while(c1>temp)
				{ 
  				auto it = vp.begin(); 
  				int pos=(rand()+vp.size())%vp.size();
  				pair<int,int> pp=*(it+pos);
  				arr[pp.first][pp.second]=1;
    			vp.erase(it+pos); 
    			c1--;
				if(vp.size()==0)
    			break;	
				}
			}
			else if(c1<temp)
			{
			//	cout<<"gg"<<endl;
				while(c1<temp)
				{
					vector<pair<int,int> >::iterator it; 
  					it = vz.begin(); 
  					int pos=(rand()+vz.size())%vz.size();
  					pair<int,int> pp=*(it+pos);
  					arr[pp.first][pp.second]=0;
    				vz.erase(it+pos); 
    				c1++;
    				if(vz.size()==0)
    				break;
				}
			}
			if(i%2==0)
			a++,b++;
			else
			aa--,bb--;
		}
		cout<<"2"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		int temp;
		cin>>temp;
	}
}
