package main

import (
	"fmt"
	"math"
)

const (
	maxq = 5010
	maxn = 100100
)

type segmentNode struct {
	be, en   int
	maxv, add, sum int
}

type segmentTree struct {
	l    int
	tree []segmentNode
}

type q struct {
	l, r, maxv, deep int
	p               float64
}

var (
	son [][]int
	arr []int
	fa  []int
	dp  [][]pair
	n, nq, be, en int
	sgt segmentTree
)

type pair struct {
	first  float64
	second int
}

func main() {
	fmt.Scan(&n, &nq)
	arr = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	que := make([]q, nq)
	for i := 0; i < nq; i++ {
		fmt.Scan(&que[i].l, &que[i].r, &que[i].p)
		que[i].l--
		que[i].r--
	}
	fa = make([]int, nq)
	for i := 0; i < nq; i++ {
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
			if j != i && que[j].r-que[j].l == que[i].r-que[i].l {
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
	son = make([][]int, nq+1)
	for i := 0; i < nq; i++ {
		if fa[i] != -1 {
			son[fa[i]] = append(son[fa[i]], i)
		} else {
			fa[i] = nq
			son[nq] = append(son[nq], i)
		}
	}
	que = append(que, q{l: 0, r: n - 1})
	sgt.build(1, 0, n-1, 0, arr)

	dfs(nq)
	dfsdp(nq)
	ans := 0.0
	for i := 0; i < len(dp[nq]); i++ {
		ans += dp[nq][i].first * float64(dp[nq][i].second)
	}
	fmt.Printf("%.10f\n", ans)
}

func (sgt *segmentTree) build(no, l, r, orig int, a []int) {
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
		sgt.tree[no].add = 0
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
	sgt.tree[no].maxv = max1(sgt.tree[sgt.gleft(no)].maxv, sgt.tree[sgt.gright(no)].maxv)
}

func (sgt *segmentTree) gleft(no int) int {
	return no << 1
}

func (sgt *segmentTree) gright(no int) int {
	return (no << 1) + 1
}

func (sgt *segmentTree) gfa(no int) int {
	return no >> 1
}

func (sgt *segmentTree) relax(no int) {
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

func (sgt *segmentTree) down(l, r, no, ranadd int) {
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
	sgt.tree[no].maxv = max1(sgt.tree[sgt.gleft(no)].maxv, sgt.tree[sgt.gright(no)].maxv)
}

func (sgt *segmentTree) getmax(l, r, no int) int {
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
		ans = max1(ans, sgt.getmax(l, r, sgt.gleft(no)))
	}
	if r >= mid+1 && l <= sgt.tree[no].en {
		ans = max1(ans, sgt.getmax(l, r, sgt.gright(no)))
	}
	return ans
}

func dfs(no, deep int) {
	que[no].maxv = sgt.getmax(que[no].l, que[no].r, 1)
	be = max1(be, que[no].maxv)
	en = max1(en, que[no].maxv+deep+1)
	que[no].deep = deep
	for i := 0; i < len(son[no]); i++ {
		dfs(son[no][i], deep+1)
	}
}

func dfsdp(no int) {
	dp[no] = append(dp[no], pair{first: 1, second: que[no].maxv})
	for i := 0; i < len(son[no]); i++ {
		rno := son[no][i]
		dfsdp(rno)
		rdp := make([]pair, 0)
		rdp1 := make([]pair, 0)
		sum1 := dp[no][0].first
		sum2 := dp[rno][0].first
		p := que[rno].p
		for link1, link2 := 0, 0; link1 < len(dp[no]) || link2 < len(dp[rno]); {
			rdp = append(rdp, pair{first: sum1 * sum2 * (1 - p), second: max1(dp[no][link1].second, dp[rno][link2].second)})
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
			if sum1*sum2 > eps {
				rdp1 = append(rdp1, pair{first: sum1 * sum2 * p, second: max1(dp[no][link1].second, dp[rno][link2].second+1)})
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
				dp[no] = append(dp[no], rdp[link1].add(rdp1[link2]))
				link2++
				link1++
			} else if rdp[link1].second < rdp1[link2].second {
				dp[no] = append(dp[no], rdp[link1])
				link1++
			}
		}
	}
}

func max1(a, b int) int {
	if b < a {
		return a
	}
	return b
}

func max1(a, b, c int) int {
	return max1(max1(a, b), c)
}

func max1(a, b, c, d int) int {
	return max1(max1(a, b, c), d)
}

func max1(a, b, c, d, e int) int {
	return max1(max1(a, b, c, d), e)
}

func (p pair) add(q pair) pair {
	return pair{first: p.first + q.first, second: p.second}
}

func (sgt *segmentTree) pow(n, m, mod int) int {
	if m < 0 {
		return 0
	}
	ans := 1
	k := n
	for m > 0 {
		if m&1 == 1 {
			ans *= k
			if mod != 0 {
				ans %= mod
			}
		}
		k *= k
		if mod != 0 {
			k %= mod
		}
		m >>= 1
	}
	return ans
}

func (sgt *segmentTree) bitnum(nValue int) int {
	return int(bitnum(uint(nValue)))
}

func bitnum(nValue uint) int {
	return int(popcount(nValue) + popcount(nValue>>32))
}

func popcount(nValue uint) uint {
	nValue = (nValue & 0x55555555) + ((nValue >> 1) & 0x55555555)
	nValue = (nValue & 0x33333333) + ((nValue >> 2) & 0x33333333)
	nValue = (nValue & 0x0F0F0F0F) + ((nValue >> 4) & 0x0F0F0F0F)
	nValue = (nValue & 0x00FF00FF) + ((nValue >> 8) & 0x00FF00FF)
	nValue = (nValue & 0x0000FFFF) + ((nValue >> 16) & 0x0000FFFF)
	return nValue
}

func (sgt *segmentTree) bitmaxl(a uint) int {
	if a == 0 {
		return 0
	}
	return 32 - int(clz(a))
}

func clz(a uint) uint {
	a |= a >> 1
	a |= a >> 2
	a |= a >> 4
	a |= a >> 8
	a |= a >> 16
	return 32 - popcount(a)
}

func (sgt *segmentTree) lowb(num int) int {
	return num & (-num)
}

func (sgt *segmentTree) jud(a, b float64) int {
	if math.Abs(a) < eps && math.Abs(b) < eps {
		return 0
	} else if math.Abs(a-b)/math.Abs(a) < eps {
		return 0
	}
	if a < b {
		return -1
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, fSmall, fLb bool) int {
	be := 0
	en := len(a) - 1
	if a[0] <= a[len(a)-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(a[mid], float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(a[mid], float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(a[be], float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(a[be], float64(val)) == -1 {
			be++
		}
	} else {
		if fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(a[mid], float64(val)) != -1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(a[mid], float64(val)) != 1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if !fSmall && sgt.jud(a[be], float64(val)) == -1 {
			be--
		}
		if fSmall && sgt.jud(a[be], float64(val)) == 1 {
			be++
		}
	}
	return be
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) abs1(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func (sgt *segmentTree) min1(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func (sgt *segmentTree) min1(a, b, c int) int {
	return sgt.min1(sgt.min1(a, b), c)
}

func (sgt *segmentTree) min1(a, b, c, d int) int {
	return sgt.min1(sgt.min1(a, b, c), d)
}

func (sgt *segmentTree) min1(a, b, c, d, e int) int {
	return sgt.min1(sgt.min1(a, b, c, d), e)
}

func (sgt *segmentTree) max1(a, b int) int {
	if b < a {
		return a
	}
	return b
}

func (sgt *segmentTree) max1(a, b, c int) int {
	return sgt.max1(sgt.max1(a, b), c)
}

func (sgt *segmentTree) max1(a, b, c, d int) int {
	return sgt.max1(sgt.max1(a, b, c), d)
}

func (sgt *segmentTree) max1(a, b, c, d, e int) int {
	return sgt.max1(sgt.max1(a, b, c, d), e)
}

func (sgt *segmentTree) pow(n, m, mod int) int {
	if m < 0 {
		return 0
	}
	ans := 1
	k := n
	for m > 0 {
		if m&1 == 1 {
			ans *= k
			if mod != 0 {
				ans %= mod
			}
		}
		k *= k
		if mod != 0 {
			k %= mod
		}
		m >>= 1
	}
	return ans
}

func (sgt *segmentTree) add(a *int, b int, mod int) {
	if mod == -1 {
		mod = MOD
	}
	*a += b
	for *a >= mod {
		*a -= mod
	}
	for *a < 0 {
		*a += mod
	}
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) jud(a, b float64) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, na int, fSmall, fLb bool) int {
	be := 0
	en := na - 1
	if a[0] <= a[na-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be++
		}
	} else {
		if fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be--
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be++
		}
	}
	return be
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) abs1(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func (sgt *segmentTree) min1(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func (sgt *segmentTree) min1(a, b, c int) int {
	return sgt.min1(sgt.min1(a, b), c)
}

func (sgt *segmentTree) min1(a, b, c, d int) int {
	return sgt.min1(sgt.min1(a, b, c), d)
}

func (sgt *segmentTree) min1(a, b, c, d, e int) int {
	return sgt.min1(sgt.min1(a, b, c, d), e)
}

func (sgt *segmentTree) max1(a, b int) int {
	if b < a {
		return a
	}
	return b
}

func (sgt *segmentTree) max1(a, b, c int) int {
	return sgt.max1(sgt.max1(a, b), c)
}

func (sgt *segmentTree) max1(a, b, c, d int) int {
	return sgt.max1(sgt.max1(a, b, c), d)
}

func (sgt *segmentTree) max1(a, b, c, d, e int) int {
	return sgt.max1(sgt.max1(a, b, c, d), e)
}

func (sgt *segmentTree) pow(n, m, mod int) int {
	if m < 0 {
		return 0
	}
	ans := 1
	k := n
	for m > 0 {
		if m&1 == 1 {
			ans *= k
			if mod != 0 {
				ans %= mod
			}
		}
		k *= k
		if mod != 0 {
			k %= mod
		}
		m >>= 1
	}
	return ans
}

func (sgt *segmentTree) add(a *int, b int, mod int) {
	if mod == -1 {
		mod = MOD
	}
	*a += b
	for *a >= mod {
		*a -= mod
	}
	for *a < 0 {
		*a += mod
	}
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) jud(a, b float64) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, na int, fSmall, fLb bool) int {
	be := 0
	en := na - 1
	if a[0] <= a[na-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be++
		}
	} else {
		if fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be--
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be++
		}
	}
	return be
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) jud(a, b float64) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, na int, fSmall, fLb bool) int {
	be := 0
	en := na - 1
	if a[0] <= a[na-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be++
		}
	} else {
		if fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be--
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be++
		}
	}
	return be
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) jud(a, b float64) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, na int, fSmall, fLb bool) int {
	be := 0
	en := na - 1
	if a[0] <= a[na-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be++
		}
	} else {
		if fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be--
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be++
		}
	}
	return be
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) jud(a, b float64) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, na int, fSmall, fLb bool) int {
	be := 0
	en := na - 1
	if a[0] <= a[na-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be++
		}
	} else {
		if fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be--
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be++
		}
	}
	return be
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) jud(a, b float64) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, na int, fSmall, fLb bool) int {
	be := 0
	en := na - 1
	if a[0] <= a[na-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be++
		}
	} else {
		if fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be--
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be++
		}
	}
	return be
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) jud(a, b float64) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, na int, fSmall, fLb bool) int {
	be := 0
	en := na - 1
	if a[0] <= a[na-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be++
		}
	} else {
		if fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be--
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be++
		}
	}
	return be
}

func (sgt *segmentTree) output1(arr []pair) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v|%v ", arr[i].first, arr[i].second)
	}
	fmt.Println()
}

func (sgt *segmentTree) output2(arr [][]pair) {
	for i := 0; i < len(arr); i++ {
		sgt.output1(arr[i])
	}
}

func (sgt *segmentTree) jud(a, b float64) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func (sgt *segmentTree) find(val int, a []int, na int, fSmall, fLb bool) int {
	be := 0
	en := na - 1
	if a[0] <= a[na-1] {
		if !fLb {
			for be < en {
				mid := (be + en + 1) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != 1 {
					be = mid
				} else {
					en = mid - 1
				}
			}
		} else {
			for be < en {
				mid := (be + en) / 2
				if sgt.jud(float64(a[mid]), float64(val)) != -1 {
					en = mid
				} else {
					be = mid + 1
				}
			}
		}
		if fSmall && sgt.jud(float64(a[be]), float64(val)) == 1 {
			be--
		}
		if !fSmall && sgt.jud(float64(a[be]), float64(val)) == -1 {
			be++
