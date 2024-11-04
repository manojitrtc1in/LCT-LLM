






















































def id0(EvenCount,OddCount):
    if (OddCount%4) in [0,3]:
        return True
    return ((EvenCount%4) in [1,3]) and (OddCount%4==1)
for _ in range(int(input())):
    EvenCount,OddCount=[0,0]
    input()
    for i in list(map(int,input().split())):
        if i%2==0:
            EvenCount+=1
        else:
            OddCount+=1
    if id0(EvenCount,OddCount):
        print("Alice")
    else:
        print("Bob")
        
























