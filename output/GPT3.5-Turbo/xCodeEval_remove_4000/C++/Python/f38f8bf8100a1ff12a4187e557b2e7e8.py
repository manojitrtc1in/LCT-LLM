def main():
    n = int(input())
    V = []
    for i in range(n):
        V.append(int(input()))
    V.sort()
    print(V[n // 2])

if __name__ == "__main__":
    main()
