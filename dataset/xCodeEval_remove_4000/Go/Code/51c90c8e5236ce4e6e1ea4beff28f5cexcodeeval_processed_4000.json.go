package main

import (
	"bufio"
	"bytes"
	"io"
	"os"
	"sort"
	"strconv"
)

type Scanner struct {
	r            io.Reader
	split        bufio.SplitFunc
	maxTokenSize int
	token, buf   []byte
	start, end   int
}

func NewScanner(r io.Reader) *Scanner {
	return &Scanner{
		r:            r,
		split:        bufio.ScanWords,
		maxTokenSize: 16777216,
		buf:          make([]byte, 4096),
	}
}

func (s *Scanner) advance(n int) bool {
	if n < 0 || n > s.end-s.start {
		return false
	}
	s.start += n
	return true
}

func (s *Scanner) Text() string {
	return string(s.token)
}

func (s *Scanner) Scan() bool {
	for {
		if s.end > s.start {
			advance, token, err := s.split(s.buf[s.start:s.end], false)
			if err != nil || !s.advance(advance) {
				return false
			}
			s.token = token
			if token != nil {
				return true
			}
		}
		if s.start > 0 && (s.end == len(s.buf) || s.start > len(s.buf)/2) {
			copy(s.buf, s.buf[s.start:s.end])
			s.end -= s.start
			s.start = 0
		}
		if s.end == len(s.buf) {
			if len(s.buf) >= s.maxTokenSize {
				return false
			}
			newSize := len(s.buf) * 2
			if newSize > s.maxTokenSize {
				newSize = s.maxTokenSize
			}
			newBuf := make([]byte, newSize)
			copy(newBuf, s.buf[s.start:s.end])
			s.buf = newBuf
			s.end -= s.start
			s.start = 0
			continue
		}
		for loop := 0; ; {
			n, _ := s.r.Read(s.buf[s.end:len(s.buf)])
			s.end += n
			if n > 0 {
				break
			}
			loop++
			if loop > 100 {
				break
			}
		}
	}
}

func (s *Scanner) Split(split bufio.SplitFunc) {
	s.split = split
}

var w *bufio.Writer = bufio.NewWriter(os.Stdout)
var sc *Scanner = NewScanner(os.Stdin)

func next() string { sc.Scan(); return sc.Text() }
func nc() byte     { sc.Scan(); return sc.Text()[0] }

func ni32() int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func ni64() int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
}

func pri32(i ...int) {
	for _, ii := range i {
		w.WriteString(strconv.Itoa(ii))
		sp()
	}
}
func pri64(i ...int64) {
	for _, ii := range i {
		w.WriteString(strconv.FormatInt(ii, 10))
		sp()
	}
}
func sp()   { w.WriteByte(' ') }
func endl() { w.WriteByte('\n') }

const empty = -2147483648
const K = 256

