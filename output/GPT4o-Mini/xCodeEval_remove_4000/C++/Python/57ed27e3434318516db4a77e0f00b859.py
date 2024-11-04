from collections import defaultdict

def main():
    str_input = input().strip()
    res = 1
    use = [False] * 1200
    zero = 0
    all = 10
    n = len(str_input)

    for i in range(n):
        if i == 0:
            if 'A' <= str_input[i] <= 'J':
                res *= 9
                all -= 1
                use[ord(str_input[i])] = True
            elif str_input[i] == '?':
                res *= 9
        else:
            if 'A' <= str_input[i] <= 'J':
                if use[ord(str_input[i])]:
                    continue
                use[ord(str_input[i])] = True
                res *= all
                all -= 1
            elif str_input[i] == '?':
                zero += 1

    print(res, end='')
    print('0' * zero)

main()
