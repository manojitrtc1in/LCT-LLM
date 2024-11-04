package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func main() {
	solver()
	writer.Flush()
}

func solver() {
	n := nextInt()
	m := nextInt()
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt()
	}
	required := sum(arr)
	typeDays := make(map[int]map[int]bool)
	for i := 0; i < m; i++ {
		d := nextInt()
		typ := nextInt()
		if arr[typ-1] <= 0 {
			continue
		}
		if _, ok := typeDays[typ]; !ok {
			typeDays[typ] = make(map[int]bool)
		}
		typeDays[typ][d] = true
	}

	lo := required
	hi := 2 * required
	valid := hi
	for lo <= hi {
		mid := (lo + hi) / 2
		if isEnough(mid, arr, required, typeDays) {
			valid = mid
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}
	fmt.Fprintln(writer, valid)
}

func isEnough(day int, arr []int, required int, typeDays map[int]map[int]bool) bool {
	totalCoin := day
	req := required

	ddays := make([]int, day+1)
	for typ, days := range typeDays {
		lastDay := -1
		for d := range days {
			if d <= day {
				lastDay = max(lastDay, d)
			}
		}
		if lastDay == -1 {
			continue
		}
		ddays[lastDay] += arr[typ-1]
	}

	removed := 0
	for i := 1; i < day+1; i++ {
		coins := i - removed
		toRemove := min(coins, ddays[i])
		removed += toRemove
		totalCoin -= toRemove
		req -= toRemove
	}

	return req*2 <= totalCoin
}

func next() string {
	if !scanner.Scan() {
		panic("scan error")
	}
	return scanner.Text()
}

func nextInt() int {
	i, err := strconv.Atoi(next())
	if err != nil {
		panic(err)
	}
	return i
}

func nextInt64() int64 {
	i, err := strconv.ParseInt(next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func nextFloat64() float64 {
	f, err := strconv.ParseFloat(next(), 64)
	if err != nil {
		panic(err)
	}
	return f
}

func nextString() string {
	return next()
}

func nextLine() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInts(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt()
	}
	return arr
}

func nextInt64s(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt64()
	}
	return arr
}

func nextFloat64s(n int) []float64 {
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextFloat64()
	}
	return arr
}

func nextStrings(n int) []string {
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		arr[i] = nextString()
	}
	return arr
}

