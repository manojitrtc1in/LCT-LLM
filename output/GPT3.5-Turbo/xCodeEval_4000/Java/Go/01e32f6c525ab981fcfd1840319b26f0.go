package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var out *bufio.Writer

func init() {
	out = bufio.NewWriter(os.Stdout)
}

type FastReader struct {
	br *bufio.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin)}
}

func (r *FastReader) Next() string {
	for {
		str, err := r.br.ReadString('\n')
		if err != nil {
			panic(err)
		}
		str = strings.TrimSpace(str)
		if str != "" {
			return str
		}
	}
}

func (r *FastReader) NextInt() int {
	num, err := strconv.Atoi(r.Next())
	if err != nil {
		panic(err)
	}
	return num
}

func (r *FastReader) NextLong() int64 {
	num, err := strconv.ParseInt(r.Next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return num
}

func (r *FastReader) NextDouble() float64 {
	num, err := strconv.ParseFloat(r.Next(), 64)
	if err != nil {
		panic(err)
	}
	return num
}

func (r *FastReader) NextLine() string {
	str, err := r.br.ReadString('\n')
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
	return (n & (n - 1)) == 0
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
	return x == y
}

func IsPossibleTriangle(a, b, c int) bool {
	return a+b > c && c+b > a && a+c > b
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
	return Lcm(temp, c, d)
}

func Lcm(a, b int) int {
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

	LongestPrefixSuffix(lps, q, n+m+1)

	for i := m + 1; i < n+m+1; i++ {
		if lps[i] == m {
			list = append(list, i-2*m)
		}
	}

	return list
}

func LongestPrefixSuffix(lps []int, str string, n int) {
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

func GeneratePermutation(str string, start, end int) {
	if start == end-1 {
		fmt.Println(str)
	} else {
		for i := start; i < end; i++ {
			str = SwapString(str, start, i)
			GeneratePermutation(str, start+1, end)
			str = SwapString(str, start, i)
		}
	}
}

func SwapString(a string, i, j int) string {
	b := []rune(a)
	ch := b[i]
	b[i] = b[j]
	b[j] = ch
	return string(b)
}

func EulerTotientFunction(arr []int, n int) {
	for i := 1; i <= n; i++ {
		arr[i] = i
	}

	for i := 2; i <= n; i++ {
		if arr[i] == i {
			arr[i] = i - 1

			for j := 2 * i; j <= n; j += i {
				arr[j] = (arr[j] * (i - 1)) / i
			}
		}
	}
}

func NCr(n, k int) int64 {
	ans := int64(1)

	k = min(k, n-k)

	j := 1
	for ; j <= k; j, n = j+1, n-1 {
		if n%j == 0 {
			ans *= int64(n / j)
		} else if ans%int64(j) == 0 {
			ans = ans/int64(j)*int64(n)
		} else {
			ans = (ans * int64(n)) / int64(j)
		}
	}

	return ans
}

func AllFactors(n int) []int {
	list := make([]int, 0)

	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			if i*i == n {
				list = append(list, i)
			} else {
				list = append(list, i)
				list = append(list, n/i)
			}
		}
	}

	return list
}

func AllFactorsLong(n int64) []int64 {
	list := make([]int64, 0)

	for i := int64(1); i*i <= n; i++ {
		if n%i == 0 {
			if i*i == n {
				list = append(list, i)
			} else {
				list = append(list, i)
				list = append(list, n/i)
			}
		}
	}

	return list
}

const MAXN = 10000001

var spf []int

func Sieve() {
	spf = make([]int, MAXN)

	for i := 4; i <= MAXN; i++ {
		spf[i] = i
		i++
	}

	for i := 3; i*i <= MAXN; i++ {
		if spf[i] == i {
			for j := i * i; j <= MAXN; j += i {
				if spf[j] == j {
					spf[j] = i
				}
			}
		}
	}
}

func GetFactorization(x int) []int {
	ret := make([]int, 0)
	for x != 1 {
		ret = append(ret, spf[x])
		x = x / spf[x]
	}
	return ret
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

func BinarySearchGreater(arr []int, start, end, val int) int {
	if start > end {
		return 0
	}

	mid := (start + end) / 2

	if arr[mid] <= val {
		return BinarySearchGreater(arr, mid+1, end, val)
	} else {
		return BinarySearchGreater(arr, start, mid-1, val) + end - mid + 1
	}
}

func Power(x, n int64) int64 {
	if n == 0 {
		return 1
	} else if n == 1 {
		return x
	}

	ans := int64(1)

	for n > 0 {
		if n%2 == 1 {
			ans = ans * x
		}

		n /= 2

		x = x * x
	}

	return ans
}

func PowerMod(x, n, mod int64) int64 {
	if n == 0 {
		return 1
	} else if n == 1 {
		return x
	}

	ans := int64(1)
	for n > 0 {
		if n%2 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
		n /= 2
	}
	return ans
}

func LowerBound(arr []int, k int) int {
	ans := -1

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

func UpperBound(arr []int, k int) int {
	ans := -1

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

var tree [][]int

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

func DFS(sv int, vis []bool) {
	vis[sv] = true

	for _, x := range tree[sv] {
		if !vis[x] {
			DFS(x, vis)
		}
	}
}

func Solve() {
	scanner := NewFastReader()

	var testcases int
	fmt.Scan(&testcases)

	for testcase := 1; testcase <= testcases; testcase++ {
		n := scanner.NextLong()
		a1 := scanner.NextLong()
		a2 := scanner.NextLong()
		a3 := scanner.NextLong()
		b1 := scanner.NextLong()
		b2 := scanner.NextLong()
		b3 := scanner.NextLong()

		var min int64

		if b1 >= a1+a2 {
			min = a3 - b2 - b3
		} else if b2 >= a3+a2 {
			min = a1 - b1 - b3
		} else if b3 >= a1+a3 {
			min = a2 - b2 - b1
		} else {
			min = 0
		}

		max := minInt64(a1, b2) + minInt64(a2, b3) + minInt64(a3, b1)

		fmt.Println(min, max)
	}
}

func main() {
	Solve()
	out.Flush()
}
