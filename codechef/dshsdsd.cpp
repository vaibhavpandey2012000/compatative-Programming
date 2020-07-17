#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
int r,c,i,j,b,q;

cin>> r >> q;
vector<vector<int> >v(r);
for(i=0;i<r;i++){
cin>>c;
for(j=0;j<c;j++){
	int data;
	cin>>data;
v[i].push_back(data);
}
}
for(b=0;b<q;b++){
    cin>> i >> j;
    cout<< v[i][j] <<"\n";
}
   return 0;
}
