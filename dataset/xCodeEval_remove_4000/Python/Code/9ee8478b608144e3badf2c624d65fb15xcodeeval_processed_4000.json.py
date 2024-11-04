n, m, k = map(int, input().split())
a = []
b = []
d = 0
e = 0
for i in range(m+1):
    x = int(input())
    a.append(x)
for i in range(m):
    b.append(bin(a[-1]^a[i]).replace("0b",""))

for i in b:
    c = list(i)
    
    for j in range(len(c)):
        if(c[j] == '1'):
            d += 1
    
    if(d <= k):
        e += 1
    d = 0
        
print(e)





    










    
    
    






 






    
    
    
    

    
    
    
    
            
    
    
        



    
    
    



    
    





    


    
            



    
        
        



    
        



    
    
            







    















    


    

