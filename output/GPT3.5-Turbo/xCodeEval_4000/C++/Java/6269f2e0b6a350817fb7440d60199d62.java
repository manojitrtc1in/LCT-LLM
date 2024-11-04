import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static final long MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        while (q-- > 0) {
            long n = sc.nextLong();
            long M = n / 4 + 1;
            long m = M % MOD;
            long ans = (m * m) % MOD;
