package main

import (
	"fmt"
	"math"
)

const (
	mdlo    = 1000000007
	maxERR  = 0.00000064
	maxBits = 40
	pi      = 3.1415926535897932384626433832795
	INF     = 999999999999
)

type edge struct {
	first  int
	second int
}

type adjList []int

type treeInfo struct {
	depth               int
	longestPath         int
	startPointOflongestpath int
	deepestNode         int
	included            bool
}

var (
	mInv       [41]int64
	fact       [41]int64
	factInv    [41]int64
	N, M       int64
	levels     [15]int
	nextPoint  [15]int
	firstDigit [15]int
	inTree     [123466]bool
	visited    [123466]bool
	tree       [123466]adjList
	startPoints []int
	graph      [15]adjList
	primes     []uint64
	dp         [22][22]int64
	par        [45]int64
)

func getmoduloInv(n int64) int64 {
	if n == 1 {
		return 1
	}
	if mInv[n] > 0 {
		return mInv[n]
	}
	m := (-1 * mdlo) / n
	m += mdlo
	m *= getmoduloInv(mdlo % n)
	mInv[n] = (m % mdlo)
	return mInv[n]
}

func getAncestor(val int64) int64 {
	if par[val] != val {
		par[val] = getAncestor(par[val])
	}
	return par[val]
}

func unify(a, b int64) bool {
	para, parb := getAncestor(a), getAncestor(b)
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

func get_primes(max uint64) []uint64 {
	sieve := make([]byte, max/8+1)

	m := (max / 8) + 1
	for i := uint64(0); i < m; i++ {
		sieve[i] = 255
	}
	for x := uint64(2); x <= max; x++ {
		if sieve[x/8]&(0x01<<(x%8)) != 0 {
			primes = append(primes, x)

			for j := uint64(2 * x); j <= max; j += x {
				sieve[j/8] &= ^(0x01 << (j % 8))
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
		v1, v2 := getdp(N, K-1), getdp(N-1, K-1)
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

func getLcm(a, b int64) int64 {
	c := a / gcd(a, b)
	return b * c
}

func dfs(startPoint int) treeInfo {
	var tInfo treeInfo
	maxDepth := 0
	maxDepth2 := 0
	deepestNode := 1234567
	deepestNode2 := 1234567
	longestPath := 0
	longestPathStart := 1234567
	status := inTree[startPoint]
	visited[startPoint] = true
	for i := 0; i < len(tree[startPoint]); i++ {
		if !visited[tree[startPoint][i]] {
			childInfo := dfs(tree[startPoint][i])
			if childInfo.included {
				status = true
				if maxDepth < childInfo.depth || (maxDepth == childInfo.depth && deepestNode > childInfo.deepestNode) {
					maxDepth2 = maxDepth
					deepestNode2 = deepestNode
					deepestNode = childInfo.deepestNode
					maxDepth = childInfo.depth
				} else if maxDepth2 < childInfo.depth || (maxDepth2 == childInfo.depth && deepestNode2 > childInfo.deepestNode) {
					maxDepth2 = childInfo.depth
					deepestNode2 = childInfo.deepestNode
				}
				if childInfo.longestPath > longestPath || (childInfo.longestPath == longestPath && longestPathStart < childInfo.startPointOflongestpath) {
					longestPath = childInfo.longestPath
					longestPathStart = childInfo.startPointOflongestpath
				}
			}
		}
	}
	tInfo.included = status
	if maxDepth == 0 {
		tInfo.deepestNode = startPoint
		tInfo.depth = 1
		tInfo.longestPath = 1
		tInfo.startPointOflongestpath = startPoint
		return tInfo
	}
	if maxDepth+maxDepth2+1 > longestPath || (maxDepth+maxDepth2+1 == longestPath && longestPathStart > min(deepestNode, deepestNode2)) {
		longestPathStart = min(deepestNode, deepestNode2)
		longestPath = maxDepth + maxDepth2 + 1
	}
	if maxDepth2 == maxDepth && deepestNode2 < deepestNode {
		deepestNode = deepestNode2
	}
	tInfo.deepestNode = deepestNode
	tInfo.depth = maxDepth + 1
	tInfo.longestPath = longestPath
	tInfo.startPointOflongestpath = longestPathStart
	inTree[startPoint] = status
	return tInfo
}

func getVal(num int64) int64 {
	ans := int64(1)
	for i := int64(1); i < num; i++ {
		ans += (num / gcd(num, i))
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
	rotateDist1 := math.Cos((pi+C)/2) - math.Cos((pi-C)/2)
	rotateDist2 := math.Cos((3*pi+C)/2) - math.Cos((3*pi-C)/2)
	return dist + r*math.Max(rotateDist1, rotateDist2)
}

func printMaxMin(C float64) {
	maxVal := -1.0
	maxAngle := 0.0
	minVal := 1.0
	minAngle := 0.0
	for th := 0.00; th < 360.1; th += 0.01 {
		angle := ((th + C) * pi) / 180.0
		val := math.Cos(angle) - math.Cos((th * pi) / 180.0)
		if val > maxVal {
			maxVal = val
			maxAngle = th
		}
		if val < minVal {
			minVal = val
			minAngle = th
		}
	}
	fmt.Println("max", maxVal, "angle", maxAngle)
	fmt.Println("min", minVal, "angle", minAngle)
}

func main() {
	var test_cases int64 = 1
	var C, D, A, L, R, rep, round, rem, ans, num int64
	var st, en, minerr, r, v float64
	fmt.Scan(&test_cases, &r, &v)

	for T := int64(0); T < test_cases; T++ {
		fmt.Scanf("%f %f", &st, &en)
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
