package main

import (
	"fmt"
	"math"
)

const (
	maxq = 5010
	maxn = 100100
	eps  = 1e-10
)

type SegmentNode struct {
	be, en   int
	maxv, add, sum int
}

type SegmentTree struct {
	l    int
	tree [maxn * 4]SegmentNode
}

func (sgt *SegmentTree) gleft(no int) int {
	return no << 1
}

func (sgt *SegmentTree) gright(no int) int {
	return (no << 1) + 1
}

func (sgt *SegmentTree) gfa(no int) int {
	return no >> 1
}

func (sgt *SegmentTree) build(no, l, r int, orig int, a []int) {
	if l > r {
		r = l
	}
	if l == r {
		sgt.tree[no].be = l
		sgt.tree[no].en = l
		sgt.tree[no].add = 0
		if a == nil {
			sgt.tree[no].maxv = orig
		} else {
			sgt.tree[no].maxv = a[l]
		}
		sgt.tree[no].sum = sgt.tree[no].maxv
		return
	}
	sgt.tree[no].be = l
	sgt.tree[no].en = r
	mid := (l + r) / 2
	sgt.build(sgt.gleft(no), l, mid, orig, a)
	sgt.build(sgt.gright(no), mid+1, r, orig, a)
	sgt.tree[no].sum = sgt.tree[sgt.gleft(no)].sum + sgt.tree[sgt.gright(no)].sum
	sgt.tree[no].add = 0
	sgt.tree[no].maxv = max(sgt.tree[sgt.gleft(no)].maxv, sgt.tree[sgt.gright(no)].maxv)
}

func (sgt *SegmentTree) relax(no int) {
	le := sgt.gleft(no)
	ri := sgt.gright(no)
	sgt.tree[le].add += sgt.tree[no].add
	sgt.tree[le].sum += sgt.tree[no].add * (sgt.tree[le].en - sgt.tree[le].be + 1)
	sgt.tree[le].maxv += sgt.tree[no].add
	sgt.tree[ri].add += sgt.tree[no].add
	sgt.tree[ri].sum += sgt.tree[no].add * (sgt.tree[ri].en - sgt.tree[ri].be + 1)
	sgt.tree[ri].maxv += sgt.tree[no].add
	sgt.tree[no].add = 0
}

func (sgt *SegmentTree) down(l, r, no int, ranadd int) {
	if l <= sgt.tree[no].be && r >= sgt.tree[no].en {
		sgt.tree[no].add += ranadd
		sgt.tree[no].sum += ranadd * (sgt.tree[no].en - sgt.tree[no].be + 1)
		sgt.tree[no].maxv += ranadd
		return
	}
	if sgt.tree[no].add != 0 && sgt.tree[no].be != sgt.tree[no].en {
		sgt.relax(no)
	}
	mid := (sgt.tree[no].be + sgt.tree[no].en) >> 1
	if r >= sgt.tree[no].be && l <= mid {
		sgt.down(l, r, sgt.gleft(no), ranadd)
	}
	if r >= mid+1 && l <= sgt.tree[no].en {
		sgt.down(l, r, sgt.gright(no), ranadd)
	}
	sgt.tree[no].sum = sgt.tree[sgt.gleft(no)].sum + sgt.tree[sgt.gright(no)].sum
	sgt.tree[no].maxv = max(sgt.tree[sgt.gleft(no)].maxv, sgt.tree[sgt.gright(no)].maxv)
}

