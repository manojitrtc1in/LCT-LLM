import math



















































testcases = int(input())
while testcases > 0:
    n,k = map(int,input().split())
    myArray = list(map(int,input().split()))
    myMap = dict()
    maxValue = myArray[0]
    minValue = myArray[0]
    mexValue=-1
    for i in range(len(myArray)):
        myMap[myArray[i]]=1
        if i!=0:
            if maxValue < myArray[i]:
                maxValue = myArray[i]
            if minValue > myArray[i]:
                minValue = myArray[i]
                
    if minValue!=0:
        mexValue=0
    else:
        while True:
            mexValue+=1
            if myMap.get(mexValue)==None:
                break
    if mexValue > maxValue:
        print(len(myMap)+k)
    else:
        while k>0:
            value = int(math.ceil((mexValue+maxValue)/2))
            if myMap.get(value)==None:
                myMap[value]=1
            else:
                myMap[value]+=1
                break
            myArray.append(value)
            k-=1
        print(len(myMap))
    testcases-=1


    

        
    


    

            
            
    


   






    
