package main

import (
    "fmt"
    "math"
    "sort"
)

type Pair struct {
    first, second int
}

func touchPos(r, c, d int, len []int, dist [][]int, q *[]Pair) Pair {
    pos := Pair{r, min(c, len[r])}
    if d < dist[r][pos.second] {
        dist[r][pos.second] = d
        *q = append(*q, pos)
    }
    return pos
}

func c253() {
    var nrow int
    fmt.Scan(&nrow)

    len := make([]int, nrow)
    for i := 0; i < nrow; i++ {
        fmt.Scan(&len[i])
    }

    var first, last Pair
    fmt.Scan(&first.first, &first.second)
    fmt.Scan(&last.first, &last.second)

    first = Pair{first.first - 1, first.second - 1}
    last = Pair{last.first - 1, last.second - 1}

    if first == last {
        fmt.Println(0)
        return
    }

    const INF = int(^uint(0) >> 1)
    dist := make([][]int, nrow)
    for j := 0; j < nrow; j++ {
        dist[j] = make([]int, len[j]+1)
        for k := range dist[j] {
            dist[j][k] = INF
        }
    }

    q := []Pair{first}
    dist[first.first][first.second] = 0

    touch := func(r, c, d int) Pair {
        return touchPos(r, c, d, len, dist, &q)
    }

    for len(q) > 0 {
        r, c := q[0].first, q[0].second
        d := dist[r][c] + 1
        q = q[1:]

        if r > 0 && last == touch(r-1, c, d) {
            break
        }
        if r+1 < nrow && last == touch(r+1, c, d) {
            break
        }
        if c > 0 && last == touch(r, c-1, d) {
            break
        }
        if c < len[r] && last == touch(r, c+1, d) {
            break
        }
    }
    fmt.Println(dist[last.first][last.second])
}

func d34() {
    var n, fst, lst int
    fmt.Scan(&n, &fst, &lst)
    fst--
    lst--

    a := make([]int, n-1)
    for i := 0; i < n-1; i++ {
        fmt.Scan(&a[i])
    }

    for i := range a {
        a[i]--
    }

    adj := make([][]int, n)
    for j := 0; j < n-1; j++ {
        var u, v int
        if j < fst {
            u = j
        } else {
            u = j + 1
        }
        v = a[j]
        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)
    }

    const NIL = n + 1
    tag := make([]int, n)
    for i := range tag {
        tag[i] = NIL
    }
    q := []int{lst}
    tag[lst] = lst

    for len(q) > 0 {
        u := q[0]
        q = q[1:]

        for _, v := range adj[u] {
            if tag[v] == NIL {
                tag[v] = u
                q = append(q, v)
            }
        }
    }

    tag = append(tag[:lst], tag[lst+1:]...)
    for i := range tag {
        tag[i]++
    }
    fmt.Println(tag)
}

func b140() {
    var n int
    fmt.Scan(&n)

    l := make([][]int, n)
    for i := range l {
        l[i] = make([]int, n)
        for j := range l[i] {
            fmt.Scan(&l[i][j])
        }
    }

    xs := make([]int, n)
    for i := range xs {
        fmt.Scan(&xs[i])
    }

    a := make([]int, n)
    b := make([]int, n)
    a[0] = xs[0]
    b[0] = math.MaxInt

    for j := 1; j < n; j++ {
        if xs[j] < a[j-1] {
            b[j] = a[j-1]
            a[j] = xs[j]
        } else {
            a[j] = a[j-1]
            b[j] = min(b[j-1], xs[j])
        }
    }

    pos := make([]int, n+1)
    for j := 0; j < n; j++ {
        pos[xs[j]] = j
    }

    soln := []int{}
    for j := 0; j < n; j++ {
        for i := 0; i < n; i++ {
            if l[j][i] != j+1 {
                k := pos[l[j][i]]
                runMin := a[k]
                if runMin != j+1 {
                    runMin = b[k]
                }

                if l[j][i] <= runMin {
                    soln = append(soln, l[j][i])
                    break
                }
            }
        }
    }

    for _, val := range soln {
        fmt.Print(val, " ")
    }
}

func a51() int {
    var n int
    fmt.Scan(&n)

    xs := make([][]int, n)
    for j := 0; j < n; j++ {
        var a, b int
        fmt.Scan(&a, &b)
        xs[j] = []int{a / 10, a % 10, b % 10, b / 10}

        if j+1 != n {
            var str string
            fmt.Scan(&str)
        }
    }

    for i := range xs {
        b := xs[i]
        for j := 0; j < 4; j++ {
            rotate(b)
            if less(b, xs[i]) {
                xs[i] = b
            }
        }
    }

    sort.Slice(xs, func(i, j int) bool {
        return less(xs[i], xs[j])
    })

    return unique(xs)
}

func b444() {
    var n, d int
    var x int64
    fmt.Scan(&n, &d, &x)

    a := make([]int64, n)
    b := make([]bool, n)
    for i := range a {
        a[i] = int64(i + 1)
    }

    for i := 0; i < n; i++ {
        x = (x*37 + 10007) % 1000000007
        a[i], a[x%int64(i+1)] = a[x%int64(i+1)], a[i]
    }

    for i := 0; i < d; i++ {
        b[i] = true
    }
    for i := 0; i < n; i++ {
        x = (x*37 + 10007) % 1000000007
        c := b[i]
        b[i], b[x%int64(i+1)] = b[x%int64(i+1)], c
    }

    soln := make([]int64, n)
    idx := []int{}
    for j := 0; j < n; j++ {
        if b[j] {
            idx = append(idx, j)
        }
    }

    minHeap := make([]Pair, 0)
    budget := 1000000

    for j := 0; j < n; j++ {
        minHeap = append(minHeap, Pair{a[j], j})
        if budget < len(minHeap)*len(idx) {
            minHeap = minHeap[1:]
        }
    }

    heap := make([]Pair, 0)
    for len(minHeap) > 0 {
        heap = append(heap, minHeap[0])
        minHeap = minHeap[1:]
    }

    for len(heap) > 0 {
        i := heap[0].second
        val := heap[0].first
        heap = heap[1:]

        for _, j := range idx {
            if j+i < n {
                soln[j+i] = max(soln[j+i], val)
            } else {
                break
            }
        }
    }

    for j := 0; j < n; j++ {
        if soln[j] == 0 {
            for _, i := range idx {
                if j < i {
                    break
                } else {
                    soln[j] = max(soln[j], a[j-i])
                }
            }
        }
    }

    for _, val := range soln {
        fmt.Println(val)
    }
}

func main() {
    b444()
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func rotate(arr []int) {
    first := arr[0]
    copy(arr, arr[1:])
    arr[len(arr)-1] = first
}

func less(a, b []int) bool {
    for i := range a {
        if a[i] != b[i] {
            return a[i] < b[i]
        }
    }
    return false
}

func unique(arr [][]int) int {
    sort.Slice(arr, func(i, j int) bool {
        return less(arr[i], arr[j])
    })
    return len(arr)
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}
