import java.io.*;
import java.util.*;

public class CodeForcesSolution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static int mod = (int) 1e9+7, n, m;
    static int[] dr = new int[] {-1, 1, 0, 0}, dc = new int[] {0, 0, -1, 1};
    public static void main(String[] args) throws IOException {
        int T = readInt();
        for (int i = 0; i < T; i++) {
            String s = readLine();
            int n = s.length();
            int[] psa = new int[n+1];
            for (int j = 0; j < n; j++) {
                psa[j+1] = psa[j] + s.charAt(j) - '0';
            }
            int ans = psa[n]; 

            int totalOnes = psa[n], totalZeros = n-totalOnes;
            for (int j = 0; j < n; j++) {
                

                int beg_ones = psa[j], beg_zeros = j - beg_ones;
                int lo = 0, hi = n-j;
                while (lo<=hi) {
                    int mid = (lo+hi)/2;
                    int end_ones = psa[n] - psa[n-mid], end_zeros = mid - end_ones;
                    int cur = Math.max(beg_ones + end_ones, (totalZeros - beg_zeros - end_zeros));
                    ans = Math.min(ans, cur);
                    if (beg_ones + end_ones==(totalZeros - beg_zeros - end_zeros)) break;
                    else if (beg_ones + end_ones<(totalZeros - beg_zeros - end_zeros)) lo = mid+1;
                    else hi = mid-1;
                }
            }
            System.out.println(ans);
        }
    }


    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong() throws IOException {
        return Long.parseLong(next());
    }
    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter() throws IOException {
        return next().charAt(0);
    }
    static String readLine() throws IOException {
        return br.readLine().trim();
    }
    static int readALotInt() throws IOException{
        int x = 0, c;
        while((c = br.read()) != ' ' && c != '\n')
            x = x * 10 + (c - '0');
        return x;
    }
}
