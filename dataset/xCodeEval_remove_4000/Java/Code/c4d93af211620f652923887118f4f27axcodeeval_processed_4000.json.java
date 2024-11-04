import java.io.*;
import java.util.*;

public class id1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static int mod = (int) 1e9+7;
    public static void main(String[] args) throws IOException {
        int T = readInt();
        for (int i = 0; i < T; i++) {
            int n = readInt();
            int fir = 1;
            int[] A = new int[n];
            boolean worked = true;
            for (int j = 0; j < n; j++) {
                A[j] = fir;
                fir*=3;
                if (fir<0) {
                    worked = false; break;
                }
            }
            if (worked) {
                System.out.println("YES");
                for (int j = 0; j < n; j++) {
                    System.out.print(A[j] + " ");
                }
                System.out.println();
            }
            else System.out.println("NO");
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
    static int id0() throws IOException{
        int x = 0, c;
        while((c = br.read()) != ' ' && c != '\n')
            x = x * 10 + (c - '0');
        return x;
    }
}
