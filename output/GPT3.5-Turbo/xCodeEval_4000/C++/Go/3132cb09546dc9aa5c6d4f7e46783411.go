package main

import (
	"fmt"
	"math"
	"sort"
)

type pi struct {
	first, second int64
}

type spi map[pi]bool

type vi []int64

type vvi [][]int64

type vpi []pi

type vvpi [][]pi

type vppi []ppi

type vb []bool

type vvb [][]bool

type mii map[int64]int64

type si map[int64]bool

type msi map[int64]int64

type mspi map[pi]int64

type vsi []si

type V []interface{}

type VV []V

type Mi map[int64]interface{}

type MMi map[int64]Mi

type LCA struct {
	N, n   int64
	up     vvi
	g      vvi
	lvl    vi
}

type Node struct {
	a, del int64
	l, r   int64
	lChildren, rChildren *Node
	lca *LCA
}

var zero = pi{-1, -1}

func cinArr(arr vi) {
	for i := 0; i < len(arr); i++ {
		fmt.Scan(&arr[i])
	}
}

func cinMatr(matr vvi) {
	n := int64(len(matr))
	m := int64(len(matr[0]))
	for i := int64(0); i < n; i++ {
		for j := int64(0); j < m; j++ {
			fmt.Scan(&matr[i][j])
		}
	}
}

var xx = []int64{1, -1, 0, 0}
var yy = []int64{0, 0, 1, -1}

var prim, prims vi

func er() {
	n := int64(1e6)
	prim = make(vi, n+1)
	for i := int64(0); i <= n; i++ {
		prim[i] = i
	}
	for i := int64(2); i <= n; i++ {
		if prim[i] == i {
			prims = append(prims, i)
			for j := i * i; j <= n; j += i {
				if prim[j] == j {
					prim[j] = i
				}
			}
		}
	}
}

func NewLCA(parent vi) *LCA {
	n := int64(len(parent))
	N := int64(math.Log2(float64(n))) + 1
	g := make(vvi, n)
	lvl := make(vi, n)
	core := int64(-1)
	for i := int64(0); i < n; i++ {
		if parent[i] != -1 {
			g[parent[i]] = append(g[parent[i]], i)
		} else {
			core = i
		}
	}
	dfs(core, 0, g, lvl)
	up := make(vvi, N)
	up[0] = parent
	for i := int64(1); i < N; i++ {
		for j := int64(0); j < n; j++ {
			parent := up[i-1][j]
			if parent == -1 {
				up[i][j] = -1
			} else {
				up[i][j] = up[i-1][parent]
			}
		}
	}
	return &LCA{
		N:   N,
		n:   n,
		up:  up,
		g:   g,
		lvl: lvl,
	}
}

func dfs(v, h int64, g vvi, lvl vi) {
	lvl[v] = h
	for _, u := range g[v] {
		dfs(u, h+1, g, lvl)
	}
}

func (lca *LCA) getParent(v, needUp int64) int64 {
	for i := lca.N - 1; i >= 0; i-- {
		if lca.up[i][v] != -1 && lvl[v]-lvl[lca.up[i][v]] <= needUp {
			needUp -= lvl[v] - lvl[lca.up[i][v]]
			v = lca.up[i][v]
		}
	}
	if needUp != 0 {
		return -1
	} else {
		return v
	}
}

