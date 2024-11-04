package main

import (
	"fmt"
	"math/rand"
	"sort"
)

const mod = 1000000007

func main() {
	var n int64
	var m int
	fmt.Scan(&n, &m)

	a := make([]int64, m)
	for i := 0; i < m; i++ {
		a[i] = n / int64(m)
	}
	for i := int64(1); i <= n%int64(m); i++ {
		a[i]++
	}

	b := make([]int64, m)
	for i := 0; i < m; i++ {
		t := (i % m * i % m) % m
		b[t] += a[i]
	}

	ans := int64(0)
	for i := 0; i < m; i++ {
		if i == 0 {
			ans += b[i] * b[i]
		} else {
			ans += b[i] * b[m-i]
		}
	}
	fmt.Println(ans)
}

func id13(fact []int, n int64) {
	for i := 2; i <= n; i += 2 {
		fact[i] = 2
	}

	for i := 3; i <= n; i += 2 {
		if fact[i] == 0 {
			fact[i] = i
			for j := i; int64(j)*i <= n; j++ {
				fact[int64(i)*int64(j)] = i
			}
		}
	}
}

func gcd(p2, p22 int) int {
	if p2 == 0 {
		return p22
	}
	return gcd(p22%p2, p2)
}

func nextGreater(a []int64, ans []int) {
	stk := []int{0}

	for i := 1; i < len(a); i++ {
		if len(stk) > 0 {
			s := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			for a[s] < a[i] {
				ans[s] = i
				if len(stk) > 0 {
					s = stk[len(stk)-1]
					stk = stk[:len(stk)-1]
				} else {
					break
				}
			}
			if a[s] >= a[i] {
				stk = append(stk, s)
			}
		}
		stk = append(stk, i)
	}
}

func id7(a []int64, ans []int) {
	n := len(a)
	pans := make([]int, n)
	for i := range pans {
		pans[i] = -1
	}
	arev := make([]int64, n)
	for i := 0; i < n; i++ {
		arev[i] = a[n-1-i]
	}

	stk := []int{0}

	for i := 1; i < n; i++ {
		if len(stk) > 0 {
			s := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			for arev[s] < arev[i] {
				pans[s] = n - i - 1
				if len(stk) > 0 {
					s = stk[len(stk)-1]
					stk = stk[:len(stk)-1]
				} else {
					break
				}
			}
			if arev[s] >= arev[i] {
				stk = append(stk, s)
			}
		}
		stk = append(stk, i)
	}

	for i := 0; i < n; i++ {
		ans[i] = pans[n-i-1]
	}
}

func id0(a []int64, ans []int) {
	stk := []int{0}

	for i := 1; i < len(a); i++ {
		if len(stk) > 0 {
			s := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			for a[s] > a[i] {
				ans[s] = i
				if len(stk) > 0 {
					s = stk[len(stk)-1]
					stk = stk[:len(stk)-1]
				} else {
					break
				}
			}
			if a[s] <= a[i] {
				stk = append(stk, s)
			}
		}
		stk = append(stk, i)
	}
}

func lcm(numbers []int) int64 {
	lcm := int64(1)
	divisor := 2
	for {
		cnt := 0
		divisible := false
		for i := 0; i < len(numbers); i++ {
			if numbers[i] == 0 {
				return 0
			} else if numbers[i] < 0 {
				numbers[i] = -numbers[i]
			}
			if numbers[i] == 1 {
				cnt++
			}
			if numbers[i]%divisor == 0 {
				divisible = true
				numbers[i] /= divisor
			}
		}
		if divisible {
			lcm *= int64(divisor)
		} else {
			divisor++
		}
		if cnt == len(numbers) {
			return lcm
		}
	}
}

func fact(n int64) int64 {
	factorial := int64(1)
	for i := int64(1); i <= n; i++ {
		factorial *= i
	}
	return factorial
}

func choose(total, choose int64) int64 {
	if total < choose {
		return 0
	}
	if choose == 0 || choose == total {
		return 1
	}
	return (choose(total-1, choose-1) + choose(total-1, choose)) % mod
}

func suffle(a []int, gen *rand.Rand) []int {
	n := len(a)
	for i := 0; i < n; i++ {
		ind := gen.Intn(n-i) + i
		a[ind], a[i] = a[i], a[ind]
	}
	return a
}

func id12(a []int) []int {
	n := len(a)
	gen := rand.New(rand.NewSource(0))
	for i := 0; i < n; i++ {
		ind := gen.Intn(n-i) + i
		a[ind], a[i] = a[i], a[ind]
	}
	sort.Ints(a)
	return a
}

