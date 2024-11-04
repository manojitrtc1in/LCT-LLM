package main

import (
	"fmt"
	"sort"
)

const (
	maxn1 = 31
	maxn2 = 100
	maxn3 = (1 << 20) + 10
	inf   = 1e18
)

var (
	C   [maxn2][maxn2]int64
	arr [2 * maxn1]int
	A, B, n, N int
	pa1, pb1 int
	pre1 int64
	opt  [maxn1][maxn1]int64
	vec  [maxn1][maxn3]int64
	pt   [maxn1]int
)

func doSave(l, r int) {
	for i := range pt {
		pt[i] = 0
	}
	MSKA, MSKB := 0, 0
	SZ := r - l
	for i := l; i < r; i++ {
		if arr[i] == 1 {
			MSKA += (1 << (i - l))
		}
		if arr[i] == -1 {
			MSKB += (1 << (i - l))
		}
	}
	for msk := 0; msk < (1 << SZ); msk++ {
		if (MSKA&msk) != MSKA || (MSKB&msk) != 0 || pa1+bitCount(msk) >= maxn1 {
			continue
		}
		cnta, cntb := pa1, pb1
		num := pre1
		for i := 0; i < SZ; i++ {
			if bit(msk, i) {
				num += C[cnta][A-1] * C[cntb][A]
				cnta++
			} else {
				num -= C[cnta][A] * C[cntb][A-1]
				cntb++
			}
		}
		vec[cnta][pt[cnta]] = num
		pt[cnta]++
	}
	for i := 0; i < maxn1; i++ {
		sort.Slice(vec[i][:pt[i]], func(a, b int) bool {
			return vec[i][a] < vec[i][b]
		})
	}
}

func doCalc(l, r int) (int64, int64) {
	MSKA, MSKB := 0, 0
	SZ := r - l
	ans := [2]int64{inf, 0}
	for i := l; i < r; i++ {
		if arr[i] == 1 {
			MSKA += (1 << (i - l))
		}
		if arr[i] == -1 {
			MSKB += (1 << (i - l))
		}
	}
	for msk := 0; msk < (1 << SZ); msk++ {
		pp := bitCount(msk)
		cnta := n - pp
		cntb := l - cnta
		start := cnta
		num := int64(0)
		if cnta < 0 || cntb < 0 || (MSKA&msk) != MSKA || (MSKB&msk) != 0 {
			continue
		}
		for i := 0; i < SZ; i++ {
			if bit(msk, i) {
				num += C[cnta][A-1] * C[cntb][A]
				cnta++
			} else {
				num -= C[cnta][A] * C[cntb][A-1]
				cntb++
			}
		}
		it := sort.Search(pt[start], func(i int) bool {
			return vec[start][i] >= -num
		})
		cand1 := [2]int64{inf, 0}
		cand2 := [2]int64{inf, 0}
		if it < pt[start] {
			x := vec[start][it]
			cand1[0] = num + x
			cand1[1] = int64(sort.Search(pt[start]-it, func(i int) bool {
				return vec[start][it+i] > x
			}))
		}
		if it > 0 {
			x := vec[start][it-1]
			cand2[0] = -num - x
			cand2[1] = int64(it - sort.Search(it, func(i int) bool {
				return vec[start][i] >= x
			}))
		}
		if cand1[0] < ans[0] {
			ans[0] = cand1[0]
			ans[1] = 0
		}
		if cand2[0] < ans[0] {
			ans[0] = cand2[0]
			ans[1] = 0
		}
		if cand1[0] == ans[0] {
			ans[1] += cand1[1]
		}
		if cand2[0] == ans[0] {
			ans[1] += cand2[1]
		}
	}
	return ans[0], ans[1]
}

func solve() (int64, int64) {
	ans := [2]int64{inf, 0}
	Ca, Cb := 0, 0
	for start := 0; start < N; start++ {
		mid := (start + 1 + N) >> 1
		if Ca < A && arr[start] != -1 && Ca+start+1 >= A && start >= 2*A-1 {
			pa1, pb1, pre1 := A, start+1-A, C[pb1][A]
			doSave(start+1, mid)
			p := doCalc(mid, N)
			if p[0] < ans[0] {
				ans[0] = p[0]
				ans[1] = 0
			}
			if p[0] == ans[0] {
				ans[1] += C[start-Ca-Cb][A-1-Ca] * p[1]
			}
		}
		if Cb < A && arr[start] != 1 && Cb+start+1 >= A && start >= 2*A-1 {
			pb1, pa1, pre1 := A, start+1-A, -C[pa1][A]
			doSave(start+1, mid)
			p := doCalc(mid, N)
			if p[0] < ans[0] {
				ans[0] = p[0]
				ans[1] = 0
			}
			if p[0] == ans[0] {
				ans[1] += C[start-Ca-Cb][A-1-Cb] * p[1]
			}
		}
		Ca += arr[start] == 1
		Cb += arr[start] == -1
	}
	return ans[0], ans[1]
}

func main() {
	C[0][0] = 1
	for i := 1; i < maxn2; i++ {
		C[i][i] = 1
		C[i][0] = 1
		for j := 1; j < i; j++ {
			C[i][j] = C[i-1][j] + C[i-1][j-1]
		}
	}
	fmt.Scan(&A, &B)
	n = A + B
	N = 2 * n
	var s string
	fmt.Scan(&s)
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			arr[i] = 1
		}
		if s[i] == 'B' {
			arr[i] = -1
		}
	}
	p := solve()
	if p[0] == opt[A][B] {
		fmt.Println(p[1])
	} else {
		fmt.Println(0)
	}
}

func bit(n, k int) bool {
	return (n>>k)&1 == 1
}

func bitCount(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}
