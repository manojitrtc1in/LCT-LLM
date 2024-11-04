
  







     
        

        





            













  


   








   
    






      







































































  


























    
    



















         
                














for _ in range(int(input())):

    n=int(input())
    l=list(map(int,input().split()))
    t=0
    
    for i in range(n-1,-1,-1):
        if l[i]==i+1:
            continue
        else:
            t=i
            break

    if t==0:
        print("0")

    else:
        j=[]
        for i in range(t,-1,-1):
            if l[i]==i+1:
               j.append(i+1)

        a=False
        
        for i in range(len(j)-1,-1,-1):
            if j[i]!=len(j)-i:
                a=True
                break

        if a==False:
            print("1")
        else:
            print("2")
            

    
        
            
     
        











