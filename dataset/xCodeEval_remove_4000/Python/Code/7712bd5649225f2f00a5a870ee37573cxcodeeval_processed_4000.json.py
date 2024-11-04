n, m = map(int, input().split())
a = []
b = []
d = []
e = 0
for i in range(n):
    s = input()
    s = list(s)
    a.append(s)
for i in range(len(a)):
    for j in range(i+1, len(a)):
        if(a[i] == a[j][::-1]):
            if(len(b) == 0):
                b.insert(0,''.join(map(str,a[i])))
                b.insert(1,''.join(map(str,a[j])))
            else:
                b.insert(0,''.join(map(str,a[i])))
                b.insert(len(b),''.join(map(str,a[j])))
    
    if(len(a[i])%2 == 0):
        if(a[i][:len(a[i])//2] == a[i][len(a[i])//2:][::-1]):
            e = 1
            if(len(d) == 0):
                b.insert(len(b)//2,''.join(map(str,a[i])))
                d.append(''.join(map(str,a[i])))
                
            
                
                
    else:
        if(a[i][:len(a[i])//2+1] == a[i][len(a[i])//2:][::-1]):
            e = 1
            if(len(d) == 0):
                b.insert(len(b)//2,''.join(map(str,a[i])))
                d.append(''.join(map(str,a[i])))
                
            
                
                
                
print(len(''.join(map(str,b))))
print(''.join(map(str,b)))










    
    
    






 






    
    
    
    

    
    
    
    
            
    
    
        



    
    
    



    
    





    


    
            



    
        
        



    
        



    
    
            







    















    


    

