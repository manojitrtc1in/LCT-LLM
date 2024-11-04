for _ in range(int(input())):
    n,m=map(int,input().split())
    l=[]
    for i in range(n):
        k=input()
        x=list(k)
        l.append(x)
    c=0
    ans=[]
    if(m%2==1):
        for i in range(0,n-2):
            for j in range(0,m-1,2):
                if(l[i][j]=='0' and l[i][j+1]=='1'):
                    c+=1
                    l[i][j]='0'
                    l[i][j+1]='0'
                    ans.append([i,j+1,i+1,j,i+1,j+1])
                    if(l[i+1][j+1]=='1'):
                        l[i+1][j+1]='0'
                    else:
                        l[i+1][j+1]='1'
                    if(l[i+1][j]=='1'):
                        l[i+1][j]='0'
                    else:
                        l[i+1][j]='1'
                elif (l[i][j] == '1' and l[i][j + 1] == '0'):
                    c += 1
                    l[i][j] = '0'
                    l[i][j + 1] = '0'
                    ans.append([i, j, i + 1, j, i + 1, j + 1])
                    if(l[i+1][j+1]=='1'):
                        l[i+1][j+1]='0'
                    else:
                        l[i+1][j+1]='1'
                    if(l[i+1][j]=='1'):
                        l[i+1][j]='0'
                    else:
                        l[i+1][j]='1'
                elif (l[i][j] == '1' and l[i][j + 1] == '1'):
                    c += 1
                    l[i][j] = '0'
                    l[i][j + 1] = '0'
                    ans.append([i, j , i, j+1, i + 1, j + 1])
                    if(l[i+1][j+1]=='1'):
                        l[i+1][j+1]='0'
                    else:
                        l[i+1][j+1]='1'
            j=m-2
            if (l[i][j] == '0' and l[i][j + 1] == '1'):
                c += 1
                l[i][j] = '0'
                l[i][j + 1] = '0'
                ans.append([i, j + 1, i + 1, j, i + 1, j + 1])
                if (l[i + 1][j + 1] == '1'):
                    l[i + 1][j + 1] = '0'
                else:
                    l[i + 1][j + 1] = '1'
                if (l[i + 1][j] == '1'):
                    l[i + 1][j] = '0'
                else:
                    l[i + 1][j] = '1'
            elif (l[i][j] == '1' and l[i][j + 1] == '0'):
                c += 1
                l[i][j] = '0'
                l[i][j + 1] = '0'
                ans.append([i, j, i + 1, j, i + 1, j + 1])
                if (l[i + 1][j + 1] == '1'):
                    l[i + 1][j + 1] = '0'
                else:
                    l[i + 1][j + 1] = '1'
                if (l[i + 1][j] == '1'):
                    l[i + 1][j] = '0'
                else:
                    l[i + 1][j] = '1'
            elif (l[i][j] == '1' and l[i][j + 1] == '1'):
                c += 1
                l[i][j] = '0'
                l[i][j + 1] = '0'
                ans.append([i, j, i, j + 1, i + 1, j + 1])
                if (l[i + 1][j + 1] == '1'):
                    l[i + 1][j + 1] = '0'
                else:
                    l[i + 1][j + 1] = '1'
        i=n-2
        for j in range(0,m-1,2):
            c0=[]
            c1=[]
            if(l[i][j]=='1'):
                c1.append([i,j])
            else:
                c0.append([i,j])
            if (l[i][j+1] == '1'):
                c1.append([i,j+1])
            else:
                c0.append([i,j+1])
            if (l[i+1][j] == '1'):
                c1.append([i+1,j])
            else:
                c0.append([i+1,j])
            if (l[i+1][j+1] == '1'):
                c1.append([i+1,j+1])
            else:
                c0.append([i+1,j+1])
            l0=len(c0)
            l1=len(c1)
            if(l1==1):
                c+=1
                z=[]
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
                z=[]
                c+=1
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[2][0])
                z.append(c0[2][1])
                ans.append(z)
                c += 1
                z = []
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[2][0])
                z.append(c0[2][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
            elif l1==2:
                z = []
                c += 1
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
                z = []
                c += 1
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                z.append(c1[1][0])
                z.append(c1[1][1])
                ans.append(z)
            elif l1==3:
                z = []
                c += 1
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c1[1][0])
                z.append(c1[1][1])
                z.append(c1[2][0])
                z.append(c1[2][1])
                ans.append(z)
            elif l1==4:
                c+=1
                c0=[]
                z=[]
                for b in range(l1-1):
                    c0.append(c1[b])
                    z.append(c1[b][0])
                    z.append(c1[b][1])
                c1=c1[-1:]
                ans.append(z)
                c += 1
                z = []
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
                z = []
                c += 1
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[2][0])
                z.append(c0[2][1])
                ans.append(z)
                c += 1
                z = []
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[2][0])
                z.append(c0[2][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
        i=n-2
        j=m-2
        c0 = []
        c1 = []
        l[n-2][m-2]='0'
        l[n-1][m-2]='0'
        if (l[i][j] == '1'):
            c1.append([i, j])
        else:
            c0.append([i, j])
        if (l[i][j + 1] == '1'):
            c1.append([i, j + 1])
        else:
            c0.append([i, j + 1])
        if (l[i + 1][j] == '1'):
            c1.append([i + 1, j])
        else:
            c0.append([i + 1, j])
        if (l[i + 1][j + 1] == '1'):
            c1.append([i + 1, j + 1])
        else:
            c0.append([i + 1, j + 1])
        l0 = len(c0)
        l1 = len(c1)
        if (l1 == 1):
            c += 1
            z = []
            z.append(c1[0][0])
            z.append(c1[0][1])
            z.append(c0[0][0])
            z.append(c0[0][1])
            z.append(c0[1][0])
            z.append(c0[1][1])
            ans.append(z)
            z = []
            c += 1
            z.append(c1[0][0])
            z.append(c1[0][1])
            z.append(c0[0][0])
            z.append(c0[0][1])
            z.append(c0[2][0])
            z.append(c0[2][1])
            ans.append(z)
            c += 1
            z = []
            z.append(c1[0][0])
            z.append(c1[0][1])
            z.append(c0[2][0])
            z.append(c0[2][1])
            z.append(c0[1][0])
            z.append(c0[1][1])
            ans.append(z)
        elif l1 == 2:
            z = []
            c += 1
            z.append(c1[0][0])
            z.append(c1[0][1])
            z.append(c0[0][0])
            z.append(c0[0][1])
            z.append(c0[1][0])
            z.append(c0[1][1])
            ans.append(z)
            z = []
            c += 1
            z.append(c0[0][0])
            z.append(c0[0][1])
            z.append(c0[1][0])
            z.append(c0[1][1])
            z.append(c1[1][0])
            z.append(c1[1][1])
            ans.append(z)
        elif l1 == 3:
            z = []
            c += 1
            z.append(c1[0][0])
            z.append(c1[0][1])
            z.append(c1[1][0])
            z.append(c1[1][1])
            z.append(c1[2][0])
            z.append(c1[2][1])
            ans.append(z)
        elif l1 == 4:
            c0 = []
            z=[]
            c+=1
            for b in range(0,l1 - 1):
                c0.append(c1[b])
                z.append(c1[b][0])
                z.append(c1[b][1])
            c1 = c1[:-1]
            c += 1
            ans.append(z)
            z = []
            z.append(c1[0][0])
            z.append(c1[0][1])
            z.append(c0[0][0])
            z.append(c0[0][1])
            z.append(c0[1][0])
            z.append(c0[1][1])
            ans.append(z)
            z = []
            c += 1
            z.append(c1[0][0])
            z.append(c1[0][1])
            z.append(c0[0][0])
            z.append(c0[0][1])
            z.append(c0[2][0])
            z.append(c0[2][1])
            ans.append(z)
            c += 1
            z = []
            z.append(c1[0][0])
            z.append(c1[0][1])
            z.append(c0[2][0])
            z.append(c0[2][1])
            z.append(c0[1][0])
            z.append(c0[1][1])
            ans.append(z)

    else:
        for i in range(0,n-2):
                for j in range(0, m, 2):
                    if (l[i][j] == '0' and l[i][j + 1] == '1'):
                        c += 1
                        l[i][j] = '0'
                        l[i][j + 1] = '0'
                        ans.append([i, j + 1, i + 1, j, i + 1, j + 1])
                        if (l[i + 1][j + 1] == '1'):
                            l[i + 1][j + 1] = '0'
                        else:
                            l[i + 1][j + 1] = '1'
                        if (l[i + 1][j] == '1'):
                            l[i + 1][j] = '0'
                        else:
                            l[i + 1][j] = '1'
                    elif (l[i][j] == '1' and l[i][j + 1] == '0'):
                        c += 1
                        l[i][j] = '0'
                        l[i][j + 1] = '0'
                        ans.append([i, j, i + 1, j, i + 1, j + 1])
                        if (l[i + 1][j + 1] == '1'):
                            l[i + 1][j + 1] = '0'
                        else:
                            l[i + 1][j + 1] = '1'
                        if (l[i + 1][j] == '1'):
                            l[i + 1][j] = '0'
                        else:
                            l[i + 1][j] = '1'
                    elif (l[i][j] == '1' and l[i][j + 1] == '1'):
                        c += 1
                        l[i][j] = '0'
                        l[i][j + 1] = '0'
                        ans.append([i, j, i, j + 1, i + 1, j + 1])
                        if (l[i + 1][j + 1] == '1'):
                            l[i + 1][j + 1] = '0'
                        else:
                            l[i + 1][j + 1] = '1'

        i = n - 2
        for j in range(0, m, 2):
            c0 = []
            c1 = []
            if (l[i][j] == '1'):
                c1.append([i, j])
            else:
                c0.append([i, j])
            if (l[i][j + 1] == '1'):
                c1.append([i, j + 1])
            else:
                c0.append([i, j + 1])
            if (l[i + 1][j] == '1'):
                c1.append([i + 1, j])
            else:
                c0.append([i + 1, j])
            if (l[i + 1][j + 1] == '1'):
                c1.append([i + 1, j + 1])
            else:
                c0.append([i + 1, j + 1])
            l0 = len(c0)
            l1 = len(c1)
            if (l1 == 1):
                c += 1
                z = []
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
                z = []
                c += 1
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[2][0])
                z.append(c0[2][1])
                ans.append(z)
                c += 1
                z = []
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[2][0])
                z.append(c0[2][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
            elif l1 == 2:
                z = []
                c += 1
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
                z = []
                c += 1
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                z.append(c1[1][0])
                z.append(c1[1][1])
                ans.append(z)
            elif l1 == 3:
                z = []
                c += 1
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c1[1][0])
                z.append(c1[1][1])
                z.append(c1[2][0])
                z.append(c1[2][1])
                ans.append(z)
            elif l1 == 4:
                c0 = []
                z=[]
                c+=1
                for b in range(l1 - 1):
                    c0.append(c1[b])
                    z.append(c1[b][0])
                    z.append(c1[b][1])
                c1 = c1[-1:]
                ans.append(z)
                c += 1
                z = []
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
                z = []
                c += 1
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[0][0])
                z.append(c0[0][1])
                z.append(c0[2][0])
                z.append(c0[2][1])
                ans.append(z)
                c += 1
                z = []
                z.append(c1[0][0])
                z.append(c1[0][1])
                z.append(c0[2][0])
                z.append(c0[2][1])
                z.append(c0[1][0])
                z.append(c0[1][1])
                ans.append(z)
    if(c==0):
        ans.append([0,0,1,0,1,1])
        ans.append([0,0,1,0,1,1])
        c=2
    print(c)
    for i in ans:
        k=[]
        for j in i:
            k.append(j+1)
        print(*k)










