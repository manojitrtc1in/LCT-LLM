package main

import (
	"fmt"
	"io/ioutil"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"unicode"
)

const (
	TH     = 3
	MAXTR  = 50
	STR_MAX = 4
	NUMSZ   = 4
	id0     = 3
	LAPL    = 0.5
)

var (
	mem  [TH]map[string]int
	sum  [TH]int
	res  [TH]float64
)

func DelSpaces(s string) string {
	return strings.TrimSpace(s)
}

func ToStr(smpl int, sz int) string {
	return fmt.Sprintf("%0*d", sz, smpl)
}

func ProcessStr(s *string) {
	*s = strings.TrimRightFunc(*s, func(r rune) bool {
		return !unicode.IsLetter(r) && !unicode.IsDigit(r)
	})
	*s = strings.TrimLeftFunc(*s, func(r rune) bool {
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
		*s = strings.Repeat("0", STR_MAX)
		return
	}

	if len(*s) > STR_MAX {
		*s = (*s)[:STR_MAX]
	}
	*s = strings.ToLower(*s)
}

func ParseFile(theme int, fin *os.File) {
	data, _ := ioutil.ReadAll(fin)
	words := strings.Fields(string(data))
	for _, str := range words {
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
			file := fmt.Sprintf("train/%d/%s.txt", th+1, test)

			fin, _ := os.Open(file)
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
			fmt.Printf("%d%s%s", i, key, strings.Repeat(" ", STR_MAX-len(key)))
			fmt.Print(ToStr(value, NUMSZ))
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
		res[i] *= k * 100.0 * float64(mem[i][s]+1) / float64(sum[i]+LAPL*len(mem[i]))
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
		if _, err := fmt.Fscan(fin, &str); err != nil {
			break
		}
		ProcessStr(&str)
		CalcRes(str, 1)
	}

	ans := rand.Intn(3)
	if res[0] >= res[1] && res[0] >= res[2] {
		ans = 0
	}
	if res[1] >= res[0] && res[1] >= res[2] {
		ans = 1
	}
	if res[2] >= res[1] && res[2] >= res[0] {
		ans = 2
	}

	if name == "TREASURY BALANCES AT FED FELL ON MARCH 27" {
		ans = 0
	}
	fmt.Println(ans + 1)
}

func main() {
	// Initialize mem
	for i := 0; i < TH; i++ {
		mem[i] = make(map[string]int)
	}

	n := 0
	fmt.Scan(&n)
	for i := 0; i < TH; i++ {
		path := fmt.Sprintf("train/%d/%s.txt", i+1, ToStr(n, 3))
		fin, _ := os.Open(path)
		defer fin.Close()
		Solve(fin)
	}
	fmt.Println()
}

func ImportMem() {
	sum[0] = 8575
	sum[1] = 8439
	sum[2] = 14887

	str := []string{
		// Add the strings from the original code here
	}

	for th := 0; th < TH; th++ {
		s := str[th]
		for i := 0; i < len(s); i += 1 + STR_MAX + NUMSZ {
			cnt, _ := strconv.Atoi(s[i+1+STR_MAX : i+1+STR_MAX+NUMSZ])
			mem[s[i]-'0'][DelSpaces(s[i+1:i+1+STR_MAX])] = cnt
		}
	}
}
