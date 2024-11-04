def touch_pos(r, c, d, len, dist, q):
    pos = (r, min(c, len[r]))
    if d < dist[r][pos[1]]:
        dist[r][pos[1]] = d
        q.append(pos)
    return pos

def c253():
    nrow = int(input())
    len = list(map(int, input().split()))
    first = tuple(map(int, input().split()))
    last = tuple(map(int, input().split()))

    first = (first[0] - 1, min(first[1] - 1, len[first[0] - 1]))
    last = (last[0] - 1, min(last[1] - 1, len[last[0] - 1]))

    if first == last:
        print(0)
        return

    INF = float('inf')
    dist = [[INF] * (len[j] + 1) for j in range(nrow)]
    q = [first]
    dist[first[0]][first[1]] = 0

    while q:
        r, c = q.pop(0)
        d = dist[r][c] + 1

        if 0 < r and last == touch_pos(r - 1, c, d, len, dist, q):
            break

        if r + 1 < nrow and last == touch_pos(r + 1, c, d, len, dist, q):
            break

        if 0 < c and last == touch_pos(r, c - 1, d, len, dist, q):
            break

        if c < len[r] and last == touch_pos(r, c + 1, d, len, dist, q):
            break

    print(dist[last[0]][last[1]])

c253()
