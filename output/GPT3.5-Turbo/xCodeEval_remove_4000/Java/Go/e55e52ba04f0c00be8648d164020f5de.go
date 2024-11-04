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
	str := r.Next()
	num, err := strconv.Atoi(str)
	if err != nil {
		panic(err)
	}
	return num
}

func (r *FastReader) NextLong() int64 {
	str := r.Next()
	num, err := strconv.ParseInt(str, 10, 64)
	if err != nil {
		panic(err)
	}
	return num
}

func (r *FastReader) NextDouble() float64 {
	str := r.Next()
	num, err := strconv.ParseFloat(str, 64)
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

func ID2(n int64) int {
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

func ID0(n int64) bool {
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

func ID5(a, b, c int) bool {
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

func ID6(n int) int {
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

func Sieve() {
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
		p++
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

func ID1(arr []int64, sum int64) int64 {
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

func SwapString(a string, i, j int) string {
	b := []byte(a)
	ch := b[i]
	b[i] = b[j]
	b[j] = ch
	return string(b)
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

func Solve() {
	scanner := NewFastReader()

	// Your code here

	out.Flush()
}

func main() {
	Solve()
}
