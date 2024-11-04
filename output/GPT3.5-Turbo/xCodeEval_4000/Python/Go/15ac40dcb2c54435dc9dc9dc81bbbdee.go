package main

import (
	"fmt"
)

func divisors(M int) []int {
	d := []int{}
	i := 1
	for M >= i*i {
		if M%i == 0 {
			d = append(d, i)
			if i*i != M {
				d = append(d, M/i)
			}
		}
		i = i + 1
	}
	return d
}

func popcount(x int) int {
	x = x - ((x >> 1) & 0x55555555)
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
	x = (x + (x >> 4)) & 0x0f0f0f0f
	x = x + (x >> 8)
	x = x + (x >> 16)
	return x & 0x0000007f
}

func eratosthenes(n int) map[int]bool {
	res := make(map[int]bool)
	prime := []int{}
	for i := 2; i <= n; i++ {
		if _, ok := res[i]; !ok {
			prime = append(prime, i)
			for j := 1; j <= n/i; j++ {
				res[i*j] = true
			}
		}
	}
	return res
}

func factorization(n int, prime map[int]bool) []int {
	res := []int{}
	for p := range prime {
		if n%p == 0 {
			for n%p == 0 {
				n /= p
			}
			res = append(res, p)
		}
	}
	if n != 1 {
		res = append(res, n)
	}
	return res
}

func euler_phi(n int) int {
	res := n
	for x := 2; x <= n; x++ {
		if x*x > n {
			break
		}
		if n%x == 0 {
			res = res/x*(x-1)
			for n%x == 0 {
				n /= x
			}
		}
	}
	if n != 1 {
		res = res/n*(n-1)
	}
	return res
}

func ind(b, n int) int {
	res := 0
	for n%b == 0 {
		res += 1
		n /= b
	}
	return res
}

func isPrimeMR(n int) int {
	d := n - 1
	d = d / (d & -d)
	L := []int{2, 3, 5, 7, 11, 13, 17}
	for _, a := range L {
		t := d
		y := pow(a, t, n)
		if y == 1 {
			continue
		}
		for y != n-1 {
			y = (y * y) % n
			if y == 1 || t == n-1 {
				return 0
			}
			t <<= 1
		}
	}
	return 1
}

func findFactorRho(n int) int {
	m := 1 << (n.bitLength() / 8)
	for c := 1; c < 99; c++ {
		f := func(x int) int {
			return (x*x + c) % n
		}
		y, r, q, g := 2, 1, 1, 1
		for g == 1 {
			x := y
			for i := 0; i < r; i++ {
				y = f(y)
			}
			k := 0
			for k < r && g == 1 {
				ys := y
				for i := 0; i < min(m, r-k); i++ {
					y = f(y)
					q = q * abs(x-y) % n
				}
				g = gcd(q, n)
				k += m
			}
			r <<= 1
		}
		if g == n {
			g = 1
			for g == 1 {
				ys = f(ys)
				g = gcd(abs(x-ys), n)
			}
		}
		if g < n {
			if isPrimeMR(g) == 1 {
				return g
			} else if isPrimeMR(n/g) == 1 {
				return n / g
			}
			return findFactorRho(g)
		}
	}
	return -1
}

func primeFactor(n int) map[int]int {
	i := 2
	ret := make(map[int]int)
	rhoFlg := 0
	for i*i <= n {
		k := 0
		for n%i == 0 {
			n /= i
			k += 1
		}
		if k != 0 {
			ret[i] = k
		}
		i += 1 + i%2
		if i == 101 && n >= 2**20 {
			for n > 1 {
				if isPrimeMR(n) == 1 {
					ret[n], n = 1, 1
				} else {
					rhoFlg = 1
					j := findFactorRho(n)
					k := 0
					for n%j == 0 {
						n /= j
						k += 1
					}
					ret[j] = k
				}
			}
		}
	}
	if n > 1 {
		ret[n] = 1
	}
	if rhoFlg == 1 {
		// sort ret
	}
	return ret
}

func divisors(n int) []int {
	res := []int{1}
	prime := primeFactor(n)
	for p := range prime {
		newres := []int{}
		for _, d := range res {
			for j := 0; j <= prime[p]; j++ {
				newres = append(newres, d*pow(p, j))
			}
		}
		res = newres
	}
	// sort res
	return res
}

func xorfactorial(num int) int {
	if num == 0 {
		return 0
	} else if num == 1 {
		return 1
	} else if num == 2 {
		return 3
	} else if num == 3 {
		return 0
	} else {
		x := baseorder(num)
		return (2**x)*((num-2**x+1)%2) + function(num-2**x)
	}
}

