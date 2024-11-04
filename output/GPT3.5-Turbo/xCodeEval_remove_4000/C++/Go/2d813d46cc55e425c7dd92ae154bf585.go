package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	n, k, p, c = 0, 0, 0, 0
	a          [505][505]int
	out        [125005]int
	chk        [125005]int
	ans, best  = 0, 0
	di         = []int{1, 0, -1, 0}
	dj         = []int{0, 1, 0, -1}
	x          byte
	t          pos
	q          []pos
)

type pos struct {
	i, j int
}

func solve() {
	scan(&n, &k)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			scan(&x)
			if x == '.' {
				a[i][j] = -1
			} else {
				a[i][j] = 0
			}
		}
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if a[i][j] == -1 {
				c++
				a[i][j] = c
				q = append(q, pos{i, j})
				for len(q) > 0 {
					t = q[0]
					q = q[1:]
					for k := 0; k < 4; k++ {
						if a[t.i+di[k]][t.j+dj[k]] == -1 {
							a[t.i+di[k]][t.j+dj[k]] = c
							q = append(q, pos{t.i + di[k], t.j + dj[k]})
						}
					}
				}
			}
		}
	}
	for i := 0; i <= n+1; i++ {
		for j := 0; j <= n+1; j++ {
			out[a[i][j]]++
		}
	}
	for addi := 0; addi <= n-k; addi++ {
		for i := addi + 1; i <= addi+k; i++ {
			for j := 0; j < k; j++ {
				out[a[i][j]]--
			}
		}
		for addj := 0; addj <= n-k; addj++ {
			ans = k * k
			for i := addi + 1; i <= addi+k; i++ {
				out[a[i][addj]]++
				out[a[i][addj+k]]--
			}
			for i := addi + 1; i <= addi+k; i++ {
				p = a[i][addj]
				if p != 0 && chk[p] == 0 {
					chk[p] = 1
					ans += out[p]
				}
				p = a[i][addj+k+1]
				if p != 0 && chk[p] == 0 {
					chk[p] = 1
					ans += out[p]
				}
			}
			for j := addj + 1; j <= addj+k; j++ {
				p = a[addi][j]
				if p != 0 && chk[p] == 0 {
					chk[p] = 1
					ans += out[p]
				}
				p = a[addi+k+1][j]
				if p != 0 && chk[p] == 0 {
					chk[p] = 1
					ans += out[p]
				}
			}
			for i := addi + 1; i <= addi+k; i++ {
				chk[a[i][addj]] = 0
				chk[a[i][addj+k+1]] = 0
			}
			for j := addj + 1; j <= addj+k; j++ {
				chk[a[addi][j]] = 0
				chk[a[addi+k+1][j]] = 0
			}
			if ans > best {
				best = ans
			}
		}
		for i := addi + 1; i <= addi+k; i++ {
			for j := n - k + 1; j <= n; j++ {
				out[a[i][j]]++
			}
		}
	}
	fmt.Println(best)
}

func main() {
	scan := newScanner()
	solve()
}

type scanner struct {
	scanner *bufio.Scanner
}

func newScanner() *scanner {
	return &scanner{bufio.NewScanner(os.Stdin)}
}

func (s *scanner) scan(a ...interface{}) {
	for i := 0; i < len(a); i++ {
		s.scanner.Scan()
		switch v := a[i].(type) {
		case *int:
			*v, _ = strconv.Atoi(s.scanner.Text())
		case *int64:
			*v, _ = strconv.ParseInt(s.scanner.Text(), 10, 64)
		case *float64:
			*v, _ = strconv.ParseFloat(s.scanner.Text(), 64)
		case *string:
			*v = s.scanner.Text()
		case *[]int:
			s.scanSlice(v)
		case *[]int64:
			s.scanSlice(v)
		case *[]float64:
			s.scanSlice(v)
		}
	}
}

func (s *scanner) scanSlice(a interface{}) {
	s.scanner.Scan()
	t := strings.Fields(s.scanner.Text())
	switch v := a.(type) {
	case *[]int:
		for i := 0; i < len(t); i++ {
			(*v)[i], _ = strconv.Atoi(t[i])
		}
	case *[]int64:
		for i := 0; i < len(t); i++ {
			(*v)[i], _ = strconv.ParseInt(t[i], 10, 64)
		}
	case *[]float64:
		for i := 0; i < len(t); i++ {
			(*v)[i], _ = strconv.ParseFloat(t[i], 64)
		}
	}
}

func (s *scanner) scanStringSlice() []string {
	s.scanner.Scan()
	return strings.Fields(s.scanner.Text())
}

func (s *scanner) scanStringMatrix(n int) [][]string {
	matrix := make([][]string, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanStringSlice()
	}
	return matrix
}

func (s *scanner) scanIntMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanIntSlice()
	}
	return matrix
}

