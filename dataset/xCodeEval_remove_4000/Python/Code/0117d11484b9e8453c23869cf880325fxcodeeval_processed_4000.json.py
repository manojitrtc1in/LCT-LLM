





























































 








 







 




 






 









 








 





 




 







 




 


 







 


 








 

 




 


 







 








 

 






 




















 







 






 






 




 




 



 



 




 




 







 



 



 


























































































































import sys
def solve():
    n = int(input())
    s = ['T'] * n
    print(''.join(s))
    sys.stdout.flush()
    tot1 = int(input())
    if tot1 == n:
        return
    res1 = []
    for i in range(0, n, 3):
        if i + 2 < n:
            s[i] = s[i + 1] = s[i + 2] = 'F'
            print(''.join(s))
            sys.stdout.flush()
            res1.append(int(input()))
            if res1[-1] == n:
                return
            s[i] = s[i + 1] = s[i + 2] = 'T'
    s = ['T'] * n
    for i in range(0, n, 3):
        if i + 2 < n:
            s[i] = s[i + 2] = 'F'
    print(''.join(s))
    sys.stdout.flush()
    tot2 = int(input())
    if tot2 == n:
        return
    res2 = []
    for i in range(0, n, 3):
        if i + 2 < n:
            s[i + 1] = s[i + 2] = 'F'
            s[i] = 'T'
            print(''.join(s))
            sys.stdout.flush()
            res2.append(int(input()))
            if res2[-1] == n:
                return
            s[i] = s[i + 2] = 'F'
            s[i + 1] = 'T'

    ans = []
    for i in range(n // 3):
        x = tot1 - res1[i]
        y = tot2 - res2[i]
        if (x, y) == (3, 0):
            ans.append('TTT')
        elif (x, y) == (1, 2):
            ans.append('FTT')
        elif (x, y) == (1, -2):
            ans.append('TFT')
        elif (x, y) == (-1, 0):
            ans.append('FFT')
        elif (x, y) == (1, 0):
            ans.append('TTF')
        elif (x, y) == (-1, 2):
            ans.append('FTF')
        elif (x, y) == (-1, -2):
            ans.append('TFF')
        elif (x, y) == (-3, 0):
            ans.append('FFF')
    res = n - n // 3 * 3

    if len(ans) != n // 3:
        print('fuck',len(ans),n//3*3)

    if res == 1:
        s = ['T'] * n
        s[-1] = 'F'
        print(''.join(s))
        sys.stdout.flush()
        t = int(input())
        if t == n:
            return
        if t < tot1: ans.append('T')
        else: ans.append('F')
    if res == 2:
        s = ['T'] * n
        s[-2] = 'F'
        print(''.join(s))
        sys.stdout.flush()
        t = int(input())
        if t == n:
            return
        if t < tot1: ans.append('T')
        else: ans.append('F')
        s[-1] = 'F'
        print(''.join(s))
        sys.stdout.flush()
        t1 = int(input())
        if t1 == n:
            return
        if t1 < t: ans.append('T')
        else: ans.append('F')
    print(''.join(ans))
    sys.stdout.flush()
    t = int(input())
solve()





