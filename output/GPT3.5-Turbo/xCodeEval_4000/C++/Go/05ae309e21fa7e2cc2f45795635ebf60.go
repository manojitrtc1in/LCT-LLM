package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	N   int
	A   [1000]int
	B   [1000]int
	C   [1000]int
	g   wgraph
	arr [1001]int
	as  int
	r   int
	ok  [1001]int
	dp  [1001]int
	back [1001]int
)

type wgraph struct {
	cost [][]int
	g    graph
	N    int
	edge [][]int
	es   []int
}

type graph struct {
	N    int
	edge [][]int
	es   []int
}

func (g *graph) setEdge(N__ int, M int, A []int, B []int, mem *[]byte) {
	N = N__
	es := make([]int, N)
	for i := 0; i < N; i++ {
		es[i] = 0
	}
	for i := 0; i < M; i++ {
		es[A[i]]++
		es[B[i]]++
	}
	edge := make([][]int, N)
	for i := 0; i < N; i++ {
		edge[i] = make([]int, es[i])
	}
	cost := make([][]int, N)
	for i := 0; i < N; i++ {
		cost[i] = make([]int, es[i])
	}
	for i := 0; i < N; i++ {
		es[i] = 0
	}
	for i := 0; i < M; i++ {
		edge[A[i]][es[A[i]]] = B[i]
		edge[B[i]][es[B[i]]] = A[i]
		cost[A[i]][es[A[i]]] = C[i]
		cost[B[i]][es[B[i]]] = C[i]
	}
	g.N = N
	g.es = es
	g.edge = edge
	g.cost = cost
}

func (g *graph) setDirectEdge(N__ int, M int, A []int, B []int, mem *[]byte) {
	N = N__
	es := make([]int, N)
	for i := 0; i < N; i++ {
		es[i] = 0
	}
	for i := 0; i < M; i++ {
		es[A[i]]++
	}
	edge := make([][]int, N)
	for i := 0; i < N; i++ {
		edge[i] = make([]int, es[i])
	}
	cost := make([][]int, N)
	for i := 0; i < N; i++ {
		cost[i] = make([]int, es[i])
	}
	for i := 0; i < N; i++ {
		es[i] = 0
	}
	for i := 0; i < M; i++ {
		edge[A[i]][es[A[i]]] = B[i]
		cost[A[i]][es[A[i]]] = C[i]
	}
	g.N = N
	g.es = es
	g.edge = edge
	g.cost = cost
}

func (g *graph) reverse(mem *[]byte) graph {
	var r graph
	N := g.N
	es := make([]int, N)
	for i := 0; i < N; i++ {
		es[i] = 0
	}
	for i := 0; i < N; i++ {
		for j := 0; j < g.es[i]; j++ {
			es[g.edge[i][j]]++
		}
	}
	edge := make([][]int, N)
	for i := 0; i < N; i++ {
		edge[i] = make([]int, es[i])
	}
	for i := 0; i < N; i++ {
		es[i] = 0
	}
	for i := 0; i < N; i++ {
		for j := 0; j < g.es[i]; j++ {
			k := g.edge[i][j]
			edge[k][es[k]] = i
			es[k]++
		}
	}
	r.N = N
	r.es = es
	r.edge = edge
	return r
}

func (g *graph) reduce(tn int, ind []int, self_e int, dep_e int, mem *[]byte) graph {
	var r graph
	N := g.N
	M := 0
	A := make([]int, N)
	for i := 0; i < N; i++ {
		M += g.es[i]
	}
	arr := make([]pair, M)
	M = 0
	for i := 0; i < N; i++ {
		x := ind[i]
		if x < 0 {
			continue
		}
		for j := 0; j < g.es[i]; j++ {
			y := ind[g.edge[i][j]]
			if y < 0 {
				continue
			}
			if self_e == 0 && x == y {
				continue
			}
			arr[M] = pair{x, y}
			M++
		}
	}
	if dep_e == 0 {
		sort.Slice(arr, func(i, j int) bool {
			if arr[i].first == arr[j].first {
				return arr[i].second < arr[j].second
			}
			return arr[i].first < arr[j].first
		})
		k := 0
		for i := 0; i < M; i++ {
			if k > 0 && arr[k-1] == arr[i] {
				continue
			}
			arr[k] = arr[i]
			k++
		}
		M = k
	}
	r.N = tn
	r.es = make([]int, N)
	r.edge = make([][]int, N)
	r.edge[0] = make([]int, M)
	for i := 0; i < tn; i++ {
		r.es[i] = 0
	}
	for i := 0; i < M; i++ {
		r.es[arr[i].first]++
	}
	for i := 1; i < tn; i++ {
		r.edge[i] = r.edge[i-1][:r.es[i-1]]
	}
	for i := 0; i < tn; i++ {
		r.es[i] = 0
	}
	for i := 0; i < M; i++ {
		j := arr[i].first
		k := arr[i].second
		r.edge[j][r.es[j]] = k
		r.es[j]++
	}
	return r
}

