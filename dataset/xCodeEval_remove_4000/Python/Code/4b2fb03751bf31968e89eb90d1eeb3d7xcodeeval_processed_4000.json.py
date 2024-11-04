n = int(input())
a = list(map(int, input().split()))
b = 0
d = 0
e = 0
o = 0
g = []
h = []
m = []
for i in range(n):
    if(a[i]<0):
        b += 1
    elif(a[i]>0):
        d += 1
    else:
        e += 1
for i in range(n):
    if(b%2 == 1):
        if(a[i] < 0 and len(g) == 0):
            g.append(a[i])
        elif(a[i] > 0 or a[i] < 0):
            h.append(a[i])
        else:
            m.append(a[i])
    elif(b%2 == 0):
        if(a[i]<0 and len(g) == 0):
            g.append(a[i])
        elif(a[i]<0):
            if(d == 0):
                h.append(a[i])
            else:
                m.append(a[i])
        elif(a[i]>0):
            h.append(a[i])
        else:
            m.append(a[i])
    
        
if(d == 0 and len(h)%2 != 0):
    o = h.pop()
    m.append(o)
print(len(g),*g)
print(len(h),*h)
print(len(m),*m)



        
    
    







    










    
    
    






 






    
    
    
    

    
    
    
    
            
    
    
        



    
    
    



    
    





    


    
            



    
        
        



    
        



    
    
            







    















    


    

