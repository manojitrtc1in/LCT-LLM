package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

const MOD int = 1e9 + 7

type Modular struct {
	val int
}

func (m Modular) Equal(other Modular) bool {
	return m.val == other.val
}

func (m Modular) NotEqual(other Modular) bool {
	return m.val != other.val
}

func (m Modular) LessThan(other Modular) bool {
	return m.val < other.val
}

func (m Modular) LessThanOrEqual(other Modular) bool {
	return m.val <= other.val
}

func (m Modular) GreaterThan(other Modular) bool {
	return m.val > other.val
}

func (m Modular) GreaterThanOrEqual(other Modular) bool {
	return m.val >= other.val
}

func (m Modular) Add(other Modular) Modular {
	return Modular{id0(m.val + other.val)}
}

func (m *Modular) AddAssign(other Modular) {
	*m = m.Add(other)
}

func (m Modular) Subtract(other Modular) Modular {
	return Modular{id0(m.val - other.val)}
}

func (m *Modular) SubtractAssign(other Modular) {
	*m = m.Subtract(other)
}

func (m Modular) Multiply(other Modular) Modular {
	return Modular{id0(m.val * other.val % MOD)}
}

func (m *Modular) MultiplyAssign(other Modular) {
	*m = m.Multiply(other)
}

func (m Modular) Pow(power int) Modular {
	ans := Modular{1}
	for power > 0 {
		if power&1 == 1 {
			ans = ans.Multiply(m)
		}
		m = m.Multiply(m)
		power >>= 1
	}
	return ans
}

func (m Modular) Inverse() Modular {
	return m.Pow(MOD - 2)
}

func (m Modular) Divide(other Modular) Modular {
	return m.Multiply(other.Inverse())
}

func (m *Modular) DivideAssign(other Modular) {
	*m = m.Divide(other)
}

func id0(val int) int {
	if val < 0 {
		val += MOD
	}
	if val >= MOD {
		val -= MOD
	}
	return val
}

func ModularFromString(s string) Modular {
	val, _ := strconv.Atoi(s)
	return Modular{val % MOD}
}

type HashTable struct {
	size int
	xp   []Modular
	hash []Modular
}

func (ht *HashTable) GetHash(l, r int) Modular {
	if l > r || r >= ht.size {
		panic("Invalid range")
	}
	return ht.hash[l].Subtract(ht.hash[r+1].Multiply(ht.xp[r-l+1]))
}

func NewHashTable(s string, m Modular) *HashTable {
	len := len(s)
	ht := &HashTable{
		size: len,
		xp:   make([]Modular, len+1),
		hash: make([]Modular, len+1),
	}

	ht.xp[0] = Modular{1}
	for i := 1; i <= len; i++ {
		ht.xp[i] = ht.xp[i-1].Multiply(m)
	}

	ht.hash[len] = Modular{0}
	for i := len - 1; i >= 0; i-- {
		ht.hash[i] = ht.hash[i+1].Multiply(m).Add(ModularFromString(string(s[i])))
	}

	return ht
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	readString := func() string {
		scanner.Scan()
		return scanner.Text()
	}

	readInt := func() int {
		val, _ := strconv.Atoi(readString())
		return val
	}

	n := readInt()
	t := readString()

	zp := make([]int, 0)
	for i := 0; i < len(t); i++ {
		if t[i] == '0' {
			zp = append(zp, i)
		}
	}

	zpl := len(zp)

	m := Modular{mul[rand.Intn(5)]}

	s := strings.Repeat("0", zpl)
	for i := 0; i < zpl; i++ {
		s = s[:i] + string('0'+(zp[i]&1)) + s[i+1:]
	}

	hash := NewHashTable(s, m)

	s = strings.Repeat("0", zpl)
	for i := 0; i < zpl; i++ {
		s = s[:i] + string('1'-(zp[i]&1)) + s[i+1:]
	}

	rhash := NewHashTable(s, m)

	for q := 0; q < n; q++ {
		l1 := readInt() - 1
		l2 := readInt() - 1
		len := readInt()

		d1 := sort.SearchInts(zp, l1)
		d2 := sort.SearchInts(zp, l2)

		z1 := sort.SearchInts(zp, l1+len-1) - d1
		z2 := sort.SearchInts(zp, l2+len-1) - d2

		if z1 != z2 {
			fmt.Println("No")
			continue
		}

		if z1 == 0 {
			fmt.Println("Yes")
			continue
		}

		hash1 := hash.GetHash(d1, d1+z1-1)
		hash2 := hash.GetHash(d2, d2+z1-1)
		if l1&1 != l2&1 {
			hash2 = rhash.GetHash(d2, d2+z1-1)
		}

		if hash1.Equal(hash2) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
