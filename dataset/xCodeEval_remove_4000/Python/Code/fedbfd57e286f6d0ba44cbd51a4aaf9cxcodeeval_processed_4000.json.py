



from __future__ import division, print_function

import os,sys
from io import BytesIO, IOBase

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip


def ii():  return int(input())
def si():  return input()
def mi():  return map(int,input().strip().split(" "))
def msi(): return map(str,input().strip().split(" "))
def li():  return list(mi())

def dmain():
    sys.setrecursionlimit(1000000)
    threading.stack_size(1024000)
    thread = threading.Thread(target=main)
    thread.start()
    









abc='abcdefghijklmnopqrstuvwxyz'
abd={'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
mod=1000000007

inf = float("inf")
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]
def getKey(item): return item[1] 
def sort2(l):return sorted(l, key=getKey,reverse=True)
def d2(n,m,num):return [[num for x in range(m)] for y in range(n)]
def id0 (x): return (x and (not(x & (x - 1))) )
def id2(n): return bin(n).replace("0b","")
def ntl(n):return [int(i) for i in str(n)]
def ncr(n,r): return factorial(n)//(factorial(r)*factorial(max(n-r,1)))

def ceil(x,y):
    if x%y==0:
        return x//y
    else:
        return x//y+1

def powerMod(x,y,p):
    res = 1
    x %= p
    while y > 0:
        if y&1:
            res = (res*x)%p
        y = y>>1
        x = (x*x)%p
    return res

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x
    
def isPrime(n) : 
    if (n <= 1) : return False
    if (n <= 3) : return True
    if (n % 2 == 0 or n % 3 == 0) : return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
    return True



def read():
    sys.stdin  = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w') 





