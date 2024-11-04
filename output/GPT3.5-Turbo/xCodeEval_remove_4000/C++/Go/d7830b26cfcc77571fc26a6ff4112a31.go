package main

import (
	"fmt"
	"math"
	"sort"
)

type adjList []int

var Trree [100]adjList
type sum struct {
	first  int64
	second int64
}
type updat struct {
	first  sum
	second int64
}
var N int64

type cnts map[int64]int64

var counts1 [30]cnts
var counts2 [30]cnts
var pwr2 [100]int64
var parent [1010]int64

func getParent(node int64) int64 {
	if parent[node] != node {
		parent[node] = getParent(parent[node])
	}
	return parent[node]
}

func unionNode(node1, node2 int64) {
	if getParent(node1) != getParent(node2) {
		parent[parent[node1]] = parent[node2]
	}
}

func id11(lim int64) {
	pwr2[0] = 1
	for i := int64(0); i < lim; i++ {
		pwr2[i+1] = pwr2[i] << 1
	}
}

func id0(pos, val int64) int64 {
	return val | pwr2[pos]
}

func id1(pos, val int64) bool {
	return (val&pwr2[pos]) > 0
}

func gcd(a, b int64) int64 {
	c := b % a
	for c > 0 {
		b = a
		a = c
		c = b % a
	}
	return a
}

var s string
var target, sticker int64
var segTree [600005]int64
var segTreeData [100005]int64
var sumSegTree [600005]int64
var sumSegTreeData [100005]int64
var minStart [2]int64
var minEnd [2]int64

func id7(b, e, node int64) {
	if b == e {
		segTree[node] = b
		return
	}
	mid := (b + e) / 2
	id7(b, mid, node*2)
	id7(mid+1, e, 1+(node*2))
	if segTreeData[segTree[node*2]] > segTreeData[segTree[1+(node*2)]] {
		segTree[node] = segTree[node*2]
	} else {
		segTree[node] = segTree[1+(2*node)]
	}
}

func id10(b, e, node int64) {
	if b == e {
		segTree[node] = b
		return
	}
	mid := (b + e) / 2
	id10(b, mid, node*2)
	id10(mid+1, e, 1+(node*2))
	if segTreeData[segTree[node*2]] > segTreeData[segTree[1+(node*2)]] {
		segTree[node] = segTree[1+(node*2)]
	} else {
		segTree[node] = segTree[(2*node)]
	}
}

func id3(b, e, node, pos, val int64) {
	if b > pos || e < pos {
		return
	}
	if b == e {
		segTreeData[pos] = val
		return
	}
	mid := (b + e) / 2
	id3(b, mid, node*2, pos, val)
	id3(mid+1, e, 1+node*2, pos, val)
	if segTreeData[segTree[node*2]] > segTreeData[segTree[1+node*2]] {
		segTree[node] = segTree[1+2*node]
	} else {
		segTree[node] = segTree[2*node]
	}
}

func getMax(qStart, qEnd, sStart, sEnd, node int64) int64 {
	if qEnd < sStart || qStart > sEnd {
		return -1
	}
	if sStart >= qStart && sEnd <= qEnd {
		return segTree[node]
	}
	sMid := (sStart + sEnd) / 2
	r1 := getMax(qStart, qEnd, sStart, sMid, 2*node)
	r2 := getMax(qStart, qEnd, sMid+1, sEnd, 1+(2*node))
	if r1 < 0 {
		return r2
	}
	if r2 < 0 || segTreeData[r1] > segTreeData[r2] {
		return r1
	}
	return r2
}

func id5(qStart, qEnd, sStart, sEnd, node int64) int64 {
	if qEnd < sStart || qStart > sEnd {
		return -1
	}
	if sStart >= qStart && sEnd <= qEnd {
		return segTree[node]
	}
	sMid := (sStart + sEnd) / 2
	r1 := id5(qStart, qEnd, sStart, sMid, 2*node)
	r2 := id5(qStart, qEnd, sMid+1, sEnd, 1+(2*node))
	if r2 < 0 {
		return r1
	}
	if r1 < 0 || segTreeData[r1] > segTreeData[r2] {
		return r2
	}
	return r1
}

func id8(b, e, node int64) {
	if b == e {
		sumSegTree[node] = sumSegTreeData[b]
		return
	}
	mid := (b + e) / 2
	id8(b, mid, node*2)
	id8(mid+1, e, 1+node*2)
	sumSegTree[node] = sumSegTree[node*2] + sumSegTree[1+(node*2)]
}