func (s *scanner) scanIntSlice() []int {
	s.scanner.Scan()
	t := strings.Fields(s.scanner.Text())
	res := make([]int, len(t))
	for i := 0; i < len(t); i++ {
		res[i], _ = strconv.Atoi(t[i])
	}
	return res
}

func (s *scanner) scanInt64Slice() []int64 {
	s.scanner.Scan()
	t := strings.Fields(s.scanner.Text())
	res := make([]int64, len(t))
	for i := 0; i < len(t); i++ {
		res[i], _ = strconv.ParseInt(t[i], 10, 64)
	}
	return res
}

func (s *scanner) scanFloat64Slice() []float64 {
	s.scanner.Scan()
	t := strings.Fields(s.scanner.Text())
	res := make([]float64, len(t))
	for i := 0; i < len(t); i++ {
		res[i], _ = strconv.ParseFloat(t[i], 64)
	}
	return res
}

func (s *scanner) scanString() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *scanner) scanInt() int {
	s.scanner.Scan()
	res, _ := strconv.Atoi(s.scanner.Text())
	return res
}

func (s *scanner) scanInt64() int64 {
	s.scanner.Scan()
	res, _ := strconv.ParseInt(s.scanner.Text(), 10, 64)
	return res
}

func (s *scanner) scanFloat64() float64 {
	s.scanner.Scan()
	res, _ := strconv.ParseFloat(s.scanner.Text(), 64)
	return res
}

func (s *scanner) scanStringMatrix(n, m int) [][]string {
	matrix := make([][]string, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanStringSlice()
	}
	return matrix
}

func (s *scanner) scanIntMatrix(n, m int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanIntSlice()
	}
	return matrix
}

func (s *scanner) scanInt64Matrix(n, m int) [][]int64 {
	matrix := make([][]int64, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanInt64Slice()
	}
	return matrix
}

func (s *scanner) scanFloat64Matrix(n, m int) [][]float64 {
	matrix := make([][]float64, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanFloat64Slice()
	}
	return matrix
}

func (s *scanner) scanRuneSlice() []rune {
	s.scanner.Scan()
	t := s.scanner.Text()
	res := make([]rune, len(t))
	for i, c := range t {
		res[i] = c
	}
	return res
}

func (s *scanner) scanRuneMatrix(n int) [][]rune {
	matrix := make([][]rune, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanRuneSlice()
	}
	return matrix
}

func (s *scanner) scanRune() rune {
	s.scanner.Scan()
	t := s.scanner.Text()
	return rune(t[0])
}

func (s *scanner) scanRuneMatrix(n, m int) [][]rune {
	matrix := make([][]rune, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanRuneSlice()
	}
	return matrix
}

func (s *scanner) scanRuneSliceMatrix(n int) [][][]rune {
	matrix := make([][][]rune, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanRuneMatrix(n)
	}
	return matrix
}

func (s *scanner) scanRuneMatrixMatrix(n, m int) [][][]rune {
	matrix := make([][][]rune, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanRuneMatrix(m)
	}
	return matrix
}

func (s *scanner) scanRuneSliceMatrix(n, m int) [][][]rune {
	matrix := make([][][]rune, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanRuneSliceMatrix(m)
	}
	return matrix
}

func (s *scanner) scanBoolSlice() []bool {
	s.scanner.Scan()
	t := strings.Fields(s.scanner.Text())
	res := make([]bool, len(t))
	for i := 0; i < len(t); i++ {
		res[i], _ = strconv.ParseBool(t[i])
	}
	return res
}

func (s *scanner) scanBoolMatrix(n int) [][]bool {
	matrix := make([][]bool, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanBoolSlice()
	}
	return matrix
}

func (s *scanner) scanBool() bool {
	s.scanner.Scan()
	res, _ := strconv.ParseBool(s.scanner.Text())
	return res
}

func (s *scanner) scanBoolMatrix(n, m int) [][]bool {
	matrix := make([][]bool, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanBoolSlice()
	}
	return matrix
}

func (s *scanner) scanSliceOfSlice(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanIntSlice()
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSlice(n int) [][][]int {
	matrix := make([][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSlice(n int) [][][][]int {
	matrix := make([][][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSliceOfSlice(n int) [][][][][]int {
	matrix := make([][][][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSliceOfSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n int) [][][][][][]int {
	matrix := make([][][][][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSliceOfSliceOfSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n int) [][][][][][][]int {
	matrix := make([][][][][][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n int) [][][][][][][][]int {
	matrix := make([][][][][][][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n int) [][][][][][][][][]int {
	matrix := make([][][][][][][][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n int) [][][][][][][][][][]int {
	matrix := make([][][][][][][][][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n int) [][][][][][][][][][][]int {
	matrix := make([][][][][][][][][][][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = s.scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n)
	}
	return matrix
}

func (s *scanner) scanSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSliceOfSlice(n int) [][][][][][][][][][][][]int {
	matrix := make([][][][][][][][][][][][]int, n)
	for i := 0; i < n; i++ {