func (sgt *SegmentTree) getmax(l, r, no int) int {
	if l > r {
		return 0
	}
	if l <= sgt.tree[no].be && r >= sgt.tree[no].en {
		return sgt.tree[no].maxv
	}
	if sgt.tree[no].add != 0 && sgt.tree[no].be != sgt.tree[no].en {
		sgt.relax(no)
	}
	ans := 0
	mid := (sgt.tree[no].be + sgt.tree[no].en) >> 1
	if r >= sgt.tree[no].be && l <= mid {
		ans = max(ans, sgt.getmax(l, r, sgt.gleft(no)))
	}
	if r >= mid+1 && l <= sgt.tree[no].en {
		ans = max(ans, sgt.getmax(l, r, sgt.gright(no)))
	}
	return ans
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

type Query struct {
	l, r, maxv, deep int
	p                float64
}

var (
	son  [maxq][]int
	arr  [maxn]int
	fa   [maxq]int
	dp   [maxq][][2]float64
	n, nq, be, en int
	sgt SegmentTree
	que [maxq]Query
)

func dfs(no, deep int) {
	que[no].maxv = sgt.getmax(que[no].l, que[no].r, 1)
	be = max(be, que[no].maxv)
	en = max(en, que[no].maxv+deep+1)
	que[no].deep = deep
	for _, child := range son[no] {
		dfs(child, deep+1)
	}
}

func dfsdp(no int) {
	dp[no] = append(dp[no], [2]float64{1, float64(que[no].maxv)})
	for _, rno := range son[no] {
		dfsdp(rno)
		var rdp, id1 [][2]float64
		sum1 := dp[no][0][0]
		sum2 := dp[rno][0][0]
		p := que[rno].p
		for link1, link2 := 0, 0; link1 < len(dp[no]) || link2 < len(dp[rno]); {
			rdp = append(rdp, [2]float64{sum1 * sum2 * (1 - p), math.Max(dp[no][link1][1], dp[rno][link2][1])})
			if link1 == len(dp[no])-1 {
				link2++
				if link2 == len(dp[rno]) {
					break
				}
				sum2 += dp[rno][link2][0]
			} else if link2 == len(dp[rno])-1 {
				link1++
				sum1 += dp[no][link1][0]
			} else if dp[no][link1+1][1] > dp[rno][link2+1][1] {
				link2++
				sum2 += dp[rno][link2][0]
			} else {
				link1++
				sum1 += dp[no][link1][0]
			}
		}
		for i := len(rdp) - 1; i > 0; i-- {
			rdp[i][0] -= rdp[i-1][0]
		}
		rsz := 1
		for i := 1; i < len(rdp); i++ {
			if rdp[i][1] == rdp[i-1][1] {
				rdp[rsz-1][0] += rdp[i][0]
			} else {
				rdp[rsz] = rdp[i]
				rsz++
			}
		}
		rdp = rdp[:rsz]

		sum1 = dp[no][0][0]
		sum2 = dp[rno][0][0]
		for link1, link2 := 0, 0; link1 < len(dp[no]) || link2 < len(dp[rno]); {
			if sum1*sum2 > eps {
				id1 = append(id1, [2]float64{sum1 * sum2 * p, math.Max(dp[no][link1][1], dp[rno][link2][1]+1)})
			}
			if link1 == len(dp[no])-1 {
				link2++
				if link2 == len(dp[rno]) {
					break
				}
				sum2 += dp[rno][link2][0]
			} else if link2 == len(dp[rno])-1 {
				link1++
				sum1 += dp[no][link1][0]
			} else if dp[no][link1+1][1] > dp[rno][link2+1][1]+1 {
				link2++
				sum2 += dp[rno][link2][0]
			} else {
				link1++
				sum1 += dp[no][link1][0]
			}
		}
		for i := len(id1) - 1; i > 0; i-- {
			id1[i][0] -= id1[i-1][0]
		}
		rsz = 1
		for i := 1; i < len(id1); i++ {
			if id1[i][1] == id1[i-1][1] {
				id1[rsz-1][0] += id1[i][0]
			} else {
				id1[rsz] = id1[i]
				rsz++
			}
		}
		id1 = id1[:rsz]

		dp[no] = nil
		for link1, link2 := 0, 0; link1 < len(rdp) || link2 < len(id1); {
			if link2 == len(id1) {
				dp[no] = append(dp[no], rdp[link1])
				link1++
			} else if link1 == len(rdp) {
				dp[no] = append(dp[no], id1[link2])
				link2++
			} else if rdp[link1][1] > id1[link2][1] {
				dp[no] = append(dp[no], id1[link2])
				link2++
			} else if rdp[link1][1] == id1[link2][1] {
				dp[no] = append(dp[no], [2]float64{rdp[link1][0] + id1[link2][0], rdp[link1][1]})
				link2++
				link1++
			} else {
				dp[no] = append(dp[no], rdp[link1])
				link1++
			}
		}
	}
}

func main() {
	var id0 = 256 << 20
	_ = make([]byte, id0)

	fmt.Scan(&n, &nq)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	for i := 0; i < nq; i++ {
		fmt.Scan(&que[i].l, &que[i].r, &que[i].p)
		que[i].l--
		que[i].r--
	}
	for i := range fa {
		fa[i] = -1
	}
	for i := 0; i < nq; i++ {
		for j := 0; j < i; j++ {
			if j != i {
				if que[j].r-que[j].l == que[i].r-que[i].l && que[j].r == que[i].r {
					fa[i] = j
				}
			}
		}
		if fa[i] != -1 {
			continue
		}
		for j := 0; j < nq; j++ {
			if j != i {
				if que[j].r-que[j].l == que[i].r-que[i].l {
					continue
				}
				if que[j].l <= que[i].l && que[j].r >= que[i].r {
					if fa[i] == -1 {
						fa[i] = j
						continue
					}
					if que[j].r-que[j].l <= que[fa[i]].r-que[fa[i]].l {
						fa[i] = j
						continue
					}
				}
			}
		}
	}
	for i := 0; i < nq; i++ {
		if fa[i] != -1 {
			son[fa[i]] = append(son[fa[i]], i)
		} else {
			fa[i] = nq
			son[nq] = append(son[nq], i)
		}
	}
	que[nq].l = 0
	que[nq].r = n - 1
	sgt.build(1, 0, n-1, 0, arr[:])

	dfs(nq, 0)
	dfsdp(nq)
	ans := 0.0
	for i := 0; i < len(dp[nq]); i++ {
		ans += dp[nq][i][0] * dp[nq][i][1]
	}
	fmt.Printf("%.10f\n", ans)
}