func (g *graph) getDist(root int, res []int, mem []byte) {
	N := g.N
	q := make([]int, N)
	visited := make([]bool, N)
	for i := 0; i < N; i++ {
		res[i] = -1
	}
	res[root] = 0
	s := 0
	z := 1
	q[0] = root
	for z > 0 {
		i := q[s]
		s++
		z--
		for j := 0; j < g.es[i]; j++ {
			k := g.edge[i][j]
			if res[k] >= 0 {
				continue
			}
			res[k] = res[i] + 1
			q[s+z] = k
			z++
		}
	}
}

func (g *graph) sccDFS(num []int, st int, mx int) int {
	num[st] = -2
	for i := 0; i < g.es[st]; i++ {
		j := g.edge[st][i]
		if num[j] == -1 {
			mx = g.sccDFS(num, j, mx)
		}
	}
	num[st] = mx
	return mx + 1
}

func (g *graph) scc(res []int, mem []byte) int {
	N := g.N
	r := g.reverse(mem)
	st := make([]int, N)
	num := make([]int, N)
	nrv := make([]int, N)
	for i := 0; i < N; i++ {
		res[i] = -1
	}
	k := 0
	for i := 0; i < N; i++ {
		if num[i] == -1 {
			k = g.sccDFS(num, i, k)
		}
	}
	for i := 0; i < N; i++ {
		nrv[num[i]] = i
	}
	for k := N - 1; k >= 0; k-- {
		i := nrv[k]
		if res[i] >= 0 {
			continue
		}
		res[i] = k
		st_size := 0
		st[st_size] = i
		for st_size > 0 {
			i = st[st_size-1]
			st_size--
			for j := 0; j < r.es[i]; j++ {
				if res[r.edge[i][j]] == -1 {
					res[r.edge[i][j]] = k
					st[st_size] = r.edge[i][j]
					st_size++
				}
			}
		}
	}
	return k + 1
}

func (g *graph) bccDFS(v int, u int, res []int, rt []int, rts *int, S []int, Ss *int, inS []int, num []int, tm *int) {
	num[v] = *tm
	S[*Ss] = v
	*Ss++
	inS[v] = 1
	rt[*rts] = v
	for i := 0; i < g.es[v]; i++ {
		w := g.edge[v][i]
		if num[w] == 0 {
			g.bccDFS(w, v, res, rt, rts, S, Ss, inS, num, tm)
		} else if u != w && inS[w] {
			for num[rt[*rts-1]] > num[w] {
				*rts--
			}
		}
	}
	if v == rt[*rts-1] {
		k := S[*Ss-1]
		for {
			w := S[*Ss-1]
			*Ss--
			inS[w] = 0
			res[w] = k
			if v == w {
				break
			}
		}
		*rts--
	}
}

func (g *graph) bcc(res []int, mem []byte) int {
	N := g.N
	S := make([]int, N)
	Ss := 0
	inS := make([]int, N)
	num := make([]int, N)
	rt := make([]int, N)
	rts := 0
	tm := 0
	arr := make([]pair, N)
	for i := 0; i < N; i++ {
		num[i] = 0
		inS[i] = 0
	}
	for i := 0; i < N; i++ {
		if num[i] == 0 {
			g.bccDFS(i, N, res, rt, &rts, S, &Ss, inS, num, &tm)
		}
	}
	for i := 0; i < N; i++ {
		arr[i].first = res[i]
		arr[i].second = i
	}
	sort.Slice(arr, func(i, j int) bool {
		if arr[i].first == arr[j].first {
			return arr[i].second < arr[j].second
		}
		return arr[i].first < arr[j].first
	})
	k := 0
	for i := 0; i < N; i++ {
		if i > 0 && arr[i].first != arr[i-1].first {
			k++
		}
		res[arr[i].second] = k
	}
	return k + 1
}