func nextLines(n int) []string {
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		arr[i] = nextLine()
	}
	return arr
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func min(a ...int) int {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func max(a ...int) int {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func sum(a ...int) int {
	s := 0
	for _, v := range a {
		s += v
	}
	return s
}

func abs64(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func min64(a ...int64) int64 {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func max64(a ...int64) int64 {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func sum64(a ...int64) int64 {
	s := int64(0)
	for _, v := range a {
		s += v
	}
	return s
}

func absf(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}

func minf(a ...float64) float64 {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxf(a ...float64) float64 {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func sumf(a ...float64) float64 {
	s := 0.0
	for _, v := range a {
		s += v
	}
	return s
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func pow(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res *= a
		}
		a *= a
		b >>= 1
	}
	return res
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func sortString(s string) string {
	r := []rune(s)
	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})
	return string(r)
}

func uniqueInts(arr []int) []int {
	m := make(map[int]bool)
	for _, v := range arr {
		m[v] = true
	}
	res := make([]int, 0, len(m))
	for k := range m {
		res = append(res, k)
	}
	return res
}

func uniqueInt64s(arr []int64) []int64 {
	m := make(map[int64]bool)
	for _, v := range arr {
		m[v] = true
	}
	res := make([]int64, 0, len(m))
	for k := range m {
		res = append(res, k)
	}
	return res
}

func uniqueFloat64s(arr []float64) []float64 {
	m := make(map[float64]bool)
	for _, v := range arr {
		m[v] = true
	}
	res := make([]float64, 0, len(m))
	for k := range m {
		res = append(res, k)
	}
	return res
}

func uniqueStrings(arr []string) []string {
	m := make(map[string]bool)
	for _, v := range arr {
		m[v] = true
	}
	res := make([]string, 0, len(m))
	for k := range m {
		res = append(res, k)
	}
	return res
}

func containsInt(arr []int, x int) bool {
	for _, v := range arr {
		if v == x {
			return true
		}
	}
	return false
}

func containsInt64(arr []int64, x int64) bool {
	for _, v := range arr {
		if v == x {
			return true
		}
	}
	return false
}

func containsFloat64(arr []float64, x float64) bool {
	for _, v := range arr {
		if v == x {
			return true
		}
	}
	return false
}

func containsString(arr []string, x string) bool {
	for _, v := range arr {
		if v == x {
			return true
		}
	}
	return false
}

func countsInt(arr []int) map[int]int {
	counts := make(map[int]int)
	for _, v := range arr {
		counts[v]++
	}
	return counts
}

func countsInt64(arr []int64) map[int64]int {
	counts := make(map[int64]int)
	for _, v := range arr {
		counts[v]++
	}
	return counts
}

func countsFloat64(arr []float64) map[float64]int {
	counts := make(map[float64]int)
	for _, v := range arr {
		counts[v]++
	}
	return counts
}

func countsString(arr []string) map[string]int {
	counts := make(map[string]int)
	for _, v := range arr {
		counts[v]++
	}
	return counts
}

func binarySearch(arr []int, target int) int {
	left := 0
	right := len(arr) - 1
	for left <= right {
		mid := (left + right) / 2
		if arr[mid] == target {
			return mid
		} else if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return -1
}

func upperBound(arr []int, target int) int {
	left := 0
	right := len(arr) - 1
	for right-left >= 0 {
		mid := (left + right) / 2
		if target < arr[mid] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return left
}

func lowerBound(arr []int, target int) int {
	left := 0
	right := len(arr) - 1
	for right-left >= 0 {
		mid := (left + right) / 2
		if target <= arr[mid] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return left
}

func deepCopyInts(arr []int) []int {
	res := make([]int, len(arr))
	copy(res, arr)
	return res
}

func deepCopyInt64s(arr []int64) []int64 {
	res := make([]int64, len(arr))
	copy(res, arr)
	return res
}

func deepCopyFloat64s(arr []float64) []float64 {
	res := make([]float64, len(arr))
	copy(res, arr)
	return res
}

func deepCopyStrings(arr []string) []string {
	res := make([]string, len(arr))
	copy(res, arr)
	return res
}

func fillInts(arr []int, val int) {
	for i := 0; i < len(arr); i++ {
		arr[i] = val
	}
}

func fillInt64s(arr []int64, val int64) {
	for i := 0; i < len(arr); i++ {
		arr[i] = val
	}
}

func fillFloat64s(arr []float64, val float64) {
	for i := 0; i < len(arr); i++ {
		arr[i] = val
	}
}

func fillStrings(arr []string, val string) {
	for i := 0; i < len(arr); i++ {
		arr[i] = val
	}
}

func fill2DInts(arr [][]int, val int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			arr[i][j] = val
		}
	}
}

func fill2DInt64s(arr [][]int64, val int64) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			arr[i][j] = val
		}
	}
}

func fill2DFloat64s(arr [][]float64, val float64) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			arr[i][j] = val
		}
	}
}

func fill2DStrings(arr [][]string, val string) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			arr[i][j] = val
		}
	}
}

func swapInts(arr []int, left, right int) []int {
	arr[left], arr[right] = arr[right], arr[left]
	return arr
}

func swapInt64s(arr []int64, left, right int) []int64 {
	arr[left], arr[right] = arr[right], arr[left]
	return arr
}

func swapFloat64s(arr []float64, left, right int) []float64 {
	arr[left], arr[right] = arr[right], arr[left]
	return arr
}

func swapStrings(arr []string, left, right int) []string {
	arr[left], arr[right] = arr[right], arr[left]
	return arr
}

func reverseInts(arr []int, left, right int) []int {
	for left < right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
	return arr
}

func reverseInt64s(arr []int64, left, right int) []int64 {
	for left < right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
	return arr
}

func reverseFloat64s(arr []float64, left, right int) []float64 {
	for left < right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
	return arr
}

func reverseStrings(arr []string, left, right int) []string {
	for left < right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
	return arr
}

func isPrime(a int) bool {
	if a == 1 {
		return false
	}
	for i := 2; i*i <= a; i++ {
		if a%i == 0 {
			return false
		}
	}
	return true
}

func sieve(n int) []int {
	isPrime := make([]bool, n+1)
	for i := 2; i <= n; i++ {
		isPrime[i] = true
	}
	for i := 2; i*i <= n; i++ {
		if isPrime[i] {
			for j := i * i; j <= n; j += i {
				isPrime[j] = false
			}
		}
	}
	primes := make([]int, 0)
	for i := 2; i <= n; i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}
	return primes
}

