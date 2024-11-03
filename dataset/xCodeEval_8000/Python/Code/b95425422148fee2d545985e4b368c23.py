z='"""6"k"="3,"iG"17G"6m?"C@f"2<6z"ki1,"1Y[{s"dnF)N"1j.&{o"aZ>k}1"173exa+"atUi,},"1canZ35z"b*-!Ps6l"1z<F!WJlC"fQrp~1])H"1}8l0AiPTl"nXgm


q = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!

def zz(x):
    a = 0
    for i in x:
        a = a*len(q)+q.find(i)
    return a

k=[zz(x) for x in z.split('"')]

n, m = map(int, input().split())

print(k[n]%m)