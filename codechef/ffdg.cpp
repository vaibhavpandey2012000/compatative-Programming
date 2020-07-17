#include <bits/stdc++.h> 
using namespace std; 

int arr[200005];
void add_edge(vector<int> adj[], int src, int dest) 
{ 
	adj[src].push_back(dest); 
	adj[dest].push_back(src); 
} 
bool BFS(vector<int> adj[], int src, int dest, int v, 
		int pred[], int dist[]) 
{ 
	list<int> queue; 
	bool visited[v]; 
	for (int i = 0; i < v; i++) { 
		visited[i] = false; 
		dist[i] = INT_MAX; 
		pred[i] = -1; 
	} 

	visited[src] = true; 
	dist[src] = 0; 
	queue.push_back(src); 

	while (!queue.empty()) { 
		int u = queue.front(); 
		queue.pop_front(); 
		for (int i = 0; i < adj[u].size(); i++) { 
			if (visited[adj[u][i]] == false) { 
				visited[adj[u][i]] = true; 
				dist[adj[u][i]] = dist[u] + 1; 
				pred[adj[u][i]] = u; 
				queue.push_back(adj[u][i]); 
				if (adj[u][i] == dest) 
					return true; 
			} 
		} 
	} 

	return false; 
} 
void printShortestDistance(vector<int> adj[], int s, 
						int dest, int v) 
{ 
	int pred[v], dist[v]; 

	if (BFS(adj, s, dest, v, pred, dist) == false) { 
		return; 
	} 

	vector<int> path; 
	int crawl = dest; 
	path.push_back(crawl); 
	while (pred[crawl] != -1) { 
		path.push_back(pred[crawl]); 
		crawl = pred[crawl]; 
	} 
	vector<int>vv;
	for (int i = path.size() - 1; i >= 0; i--) 
		vv.push_back(arr[path[i]]); 
	sort(vv.begin(),vv.end());
	int ans=INT_MAX;
	for(int i=1;i<vv.size();i++)
	ans=min(ans,abs(vv[i-1]-vv[i]));
	cout<<ans<<endl;
} 

int main() 
{ 
	int tc;
	cin>>tc;
	while(tc--){
		int v ,q;
		cin>>v>>q; 
		vector<int> adj[v+1]; 

		for(int i=1;i<=v;i++) cin>>arr[i];
		for(int i=0;i<v-1;i++){
			int a,b;
			cin>>a>>b;
			add_edge(adj, a, b);
		}
	 	
		for(int i=0;i<q;i++){
			int s, d; 
			cin>>s>>d;
			printShortestDistance(adj, s, d, v); 
		}
	}
	
	return 0; 
} 