func (g *graph) shortestPath(s int, t int, res []int, mem []byte) int {
	N := g.N
	b := make([]int, N)
	q := make([]int, N)
	qe := 0
	qs := 0
	for i := 0; i < N; i++ {
		b[i] = -1
	}
	b[s] = -2
	q[qe] = s
	qe++
	for qs < qe {
		i := q[qs]
		qs++
		for j := 0; j < g.es[i]; j++ {
			k := g.edge[i][j]
			if b[k] != -1 {
				continue
			}
			b[k] = i
			q[qe] = k
			qe++
		}
		if b[t] != -1 {
			break
		}
	}
	if b[t] == -1 {
		return -1
	}
	k := 0
	res[k] = i
	for i != s {
		k++
		res[k] = b[i]
		i = b[i]
	}
	return k
}

func (g *graph) TopologicalSort(res []int, mem []byte) int {
	N := g.N
	deg := make([]int, N)
	q := make([]int, N)
	qe := 0
	qs := 0
	rs := 0
	for i := 0; i < N; i++ {
		deg[i] = 0
	}
	for i := 0; i < N; i++ {
		for j := 0; j < g.es[i]; j++ {
			deg[g.edge[i][j]]++
		}
	}
	for i := 0; i < N; i++ {
		if deg[i] == 0 {
			q[qe] = i
			qe++
		}
	}
	for qs < qe {
		i := q[qs]
		qs++
		res[rs] = i
		rs++
		for j := 0; j < g.es[i]; j++ {
			k := g.edge[i][j]
			deg[k]--
			if deg[k] == 0 {
				q[qe] = k
				qe++
			}
		}
	}
	if rs == N {
		return 1
	}
	return 0
}

func (g *wgraph) getDist(root int, res []int, unreachable int, mem []byte) {
	hp := new(DijkstraHeap)
	N := g.N
	hp.malloc(N)
	hp.init(N)
	hp.change(root, 0)
	for hp.size > 0 {
		i := hp.pop()
		for j := 0; j < g.es[i]; j++ {
			hp.change(g.edge[i][j], hp.val[i]+g.cost[i][j])
		}
	}
	for i := 0; i < N; i++ {
		if hp.visited[i] {
			res[i] = hp.val[i]
		} else {
			res[i] = unreachable
		}
	}
}

func (g *wgraph) getDistForest(root int, res []int, unreachable int, mem []byte) {
	N := g.N
	r := make([]bool, N)
	q := make([]int, N)
	s := 0
	z := 1
	for i := 0; i < N; i++ {
		r[i] = false
	}
	res[root] = 0
	r[root] = true
	q[0] = root
	for z > 0 {
		i := q[s]
		s++
		z--
		for j := 0; j < g.es[i]; j++ {
			k := g.edge[i][j]
			if r[k] {
				continue
			}
			res[k] = res[i] + g.cost[i][j]
			r[k] = true
			q[s+z] = k
			z++
		}
	}
	for i := 0; i < N; i++ {
		if !r[i] {
			res[i] = unreachable
		}
	}
}

func (g *wgraph) BellmanFord(root int, res []int, unreachable int, minusInf int, step int, mem []byte) {
	N := g.N
	q := make([]int, N)
	inf := make([]int, N)
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		inf[i] = 0
	}
	for i := 0; i < N; i++ {
		res[i] = 0
		arr[i] = 0
	}
	res[root] = 0
	arr[root] = 0
	t := step
	if t == -1 {
		t = N
	}
	for KL2GvlyY := 0; KL2GvlyY < t; KL2GvlyY++ {
		for i := 0; i < N; i++ {
			if res[i] != 0 {
				for j := 0; j < g.es[i]; j++ {
					chmin(&arr[g.edge[i][j]], res[i]+g.cost[i][j])
				}
			}
		}
		for i := 0; i < N; i++ {
			res[i] = arr[i]
		}
	}
	if step != -1 {
		for i := 0; i < N; i++ {
			if res[i] == 0 {
				res[i] = unreachable
			}
		}
		return
	}
	for i := 0; i < N; i++ {
		if res[i] != 0 {
			for j := 0; j < g.es[i]; j++ {
				k := g.edge[i][j]
				if arr[k] > res[i]+g.cost[i][j] {
					inf[k] = 1
				}
			}
		}
	}
	qs := 0
	qe := 0
	for i := 0; i < N; i++ {
		if inf[i] == 1 {
			q[qe] = i
			qe++
		}
	}
	for qs < qe {
		i := q[qs]
		qs++
		for j := 0; j < g.es[i]; j++ {
			k := g.edge[i][j]
			if inf[k] == 0 {
				inf[k] = 1
				q[qe] = k
				qe++
			}
		}
	}
	for i := 0; i < N; i++ {
		if res[i] == 0 {
			res[i] = unreachable
		}
	}
	for i := 0; i < N; i++ {
		if inf[i] == 1 {
			res[i] = minusInf
		}
	}
}

