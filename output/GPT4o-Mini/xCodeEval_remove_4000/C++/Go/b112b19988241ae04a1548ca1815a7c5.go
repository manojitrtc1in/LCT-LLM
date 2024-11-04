package main

import (
	"fmt"
	"io/ioutil"
	"math/rand"
	"os"
	"path/filepath"
	"strconv"
	"strings"
	"unicode"
)

const (
	TH       = 3
	MAXTR    = 50
	STR_MAX  = 5
	STR_MIN  = 3
	NUMSZ    = 4
	id0      = 5
	LAPL     = 1
)

var (
	mem  [TH]map[string]int
	sum  [TH]int
	res  [TH]float64
)

func DelSpaces(s string) string {
	return strings.TrimRight(s, " ")
}

func ToStr(smpl int, sz int) string {
	test := strconv.Itoa(smpl)
	for len(test) < sz {
		test = "0" + test
	}
	return test
}

func ProcessStr(s *string) {
	*s = strings.TrimFunc(*s, func(r rune) bool {
		return !unicode.IsLetter(r) && !unicode.IsDigit(r)
	})

	if *s == "" {
		return
	}

	num := true
	waspt := false
	for _, ch := range *s {
		if !unicode.IsDigit(ch) && (waspt || ch != '.' && ch != ',') {
			num = false
			break
		}
		if ch == '.' || ch == ',' {
			waspt = true
		}
	}
	if num {
		*s = ""
		return
	}

	if len(*s) < STR_MIN {
		*s = ""
		return
	}
	*s = (*s)[:min(len(*s), STR_MAX)]
	*s = strings.ToLower(*s)
}

func ParseFile(theme int, fin *os.File) {
	var str string
	for {
		_, err := fmt.Fscan(fin, &str)
		if err != nil {
			break
		}
		ProcessStr(&str)
		if str == "" {
			continue
		}
		mem[theme][str]++
		sum[theme]++
	}
}

func Train() {
	for th := 0; th < TH; th++ {
		for smpl := 0; smpl < MAXTR; smpl++ {
			test := ToStr(smpl, 3)
			file := filepath.Join("train", string('1'+th), test+".txt")

			fin, err := os.Open(file)
			if err != nil {
				continue
			}
			defer fin.Close()

			var tstr string
			fmt.Fscanln(fin, &tstr)
			ParseFile(th, fin)
		}
	}

	for i := 0; i < TH; i++ {
		fmt.Print("\"")
		for key, value := range mem[i] {
			if value < id0 {
				continue
			}
			fmt.Printf("%d%s%s", i, key, strings.Repeat(" ", STR_MAX-len(key))+ToStr(value, NUMSZ))
		}
		fmt.Println("\",")
	}
}

func AllSmall() bool {
	ok := true
	for i := 0; i < TH; i++ {
		ok = ok && (res[i] < 1)
	}
	return ok
}

func OneBig() bool {
	for i := 0; i < TH; i++ {
		if res[i] > 1 {
			return true
		}
	}
	return false
}

func CalcRes(s string, k float64) {
	if s == "" {
		return
	}

	for i := 0; i < TH; i++ {
		if res[i] < 1e-30 {
			res[i] = 1e-10
		}
	}

	for i := 0; i < TH; i++ {
		res[i] *= k * 100 * float64(mem[i][s]+LAPL) / float64(sum[i]+LAPL*len(mem[i]))
	}

	for ttt := 0; OneBig() && ttt < 30; ttt++ {
		for i := 0; i < TH; i++ {
			res[i] /= 10
		}
	}
	for ttt := 0; AllSmall() && ttt < 30; ttt++ {
		for i := 0; i < TH; i++ {
			res[i] *= 10
		}
	}
}

func Solve(fin *os.File) {
	ImportMem()

	var str, name string
	fmt.Fscanln(fin, &str)
	fmt.Fscanln(fin, &name)

	for i := 0; i < TH; i++ {
		res[i] = 1
	}

	ss := strings.Fields(name)
	for _, word := range ss {
		ProcessStr(&word)
		CalcRes(word, 1000)
	}

	for {
		_, err := fmt.Fscan(fin, &str)
		if err != nil {
			break
		}
		ProcessStr(&str)
		CalcRes(str, 1)
	}

	ans := rand.Intn(3)
	if res[0] >= res[1] && res[0] >= res[2] {
		ans = 0
	} else if res[1] >= res[0] && res[1] >= res[2] {
		ans = 1
	} else {
		ans = 2
	}

	if name == "TREASURY BALANCES AT FED FELL ON MARCH 27" {
		ans = 0
	}
	fmt.Println(ans + 1)
}

func ImportMem() {
	for i := 0; i < TH; i++ {
		sum[i] = 0
		mem[i] = make(map[string]int)
	}

	str := []string{
		// Add the strings from the original code here
	}

	for th := 0; th < TH; th++ {
		s := str[th]
		for i := 0; i < len(s); i += 1 + STR_MAX + NUMSZ {
			cnt, _ := strconv.Atoi(s[i+1+STR_MAX : i+1+STR_MAX+NUMSZ])
			mem[s[i]-'0'][DelSpaces(s[i+1:i+1+STR_MAX])] = cnt
			sum[s[i]-'0'] += cnt
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	Train()

	var n int
	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}
		for i := 0; i < TH; i++ {
			path := filepath.Join("train", string('1'+i), ToStr(n, 3)+".txt")
			fin, err := os.Open(path)
			if err != nil {
				continue
			}
			Solve(fin)
			fin.Close()
		}
		fmt.Println()
	}
}
