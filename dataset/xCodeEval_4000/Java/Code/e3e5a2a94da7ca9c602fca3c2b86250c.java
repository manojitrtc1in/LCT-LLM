

import java.io.*;
import java.util.*;
import java.util.StringTokenizer;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            out.println(in.nextInt());
            }
        out.flush();
        }
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
    }


