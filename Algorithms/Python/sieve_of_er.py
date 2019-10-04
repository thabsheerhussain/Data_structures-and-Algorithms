print("enter the number upto which you want to find the prime numbers:")
x = int(input())

import math

def sieve(x):
    a=[1]*x
    a[0]=0
    a[1]=0
    for i in range(2,int(math.sqrt(101))):
        if a[i]==1:
            for j in range(i+i,101,i):
                a[j]=0

    return(a)


b = sieve(x+1)
print(b)

for i in range(0,x+1):
    if b[i]==1:
        print(i)
