 #include<bits/stdc++.h>
 #define ll long long
 using namespace std;
 ll subarray(vector<ll>& A, int K) {
        vector<ll> f(K, 0);
        f[0] = 1;
        ll s = 0;
        ll r = 0;
        
        for (int i = 0; i < A.size(); i++) {
            s += A[i];
            ll tmp = (K + (s%K)) % K;
            r += f[tmp];
            f[tmp]++;    
        }

        return r;
    }
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<ll>A(n);
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		cout<<subarray( A, n)<<endl;
	}
}