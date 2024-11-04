import java.util.*;
import java.io.*;

public class d3477381135b36616240d257a4407fa7_nc {
    static final int N = (int)1e2 + 9;
    static char[] a = new char[N];
    static char[] c = new char[N];
    static int[] t = new int[N];
    static int b, d;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        b = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        a = br.readLine().toCharArray();
        c = br.readLine().toCharArray();
        
        int an = a.length, cn = c.length;

        for (int i = 0; i < cn; i++) {
            int k = t[i];
            for (int j = 0; j < an; j++) {
                if (a[j] == c[(i + k) % cn]) {
                    k++;
                }
            }
            t[i] = k;
        }

        int s = 0;
