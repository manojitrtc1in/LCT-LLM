package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var (
	nA, nB, nV, len, mx, cans int
	d                         [101][101][101]int
	prefix                    [101][1001]int
	c                         [101][101][101]int
	A, B, V, t                string
	ans                       []byte
)

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	A = "#" + scanner.Scan()
	B = "#" + scanner.Scan()
	V = "#" + scanner.Scan()

	nA = len(A)
	nB = len(B)
	nV = len(V)

	for iV := 0; iV < nV; iV++ {
		for C := 'A'; C <= 'Z'; C++ {
			prefix[iV][C] = iV + 1
			for prefix[iV][C] > 0 {
				if strings.HasPrefix(V[1:prefix[iV][C]], V[iV+2-prefix[iV][C]:prefix[iV][C]-1]+string(C)) {
					break
				}
				prefix[iV][C]--
			}
		}
	}

	for iA := 1; iA <= nA; iA++ {
		for iB := 1; iB <= nB; iB++ {
			for iV := 0; iV < nV; iV++ {
				d[iA][iB][iV] = -1
				if d[iA-1][iB][iV] > d[iA][iB][iV] {
					d[iA][iB][iV] = d[iA-1][iB][iV]
					c[iA][iB][iV] = -1
				}
				if d[iA][iB-1][iV] > d[iA][iB][iV] {
					d[iA][iB][iV] = d[iA][iB-1][iV]
					c[iA][iB][iV] = -2
				}
			}
			for iV := 0; iV < nV; iV++ {
				if A[iA] == B[iB] {
					if d[iA-1][iB-1][iV]+1 > d[iA][iB][prefix[iV][A[iA]]] {
						d[iA][iB][prefix[iV][A[iA]]] = d[iA-1][iB-1][iV] + 1
						c[iA][iB][prefix[iV][A[iA]]] = iV
					}
				}
			}
		}
	}

	mx = 0
	for iV := 0; iV < nV; iV++ {
		if d[nA][nB][iV] > mx {
			mx = d[nA][nB][iV]
			cans = iV
		}
	}

	if mx == 0 {
		fmt.Println(0)
	} else {
		iA := nA
		iB := nB
		iV := cans
		for iA > 0 && iB > 0 {
			if c[iA][iB][iV] == -1 {
				iA--
			} else if c[iA][iB][iV] == -2 {
				iB--
			} else {
				ans = append(ans, A[iA])
				iV = c[iA][iB][iV]
				iA--
				iB--
			}
		}
	}

	for i := len(ans) - 1; i >= 0; i-- {
		fmt.Printf("%c", ans[i])
	}
	fmt.Println()
}

func main() {
	solve()
}
