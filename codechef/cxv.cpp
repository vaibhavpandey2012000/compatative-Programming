#include<bits/stdc++.h>
using namespace std;
int arr[200005];
vector<int> adj[200005];

void printPath(vector<int> stack) 
{ 
    int i;
	vector<int>vv; 
    for (i = 0; i < (int)stack.size()-1 ; 
         i++) { 
        //cout << arr[stack[i]]<< " -> "; 
        vv.push_back(arr[stack[i]]);
    } 
   // cout << arr[stack[i]]; 
    vv.push_back(arr[stack[i]]);
    sort(vv.begin(),vv.end());
    int ans=INT_MAX;
    for(int i=1;i<vv.size();i++)
    {
    	ans=min(ans,abs(vv[i-1]-vv[i]));
	}
	cout<<ans<<endl;
} 

void DFS(vector<int> v[], 
         bool vis[], 
         int x, 
         int y, 
         vector<int> stack) 
{ 
    stack.push_back(x); 
    if (x == y) { 
        printPath(stack); 
        return; 
    } 
    vis[x] = true; 
    int flag = 0; 
    if (!v[x].empty()) { 
        for (int j = 0; j < v[x].size(); j++) { 
            if (vis[v[x][j]] == false) { 
                DFS(v, vis, v[x][j], y, stack); 
                flag = 1; 
            } 
        } 
    } 
    if (flag == 0) { 
        stack.pop_back(); 
    } 
} 

void DFSCall(int x, 
             int y, 
             vector<int> v[], 
             int n, 
             vector<int> stack) 
{ 
    bool vis[n + 1]; 
  
    memset(vis, false, sizeof(vis)); 
  
    DFS(v, vis, x, y, stack); 
} 
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,q;
		cin>>n>>q;

		for(int i=1;i<=n;i++)
		{
			adj[i].clear();
			cin>>arr[i];
		}
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i=0;i<q;i++)
		{
			vector<int>stack;
			int uu,vv;
			cin>>uu>>vv;
			DFSCall(uu, vv, adj, n, stack);
		}
		
	
	}
}
