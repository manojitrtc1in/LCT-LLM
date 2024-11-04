import math





















































testcases = int(input())
while testcases > 0:
    n,k = map(int,input().split())
    myString = input()
    if k==0:
        print("YES")
    elif n == 2*k:
        print("NO")
    else:
        flag=0
        i=0
        j=len(myString)-1
        count=1
        while count<=k and i!=j:
            if myString[i]!=myString[j]:
                flag=1
                break
            count+=1
            i+=1
            j-=1
        if flag==1:
            print("NO")
        else:
            print("YES")
    testcases-=1
    

        
    


    

            
            
    


   






    
