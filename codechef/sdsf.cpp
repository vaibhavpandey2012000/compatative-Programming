#include<bits/stdc++.h> 
using namespace std; 
int main()
{
    int i,j,n;
    char ch;
 
    printf("Enter number of rows: ");
    scanf("%d%c",&n,&ch);
    printf("Enter the symbol: ");
    ch=getchar();
 
    for(i=n;i>0;i--)
    {
	    for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        
	    if(i==1 || i==n)
            for(j=1;j<=i*2-1;j++)
            {
                printf("%c\t",ch);
            }
        else
	    {
            for(j=1;j<=i*2-1;j++)
            {  
                if(j==1 || j==i*2-1)
                    printf("%c",ch);
                else
                    printf("\t");
            }
        }
        printf("\n");
                       
    }             
 
    return 0;
}