func xorconv(n int, X, Y []int) []int {
	if n == 0 {
		res := []int{(X[0] * Y[0]) % mod}
		return res
	}
	x := make([]int, 2**(n-1))
	y := make([]int, 2**(n-1))
	z := make([]int, 2**(n-1))
	w := make([]int, 2**(n-1))
	for i := 0; i < 2**(n-1); i++ {
		x[i] = X[i] + X[i+2**(n-1)]
		y[i] = Y[i] + Y[i+2**(n-1)]
		z[i] = X[i] - X[i+2**(n-1)]
		w[i] = Y[i] - Y[i+2**(n-1)]
	}
	res1 := xorconv(n-1, x, y)
	res2 := xorconv(n-1, z, w)
	former := make([]int, 2**(n-1))
	latter := make([]int, 2**(n-1))
	for i := 0; i < 2**(n-1); i++ {
		former[i] = (res1[i] + res2[i]) * inv
		latter[i] = (res1[i] - res2[i]) * inv
	}
	// mod former and latter
	return append(former, latter...)
}

func merge_sort(A, B []int) []int {
	pos_A, pos_B := 0, 0
	n, m := len(A), len(B)
	res := []int{}
	for pos_A < n && pos_B < m {
		a, b := A[pos_A], B[pos_B]
		if a < b {
			res = append(res, a)
			pos_A += 1
		} else {
			res = append(res, b)
			pos_B += 1
		}
	}
	res = append(res, A[pos_A:]...)
	res = append(res, B[pos_B:]...)
	return res
}

type UnionFindVerSize struct {
	parent []int
	size   []int
	group  int
}

func NewUnionFindVerSize(N int) *UnionFindVerSize {
	parent := make([]int, N)
	size := make([]int, N)
	for i := 0; i < N; i++ {
		parent[i] = i
		size[i] = 1
	}
	return &UnionFindVerSize{
		parent: parent,
		size:   size,
		group:  N,
	}
}

func (uf *UnionFindVerSize) findRoot(x int) int {
	if uf.parent[x] == x {
		return x
	}
	uf.parent[x] = uf.findRoot(uf.parent[x])
	stack := []int{x}
	for uf.parent[stack[len(stack)-1]] != stack[len(stack)-1] {
		stack = append(stack, uf.parent[stack[len(stack)-1]])
	}
	for _, v := range stack {
		uf.parent[v] = stack[len(stack)-1]
	}
	return uf.parent[x]
}

func (uf *UnionFindVerSize) unite(x, y int) {
	gx := uf.findRoot(x)
	gy := uf.findRoot(y)
	if gx == gy {
		return
	}
	uf.group -= 1
	if uf.size[gx] < uf.size[gy] {
		uf.parent[gx] = gy
		uf.size[gy] += uf.size[gx]
	} else {
		uf.parent[gy] = gx
		uf.size[gx] += uf.size[gy]
	}
}

func (uf *UnionFindVerSize) getSize(x int) int {
	return uf.size[uf.findRoot(x)]
}

func (uf *UnionFindVerSize) isSameGroup(x, y int) bool {
	return uf.findRoot(x) == uf.findRoot(y)
}

type WeightedUnionFind struct {
	parent []int
	size   []int
	val    []int
	flag   bool
	edge   [][]int
}

func NewWeightedUnionFind(N int) *WeightedUnionFind {
	parent := make([]int, N)
	size := make([]int, N)
	val := make([]int, N)
	edge := make([][]int, N)
	for i := 0; i < N; i++ {
		parent[i] = i
		size[i] = 1
		val[i] = 0
		edge[i] = []int{}
	}
	return &WeightedUnionFind{
		parent: parent,
		size:   size,
		val:    val,
		flag:   true,
		edge:   edge,
	}
}

func (wuf *WeightedUnionFind) dfs(v, pv int) {
	stack := [][]int{{v, pv}}
	new_parent := wuf.parent[pv]
	for len(stack) != 0 {
		v, pv := stack[len(stack)-1][0], stack[len(stack)-1][1]
		stack = stack[:len(stack)-1]
		wuf.parent[v] = new_parent
		for _, nv := range wuf.edge[v] {
			if nv != pv {
				wuf.val[nv] = wuf.val[v] + 1
				stack = append(stack, []int{nv, v})
			}
		}
	}
}

