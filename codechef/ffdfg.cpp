#include <iostream>
using namespace std;
int main() {
int r,c,q,i,j;
cin>> r>> q;
int **arr = new int*[r];
for( i=0;i<r;i++){
	    cin>> c;
for( j=0;j<c;j++){
  cin>> arr[i][j];  
}
} 
for(int b=0;b<q;b++){
    cin>> i>> j;
    cout<<arr[i][j]<<"\n";
}

    return 0;
}
