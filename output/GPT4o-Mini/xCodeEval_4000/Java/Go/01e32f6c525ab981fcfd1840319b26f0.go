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

func (fr *FastReader) Next() string {
	line, _ := fr.br.ReadString('\n')
	return strings.TrimSpace(line)
}

func (fr *FastReader) NextInt() int {
	n, _ := strconv.Atoi(fr.Next())
	return n
}

func (fr *FastReader) NextLong() int64 {
	n, _ := strconv.ParseInt(fr.Next(), 10, 64)
	return n
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

func isPowerOfTwo(n int64) bool {
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

func isPossibleTriangle(a, b, c int) bool {
	return a+b > c && b+c > a && a+c > b
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

func xorOfFirstN(n int) int {
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

func lcm(a, b int) int {
	return (a * b) / gcd(a, b)
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

func sieveOfEratosthenes() {
	for i := 4; i <= sieve; i++ {
		prime[i] = true
	}
	for p := 3; p*p <= sieve; p++ {
		if !prime[p] {
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

func solve() {
	scn := NewFastReader()
	testcases := 1

	for testcase := 1; testcase <= testcases; testcase++ {
		n := scn.NextLong()
		a1 := scn.NextLong()
		a2 := scn.NextLong()
		a3 := scn.NextLong()
		b1 := scn.NextLong()
		b2 := scn.NextLong()
		b3 := scn.NextLong()

		var min int64 = 0
		if b1 >= a1+a2 {
			min = a3 - b2 - b3
		} else if b2 >= a3+a2 {
			min = a1 - b1 - b3
		} else if b3 >= a1+a3 {
			min = a2 - b2 - b1
		} else {
			min = 0
		}

		max := min(a1, b2) + min(a2, b3) + min(a3, b1)

		fmt.Fprintf(out, "%d %d\n", min, max)
	}

	out.Flush()
}

func main() {
	solve()
}
