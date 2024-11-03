package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var out *bufio.Writer

type FastReader struct {
	br *bufio.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin)}
}

func (fr *FastReader) Next() string {
	for {
		str, err := fr.br.ReadString('\n')
		if err != nil {
			panic(err)
		}
		str = strings.TrimSpace(str)
		if str != "" {
			return str
		}
	}
}

func (fr *FastReader) NextInt() int {
	num, err := strconv.Atoi(fr.Next())
	if err != nil {
		panic(err)
	}
	return num
}

func (fr *FastReader) NextLong() int64 {
	num, err := strconv.ParseInt(fr.Next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return num
}

func (fr *FastReader) NextDouble() float64 {
	num, err := strconv.ParseFloat(fr.Next(), 64)
	if err != nil {
		panic(err)
	}
	return num
}

func (fr *FastReader) NextLine() string {
	str, err := fr.br.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(str)
}

func CountDigit(n int64) int {
	return int(math.Floor(math.Log10(float64(n)) + 1))
}

func SumOfDigits(n int64) int {
	if n < 0 {
		return -1
	}

	sum := 0
	for n > 0 {
		sum += int(n % 10)
		n /= 10
	}

	return sum
}

func ArraySum(arr []int, start, end int) int64 {
	var ans int64
	for i := start; i <= end; i++ {
		ans += int64(arr[i])
	}
	return ans
}

func Mod(x int) int {
	if x < 0 {
		return -1 * x
	} else {
		return x
	}
}

func ModLong(x int64) int64 {
	if x < 0 {
		return -1 * x
	} else {
		return x
	}
}

func SwapArray(arr []int, start, end int) {
	for start < end {
		temp := arr[start]
		arr[start] = arr[end]
		arr[end] = temp
		start++
		end--
	}
}

func Rotate(input [][]int) [][]int {
	n := len(input)
	m := len(input[0])
	output := make([][]int, m)
	for i := 0; i < m; i++ {
		output[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			output[j][n-1-i] = input[i][j]
		}
	}
	return output
}

func CountBits(n int64) int {
	count := 0
	for n != 0 {
		count++
		n = n >> 1
	}
	return count
}

func IsPowerOfTwo(n int64) bool {
	if n == 0 {
		return false
	}

	if (n & (n - 1)) == 0 {
		return true
	} else {
		return false
	}
}

func Min(a, b, c, d int) int {
	arr := []int{a, b, c, d}
	sort.Ints(arr)
	return arr[0]
}

func Max(a, b, c, d int) int {
	arr := []int{a, b, c, d}
	sort.Ints(arr)
	return arr[3]
}

func Reverse(input string) string {
	str := ""
	for i := len(input) - 1; i >= 0; i-- {
		str += string(input[i])
	}
	return str
}

func SameParity(a, b int64) bool {
	x := a % 2
	y := b % 2
	if x == y {
		return true
	} else {
		return false
	}
}

func IsPossibleTriangle(a, b, c int) bool {
	if a+b > c && c+b > a && a+c > b {
		return true
	} else {
		return false
	}
}

func Xnor(num1, num2 int64) int64 {
	if num1 < num2 {
		temp := num1
		num1 = num2
		num2 = temp
	}
	num1 = ToggleBit(num1)
	return num1 ^ num2
}

func ToggleBit(n int64) int64 {
	if n == 0 {
		return 1
	}
	i := n
	n |= n >> 1
	n |= n >> 2
	n |= n >> 4
	n |= n >> 8
	n |= n >> 16
	return i ^ n
}

func XorOfFirstN(n int) int {
	if n%4 == 0 {
		return n
	} else if n%4 == 1 {
		return 1
	} else if n%4 == 2 {
		return n + 1
	} else {
		return 0
	}
}

func Gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return Gcd(b, a%b)
	}
}

func Lcm(a, b, c, d int) int {
	temp := Lcm(a, b)
	ans := Lcm(temp, c)
	return ans
}

