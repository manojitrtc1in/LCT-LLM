package main

import (
	"fmt"
	"math"
	"os"
)

const maxN = 123466
const maxM = 41
const pi = 3.141592653589793

var mInv [maxM]int64
var fact [maxM]int64
var factInv [maxM]int64
var N, M int64
var levels [15]int64
var nextPoint [15]int64
var firstDigit [15]int64
var inTree [maxN]bool
var visited [maxN]bool
var tree [maxN][]int64
var startPoints []int64
var primes []uint64
var dp [22][22]int64

type treeInfo struct {
	depth                     int64
	id6                       int64
	startPointOflongestpath  int64
	id3                       int64
	included                  bool
}

func id4(n int64) int64 {
	if n == 1 {
		return 1
	}
	if mInv[n] > 0 {
		return mInv[n]
	}
	m := (-1 * mdlo) / n
	m += mdlo
	m *= id4(mdlo % n)
	mInv[n] = m % mdlo
	return mInv[n]
}

var par [45]int64

func getAncestor(val int64) int64 {
	if par[val] != val {
		par[val] = getAncestor(par[val])
	}
	return par[val]
}

func unify(a, b int64) bool {
	para := getAncestor(a)
	parb := getAncestor(b)
	if para == parb {
		return false
	}
	if para < parb {
		par[parb] = para
	} else {
		par[para] = parb
	}
	return true
}

func id1(max uint64) []uint64 {
	sieve := make([]byte, (max/8)+1)
	m := (max / 8) + 1
	for i := 0; i < int(m); i++ {
		sieve[i] = 255
	}
	for x := uint64(2); x <= max; x++ {
		if sieve[x/8]&(0x01<<(x%8)) != 0 {
			primes = append(primes, x)
			for j := 2 * x; j <= max; j += x {
				sieve[j/8] &^= (0x01 << (j % 8))
			}
		}
	}
	return primes
}

func getdp(N, K int64) int64 {
	if dp[N][K] == 0 {
		if K == 1 {
			dp[N][K] = N
			return dp[N][K]
		}
		v1 := getdp(N, K-1)
		v2 := getdp(N-1, K-1)
		dp[N][K] = (v1 * v2) / (v1 - v2)
	}
	return dp[N][K]
}

func isPrime(N int64) bool {
	if N == 1 {
		return false
	}
	if N < 4 {
		return true
	}
	for i := int64(2); i*i < N; i++ {
		if N%i == 0 {
			return false
		}
	}
	return true
}

func gcd(a, b int64) int64 {
	var c int64
	if a > b {
		c = a
		a = b
		b = c
	}
	if a == 0 {
		return b
	}
	c = b % a
	for c > 0 {
		b = a
		a = c
		c = b % a
	}
	return a
}

func id5(a, b int64) int64 {
	c := a / gcd(a, b)
	return b * c
}

func dfs(startPoint int64) treeInfo {
	var tInfo treeInfo
	maxDepth := int64(0)
	id7 := int64(0)
	id3 := int64(1234567)
	id9 := int64(1234567)
	id6 := int64(0)
	id10 := int64(1234567)
	status := inTree[startPoint]
	visited[startPoint] = true
	for i := int64(0); i < int64(len(tree[startPoint])); i++ {
		if !visited[tree[startPoint][i]] {
			childInfo := dfs(tree[startPoint][i])
			if childInfo.included {
				status = true
				if maxDepth < childInfo.depth || (maxDepth == childInfo.depth && id3 > childInfo.id3) {
					id7 = maxDepth
					id9 = id3
					id3 = childInfo.id3
					maxDepth = childInfo.depth
				} else if id7 < childInfo.depth || (id7 == childInfo.depth && id9 > childInfo.id3) {
					id7 = childInfo.depth
					id9 = childInfo.id3
				}
				if childInfo.id6 > id6 || (childInfo.id6 == id6 && id10 < childInfo.startPointOflongestpath) {
					id6 = childInfo.id6
					id10 = childInfo.startPointOflongestpath
				}
			}
		}
	}
	tInfo.included = status
	if maxDepth == 0 {
		tInfo.id3 = startPoint
		tInfo.depth = 1
		tInfo.id6 = 1
		tInfo.startPointOflongestpath = startPoint
		return tInfo
	}
	if maxDepth+id7+1 > id6 || (maxDepth+id7+1 == id6 && id10 > min(id3, id9)) {
		id10 = min(id3, id9)
		id6 = maxDepth + id7 + 1
	}
	if id7 == maxDepth && id9 < id3 {
		id3 = id9
	}
	tInfo.id3 = id3
	tInfo.depth = maxDepth + 1
	tInfo.id6 = id6
	tInfo.startPointOflongestpath = id10
	inTree[startPoint] = status
	return tInfo
}

func getVal(num int64) int64 {
	ans := int64(1)
	for i := int64(1); i < num; i++ {
		ans += num / gcd(num, i)
	}
	return ans
}

func buildDp() {
	for i := int64(1); i < 22; i++ {
		for j := int64(1); j <= i; j++ {
			dp[i][j] = getdp(i, j)
			fmt.Print(dp[i][j], " ")
		}
		fmt.Println()
	}
}

func maxDist(t, v, r float64) float64 {
	dist := t * v
	C := t * v / r
	id0 := math.Cos((pi+C)/2) - math.Cos((pi-C)/2)
	id8 := math.Cos((3*pi+C)/2) - math.Cos((3*pi-C)/2)
	return dist + r*math.Max(id0, id8)
}

func id2(C float64) {
	maxVal := -1.0
	maxAngle := 0.0
	minVal := 1.0
	minAngle := 0.0
	for th := 0.0; th < 360.1; th += 0.01 {
		angle := (th + C) * pi / 180.0
		val := math.Cos(angle) - math.Cos((th*pi)/180.0)
		if val > maxVal {
			maxVal = val
			maxAngle = th
		}
		if val < minVal {
			minVal = val
			minAngle = th
		}
	}
	fmt.Printf("max %f angle %f\n", maxVal, maxAngle)
	fmt.Printf("min %f angle %f\n", minVal, minAngle)
}

func main() {
	var testCases int64 = 1
	var C, D, A, L, R, rep, round, rem, ans, num int64
	var st, en, minerr, r, v float64
	minerr = 0.00000001
	fmt.Scan(&testCases, &r, &v)
	fmt.Printf("%.15f\n", 0.0)

	for T := int64(0); T < testCases; T++ {
		fmt.Scan(&st, &en)
		dist := en - st
		low := (dist - 2*r) / v
		high := (dist + 2*r) / v
		var mid float64
		for low+minerr < high && low+low*minerr < high {
			mid = (low + high) / 2
			if maxDist(mid, v, r) > dist {
				high = mid
			} else {
				low = mid
			}
		}
		fmt.Printf("%f\n", (low+high)/2)
	}
}
