t=int(input())
for i in range(t):
    n,m=input().strip().split(" ")
    n,m=[int(n),int(m)]
    p=[]
    for i in range(n):
        s=input()
        p.append(list(s))
    
    ans=[]
    for i in range(0,n-1,2):
        
        for j in range(0,m-1,2):
            a=int(p[i][j])
            b=int(p[i][j+1])
            c=int(p[i+1][j])
            d=int(p[i+1][j+1])
            rts=a+b+c+d
            if rts==0:
                pass
            elif rts==3:
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            elif rts==2:
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            elif rts==1:
                if a:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    
                    b=1
                    c=1
                    p[i][j+1]="1"
                    p[i][j]="0"
                    p[i+1][j]="1"
                elif b:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=0
                    c=1
                    p[i][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                elif c:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=1
                    c=0
                    p[i][j+1]="1"
                    p[i][j]="1"
                    p[i+1][j]="0"
                elif d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=1
                    c=1
                    d=0
                    p[i+1][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            
            elif rts==4:
                ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                a=0
                b=0
                c=0
                p[i][j]="0"
                p[i+1][j]="0"
                p[i][j+1]="0"
                if a:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    
                    b=1
                    c=1
                    p[i][j+1]="1"
                    p[i][j]="0"
                    p[i+1][j]="1"
                elif b:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=0
                    c=1
                    p[i][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                elif c:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=1
                    c=0
                    p[i][j+1]="1"
                    p[i][j]="1"
                    p[i+1][j]="0"
                elif d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=1
                    c=1
                    d=0
                    p[i+1][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
          
    if n%2:
        i=n-2
        for j in range(0,m-1):
            a=int(p[i][j])
            b=int(p[i][j+1])
            c=int(p[i+1][j])
            d=int(p[i+1][j+1])
            rts=a+b+c+d
            if rts==0:
                pass
            elif rts==3:
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            elif rts==2:
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            elif rts==1:
                if a:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    
                    b=1
                    c=1
                    p[i][j+1]="1"
                    p[i][j]="0"
                    p[i+1][j]="1"
                elif b:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=0
                    c=1
                    p[i][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                elif c:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=1
                    c=0
                    p[i][j+1]="1"
                    p[i][j]="1"
                    p[i+1][j]="0"
                elif d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=1
                    c=1
                    d=0
                    p[i+1][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            
            elif rts==4:
                ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                a=0
                b=0
                c=0
                p[i][j]="0"
                p[i+1][j]="0"
                p[i][j+1]="0"
                if a:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    
                    b=1
                    c=1
                    p[i][j+1]="1"
                    p[i][j]="0"
                    p[i+1][j]="1"
                elif b:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=0
                    c=1
                    p[i][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                elif c:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=1
                    c=0
                    p[i][j+1]="1"
                    p[i][j]="1"
                    p[i+1][j]="0"
                elif d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=1
                    c=1
                    d=0
                    p[i+1][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"            
    if m%2:
        j=m-2
        for i in range(0,n-1):
            a=int(p[i][j])
            b=int(p[i][j+1])
            c=int(p[i+1][j])
            d=int(p[i+1][j+1])
            rts=a+b+c+d
            if rts==0:
                pass
            elif rts==3:
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            elif rts==2:
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            elif rts==1:
                if a:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    
                    b=1
                    c=1
                    p[i][j+1]="1"
                    p[i][j]="0"
                    p[i+1][j]="1"
                elif b:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=0
                    c=1
                    p[i][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                elif c:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=1
                    c=0
                    p[i][j+1]="1"
                    p[i][j]="1"
                    p[i+1][j]="0"
                elif d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=1
                    c=1
                    d=0
                    p[i+1][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
            
            elif rts==4:
                ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                a=0
                b=0
                c=0
                p[i][j]="0"
                p[i+1][j]="0"
                p[i][j+1]="0"
                if a:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    
                    b=1
                    c=1
                    p[i][j+1]="1"
                    p[i][j]="0"
                    p[i+1][j]="1"
                elif b:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=0
                    c=1
                    p[i][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                elif c:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=1
                    b=1
                    c=0
                    p[i][j+1]="1"
                    p[i][j]="1"
                    p[i+1][j]="0"
                elif d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=1
                    c=1
                    d=0
                    p[i+1][j+1]="0"
                    p[i][j]="1"
                    p[i+1][j]="1"
                if a and b:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    c=1
                    p[i+1][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif a and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    a=0
                    p[i][j]="0"
                    b=1
                    p[i][j+1]="1"
                    c=1
                    p[i+1][j]="1"
                elif b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    d=1
                    p[i+1][j+1]="1"
                elif c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    c=0
                    p[i+1][j]="0"
                    a=1
                    p[i][j]="1"
                    b=1
                    p[i][j+1]="1"
                elif b and d:
                    ans.append([i+1,j+1,i+2,j+1,i+1,j+2])
                    b=0
                    p[i][j+1]="0"
                    a=1
                    p[i][j]="1"
                    c=1
                    p[i+1][j]="1"
                if a and b and c:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+1])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
                elif a and c and d:
                    ans.append([i+1,j+1,i+2,j+1,i+2,j+2])
                    p[i][j]="0"
                    p[i+1][j]="0"
                    p[i+1][j+1]="0"
                    
                elif a and b and d:
                    ans.append([i+1,j+1,i+1,j+2,i+2,j+2])
                    p[i][j]="0"
                    p[i][j+1]="0"
                    p[i+1][j+1]="0"
                elif b and c and d:
                    ans.append([i+1,j+2,i+2,j+1,i+2,j+2])
                    p[i+1][j+1]="0"
                    p[i][j+1]="0"
                    p[i+1][j]="0"
    
    
    print(len(ans))
    for j in ans:
        print(*j)
        
                
            
                    