def main():



    for _ in range(ii()):


        n,m=mi()


        a=[]
        for i in range(n):

            a.append(list(si()))


        ans=[]


        for i in range(0,n,2):

            if i==n-1:
                continue


            for j in range(0,m,2):

                if j==m-1:
                    continue

                c=int(a[i][j])+int(a[i+1][j])+int(a[i][j+1])+int(a[i+1][j+1])


                if c==0:
                    continue

                elif c==1:

                    if a[i][j]=='1':    
                        ans.append([[i,j],[i+1,j],[i+1,j+1]])
                        ans.append([[i,j],[i+1,j],[i,j+1]])
                        ans.append([[i,j],[i+1,j+1],[i,j+1]])

                    elif a[i+1][j]=='1':

                        ans.append([[i+1,j],[i,j],[i,j+1]])
                        ans.append([[i+1,j],[i+1,j+1],[i,j]])
                        ans.append([[i+1,j],[i+1,j+1],[i,j+1]])

                    elif a[i][j+1]=='1':

                        ans.append([[i,j],[i+1,j],[i,j+1]])
                        ans.append([[i,j],[i,j+1],[i+1,j+1]])
                        ans.append([[i+1,j],[i,j+1],[i+1,j+1]])

                    elif a[i+1][j+1]=='1':

                        ans.append([[i,j],[i,j+1],[i+1,j+1]])
                        ans.append([[i,j],[i+1,j],[i+1,j+1]])
                        ans.append([[i+1,j],[i,j+1],[i+1,j+1]])


                elif c==2:

                    if a[i][j]==a[i+1][j+1]:

                        if a[i][j]=='1':

                            ans.append([[i+1,j],[i+1,j+1],[i,j+1]])
                            ans.append([[i,j],[i+1,j],[i,j+1]])

                        else:

                            ans.append([[i,j+1],[i+1,j+1],[i,j]])
                            ans.append([[i+1,j],[i,j],[i+1,j+1]])

                    else:


                        if a[i+1][j]=='1' and a[i+1][j+1]=='1':    
                            ans.append([[i,j],[i+1,j],[i,j+1]])
                            ans.append([[i,j],[i+1,j+1],[i,j+1]])

                        elif a[i][j]=='1' and a[i][j+1]=='1':

                            ans.append([[i+1,j],[i+1,j+1],[i,j]])
                            ans.append([[i+1,j],[i+1,j+1],[i,j+1]])

                        elif a[i][j]=='1' and a[i+1][j]=='1':

                            ans.append([[i,j],[i,j+1],[i+1,j+1]])
                            ans.append([[i+1,j],[i,j+1],[i+1,j+1]])

                        else:

                            ans.append([[i,j],[i+1,j],[i+1,j+1]])
                            ans.append([[i+1,j],[i,j+1],[i,j]])

                elif c==3:

                    if a[i][j]=='1' and a[i+1][j]=='1' and a[i+1][j+1]=='1':
                        ans.append([[i,j],[i+1,j],[i+1,j+1]])
                    elif a[i][j+1]=='1' and a[i+1][j]=='1' and a[i+1][j+1]=='1':
                        ans.append([[i,j+1],[i+1,j],[i+1,j+1]])

                    elif a[i][j+1]=='1' and a[i][j]=='1' and a[i+1][j+1]=='1':
                        ans.append([[i,j+1],[i,j],[i+1,j+1]])

                    else:

                        ans.append([[i,j],[i+1,j],[i,j+1]])


                else:


                    ans.append([[i,j+1],[i+1,j],[i+1,j+1]])

                    ans.append([[i,j],[i+1,j],[i+1,j+1]])
                    ans.append([[i,j],[i+1,j],[i,j+1]])
                    ans.append([[i,j],[i+1,j+1],[i,j+1]])


                a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]='0'




        if n%2:



            for i in range(n-2,n):

                if i==n-1:
                    continue


                for j in range(0,m):

                    if j==m-1:
                        continue

                    c=int(a[i][j])+int(a[i+1][j])+int(a[i][j+1])+int(a[i+1][j+1])


                    if c==0:
                        continue

                    elif c==1:

                        if a[i][j]=='1':    
                            ans.append([[i,j],[i+1,j],[i+1,j+1]])
                            ans.append([[i,j],[i+1,j],[i,j+1]])
                            ans.append([[i,j],[i+1,j+1],[i,j+1]])

                        elif a[i+1][j]=='1':

                            ans.append([[i+1,j],[i,j],[i,j+1]])
                            ans.append([[i+1,j],[i+1,j+1],[i,j]])
                            ans.append([[i+1,j],[i+1,j+1],[i,j+1]])

                        elif a[i][j+1]=='1':

                            ans.append([[i,j],[i+1,j],[i,j+1]])
                            ans.append([[i,j],[i,j+1],[i+1,j+1]])
                            ans.append([[i+1,j],[i,j+1],[i+1,j+1]])

                        elif a[i+1][j+1]=='1':

                            ans.append([[i,j],[i,j+1],[i+1,j+1]])
                            ans.append([[i,j],[i+1,j],[i+1,j+1]])
                            ans.append([[i+1,j],[i,j+1],[i+1,j+1]])


                    elif c==2:

                        if a[i][j]==a[i+1][j+1]:

                            if a[i][j]=='1':

                                ans.append([[i+1,j],[i+1,j+1],[i,j+1]])
                                ans.append([[i,j],[i+1,j],[i,j+1]])

                            else:

                                ans.append([[i,j+1],[i+1,j+1],[i,j]])
                                ans.append([[i+1,j],[i,j],[i+1,j+1]])

                        else:


                            if a[i+1][j]=='1' and a[i+1][j+1]=='1':    

                                ans.append([[i,j],[i+1,j],[i,j+1]])
                                ans.append([[i,j],[i+1,j+1],[i,j+1]])

                            elif a[i][j]=='1' and a[i][j+1]=='1':

                                ans.append([[i+1,j],[i+1,j+1],[i,j]])
                                ans.append([[i+1,j],[i+1,j+1],[i,j+1]])

                            elif a[i][j]=='1' and a[i+1][j]=='1':

                                ans.append([[i,j],[i,j+1],[i+1,j+1]])
                                ans.append([[i+1,j],[i,j+1],[i+1,j+1]])

                            else:

                                ans.append([[i,j],[i+1,j],[i+1,j+1]])
                                ans.append([[i+1,j],[i,j+1],[i,j]])

                    elif c==3:

                        if a[i][j]=='1' and a[i+1][j]=='1' and a[i+1][j+1]=='1':
                            ans.append([[i,j],[i+1,j],[i+1,j+1]])
                        elif a[i][j+1]=='1' and a[i+1][j]=='1' and a[i+1][j+1]=='1':
                            ans.append([[i,j+1],[i+1,j],[i+1,j+1]])

                        elif a[i][j+1]=='1' and a[i][j]=='1' and a[i+1][j+1]=='1':
                            ans.append([[i,j+1],[i,j],[i+1,j+1]])

                        else:

                            ans.append([[i,j],[i+1,j],[i,j+1]])


                    else:


                        ans.append([[i,j+1],[i+1,j],[i+1,j+1]])

                        ans.append([[i,j],[i+1,j],[i+1,j+1]])
                        ans.append([[i,j],[i+1,j],[i,j+1]])
                        ans.append([[i,j],[i+1,j+1],[i,j+1]])


                    a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]='0'

        if m%2:



            for i in range(0,n):

                if i==n-1:
                    continue


                for j in range(m-2,m):

                    if j==m-1:
                        continue

                    c=int(a[i][j])+int(a[i+1][j])+int(a[i][j+1])+int(a[i+1][j+1])


                    if c==0:
                        continue

                    elif c==1:

                        if a[i][j]=='1':    


                            ans.append([[i,j],[i+1,j],[i+1,j+1]])
                            ans.append([[i,j],[i+1,j],[i,j+1]])
                            ans.append([[i,j],[i+1,j+1],[i,j+1]])

                        elif a[i+1][j]=='1':

                            ans.append([[i+1,j],[i,j],[i,j+1]])
                            ans.append([[i+1,j],[i+1,j+1],[i,j]])
                            ans.append([[i+1,j],[i+1,j+1],[i,j+1]])

                        elif a[i][j+1]=='1':

                            ans.append([[i,j],[i+1,j],[i,j+1]])
                            ans.append([[i,j],[i,j+1],[i+1,j+1]])
                            ans.append([[i+1,j],[i,j+1],[i+1,j+1]])

                        elif a[i+1][j+1]=='1':

                            ans.append([[i,j],[i,j+1],[i+1,j+1]])
                            ans.append([[i,j],[i+1,j],[i+1,j+1]])
                            ans.append([[i+1,j],[i,j+1],[i+1,j+1]])


                    elif c==2:

                        if a[i][j]==a[i+1][j+1]:


                            if a[i][j]=='1':

                                ans.append([[i+1,j],[i+1,j+1],[i,j+1]])
                                ans.append([[i,j],[i+1,j],[i,j+1]])

                            else:

                                ans.append([[i,j+1],[i+1,j+1],[i,j]])
                                ans.append([[i+1,j],[i,j],[i+1,j+1]])

                        else:


                            if a[i+1][j]=='1' and a[i+1][j+1]=='1':    

                                ans.append([[i,j],[i+1,j],[i,j+1]])
                                ans.append([[i,j],[i+1,j+1],[i,j+1]])

                            elif a[i][j]=='1' and a[i][j+1]=='1':

                                ans.append([[i+1,j],[i+1,j+1],[i,j]])
                                ans.append([[i+1,j],[i+1,j+1],[i,j+1]])

                            elif a[i][j]=='1' and a[i+1][j]=='1':

                                ans.append([[i,j],[i,j+1],[i+1,j+1]])
                                ans.append([[i+1,j],[i,j+1],[i+1,j+1]])

                            else:

                                ans.append([[i,j],[i+1,j],[i+1,j+1]])
                                ans.append([[i+1,j],[i,j+1],[i,j]])

                    elif c==3:

                        if a[i][j]=='1' and a[i+1][j]=='1' and a[i+1][j+1]=='1':
                            ans.append([[i,j],[i+1,j],[i+1,j+1]])
                        elif a[i][j+1]=='1' and a[i+1][j]=='1' and a[i+1][j+1]=='1':
                            ans.append([[i,j+1],[i+1,j],[i+1,j+1]])

                        elif a[i][j+1]=='1' and a[i][j]=='1' and a[i+1][j+1]=='1':
                            ans.append([[i,j+1],[i,j],[i+1,j+1]])

                        else:
                            ans.append([[i,j],[i+1,j],[i,j+1]])


                    else:


                        ans.append([[i,j+1],[i+1,j],[i+1,j+1]])

                        ans.append([[i,j],[i+1,j],[i+1,j+1]])
                        ans.append([[i,j],[i+1,j],[i,j+1]])
                        ans.append([[i,j],[i+1,j+1],[i,j+1]])


                    a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]='0'


        print(len(ans))

        for i in ans:
            
            print(i[0][0]+1,i[0][1]+1,i[1][0]+1,i[1][1]+1,i[2][0]+1,i[2][1]+1)




















id1 = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id1))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id1))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


def print(*args, **kwargs):
    
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")




if __name__ == "__main__":
    
    main()
    