func id1(s []byte) []int {
	n := len(s) + 1

	SA := make([]int, n)
	var bkt = make([]int, K)

	var s1 []int

	var n1 int = 0

	getBuckets := func(end bool) {
		for i := 0; i < K; i++ {
			bkt[i] = 0
		}
		for i := 0; i < n-1; i++ {
			bkt[s[i]]++
		}
		bkt[0]++
		if end {
			bkt[0]--
			for i := 1; i < K; i++ {
				bkt[i] += bkt[i-1]
			}
		} else {
			sum := 0
			for i := 0; i < K; i++ {
				sum += bkt[i]
				bkt[i] = sum - bkt[i]
			}
		}
	}

	induceSAl0 := func(suffix bool) {
		getBuckets(false)
		bkt[0]++
		for i := 0; i < n; i++ {
			if SA[i] > 0 {
				j := SA[i] - 1
				if j == len(s)-1 || s[j] >= s[j+1] {
					

					SA[bkt[s[j]]] = j
					bkt[s[j]]++
					if !suffix && i > 0 {
						SA[i] = 0
					}
				}
			}
		}
	}

	induceSAs0 := func(suffix bool) {
		getBuckets(true)
		for i := n - 1; i > 0; i-- {
			if SA[i] > 0 {
				j := SA[i] - 1
				

				if s[j] <= s[j+1] && bkt[s[j]] < i {
					SA[bkt[s[j]]] = j
					bkt[s[j]]--
					if !suffix {
						SA[i] = 0
					}
				}
			}
		}
	}

	getLengthofLMS := func(pos int) int {
		if pos == n-1 {
			return 1
		}
		dist, i := 0, 1

		for pos+i < n-1 && s[pos+i] >= s[pos+i-1] {
			i++
		}

		for ; pos+i <= n-1 && (pos+i == n-1 || s[pos+i] <= s[pos+i-1]); i++ {
			if pos+i == n-1 || s[pos+i] < s[pos+i-1] {
				dist = i
			}
		}
		return dist + 1
	}

	nameSubstr := func() int {
		for i := n1; i < n; i++ {
			SA[i] = empty
		}

		name, nameCtr := 0, 0
		prePos, preLen := 0, 0
		for i := 0; i < n1; i++ {
			diff := false
			pos := SA[i]
			length := getLengthofLMS(pos)

			if length != preLen {
				diff = true
			} else {
				for d := 0; d < length; d++ {
					if pos+d == n-1 || prePos+d == n-1 || s[pos+d] != s[prePos+d] {
						diff = true
						break
					}
				}
			}
			if diff {
				name = i
				nameCtr++
				SA[name] = 1
				prePos = pos
				preLen = length
			} else {
				SA[name]++
			}
			SA[n1+pos/2] = name
		}
		for i, j := n-1, n-1; i >= n1; i-- {
			if SA[i] != empty {
				SA[j] = SA[i]
				j--
			}
		}

		for succT, i := true, n1-1; i > 0; i-- {
			if s1[i-1] < s1[i] || (s1[i-1] == s1[i] && succT) {
				succT = true
				s1[i-1] += SA[s1[i-1]] - 1
			} else {
				succT = false
			}
		}
		return nameCtr
	}

	

	getBuckets(true)
	for i := 0; i < n; i++ {
		SA[i] = 0
	}
	for succT, i := false, n-2; i > 0; i-- {
		if s[i-1] < s[i] || (s[i-1] == s[i] && succT) {
			succT = true
		} else {
			if succT {
				SA[bkt[s[i]]] = i
				bkt[s[i]]--
			}
			succT = false
		}
	}
	SA[0] = n - 1
	

	

	induceSAl0(false)
	induceSAs0(false)

	for i := 0; i < n; i++ {
		if SA[i] > 0 {
			SA[n1] = SA[i]
			n1++
		}
	}

	s1 = SA[n-n1:]
	nameCtr := nameSubstr()
	if nameCtr < n1 {
		id0(s1, SA, n1, n-n1)
	} else {
		for i := 0; i < n1; i++ {
			SA[s1[i]] = i
		}
	}

	

	j := n1 - 2
	s1[j+1] = n - 1
	for succT, i := false, n-2; i > 0; i-- {
		if s[i-1] < s[i] || (s[i-1] == s[i] && succT) {
			succT = true
		} else {
			if succT {
				s1[j] = i
				j--
			}
			succT = false
		}
	}
	for i := 0; i < n1; i++ {
		SA[i] = s1[SA[i]]
	}
	for i := n1; i < n; i++ {
		SA[i] = 0

	}
	

	


	

	getBuckets(true)
	for i := n1 - 1; i > 0; i-- {
		j := SA[i]
		SA[i] = 0
		SA[bkt[s[j]]] = j
		bkt[s[j]]--
	}
	SA[0] = n - 1
	

	


	induceSAl0(true)
	induceSAs0(true)

	return SA[1:]

}