type pair struct {
	first  int
	second int
}

type DijkstraHeap struct {
	val     []int
	visited []bool
	hp      []int
	place   []int
	size    int
}

func (h *DijkstraHeap) malloc(N int) {
	h.hp = make([]int, N)
	h.place = make([]int, N)
	h.visited = make([]bool, N)
	h.val = make([]int, N)
}

func (h *DijkstraHeap) free() {
	h.hp = nil
	h.place = nil
	h.visited = nil
	h.val = nil
}

func (h *DijkstraHeap) walloc(N int, mem *[]byte) {
	walloc1d(&h.hp, N, mem)
	walloc1d(&h.place, N, mem)
	walloc1d(&h.visited, N, mem)
	walloc1d(&h.val, N, mem)
}

func (h *DijkstraHeap) init(N int) {
	h.size = 0
	for i := 0; i < N; i++ {
		h.place[i] = -1
	}
	for i := 0; i < N; i++ {
		h.visited[i] = false
	}
}

func (h *DijkstraHeap) up(n int) {
	m := 0
	for n > 0 {
		m = (n - 1) / 2
		if h.val[h.hp[m]] <= h.val[h.hp[n]] {
			break
		}
		hpSwap(h.hp, m, n)
		hpSwap(h.place, m, n)
		n = m
	}
}

func (h *DijkstraHeap) down(n int) {
	m := 0
	for {
		m = 2*n + 1
		if m >= h.size {
			break
		}
		if m+1 < h.size && h.val[h.hp[m]] > h.val[h.hp[m+1]] {
			m++
		}
		if h.val[h.hp[m]] >= h.val[h.hp[n]] {
			break
		}
		hpSwap(h.hp, m, n)
		hpSwap(h.place, m, n)
		n = m
	}
}

func (h *DijkstraHeap) change(n int, v int) {
	if h.visited[n] || (h.place[n] >= 0 && h.val[n] <= v) {
		return
	}
	h.val[n] = v
	if h.place[n] == -1 {
		h.place[n] = h.size
		h.hp[h.size] = n
		h.up(h.place[n])
		h.size++
	} else {
		h.up(h.place[n])
	}
}

func (h *DijkstraHeap) pop() int {
	res := h.hp[0]
	h.place[res] = -1
	h.size--
	if h.size > 0 {
		h.hp[0] = h.hp[h.size]
		h.place[h.hp[0]] = 0
		h.down(0)
	}
	h.visited[res] = true
	return res
}

func hpSwap(arr []int, i int, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

func walloc1d(arr *[]int, x int, mem *[]byte) {
	skip := []int{0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	*mem = (*mem)[skip[uintptr(unsafe.Pointer(mem))&15]:]
	*arr = (*mem)[:x]
	*mem = (*mem)[x:]
}

func rd(x *int) {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, x)
}

func wt_L(a interface{}) {
	fmt.Println(a)
}

func chmin(a *int, b int) int {
	if *a > b {
		*a = b
	}
	return *a
}

func main() {
	rd(&N)
	for i := 0; i < N-1; i++ {
		rd(&A[i])
		A[i] += -1
		rd(&B[i])
		B[i] += -1
	}
	g.setEdge(N, N-1, A[:N-1], B[:N-1], C[:N-1], nil)
	for r = 0; r < N; r++ {
		as = 0
		for i := 0; i < g.es[r]; i++ {
			arr[as] = dfs2(g.edge[r][i], r)
			as++
		}
		for i := 0; i < N+1; i++ {
			dp[i] = 0
		}
		dp[0] = 1
		for i := 0; i < as; i++ {
			for j := N; j >= arr[i]; j-- {
				if dp[j] == 0 && dp[j-arr[i]] == 1 {
					dp[j] = 1
					back[j] = i
				}
			}
		}
		for p := 0; p < N+1; p++ {
			if dp[p] == 1 && (p+1)*(N-p)-1 >= 2*N*N/9 {
				break
			}
		}
		if p == N+1 {
			continue
		}
		k := p
		for k > 0 {
			ok[back[k]] = 1
			k -= arr[back[k]]
		}
		cnt = 0
		dfs(r, -1, 0, 1, 0)
		cnt = 0
		dfs(r, -1, 0, p+1, 1)
		break
	}
	for i := 0; i < N; i++ {
		for j := 0; j < g.es[i]; j++ {
			k := g.edge[i][j]
			r := g.cost[i][j]
			if r > 0 {
				wt_L(i+1)
				wt_L(' ')
				wt_L(k+1)
				wt_L(' ')
				wt_L(r)
				wt_L('\n')
			}
		}
	}
}