func floorSearch(arr []int, low, high, x int) int {
	if low > high {
		return -1
	}
	if x > arr[high] {
		return high
	}
	mid := (low + high) / 2
	if mid > 0 && arr[mid-1] < x && x < arr[mid] {
		return mid - 1
	}
	if x < arr[mid] {
		return floorSearch(arr, low, mid-1, x)
	}
	return floorSearch(arr, mid+1, high, x)
}

func swap(a, b int) (int, int) {
	return b, a
}

func id2(n int) []int {
	a := []int{}
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			a = append(a, i)
			n /= i
		}
	}
	if n != 1 {
		a = append(a, n)
	}
	return a
}

func sieve(isPrime []bool, n int) {
	for i := 1; i < n; i++ {
		isPrime[i] = true
	}
	isPrime[0] = false
	isPrime[1] = false

	for i := 2; i*i < n; i++ {
		if isPrime[i] {
			for j := 2 * i; j < n; j += i {
				isPrime[j] = false
			}
		}
	}
}

func lowerbound(net []int64, c2 int64) int {
	i := sort.Search(len(net), func(i int) bool { return net[i] >= c2 })
	if i < len(net) && net[i] == c2 {
		return i
	}
	return i - 1
}

func id3(dis []int, c2 int) int {
	i := sort.Search(len(dis), func(i int) bool { return dis[i] >= c2 })
	if i < len(dis) && dis[i] == c2 {
		return i
	}
	return i - 1
}

func uperbound(list []int, c2 int) int {
	i := sort.Search(len(list), func(i int) bool { return list[i] > c2 })
	return i
}

func id6(dis []int, c2 int) int {
	i := sort.Search(len(dis), func(i int) bool { return dis[i] >= c2 })
	return i
}

func GCD(a, b int) int {
	if b == 0 {
		return a
	}
	return GCD(b, a%b)
}

func GCDLong(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return GCDLong(b, a%b)
}

var d1, p1, q1 int

func id9(A, B int) {
	if B == 0 {
		d1 = A
		p1 = 1
		q1 = 0
	} else {
		id9(B, A%B)
		temp := p1
		p1 = q1
		q1 = temp - (A / B) * q1
	}
}

func LCM(a, b int64) int64 {
	return (a * b) / GCDLong(a, b)
}

func LCMInt(a, b int) int {
	return (a * b) / GCD(a, b)
}

func id14(x, n int) int {
	result := 1
	for n > 0 {
		if n%2 == 1 {
			result *= x
		}
		x *= x
		n /= 2
	}
	return result
}

func countDer(n int) []int {
	der := make([]int, n+1)
	der[0] = 1
	der[1] = 0
	der[2] = 1

	for i := 3; i <= n; i++ {
		der[i] = (i - 1) * (der[i-1] + der[i-2])
	}
	return der
}

func id11(n, k int) int64 {
	C := make([][]int64, n+1)
	for i := range C {
		C[i] = make([]int64, k+1)
	}

	for i := 0; i <= n; i++ {
		for j := 0; j <= min(i, k); j++ {
			if j == 0 || j == i {
				C[i][j] = 1
			} else {
				C[i][j] = C[i-1][j-1] + C[i-1][j]
			}
		}
	}
	return C[n][k]
}

func id14Long(x, n int64) int64 {
	result := int64(1)
	for n > 0 {
		if n%2 == 1 {
			result = (result * x) % mod
		}
		x = (x % mod * x % mod) % mod
		n /= 2
	}
	return result
}

func id10(x, n, M int) int {
	result := 1
	for n > 0 {
		if n%2 == 1 {
			result = (result * x) % M
		}
		x = (x * x) % M
		n /= 2
	}
	return result
}

func id10Long(x, n, M int64) int64 {
	result := int64(1)
	for n > 0 {
		if n%2 == 1 {
			result = (result * x) % M
		}
		x = (x * x) % M
		n /= 2
	}
	return result
}

func modInverse(A, M int) int {
	return id10(A, M-2, M)
}

func sie(A, M int64) int64 {
	return id10Long(A, M-2, M)
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

type pair struct {
	x, y int
}

func (p pair) String() string {
	return fmt.Sprintf("%d %d", p.x, p.y)
}

func (p pair) Equals(o pair) bool {
	return p.x == o.x && p.y == o.y
}

type triplet struct {
	x, y, z int
}

func (t triplet) String() string {
	return fmt.Sprintf("%d %d %d", t.x, t.y, t.z)
}

func (t triplet) Equals(o triplet) bool {
	return t.x == o.x && t.y == o.y && t.z == o.z
}
