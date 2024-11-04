












































def main():
    from sys import stdin,stdout
    import collections
    n=int(stdin.readline())
    home=list(n-1 for x in range(n))
    away=list(n-1 for x in range(n))
    team=[]
    homeDic=collections.Counter()
    awayDic=collections.Counter()
    for _ in range(n):
        a,b=map(int,stdin.readline().split())
        homeDic[a]+=1
        awayDic[b]+=1
        team.append((a,b))
    for i in range(n):
        d=homeDic[team[i][1]]
        home[i]+=d
        away[i]-=d
    for i in range(n):
        stdout.write(str(home[i])+' '+str(away[i])+'\n')
if __name__=='__main__':
    main()
