#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
void leftRotate(int arr[], int d, int n) 
{ 
    d = d % n; 
    int g_c_d = gcd(d, n); 
    for (int i = 0; i < g_c_d; i++) { 
        int temp = arr[i]; 
        int j = i; 
  
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
  
            if (k == i) 
                break; 
  
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    } 
} 
int main()
{
	int tc=1;
	//cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int arr[n],b[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		for(int i=0;i<n;i++)
		cin>>b[i];
		int mx=1;
		for(int i=0;i<n-1;i++)
		{
			leftRotate(arr,1,n);
			int p=0;
			for(int j=0;j<n;j++)
			{
				if(arr[j]==b[j])
				p++;
			}
			mx=max(mx,p);
		}
		cout<<mx<<endl;
	}
}
