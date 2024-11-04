package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
)

const (
	id8  = "id8"
	id10 = "id10"
	YES  = "YES"
	NO   = "NO"
	MOD  = 998244353
	RADIX = 10
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner(r *os.File) *MyScanner {
	return &MyScanner{scanner: bufio.NewScanner(r)}
}

func (ms *MyScanner) nextInt() int {
	ms.scanner.Scan()
	var x int
	fmt.Sscanf(ms.scanner.Text(), "%d", &x)
	return x
}

func (ms *MyScanner) nextPairs(n int) (u, v []int) {
	u = make([]int, n)
	v = make([]int, n)
	for i := 0; i < n; i++ {
		u[i] = ms.nextInt()
		v[i] = ms.nextInt()
	}
	return
}

type id4 struct {
	writer *bufio.Writer
}

func NewId4(w *os.File) *id4 {
	return &id4{writer: bufio.NewWriter(w)}
}

func (out *id4) println(ans interface{}) {
	fmt.Fprintln(out.writer, ans)
}

func (out *id4) close() {
	out.writer.Flush()
}

func main() {
	sol := &id3{}
	sol.run()
}

type id3 struct {
	out *id4
	in  *MyScanner
}

func (sol *id3) initIO(id7 bool) {
	if os.Getenv("ONLINE_JUDGE") == "" && id7 {
		file, err := os.Open("input.txt")
		if err != nil {
			panic(err)
		}
		sol.in = NewMyScanner(file)

		fileOut, err := os.Create("output.txt")
		if err != nil {
			panic(err)
		}
		sol.out = NewId4(fileOut)
	} else {
		sol.in = NewMyScanner(os.Stdin)
		sol.out = NewId4(os.Stdout)
	}
}

func (sol *id3) run() {
	isDebug := false
	id7 := true
	id1 := false

	sol.initIO(id7)

	t := 1
	if id1 {
		t = sol.in.nextInt()
	}

	for i := 1; i <= t; i++ {
		n := sol.in.nextInt()
		m := sol.in.nextInt()
		u, v := sol.in.nextPairs(m)

		if isDebug {
			sol.out.println(fmt.Sprintf("Test %d", i))
		}

		ans := sol.solve2(u, v, n)
		sol.out.println(ans)

		if isDebug {
			sol.out.close()
		}
	}

	sol.out.close()
}

func (sol *id3) validate(u, v []int, n int) {
	set := make(map[string]struct{})
	cmp := make([][]int, RADIX)
	for i := range cmp {
		cmp[i] = make([]int, RADIX)
	}

	for i := 0; i < len(u); i++ {
		small := min(u[i], v[i])
		large := max(u[i], v[i])
		cmp[small][large] = -1
		cmp[large][small] = 1
	}

	comp := func(i, j int) bool {
		return cmp[i][j] < 0
	}

	curr := big.NewInt(0)
	limit := new(big.Int).Exp(big.NewInt(RADIX), big.NewInt(int64(n)), nil)
	sb := make([]byte, n)

	for curr.Cmp(limit) < 0 {
		s := curr.Text(RADIX)
		padding := n - len(s)
		for i := 0; i < padding; i++ {
			sb[i] = '0'
		}
		copy(sb[padding:], s)

		arr := make([]int, n)
		for i := 0; i < n; i++ {
			arr[i] = int(sb[i] - '0')
		}
		sort.Slice(arr, func(i, j int) bool {
			return comp(arr[i], arr[j])
		})

		set[string(sb)] = struct{}{}
		curr.Add(curr, big.NewInt(1))
	}

	sol.out.println(len(set))
}

func (sol *id3) solve2(u, v []int, n int) int64 {
	dp := make([]int64, 1<<RADIX)
	for j := 0; j < RADIX; j++ {
		dp[1<<j] = 1
	}

	cmp := make([][]int, RADIX)
	for i := range cmp {
		cmp[i] = make([]int, RADIX)
	}

	m := len(u)
	for i := 0; i < m; i++ {
		small := min(u[i], v[i])
		larger := max(u[i], v[i])
		cmp[small][larger] = -1
		cmp[larger][small] = 1
	}

	isValid := make([][]bool, 1<<RADIX)
	mapMask := make([][]int, 1<<RADIX)
	for mask := 0; mask < 1<<RADIX; mask++ {
		isValid[mask] = make([]bool, RADIX)
		mapMask[mask] = make([]int, RADIX)
		for j := 0; j < RADIX; j++ {
			ok := true
			next := 1 << j
			for k := 0; k < RADIX; k++ {
				if (1<<k&mask) == 0 {
					continue
				}
				if cmp[j][k] == 0 {
					continue
				} else if cmp[j][k] == -1 {
					next |= 1 << k
				} else {
					ok = false
				}
			}
			isValid[mask][j] = ok
			mapMask[mask][j] = next
		}
	}

	for i := n - 2; i >= 0; i-- {
		next := make([]int64, 1<<RADIX)
		for mask := 0; mask < 1<<RADIX; mask++ {
			for j := 0; j < RADIX; j++ {
				if !isValid[mask][j] {
					continue
				}
				mask2 := mapMask[mask][j]
				val := next[mask2] + dp[mask]
				if val >= MOD {
					val -= MOD
				}
				next[mask2] = val
			}
		}
		dp = next
	}

	sum := int64(0)
	for mask := 0; mask < 1<<RADIX; mask++ {
		sum += dp[mask]
	}

	return sum % MOD
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