func LcmTwo(a, b int) int {
	gc := Gcd(a, b)
	return (a * b) / gc
}

func IsPrime(n int64) bool {
	if n == 1 {
		return false
	}

	ans := true

	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			ans = false
			break
		}
	}

	return ans
}

func SieveOfEratosthenes() {
	sieve := 1000000
	prime := make([]bool, sieve+1)

	for i := 4; i <= sieve; i++ {
		prime[i] = true
		i++
	}

	for p := 3; p*p <= sieve; p++ {
		if prime[p] == false {
			for i := p * p; i <= sieve; i += p {
				prime[i] = true
			}
		}
	}
}

func SortD(arr []int, s, e int) {
	sort.Ints(arr[s : e+1])

	i := s
	j := e

	for i < j {
		temp := arr[i]
		arr[i] = arr[j]
		arr[j] = temp
		i++
		j--
	}
}

func CountSubarraysSumToK(arr []int64, sum int64) int64 {
	m := make(map[int64]int64)
	n := len(arr)
	prefixSum := int64(0)
	count := int64(0)

	for i := 0; i < n; i++ {
		prefixSum += arr[i]

		if sum == prefixSum {
			count++
		}

		if val, ok := m[prefixSum-sum]; ok {
			count += val
		}

		if val, ok := m[prefixSum]; ok {
			m[prefixSum] = val + 1
		} else {
			m[prefixSum] = 1
		}
	}

	return count
}

func KmpAlgorithm(str, pat string) []int {
	list := make([]int, 0)
	n := len(str)
	m := len(pat)
	q := pat + "#" + str
	lps := make([]int, n+m+1)

	LongestPefixSuffix(lps, q, n+m+1)

	for i := m + 1; i < n+m+1; i++ {
		if lps[i] == m {
			list = append(list, i-2*m)
		}
	}

	return list
}

func LongestPefixSuffix(lps []int, str string, n int) {
	lps[0] = 0

	for i := 1; i <= n-1; i++ {
		l := lps[i-1]

		for l > 0 && str[i] != str[l] {
			l = lps[l-1]
		}

		if str[i] == str[l] {
			l++
		}

		lps[i] = l
	}
}

func Knapsack(weight []int, value []int64, maxWeight int) int64 {
	n := len(value)
	dp := make([]int64, maxWeight+1)

	for i := 0; i < n; i++ {
		for j := maxWeight; j >= weight[i]; j-- {
			dp[j] = max(dp[j], value[i]+dp[j-weight[i]])
		}
	}

	return dp[maxWeight]
}

func KadanesAlgorithm(arr []int64) int64 {
	dp := make([]int64, len(arr))
	dp[0] = arr[0]
	max := dp[0]

	for i := 1; i < len(arr); i++ {
		if dp[i-1] > 0 {
			dp[i] = dp[i-1] + arr[i]
		} else {
			dp[i] = arr[i]
		}

		if dp[i] > max {
			max = dp[i]
		}
	}

	return max
}

func LowerBound(arr []int64, k int64) int64 {
	ans := int64(-1)
	start := 0
	end := len(arr) - 1

	for start <= end {
		mid := (start + end) / 2

		if arr[mid] <= k {
			ans = arr[mid]
			start = mid + 1
		} else {
			end = mid - 1
		}
	}

	return ans
}

func UpperBound(arr []int64, k int64) int64 {
	ans := int64(-1)
	start := 0
	end := len(arr) - 1

	for start <= end {
		mid := (start + end) / 2

		if arr[mid] >= k {
			ans = arr[mid]
			end = mid - 1
		} else {
			start = mid + 1
		}
	}

	return ans
}

func PrintArray(arr []int, si, ei int) {
	for i := si; i <= ei; i++ {
		fmt.Print(arr[i], " ")
	}
}

