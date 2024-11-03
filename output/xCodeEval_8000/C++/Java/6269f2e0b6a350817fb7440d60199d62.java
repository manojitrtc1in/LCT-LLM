import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            long n = Long.parseLong(br.readLine());
            long M = n / 4 + 1;
            long m = M % MOD;
            long ans = (m * m) % MOD;
