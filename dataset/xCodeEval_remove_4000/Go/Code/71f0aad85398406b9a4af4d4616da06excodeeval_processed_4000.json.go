package main

import (
	"bufio"
	"bytes"
	"errors"
	"flag"
	"fmt"
	"io"
	"log"
	"os"
	"runtime/pprof"
	"strconv"
	"time"
	"unicode/utf8"
	"math/rand"
)




const (
)

var (
	n int
	d1 [1 << 12]int64
	d2 [1 << 12]int64
	array [1 << 11][1 << 11]int
)

func calc1(sj, si int) {
	res := int64(0)
	j := sj
	i := si
	for j >= 0 && i >= 0 && j < n && i < n {
		res += int64(array[j][i])
		j--
		i++
	}
	d1[sj + si] = res
}

func calc2(sj, si int) {
	res := int64(0)
	j := sj
	i := si
	for j >= 0 && i >= 0 && j < n && i < n {
		res += int64(array[j][i])
		j++
		i++
	}
	d2[(1 << 11) + sj - si] = res
}

func solve() {
	n = readInt()
	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			array[j][i] = readInt()
		}
	}
	for i := 0; i < n; i++ {
		calc1(i, 0)
		calc2(i, 0)

		calc1(n - 1, i)
		calc2(0, i)
	}

	best1 := int64(0)
	x1 := -1 
	y1 := -1
	best2 := int64(0)
	x2 := -1 
	y2 := -1

	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			if ((j + i) & 1) == 1 {
				value := d1[j + i] + d2[(1 << 11) + j - i] - int64(array[j][i])
				if best1 <= value {
					best1 = value
					x1 = j
					y1 = i
				}
			} else {
				value := d1[j + i] + d2[(1 << 11) + j - i] - int64(array[j][i])
				if best2 <= value {
					best2 = value
					x2 = j
					y2 = i
				}
			}
		}
	}
	id5(best1 + best2)
	printLine()
	printInt(x1 + 1)
	printSpace()
	printInt(y1 + 1)
	printSpace()
	printInt(x2 + 1)
	printSpace()
	printInt(y2 + 1)
	printLine()

} 






var (
	scanner *Scanner
	writer  *bufio.Writer
	logger  *log.Logger
)

func main() {
	dbg := flag.Bool("dbg", false, "Equals true, if run is in debug mode.")
	opt := flag.Bool("opt", false, "Equals true, if run is in optimized mode.")
	flag.Parse()

	var (
		input  *os.File
		output *os.File
	)

	if *opt || *dbg {
		startTime := time.Now()
		defer func() {
			println(fmt.Sprintf("Time: %.5fs", time.Since(startTime).Seconds()))
		}()
		input, _ = os.Open("/home/outside/coding/workspace/go/io/input.txt")
		output, _ = os.Create("/home/outside/coding/workspace/go/io/output.txt")
		logger = log.New(output, "log: ", 0)
		if *dbg {
			cpuprofile, _ := os.Create("/home/outside/coding/workspace/go/io/cpuprofile.txt")
			pprof.StartCPUProfile(cpuprofile)
			defer cpuprofile.Close()
			defer pprof.StopCPUProfile()
		}
	} else {
		input = os.Stdin
		output = os.Stdout
		

		

	}
	defer input.Close()
	defer output.Close()

	scanner = NewScanner(input)
	scanner.Split(bufio.ScanWords)

	writer = bufio.NewWriter(output)
	defer writer.Flush()

	rand.Seed(int64(time.Now().Nanosecond()))
	solve()
}




func readString() string {
	scanner.Scan()
	ans := scanner.Text()
	return ans
}

func readLine() string {
	scanner.Split(bufio.ScanLines)
	defer scanner.Split(bufio.ScanWords)
	return readString()
}

func readInt() int {
	ans, _ := strconv.ParseInt(readString(), 10, 0)
	return int(ans)
}

func id8() int64 {
	ans, _ := strconv.ParseInt(readString(), 10, 64)
	return ans
}

func id4() float64 {
	ans, _ := strconv.ParseFloat(readString(), 64)
	return ans
}




func printString(value string) {
	writer.WriteString(value)
}

func printLine() {
	printString("\n")
}

func printSpace() {
	printString(" ")
}

func printInt(value int) {
	printString(strconv.FormatInt(int64(value), 10))
}

func id5(value int64) {
	printString(strconv.FormatInt(value, 10))
}

func id6(value float64) {
	printString(strconv.FormatFloat(value, 'f', 20, 64))
}




func logln(value ...interface{}) {
	writer.Flush()
	logger.Println(value...)
}
func logf(format string, value ...interface{}) {
	writer.Flush()
	logger.Printf(format, value...)
}




