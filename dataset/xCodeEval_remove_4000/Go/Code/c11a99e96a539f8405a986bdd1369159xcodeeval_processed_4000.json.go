package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strings"
)

func main() {
	id17(os.Stdin, os.Stdout)
}

func cf(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	fmt.Fscan(in, &n)

	fmt.Fprintln(out, n)
}

func id17(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k int
	var s string
	fmt.Fscan(in, &n, &k, &s)
	ss := []string{}
	for i := range s {
		ss = append(ss, strings.Repeat(s[:i+1], (k+i)/(i+1)))
	}
	sort.Strings(ss)

	fmt.Fprintln(out, ss[0][:k])
}

func id11(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var x string
	fmt.Fscan(in, &x)
	if !strings.Contains(x, ".") {
		x += "."
	}
	x = strings.Trim(x, "0")
	idx := strings.Index(x, ".")
	e := idx - strings.IndexAny(x, "123456789")
	if e > 0 {
		e--
	}
	x = strings.Trim(x[:idx]+x[idx+1:], "0")
	if len(x) > 1 {
		x = x[:1] + "." + x[1:]
	}
	fmt.Fprint(out, x)
	if e != 0 {
		fmt.Fprint(out, "E", e)
	}
}

func id10(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m, k int
	fmt.Fscan(in, &n, &m, &k)
	sums := make([]int64, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &sums[i])
		sums[i] += sums[i-1]
	}
	f := make([]int64, n+1)
	for j := 1; j <= k; j++ {
		ff := make([]int64, n+1)
		for i := j * m; i <= n; i++ {
			ff[i] = max64(ff[i-1], sums[i]-sums[i-m]+f[i-m])
		}
		f = ff
	}

	fmt.Fprintln(out, f[n])
}

func id5(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var t int
	fmt.Fscan(in, &t)
next:
	for ; t > 0; t-- {
		var n, k int
		fmt.Fscan(in, &n, &k)
		h := make([]int, n)
		for i := range h {
			fmt.Fscan(in, &h[i])
		}
		pre := []int{h[0], h[0]}
		for i := 1; i < n; i++ {
			cur := []int{max(pre[0]-k+1, h[i]), min(pre[1]+k-1, h[i]+k-1)}
			if cur[0] > cur[1] {
				fmt.Fprintln(out, "NO")
				continue next
			}
			pre = cur
		}
		if pre[0] == h[n-1] {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
	}
}

func id1(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m, x int
	fmt.Fscan(in, &n, &m)
	nums1, nums2 := make([]int64, n+1), make([]int64, m+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &nums1[i])
		nums1[i] += nums1[i-1]
	}
	for i := 1; i <= m; i++ {
		fmt.Fscan(in, &nums2[i])
		nums2[i] += nums2[i-1]
	}
	fmt.Fscan(in, &x)
	mins1, mins2 := make([]int64, n+1), make([]int64, m+1)
	for i := 1; i <= n; i++ {
		mins1[i] = nums1[i]
		for j := i + 1; j <= n; j++ {
			mins1[i] = min64(mins1[i], nums1[j]-nums1[j-i])
		}
	}
	for i := 1; i <= m; i++ {
		mins2[i] = nums2[i]
		for j := i + 1; j <= m; j++ {
			mins2[i] = min64(mins2[i], nums2[j]-nums2[j-i])
		}
	}
	ans := 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if mins1[i]*mins2[j] <= int64(x) && i*j > ans {
				ans = i * j
			}
		}
	}

	fmt.Fprintln(out, ans)
}

func id18(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m int
	fmt.Fscan(in, &n, &m)
	arr, preArr := make([]int, n+1), make([]int, n+1)
	var pre, cur int
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &cur)
		preArr[cur] = pre
		arr[pre], pre = cur, cur
	}
	for ; m > 1; m-- {
		pre = 0
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &cur)
			if arr[pre] != cur {
				preArr[cur] = 0
				arr[pre] = 0
			}
			pre = cur
		}
		arr[cur] = 0
	}
	ans := int64(n)
	for i := 1; i <= n; i++ {
		if arr[i] > 0 {
			cnt, id := 0, i
			for preArr[id] != 0 {
				id = preArr[id]
			}
			for arr[id] != 0 {
				arr[id], id = 0, arr[id]
				cnt++
				ans += int64(cnt)
			}
		}
	}

	fmt.Fprintln(out, ans)
}

func id12(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	fmt.Fscan(in, &n)
	nums1, nums2 := make([]int64, n), make([]int64, n)
	for i := range nums1 {
		fmt.Fscan(in, &nums1[i])
	}
	for i := range nums2 {
		fmt.Fscan(in, &nums2[i])
	}
	f := make([]int64, n+1)
	for i := range nums1 {
		f[i+1] = f[i] + nums1[i]*nums2[i]
	}
	ans := f[n]
	for i := range nums1 {
		for j, d, sum := i, 1, nums1[i]*nums2[i]; j-d >= 0 && j+d < n; d++ {
			sum += nums1[j-d]*nums2[j+d] + nums1[j+d]*nums2[j-d]
			ans = max64(ans, sum+f[n]-f[j+d+1]+f[j-d])
		}
		for j1, j2, d, sum := i, i+1, 0, int64(0); j1-d >= 0 && j2+d < n; d++ {
			sum += nums1[j2+d]*nums2[j1-d] + nums1[j1-d]*nums2[j2+d]
			ans = max64(ans, sum+f[n]-f[j2+d+1]+f[j1-d])
		}
	}

	fmt.Fprintln(out, ans)
}

