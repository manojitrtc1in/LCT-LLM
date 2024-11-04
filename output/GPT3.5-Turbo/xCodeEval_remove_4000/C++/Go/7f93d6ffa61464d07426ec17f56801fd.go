package main

import (
	"fmt"
	"sort"
)

const (
	s    = "(:LW:LYL]Uee1CUCUb]eCUUdU:L]L]iegUceib]jjfCUaUcegUccb]jjUd`L]h]jlUeeceliejfCUL]]L\\cUdUcbCUb]jh]d]k]eZUe]kmejjkL]]k]keeCUUdU]ZUce]dUeeeL\\cCTSUZT[(:L(:L:LZUc^1CQCUL\\_CSUZP:LYL]UdCUUdUL]]]1CUCUUdCUUUL]]ZU\\:L]L]]gUccUdjUd]1CRL[YLUSUZUUICUL]]L\\[]b\\bCUb]eUd]]`L[]b]cc_CSUZT[CUUb\\ZUcc`LUQCKCTCLG1C'1C1CRL[V(:H:LCTW:JLRG1CQCUL\\:LL\\LCUUU(:L:LL\\:LLLCUURLT1CUCUU`L[[L\\cL\\U(:ICSQCLJLRLL@:LCUUCTSUZTZ:LZU]L\\UUXCSUZU[[W:JLRKS:LLZTRL[[XCLH:B:K:C?1@'1@1C:LL&(:(:ICL(::K:/1C1CRLP:JLRICSSP(:H:JLP:JJICSS:KG1CQCSU:LLJLURLSN(:1CC1BJ:K:JI(:ICSQCKCTCL@:LCTYLSST1CCTCTLL(::K:C@:JLCK:LLL1BJ(98:@9A(9/(80:9CC/ 1'1@:C 11B18(:0:ICG1ACI@:JJI/1@1ACG1AA@:JJ1B@(:H:JL1CCACLICJG 1(::(9A1B1A@/1@:JH:B:K:C91C:KQCJJK8::K:KCC/11B1:91AC:B1CCC(9A 0/181:(A/(8099BA/ 0'109? /1728(90:9B/11B18:::A/1819B/1118::9198(:0::G1AA1BJ1B:/ /(86(1/1711)/10::(98:@9@A1A:C1B::B89:@:AAA/01708A19@991AA@(1/ '/08AGJ8'A019:B8&)/(018&'(.+A/2819:8(09(A191J8(A09:8(0(A19288A/1819@(8889A8918&('0/ (((0(("
	MAX  = 1000000
)

var (
	pr  = [8]int{2, 3, 5, 7, 11, 13, 17, 19}
	num = [100][2]int{
		{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 1}, {1, 2}, {1, 3},
		{1, 4}, {1, 5}, {1, 6}, {1, 7}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5},
		{2, 6}, {2, 7}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7},
		{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {5, 0}, {5, 1},
		{5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {6, 0}, {6, 1}, {6, 2}, {6, 3},
		{6, 4}, {6, 5}, {6, 6}, {6, 7}, {7, 0}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6},
		{7, 7}, {7, 8}, {8, 1}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9},
		{9, 3}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}, {9, 10}, {10, 7},
	}
	L   [300][]int
	ans [300][300]int
	cnt int
	mp  [MAX + 1]int
)

func init(i, x, la int, v []int) {
	L[cnt] = v
	cnt++
	sz := len(v)
	v = append(v, 0)
	for d := 1; d <= la && (x /= pr[i]); d++ {
		v[sz]++
		init(i+1, x, d, v)
	}
	v = v[:len(v)-1]
}

func get(x int) int {
	v := make([]int, 0)
	for x > 1 {
		p := mp[x]
		c := 0
		for x%p == 0 {
			x /= p
			c++
		}
		v = append(v, -c)
	}
	sort.Ints(v)
	for i := range v {
		v[i] *= -1
	}
	return sort.Search(len(L), func(i int) bool {
		return L[i] >= v
	})
}

func main() {
	v := make([]int, 0)
	init(0, MAX, 1<<30, v)
	for i := 2; i <= MAX; i++ {
		if mp[i] == 0 {
			for j := i; j <= MAX; j += i {
				if mp[j] == 0 {
					mp[j] = i
				}
			}
		}
	}
	i := 0
	j := 1
	for _, c := range s {
		for t := 0; t < 2; t++ {
			x := num[c-32][t]
			ans[i][j] = x
			ans[j][i] = x
			j++
			if j == cnt {
				j = i + 1
			}
		}
	}
	var t int
	fmt.Scan(&t)
	for t > 0 {
		var a, b int
		fmt.Scan(&a, &b)
		fmt.Println(ans[get(a)][get(b)])
		t--
	}
}
