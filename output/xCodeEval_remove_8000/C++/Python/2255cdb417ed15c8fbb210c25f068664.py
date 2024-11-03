import math

pp = []

def get(l, r):
    ans = 0
    for i in range(l, r+1):
        flag = True
        for j in range(len(pp)):
            if pp[j]*pp[j] > i:
                break
            if i % pp[j] == 0:
                flag = False
                break
        if flag:
            f2 = False
            for f in range(1, int(math.sqrt(i))+1):
                s = int(math.sqrt(i-f*f))
                if s*s + f*f == i or (s+1)*(s+1) + f*f == i:
                    f2 = True
                    break
            if f2:
                ans += 1
    return ans

def main():
    global pp
    p = [True] * 20000
    for i in range(2, 20000):
        if p[i]:
            pp.append(i)
            j = i+i
            while j < 20000:
                p[j] = False
                j += i
    
    l, r = map(int, input().split())
    ans = 0
    cl = 0
    ul = 0
    while l > cl:
        ul += 1
        cl += 100000
    if cl <= r:
        ans += get(l, cl-1)
    else:
        ans += get(l, r)
    while cl+100000-1 <= r:
        ans += pr[ul]
        cl += 100000
        ul += 1
    
    ans += get(cl, r)
    
    print(ans)

if __name__ == "__main__":
    main()
