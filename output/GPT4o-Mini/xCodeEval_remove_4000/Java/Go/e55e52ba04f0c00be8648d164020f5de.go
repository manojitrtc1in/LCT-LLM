package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var out = bufio.NewWriter(os.Stdout)

type FastReader struct {
	br *bufio.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin)}
}

func (fr *FastReader) next() string {
	line, _ := fr.br.ReadString('\n')
	return strings.TrimSpace(line)
}

func (fr *FastReader) nextInt() int {
	val, _ := strconv.Atoi(fr.next())
	return val
}

func (fr *FastReader) nextLong() int64 {
	val, _ := strconv.ParseInt(fr.next(), 10, 64)
	return val
}

func countDigit(n int64) int {
	return int(math.Floor(math.Log10(float64(n)) + 1))
}

func id2(n int64) int {
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

func arraySum(arr []int, start, end int) int64 {
	var ans int64 = 0
	for i := start; i <= end; i++ {
		ans += int64(arr[i])
	}
	return ans
}

func mod(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func modLong(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func swapArray(arr []int, start, end int) {
	for start < end {
		arr[start], arr[end] = arr[end], arr[start]
		start++
		end--
	}
}

func rotate(input [][]int) [][]int {
	n := len(input)
	m := len(input[0])
	output := make([][]int, m)
	for i := range output {
		output[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			output[j][n-1-i] = input[i][j]
		}
	}
	return output
}

func countBits(n int64) int {
	count := 0
	for n != 0 {
		count++
		n >>= 1
	}
	return count
}

func id0(n int64) bool {
	if n == 0 {
		return false
	}
	return (n & (n - 1)) == 0
}

func min(a, b, c, d int) int {
	arr := []int{a, b, c, d}
	sort.Ints(arr)
	return arr[0]
}

func max(a, b, c, d int) int {
	arr := []int{a, b, c, d}
	sort.Ints(arr)
	return arr[3]
}

func reverse(input string) string {
	runes := []rune(input)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func sameParity(a, b int64) bool {
	return (a%2) == (b%2)
}

func id5(a, b, c int) bool {
	return a+b > c && c+b > a && a+c > b
}

func xnor(num1, num2 int64) int64 {
	if num1 < num2 {
		num1, num2 = num2, num1
	}
	num1 = togglebit(num1)
	return num1 ^ num2
}

func togglebit(n int64) int64 {
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

func id6(n int) int {
	if n%4 == 0 {
		return n
	} else if n%4 == 1 {
		return 1
	} else if n%4 == 2 {
		return n + 1
	}
	return 0
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func gcdLong(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcdLong(b, a%b)
}

func lcm(a, b, c, d int) int {
	temp := lcm(a, b, c)
	return lcm(temp, d)
}

func lcm(a, b, c int) int {
	temp := lcm(a, b)
	return lcm(temp, c)
}

func lcm(a, b int) int {
	gc := gcd(a, b)
	return (a * b) / gc
}

func lcmLong(a, b int64) int64 {
	gc := gcdLong(a, b)
	return (a * b) / gc
}

func isPrime(n int64) bool {
	if n == 1 {
		return false
	}
	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

const sieve = 1000000

var prime = make([]bool, sieve+1)

func id4() {
	for i := 4; i <= sieve; i++ {
		prime[i] = true
		i++
	}
	for p := 3; p*p <= sieve; p++ {
		if !prime[p] {
			for i := p * p; i <= sieve; i += p {
				prime[i] = true
			}
		}
		p++
	}
}

func sortD(arr []int, s, e int) {
	sort(arr[s:e+1])
	i, j := s, e
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
}

func sortDLong(arr []int64, s, e int) {
	sort(arr[s:e+1])
	i, j := s, e
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
}

func id1(arr []int64, sum int64) int64 {
	mapCount := make(map[int64]int64)
	n := len(arr)
	prefixSum := int64(0)
	count := int64(0)
	for i := 0; i < n; i++ {
		prefixSum += arr[i]
		if sum == prefixSum {
			count++
		}
		if val, exists := mapCount[prefixSum-sum]; exists {
			count += val
		}
		mapCount[prefixSum]++
	}
	return count
}

func id3(str, pat string) []int {
	list := []int{}
	n := len(str)
	m := len(pat)
	q := pat + ""
	lps := make([]int, n+m+1)
	longestPrefixSuffix(lps, q, n+m+1)
	for i := m + 1; i < n+m+1; i++ {
		if lps[i] == m {
			list = append(list, i-2*m)
		}
	}
	return list
}

func longestPrefixSuffix(lps []int, str string, n int) {
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

func eulerTotientFunction(arr []int, n int) {
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

func nCr(n, k int) int64 {
	ans := int64(1)
	if k > n-k {
		k = n - k
	}
	for j := 1; j <= k; j++ {
		if n%j == 0 {
			ans *= int64(n / j)
		} else if ans%int64(j) == 0 {
			ans = ans / int64(j) * int64(n)
		} else {
			ans = (ans * int64(n)) / int64(j)
		}
		n--
	}
	return ans
}

func allFactors(n int) []int {
	list := []int{}
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

func allFactorsLong(n int64) []int64 {
	list := []int64{}
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

var spf = make([]int, MAXN)

func sieveFunc() {
	spf[1] = 1
	for i := 2; i < MAXN; i++ {
		spf[i] = i
	}
	for i := 4; i < MAXN; i += 2 {
		spf[i] = 2
	}
	for i := 3; i*i < MAXN; i++ {
		if spf[i] == i {
			for j := i * i; j < MAXN; j += i {
				if spf[j] == j {
					spf[j] = i
				}
			}
		}
	}
}

func getFactorization(x int) []int {
	ret := []int{}
	for x != 1 {
		ret = append(ret, spf[x])
		x = x / spf[x]
	}
	return ret
}

func merge(arr []int, l, m, r int) {
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

	i, j, k := 0, 0, l
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

func sort(arr []int, l, r int) {
	if l < r {
		m := (l + r) / 2
		sort(arr, l, m)
		sort(arr, m+1, r)
		merge(arr, l, m, r)
	}
}

func mergeLong(arr []int64, l, m, r int) {
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

	i, j, k := 0, 0, l
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

func sortLong(arr []int64, l, r int) {
	if l < r {
		m := (l + r) / 2
		sortLong(arr, l, m)
		sortLong(arr, m+1, r)
		mergeLong(arr, l, m, r)
	}
}

func knapsack(weight []int, value []int64, maxWeight int) int64 {
	n := len(value)
	dp := make([]int64, maxWeight+1)
	for i := 0; i < n; i++ {
		for j := maxWeight; j >= weight[i]; j-- {
			dp[j] = max(dp[j], value[i]+dp[j-weight[i]])
		}
	}
	return dp[maxWeight]
}

func kadanesAlgorithm(arr []int64) int64 {
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

func kadanesAlgorithmInt(arr []int) int64 {
	dp := make([]int64, len(arr))
	dp[0] = int64(arr[0])
	max := dp[0]
	for i := 1; i < len(arr); i++ {
		if dp[i-1] > 0 {
			dp[i] = dp[i-1] + int64(arr[i])
		} else {
			dp[i] = int64(arr[i])
		}
		if dp[i] > max {
			max = dp[i]
		}
	}
	return max
}

func binarySearchGreater(arr []int, start, end, val int) int64 {
	if start > end {
		return 0
	}
	mid := (start + end) / 2
	if arr[mid] <= val {
		return binarySearchGreater(arr, mid+1, end, val)
	}
	return binarySearchGreater(arr, start, mid-1, val) + int64(end-mid+1)
}

func swapString(a string, i, j int) string {
	b := []rune(a)
	b[i], b[j] = b[j], b[i]
	return string(b)
}

func generatePermutation(str string, start, end int) {
	if start == end-1 {
		fmt.Println(str)
	} else {
		for i := start; i < end; i++ {
			str = swapString(str, start, i)
			generatePermutation(str, start+1, end)
			str = swapString(str, start, i)
		}
	}
}

func factMod(n int64, mod int64) int64 {
	if n <= 1 {
		return 1
	}
	ans := int64(1)
	for i := int64(1); i <= n; i++ {
		ans = (ans * i) % mod
	}
	return ans
}

func power(x, n int64) int64 {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return x
	}
	ans := int64(1)
	for n > 0 {
		if n%2 == 1 {
			ans *= x
		}
		n /= 2
		x *= x
	}
	return ans
}

func powerMod(x, n, mod int64) int64 {
	if n == 0 {
		return 1
	}
	if n == 1 {
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

func lowerBound(arr []int64, k int64) int64 {
	ans := int64(-1)
	start, end := 0, len(arr)-1
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

func lowerBoundInt(arr []int, k int) int {
	ans := -1
	start, end := 0, len(arr)-1
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

func upperBound(arr []int64, k int64) int64 {
	ans := int64(-1)
	start, end := 0, len(arr)-1
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

func upperBoundInt(arr []int, k int) int {
	ans := -1
	start, end := 0, len(arr)-1
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

func printArray(arr []int, si, ei int) {
	for i := si; i <= ei; i++ {
		fmt.Print(arr[i], " ")
	}
}

func printArrayln(arr []int, si, ei int) {
	for i := si; i <= ei; i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func printLArray(arr []int64, si, ei int) {
	for i := si; i <= ei; i++ {
		fmt.Print(arr[i], " ")
	}
}

func printLArrayln(arr []int64, si, ei int) {
	for i := si; i <= ei; i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func printTwoDArray(ans [][]int) {
	for i := 0; i < len(ans); i++ {
		for j := 0; j < len(ans[0]); j++ {
			fmt.Print(ans[i][j], " ")
		}
		fmt.Println()
	}
	fmt.Println()
}

func modPow(a, x, p int64) int64 {
	res := int64(1)
	for x > 0 {
		if x%2 != 0 {
			res = (res * a) % p
		}
		a = (a * a) % p
		x /= 2
	}
	return res
}

func modInverse(a, p int64) int64 {
	return modPow(a, p-2, p)
}

func modBinomial(n, k, p int64) int64 {
	numerator := int64(1)
	for i := int64(0); i < k; i++ {
		numerator = (numerator * (n - i)) % p
	}

	denominator := int64(1)
	for i := int64(1); i <= k; i++ {
		denominator = (denominator * i) % p
	}

	return (numerator * modInverse(denominator, p)) % p
}

var tree [][]int

func countNoOfNodesInSubtree(child, par int, dp []int) {
	count := 1
	for _, x := range tree[child] {
		if x == par {
			continue
		}
		countNoOfNodesInSubtree(x, child, dp)
		count += dp[x]
	}
	dp[child] = count
}

func depth(child, par int, dp []int, d int) {
	dp[child] = d
	for _, x := range tree[child] {
		if x == par {
			continue
		}
		depth(x, child, dp, d+1)
	}
}

func dfs(sv int, vis []bool) {
	vis[sv] = true
	for _, x := range tree[sv] {
		if !vis[x] {
			dfs(x, vis)
		}
	}
}

func solve() {
	scn := NewFastReader()

	var list []int64
	var listl []int64
	var lista []int
	var listb []int

	mapCount := make(map[int]int)

	map1 := make(map[int]int)
	map2 := make(map[int]int)

	set := make(map[int]struct{})

	setx := make(map[int]struct{})
	sety := make(map[int]struct{})

	sb := strings.Builder{}

	testcases := 1

	for testcase := 1; testcase <= testcases; testcase++ {
		n := scn.nextLong()
		x := n

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

		sb.Reset()
		list = nil
		listb = nil
		mapCount = make(map[int]int)
		map1 = make(map[int]int)
		map2 = make(map[int]int)
		set = make(map[int]struct{})
		sety = make(map[int]struct{})
	}

	out.Flush()
}

func main() {
	solve()
}
