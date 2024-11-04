package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	inf     = int(1e8)
	modular = newModular(998244353)
	power   = newPower(modular)
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	local := os.Getenv("ONLINE_JUDGE") == ""
	async := false

	charset := newCharset("ascii")

	io := newFastIO(reader, writer, charset)
	task := newTask(io, newDebug(local))

	if async {
		go task.run()
	} else {
		task.run()
	}

	if local {
		io.cache.WriteString("\n\n--memory -- \n" + strconv.Itoa(int((runtime.MemStats.TotalAlloc-runtime.MemStats.HeapReleased)>>20)) + "M")
	}

	io.flush()
}

type FastIO struct {
	reader  *bufio.Reader
	writer  *bufio.Writer
	charset *Charset
	cache   *strings.Builder
	next    int
}

func newFastIO(reader *bufio.Reader, writer *bufio.Writer, charset *Charset) *FastIO {
	return &FastIO{
		reader:  reader,
		writer:  writer,
		charset: charset,
		cache:   &strings.Builder{},
		next:    -1,
	}
}

func (io *FastIO) read() int {
	for io.next == -1 || io.next == 32 {
		b, err := io.reader.ReadByte()
		if err != nil {
			return -1
		}
		io.next = int(b)
	}
	res := io.next
	io.next = -1
	return res
}

func (io *FastIO) skipBlank() {
	for io.next >= 0 && io.next <= 32 {
		io.next = io.read()
	}
}

func (io *FastIO) readInt() int {
	sign := 1

	io.skipBlank()
	if io.next == '+' || io.next == '-' {
		if io.next == '-' {
			sign = -1
		}
		io.next = io.read()
	}

	val := 0
	if sign == 1 {
		for io.next >= '0' && io.next <= '9' {
			val = val*10 + io.next - '0'
			io.next = io.read()
		}
	} else {
		for io.next >= '0' && io.next <= '9' {
			val = val*10 - io.next + '0'
			io.next = io.read()
		}
	}

	return val
}

func (io *FastIO) readLong() int64 {
	sign := int64(1)

	io.skipBlank()
	if io.next == '+' || io.next == '-' {
		if io.next == '-' {
			sign = -1
		}
		io.next = io.read()
	}

	val := int64(0)
	if sign == 1 {
		for io.next >= '0' && io.next <= '9' {
			val = val*10 + int64(io.next-'0')
			io.next = io.read()
		}
	} else {
		for io.next >= '0' && io.next <= '9' {
			val = val*10 - int64(io.next-'0')
			io.next = io.read()
		}
	}

	return val
}

func (io *FastIO) readDouble() float64 {
	sign := true
	io.skipBlank()
	if io.next == '+' || io.next == '-' {
		sign = io.next == '+'
		io.next = io.read()
	}

	val := int64(0)
	for io.next >= '0' && io.next <= '9' {
		val = val*10 + int64(io.next-'0')
		io.next = io.read()
	}
	if io.next != '.' {
		if sign {
			return float64(val)
		}
		return -float64(val)
	}
	io.next = io.read()
	radix := int64(1)
	point := int64(0)
	for io.next >= '0' && io.next <= '9' {
		point = point*10 + int64(io.next-'0')
		radix = radix * 10
		io.next = io.read()
	}
	result := float64(val) + float64(point)/float64(radix)
	if sign {
		return result
	}
	return -result
}

func (io *FastIO) readString() string {
	io.cache.Reset()
	io.skipBlank()

	for io.next > 32 {
		io.cache.WriteByte(byte(io.next))
		io.next = io.read()
	}

	return io.cache.String()
}

func (io *FastIO) flush() {
	io.writer.WriteString(io.cache.String())
	io.writer.Flush()
	io.cache.Reset()
}

type Charset struct {
	name string
}

func newCharset(name string) *Charset {
	return &Charset{
		name: name,
	}
}

type Task struct {
	io    *FastIO
	debug *Debug
	inf   int
}

func newTask(io *FastIO, debug *Debug) *Task {
	return &Task{
		io:    io,
		debug: debug,
		inf:   inf,
	}
}

func (task *Task) run() {
	task.solve()
}

