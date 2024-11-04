package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextLong() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func nextFloat() float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func nextLine() string {
	scanner.Scan()
	return scanner.Text()
}

func printString(s string) {
	fmt.Fprint(writer, s)
}

func printInt(num int) {
	fmt.Fprint(writer, num)
}

func printLong(num int64) {
	fmt.Fprint(writer, num)
}

func printFloat(num float64) {
	fmt.Fprint(writer, num)
}

func println() {
	fmt.Fprintln(writer)
}

func countDigit(n int64) int {
	return int(math.Floor(math.Log10(float64(n)) + 1))
}

func sumOfDigits(n int64) int {
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
	var ans int64

	for i := start; i <= end; i++ {
		ans += int64(arr[i])
	}

	return ans
}

func mod(x int) int {
	if x < 0 {
		return -1 * x
	} else {
		return x
	}
}

func modLong(x int64) int64 {
	if x < 0 {
		return -1 * x
	} else {
		return x
	}
}

func swapArray(arr []int, start, end int) {
	for start < end {
		temp := arr[start]
		arr[start] = arr[end]
		arr[end] = temp
		start++
		end--
	}
}

func rotate(input [][]int) [][]int {
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

func countBits(n int64) int {
	count := 0

	for n != 0 {
		count++
		n = n >> 1
	}

	return count
}

func isPowerOfTwo(n int64) bool {
	if n == 0 {
		return false
	}

	if (n & (n - 1)) == 0 {
		return true
	} else {
		return false
	}
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
	str := ""

	for i := len(input) - 1; i >= 0; i-- {
		str += string(input[i])
	}

	return str
}

func sameParity(a, b int64) bool {
	x := a % 2
	y := b % 2

	if x == y {
		return true
	} else {
		return false
	}
}

func isPossibleTriangle(a, b, c int) bool {
	if a+b > c && c+b > a && a+c > b {
		return true
	} else {
		return false
	}
}

func xnor(num1, num2 int64) int64 {
	if num1 < num2 {
		temp := num1
		num1 = num2
		num2 = temp
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

func xorOfFirstN(n int) int {
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

func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a%b)
	}
}

func lcm(a, b, c, d int) int {
	temp := lcm(a, b, c)
	ans := lcm(temp, d)
	return ans
}

func lcm(a, b, c int) int {
	temp := lcm(a, b)
	ans := lcm(temp, c)
	return ans
}

func lcm(a, b int) int {
	gc := gcd(a, b)
	return (a * b) / gc
}

func isPrime(n int64) bool {
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

func sieveOfEratosthenes() {
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

func sortD(arr []int, s, e int) {
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

func countSubarraysSumToK(arr []int64, sum int64) int64 {
	m := make(map[int64]int64)
	n := len(arr)
	prefixSum := int64(0)
	count := int64(0)

	for i := 0; i < n; i++ {
		prefixSum += arr[i]

		if prefixSum == sum {
			count++
		}

		if val, ok := m[prefixSum-sum]; ok {
			count += val
		}

		if _, ok := m[prefixSum]; ok {
			m[prefixSum]++
		} else {
			m[prefixSum] = 1
		}
	}

	return count
}

func kmpAlgorithm(str, pat string) []int {
	list := make([]int, 0)
	n := len(str)
	m := len(pat)
	q := pat + "#" + str
	lps := make([]int, n+m+1)

	longestPefixSuffix(lps, q, n+m+1)

	for i := m + 1; i < n+m+1; i++ {
		if lps[i] == m {
			list = append(list, i-2*m)
		}
	}

	return list
}

func longestPefixSuffix(lps []int, str string, n int) {
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

func allFactors(n int) []int {
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

func allFactorsLong(n int64) []int64 {
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

func sieve() {
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

func sortLong(arr []int64, l, r int) {
	if l < r {
		m := (l + r) / 2

		sortLong(arr, l, m)
		sortLong(arr, m+1, r)

		mergeLong(arr, l, m, r)
	}
}

func countNoOfNodesInsubtree(child, par int, dp []int) {
	count := 1

	for _, x := range tree[child] {
		if x == par {
			continue
		}

		countNoOfNodesInsubtree(x, child, dp)

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
	initIO()

	tree = make([][]int, 0)

	// Read input
	n := nextLong()
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
		printInt(1)
		println()
		printInt(0)
		println()
	}

	if len(list) == 2 {
		printInt(2)
		println()
	}

	if len(list) > 2 {
		printInt(1)
		println()

		if len(list) == 1 {
			printInt(0)
			println()
		} else {
			ans := list[0] * list[1]
			printInt(ans)
			println()
		}
	}

	flush()

	list = make([]int64, 0)
	listb = make([]int, 0)
	map1 = make(map[int]int)
	map2 = make(map[int]int)
	set = make(map[int]bool)
	sety = make(map[int]bool)
}

func main() {
	solve()
}