func id3(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	fmt.Fscan(in, &n)
	nums := make([][2]int64, n)
	for i := range nums {
		fmt.Fscan(in, &nums[i][0], &nums[i][1])
	}
	var t int
	fmt.Fscan(in, &t)
	p := make([]int64, t+2)
	p[t+1] = 1e12
	pre := int64(0)
	for i := 1; i <= t; i++ {
		fmt.Fscan(in, &p[i])
		pre, p[i] = p[i], p[i]-pre
	}
	sort.Slice(nums, func(i, j int) bool {
		return nums[i][1] < nums[j][1]
	})
	sum := int64(0)
	for i, j := 0, 1; i < len(nums); {
		sum += min64(nums[i][0], p[j]) * nums[i][1] * int64(j)
		if nums[i][0] > p[j] {
			nums[i][0] -= p[j]
			j++
		} else {
			p[j] -= nums[i][0]
			i++
		}
	}

	fmt.Fprintln(out, sum)
}

func id16(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s string
	fmt.Fscan(in, &s)
	sum, minSum, cnt := 0, len(s), 0
	for i := range s {
		if s[i] == '(' {
			sum++
		} else if s[i] == ')' {
			sum--
		} else {
			sum--
			minSum = sum
			cnt++
		}
		if sum < 0 {
			fmt.Fprintln(out, -1)
			return
		}
		minSum = min(minSum, sum)
	}
	if minSum < sum {
		fmt.Fprintln(out, -1)
	} else {
		fmt.Fprintln(out, strings.Repeat("1\n", cnt-1), sum+1)
	}
}

func id6(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	fmt.Fscan(in, &n)
	for ; n > 0; n-- {
		var s, c string
		fmt.Fscan(in, &s, &c)
		cs := []byte(s)
		j, a, b := len(s)-1, 0, 0
		for i := len(s) - 1; i >= 0; i-- {
			if cs[i] > cs[j] {
				a, b = i, j
			} else if cs[i] < cs[j] {
				j = i
			}
		}
		cs[a], cs[b] = cs[b], cs[a]
		if s = string(cs); s < c {
			fmt.Fprintln(out, s)
		} else {
			fmt.Fprintln(out, "---")
		}
	}
}

func id2(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	fmt.Fscan(in, &n)
	nums := make([][3]int, n) 

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &nums[i][0])
		nums[i][1] = i
	}
	sort.SliceStable(nums, func(i, j int) bool {
		return nums[i][0] < nums[j][0]
	})
	for i := range nums {
		nums[i][2] = i
	}
	sort.Slice(nums, func(i, j int) bool {
		return nums[i][1] < nums[j][1]
	})
	f := make([]int, n+1)
	for _, num := range nums {
		f[num[2]+1] = f[num[2]] + 1
	}

	fmt.Fprintln(out, n-max(f...))
}