func factorial(n int) int {
	ans := 1
	for i := n; i > 0; i-- {
		ans *= i
	}
	return ans
}

func facMod(n, mod int) int {
	ans := 1
	for i := n; i > 0; i-- {
		ans = (ans * i) % mod
	}
	return ans
}

func nCr(n, r int) int {
	if r > (n - r) {
		r = n - r
	}
	ans := 1
	for i := 1; i <= r; i++ {
		ans *= n
		ans /= i
		n--
	}
	return ans
}

func nCrMod(n, r, mod int) int {
	ans := 1
	for i := (n - r + 1); i <= n; i++ {
		ans = (ans * i) % mod
	}
	first := facMod(n, mod)
	second := pow(facMod(r, mod), mod-2, mod)
	return (first * second) % mod
}

func bitString(n int) string {
	return strconv.FormatInt(int64(n), 2)
}

func id18(n, k int) int {
	return (n | (1 << k))
}

func id5(n, k int) int {
	return (n & ^(1 << k))
}

func id16(n, k int) int {
	return (n ^ (1 << k))
}

func id6(n int) bool {
	return (n & (n - 1)) == 0
}

func id0(n int) {
	fmt.Fprintf(writer, "%032b\n", n)
}

func id19(n int) []int {
	lp := make([]int, n+1)
	pr := make([]int, 0)
	for i := 2; i <= n; i++ {
		if lp[i] == 0 {
			lp[i] = i
			pr = append(pr, i)
		}
		for j := 0; j < len(pr) && pr[j] <= lp[i] && i*pr[j] <= n; j++ {
			lp[i*pr[j]] = pr[j]
		}
	}
	return pr
}

func id9(n, r, mod int) int {
	res := 1
	for i := (n - r + 1); i <= n; i++ {
		res = (res * i) % mod
	}
	return res
}

func id10(n, r, mod int) int {
	id13 := id9(r, r, mod)
	first := id9(n, r, mod)
	second := pow(id13, mod-2, mod)
	return (first * second) % mod
}

func id17(a, b, mod int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = (res * a) % mod
		}
		a = (a * a) % mod
		b >>= 1
	}
	return res
}

func id1(num int) int {
	cf := 1
	d := 0
	for num >= cf {
		d++
		cf = 1 << d
	}
	return d
}

func id14(num int) int {
	cf := 1
	d := 0
	for num >= cf {
		d++
		cf *= 10
	}
	return d
}

func id8(y, x, h, w int) bool {
	if y < 0 {
		return false
	}
	if x < 0 {
		return false
	}
	if y >= h {
		return false
	}
	if x >= w {
		return false
	}
	return true
}

func shuffleInts(arr []int) {
	n := len(arr)
	for i := 0; i < n; i++ {
		oi := randomInt(n)
		arr[oi], arr[i] = arr[i], arr[oi]
	}
}

func shuffleInt64s(arr []int64) {
	n := len(arr)
	for i := 0; i < n; i++ {
		oi := randomInt(n)
		arr[oi], arr[i] = arr[i], arr[oi]
	}
}

func shuffleFloat64s(arr []float64) {
	n := len(arr)
	for i := 0; i < n; i++ {
		oi := randomInt(n)
		arr[oi], arr[i] = arr[i], arr[oi]
	}
}

func shuffleStrings(arr []string) {
	n := len(arr)
	for i := 0; i < n; i++ {
		oi := randomInt(n)
		arr[oi], arr[i] = arr[i], arr[oi]
	}
}

func randomInt(n int) int {
	return random.Intn(n)
}

func randomInts(n, min, max int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = randomInt(max-min+1) + min
	}
	return arr
}

func randomInt64(n int64) int64 {
	return random.Int63n(n)
}

func randomInt64s(n, min, max int64) []int64 {
	arr := make([]int64, n)
	for i := int64(0); i < n; i++ {
		arr[i] = randomInt64(max-min+1) + min
	}
	return arr
}

func randomFloat64() float64 {
	return random.Float64()
}

func randomFloat64s(n, min, max float64) []float64 {
	arr := make([]float64, n)
	for i := 0; i < int(n); i++ {
		arr[i] = randomFloat64()*(max-min) + min
	}
	return arr
}

func randomString(n int) string {
	const letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	b := make([]byte, n)
	for i := range b {
		b[i] = letters[randomInt(len(letters))]
	}
	return string(b)
}