func PrintArrayln(arr []int, si, ei int) {
	for i := si; i <= ei; i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func PrintLArray(arr []int64, si, ei int) {
	for i := si; i <= ei; i++ {
		fmt.Print(arr[i], " ")
	}
}

func PrintLArrayln(arr []int64, si, ei int) {
	for i := si; i <= ei; i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func PrintTwoDArray(ans [][]int) {
	for i := 0; i < len(ans); i++ {
		for j := 0; j < len(ans[0]); j++ {
			fmt.Print(ans[i][j], " ")
		}
		fmt.Println()
	}
	fmt.Println()
}

func Merge(arr []int, l, m, r int) {
	n1 := m - l + 1
	n2 := r - m

	L := make([]int, n1)
	R := make([]int, n2)

	for i := 0; i < n1; i++ {
		L[i] = arr[l+i]
	}
	for j := 0; j < n2; j++ {
		R[j] = arr[m+1+j]
	}

	i := 0
	j := 0
	k := l

	for i < n1 && j < n2 {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
		k++
	}

	for i < n1 {
		arr[k] = L[i]
		i++
		k++
	}

	for j < n2 {
		arr[k] = R[j]
		j++
		k++
	}
}

func Sort(arr []int, l, r int) {
	if l < r {
		m := (l + r) / 2

		Sort(arr, l, m)
		Sort(arr, m+1, r)

		Merge(arr, l, m, r)
	}
}

func MergeLong(arr []int64, l, m, r int) {
	n1 := m - l + 1
	n2 := r - m

	L := make([]int64, n1)
	R := make([]int64, n2)

	for i := 0; i < n1; i++ {
		L[i] = arr[l+i]
	}
	for j := 0; j < n2; j++ {
		R[j] = arr[m+1+j]
	}

	i := 0
	j := 0
	k := l

	for i < n1 && j < n2 {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
		k++
	}

	for i < n1 {
		arr[k] = L[i]
		i++
		k++
	}

	for j < n2 {
		arr[k] = R[j]
		j++
		k++
	}
}

func SortLong(arr []int64, l, r int) {
	if l < r {
		m := (l + r) / 2

		SortLong(arr, l, m)
		SortLong(arr, m+1, r)

		MergeLong(arr, l, m, r)
	}
}

func CountNoOfNodesInSubtree(child, par int, dp []int) {
	count := 1

	for _, x := range tree[child] {
		if x == par {
			continue
		}

		CountNoOfNodesInSubtree(x, child, dp)

		count += dp[x]
	}

	dp[child] = count
}

func Depth(child, par int, dp []int, d int) {
	dp[child] = d

	for _, x := range tree[child] {
		if x == par {
			continue
		}

		Depth(x, child, dp, d+1)
	}
}

func Dfs(sv int, vis []bool) {
	vis[sv] = true

	for _, x := range tree[sv] {
		if !vis[x] {
			Dfs(x, vis)
		}
	}
}

func Solve() {
	fr := NewFastReader()
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	tree = make([][]int, 0)

	testcases := 1

	for testcase := 1; testcase <= testcases; testcase++ {
		n := fr.NextLong()

		x := n

		list := make([]int64, 0)

		for i := int64(2); i*i <= n; i++ {
			if x%i == 0 {
				for x%i == 0 {
					list = append(list, i)
					x = x / i
				}
			}
		}

		if x > 1 {
			list = append(list, x)
		}

		if n == 1 {
			fmt.Fprintln(out, 1)
			fmt.Fprintln(out, 0)
		} else if len(list) == 2 {
			fmt.Fprintln(out, 2)
		} else {
			fmt.Fprintln(out, 1)

			if len(list) == 1 {
				fmt.Fprintln(out, 0)
			} else {
				ans := list[0] * list[1]
				fmt.Fprintln(out, ans)
			}
		}

		list = make([]int64, 0)

	}

}

func main() {
	Solve()
}