func id9(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m, k int
	fmt.Fscan(in, &n, &m, &k)
	if n > m {
		fmt.Fprintln(out, "YES")
		return
	}
	a, b := make([]int, n), make([]int, m)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	for i := range b {
		fmt.Fscan(in, &b[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	sort.Sort(sort.Reverse(sort.IntSlice(b)))
	for i := range a {
		if a[i] > b[i] {
			fmt.Fprintln(out, "YES")
			return
		}
	}

	fmt.Fprintln(out, "NO")
}

func helan(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	fmt.Fscan(in, &n)
	nums := make([]int, n)
	for i := range nums {
		fmt.Fscan(in, &nums[i])
	}

	less, more := -1, n
	for i := 0; i < more; i++ {
		if nums[i] == 0 {
			less++
			nums[i], nums[less] = nums[less], nums[i]
		} else if nums[i] == 2 {
			more--
			nums[i], nums[more] = nums[more], nums[i]
			i--
		}
	}

	fmt.Fprintln(out, nums)
}

func id8(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s, t string
	fmt.Fscan(in, &s, &t)
	ans := 0
	left, right := make([]int, len(t)), make([]int, len(t))
	i, j := 0, 0
	for ; i < len(s) && j < len(t); i++ {
		if s[i] == t[j] {
			left[j] = i
			j++
		}
	}
	ans = max(ans, len(s)-i)
	i, j = len(s)-1, len(t)-1
	for ; i >= 0 && j >= 0; i-- {
		if s[i] == t[j] {
			right[j] = i
			j--
		}
	}
	ans = max(ans, i+1)
	for k := 0; k < len(t)-1; k++ {
		ans = max(ans, right[k+1]-left[k]-1)
	}

	fmt.Fprintln(out, ans)

}

func id14(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var t, n, k int
	var s string
	fmt.Fscan(in, &t)
	pat := "RGB"
	for ; t > 0; t-- {
		fmt.Fscan(in, &n, &k, &s)
		ans := k
		for i := 0; i < 3; i++ {
			diff := 0
			for j := range s[:k] {
				if s[j] != pat[(i+j)%3] {
					diff++
				}
			}
			ans = min(ans, diff)
			for j := k; j < n; j++ {
				if s[j] != pat[(i+j)%3] {
					diff++
				}
				if s[j-k] != pat[(i+j-k%3)%3] {
					diff--
				}
				ans = min(ans, diff)
			}
		}

		fmt.Fprintln(out, ans)
	}
}

func id15(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var s string
	fmt.Fscan(in, &s)
	f := make([][10]int64, len(s))
	for i := range f[0] {
		f[0][i] = 1
	}
	for i := 1; i < len(s); i++ {
		for j := range f[i] {
			f[i][(j+int(s[i])-'0')/2] += f[i-1][j]
			if (j+int(s[i])-'0')&1 == 1 {
				f[i][(j+int(s[i])-'0'+1)/2] += f[i-1][j]
			}
		}
	}
	flag := true
	for i := range s[:len(s)-1] {
		if s[i]-s[i+1] <= 1 || s[i+1]-s[i] <= 1 {
			continue
		} else {
			flag = false
			break
		}
	}
	ans := int64(0)
	for i := range f[0] {
		ans += f[len(s)-1][i]
	}
	if flag {
		ans--
	}
	fmt.Fprintln(out, ans)
}

func id7(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	if k == 1 {
		fmt.Fprintln(out, 2)
		return
	}
	mod := int64(998244353)
	f := make([][2]int64, k+1)
	f[1][1], f[2][0] = 2, 2
	for i := 2; i <= n; i++ {
		for j := min(k, 2*i); j >= 2; j-- {
			f[j][1] = (f[j][0]*2 + f[j][1] + f[j-1][1]) % mod
			f[j][0] = (f[j][0] + f[j-2][0] + f[j-1][1]*2) % mod
		}
	}

	fmt.Fprintln(out, (f[k][0]+f[k][1])%mod)
}

func id4(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	if k == 1 {
		fmt.Fprintln(out, 2)
		return
	}
	mod := int64(998244353)
	f := make([][][2]int64, n+1)
	for i := range f {
		f[i] = make([][2]int64, k+1)
	}
	f[1][1][1], f[1][2][0] = 2, 2
	for i := 2; i <= n; i++ {
		f[i][1][1] = 2
		for j := 2; j <= k && j <= 2*i; j++ {
			f[i][j][0] = (f[i-1][j][0] + f[i-1][j-2][0] + f[i-1][j-1][1]*2) % mod
			f[i][j][1] = (f[i-1][j][0]*2 + f[i-1][j][1] + f[i-1][j-1][1]) % mod
		}
	}

	fmt.Fprintln(out, (f[n][k][0]+f[n][k][1])%mod)
}

func id0(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	if n < 4 {
		fmt.Fprintln(out, "NO")
		return
	}
	fmt.Fprintln(out, "YES")
	if (n-4)&1 == 0 {
		fmt.Fprintln(out, "1 * 2 = 2")
		fmt.Fprintln(out, "2 * 3 = 6")
		fmt.Fprintln(out, "6 * 4 = 24")
	} else {
		fmt.Fprintln(out, "2 * 4 = 8")
		fmt.Fprintln(out, "3 * 5 = 15")
		fmt.Fprintln(out, "8 + 15 = 23")
		fmt.Fprintln(out, "23 + 1 = 24")
	}
	for i := 5 + n&1; i < n; i += 2 {
		fmt.Fprintln(out, i+1, "-", i, "= 1")
		fmt.Fprintln(out, "1 * 24 = 24")
	}
}

func id13(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, ans int
	fmt.Fscan(in, &n)
	arr := make([]int, n+2)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &arr[i])
		arr[i] = min(arr[i], arr[i-1]+1)
	}
	for i := n; i >= 1; i-- {
		arr[i] = min(arr[i], arr[i+1]+1)
		ans = max(ans, arr[i])
	}

	fmt.Fprintln(out, ans)
}

func min(nums ...int) int {
	ans := nums[0]
	for _, num := range nums {
		if ans > num {
			ans = num
		}
	}
	return ans
}

func min64(nums ...int64) int64 {
	ans := nums[0]
	for _, num := range nums {
		if ans > num {
			ans = num
		}
	}
	return ans
}

func max(nums ...int) int {
	ans := nums[0]
	for _, num := range nums {
		if ans < num {
			ans = num
		}
	}
	return ans
}

func max64(nums ...int64) int64 {
	ans := nums[0]
	for _, num := range nums {
		if ans < num {
			ans = num
		}
	}
	return ans
}

func abs(a int) int {
	if a < 0 {
		a = -a
	}
	return a
}
