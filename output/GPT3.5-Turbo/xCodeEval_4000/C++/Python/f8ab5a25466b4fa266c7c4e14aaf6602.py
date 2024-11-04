def int_to_string(n):
    return str(n)

def sum(a, b):
    k = abs(len(a) - len(b))
    if len(a) > len(b):
        b = '0' * k + b
    else:
        a = '0' * k + a
    
    vect = []
    for i in range(len(a)-1, -1, -1):
        vect.append(int(a[i]) + int(b[i]))
    
    for i in range(len(vect)):
        if vect[i] > 9:
            if i == len(vect) - 1:
                vect.append(vect[i] // 10)
                vect[i] %= 10
                break
            vect[i+1] += vect[i] // 10
            vect[i] %= 10
    
    res = ''.join(str(x) for x in vect[::-1])
    return res

def multiply(a, b):
    vect = [[] for _ in range(7000)]
    for i in range(len(a)-1, -1, -1):
        for u in range(len(a)-i-1):
            vect[len(a)-i-1].append(0)
        for j in range(len(b)-1, -1, -1):
            vect[len(a)-i-1].append(int(a[i]) * int(b[j]))
        
        for u in range(len(vect[len(a)-i-1])):
            if vect[len(a)-i-1][u] > 9:
                if u == len(vect[len(a)-i-1]) - 1:
                    vect[len(a)-i-1].append(vect[len(a)-i-1][u] // 10)
                    vect[len(a)-i-1][u] = vect[len(a)-i-1][u] % 10
                    break
                vect[len(a)-i-1][u+1] += vect[len(a)-i-1][u] // 10
                vect[len(a)-i-1][u] = vect[len(a)-i-1][u] % 10
    
    res = [''] * 7000
    for i in range(len(a)):
        for p in range(len(vect[i])-1, -1, -1):
            h = str(vect[i][p])
            res[i] += h
    
    ans = "0"
    for i in range(len(a)):
        ans = sum(ans, res[i])
    
    return ans

def rec1(n):
    ans = 0
    if n == 1:
        for i in range(10):
            if i != 0:
                ans += 1
    elif n == 2:
        for i in range(10):
            for k in range(10):
                if i != 0 and i != k:
                    ans += 1
    elif n == 3:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    if i != 0 and i != k and i != c and k != c:
                        ans += 1
    elif n == 4:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    for d in range(10):
                        if i != 0 and i != k and i != c and i != d and k != c and k != d and c != d:
                            ans += 1
    elif n == 5:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    for d in range(10):
                        for e in range(10):
                            if i != 0 and i != k and i != c and i != d and i != e and k != c and k != d and k != e and c != d and c != e and d != e:
                                ans += 1
    elif n == 6:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    for d in range(10):
                        for e in range(10):
                            for f in range(10):
                                if i != 0 and i != k and i != c and i != d and i != e and i != f and k != c and k != d and k != e and k != f and c != d and c != e and c != f and d != e and d != f and e != f:
                                    ans += 1
    elif n == 7:
        for i in range(1, 10):
            for k in range(10):
                for c in range(10):
                    for d in range(10):
                        for e in range(10):
                            for f in range(10):
                                for g in range(10):
                                    if i != k and i != c and i != d and i != e and i != f and i != g and k != c and k != d and k != e and k != f and k != g and c != d and c != e and c != f and c != g and d != e and d != f and d != g and e != f and e != g and f != g:
                                        ans += 1
    elif n == 8:
        ans = 1632960
    elif n == 9:
        ans = 3265920
    elif n == 10:
        ans = 3265920
    
    return ans

def rec(n):
    ans = 0
    if n == 1:
        for i in range(10):
            ans += 1
    elif n == 2:
        for i in range(10):
            for k in range(10):
                if i != k:
                    ans += 1
    elif n == 3:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    if i != k and i != c and k != c:
                        ans += 1
    elif n == 4:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    for d in range(10):
                        if i != k and i != c and i != d and k != c and k != d and c != d:
                            ans += 1
    elif n == 5:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    for d in range(10):
                        for e in range(10):
                            if i != k and i != c and i != d and i != e and k != c and k != d and k != e and c != d and c != e and d != e:
                                ans += 1
    elif n == 6:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    for d in range(10):
                        for e in range(10):
                            for f in range(10):
                                if i != k and i != c and i != d and i != e and i != f and k != c and k != d and k != e and k != f and c != d and c != e and c != f and d != e and d != f and e != f:
                                    ans += 1
    elif n == 7:
        for i in range(10):
            for k in range(10):
                for c in range(10):
                    for d in range(10):
                        for e in range(10):
                            for f in range(10):
                                for g in range(10):
                                    if i != k and i != c and i != d and i != e and i != f and i != g and k != c and k != d and k != e and k != f and k != g and c != d and c != e and c != f and c != g and d != e and d != f and d != g and e != f and e != g and f != g:
                                        ans += 1
    elif n == 8:
        ans = 1814400
    elif n == 9:
        ans = 3628800
    elif n == 10:
        ans = 3628800
    
    return ans

while True:
    x = input()
    if not x:
        break
    
    ans = "1"
    vis = [0] * 101
    
    CHn = 0
    F = 0
    for i in range(len(x)):
        if x[i].isalpha() and i != 0 and not vis[ord(x[i]) - ord('A')]:
            CHn += 1
            vis[ord(x[i]) - ord('A')] = 1
        elif x[i].isalpha() and i == 0 and not vis[ord(x[i]) - ord('A')]:
            F += 1
            vis[ord(x[i]) - ord('A')] = 1
    
    Zeros = 0
    if x[0] == '?':
        ans = "9"
    
    for i in range(1, len(x)):
        if x[i] == '?':
            Zeros += 1
    
    if F != 0:
        ans = multiply(int_to_string(rec1(F+CHn)), ans)
    elif CHn > 0:
        ans = multiply(int_to_string(rec(CHn)), ans)
    
    print(ans + '0' * Zeros)
