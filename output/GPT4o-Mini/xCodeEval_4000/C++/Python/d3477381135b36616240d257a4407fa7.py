def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    b = int(data[0])
    d = int(data[1])
    a = data[2]
    c = data[3]
    
    an = len(a)
    cn = len(c)
    t = [0] * cn

    for i in range(cn):
        k = t[i]
        for j in range(an):
            if a[j] == c[(i + k) % cn]:
                k += 1
        t[i] = k

    s = 0
    for _ in range(b):
        s += t[s % cn]
    s //= (cn * d)
    
    print(s)

if __name__ == "__main__":
    main()
