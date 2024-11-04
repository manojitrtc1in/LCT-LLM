package main

import (
	"fmt"
	"math/big"
)

const mod = 998244353
const mxN = 2000005

var fac [mxN]*big.Int

func init() {
	fac[0] = big.NewInt(1)
	for i := 1; i < mxN; i++ {
		fac[i] = new(big.Int).Mul(fac[i-1], big.NewInt(int64(i)))
		fac[i].Mod(fac[i], big.NewInt(mod))
	}
}

func C(n, m int) *big.Int {
	return new(big.Int).Div(new(big.Int).Div(fac[n], fac[m]), fac[n-m])
}

func bpow(x *big.Int, n int) *big.Int {
	res := big.NewInt(1)
	for n > 0 {
		if n%2 == 1 {
			res.Mul(res, x)
			res.Mod(res, big.NewInt(mod))
		}
		x.Mul(x, x)
		x.Mod(x, big.NewInt(mod))
		n /= 2
	}
	return res
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	if k >= n {
		fmt.Println(0)
		return
	}

	ans := big.NewInt(0)
	for i := 0; i <= n-k; i++ {
		sign := 1
		if (n-k-i)%2 != 0 {
			sign = -1
		}
		temp := new(big.Int).Mul(C(n-k, i), bpow(big.NewInt(int64(i)), n))
		temp.Mul(temp, big.NewInt(int64(sign)))
		ans.Add(ans, temp)
		ans.Mod(ans, big.NewInt(mod))
	}

	if k > 0 {
		ans.Add(ans, big.NewInt(1))
		ans.Mod(ans, big.NewInt(mod))
	}
	ans.Mul(ans, C(n, n-k))
	ans.Mod(ans, big.NewInt(mod))

	fmt.Println(ans)
}
