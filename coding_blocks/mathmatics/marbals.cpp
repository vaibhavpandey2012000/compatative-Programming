from math import *

def printNcR(n, r): 
    p = 1
    k = 1

    if (n - r < r): 
        r = n - r 
  
    if (r != 0):  
        while (r): 
            p *= n 
            k *= r 
  
            m = gcd(p, k) 
  
            p //= m 
            k //= m 
  
            n -= 1
            r -= 1
  
  
    else: 
        p = 1
  
    print(p)



tc=int(input())
while tc:
    a,b=input().split()
    a=int(a)
    b=int(b)
    a=a-1
    b=b-1
    printNcR(a, b)
    tc=tc-1