func id9(b, e, node, pos, val int64) {
	if pos < b || pos > e {
		return
	}
	if b == e {
		sumSegTree[node] = val
		sumSegTreeData[pos] = val
		return
	}
	mid := (b + e) / 2
	id9(b, mid, 2*node, pos, val)
	id9(mid+1, e, 1+2*node, pos, val)
	sumSegTree[node] = sumSegTree[node*2] + sumSegTree[1+(node*2)]
}

func id6(b, e, node, qStart, qEnd int64) int64 {
	if qStart > e || qEnd < b {
		return 0
	}
	if b >= qStart && e <= qEnd {
		return sumSegTree[node]
	}
	mid := (b + e) / 2
	return id6(b, mid, node*2, qStart, qEnd) + id6(mid+1, e, 1+2*node, qStart, qEnd)
}

func id2(a, b int64) int64 {
	c := a / gcd(a, b)
	return b * c
}

var pow10 [18]int64
var pow2 [18]int64

func getlen(num int64) int64 {
	len := int64(1)
	for num > 9 {
		num /= 10
		len++
	}
	return len
}

func test(a int64) {
	switch a {
	case 1:
		fmt.Print(1)
	case 2:
		fmt.Print(2)
	case 3:
		fmt.Print(3)
	case 4:
		fmt.Print(4)
	case 5:
		fmt.Print(5)
	default:
		fmt.Print(0)
	}
	fmt.Println()
}

type base struct{}

func (b *base) f(lable string) {
	fmt.Println(lable + ":base")
}

type derived struct {
	base
}

func (d *derived) f(lable string) {
	fmt.Println(lable + ":derived")
}

func id4(tree []adjList, node int64) {
	ancestor := make([]int64, 100)
	for i := int64(0); i < 100; i++ {
		ancestor[i] = i
	}
	// srand((unsigned)time(0));
	for i := int64(1); i < node; i++ {
		node1 := rand()
		node2 := rand()
		par1, par2 := node1, node2
		for ancestor[par1] != par1 {
			par1 = ancestor[par1]
		}
	}
}

func main() {
	var test_cases int64 = 1
	pow2[0] = 1
	for i := int64(1); i < 18; i++ {
		pow2[i] = pow2[i-1] * 2
	}

	fmt.Printf("%.10f\n", 0.0)

	for T := int64(0); T < test_cases; T++ {
		var s, t string
		var m1, m2 string
		var k, n, m, p int64
		fmt.Scan(&n, &k)
		bamboo := make([]int64, 111)
		for i := int64(0); i < n; i++ {
			fmt.Scan(&bamboo[i])
		}
		sort.Slice(bamboo, func(i, j int) bool {
			return bamboo[i] < bamboo[j]
		})
		bambooSum := make([]int64, 111)
		bambooSum[0] = bamboo[0]
		maxval := int64(0)
		for i := int64(1); i < n; i++ {
			bambooSum[i] = bamboo[i] + bambooSum[i-1]
			m := i*bamboo[i] - bambooSum[i-1]
			if m > k && maxval == 0 {
				maxval = bamboo[i]
			}
		}
		if maxval == 0 {
			remaining := k + bambooSum[n-1] - (n * bamboo[n-1])
			fmt.Println((remaining / n) + bamboo[n-1])
			return
		}
		candidatePoints := make(map[int64]bool)

		for i := int64(0); i < n; i++ {
			bambooSum[i] += k
			lim := 1 + int64(math.Sqrt(float64(bamboo[i]+1)))
			for j := int64(1); j < lim; j++ {
				r1 := bamboo[i] / j
				r2 := j
				if r1 < maxval {
					if r1*j == bamboo[i] {
						candidatePoints[r1] = true
					} else {
						candidatePoints[r1+1] = true
					}
				}
			}
		}
		lim := int64(math.Sqrt(float64(bamboo[n-1])))
		if lim > maxval {
			lim = maxval
		}
		for i := int64(1); i < lim; i++ {
			candidatePoints[i] = true
		}
		for cp := range candidatePoints {
			total := int64(0)
			var d1 int64
			flag := true
			for i := int64(0); i < n; i++ {
				d1 = (bamboo[i] + cp - 1) / cp
				total += (d1 * cp)
				if total > bambooSum[i] {
					flag = false
					break
				}
			}
			if flag {
				dv := int64(0)
				for i := int64(0); i < n; i++ {
					dv += (bamboo[i] + cp - 1) / cp
				}
				fmt.Println(cp + (bambooSum[n-1]-total)/dv)
				return
			}
		}
		fmt.Println(1)
	}
}
