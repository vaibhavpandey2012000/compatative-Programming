#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
void multiply(int F[2][2], int M[2][2]); 
  
void power(int F[2][2], int n); 
  
/* function that returns nth Fibonacci number */
int fib(int n) 
{ 
  int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return (F[0][0]%mod); 
} 
  
/* Optimized version of power() in method 4 */
void power(int F[2][2], int n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  int M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%mod; 
  int y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%mod; 
  int z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%mod; 
  int w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%mod; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
int combine(int a,int b){
    if (b == 0) 
        return a; 
    return combine(b, a % b); 
}
void buildTree(int *a,int s,int e,int *tree,int index){
    //Base Case
    if(s==e){
        tree[index]=a[s];
        return;
    }
    //Recursive case
    int mid=(s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index]=combine(tree[2*index],tree[2*index+1]);
    return;
}
int query(int *tree,int ss,int se,int qs,int qe,int index){
    //Complete Overlap
    if(ss>=qs && se<=qe)
     return tree[index];
     //No Overlap
    if(ss>qe || qs>se)
     return 0;
     //Partial Overlap
    int mid=(ss+se)/2;
    int leftAns=query(tree,ss,mid,qs,qe,2*index);
    int rightAns=query(tree,mid+1,se,qs,qe,2*index+1);
    return combine(leftAns,rightAns);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	int arr[n];
	int fibtree[n];
	int tree[4*n];
	for(int i=0;i<n;i++){
        cin>>arr[i];
	    fibtree[i]=fib(arr[i]);
        fibtree[i]%=mod;
    }
	buildTree(arr,0,n-1,tree,1);
	for(int i=0;i<q;i++){
	    int ql,qr;
	    cin>>ql>>qr;
	    int as=query(tree,0,n-1,ql-1,qr-1,1);
        int res=fib(as)%mod;
        cout<<res<<endl;
	}
	return 0;
}