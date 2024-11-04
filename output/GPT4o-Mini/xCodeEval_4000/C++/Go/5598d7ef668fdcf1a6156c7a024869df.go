package main

import (
    "fmt"
    "math"
)

const M = 1000000007

func reset(dp [][]int) {
    for i := range dp {
        for j := range dp[i] {
            dp[i][j] = 0
        }
    }
}

func main() {
    var s, t string
    fmt.Scan(&s, &t)

    dp := make([][]int, len(s)+1)
    for i := range dp {
        dp[i] = make([]int, len(t)+1)
    }
    reset(dp)

    for i := 0; i < len(s); i++ {
        for j := 0; j < len(t); j++ {
            if s[i] == t[j] {
                dp[i+1][j+1] = (dp[i+1][j] + (dp[i][j] + 1)) % M
            } else {
                dp[i+1][j+1] = dp[i+1][j]
            }
        }
    }

    re := 0
    sz := len(t)
    for i := 0; i < len(s); i++ {
        re = (re + dp[i+1][sz]) % M
    }
    fmt.Println(re)
}
