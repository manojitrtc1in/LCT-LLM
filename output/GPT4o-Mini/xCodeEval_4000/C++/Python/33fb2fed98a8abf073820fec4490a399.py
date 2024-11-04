def int_to_string(n):
    return str(n)

def sum(a, b):
    if len(a) > len(b):
        b = b.zfill(len(a))
    else:
        a = a.zfill(len(b))
    
    vect = []
    for i in range(len(a) - 1, -1, -1):
        vect.append(int(a[i]) + int(b[i]))
    
    for i in range(len(vect)):
        if vect[i] > 9:
            if i == len(vect) - 1:
                vect.append(vect[i] // 10)
                vect[i] %= 10
                break
            vect[i + 1] += (vect[i] // 10)
            vect[i] %= 10
    
    res = ''.join(str(x) for x in vect[::-1])
    return res

def multiply(a, b):
    vect = [[] for _ in range(len(a))]
    
    for i in range(len(a) - 1, -1, -1):
        vect[len(a) - i - 1] = [0] * (len(a) - i - 1)
        for j in range(len(b) - 1, -1, -1):
            vect[len(a) - i - 1].append((int(a[i]) * int(b[j])))
        
        for u in range(len(vect[len(a) - i - 1])):
            if vect[len(a) - i - 1][u] > 9:
                if u == len(vect[len(a) - i - 1]) - 1:
                    vect[len(a) - i - 1].append(vect[len(a) - i - 1][u] // 10)
                    vect[len(a) - i - 1][u] %= 10
                    break
                vect[len(a) - i - 1][u + 1] += (vect[len(a) - i - 1][u] // 10)
                vect[len(a) - i - 1][u] %= 10
    
    res = [''] * len(a)
    for i in range(len(a)):
        for p in range(len(vect[i]) - 1, -1, -1):
            res[i] += str(vect[i][p])
    
    ans = "0"
    for i in range(len(a)):
        ans = sum(ans, res[i])
    
    return ans

def rec1(n):
    ans = 0
    if n == 1:
        ans = 9
    elif n == 2:
        ans = 9 * 9
    elif n == 3:
        ans = 9 * 9 * 8
    elif n == 4:
        ans = 9 * 9 * 8 * 7
    elif n == 5:
        ans = 9 * 9 * 8 * 7 * 6
    elif n == 6:
        ans = 9 * 9 * 8 * 7 * 6 * 5
    elif n == 7:
        ans = 9 * 9 * 8 * 7 * 6 * 5 * 4
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
        ans = 10
    elif n == 2:
        ans = 10 * 9
    elif n == 3:
        ans = 10 * 9 * 8
    elif n == 4:
        ans = 10 * 9 * 8 * 7
    elif n == 5:
        ans = 10 * 9 * 8 * 7 * 6
    elif n == 6:
        ans = 10 * 9 * 8 * 7 * 6 * 5
    elif n == 7:
        ans = 10 * 9 * 8 * 7 * 6 * 5 * 4
    elif n == 8:
        ans = 1814400
    elif n == 9:
        ans = 3628800
    elif n == 10:
        ans = 3628800
    return ans

def main():
    while True:
        try:
            x = input()
        except EOFError:
            break
        
        ans = "1"
        vis = [0] * 101
        CHn = 0
        F = 0
        
        for i in range(len(x)):
            if 'A' <= x[i] <= 'J' and i != 0 and not vis[ord(x[i]) - ord('A')]:
                CHn += 1
                vis[ord(x[i]) - ord('A')] = 1
            elif 'A' <= x[i] <= 'J' and i == 0 and not vis[ord(x[i]) - ord('A')]:
                F += 1
                vis[ord(x[i]) - ord('A')] = 1
        
        Zeros = x.count('?') - (1 if x[0] == '?' else 0)
        
        if x[0] == '?':
            ans = "9"
        
        if F != 0:
            ans = multiply(int_to_string(rec1(F + CHn)), ans)
        elif CHn > 0:
            ans = multiply(int_to_string(rec(CHn)), ans)
        
        print(ans + '0' * Zeros)

if __name__ == "__main__":
    main()
