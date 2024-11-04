package main

import (
	"fmt"
	"math"
	"os"
)

type Reader struct {
	buffer []byte
}

func NewReader() *Reader {
	return &Reader{buffer: make([]byte, 1<<16)}
}

func (r *Reader) ReadLine() (string, error) {
	n, err := os.Stdin.Read(r.buffer)
	if err != nil {
		return "", err
	}
	return string(r.buffer[:n]), nil
}

func (r *Reader) NextLong() (int64, error) {
	var ret int64
	var c byte
	for {
		n, err := os.Stdin.Read(r.buffer)
		if err != nil {
			return 0, err
		}
		c = r.buffer[0]
		if c > ' ' {
			break
		}
	}
	neg := false
	if c == '-' {
		neg = true
		c = r.buffer[1]
	}
	for {
		ret = ret*10 + int64(c-'0')
		n, err := os.Stdin.Read(r.buffer)
		if err != nil {
			break
		}
		c = r.buffer[0]
		if c < '0' || c > '9' {
			break
		}
	}
	if neg {
		return -ret, nil
	}
	return ret, nil
}

func giveAns(x int64) int64 {
	id23 := int64(len(fmt.Sprintf("%d", x)))
	ans := int64(0)
	for i := int64(2); i < id23; i++ {
		ans += 9 * int64(math.Pow(10, float64(i-2)))
	}
	if id23 > 1 {
		ans += 9
	}
	if id23 == 1 {
		ans += x
	} else {
		firstDigit := int64(fmt.Sprintf("%d", x)[0] - '0')
		lastDigit := int64(fmt.Sprintf("%d", x)[id23-1] - '0')
		ans += (firstDigit - 1) * int64(math.Pow(10, float64(id23-2)))
		s := fmt.Sprintf("%d", x)
		for j := int64(1); j < id23-1; j++ {
			val := int64(1)
			digit := int64(s[j] - '0')
			val *= (digit * int64(math.Pow(10, float64(id23-j-2))))
			ans += val
		}
		if firstDigit <= lastDigit {
			ans++
		}
	}
	return ans
}

func main() {
	reader := NewReader()
	l, _ := reader.NextLong()
	r, _ := reader.NextLong()
	fmt.Println(giveAns(r) - giveAns(l-1))
}
