package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner() *MyScanner {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	return &MyScanner{scanner}
}

func (m *MyScanner) Next() string {
	m.scanner.Scan()
	return m.scanner.Text()
}

func (m *MyScanner) NextInt() int {
	num, _ := strconv.Atoi(m.Next())
	return num
}

func (m *MyScanner) NextPairs(n int) (u, v []int) {
	u = make([]int, n)
	v = make([]int, n)
	for i := 0; i < n; i++ {
		u[i] = m.NextInt()
		v[i] = m.NextInt()
	}
	return u, v
}

type id4 struct {
	writer *bufio.Writer
}

func NewId4() *id4 {
	writer := bufio.NewWriter(os.Stdout)
	return &id4{writer}
}

func (i *id4) Println(a ...interface{}) {
	fmt.Fprintln(i.writer, a...)
}

func (i *id4) Close() {
	i.writer.Flush()
}

type id3 struct {
	out *id4
	in  *MyScanner
}

const (
	id8  = "id8"
	id10 = "id10"
	YES  = "YES"
	NO   = "NO"
	MOD  = 998244353
)

func main() {
	sol := &id3{}
	sol.run()
}

func (sol *id3) run() {
	isDebug := false
	id7 := true
	id1 := false

	sol.initIO(id7)

	t := 1
	if id1 {
		t = sol.in.NextInt()
	}

	for i := 1; i <= t; i++ {
		n := sol.in.NextInt()
		m := sol.in.NextInt()
		u, v := sol.in.NextPairs(m)

		if isDebug {
			sol.out.Println("Test", i)
		}

		ans := sol.solve2(u, v, n)
		sol.out.Println(ans)

		if isDebug {
			sol.out.Flush()
		}
	}

	sol.in.Close()
	sol.out.Close()
}

func (sol *id3) initIO(id7 bool) {
	if os.Getenv("ONLINE_JUDGE") == "" && id7 {
		file, _ := os.Open("input.txt")
		defer file.Close()
		sol.in = NewMyScanner(file)
		file, _ = os.Create("output.txt")
		defer file.Close()
		sol.out = NewId4(file)
	} else {
		sol.in = NewMyScanner()
		sol.out = NewId4()
	}
}

func (sol *id3) validate(u, v []int, n int) {
	set := make(map[string]bool)
	cmp := make([][]int, RADIX)
	for i := 0; i < RADIX; i++ {
		cmp[i] = make([]int, RADIX)
	}

	for i := 0; i < RADIX; i++ {
		for j := 0; j < RADIX; j++ {
			cmp[i][j] = 0
		}
	}

	for i := 0; i < len(u); i++ {
		small := min(u[i], v[i])
		large := max(u[i], v[i])
		cmp[small][large] = -1
		cmp[large][small] = 1
	}

	comp := func(o1, o2 int) int {
		return cmp[o1-'0'][o2-'0']
	}

	curr := 0
	limit := pow(RADIX, n)
	sb := make([]byte, n)
	for curr < limit {
		s := strconv.FormatInt(int64(curr), RADIX)
		padding := n - len(s)
		for i := 0; i < padding; i++ {
			sb[i] = '0'
		}
		for i := 0; i < len(s); i++ {
			sb[padding+i] = s[i]
		}
		arr := make([]byte, n)
		for i := 0; i < n; i++ {
			arr[i] = sb[i]
		}
		sort.Slice(arr, comp)

		set[string(arr)] = true
		curr++
	}

	sol.out.Println(len(set))
	sol.out.Println(set)
}

const RADIX = 10

func (sol *id3) solve2(u, v []int, n int) int64 {
	dp := make([]int64, 1<<RADIX)
	for j := 0; j < RADIX; j++ {
		dp[1<<j] = 1
	}

	cmp := make([][]int, RADIX)
	for i := 0; i < RADIX; i++ {
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
				if 1<<k&mask == 0 {
					continue
				}

				if cmp[j][k] == 0 {
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
				next[mask2] = val % MOD
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

func (sol *id3) solve(u, v []int, n int) int64 {
	m := len(u)

	num := make([]int64, RADIX)
	for i := 0; i < RADIX; i++ {
		num[i] = 1
	}

	multipliers := make([][]int64, RADIX)
	for i := 0; i < RADIX; i++ {
		multipliers[i] = make([]int64, RADIX)
		for j := 0; j < RADIX; j++ {
			multipliers[i][j] = 1
		}
	}

	for i := 0; i < m; i++ {
		min := min(u[i], v[i])
		max := max(u[i], v[i])
		multipliers[max][min] = 0
	}

	for i := 1; i < n; i++ {
		num2 := make([]int64, RADIX)
		for j := 0; j < RADIX; j++ {
			for k := 0; k < RADIX; k++ {
				num2[j] += num[k] * multipliers[j][k] % MOD
			}
			num2[j] %= MOD
		}
		num = num2
	}

	sum := int64(0)
	for i := 0; i < RADIX; i++ {
		sum += num[i]
	}

	return sum % MOD
}

func pow(a, k int, p int64) int64 {
	m := int64(k)
	ans := int64(1)
	curr := int64(a)

	for m > 0 {
		if m&1 == 1 {
			ans *= curr
			ans %= p
		}
		m >>= 1
		curr *= curr
		curr %= p
	}
	return ans
}

func inverse(a int, p int64) int64 {
	return pow(a, int(p-2), p)
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

func main() {
	sol := &id3{}
	sol.run()
}