func (lca *LCA) getLCA(a, b int64) int64 {
	if lvl[a] > lvl[b] {
		del := int64(math.Abs(float64(lvl[a] - lvl[b])))
		a = lca.getParent(a, del)
	}
	if lvl[a] < lvl[b] {
		del := int64(math.Abs(float64(lvl[a] - lvl[b])))
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
	return lvl[v]
}

func merge(x, y pi, len1, len2 int64, lca *LCA) pi {
	if len1 > 2 && len2 > 2 {
		a := x.first
		b := x.second
		c := y.first
		d := y.second

		ac := lca.getLCA(a, c)
		acb := lca.getLCA(ac, b)
		acd := lca.getLCA(ac, d)
		if lca.getLvl(acb) > lca.getLvl(acd) {
			return pi{acb, d}
		} else {
			return pi{acd, b}
		}
	}
	if len1 == 0 {
		return y
	}
	if len2 == 0 {
		return x
	}
	a := x.first
	b := x.second
	c := y.first
	d := y.second

	if len1 == 1 && len2 == 1 {
		if lca.getLvl(b) > lca.getLvl(d) {
			return pi{b, d}
		} else {
			return pi{d, b}
		}
	}

	if len1 == 1 {
		if len2 == 2 {
			bc := lca.getLCA(b, c)
			bd := lca.getLCA(b, d)
			cd := lca.getLCA(c, d)
			lbc := lca.getLvl(bc)
			lbd := lca.getLvl(bd)
			lcd := lca.getLvl(cd)
			if lbc > lbd && lbc > lcd {
				return pi{bc, d}
			}
			if lbd > lcd {
				return pi{bd, c}
			}
			return pi{cd, b}
		}

		bc := lca.getLCA(b, c)
		cd := lca.getLCA(c, d)
		lbc := lca.getLvl(bc)
		lcd := lca.getLvl(cd)
		if lbc > lcd {
			return pi{bc, d}
		} else {
			return pi{cd, b}
		}
	}
	if len2 == 1 {
		if len1 == 2 {
			ab := lca.getLCA(a, b)
			ad := lca.getLCA(a, d)
			bd := lca.getLCA(b, d)
			lab := lca.getLvl(ab)
			lad := lca.getLvl(ad)
			lbd := lca.getLvl(bd)
			if lab > lad && lab > lbd {
				return pi{ab, d}
			}
			if lad > lbd {
				return pi{ad, b}
			}
			return pi{bd, a}
		}

		ab := lca.getLCA(b, a)
		ad := lca.getLCA(a, d)
		lab := lca.getLvl(ab)
		lad := lca.getLvl(ad)
		if lab > lad {
			return pi{ab, d}
		} else {
			return pi{ad, b}
		}
	}
	if len1 == 2 && len2 > 2 {
		abc := lca.getLCA(a, lca.getLCA(b, c))
		acd := lca.getLCA(a, lca.getLCA(c, d))
		bcd := lca.getLCA(b, lca.getLCA(c, d))

		labc := lca.getLvl(abc)
		lacd := lca.getLvl(acd)
		lbcd := lca.getLvl(bcd)
		ans := max(labc, lacd, lbcd)
		if labc == ans {
			return pi{abc, d}
		}
		if lacd == ans {
			return pi{acd, b}
		}
		if lbcd == ans {
			return pi{bcd, a}
		}
	}
	if len2 == 2 && len1 > 2 {
		abc := lca.getLCA(a, lca.getLCA(b, c))
		abd := lca.getLCA(a, lca.getLCA(b, d))
		acd := lca.getLCA(a, lca.getLCA(c, d))

		labc := lca.getLvl(abc)
		labd := lca.getLvl(abd)
		lacd := lca.getLvl(acd)
		ans := max(labc, labd, lacd)
		if labc == ans {
			return pi{abc, d}
		}
		if labd == ans {
			return pi{abd, c}
		}
		if lacd == ans {
			return pi{acd, b}
		}
	}

	abc := lca.getLCA(a, lca.getLCA(b, c))
	abd := lca.getLCA(a, lca.getLCA(b, d))
	acd := lca.getLCA(a, lca.getLCA(c, d))
	bcd := lca.getLCA(b, lca.getLCA(c, d))

	labc := lca.getLvl(abc)
	labd := lca.getLvl(abd)
	lacd := lca.getLvl(acd)
	lbcd := lca.getLvl(bcd)
	ans := max(labc, labd, lacd, lbcd)
	if labc == ans {
		return pi{abc, d}
	}
	if labd == ans {
		return pi{abd, c}
	}
	if lacd == ans {
		return pi{acd, b}
	}
	if lbcd == ans {
		return pi{bcd, a}
	}

	return zero
}

func max(nums ...int64) int64 {
	maxNum := nums[0]
	for _, num := range nums {
		if num > maxNum {
			maxNum = num
		}
	}
	return maxNum
}

func NewNode(l, r int64, arr vi, lca *LCA) *Node {
	if l == r {
		return &Node{
			a:   -1,
			del: arr[l],
			l:   l,
			r:   r,
			lca: lca,
		}
	} else {
		mid := (l + r) / 2
		lChildren := NewNode(l, mid, arr, lca)
		rChildren := NewNode(mid+1, r, arr, lca)
		len1 := mid - l + 1
		len2 := r - mid
		p := merge(lChildren.getValue(), rChildren.getValue(), len1, len2, lca)
		return &Node{
			a:          p.first,
			del:        p.second,
			l:          l,
			r:          r,
			lChildren: lChildren,
			rChildren: rChildren,
			lca:       lca,
		}
	}
}

func (node *Node) getValue() pi {
	return pi{node.a, node.del}
}

func (node *Node) getValueRange(left, right int64) pi {
	if node.l == left && node.r == right {
		return node.getValue()
	}
	mid := (node.l + node.r) / 2
	var p1, p2 pi
	len1, len2 := int64(0), int64(0)
	p1, p2 = zero, zero
	if left <= mid {
		p1 = node.lChildren.getValueRange(left, min(right, mid))
		len1 = min(right, mid) - left + 1
	}
	if right > mid {
		p2 = node.rChildren.getValueRange(max(mid+1, left), right)
		len2 = right - max(mid+1, left) + 1
	}
	p := merge(p1, p2, len1, len2, node.lca)
	return p
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

func gcdExtended(a, b int64) (int64, int64, int64) {
	if a == 0 {
		return 0, 1, b
	}
	x1, y1, d := gcdExtended(b%a, a)
	x := y1 - (b/a)*x1
	y := x1
	return x, y, d
}

func nok(a, b int64) int64 {
	nnod := gcd(a, b)
	ans := a / nnod * b
	return ans
}

func divup(a, b int64) int64 {
	if a%b == 0 {
		return a / b
	} else {
		return a/b + 1
	}
}

func chec(day int64, pr spi, arr vi) bool {
	var bue vpi
	sum := int64(0)
	for i := int64(0); i < int64(len(arr)); i++ {
		p := pi{i, -day}
		it, ok := pr[p]
		if !ok {
			sum += arr[i]
		} else {
			bue = append(bue, pi{-it, i})
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
	return moneyDelete+sum*2 <= day
}

func main() {
	var n, m int64
	fmt.Scan(&n, &m)
	arr := make(vi, n)
	cinArr(arr)
	pr := make(spi)
	for i := int64(0); i < m; i++ {
		var a, b int64
		fmt.Scan(&a, &b)
		pr[pi{b - 1, -a}] = true
	}
	l := int64(0)
	r := int64(1e18)
	for l < r {
		mid := (l + r) / 2
		if chec(mid, pr, arr) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	fmt.Println(l)
}