func id0(s, SA []int, n, m int) {
	var SA1, s1 []int

	var n1 int = 0

	putSuffix1 := func() {
		pos, pre := 0, -1
		for i := n1 - 1; i > 0; i-- {
			j := SA[i]
			SA[i] = empty
			if s[j] != pre {
				pre = s[j]
				pos = s[j]
			}
			SA[pos] = j
			pos--
		}
	}

	induceSAl1 := func(suffix bool) {
		step := 1
		for i := 0; i < n; i += step {
			step = 1
			j := SA[i] - 1
			if SA[i] <= 0 {
				continue
			}
			if s[j] < s[j+1] { 

				continue
			}
			d := SA[s[j]]
			if d >= 0 {
				foo := SA[s[j]]
				h := s[j] - 1
				for ; SA[h] >= 0 || SA[h] == empty; h-- {
					SA[h], foo = foo, SA[h]
				}
				SA[h] = foo
				if h < i {
					step = 0
				}
				d = empty
			}
			if d == empty {
				if s[j] < n-1 && SA[s[j]+1] == empty {
					SA[s[j]] = -1
					SA[s[j]+1] = j
				} else {
					SA[s[j]] = j
				}
			} else {
				pos := s[j] - d + 1
				if pos > n-1 || SA[pos] != empty {
					for h := 0; h < (-d); h++ {
						SA[s[j]+h] = SA[s[j]+h+1]
					}
					pos--
					if s[j] < i {
						step = 0
					}
				} else {
					SA[s[j]]--
				}
				SA[pos] = j
			}

			isL1 := (j+1 < n-1) &&
				(s[j+1] > s[j+2] || (s[j+1] == s[j+2] && s[j+1] < i))

			if (!suffix || !isL1) && i > 0 {
				if step == 0 {
					SA[i-1] = empty
				} else {
					SA[i] = empty
				}
			}
		}

		for i := 1; i < n; i++ {
			j := SA[i]
			if j < 0 && j != empty {
				for h := 0; h < (-j); h++ {
					SA[i+h] = SA[i+h+1]
				}
				SA[i-j] = empty
			}
		}

	}

	induceSAs1 := func(suffix bool) {
		step := 1
		for i := n - 1; i > 0; i -= step {
			step = 1
			j := SA[i] - 1
			if SA[i] <= 0 {
				continue
			}

			

			if (s[j] > s[j+1]) || (s[j] == s[j+1] && s[j] <= i) { 

				continue
			}
			d := SA[s[j]]
			if d >= 0 {
				foo := SA[s[j]]
				h := s[j] + 1
				for ; SA[h] >= 0 || SA[h] == empty; h++ {
					SA[h], foo = foo, SA[h]
				}
				SA[h] = foo
				if h > i {
					step = 0
				}
				d = empty
			}
			if d == empty {
				if SA[s[j]-1] == empty {
					SA[s[j]] = -1
					SA[s[j]-1] = j
				} else {
					SA[s[j]] = j
				}
			} else {
				pos := s[j] + d - 1
				if SA[pos] != empty {
					for h := 0; h < (-d); h++ {
						SA[s[j]-h] = SA[s[j]-h-1]
					}
					pos++
					if s[j] > i {
						step = 0
					}
				} else {
					SA[s[j]]--
				}
				SA[pos] = j
			}
			if !suffix {
				if step == 0 {
					SA[i+1] = empty
				} else {
					SA[i] = empty
				}
			}
		}
		if !suffix {
			for i := n - 1; i >= 0; i-- {
				j := SA[i]
				if j < 0 && j != empty {
					for h := 0; h < (-j); h++ {
						SA[i-h] = SA[i-h-1]
					}
					SA[i+j] = empty
				}
			}
		}
	}

	putSubstr1 := func() {
		h := 0
		for i := 0; i < n; i++ {
			SA[i] = empty
		}
		c, c1 := 0, s[n-2]
		t, t1 := false, false
		for i := n - 2; i > 0; i-- {
			c, t = c1, t1
			c1 = s[i-1]
			t1 = c1 < c || (c1 == c && t)
			if t && !t1 {
				if SA[c] >= 0 {
					for h = c + 1; SA[h] >= 0 && SA[h] != empty; h++ {
						SA[h], SA[c] = SA[c], SA[h]
					}
					SA[h] = SA[c]
					SA[c] = empty
				}
				d := SA[c]
				if d == empty {
					if SA[c-1] == empty {
						SA[c] = -1
						SA[c-1] = i
					} else {
						SA[c] = i
					}
				} else {
					pos := c + d - 1
					if SA[pos] != empty {
						for h = 0; h < (-d); h++ {
							SA[c-h] = SA[c-h-1]
						}
						pos++
					} else {
						SA[c]--
					}
					SA[pos] = i
				}
			}
		}
		for i := n - 1; i > 0; i-- {
			j := SA[i]
			if j < 0 && j != empty {
				for h = 0; h < (-j); h++ {
					SA[i-h] = SA[i-h-1]
				}
				SA[i-h] = empty
			}
		}
		SA[0] = n - 1
	}

	getLengthofLMS := func(x int) int {
		if x == n-1 {
			return 1
		}
		dist, i := 0, 1
		for s[x+i] >= s[x+i-1] {
			i++
		}
		for ; x+i <= n-1 && s[x+i] <= s[x+i-1]; i++ {
			if x+i == n-1 || s[x+i] < s[x+i-1] {
				dist = i
			}
		}
		return dist + 1
	}

	nameSubstr := func() int {
		for i := n1; i < n; i++ {
			SA[i] = empty
		}
		name, nameCtr := 0, 0
		prePos, preLen := 0, 0
		for i := 0; i < n1; i++ {
			diff := false
			pos := SA[i]
			length := getLengthofLMS(pos)
			if length != preLen {
				diff = true
			} else {
				for d := 0; d < length; d++ {
					if pos+d == n-1 || prePos+d == n-1 || s[pos+d] != s[prePos+d] {
						diff = true
						break
					}
				}
			}
			if diff {
				name = i
				nameCtr++
				SA[name] = 1
				prePos = pos
				preLen = length
			} else {
				SA[name]++
			}
			SA[n1+pos/2] = name
		}

		for i, j := n-1, m-1; i >= n1; i-- {
			if SA[i] != empty {
				SA[j] = SA[i]
				j--
			}
		}

		for succT, i := true, n1-1; i > 0; i-- {
			if s1[i-1] < s1[i] || (s1[i-1] == s1[i] && succT) {
				succT = true
				s1[i-1] += SA[s1[i-1]] - 1
			} else {
				succT = false
			}
		}

		return nameCtr
	}

	getSAlms := func() {
		j := n1 - 2
		s1[j+1] = n - 1
		for succT, i := false, n-2; i > 0; i-- {
			if s[i-1] < s[i] || (s[i-1] == s[i] && succT) {
				succT = true
			} else {
				if succT {
					s1[j] = i
					j--
				}
				succT = false
			}
		}
		for i := 0; i < n1; i++ {
			SA[i] = s1[SA[i]]
		}
		for i := n1; i < n; i++ {
			SA[i] = empty

		}
	}
	putSubstr1()
	induceSAl1(false)
	induceSAs1(false)

	for i := 0; i < n; i++ {
		if SA[i] > 0 {
			SA[n1] = SA[i]
			n1++
		}
	}
	SA1, s1 = SA, SA[m-n1:]

	nameCtr := nameSubstr()

	if nameCtr < n1 {
		id0(s1, SA1, n1, m-n1)
	} else {
		for i := 0; i < n1; i++ {
			SA1[s1[i]] = i
		}
	}

	getSAlms()

	putSuffix1()

	induceSAl1(true)
	induceSAs1(true)
}

