package main

import (
	"strings"
	"fmt"
	"strconv"
	"errors"
	"io"
	"unicode/utf8"
	"bytes"
	"os"
)

type block struct {
	i, sz int
}
func main() {
	t, m, s := nextInt(), nextInt(), 1
	mem := make([]*block, 1)
	mem[0] = &block{0, m}
	for i := 0; i < t; i++ {
		op := nextWord()
		switch op {
		case "defragment":
			newMem := make([]*block, 0)
			sz := 0
			for _, b := range mem {
				if b.i != 0 {
					sz += b.sz
					newMem = append(newMem, b)
				}
			}
			if m - sz > 0 {
				mem = append(newMem, &block{0, m - sz})
			}
		case "alloc":
			sz, _ := strconv.Atoi(nextWord())
			allocated := false
			for i, b := range mem {
				if b.i == 0 && b.sz >= sz {
					allocated = true
					b.sz -= sz
					newMem := make([]*block, i)
					copy(newMem, mem)
					newMem = append(newMem, &block{s, sz})
					if b.sz > 0 {
						mem = append(newMem, mem[i:]...)
					} else {
						mem = append(newMem, mem[i + 1:]...)
					}
					printf("%d\n", s)
					s++
					break
				}
			}
			if !allocated {
				printf("NULL\n")
			}
		case "erase":
			idx, _ := strconv.Atoi(nextWord())
			deleted := false
			for i, b := range mem {
				if idx == 0 {
					break
				}
				if b.i == idx {
					deleted = true
					b.i = 0
					if i > 0 && mem[i - 1].i == 0 {
						mem[i - 1].sz += b.sz
						mem = append(mem[:i], mem[i + 1:]...)
					} else if len(mem) > i + 1 && mem[i + 1].i == 0 {
						mem[i + 1].sz += b.sz
						mem = append(mem[:i], mem[i + 1:]...)
					}
				}
			}
			if !deleted {
				printf("ILLEGAL_ERASE_ARGUMENT\n")
			}
		}
	}
}

var lineScanner *Scanner
var wordScanner *Scanner

func init() {
	lineScanner = NewScanner(os.Stdin)
	wordScanner = NewScanner(strings.NewReader(""))
	wordScanner.Split(ScanWords)
}

func printf(format string, a ...interface{}) {
	fmt.Printf(format, a...)
}
func nextLine() (string, error) {
	if !lineScanner.Scan() {
		if err := lineScanner.Err(); err != nil {
			panic(err)
		}
		return "", errors.New("nextLine: EOF reached")
	}
	return lineScanner.Text(), nil
}

func nextWord() string {
	for !wordScanner.Scan() {
		if err := wordScanner.Err(); err != nil {
			panic(err)
		}
		line, err := nextLine()
		if err != nil {
			return ""
		}
		wordScanner = NewScanner(strings.NewReader(line))
		wordScanner.Split(ScanWords)
	}
	return wordScanner.Text()
}

func nextInt() int {
	res, err := strconv.Atoi(nextWord())
	if err != nil {
		panic(err)
	}
	return res
}

func nextInt64() int64 {
	res, err := strconv.ParseInt(nextWord(), 10, 64)
	if err != nil {
		panic(err)
	}
	return res
}

func nextFloat64() float64 {
	res, err := strconv.ParseFloat(nextWord(), 64)
	if err != nil {
		panic(err)
	}
	return res
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

	empties      int       

	scanCalled   bool      

	done         bool      

}

































type SplitFunc func(data []byte, atEOF bool) (advance int, token []byte, err error)



var (
	ErrTooLong = errors.New("bufio.Scanner: token too long")
	ErrNegativeAdvance = errors.New("bufio.Scanner: SplitFunc returns negative advance count")
	ErrAdvanceTooFar = errors.New("bufio.Scanner: SplitFunc returns advance count beyond input")
)

const (








	MaxScanTokenSize = 2 * 1024 * 2014

	startBufSize = 4096 

)





func NewScanner(r io.Reader) *Scanner {
	return &Scanner{
		r:            r,
		split:        ScanLines,
		maxTokenSize: MaxScanTokenSize,
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

















var ErrFinalToken = errors.New("final token")

















func (s *Scanner) Scan() bool {
	if s.done {
		return false
	}
	s.scanCalled = true
	

	for {
		

		

		

		if s.end > s.start || s.err != nil {
			advance, token, err := s.split(s.buf[s.start:s.end], s.err != nil)
			if err != nil {
				if err == ErrFinalToken {
					s.token = token
					s.done = true
					return true
				}
				s.setErr(err)
				return false
			}
			if !s.advance(advance) {
				return false
			}
			s.token = token
			if token != nil {
				if s.err == nil || advance > 0 {
					s.empties = 0
				} else {
					

					s.empties++
					if s.empties > 100 {
						panic("bufio.Scan: 100 empty tokens without progressing")
					}
				}
				return true
			}
		}
		

		

		if s.err != nil {
			

			s.start = 0
			s.end = 0
			return false
		}
		

		

		

		if s.start > 0 && (s.end == len(s.buf) || s.start > len(s.buf) / 2) {
			copy(s.buf, s.buf[s.start:s.end])
			s.end -= s.start
			s.start = 0
		}
		

		if s.end == len(s.buf) {
			

			const maxInt = int(^uint(0) >> 1)
			if len(s.buf) >= s.maxTokenSize || len(s.buf) > maxInt / 2 {
				s.setErr(ErrTooLong)
				return false
			}
			newSize := len(s.buf) * 2
			if newSize == 0 {
				newSize = startBufSize
			}
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
		

		

		

		for loop := 0;; {
			n, err := s.r.Read(s.buf[s.end:len(s.buf)])
			s.end += n
			if err != nil {
				s.setErr(err)
				break
			}
			if n > 0 {
				s.empties = 0
				break
			}
			loop++
			if loop > 10 {
				s.setErr(io.ErrNoProgress)
				break
			}
		}
	}
}



func (s *Scanner) advance(n int) bool {
	if n < 0 {
		s.setErr(ErrNegativeAdvance)
		return false
	}
	if n > s.end - s.start {
		s.setErr(ErrAdvanceTooFar)
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



















func (s *Scanner) Buffer(buf []byte, max int) {
	if s.scanCalled {
		panic("Buffer called after Scan")
	}
	s.buf = buf[0:cap(buf)]
	s.maxTokenSize = max
}









func (s *Scanner) Split(split SplitFunc) {
	if s.scanCalled {
		panic("Split called after Scan")
	}
	s.split = split
}






func ScanBytes(data []byte, atEOF bool) (advance int, token []byte, err error) {
	if atEOF && len(data) == 0 {
		return 0, nil, nil
	}
	return 1, data[0:1], nil
}

var errorRune = []byte(string(utf8.RuneError))













func ScanRunes(data []byte, atEOF bool) (advance int, token []byte, err error) {
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
	if len(data) > 0 && data[len(data) - 1] == '\r' {
		return data[0 : len(data) - 1]
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
	case '\u1680', '\u2028', '\u2029', '\u202f', '\u205f', '\u3000':
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
	

	return start, nil, nil
}