func (task *Task) solve() {
	n := task.io.readInt()
	m := task.io.readInt()
	a := make([]int, n)
	count := make([]int, 2)
	for i := 0; i < n; i++ {
		a[i] = task.io.readInt()
		count[a[i]%2]++
	}
	w := make([]int, n)
	for i := 0; i < n; i++ {
		w[i] = task.io.readInt()
		if a[i]%2 == 0 {
			hW += w[i]
		} else {
			fW += w[i]
		}
	}

	inv := make([]int, m*2+1)
	for i := 0; i < m*2+1; i++ {
		inv[i] = power.inverse(modular.valueOf(hW+fW+i-m))
	}

	f := make([][]int, m+1)
	h := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		f[i] = make([]int, m+1)
		h[i] = make([]int, m+1)
	}

	for i := 0; i <= m; i++ {
		for j := 0; j <= m; j++ {
			f[i][j] = -1
			h[i][j] = -1
		}
	}

	for i := 0; i <= m; i++ {
		f[i][0] = 1
		h[i][0] = 1
	}

	for i := 0; i < n; i++ {
		if a[i]%2 == 1 {
			task.io.cache.WriteString(strconv.Itoa(modular.mul(w[i], f(0, m))))
		} else {
			task.io.cache.WriteString(strconv.Itoa(modular.mul(w[i], h(0, m))))
		}
		task.io.cache.WriteByte('\n')
	}
}

func (task *Task) f(i, k int) int {
	f := task.f
	if f[i][k] == -1 {
		j := (m - k) - i
		fixI := modular.plus(i, fW)
		fixJ := modular.plus(hW, -j)
		f[i][k] = 0
		inv := inv[i-j+m]
		f[i][k] = modular.plus(f[i][k], modular.mul(modular.mul(fixI+1, inv), f(i+1, k-1)))
		f[i][k] = modular.plus(f[i][k], modular.mul(modular.mul(fixJ, inv), f(i, k-1)))
	}
	return f[i][k]
}

func (task *Task) h(i, k int) int {
	h := task.h
	if h[i][k] == -1 {
		j := (m - k) - i
		fixI := modular.plus(i, fW)
		fixJ := modular.plus(hW, -j)
		h[i][k] = 0
		inv := inv[i-j+m]
		h[i][k] = modular.plus(h[i][k], modular.mul(modular.mul(fixJ-1, inv), h(i, k-1)))
		h[i][k] = modular.plus(h[i][k], modular.mul(modular.mul(fixI, inv), h(i+1, k-1)))
	}
	return h[i][k]
}

type Modular struct {
	m int
}

func newModular(m int) *Modular {
	return &Modular{
		m: m,
	}
}

func (modular *Modular) valueOf(x int) int {
	x %= modular.m
	if x < 0 {
		x += modular.m
	}
	return x
}

func (modular *Modular) mul(x, y int) int {
	return modular.valueOf((int64(x) * int64(y)) % int64(modular.m))
}

func (modular *Modular) plus(x, y int) int {
	return modular.valueOf(x + y)
}

type Power struct {
	modular *Modular
}

func newPower(modular *Modular) *Power {
	return &Power{
		modular: modular,
	}
}

func (power *Power) pow(x int, n int64) int {
	if n == 0 {
		return 1
	}
	r := power.pow(x, n>>1)
	r = power.modular.mul(r, r)
	if (n & 1) == 1 {
		r = power.modular.mul(r, x)
	}
	return r
}

func (power *Power) inverse(x int) int {
	return power.pow(x, power.modular.m-2)
}

type Debug struct {
	allowDebug bool
}

func newDebug(allowDebug bool) *Debug {
	return &Debug{
		allowDebug: allowDebug,
	}
}

func (debug *Debug) assertTrue(flag bool) {
	if !debug.allowDebug {
		return
	}
	if !flag {
		debug.fail()
	}
}

func (debug *Debug) fail() {
	panic("assertion failed")
}

func (debug *Debug) assertFalse(flag bool) {
	if !debug.allowDebug {
		return
	}
	if flag {
		debug.fail()
	}
}

func (debug *Debug) debug(name string, x interface{}) {
	if !debug.allowDebug {
		return
	}
	fmt.Printf("%s = %v\n", name, x)
}

func (debug *Debug) debugf(name string, format string, x ...interface{}) {
	if !debug.allowDebug {
		return
	}
	fmt.Printf("%s = "+format+"\n", append([]interface{}{name}, x...)...)
}

func (debug *Debug) debugln(x ...interface{}) {
	if !debug.allowDebug {
		return
	}
	fmt.Println(x...)
}