type Index struct {
	data []byte
	sa   []int
}

func New(data []byte) *Index {
	return &Index{data, id1(data)}
}

func (x *Index) at(i int) []byte {
	return x.data[x.sa[i]:]
}

func (x *Index) lookupAll(s []byte) []int {
	i := sort.Search(len(x.sa), func(i int) bool { return bytes.Compare(x.at(i), s) >= 0 })
	j := i + sort.Search(len(x.sa)-i, func(j int) bool { return !bytes.HasPrefix(x.at(j+i), s) })
	return x.sa[i:j]
}

func (x *Index) Lookup(s []byte, n int) (result []int) {
	if len(s) > 0 && n != 0 {
		matches := x.lookupAll(s)
		if n < 0 || len(matches) < n {
			n = len(matches)
		}
		if n > 0 {
			result = make([]int, n)
			copy(result, matches)
		}
	}
	return
}

func main() {
	index := New([]byte(next()))
	heavy := index.Lookup([]byte("heavy"), -1)
	metal := index.Lookup([]byte("metal"), -1)
	sort.Ints(heavy)
	sort.Ints(metal)
	ans := int64(0)
	cur := 0
	for i := 0; i < len(heavy); i++ {
		for cur < len(metal) && metal[cur] <= heavy[i]+4 {
			cur++
		}
		ans += int64(len(metal) - cur)
	}
	pri64(ans)
	w.Flush()
}
