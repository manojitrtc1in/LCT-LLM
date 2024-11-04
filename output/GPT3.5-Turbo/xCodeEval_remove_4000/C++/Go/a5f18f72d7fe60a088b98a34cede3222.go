package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

type Input struct {
	reader *bufio.Reader
}

func NewInput(r io.Reader) *Input {
	return &Input{reader: bufio.NewReader(r)}
}

func (in *Input) ReadInt() int {
	line, _ := in.readLine()
	num, _ := strconv.Atoi(line)
	return num
}

func (in *Input) ReadIntArray(n int) []int {
	line, _ := in.readLine()
	parts := strings.Split(line, " ")
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(parts[i])
	}
	return arr
}

func (in *Input) readLine() (string, error) {
	line, err := in.reader.ReadString('\n')
	if err != nil {
		return "", err
	}
	return strings.TrimSpace(line), nil
}

type Output struct {
	writer *bufio.Writer
}

func NewOutput(w io.Writer) *Output {
	return &Output{writer: bufio.NewWriter(w)}
}

func (out *Output) Print(args ...interface{}) {
	fmt.Fprint(out.writer, args...)
}

func (out *Output) Println(args ...interface{}) {
	fmt.Fprintln(out.writer, args...)
}

func (out *Output) Flush() {
	out.writer.Flush()
}

func primes(n int) []int {
	isPrime := make([]bool, n)
	for i := 2; i < n; i++ {
		isPrime[i] = true
	}
	for i := 2; i*i < n; i++ {
		if isPrime[i] {
			for j := i * i; j < n; j += i {
				isPrime[j] = false
			}
		}
	}
	primes := make([]int, 0)
	for i := 2; i < n; i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}
	return primes
}

func id7(n int) []int {
	res := make([]int, n)
	if n > 1 {
		res[1] = 1
	}
	for i := 2; i < n; i++ {
		if res[i] == 0 {
			res[i] = i
			if int64(i)*int64(i) < int64(n) {
				for j := i * i; j < n; j += i {
					res[j] = i
				}
			}
		}
	}
	return res
}

func getQty(arr []int, length int) []int {
	res := make([]int, length)
	for _, num := range arr {
		res[num]++
	}
	return res
}

func solve(input *Input, output *Output) {
	n := input.ReadInt()
	k := input.ReadIntArray(n)

	p := primes(5000)
	d := id7(5001)
	id0 := make([][]int, 5001)
	id0[0] = []int{}
	id0[1] = []int{}
	for i := 2; i < 5001; i++ {
		id0[i] = make([]int, len(id0[i-1]))
		copy(id0[i], id0[i-1])
		if d[i] == i {
			id0[i] = append(id0[i], 1)
		} else {
			for q := i; q > 1; q /= d[q] {
				index := sort.SearchInts(p, d[q])
				id0[i][index]++
			}
		}
	}

	answer := int64(0)
	q := getQty(k, 5001)
	lost := 0
	still := make([]bool, 5001)
	for i := range still {
		still[i] = true
	}
	cur := make([]int, len(p))
	for {
		for i := range cur {
			cur[i] = 0
		}
		for i := 0; i < 5001; i++ {
			if still[i] && len(id0[i]) > 0 {
				cur[len(id0[i])-1] += q[i]
			}
		}
		pos := 0
		maxVal := cur[0]
		for i := 1; i < len(cur); i++ {
			if cur[i] > maxVal {
				maxVal = cur[i]
				pos = i
			}
		}
		if maxVal <= n/2 {
			pos = -2
		}
		step := 1<<31 - 1
		for i := 0; i < 5001; i++ {
			if still[i] && len(id0[i]) > 0 && len(id0[i])-1 != pos {
				answer += int64(q[i]) * int64(sum(id0[i]))
				lost += q[i]
				still[i] = false
			} else if still[i] {
				if id0[i][len(id0[i])-1] < step {
					step = id0[i][len(id0[i])-1]
				}
			}
		}
		if pos == -2 {
			break
		}
		answer += int64(step) * int64(lost)
		for i := 0; i < 5001; i++ {
			if still[i] {
				id0[i][len(id0[i])-1] -= step
				if id0[i][len(id0[i])-1] == 0 {
					id0[i] = id0[i][:len(id0[i])-1]
				}
			}
		}
	}

	output.Println(answer)
}

func main() {
	input := NewInput(os.Stdin)
	output := NewOutput(os.Stdout)
	solve(input, output)
	output.Flush()
}
