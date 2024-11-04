package main

import (
	"fmt"
	"math"
)

const (
	maxq = 5010
	maxn = 100100
	MOD  = 1000000007
)

type SegmentNode struct {
	be, en   int
	maxv, add, sum int
}

type SegmentTree struct {
	l    int
	tree [4 * maxn]SegmentNode
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
	sgt.build(2*no, l, mid, orig, a)
	sgt.build(2*no+1, mid+1, r, orig, a)
	sgt.tree[no].sum = sgt.tree[2*no].sum + sgt.tree[2*no+1].sum
	sgt.tree[no].add = 0
	sgt.tree[no].maxv = max(sgt.tree[2*no].maxv, sgt.tree[2*no+1].maxv)
}

func (sgt *SegmentTree) relax(no int) {
	le := 2 * no
	ri := 2*no + 1
	sgt.tree[le].add += sgt.tree[no].add
	sgt.tree[le].sum += sgt.tree[no].add * (sgt.tree[le].en - sgt.tree[le].be + 1)
	sgt.tree[le].maxv += sgt.tree[no].add
	sgt.tree[ri].add += sgt.tree[no].add
	sgt.tree[ri].sum += sgt.tree[no].add * (sgt.tree[ri].en - sgt.tree[ri].be + 1)
	sgt.tree[ri].maxv += sgt.tree[no].add
	sgt.tree[no].add = 0
}

func (sgt *SegmentTree) down(l, r, no, ranadd int) {
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
		sgt.down(l, r, 2*no, ranadd)
	}
	if r >= mid+1 && l <= sgt.tree[no].en {
		sgt.down(l, r, 2*no+1, ranadd)
	}
	sgt.tree[no].sum = sgt.tree[2*no].sum + sgt.tree[2*no+1].sum
	sgt.tree[no].maxv = max(sgt.tree[2*no].maxv, sgt.tree[2*no+1].maxv)
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
		ans = max(ans, sgt.getmax(l, r, 2*no))
	}
	if r >= mid+1 && l <= sgt.tree[no].en {
		ans = max(ans, sgt.getmax(l, r, 2*no+1))
	}
	return ans
}

var (
	sgt SegmentTree
	son  [maxq][]int
	que  [maxq]struct {
		l, r, maxv, deep int
		p                float64
	}
	dp  [maxq][]struct {
		first  float64
		second int
	}
	arr  [maxn]int
	fa   [maxq]int
	n, nq, be, en int
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

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
	dp[no] = append(dp[no], struct {
		first  float64
		second int
	}{1, que[no].maxv})
	for _, rno := range son[no] {
		dfsdp(rno)
		var rdp, rdp1 []struct {
			first  float64
			second int
		}
			sum1 := dp[no][0].first
			sum2 := dp[rno][0].first
			p := que[rno].p
			for link1, link2 := 0, 0; link1 < len(dp[no]) || link2 < len(dp[rno]); {
				rdp = append(rdp, struct {
					first  float64
					second int
				}{sum1 * sum2 * (1 - p), max(dp[no][link1].second, dp[rno][link2].second)})
				if link1 == len(dp[no])-1 {
					link2++
					if link2 == len(dp[rno]) {
						break
					}
					sum2 += dp[rno][link2].first
				} else if link2 == len(dp[rno])-1 {
					link1++
					sum1 += dp[no][link1].first
				} else if dp[no][link1+1].second > dp[rno][link2+1].second {
					link2++
					sum2 += dp[rno][link2].first
				} else {
					link1++
					sum1 += dp[no][link1].first
				}
			}
			for i := len(rdp) - 1; i > 0; i-- {
				rdp[i].first -= rdp[i-1].first
			}
			rsz := 1
			for i := 1; i < len(rdp); i++ {
				if rdp[i].second == rdp[i-1].second {
					rdp[rsz-1].first += rdp[i].first
				} else {
					rdp[rsz] = rdp[i]
					rsz++
				}
			}
			rdp = rdp[:rsz]

			sum1 = dp[no][0].first
			sum2 = dp[rno][0].first
			for link1, link2 := 0, 0; link1 < len(dp[no]) || link2 < len(dp[rno]); {
				if sum1*sum2 > 1e-10 {
					rdp1 = append(rdp1, struct {
						first  float64
						second int
					}{sum1 * sum2 * p, max(dp[no][link1].second, dp[rno][link2].second + 1)})
				}
				if link1 == len(dp[no])-1 {
					link2++
					if link2 == len(dp[rno]) {
						break
					}
					sum2 += dp[rno][link2].first
				} else if link2 == len(dp[rno])-1 {
					link1++
					sum1 += dp[no][link1].first
				} else if dp[no][link1+1].second > dp[rno][link2+1].second+1 {
					link2++
					sum2 += dp[rno][link2].first
				} else {
					link1++
					sum1 += dp[no][link1].first
				}
			}
			for i := len(rdp1) - 1; i > 0; i-- {
				rdp1[i].first -= rdp1[i-1].first
			}
			rsz = 1
			for i := 1; i < len(rdp1); i++ {
				if rdp1[i].second == rdp1[i-1].second {
					rdp1[rsz-1].first += rdp1[i].first
				} else {
					rdp1[rsz] = rdp1[i]
					rsz++
				}
			}
			rdp1 = rdp1[:rsz]

			dp[no] = nil
			for link1, link2 := 0, 0; link1 < len(rdp) || link2 < len(rdp1); {
				if link2 == len(rdp1) {
					dp[no] = append(dp[no], rdp[link1])
					link1++
				} else if link1 == len(rdp) {
					dp[no] = append(dp[no], rdp1[link2])
					link2++
				} else if rdp[link1].second > rdp1[link2].second {
					dp[no] = append(dp[no], rdp1[link2])
					link2++
				} else if rdp[link1].second == rdp1[link2].second {
					dp[no] = append(dp[no], struct {
						first  float64
						second int
					}{rdp[link1].first + rdp1[link2].first, rdp[link1].second})
					link2++
					link1++
				} else {
					dp[no] = append(dp[no], rdp[link1])
					link1++
				}
			}
		}
	}
}

func main() {
	var input int
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
			if j != i && que[j].r-que[j].l == que[i].r-que[i].l && que[j].r == que[i].r {
				fa[i] = j
			}
		}
		if fa[i] != -1 {
			continue
		}
		for j := 0; j < nq; j++ {
			if j != i && que[j].r-que[j].l != que[i].r-que[i].l && que[j].l <= que[i].l && que[j].r >= que[i].r {
				if fa[i] == -1 {
					fa[i] = j
				} else if que[j].r-que[j].l <= que[fa[i]].r-que[fa[i]].l {
					fa[i] = j
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
	for _, d := range dp[nq] {
		ans += d.first * float64(d.second)
	}
	fmt.Printf("%.10f\n", ans)
}
