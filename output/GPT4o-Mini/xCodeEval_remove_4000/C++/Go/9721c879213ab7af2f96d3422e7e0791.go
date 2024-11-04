package main

import (
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	first, second int64
}

type LCA struct {
	N   int64
	n   int64
	up  [][]int64
	g   [][]int64
	lvl []int64
}

func NewLCA(parent []int64) *LCA {
	n := int64(len(parent))
	N := int64(math.Log2(float64(n))) + 1
	g := make([][]int64, n)
	lvl := make([]int64, n)
	core := int64(-1)

	for i := int64(0); i < n; i++ {
		if parent[i] != -1 {
			g[parent[i]] = append(g[parent[i]], i)
		} else {
			core = i
		}
	}
	lca := &LCA{N: N, n: n, g: g, lvl: lvl}
	lca.dfs(core, 0)

	lca.up = make([][]int64, N)
	for i := int64(0); i < N; i++ {
		lca.up[i] = make([]int64, n)
	}
	for i := int64(0); i < n; i++ {
		lca.up[0][i] = parent[i]
	}
	for i := int64(1); i < N; i++ {
		for j := int64(0); j < n; j++ {
			parent := lca.up[i-1][j]
			if parent == -1 {
				lca.up[i][j] = -1
			} else {
				lca.up[i][j] = lca.up[i-1][parent]
			}
		}
	}
	return lca
}

func (lca *LCA) dfs(v, h int64) {
	lca.lvl[v] = h
	for _, u := range lca.g[v] {
		lca.dfs(u, h+1)
	}
}

func (lca *LCA) getParent(v, needUp int64) int64 {
	for i := lca.N - 1; i >= 0; i-- {
		if lca.up[i][v] != -1 && lca.lvl[v]-lca.lvl[lca.up[i][v]] <= needUp {
			needUp -= lca.lvl[v] - lca.lvl[lca.up[i][v]]
			v = lca.up[i][v]
		}
	}
	if needUp != 0 {
		return -1
	}
	return v
}

func (lca *LCA) getLCA(a, b int64) int64 {
	if lca.lvl[a] > lca.lvl[b] {
		del := lca.lvl[a] - lca.lvl[b]
		a = lca.getParent(a, del)
	}
	if lca.lvl[a] < lca.lvl[b] {
		del := lca.lvl[b] - lca.lvl[a]
		b = lca.getParent(b, del)
	}
	if a == b {
		return a
	}
	for i := lca.N - 1; i >= 0; i-- {
		if lca.up[i][a] != lca.up[i][b] {
			a = lca.up[i][a]
			b = lca.up[i][b]
		}
	}
	return lca.up[0][a]
}

func (lca *LCA) getLvl(v int64) int64 {
	return lca.lvl[v]
}

type Node struct {
	a, del int64
	l, r   int64
	lca    *LCA
	lChildren, rChildren *Node
}

func NewNode(l, r int64, arr []int64, lca *LCA) *Node {
	node := &Node{l: l, r: r, lca: lca}
	if l == r {
		node.a = -1
		node.del = arr[l]
	} else {
		mid := (l + r) / 2
		node.lChildren = NewNode(l, mid, arr, lca)
		node.rChildren = NewNode(mid+1, r, arr, lca)
		len1 := mid - l + 1
		len2 := r - mid
		p := node.merge(node.lChildren.getValue(), node.rChildren.getValue(), len1, len2)
		node.a = p.first
		node.del = p.second
	}
	return node
}

