package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF   = 2147483647
	LLINF = int64(^uint64(0) >> 1)
	PI    = 3.1415926535
	MOD   = 1000000007
	MOD2  = 998244353
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Function to read an integer from input
	readInt := func() int {
		scanner.Scan()
		val, _ := strconv.Atoi(scanner.Text())
		return val
	}

	// Function to read a string from input
	readString := func() string {
		scanner.Scan()
		return scanner.Text()
	}

	// Function to read a slice of integers from input
	readIntSlice := func(n int) []int {
		slice := make([]int, n)
		for i := 0; i < n; i++ {
			slice[i] = readInt()
		}
		return slice
	}

	// Function to read a slice of strings from input
	readStringSlice := func(n int) []string {
		slice := make([]string, n)
		for i := 0; i < n; i++ {
			slice[i] = readString()
		}
		return slice
	}

	// Function to write an integer to output
	writeInt := func(val int) {
		fmt.Println(val)
	}

	// Function to write a string to output
	writeString := func(val string) {
		fmt.Println(val)
	}

	// Function to write a slice of integers to output
	writeIntSlice := func(slice []int) {
		str := make([]string, len(slice))
		for i, v := range slice {
			str[i] = strconv.Itoa(v)
		}
		writeString(strings.Join(str, " "))
	}

	// Function to write a slice of strings to output
	writeStringSlice := func(slice []string) {
		writeString(strings.Join(slice, " "))
	}

	// Function to calculate the power of a number
	pow := func(b, p, mod int) int {
		b %= mod
		ans := 1
		for p > 0 {
			if p&1 == 1 {
				ans *= b
				ans %= mod
			}
			b *= b
			b %= mod
			p >>= 1
		}
		return ans
	}

	// Function to check if a number is prime
	isPrime := func(n int) bool {
		if n < 2 {
			return false
		}
		for i := 2; i*i <= n; i++ {
			if n%i == 0 {
				return false
			}
		}
		return true
	}

	// Function to find the minimum of two numbers
	min := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}

	// Function to find the maximum of two numbers
	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	// Function to find the greatest common divisor of two numbers
	gcd := func(a, b int) int {
		for b != 0 {
			a, b = b, a%b
		}
		return a
	}

	// Function to find the least common multiple of two numbers
	lcm := func(a, b int) int {
		return a / gcd(a, b) * b
	}

	// Function to find the factorial of a number
	factorial := func(n int) int {
		fact := 1
		for i := 2; i <= n; i++ {
			fact *= i
		}
		return fact
	}

	// Function to find the nth Fibonacci number
	fibonacci := func(n int) int {
		if n <= 1 {
			return n
		}
		a, b := 0, 1
		for i := 2; i <= n; i++ {
			a, b = b, a+b
		}
		return b
	}

	// Function to find the number of digits in a number
	numDigits := func(n int) int {
		count := 0
		for n != 0 {
			n /= 10
			count++
		}
		return count
	}

	// Function to reverse a string
	reverseString := func(s string) string {
		runes := []rune(s)
		for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
			runes[i], runes[j] = runes[j], runes[i]
		}
		return string(runes)
	}

	// Function to sort a slice of integers in ascending order
	sortIntSlice := func(slice []int) {
		n := len(slice)
		for i := 0; i < n-1; i++ {
			for j := 0; j < n-i-1; j++ {
				if slice[j] > slice[j+1] {
					slice[j], slice[j+1] = slice[j+1], slice[j]
				}
			}
		}
	}

	// Function to sort a slice of strings in ascending order
	sortStringSlice := func(slice []string) {
		n := len(slice)
		for i := 0; i < n-1; i++ {
			for j := 0; j < n-i-1; j++ {
				if slice[j] > slice[j+1] {
					slice[j], slice[j+1] = slice[j+1], slice[j]
				}
			}
		}
	}

	// Function to perform binary search on a sorted slice of integers
	binarySearch := func(slice []int, target int) int {
		left, right := 0, len(slice)-1
		for left <= right {
			mid := left + (right-left)/2
			if slice[mid] == target {
				return mid
			} else if slice[mid] < target {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
		return -1
	}

	// Function to perform linear search on a slice of integers
	linearSearch := func(slice []int, target int) int {
		for i, v := range slice {
			if v == target {
				return i
			}
		}
		return -1
	}

	// Function to calculate the sum of all elements in a slice of integers
	sum := func(slice []int) int {
		total := 0
		for _, v := range slice {
			total += v
		}
		return total
	}

	// Function to calculate the product of all elements in a slice of integers
	product := func(slice []int) int {
		total := 1
		for _, v := range slice {
			total *= v
		}
		return total
	}

	// Function to calculate the average of all elements in a slice of integers
	average := func(slice []int) float64 {
		total := 0
		for _, v := range slice {
			total += v
		}
		return float64(total) / float64(len(slice))
	}

	// Function to calculate the median of all elements in a slice of integers
	median := func(slice []int) float64 {
		n := len(slice)
		sortIntSlice(slice)
		if n%2 == 0 {
			return float64(slice[n/2-1]+slice[n/2]) / 2.0
		} else {
			return float64(slice[n/2])
		}
	}

	// Function to calculate the mode of all elements in a slice of integers
	mode := func(slice []int) []int {
		freq := make(map[int]int)
		maxFreq := 0
		for _, v := range slice {
			freq[v]++
			maxFreq = max(maxFreq, freq[v])
		}
		modeSlice := make([]int, 0)
		for k, v := range freq {
			if v == maxFreq {
				modeSlice = append(modeSlice, k)
			}
		}
		return modeSlice
	}

	// Function to calculate the variance of all elements in a slice of integers
	variance := func(slice []int) float64 {
		n := len(slice)
		avg := average(slice)
		total := 0.0
		for _, v := range slice {
			total += (float64(v) - avg) * (float64(v) - avg)
		}
		return total / float64(n)
	}

	// Function to calculate the standard deviation of all elements in a slice of integers
	standardDeviation := func(slice []int) float64 {
		return sqrt(variance(slice))
	}

	// Function to calculate the Euclidean distance between two points in 2D space
	distance := func(x1, y1, x2, y2 int) float64 {
		return sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)))
	}

	// Function to calculate the Manhattan distance between two points in 2D space
	manhattanDistance := func(x1, y1, x2, y2 int) int {
		return abs(x2-x1) + abs(y2-y1)
	}

	// Function to calculate the Hamming distance between two strings
	hammingDistance := func(s1, s2 string) int {
		dist := 0
		for i := 0; i < len(s1); i++ {
			if s1[i] != s2[i] {
				dist++
			}
		}
		return dist
	}

	// Function to calculate the Levenshtein distance between two strings
	levenshteinDistance := func(s1, s2 string) int {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
			dp[i][0] = i
		}
		for j := 0; j <= n; j++ {
			dp[0][j] = j
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1]
				} else {
					dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1)
				}
			}
		}
		return dp[m][n]
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two strings
	lcs := func(s1, s2 string) string {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]byte, dp[m][n])
		i, j := m, n
		for i > 0 && j > 0 {
			if s1[i-1] == s2[j-1] {
				lcs[dp[i][j]-1] = s1[i-1]
				i--
				j--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return string(lcs)
	}

	// Function to calculate the LIS (Longest Increasing Subsequence) of a slice of integers
	lis := func(slice []int) []int {
		n := len(slice)
		dp := make([]int, n)
		parent := make([]int, n)
		length := 0
		for i := 0; i < n; i++ {
			lo, hi := 0, length
			for lo < hi {
				mid := lo + (hi-lo)/2
				if slice[i] > slice[dp[mid]] {
					lo = mid + 1
				} else {
					hi = mid
				}
			}
			dp[lo] = i
			if lo == length {
				length++
			}
			if lo > 0 {
				parent[i] = dp[lo-1]
			}
		}
		lis := make([]int, length)
		k := dp[length-1]
		for i := length - 1; i >= 0; i-- {
			lis[i] = slice[k]
			k = parent[k]
		}
		return lis
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two slices of integers
	lcsSlice := func(slice1, slice2 []int) []int {
		m, n := len(slice1), len(slice2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if slice1[i-1] == slice2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]int, dp[m][n])
		i, j, k := m, n, dp[m][n]-1
		for i > 0 && j > 0 {
			if slice1[i-1] == slice2[j-1] {
				lcs[k] = slice1[i-1]
				i--
				j--
				k--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return lcs
	}

	// Function to calculate the edit distance between two strings
	editDistance := func(s1, s2 string) int {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
			dp[i][0] = i
		}
		for j := 0; j <= n; j++ {
			dp[0][j] = j
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1]
				} else {
					dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1)
				}
			}
		}
		return dp[m][n]
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two strings
	lcs := func(s1, s2 string) string {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]byte, dp[m][n])
		i, j := m, n
		for i > 0 && j > 0 {
			if s1[i-1] == s2[j-1] {
				lcs[dp[i][j]-1] = s1[i-1]
				i--
				j--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return string(lcs)
	}

	// Function to calculate the LIS (Longest Increasing Subsequence) of a slice of integers
	lis := func(slice []int) []int {
		n := len(slice)
		dp := make([]int, n)
		parent := make([]int, n)
		length := 0
		for i := 0; i < n; i++ {
			lo, hi := 0, length
			for lo < hi {
				mid := lo + (hi-lo)/2
				if slice[i] > slice[dp[mid]] {
					lo = mid + 1
				} else {
					hi = mid
				}
			}
			dp[lo] = i
			if lo == length {
				length++
			}
			if lo > 0 {
				parent[i] = dp[lo-1]
			}
		}
		lis := make([]int, length)
		k := dp[length-1]
		for i := length - 1; i >= 0; i-- {
			lis[i] = slice[k]
			k = parent[k]
		}
		return lis
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two slices of integers
	lcsSlice := func(slice1, slice2 []int) []int {
		m, n := len(slice1), len(slice2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if slice1[i-1] == slice2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]int, dp[m][n])
		i, j, k := m, n, dp[m][n]-1
		for i > 0 && j > 0 {
			if slice1[i-1] == slice2[j-1] {
				lcs[k] = slice1[i-1]
				i--
				j--
				k--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return lcs
	}

	// Function to calculate the edit distance between two strings
	editDistance := func(s1, s2 string) int {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
			dp[i][0] = i
		}
		for j := 0; j <= n; j++ {
			dp[0][j] = j
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1]
				} else {
					dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1)
				}
			}
		}
		return dp[m][n]
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two strings
	lcs := func(s1, s2 string) string {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]byte, dp[m][n])
		i, j := m, n
		for i > 0 && j > 0 {
			if s1[i-1] == s2[j-1] {
				lcs[dp[i][j]-1] = s1[i-1]
				i--
				j--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return string(lcs)
	}

	// Function to calculate the LIS (Longest Increasing Subsequence) of a slice of integers
	lis := func(slice []int) []int {
		n := len(slice)
		dp := make([]int, n)
		parent := make([]int, n)
		length := 0
		for i := 0; i < n; i++ {
			lo, hi := 0, length
			for lo < hi {
				mid := lo + (hi-lo)/2
				if slice[i] > slice[dp[mid]] {
					lo = mid + 1
				} else {
					hi = mid
				}
			}
			dp[lo] = i
			if lo == length {
				length++
			}
			if lo > 0 {
				parent[i] = dp[lo-1]
			}
		}
		lis := make([]int, length)
		k := dp[length-1]
		for i := length - 1; i >= 0; i-- {
			lis[i] = slice[k]
			k = parent[k]
		}
		return lis
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two slices of integers
	lcsSlice := func(slice1, slice2 []int) []int {
		m, n := len(slice1), len(slice2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if slice1[i-1] == slice2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]int, dp[m][n])
		i, j, k := m, n, dp[m][n]-1
		for i > 0 && j > 0 {
			if slice1[i-1] == slice2[j-1] {
				lcs[k] = slice1[i-1]
				i--
				j--
				k--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return lcs
	}

	// Function to calculate the edit distance between two strings
	editDistance := func(s1, s2 string) int {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
			dp[i][0] = i
		}
		for j := 0; j <= n; j++ {
			dp[0][j] = j
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1]
				} else {
					dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1)
				}
			}
		}
		return dp[m][n]
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two strings
	lcs := func(s1, s2 string) string {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]byte, dp[m][n])
		i, j := m, n
		for i > 0 && j > 0 {
			if s1[i-1] == s2[j-1] {
				lcs[dp[i][j]-1] = s1[i-1]
				i--
				j--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return string(lcs)
	}

	// Function to calculate the LIS (Longest Increasing Subsequence) of a slice of integers
	lis := func(slice []int) []int {
		n := len(slice)
		dp := make([]int, n)
		parent := make([]int, n)
		length := 0
		for i := 0; i < n; i++ {
			lo, hi := 0, length
			for lo < hi {
				mid := lo + (hi-lo)/2
				if slice[i] > slice[dp[mid]] {
					lo = mid + 1
				} else {
					hi = mid
				}
			}
			dp[lo] = i
			if lo == length {
				length++
			}
			if lo > 0 {
				parent[i] = dp[lo-1]
			}
		}
		lis := make([]int, length)
		k := dp[length-1]
		for i := length - 1; i >= 0; i-- {
			lis[i] = slice[k]
			k = parent[k]
		}
		return lis
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two slices of integers
	lcsSlice := func(slice1, slice2 []int) []int {
		m, n := len(slice1), len(slice2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if slice1[i-1] == slice2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]int, dp[m][n])
		i, j, k := m, n, dp[m][n]-1
		for i > 0 && j > 0 {
			if slice1[i-1] == slice2[j-1] {
				lcs[k] = slice1[i-1]
				i--
				j--
				k--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return lcs
	}

	// Function to calculate the edit distance between two strings
	editDistance := func(s1, s2 string) int {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
			dp[i][0] = i
		}
		for j := 0; j <= n; j++ {
			dp[0][j] = j
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1]
				} else {
					dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1)
				}
			}
		}
		return dp[m][n]
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two strings
	lcs := func(s1, s2 string) string {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]byte, dp[m][n])
		i, j := m, n
		for i > 0 && j > 0 {
			if s1[i-1] == s2[j-1] {
				lcs[dp[i][j]-1] = s1[i-1]
				i--
				j--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return string(lcs)
	}

	// Function to calculate the LIS (Longest Increasing Subsequence) of a slice of integers
	lis := func(slice []int) []int {
		n := len(slice)
		dp := make([]int, n)
		parent := make([]int, n)
		length := 0
		for i := 0; i < n; i++ {
			lo, hi := 0, length
			for lo < hi {
				mid := lo + (hi-lo)/2
				if slice[i] > slice[dp[mid]] {
					lo = mid + 1
				} else {
					hi = mid
				}
			}
			dp[lo] = i
			if lo == length {
				length++
			}
			if lo > 0 {
				parent[i] = dp[lo-1]
			}
		}
		lis := make([]int, length)
		k := dp[length-1]
		for i := length - 1; i >= 0; i-- {
			lis[i] = slice[k]
			k = parent[k]
		}
		return lis
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two slices of integers
	lcsSlice := func(slice1, slice2 []int) []int {
		m, n := len(slice1), len(slice2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if slice1[i-1] == slice2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]int, dp[m][n])
		i, j, k := m, n, dp[m][n]-1
		for i > 0 && j > 0 {
			if slice1[i-1] == slice2[j-1] {
				lcs[k] = slice1[i-1]
				i--
				j--
				k--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return lcs
	}

	// Function to calculate the edit distance between two strings
	editDistance := func(s1, s2 string) int {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
			dp[i][0] = i
		}
		for j := 0; j <= n; j++ {
			dp[0][j] = j
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1]
				} else {
					dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1)
				}
			}
		}
		return dp[m][n]
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two strings
	lcs := func(s1, s2 string) string {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]byte, dp[m][n])
		i, j := m, n
		for i > 0 && j > 0 {
			if s1[i-1] == s2[j-1] {
				lcs[dp[i][j]-1] = s1[i-1]
				i--
				j--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return string(lcs)
	}

	// Function to calculate the LIS (Longest Increasing Subsequence) of a slice of integers
	lis := func(slice []int) []int {
		n := len(slice)
		dp := make([]int, n)
		parent := make([]int, n)
		length := 0
		for i := 0; i < n; i++ {
			lo, hi := 0, length
			for lo < hi {
				mid := lo + (hi-lo)/2
				if slice[i] > slice[dp[mid]] {
					lo = mid + 1
				} else {
					hi = mid
				}
			}
			dp[lo] = i
			if lo == length {
				length++
			}
			if lo > 0 {
				parent[i] = dp[lo-1]
			}
		}
		lis := make([]int, length)
		k := dp[length-1]
		for i := length - 1; i >= 0; i-- {
			lis[i] = slice[k]
			k = parent[k]
		}
		return lis
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two slices of integers
	lcsSlice := func(slice1, slice2 []int) []int {
		m, n := len(slice1), len(slice2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if slice1[i-1] == slice2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
		lcs := make([]int, dp[m][n])
		i, j, k := m, n, dp[m][n]-1
		for i > 0 && j > 0 {
			if slice1[i-1] == slice2[j-1] {
				lcs[k] = slice1[i-1]
				i--
				j--
				k--
			} else if dp[i-1][j] > dp[i][j-1] {
				i--
			} else {
				j--
			}
		}
		return lcs
	}

	// Function to calculate the edit distance between two strings
	editDistance := func(s1, s2 string) int {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
			dp[i][0] = i
		}
		for j := 0; j <= n; j++ {
			dp[0][j] = j
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if s1[i-1] == s2[j-1] {
					dp[i][j] = dp[i-1][j-1]
				} else {
					dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1)
				}
			}
		}
		return dp[m][n]
	}

	// Function to calculate the LCS (Longest Common Subsequence) of two strings
	lcs := func(s1, s2 string) string {
		m, n := len(s1), len(s2)
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
