package main

import (
	"fmt"
	"math"
)

type InputReader struct {
	stream []byte
	index  int
}

func NewInputReader(stream []byte) *InputReader {
	return &InputReader{stream: stream}
}

func (in *InputReader) read() byte {
	if in.index >= len(in.stream) {
		return 0
	}
	in.index++
	return in.stream[in.index-1]
}

func (in *InputReader) readInt() int {
	c := in.read()
	for isWhitespace(c) {
		c = in.read()
	}
	sgn := 1
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := 0
	for !isWhitespace(c) {
		if c < '0' || c > '9' {
			panic("Invalid input")
		}
		res *= 10
		res += int(c - '0')
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) readLong() int64 {
	c := in.read()
	for isWhitespace(c) {
		c = in.read()
	}
	sgn := int64(1)
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := int64(0)
	for !isWhitespace(c) {
		if c < '0' || c > '9' {
			panic("Invalid input")
		}
		res *= 10
		res += int64(c - '0')
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) readString() string {
	c := in.read()
	for isWhitespace(c) {
		c = in.read()
	}
	res := ""
	for !isWhitespace(c) {
		if !isValidCodePoint(c) {
			panic("Invalid input")
		}
		res += string(c)
		c = in.read()
	}
	return res
}

func isWhitespace(c byte) bool {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == 0
}

func isValidCodePoint(c byte) bool {
	return true
}

type OutputWriter struct {
	stream []byte
}

func NewOutputWriter() *OutputWriter {
	return &OutputWriter{}
}

func (out *OutputWriter) print(args ...interface{}) {
	for _, arg := range args {
		out.stream = append(out.stream, []byte(fmt.Sprintf("%v", arg))...)
	}
}

func (out *OutputWriter) println(args ...interface{}) {
	out.print(args...)
	out.stream = append(out.stream, '\n')
}

func (out *OutputWriter) flush() {
	fmt.Print(string(out.stream))
	out.stream = out.stream[:0]
}

type Pair struct {
	first  interface{}
	second interface{}
}

func makePair(first, second interface{}) Pair {
	return Pair{first: first, second: second}
}

type id11 struct {
	size     int
	data     []*HashEntry
	capacity int
	entrySet *id19
}

func Newid11(maxSize int) *id11 {
	return &id11{size: 0, capacity: 0, entrySet: Newid19()}
}

func (m *id11) setCapacity(size int) {
	m.capacity = 1 << uint(math.Max(4, math.Ceil(math.Log2(float64(size)))+1))
	m.data = make([]*HashEntry, m.capacity)
}

func (m *id11) add(key, value interface{}) {
	index := m.index(key)
	current := m.data[index]
	if current != nil {
		for {
			if current.key == key {
				current.value = value
				return
			}
			if current.next == nil {
				break
			}
			current = current.next
		}
		current.next = &HashEntry{key: key, value: value}
	} else {
		m.data[index] = &HashEntry{key: key, value: value}
	}
	m.size++
	if 2*m.size > m.capacity {
		oldData := m.data
		m.setCapacity(m.size)
		for _, entry := range oldData {
			for entry != nil {
				next := entry.next
				index := m.index(entry.key)
				entry.next = m.data[index]
				m.data[index] = entry
				entry = next
			}
		}
	}
}

func (m *id11) remove(key interface{}) {
	index := m.index(key)
	current := m.data[index]
	var last *HashEntry
	for current != nil {
		if current.key == key {
			if last == nil {
				m.data[index] = current.next
			} else {
				last.next = current.next
			}
			m.size--
			return
		}
		last = current
		current = current.next
	}
}

func (m *id11) get(key interface{}) interface{} {
	index := m.index(key)
	current := m.data[index]
	for current != nil {
		if current.key == key {
			return current.value
		}
		current = current.next
	}
	return nil
}

func (m *id11) containsKey(key interface{}) bool {
	index := m.index(key)
	current := m.data[index]
	for current != nil {
		if current.key == key {
			return true
		}
		current = current.next
	}
	return false
}

func (m *id11) size() int {
	return m.size
}

func (m *id11) index(key interface{}) int {
	return m.getHash(key.(int)) & (m.capacity - 1)
}

func (m *id11) getHash(h int) int {
	result := h
	for _, shift := range []int{1, 4, 7, 10, 13, 16, 19, 22, 25, 28} {
		result ^= h >> shift
	}
	return result
}

type HashEntry struct {
	key   interface{}
	value interface{}
	next  *HashEntry
}

type id19 struct {
	size int
	data []*HashEntry
}

func Newid19() *id19 {
	return &id19{size: 0}
}

func (s *id19) iterator() *id20 {
	return &id20{set: s, index: -1}
}

func (s *id19) size() int {
	return s.size
}

type id20 struct {
	set   *id19
	index int
	entry *HashEntry
}

func (i *id20) hasNext() bool {
	if i.entry != nil && i.entry.next != nil {
		return true
	}
	for i.index++; i.index < len(i.set.data); i.index++ {
		if i.set.data[i.index] != nil {
			return true
		}
	}
	return false
}

func (i *id20) next() Pair {
	if i.entry != nil && i.entry.next != nil {
		i.entry = i.entry.next
		return Pair{first: i.entry.key, second: i.entry.value}
	}
	for i.index++; i.index < len(i.set.data); i.index++ {
		if i.set.data[i.index] != nil {
			i.entry = i.set.data[i.index]
			return Pair{first: i.entry.key, second: i.entry.value}
		}
	}
	return Pair{}
}

func main() {
	in := NewInputReader([]byte{})
	out := NewOutputWriter()

	// Your code here

	out.flush()
}