type Tuple struct {
	a, b int
}

func (p Tuple) Equals(key Key) bool {
	return p.a == key.(Tuple).a
}

func (p Tuple) Less(key Key) bool {
	return p.a < key.(Tuple).a
}

type TupleSlice []Tuple

func (p TupleSlice) Len() int {
	return len(p)
}

func (p TupleSlice) Less(j, i int) bool {
	return p[j].a < p[i].a
}

func (p TupleSlice) Swap(j, i int) {
	p[j], p[i] = p[i], p[j]
}




func maxInt(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func minInt(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func absInt(a int) int {
	if a > 0 {
		return a
	} else {
		return -a
	}
}

func id2(a, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func id9(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func id14(a int64) int64 {
	if a > 0 {
		return a
	} else {
		return -a
	}
}

func id11(a, b float64) float64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func id0(a, b float64) float64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func id12(a float64) float64 {
	if a > 0 {
		return a
	} else {
		return -a
	}
}




type Int int

func (p Int) Equals(key Key) bool {
	return int(p) == int(key.(Int))
}

func (p Int) Less(key Key) bool {
	return int(p) < int(key.(Int))
}




type Key interface {
	Equals(key Key) bool
	Less(key Key) bool
}

type node struct {
	key   Key
	left  *node
	right *node
}

func newNode(key Key) *node {
	return &node{key, nil, nil}
}

type SplayTree struct {
	root *node
	tmp  *node
	len  int
}

func id10() *SplayTree {
	return &SplayTree{nil, newNode(nil), 0}
}

func rotateLeft(x, p *node) {
	p.right = x.left
	x.left = p
}

func rotateRight(x, p *node) {
	p.left = x.right
	x.right = p
}

func (p *SplayTree) splay(x *node, key Key) *node {
	if x == nil {
		return nil
	}

	left := p.tmp
	right := p.tmp

	for {
		if key.Less(x.key) {
			y := x.left
			if y == nil {
				break
			}
			if key.Less(y.key) { 

				rotateRight(y, x)
				x = y
				if x.left == nil {
					break
				}
			}
			

			right.left = x
			right = x
			

			x = x.left
		} else if x.key.Less(key) {
			y := x.right
			if y == nil {
				break
			}
			if y.key.Less(key) { 

				rotateLeft(y, x)
				x = y
				if x.right == nil {
					break
				}
			}
			

			left.right = x
			left = x
			

			x = x.right
		} else {
			break
		}
	}

	left.right = x.left
	right.left = x.right
	x.left = p.tmp.right
	x.right = p.tmp.left

	return x
}



func (p *SplayTree) split(key Key) (left, right *node) {
	p.root = p.splay(p.root, key)
	if p.root.key.Equals(key) || p.root.key.Less(key) {
		right := p.root.right
		p.root.right = nil
		return p.root, right
	} else {
		left := p.root.left
		p.root.left = nil
		return left, p.root
	}
}



func (p *SplayTree) join(left, right *node) *node {
	if left == nil {
		return right
	} else if right == nil {
		return left
	}
	left = p.splay(left, right.key)
	left.right = right
	return left
}

type Set interface {
	Len() int
	Insert(key Key) error
	Find(key Key) bool
	Remove(key Key) error
}

func NewSet() Set {
	return Set(id10())
}

func (p *SplayTree) Len() int {
	return p.len
}

func (p *SplayTree) Insert(key Key) error {
	if p.root == nil {
		p.root = newNode(key)
		p.len++
	} else {
		p.root = p.splay(p.root, key)
		if p.root.key.Equals(key) {
			return errors.New("Such key already exists")
		} else {
			left, right := p.split(key)
			p.root = newNode(key)
			p.root.left = left
			p.root.right = right
			p.len++
		}
	}
	return nil
}

func (p *SplayTree) Find(key Key) bool {
	if p.root == nil {
		return false
	}
	p.root = p.splay(p.root, key)
	return p.root.key.Equals(key)
}

func (p *SplayTree) Remove(key Key) error {
	p.root = p.splay(p.root, key)
	if p.root == nil || !p.root.key.Equals(key) {
		return errors.New("Such key doesn't exist")
	}
	p.root = p.join(p.split(key))
	return nil
}



































type Scanner struct {
	r            io.Reader 

	split        SplitFunc 

	maxTokenSize int       

	token        []byte    

	buf          []byte    

	start        int       

	end          int       

	err          error     

}

































type SplitFunc func(data []byte, atEOF bool) (advance int, token []byte, err error)



var (
	id1         = errors.New("bufio.Scanner: token too long")
	id7 = errors.New("bufio.Scanner: SplitFunc returns negative advance count")
	id13   = errors.New("bufio.Scanner: SplitFunc returns advance count beyond input")
)

const (
	

	

	MaxScanTokenSize = 1 << 20
)





func NewScanner(r io.Reader) *Scanner {
	return &Scanner{
		r:            r,
		split:        ScanLines,
		maxTokenSize: MaxScanTokenSize,
		buf:          make([]byte, 4096), 

	}
}



func (s *Scanner) Err() error {
	if s.err == io.EOF {
		return nil
	}
	return s.err
}







func (s *Scanner) Bytes() []byte {
	return s.token
}





func (s *Scanner) Text() string {
	return string(s.token)
}













func (s *Scanner) Scan() bool {
	

	for {
		

		if s.end > s.start {
			advance, token, err := s.split(s.buf[s.start:s.end], s.err != nil)
			if err != nil {
				s.setErr(err)
				return false
			}
			if !s.advance(advance) {
				return false
			}
			s.token = token
			if token != nil {
				return true
			}
		}
		

		

		if s.err != nil {
			

			s.start = 0
			s.end = 0
			return false
		}
		

		

		

		if s.start > 0 && (s.end == len(s.buf) || s.start > len(s.buf)/2) {
			copy(s.buf, s.buf[s.start:s.end])
			s.end -= s.start
			s.start = 0
		}
		

		if s.end == len(s.buf) {
			if len(s.buf) >= s.maxTokenSize {
				s.setErr(id1)
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
			n, err := s.r.Read(s.buf[s.end:len(s.buf)])
			s.end += n
			if err != nil {
				s.setErr(err)
				break
			}
			if n > 0 {
				break
			}
			loop++
			if loop > 100 {
				s.setErr(io.ErrNoProgress)
				break
			}
		}
	}
}



func (s *Scanner) advance(n int) bool {
	if n < 0 {
		s.setErr(id7)
		return false
	}
	if n > s.end-s.start {
		s.setErr(id13)
		return false
	}
	s.start += n
	return true
}



func (s *Scanner) setErr(err error) {
	if s.err == nil || s.err == io.EOF {
		s.err = err
	}
}





func (s *Scanner) Split(split SplitFunc) {
	s.split = split
}






func ScanBytes(data []byte, atEOF bool) (advance int, token []byte, err error) {
	if atEOF && len(data) == 0 {
		return 0, nil, nil
	}
	return 1, data[0:1], nil
}

var errorRune = []byte(string(utf8.RuneError))













func id3(data []byte, atEOF bool) (advance int, token []byte, err error) {
	if atEOF && len(data) == 0 {
		return 0, nil, nil
	}

	

	if data[0] < utf8.RuneSelf {
		return 1, data[0:1], nil
	}

	

	_, width := utf8.DecodeRune(data)
	if width > 1 {
		

		

		return width, data[0:width], nil
	}

	

	

	

	if !atEOF && !utf8.FullRune(data) {
		

		return 0, nil, nil
	}

	

	

	

	return 1, errorRune, nil
}



func dropCR(data []byte) []byte {
	if len(data) > 0 && data[len(data)-1] == '\r' {
		return data[0 : len(data)-1]
	}
	return data
}













func ScanLines(data []byte, atEOF bool) (advance int, token []byte, err error) {
	if atEOF && len(data) == 0 {
		return 0, nil, nil
	}
	if i := bytes.IndexByte(data, '\n'); i >= 0 {
		

		return i + 1, dropCR(data[0:i]), nil
	}
	

	if atEOF {
		return len(data), dropCR(data), nil
	}
	

	return 0, nil, nil
}







func isSpace(r rune) bool {
	if r <= '\u00FF' {
		

		switch r {
		case ' ', '\t', '\n', '\v', '\f', '\r':
			return true
		case '\u0085', '\u00A0':
			return true
		}
		return false
	}
	

	if '\u2000' <= r && r <= '\u200a' {
		return true
	}
	switch r {
	case '\u1680', '\u180e', '\u2028', '\u2029', '\u202f', '\u205f', '\u3000':
		return true
	}
	return false
}









func ScanWords(data []byte, atEOF bool) (advance int, token []byte, err error) {
	

	start := 0
	for width := 0; start < len(data); start += width {
		var r rune
		r, width = utf8.DecodeRune(data[start:])
		if !isSpace(r) {
			break
		}
	}
	if atEOF && len(data) == 0 {
		return 0, nil, nil
	}
	

	for width, i := 0, start; i < len(data); i += width {
		var r rune
		r, width = utf8.DecodeRune(data[i:])
		if isSpace(r) {
			return i + width, data[start:i], nil
		}
	}
	

	if atEOF && len(data) > start {
		return len(data), data[start:], nil
	}
	

	return 0, nil, nil
}