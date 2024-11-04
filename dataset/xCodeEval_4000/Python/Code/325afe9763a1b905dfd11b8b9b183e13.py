

import copy


def coffee_problem():
    coffee_num_list = []
    cup_num, page_num = input().split(' ')
    coffee_num_per_cup = input().split(' ')
    cup_num = eval(cup_num)
    page_num = eval(page_num)
    for cup_idx in range(cup_num):
        coffee_num_list.append(eval(coffee_num_per_cup[cup_idx]))
    coffee_num_list.sort(reverse=True)
    if sum(coffee_num_list) < page_num:
        print(-1)
        return
    for i in range(1, cup_num + 1):
        done_page_num = 0
        for j in range(cup_num):
            done_page_num += max(coffee_num_list[j] - j // i, 0)
            if done_page_num >= page_num:
                print(i)
                return


def water_problem():
    query_num = eval(input())
    output_buffer = []
    for i in range(query_num):
        water_liter, price1liter, price2liter = input().split(' ')
        water_liter, price1liter, price2liter = eval(water_liter), eval(price1liter), eval(price2liter)

        if price2liter / 2 >= price1liter:
            num_of_1liter, num_of_2liter = water_liter, 0
        else:
            num_of_2liter = water_liter // 2
            num_of_1liter = water_liter % 2
        whole_price = num_of_1liter * price1liter + num_of_2liter * price2liter
        output_buffer.append(str(whole_price))
    for output in output_buffer:
        print(output)
    return


def grape_problem():
    andrew, dmitry, michal = input().split(' ')
    andrew, dmitry, michal = eval(andrew), eval(dmitry), eval(michal)
    green, purple, black = input().split(' ')
    green, purple, black = eval(green), eval(purple), eval(black)
    if green < andrew:
        print('NO')
        return
    green = green - andrew
    if green + purple < dmitry:
        print('NO')
        return
    green_and_purple = green + purple - dmitry
    if green_and_purple + black < michal:
        print('NO')
        return
    print('YES')
    return


def one_point_problem(l1, r1, l2, r2):
    for answer1 in range(l1, r1 + 1):
        for answer2 in range(l2, r2 + 1):
            if answer1 != answer2:
                print(str(answer1) + ' ' + str(answer2))
                return


def point_problem():
    query_num = eval(input())
    query_list = []
    for _ in range(query_num):
        l1, r1, l2, r2 = input().split(' ')
        l1, r1, l2, r2 = eval(l1), eval(r1), eval(l2), eval(r2)
        query_list.append([l1, r1, l2, r2])
    for query in query_list:
        one_point_problem(query[0], query[1], query[2], query[3])
    return


def get_result(city_num, capacity):
    sum = 0
    for i in range(2, city_num - capacity + 1):
        sum += i
    return sum


def trip_problem():
    city_num, capacity = input().split(' ')
    city_num, capacity = eval(city_num), eval(capacity)
    if city_num <= capacity + 1:
        min_cost = city_num - 1
    else:
        min_cost = capacity + get_result(city_num, capacity)
    print(min_cost)
    return


def split_problem():
    num = eval(input())
    print(num)
    for i in range(num):
        print('1 ', end='')
    print()
    return


def positive_problem():
    pos_num, neg_num = 0, 0
    n = eval(input())
    a = input().split(' ')
    for i in range(len(a)):
        a[i] = eval(a[i])
    for i in range(len(a)):
        if a[i] > 0:
            pos_num += 1
        elif a[i] < 0:
            neg_num += 1
    if n % 2 == 0:
        p = n // 2
    else:
        p = n // 2 + 1
    if pos_num >= p or neg_num >= p:
        if pos_num >= p:
            print('1')
        elif neg_num >= p and pos_num < p:
            print('-1')
    else:
        print('0')
    return


def sasha_problem():
    max_num = 110
    count = []
    n = eval(input())
    sum = 0
    answer = 0
    input_num = input().split(' ')
    for i in range(max_num):
        count.append(0)
    for i in range(len(input_num)):
        input_num[i] = eval(input_num[i])
        sum += input_num[i]
        count[input_num[i]] += 1
    for i in range(1, 101):
        for j in range(i+1, 101):
            for k in range(2, 101):
                if count[i] and count[j] and j % k == 0:
                    answer = max(answer, int((j - j / k) - (i * k - i)))
    answer = sum - answer
    print(answer)
    return


def football_problem():
    n = eval(input())
    answer = 1
    a, b = 0, 0
    while n > 0:
        n -= 1
        x, y = input().split(' ')
        x, y = eval(x), eval(y)
        if x == a and y == b:
            continue
        answer += max(0, min(x, y) - max(a, b) + 1)
        if a == b:
            answer -= 1
        a, b = x, y
    print(answer)
    return


def candy_problem():
    n = eval(input())
    input_list = input().split(' ')
    input_list.extend(['0', '0', '0'])
    for i, _ in enumerate(input_list):
        input_list[i] = eval(input_list[i])
    l2r, r2l = copy.deepcopy(input_list), copy.deepcopy(input_list)
    for i in range(n):
        if i >= 2:
            l2r[i] = input_list[i] + l2r[i-2]
        else:
            l2r[i] = input_list[i]
    for i in range(n-1, -1, -1):
        r2l[i] = input_list[i] + r2l[i+2]
    answer = 0
    for i in range(n):
        a, b = 0, 0
        if i >= 2:
            a = l2r[i-2]
            b = l2r[i-1]
        elif i == 1:
            b = l2r[0]
        a += r2l[i+1]
        b += r2l[i+2]
        if a == b:
            answer += 1
    print(answer)
    return


def emote_problem():
    xmax, imax, flag, sum = 0, 0, 0, 0
    n, m, k = input().split(' ')
    n, m, k = int(n), int(m), int(k)
    input_list = input().split(' ')
    for i, _ in enumerate(input_list):
        input_list[i] = int(input_list[i])
    for i, _ in enumerate(input_list):
        if input_list[i] > xmax:
            imax = xmax
            xmax = input_list[i]
        elif input_list[i] > imax:
            imax = input_list[i]
    if xmax == imax:
        sum = m*xmax
    else:
        sum = int(m//(k+1)*(k*xmax+imax) + m % (k+1)*xmax)
    print(sum)
    return


def string_problem():
    string = input()
    same_num = 0
    s = []
    for i in range(len(string)):
        if len(s) != 0:
            if string[i] == s[-1]:
                same_num += 1
                s.pop(-1)
            else:
                s.append(string[i])
        else:
            s.append(string[i])
    if same_num % 2 == 0:
        print('No')
    else:
        print('Yes')
    return


def tape_problem():
    n, m, k = input().split(' ')
    n, m, k = int(n), int(m), int(k)
    b = input().split(' ')
    b_t = [0]
    b_t.extend(b)
    b = b_t
    for i, _ in enumerate(b):
        b[i] = int(b[i])
    c = copy.deepcopy(b)
    for i in range(1, n):
        c[i] = b[i+1] - b[i] - 1
    c[-1] = 0
    c[1:] = sorted(c[1:], reverse=True)
    answer = b[n] - b[1] + 1
    for i in range(1, k):
        answer -= c[i]
    print(answer)
    return


def cake_problem():
    n = int(input())
    a = []
    for i in range(n+1):
        a.append([-1, -1])
    l = input().split(' ')
    for i in range(len(l)):
        l[i] = int(l[i])
        b = l[i]
        if a[b-1][0] == -1:
            a[b-1][0] = i
        else:
            a[b-1][1] = i
    len1, len2 = a[0][0], a[0][1]
    for i in range(1, n):
        len1 += abs(a[i][0] - a[i-1][0])
        len2 += abs(a[i][1] - a[i-1][1])
    print(len1 + len2)
    return


def superhero_problem():
    n, k, m = input().split(' ')
    tmp = input().split(' ')
    n, k, m = int(n), int(k), int(m)
    sum = 0
    for i, _ in enumerate(tmp):
        tmp[i] = int(tmp[i])
        sum += tmp[i]
    tmp = sorted(tmp)
    a = [0]
    a.extend(tmp)
    answer = (sum + min(n*k, m)) / n
    for i in range(1, n):
        op = m - i
        sum -= a[i]
        if op < 0:
            break
        answer = max(answer, (sum + min((n-i)*k, op))/(n-i))
    print(answer)
    return


def discounts_problem():
    n = int(input())
    a = input().split(' ')
    for i, _ in enumerate(a):
        a[i] = int(a[i])
    a = sorted(a)
    m = int(input())
    sum = 0
    for i in range(n):
        sum += a[i]
    b = input().split(' ')
    for i, _ in enumerate(b):
        b[i] = int(b[i])
    for i in range(m):
        print(sum - a[n-b[i]])
    return


def computer_games_problem():
    n, k = input().split(' ')
    n, k = int(n), int(k)
    answer = min(k-1, n-k) + 3 * n
    print(answer)
    return


def womens_day_problem():
    n, k = input().split(' ')
    n, k = int(n), int(k)
    b = input().split(' ')
    for i, _ in enumerate(b):
        b[i] = int(b[i])
    a = []
    for i in range(k+1):
        a.append(0)
    for i in range(n):
        a[b[i] % k] += 1
    cnt = a[0] // 2
    if k % 2 == 0:
        cnt += a[k//2] // 2
    for i in range((k+1)//2):
        tmp = min(a[i], a[k-i])
        cnt += tmp
        a[i] -= tmp
        a[k-i] -= tmp
    print(2 * cnt)
    return


def letters_rearranging_problem():
    t = int(input())
    while t != 0:
        t -= 1
        s = input()
        new_s_list = sorted(s)
        new_s = ''
        for i, _ in enumerate(new_s_list):
            new_s += new_s_list[i]
        if new_s[0] == new_s[-1]:
            print('-1')
        else:
            print(new_s)
    return


def teams_forming_problem():
    n = int(input())
    a = input().split(' ')
    for i, _ in enumerate(a):
        a[i] = int(a[i])
    a = sorted(a)
    answer = 0
    for i in range(0, n, 2):
        answer += a[i+1] - a[i]
    print(answer)
    return


def check(n, k, v):
    for i in range(1,n+1):
        if k[i] <= 0 or k[i] > n:
            return 0
        v[k[i]] += 1
    for i in range(1,n+1):
        if not v[i]:
            return 0
    return 1


def polycarp_restores_permutation_problem():
    maxn = int(6e5+10)
    n = int(input())
    input_list = input().split(' ')
    for i, _ in enumerate(input_list):
        input_list[i] = int(input_list[i])
    a = [0 for i in range(maxn)]
    b = [0 for i in range(maxn)]
    k = [0 for i in range(maxn)]
    v = [0 for i in range(maxn)]
    for i in range(1,n):
        b[i] = input_list[i-1]
    sum = n*(n+1)/2
    for i in range(1,n):
        a[i] = a[i-1] + b[i]
        sum -= a[i]
    k[1] = int(sum / n)
    for i in range(2,n+1):
        k[i] = k[1] + a[i-1]
    s = 0
    for i in range(1,n+1):
        s += k[i]
    if not check(n, k, v):
        print(-1)
    else:
        for i in range(1,n+1):
            print(str(k[i]) + ' ', end='')
    return


def problem_1141b():
    n = int(input())
    input_list = input().split(' ')
    for i, _ in enumerate(input_list):
        input_list[i] = int(input_list[i])
    for _ in range(n):
        input_list.append(0)
    for i in range(n,2*n-1):
        input_list[i] = input_list[i-n]
    count = 0
    answer = 0
    for i in range(2*n):
        if input_list[i] == 1:
            count += 1
            answer = max(answer, count)
        else:
            count = 0
    print(answer)
    return


def problem_1136c():
    gi = lambda: list(map(int, input().strip().split()))
    n, m = gi()
    a_list = [gi() for _ in range(n)]
    b_list = [gi() for _ in range(n)]
    for k in range(m):
        a = sorted([a_list[j][k - j] for j in range(min(n, k + 1))])
        b = sorted([b_list[j][k - j] for j in range(min(n, k + 1))])
        if a != b:
            print("NO")
            return
    for k in range(m):
        a = sorted([a_list[-j - 1][j - 1 - k] for j in range(min(n, k + 1))])
        b = sorted([b_list[-j - 1][-k + j - 1] for j in range(min(n, k + 1))])
        if a != b:
            print("NO")
            return
    if n <= m:
        print("YES")
        return
    for k in range(n):
        a = sorted([a_list[k - j][j] for j in range(min(m, k + 1))])
        b = sorted([b_list[k - j][j] for j in range(min(m, k + 1))])
        if a != b:
            print("NO")
            return
    for k in range(n):
        a = sorted([a_list[-k - 1 + j][-j - 1] for j in range(min(m, k + 1))])
        b = sorted([b_list[-k - 1 + j][-j - 1] for j in range(min(m, k + 1))])
        if a != b:
            print("NO")
            return
    print("YES")
    return


def get_len(t, z):
    ori_len = len(t)
    length = 0
    i = 1
    while i < ori_len:
        if t[i] == t[length]:
            length += 1
            z[i] = length
            i += 1
        else:
            if length != 0:
                length = z[length-1]
            else:
                z[i] = 0
                i += 1
    return z[ori_len-1]


def problem_1137b():
    maxn = int(1e6)
    s = input()
    t = input()
    zs, os, zt, ot = 0, 0, 0, 0
    for i in range(len(s)):
        if s[i] == '0':
            zs += 1
        else:
            os += 1
    for i in range(len(t)):
        if t[i] == '0':
            zt += 1
        else:
            ot += 1
    if zt > zs or ot > os:
        print(s)
        return
    z = [0 for _ in range(maxn)]
    len_t = get_len(t, z)
    answer = t
    add = t[len_t:len(t)]
    nz, no = 0, 0
    currz, curro = zt, ot
    for i in range(len(add)):
        if add[i] == '0':
            nz += 1
        else:
            no += 1
    while currz + nz <= zs and curro + no <= os:
        answer += add
        currz += nz
        curro += no
    for i in range(zs-currz):
        answer += '0'
    for i in range(os-curro):
        answer += '1'
    print(answer)
    return


def problem_1138b():
    n = int(input())
    c = input()
    a = input()
    n0, c0, a0, b0 = 0, 0, 0, 0
    for i in range(n):
        if c[i] == '0' and a[i] == '0':
            n0 += 1
        elif c[i] == '0' and a[i] == '1':
            a0 += 1
        elif c[i] == '1' and a[i] == '0':
            c0 += 1
        else:
            b0 += 1
    half_n = int(n/2)
    for i in range(half_n + 1):
        if b0 > 2*i:
            continue
        if a0 < i and c0 < i:
            if i - a0 + i - c0 == b0:
                em = half_n - i
                d1 = i - c0
                cc = i
                if em > n0:
                    continue
                for i in range(n):
                    if c[i] == '0' and a[i] == '0' and em:
                        em -= 1
                        print(str(i+1) + ' ', end='')
                    elif c[i] == '0' and a[i] == '1':
                        continue
                    elif c[i] == '1' and a[i] == '0' and cc:
                        cc -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '1' and d1:
                        d1 -= 1
                        print(str(i + 1) + ' ', end='')
                return
        elif c0 < i <= a0:
            d1 = b0 - i + c0
            d2 = a0 - i
            if i >= d1 >= 0:
                d5 = i - c0
                d3 = d2 + d1
                d4 = half_n - i - d3
                cc = i
                if d4 > n0 or d4 < 0:
                    continue
                for i in range(n):
                    if c[i] == '0' and a[i] == '0' and d4:
                        d4 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '0' and a[i] == '1' and d3:
                        d3 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '0' and cc:
                        cc -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '1' and d5:
                        d5 -= 1
                        print(str(i + 1) + ' ', end='')
                return
        elif a0 < i <= c0:
            d1 = b0 - i + a0
            if 0 <= d1 <= i:
                cc = i - d1
                d2 = half_n - cc - d1
                if d2 > n0 or d2 < 0:
                    continue
                for i in range(n):
                    if c[i] == '0' and a[i] == '0' and d2:
                        d2 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '0' and a[i] == '1':
                        continue
                    elif c[i] == '1' and a[i] == '0' and cc:
                        cc -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '1' and d1:
                        d1 -= 1
                        print(str(i + 1) + ' ', end='')
                return
        else:
            d1 = int(b0 / 2)
            d2 = i - d1
            d3 = b0 - d1
            d4 = i - d3
            d5 = c0 - d2
            d6 = a0 - d4
            if d6 + d1 + d2 <= half_n and d3 + d4 + d5 <= half_n:
                d7 = half_n - d6 - d1 - d2
                if d7 > n0 or d2 < 0:
                    continue
                for i in range(n):
                    if c[i] == '0' and a[i] == '0' and d7:
                        d7 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '0' and a[i] == '1' and d6:
                        d6 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '0' and d2:
                        d2 -= 1
                        print(str(i + 1) + ' ', end='')
                    elif c[i] == '1' and a[i] == '1' and d1:
                        d1 -= 1
                        print(str(i + 1) + ' ', end='')
                return
    print(-1)
    return


def problem_1139b():
    n = int(input())
    a = input().split(' ')
    for i, _ in enumerate(a):
        a[i] = int(a[i])
    mi = a[n-1] - 1
    for i in range(n-2, -1, -1):
        if a[i] < mi:
            mi = a[i] - 1
        else:
            a[i] = mi
            mi = max(mi-1, 0)
    answer = 0
    for i in range(n):
        answer += a[i]
    print(answer)
    return


def problem_1132c():
    maxn = 5001
    lst = [0 for _ in range(maxn)]
    dp = [0 for _ in range(maxn)]
    n, m = input().split()
    n, m = int(n), int(m)
    for i in range(1, n+1):
        lst[i] = i + 1
    for i in range(1, m+1):
        l, r = input().split(' ')
        l, r = int(l), int(r)
        for j in range(l, r+1):
            if lst[j] > l:
                lst[j] = l
    for k in range(1, m-1):
        for i in range(n, 0, -1):
            tmp = dp[lst[i] - 1] + i - lst[i] + 1
            if tmp > dp[i]:
                dp[i] = tmp
        for i in range(1, n+1):
            if dp[i-1] > dp[i]:
                dp[i] = dp[i-1]
    print(dp[n])
    return


def problem_1133c():
    nmax = 0
    n = int(input())
    a = input().split(' ')
    for i, _ in enumerate(a):
        a[i] = int(a[i])
    a.sort()
    i, j = 0, 1
    while i < n-1 and j < n:
        if a[j] - a[j-1] > 5:
            if j-1-i > nmax:
                nmax = j-1-i
            i = j
            j += 1
        elif a[j] - a[i] > 5:
            if j-1-i > nmax:
                nmax = j-1-i
            i += 1
            if i == j:
                j += 1
        else:
            j += 1
    if j - 1 - i > nmax:
        nmax = j - 1 - i
    print(nmax + 1)
    return


def problem_1197c():
    n, k = input().split(' ')
    a = input().split(' ')
    n, k = int(n), int(k)
    da = []
    for i, _ in enumerate(a):
        a[i] = int(_)
        if i != 0:
            da.append(a[i] - a[i-1])
    da.sort(reverse=True)
    max_da = 0
    for i in range(k-1):
        max_da += da[i]
    result = a[-1] - a[0] - max_da
    print(result)
    return None


if __name__ == '__main__':
    problem_1197c()
