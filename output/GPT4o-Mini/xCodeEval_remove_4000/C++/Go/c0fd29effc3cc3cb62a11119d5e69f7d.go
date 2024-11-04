package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"time"
)

type Mint struct {
	val int64
	mod int64
}

func NewMint(value int64, mod int64) Mint {
	value %= mod
	if value < 0 {
		value += mod
	}
	return Mint{val: value, mod: mod}
}

func (m Mint) Add(other Mint) Mint {
	return NewMint(m.val+other.val, m.mod)
}

func (m Mint) Sub(other Mint) Mint {
	return NewMint(m.val-other.val, m.mod)
}

func (m Mint) Mul(other Mint) Mint {
	return NewMint(m.val*other.val%m.mod, m.mod)
}

func (m Mint) Pow(power int64) Mint {
	result := Mint{val: 1, mod: m.mod}
	base := m
	for power > 0 {
		if power&1 == 1 {
			result = result.Mul(base)
		}
		base = base.Mul(base)
		power >>= 1
	}
	return result
}

func (m Mint) Inv() Mint {
	return m.Pow(m.mod - 2)
}

type HashTable struct {
	size int
	xp   []Mint
	hash []Mint
}

func NewHashTable(s string, m Mint) HashTable {
	lenS := len(s)
	ht := HashTable{
		size: lenS,
		xp:   make([]Mint, lenS+1),
		hash: make([]Mint, lenS+1),
	}
	ht.xp[0] = NewMint(1, m.mod)
	for i := 1; i <= lenS; i++ {
		ht.xp[i] = ht.xp[i-1].Mul(m)
	}
	ht.hash[lenS] = NewMint(0, m.mod)
	for i := lenS - 1; i >= 0; i-- {
		ht.hash[i] = ht.hash[i+1].Mul(m).Add(NewMint(int64(s[i]), m.mod))
	}
	return ht
}

func (ht *HashTable) GetHash(l, r int) Mint {
	return ht.hash[l].Sub(ht.hash[r+1].Mul(ht.xp[r-l+1]))
}

func main() {
	rand.Seed(time.Now().UnixNano())
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	var t string
	fmt.Fscan(reader, &t)

	var zp []int
	for i := 0; i < len(t); i++ {
		if t[i] == '0' {
			zp = append(zp, i)
		}
	}

	zpl := len(zp)
	m := Mint{val: int64([]int64{7, 11, 13, 17, 19}[rand.Intn(5)]), mod: 1_000_000_007}

	s := make([]byte, zpl)
	for i := 0; i < zpl; i++ {
		if zp[i]&1 == 0 {
			s[i] = '0'
		} else {
			s[i] = '1'
		}
	}

	hash := NewHashTable(string(s), m)

	for i := 0; i < zpl; i++ {
		if zp[i]&1 == 0 {
			s[i] = '1'
		} else {
			s[i] = '0'
		}
	}

	rhash := NewHashTable(string(s), m)

	var q int
	fmt.Fscan(reader, &q)
	for i := 0; i < q; i++ {
		var l1, l2, length int
		fmt.Fscan(reader, &l1, &l2, &length)
		l1--
		l2--

		d1 := lowerBound(zp, l1)
		d2 := lowerBound(zp, l2)

		z1 := upperBound(zp, l1+length-1) - d1
		z2 := upperBound(zp, l2+length-1) - d2

		if z1 != z2 {
			fmt.Fprintln(writer, "No")
			continue
		}

		if z1 == 0 {
			fmt.Fprintln(writer, "Yes")
			continue
		}

		hash1 := hash.GetHash(d1, d1+z1-1)
		hash2 := hash.GetHash(d2, d2+z1-1)
		if (l1&1) != (l2&1) {
			hash2 = rhash.GetHash(d2, d2+z1-1)
		}

		if hash1.val == hash2.val {
			fmt.Fprintln(writer, "Yes")
		} else {
			fmt.Fprintln(writer, "No")
		}
	}
}

func lowerBound(arr []int, target int) int {
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func upperBound(arr []int, target int) int {
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid] <= target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}
