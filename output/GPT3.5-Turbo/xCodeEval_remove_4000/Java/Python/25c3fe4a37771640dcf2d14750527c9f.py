import math
import itertools

mod = int(math.pow(10, 9) + 7)
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
dx9 = [-1, -1, -1, 0, 0, 0, 1, 1, 1]
dy9 = [-1, 0, 1, -1, 0, 1, -1, 0, 1]

eps = 1e-10
primeNumbers = []

def main():
    str = input()
    inp = list(str)
    n = len(str)

    pos = ["00", "25", "50", "75"]
    count = 0

    if len(inp) == 1:
        if inp[0] == '0' or inp[0] == 'X' or inp[0] == '_':
            count += 1
    else:
        for cstr in pos:
            X = -1
            idx = 0
            possible = True
            for i in range(n-2, n):
                curr = inp[i]
                strcurr = cstr[idx]
                idx += 1

                if curr == '_':
                    continue
                elif curr == 'X':
                    if X == -1:
                        X = int(strcurr)
                    else:
                        if X != int(strcurr):
                            possible = False
                            break
                else:
                    if curr != strcurr:
                        possible = False
                        break

            if not possible:
                continue

            if len(str) == 2:
                if cstr[0] == '0':
                    continue
                count += 1
                continue

            ninp = inp.copy()

            cntX = 0
            for ch in inp:
                if ch == 'X':
                    cntX += 1

            if X != -1 or cntX == 0:
                if X != -1:
                    for k in range(len(str)):
                        ninp[k] = str(X) if inp[k] == 'X' else inp[k]

                if ninp[0] == '0':
                    continue
                counter = 1
                for k in range(len(str) - 2):
                    if ninp[k] == '_':
                        if k == 0:
                            counter *= 9
                        else:
                            counter *= 10

                count += counter
            else:
                if ninp[0] == '0':
                    continue

                counter = 1
                for k in range(len(str) - 2):
                    if ninp[k] == '_':
                        if k == 0:
                            counter *= 9
                        else:
                            counter *= 10

                if ninp[0] == 'X':
                    counter *= 9
                else:
                    counter *= 10

                count += counter

    print(count)

if __name__ == "__main__":
    main()