func randomStrings(n, length int) []string {
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		arr[i] = randomString(length)
	}
	return arr
}

func randomBool() bool {
	return randomInt(2) == 1
}

func randomBools(n int) []bool {
	arr := make([]bool, n)
	for i := 0; i < n; i++ {
		arr[i] = randomBool()
	}
	return arr
}

func randomSubset(n, k int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = i
	}
	shuffleInts(arr)
	return arr[:k]
}

func randomSubset64(n, k int64) []int64 {
	arr := make([]int64, n)
	for i := int64(0); i < n; i++ {
		arr[i] = i
	}
	shuffleInt64s(arr)
	return arr[:k]
}

func randomSubsetFloat64(n, k int64) []float64 {
	arr := make([]float64, n)
	for i := int64(0); i < n; i++ {
		arr[i] = float64(i)
	}
	shuffleFloat64s(arr)
	return arr[:k]
}

func randomSubsetString(n, k int) []string {
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		arr[i] = strconv.Itoa(i)
	}
	shuffleStrings(arr)
	return arr[:k]
}

func randomSubsetBool(n, k int) []bool {
	arr := make([]bool, n)
	for i := 0; i < n; i++ {
		arr[i] = randomBool()
	}
	shuffleBools(arr)
	return arr[:k]
}

func randomSubsetInts(arr []int, k int) []int {
	shuffleInts(arr)
	return arr[:k]
}

func randomSubsetInt64s(arr []int64, k int) []int64 {
	shuffleInt64s(arr)
	return arr[:k]
}

func randomSubsetFloat64s(arr []float64, k int) []float64 {
	shuffleFloat64s(arr)
	return arr[:k]
}

func randomSubsetStrings(arr []string, k int) []string {
	shuffleStrings(arr)
	return arr[:k]
}

func randomSubsetBools(arr []bool, k int) []bool {
	shuffleBools(arr)
	return arr[:k]
}

func randomSubsetIntsWithoutReplacement(arr []int, k int) []int {
	n := len(arr)
	for i := 0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetInt64sWithoutReplacement(arr []int64, k int) []int64 {
	n := len(arr)
	for i := 0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetFloat64sWithoutReplacement(arr []float64, k int) []float64 {
	n := len(arr)
	for i := 0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetStringsWithoutReplacement(arr []string, k int) []string {
	n := len(arr)
	for i := 0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetBoolsWithoutReplacement(arr []bool, k int) []bool {
	n := len(arr)
	for i := 0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetIntsWithoutReplacement64(arr []int, k int64) []int {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetInt64sWithoutReplacement64(arr []int64, k int64) []int64 {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetFloat64sWithoutReplacement64(arr []float64, k int64) []float64 {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetStringsWithoutReplacement64(arr []string, k int64) []string {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetBoolsWithoutReplacement64(arr []bool, k int64) []bool {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetIntsWithoutReplacementInt64(arr []int, k int64) []int {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetInt64sWithoutReplacementInt64(arr []int64, k int64) []int64 {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetFloat64sWithoutReplacementInt64(arr []float64, k int64) []float64 {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetStringsWithoutReplacementInt64(arr []string, k int64) []string {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetBoolsWithoutReplacementInt64(arr []bool, k int64) []bool {
	n := len(arr)
	for i := int64(0); i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:k]
}

func randomSubsetIntsWithoutReplacementFloat64(arr []int, k float64) []int {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetInt64sWithoutReplacementFloat64(arr []int64, k float64) []int64 {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetFloat64sWithoutReplacementFloat64(arr []float64, k float64) []float64 {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetStringsWithoutReplacementFloat64(arr []string, k float64) []string {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetBoolsWithoutReplacementFloat64(arr []bool, k float64) []bool {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetIntsWithoutReplacementInt64Float64(arr []int, k float64) []int {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetInt64sWithoutReplacementInt64Float64(arr []int64, k float64) []int64 {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetFloat64sWithoutReplacementInt64Float64(arr []float64, k float64) []float64 {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetStringsWithoutReplacementInt64Float64(arr []string, k float64) []string {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}

func randomSubsetBoolsWithoutReplacementInt64Float64(arr []bool, k float64) []bool {
	n := len(arr)
	for i := 0.0; i < k; i++ {
		oi := randomInt(n)
		arr[oi], arr[n-1] = arr[n-1], arr[oi]
		n--
	}
	return arr[:int(k)]
}