func (wuf *WeightedUnionFind) unite(x, y, w int) {
	if !wuf.flag {
		return
	}
	if wuf.parent[x] == wuf.parent[y] {
		wuf.flag = (wuf.val[x] - wuf.val[y] == w)
		return
	}
	if wuf.size[wuf.parent[x]] > wuf.size[wuf.parent[y]] {
		wuf.edge[x] = append(wuf.edge[x], []int{y, -w})
		wuf.edge[y] = append(wuf.edge[y], []int{x, w})
		wuf.size[x] += wuf.size[y]
		wuf.val[y] = wuf.val[x] - w
		wuf.dfs(y, x)
	} else {
		wuf.edge[x] = append(wuf.edge[x], []int{y, -w})
		wuf.edge[y] = append(wuf.edge[y], []int{x, w})
		wuf.size[y] += wuf.size[x]
		wuf.val[x] = wuf.val[y] + w
		wuf.dfs(x, y)
	}
}

type Dijkstra struct {
	Edge [][]Edge
	V    int
}

type Edge struct {
	to   int
	cost int
}

func NewDijkstra(V int) *Dijkstra {
	Edge := make([][]Edge, V)
	for i := 0; i < V; i++ {
		Edge[i] = []Edge{}
	}
	return &Dijkstra{
		Edge: Edge,
		V:    V,
	}
}

func (d *Dijkstra) addEdge(_from, _to, _cost int) {
	d.Edge[_from] = append(d.Edge[_from], Edge{_to, _cost})
}

func (d *Dijkstra) shortestPath(s int) []int {
	que := make(PriorityQueue, 0)
	heap.Init(&que)
	dists := make([]int, d.V)
	for i := 0; i < d.V; i++ {
		dists[i] = 1e15
	}
	dists[s] = 0
	heap.Push(&que, &Item{value: s, priority: 0})

	for que.Len() != 0 {
		item := heap.Pop(&que).(*Item)
		v := item.value
		if dists[v] < item.priority {
			continue
		}
		for _, e := range d.Edge[v] {
			if dists[e.to] > dists[v]+e.cost {
				dists[e.to] = dists[v] + e.cost
				heap.Push(&que, &Item{value: e.to, priority: dists[e.to]})
			}
		}
	}
	return dists
}