func (node *Node) merge(x, y Pair, len1, len2 int64) Pair {
	if len1 > 2 && len2 > 2 {
		a, b, c, d := x.first, x.second, y.first, y.second
		ac := node.lca.getLCA(a, c)
		acb := node.lca.getLCA(ac, b)
		acd := node.lca.getLCA(ac, d)
		if node.lca.getLvl(acb) > node.lca.getLvl(acd) {
			return Pair{acb, d}
		}
		return Pair{acd, b}
	}
	if len1 == 0 {
		return y
	}
	if len2 == 0 {
		return x
	}
	a, b, c, d := x.first, x.second, y.first, y.second

	if len1 == 1 && len2 == 1 {
		if node.lca.getLvl(b) > node.lca.getLvl(d) {
			return Pair{b, d}
		}
		return Pair{d, b}
	}

	if len1 == 1 {
		if len2 == 2 {
			bc := node.lca.getLCA(b, c)
			bd := node.lca.getLCA(b, d)
			cd := node.lca.getLCA(c, d)
			lbc := node.lca.getLvl(bc)
			lbd := node.lca.getLvl(bd)
			lcd := node.lca.getLvl(cd)
			if lbc > lbd && lbc > lcd {
				return Pair{bc, d}
			}
			if lbd > lcd {
				return Pair{bd, c}
			}
			return Pair{cd, b}
		}
		bc := node.lca.getLCA(b, c)
		cd := node.lca.getLCA(c, d)
		lbc := node.lca.getLvl(bc)
		lcd := node.lca.getLvl(cd)
		if lbc > lcd {
			return Pair{bc, d}
		}
		return Pair{cd, b}
	}
	if len2 == 1 {
		if len1 == 2 {
			ab := node.lca.getLCA(a, b)
			ad := node.lca.getLCA(a, d)
			bd := node.lca.getLCA(b, d)
			lab := node.lca.getLvl(ab)
			lad := node.lca.getLvl(ad)
			lbd := node.lca.getLvl(bd)
			if lab > lad && lab > lbd {
				return Pair{ab, d}
			}
			if lad > lbd {
				return Pair{ad, b}
			}
			return Pair{bd, a}
		}
		ab := node.lca.getLCA(b, a)
		ad := node.lca.getLCA(a, d)
		lab := node.lca.getLvl(ab)
		lad := node.lca.getLvl(ad)
		if lab > lad {
			return Pair{ab, d}
		}
		return Pair{ad, b}
	}
	if len1 == 2 && len2 > 2 {
		abc := node.lca.getLCA(a, node.lca.getLCA(b, c))
		acd := node.lca.getLCA(a, node.lca.getLCA(c, d))
		bcd := node.lca.getLCA(b, node.lca.getLCA(c, d))
		labc := node.lca.getLvl(abc)
		lacd := node.lca.getLvl(acd)
		lbcd := node.lca.getLvl(bcd)
		ans := max(labc, max(lacd, lbcd))
		if labc == ans {
			return Pair{abc, d}
		}
		if lacd == ans {
			return Pair{acd, b}
		}
		return Pair{bcd, a}
	}
	if len2 == 2 && len1 > 2 {
		abc := node.lca.getLCA(a, node.lca.getLCA(b, c))
		abd := node.lca.getLCA(a, node.lca.getLCA(b, d))
		acd := node.lca.getLCA(a, node.lca.getLCA(c, d))
		labc := node.lca.getLvl(abc)
		labd := node.lca.getLvl(abd)
		lacd := node.lca.getLvl(acd)
		ans := max(labc, max(labd, lacd))
		if labc == ans {
			return Pair{abc, d}
		}
		if labd == ans {
			return Pair{abd, c}
		}
		return Pair{acd, b}
	}

	abc := node.lca.getLCA(a, node.lca.getLCA(b, c))
	abd := node.lca.getLCA(a, node.lca.getLCA(b, d))
	acd := node.lca.getLCA(a, node.lca.getLCA(c, d))
	bcd := node.lca.getLCA(b, node.lca.getLCA(c, d))

	labc := node.lca.getLvl(abc)
	labd := node.lca.getLvl(abd)
	lacd := node.lca.getLvl(acd)
	lbcd := node.lca.getLvl(bcd)
	ans := max(labc, max(labd, max(lacd, lbcd)))
	if labc == ans {
		return Pair{abc, d}
	}
	if labd == ans {
		return Pair{abd, c}
	}
	if lacd == ans {
		return Pair{acd, b}
	}
	if lbcd == ans {
		return Pair{bcd, a}
	}
	return Pair{-1, -1}
}

func (node *Node) getValue() Pair {
	return Pair{node.a, node.del}
}

func (node *Node) getValueRange(left, right int64) Pair {
	if node.l == left && node.r == right {
		return node.getValue()
	}
	mid := (node.l + node.r) / 2
	var p1, p2 Pair
	len1, len2 := int64(0), int64(0)
	p1 = p2 = Pair{-1, -1}
	if left <= mid {
		p1 = node.lChildren.getValueRange(left, min(right, mid))
		len1 = min(right, mid) - left + 1
	}
	if right > mid {
		p2 = node.rChildren.getValueRange(max(mid+1, left), right)
		len2 = right - max(mid+1, left) + 1
	}
	return node.merge(p1, p2, len1, len2)
}

func (node *Node) update(l, r, value int64) {
	if l == node.l && r == node.r {
		return
	}
	mid := (node.l + node.r) / 2
	if l <= mid {
		node.lChildren.update(l, min(mid, r), value)
	}
	if r > mid {
		node.rChildren.update(max(mid+1, l), r, value)
	}
}

func gcd(a, b int64) int64 {
	if a < b {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func nok(a, b int64) int64 {
	nnod := gcd(a, b)
	return a / nnod * b
}

func divup(a, b int64) int64 {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

type SNM struct {
	parent []int64
	size   []int64
}

func NewSNM(n int64) *SNM {
	parent := make([]int64, n)
	size := make([]int64, n)
	for i := int64(0); i < n; i++ {
		parent[i] = i
		size[i] = 1
	}
	return &SNM{parent: parent, size: size}
}

func (snm *SNM) findSet(v int64) int64 {
	if v == snm.parent[v] {
		return v
	}
	ans := snm.findSet(snm.parent[v])
	snm.parent[v] = ans
	return ans
}

func (snm *SNM) unionSets(a, b int64) {
	a = snm.findSet(a)
	b = snm.findSet(b)
	if a != b {
		snm.parent[b] = a
		snm.size[a] += snm.size[b]
	}
}

func (snm *SNM) getSize(v int64) int64 {
	v = snm.findSet(v)
	return snm.size[v]
}

func check(day int64, pr map[Pair]int64, arr []int64) bool {
	bue := []Pair{}
	sum := int64(0)
	for i := int64(0); i < int64(len(arr)); i++ {
		p := Pair{i, -day}
		if _, exists := pr[p]; !exists {
			sum += arr[i]
		} else {
			bue = append(bue, Pair{-pr[p], i})
		}
	}
	sort.Slice(bue, func(i, j int) bool {
		return bue[i].first < bue[j].first
	})

	moneyDelete := int64(0)
	for _, p := range bue {
		money := p.first - moneyDelete
		need := arr[p.second]
		if need <= money {
			moneyDelete += need
		} else {
			moneyDelete += money
			sum += need - money
		}
	}
	return (moneyDelete + sum*2 <= day)
}

func main() {
	var n, m int64
	fmt.Scan(&n, &m)
	arr := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Scan(&arr[i])
	}
	pr := make(map[Pair]int64)
	for i := int64(0); i < m; i++ {
		var a, b int64
		fmt.Scan(&a, &b)
		pr[Pair{b - 1, -a}] = -1
	}
	l, r := int64(0), int64(1e6)
	for l < r {
		mid := (l + r) / 2
		if check(mid, pr, arr) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	fmt.Println(l)
}
