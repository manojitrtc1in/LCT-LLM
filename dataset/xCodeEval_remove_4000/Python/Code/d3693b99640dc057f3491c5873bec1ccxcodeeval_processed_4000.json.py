




























































































































def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    t=tuple(map(int,stdin.readline().split()))
    dic={}
    asum=0
    for i in t:
        for j in range(32):
            x=(1<<j)-i
            if x in dic:
                asum+=dic[x]
        if i not in dic:
            dic[i]=1
        else:
            dic[i]+=1
    stdout.write(str(asum))
if __name__=='__main__':
    main()
