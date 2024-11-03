import sys
from typing import List, Tuple, Dict, Any

def main() -> None:
    t = 1
    epsilon = 0.00000001
    isPrime = []
    smallestFactorOf = []

    for _ in range(t):
        sOG = list(input().strip())
        n = len(sOG)

        if n == 1:
            if sOG[0] == '0' or sOG[0] == '_' or sOG[0] == 'X':
                print(1)
            else:
                print(0)
            continue

        answer = 0

        s = sOG.copy()

        shit = (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '0')
        shit |= (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '0')

        if not shit:
            if s[n - 1] == 'X' or s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '0'
            s[n - 1] = '0'
            s[n - 2] = '0'

            answer += check("00".toCharArray(), s)

            for num in range(int(1e6)):
                tgt = list(str(num) + "00")
                answer += check(tgt, s)

        s = sOG.copy()

        shit = (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '5')
        shit |= s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '2'
        shit |= (s[n - 1] == 'X' and s[n - 2] == 'X')

        if not shit:
            if s[n - 1] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '5'
            elif s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '2'

            s[n - 1] = '5'
            s[n - 2] = '2'

            answer += check("25".toCharArray(), s)

            for num in range(int(1e6)):
                tgt = list(str(num) + "25")
                answer += check(tgt, s)

        s = sOG.copy()

        shit = (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '0')
        shit |= s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '5'
        shit |= (s[n - 1] == 'X' and s[n - 2] == 'X')

        if not shit:
            if s[n - 1] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '0'
            elif s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '5'

            s[n - 1] = '0'
            s[n - 2] = '5'

            answer += check("50".toCharArray(), s)

            for num in range(int(1e6)):
                tgt = list(str(num) + "50")
                answer += check(tgt, s)

        s = sOG.copy()

        shit = (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '5')
        shit |= s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '7'
        shit |= (s[n - 1] == 'X' and s[n - 2] == 'X')

        if not shit:
            if s[n - 1] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '5'
            elif s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '7'

            s[n - 1] = '5'
            s[n - 2] = '7'

            answer += check("75".toCharArray(), s)

            for num in range(int(1e6)):
                tgt = list(str(num) + "75")
                answer += check(tgt, s)

        print(answer)

def check(tgt: List[str], src: List[str]) -> int:
    n = len(tgt)
    if len(src) != n:
        return 0

    xDig = 0
    for i in range(n):
        if src[i] == 'X':
            if xDig == 0:
                xDig = tgt[i]
            else:
                if tgt[i] != xDig:
                    return 0

    if tgt[0] == '0':
        return 0

    for i in range(n):
        if src[i] != '_' and src[i] != 'X' and tgt[i] != src[i]:
            return 0

    return 1

if __name__ == "__main__":
    main()
