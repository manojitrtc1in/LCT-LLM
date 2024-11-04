import sys

def main():
    n = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))
    
    # Modify the specified element
    a[int(sys.stdin.readline().strip()) - 1] *= -1
    
    s = []
    top = 0
    
    for i in range(n - 1, -1, -1):
        if a[i] > 0:
            if top > 0 and s[top - 1] == a[i]:
                top -= 1
            else:
                s.append(a[i])
                top += 1
                a[i] = -a[i]
        else:
            s.append(-a[i])
            top += 1
    
    if top > 0:
        print("NO")
    else:
        print("YES")
        print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()