type Item struct {
	value    int
	priority int
	index    int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func Z_algorithm(s string) []int {
	N := len(s)
	Z_alg := make([]int, N)

	Z_alg[0] = N
	i := 1
	j := 0
	for i < N {
		for i+j < N && s[j] == s[i+j] {
			j += 1
		}
		Z_alg[i] = j
		if j == 0 {
			i += 1
			continue
		}
		k := 1
		for i+k < N && k+Z_alg[k] < j {
			Z_alg[i+k] = Z_alg[k]
			k += 1
		}
		i += k
		j -= k
	}
	return Z_alg
}

type BIT struct {
	BIT  []int
	num  int
	mod  int
}

func NewBIT(n, mod int) *BIT {
	return &BIT{
		BIT:  make([]int, n+1),
		num:  n,
		mod:  mod,
	}
}

func (bit *BIT) query(idx int) int {
	res_sum := 0
	mod := bit.mod
	for idx > 0 {
		res_sum += bit.BIT[idx]
		if mod != 0 {
			res_sum %= mod
		}
		idx -= idx & -idx
	}
	return res_sum
}

func (bit *BIT) update(idx, x int) {
	mod := bit.mod
	for idx <= bit.num {
		bit.BIT[idx] += x
		if mod != 0 {
			bit.BIT[idx] %= mod
		}
		idx += idx & -idx
	}
}

type dancinglink struct {
	n     int
	debug bool
	_left []int
	_right []int
	exist []bool
}

func NewDancingLink(n int, debug bool) *dancinglink {
	_left := make([]int, n)
	_right := make([]int, n)
	exist := make([]bool, n)
	for i := 0; i < n; i++ {
		_left[i] = i - 1
		_right[i] = i + 1
		exist[i] = true
	}
	return &dancinglink{
		n:     n,
		debug: debug,
		_left: _left,
		_right: _right,
		exist: exist,
	}
}

func (dl *dancinglink) pop(k int) {
	if dl.debug {
		if !dl.exist[k] {
			panic("Invalid operation")
		}
	}
	L := dl._left[k]
	R := dl._right[k]
	if L != -1 {
		if R != dl.n {
			dl._right[L], dl._left[R] = R, L
		} else {
			dl._right[L] = dl.n
		}
	} else if R != dl.n {
		dl._left[R] = -1
	}
	dl.exist[k] = false
}

func (dl *dancinglink) left(idx, k int) int {
	if dl.debug {
		if !dl.exist[idx] {
			panic("Invalid operation")
		}
	}
	res := idx
	for k > 0 {
		res = dl._left[res]
		if res == -1 {
			break
		}
		k -= 1
	}
	return res
}

func (dl *dancinglink) right(idx, k int) int {
	if dl.debug {
		if !dl.exist[idx] {
			panic("Invalid operation")
		}
	}
	res := idx
	for k > 0 {
		res = dl._right[res]
		if res == dl.n {
			break
		}
		k -= 1
	}
	return res
}

func solveequation(edge [][]int, ans []int, n, m int) []int {
	x := make([]int, m)
	used := make([]bool, n)
	for v := 0; v < n; v++ {
		if used[v] {
			continue
		}
		y := dfs(v)
		if y != 0 {
			return nil
		}
	}
	return x

	func dfs(v int) int {
		used[v] = true
		r := ans[v]
		for _, e := range edge[v] {
			to, dire, id := e[0], e[1], e[2]
			if used[to] {
				continue
			}
			y := dfs(to)
			if dire == -1 {
				x[id] = y
			} else {
				x[id] = -y
			}
			r += y
		}
		return r
	}
}

type SegmentTree struct {
	tree     []int
	segfunc  func(int, int) int
	ide_ele  int
	num      int
	size     int
}

func NewSegmentTree(init_val []int, segfunc func(int, int) int, ide_ele int) *SegmentTree {
	n := len(init_val)
	num := 1 << (n - 1).bitLen()
	tree := make([]int, 2*num)
	size := n
	for i := 0; i < n; i++ {
		tree[num+i] = init_val[i]
	}
	for i := num - 1; i > 0; i-- {
		tree[i] = segfunc(tree[2*i], tree[2*i+1])
	}
	return &SegmentTree{
		tree:    tree,
		segfunc: segfunc,
		ide_ele: ide_ele,
		num:     num,
		size:    size,
	}
}

func (st *SegmentTree) Update(k, x int) {
	k += st.num
	st.tree[k] = x
	for k > 1 {
		st.tree[k>>1] = st.segfunc(st.tree[k], st.tree[k^1])
		k >>= 1
	}
}

func (st *SegmentTree) Query(l, r int) int {
	if r == st.size {
		r = st.num
	}
	res := st.ide_ele
	l += st.num
	r += st.num
	for l < r {
		if l&1 == 1 {
			res = st.segfunc(res, st.tree[l])
			l += 1
		}
		if r&1 == 1 {
			res = st.segfunc(res, st.tree[r-1])
		}
		l >>= 1
		r >>= 1
	}
	return res
}

func (st *SegmentTree) BisectL(l, r, x int) int {
	l += st.num
	r += st.num
	Lmin := -1
	Rmin := -1
	for l < r {
		if l&1 == 1 {
			if st.tree[l] <= x && Lmin == -1 {
				Lmin = l
			}
			l += 1
		}
		if r&1 == 1 {
			if st.tree[r-1] <= x {
				Rmin = r - 1
			}
		}
		l >>= 1
		r >>= 1
	}

	if Lmin != -1 {
		pos := Lmin
		for pos < st.num {
			if st.tree[2*pos] <= x {
				pos = 2 * pos
			} else {
				pos = 2*pos + 1
			}
		}
		return pos - st.num
	} else if Rmin != -1 {
		pos := Rmin
		for pos < st.num {
			if st.tree[2*pos] <= x {
				pos = 2 * pos
			} else {
				pos = 2*pos + 1
			}
		}
		return pos - st.num
	} else {
		return -1
	}
}

func main() {
	var n, mod int
	fmt.Scan(&n, &mod)

	M := int(math.Sqrt(float64(n))) + 10

	dp := make([]int, n+1)
	imos := make([]int, n+1)
	dp[1] = 1
	for i := 1; i < n; i++ {
		imos[i] = (imos[i] + imos[i-1]) % mod
		dp[i] += imos[i]
		dp[i] %= mod

		imos[i+1] += dp[i]
		imos[i+1] %= mod

		for j := 2; j <= n; j++ {
			if i*j > n {
				break
			}

			imos[i*j] += dp[i]
			imos[i*j] %= mod
			if (i+1)*j <= n {
				imos[(i+1)*j] -= dp[i]
				imos[(i+1)*j] %= mod
			}
		}
	}

	res := (dp[n] + imos[n] + imos[n-1]) % mod
	fmt.Println(res)
}
