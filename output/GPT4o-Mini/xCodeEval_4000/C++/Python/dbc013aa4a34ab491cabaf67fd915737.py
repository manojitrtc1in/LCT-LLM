import sys
from collections import defaultdict

def find_substr_match(str, pat):
    out = []
    loc = defaultdict(list)

    for i in range(len(pat) - 1, -1, -1):
        loc[pat[i]].append(i)

    cache = [{} for _ in range(len(pat))]

    i = 0
    for j in range(len(str)):
        if i == len(pat) or pat[i] != str[j]:
            if i == len(pat):
                out.append(j - 1)

            first = _roll_back(i, str[j], loc)
            last = i - 1
            i = _recycle(first, last, pat, loc, cache)

    if i == len(pat):
        out.append(len(str) - 1)

    return out

def _roll_back(last, chr, loc):
    if chr not in loc:
        return -1

    a = loc[chr]
    iter = next((x for x in reversed(a) if x <= last), None)

    return iter if iter is not None else -1

def _recycle(first, last, pat, loc, cache):
    if len(pat) < first:
        return -1

    ref = cache[first]
    if last in ref:
        return ref[last]

    for i in range(first - 1, -1, -1):
        if pat[i] != pat[last]:
            return ref[last] = _recycle(_roll_back(first, pat[first], loc), last, pat, loc, cache)

    return ref[last] = first

def b346():
    str = input().split()
    vir = input().strip()

    val = revmatch(0, 0, 0, str, vir, [{} for _ in range(len(str[0]))])
    return val if val != "" else "0"

def revmatch(i, j, offset, str, vir, cache):
    if i == len(str[0]) or j == len(str[1]) or offset == len(vir):
        return ""

    pr = (j, offset)

    if pr in cache[i]:
        return cache[i][pr]

    if str[0][i] != str[1][j]:
        a = revmatch(i + 1, j, offset, str, vir, cache)
        b = revmatch(i, j + 1, offset, str, vir, cache)
        return cache[i][pr] = a if len(a) < len(b) else b
    else:
        b = revmatch(i + 1, j, offset, str, vir, cache)
        c = revmatch(i, j + 1, offset, str, vir, cache)
        d = b if len(b) < len(c) else c

        chr = str[0][i]
        a = chr + revmatch(i + 1, j + 1, offset + 1, str, vir, cache) if chr == vir[offset] else chr + revmatch(i + 1, j + 1, 1 if chr == vir[0] else 0, str, vir, cache)

        fail = len(a) < len(d) or a.startswith(vir[offset:]) or a.startswith(vir)

        return cache[i][pr] = d if fail else a

if __name__ == "__main__":
    print(b346())
