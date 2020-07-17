#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
	string s;
	cin>>s;
	int cnt=1,max=1;
	for(int i=0;i<s.length();i++){
		if(s[i]==s[i-1])
			cnt++;
		else
			cnt=1;
		if(cnt>max)
			max=cnt;
	}
	cout<<max;
	return 0;
}
