package main

import (
	"fmt"
	"math"
)

func id0(M int) []int {
	d := []int{}
	i := 1
	for M >= i*i {
		if M%i == 0 {
			d = append(d, i)
			if i*i != M {
				d = append(d, M/i)
			}
		}
		i++
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

func id1(n int) map[int]struct{} {
	res := make([]int, n+1)
	prime := make(map[int]struct{})
	for i := 2; i <= n; i++ {
		if res[i] == 0 {
			prime[i] = struct{}{}
			for j := 1; j <= n/i; j++ {
				res[i*j] = 1
			}
		}
	}
	return prime
}

func factorization(n int, prime map[int]struct{}) []int {
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

func id7(n int) int {
	res := n
	for x := 2; x <= n; x++ {
		if x*x > n {
			break
		}
		if n%x == 0 {
			res = res / x * (x - 1)
			for n%x == 0 {
				n /= x
			}
		}
	}
	if n != 1 {
		res = res / n * (n - 1)
	}
	return res
}

func ind(b, n int) int {
	res := 0
	for n%b == 0 {
		res++
		n /= b
	}
	return res
}

func id2(n int) int {
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

func id12(n int) int {
	m := 1 << (int(math.Log2(float64(n))) / 8)
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
				for i := 0; i < int(math.Min(float64(m), float64(r-k))); i++ {
					y = f(y)
					q = (q * abs(x-y)) % n
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
			if id2(g) == 1 {
				return g
			} else if id2(n/g) == 1 {
				return n / g
			}
			return id12(g)
		}
	}
	return 0
}

func primeFactor(n int) map[int]int {
	i := 2
	ret := make(map[int]int)
	rhoFlg := 0
	for i*i <= n {
		k := 0
		for n%i == 0 {
			n /= i
			k++
		}
		if k > 0 {
			ret[i] = k
		}
		i += 1 + i%2
		if i == 101 && n >= 1<<20 {
			for n > 1 {
				if id2(n) == 1 {
					ret[n] = 1
					n = 1
				} else {
					rhoFlg = 1
					j := id12(n)
					k = 0
					for n%j == 0 {
						n /= j
						k++
					}
					ret[j] = k
				}
			}
		}
	}
	if n > 1 {
		ret[n] = 1
	}
	if rhoFlg > 0 {
		sortedKeys := make([]int, 0, len(ret))
		for k := range ret {
			sortedKeys = append(sortedKeys, k)
		}
		sort.Ints(sortedKeys)
		newRet := make(map[int]int)
		for _, k := range sortedKeys {
			newRet[k] = ret[k]
		}
		ret = newRet
	}
	return ret
}

func id0(n int) []int {
	res := []int{1}
	prime := primeFactor(n)
	for p, count := range prime {
		newres := []int{}
		for _, d := range res {
			for j := 0; j <= count; j++ {
				newres = append(newres, d*int(math.Pow(float64(p), float64(j))))
			}
		}
		res = newres
	}
	sort.Ints(res)
	return res
}

func id11(num int) int {
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
		return (1 << x) * ((num - (1 << x) + 1) % 2) + function(num-(1 << x))
	}
}

func xorconv(n int, X, Y []int) []int {
	if n == 0 {
		return []int{(X[0] * Y[0]) % mod}
	}
	x := make([]int, 1<<uint(n-1))
	y := make([]int, 1<<uint(n-1))
	for i := 0; i < 1<<uint(n-1); i++ {
		x[i] = X[i] + X[i+1<<(n-1)]
		y[i] = Y[i] + Y[i+1<<(n-1)]
	}
	z := make([]int, 1<<uint(n-1))
	w := make([]int, 1<<uint(n-1))
	for i := 0; i < 1<<uint(n-1); i++ {
		z[i] = X[i] - X[i+1<<(n-1)]
		w[i] = Y[i] - Y[i+1<<(n-1)]
	}
	res1 := xorconv(n-1, x, y)
	res2 := xorconv(n-1, z, w)
	former := make([]int, 1<<uint(n-1))
	latter := make([]int, 1<<uint(n-1))
	for i := 0; i < 1<<uint(n-1); i++ {
		former[i] = (res1[i] + res2[i]) * inv % mod
		latter[i] = (res1[i] - res2[i]) * inv % mod
	}
	return append(former, latter...)
}

func mergeSort(A, B []int) []int {
	posA, posB := 0, 0
	n, m := len(A), len(B)
	res := []int{}
	for posA < n && posB < m {
		a, b := A[posA], B[posB]
		if a < b {
			res = append(res, a)
			posA++
		} else {
			res = append(res, b)
			posB++
		}
	}
	res = append(res, A[posA:]...)
	res = append(res, B[posB:]...)
	return res
}

type id9 struct {
	_parent []int
	_size   []int
	group   int
}

func newId9(N int) *id9 {
	parent := make([]int, N)
	size := make([]int, N)
	for i := range parent {
		parent[i] = i
		size[i] = 1
	}
	return &id9{_parent: parent, _size: size, group: N}
}

func (d *id9) findRoot(x int) int {
	if d._parent[x] == x {
		return x
	}
	d._parent[x] = d.findRoot(d._parent[x])
	stack := []int{x}
	for d._parent[stack[len(stack)-1]] != stack[len(stack)-1] {
		stack = append(stack, d._parent[stack[len(stack)-1]])
	}
	for _, v := range stack {
		d._parent[v] = stack[len(stack)-1]
	}
	return d._parent[x]
}

func (d *id9) unite(x, y int) {
	gx := d.findRoot(x)
	gy := d.findRoot(y)
	if gx == gy {
		return
	}
	d.group--
	if d._size[gx] < d._size[gy] {
		d._parent[gx] = gy
		d._size[gy] += d._size[gx]
	} else {
		d._parent[gy] = gx
		d._size[gx] += d._size[gy]
	}
}

func (d *id9) getSize(x int) int {
	return d._size[d.findRoot(x)]
}

func (d *id9) id4(x, y int) bool {
	return d.findRoot(x) == d.findRoot(y)
}

type id6 struct {
	parent []int
	size   []int
	val    []int
	flag   bool
	edge   [][][2]int
}

func newId6(N int) *id6 {
	parent := make([]int, N)
	size := make([]int, N)
	val := make([]int, N)
	edge := make([][][2]int, N)
	for i := range parent {
		parent[i] = i
		size[i] = 1
		val[i] = 0
	}
	return &id6{parent: parent, size: size, val: val, flag: true, edge: edge}
}

func (d *id6) dfs(v, pv int) {
	stack := [][2]int{{v, pv}}
	newParent := d.parent[pv]
	for len(stack) > 0 {
		v, pv = stack[len(stack)-1][0], stack[len(stack)-1][1]
		stack = stack[:len(stack)-1]
		d.parent[v] = newParent
		for _, nv := range d.edge[v] {
			if nv[0] != pv {
				d.val[nv[0]] = d.val[v] + nv[1]
				stack = append(stack, [2]int{nv[0], v})
			}
		}
	}
}

func (d *id6) unite(x, y, w int) {
	if !d.flag {
		return
	}
	if d.parent[x] == d.parent[y] {
		d.flag = (d.val[x] - d.val[y] == w)
		return
	}
	if d.size[d.parent[x]] > d.size[d.parent[y]] {
		d.edge[x] = append(d.edge[x], [2]int{y, -w})
		d.edge[y] = append(d.edge[y], [2]int{x, w})
		d.size[x] += d.size[y]
		d.val[y] = d.val[x] - w
		d.dfs(y, x)
	} else {
		d.edge[x] = append(d.edge[x], [2]int{y, -w})
		d.edge[y] = append(d.edge[y], [2]int{x, w})
		d.size[y] += d.size[x]
		d.val[x] = d.val[y] + w
		d.dfs(x, y)
	}
}

type Dijkstra struct {
	G   [][]Edge
	_E  int
	_V  int
}

type Edge struct {
	to   int
	cost int
}

func newDijkstra(V int) *Dijkstra {
	G := make([][]Edge, V)
	return &Dijkstra{G: G, _E: 0, _V: V}
}

func (d *Dijkstra) addEdge(from, to, cost int) {
	d.G[from] = append(d.G[from], Edge{to: to, cost: cost})
	d._E++
}

func (d *Dijkstra) id10(s int) []int {
	que := make([][2]int, 0)
	distance := make([]int, d._V)
	for i := range distance {
		distance[i] = 1e15
	}
	distance[s] = 0
	que = append(que, [2]int{0, s})

	for len(que) > 0 {
		cost, v := que[0][0], que[0][1]
		que = que[1:]
		if distance[v] < cost {
			continue
		}
		for _, e := range d.G[v] {
			if distance[e.to] > distance[v]+e.cost {
				distance[e.to] = distance[v] + e.cost
				que = append(que, [2]int{distance[e.to], e.to})
			}
		}
	}
	return distance
}

func ZAlgorithm(s string) []int {
	N := len(s)
	ZAlg := make([]int, N)
	ZAlg[0] = N
	i, j := 1, 0
	for i < N {
		for i+j < N && s[j] == s[i+j] {
			j++
		}
		ZAlg[i] = j
		if j == 0 {
			i++
			continue
		}
		k := 1
		for i+k < N && k+ZAlg[k] < j {
			ZAlg[i+k] = ZAlg[k]
			k++
		}
		i += k
		j -= k
	}
	return ZAlg
}

type BIT struct {
	BIT []int
	num int
	mod int
}

func newBIT(n, mod int) *BIT {
	BIT := make([]int, n+1)
	return &BIT{BIT: BIT, num: n, mod: mod}
}

func (b *BIT) query(idx int) int {
	resSum := 0
	mod := b.mod
	for idx > 0 {
		resSum += b.BIT[idx]
		if mod != 0 {
			resSum %= mod
		}
		idx -= idx & (-idx)
	}
	return resSum
}

func (b *BIT) update(idx, x int) {
	mod := b.mod
	for idx <= b.num {
		b.BIT[idx] += x
		if mod != 0 {
			b.BIT[idx] %= mod
		}
		idx += idx & (-idx)
	}
}

type id5 struct {
	n     int
	debug bool
	_left  []int
	_right []int
	exist  []bool
}

func newId5(n int, debug bool) *id5 {
	left := make([]int, n)
	right := make([]int, n)
	exist := make([]bool, n)
	for i := range left {
		left[i] = i - 1
		right[i] = i + 1
		exist[i] = true
	}
	return &id5{n: n, debug: debug, _left: left, _right: right, exist: exist}
}

func (d *id5) pop(k int) {
	if d.debug {
		if !d.exist[k] {
			panic("assertion failed")
		}
	}
	L := d._left[k]
	R := d._right[k]
	if L != -1 {
		if R != d.n {
			d._right[L] = R
			d._left[R] = L
		} else {
			d._right[L] = d.n
		}
	} else if R != d.n {
		d._left[R] = -1
	}
	d.exist[k] = false
}

func (d *id5) left(idx, k int) int {
	if d.debug {
		if !d.exist[idx] {
			panic("assertion failed")
		}
	}
	res := idx
	for k > 0 {
		res = d._left[res]
		if res == -1 {
			break
		}
		k--
	}
	return res
}

func (d *id5) right(idx, k int) int {
	if d.debug {
		if !d.exist[idx] {
			panic("assertion failed")
		}
	}
	res := idx
	for k > 0 {
		res = d._right[res]
		if res == d.n {
			break
		}
		k--
	}
	return res
}

type SparseTable struct {
	table      [][]int
	mergeFunc  func(int, int) int
	ideEle     int
	size       int
}

func newSparseTable(A []int, mergeFunc func(int, int) int, ideEle int) *SparseTable {
	N := len(A)
	n := int(math.Log2(float64(N))) + 1
	table := make([][]int, N)
	for i := range table {
		table[i] = make([]int, n)
	}
	for i := 0; i < N; i++ {
		table[i][0] = A[i]
	}
	for j := 1; j < n; j++ {
		for i := 0; i <= N-(1<<j); i++ {
			f := table[i][j-1]
			s := table[i+(1<<(j-1))][j-1]
			table[i][j] = mergeFunc(f, s)
		}
	}
	return &SparseTable{table: table, mergeFunc: mergeFunc, ideEle: ideEle, size: N}
}

func (s *SparseTable) query(sIndex, tIndex int) int {
	b := tIndex - sIndex + 1
	m := int(math.Log2(float64(b)))
	return s.mergeFunc(s.table[sIndex][m], s.table[tIndex-(1<<m)+1][m])
}

type BinaryTrie struct {
	root *node
}

type node struct {
	left *node
	right *node
	max   int
}

func newBinaryTrie() *BinaryTrie {
	return &BinaryTrie{root: &node{max: -1e15}}
}

func (b *BinaryTrie) append(key, val int) {
	pos := b.root
	for i := 29; i >= 0; i-- {
		pos.max = max(pos.max, val)
		if (key>>i)&1 == 1 {
			if pos.right == nil {
				pos.right = &node{max: val}
				pos = pos.right
			} else {
				pos = pos.right
			}
		} else {
			if pos.left == nil {
				pos.left = &node{max: val}
				pos = pos.left
			} else {
				pos = pos.left
			}
		}
	}
	pos.max = max(pos.max, val)
}

func (b *BinaryTrie) search(M, xor int) int {
	res := -1e15
	pos := b.root
	for i := 29; i >= 0; i-- {
		if pos == nil {
			break
		}
		if (M>>i)&1 == 1 {
			if (xor>>i)&1 == 1 {
				if pos.right != nil {
					res = max(res, pos.right.max)
				}
				pos = pos.left
			} else {
				if pos.left != nil {
					res = max(res, pos.left.max)
				}
				pos = pos.right
			}
		} else {
			if (xor>>i)&1 == 1 {
				pos = pos.right
			} else {
				pos = pos.left
			}
		}
	}
	if pos != nil {
		res = max(res, pos.max)
	}
	return res
}

func id3(edge [][][3]int, ans []int, n, m int) []int {
	x := make([]int, m)
	used := make([]bool, n)
	for v := 0; v < n; v++ {
		if used[v] {
			continue
		}
		y := dfs(v, edge, ans, used, x)
		if y != 0 {
			return nil
		}
	}
	return x
}

func dfs(v int, edge [][][3]int, ans []int, used []bool, x []int) int {
	used[v] = true
	r := ans[v]
	for _, e := range edge[v] {
		to, dire, id := e[0], e[1], e[2]
		if used[to] {
			continue
		}
		y := dfs(to, edge, ans, used, x)
		if dire == -1 {
			x[id] = y
		} else {
			x[id] = -y
		}
		r += y
	}
	return r
}

type SegmentTree struct {
	tree     []int
	segFunc  func(int, int) int
	ideEle   int
	num      int
	size     int
}

func newSegmentTree(initVal []int, segFunc func(int, int) int, ideEle int) *SegmentTree {
	n := len(initVal)
	segTree := make([]int, 2*(1<<(int(math.Log2(float64(n)))+1)))
	for i := 0; i < n; i++ {
		segTree[(1<<(int(math.Log2(float64(n)))))+i] = initVal[i]
	}
	for i := (1 << (int(math.Log2(float64(n))) + 1)) - 1; i > 0; i-- {
		segTree[i] = segFunc(segTree[2*i], segTree[2*i+1])
	}
	return &SegmentTree{tree: segTree, segFunc: segFunc, ideEle: ideEle, num: 1 << (int(math.Log2(float64(n))) + 1), size: n}
}

func (s *SegmentTree) update(k, x int) {
	k += s.num
	s.tree[k] = x
	for k > 1 {
		s.tree[k>>1] = s.segFunc(s.tree[k], s.tree[k^1])
		k >>= 1
	}
}

func (s *SegmentTree) query(l, r int) int {
	if r == s.size {
		r = s.num
	}
	res := s.ideEle
	l += s.num
	r += s.num
	for l < r {
		if l&1 == 1 {
			res = s.segFunc(res, s.tree[l])
			l++
		}
		if r&1 == 1 {
			r--
			res = s.segFunc(res, s.tree[r])
		}
		l >>= 1
		r >>= 1
	}
	return res
}

func (s *SegmentTree) id8(l, r, x int) int {
	l += s.num
	r += s.num
	Lmin := -1
	Rmin := -1
	for l < r {
		if l&1 == 1 {
			if s.tree[l] <= x && Lmin == -1 {
				Lmin = l
			}
			l++
		}
		if r&1 == 1 {
			if s.tree[r-1] <= x {
				Rmin = r - 1
			}
			r--
		}
	}
	if Lmin != -1 {
		pos := Lmin
		for pos < s.num {
			if s.tree[2*pos] <= x {
				pos = 2 * pos
			} else {
				pos = 2*pos + 1
			}
		}
		return pos - s.num
	} else if Rmin != -1 {
		pos := Rmin
		for pos < s.num {
			if s.tree[2*pos] <= x {
				pos = 2 * pos
			} else {
				pos = 2*pos + 1
			}
		}
		return pos - s.num
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
