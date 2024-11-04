def read_int():
    return int(input().strip())

def read_string():
    return input().strip()

def main():
    a = read_string()
    c = read_string()
    b, d = map(int, input().strip().split())
    
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
