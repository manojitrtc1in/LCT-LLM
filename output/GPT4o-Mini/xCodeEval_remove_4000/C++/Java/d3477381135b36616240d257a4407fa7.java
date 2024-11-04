import java.util.*;
import java.io.*;

public class d3477381135b36616240d257a4407fa7xcodeeval_processed_4000.json {
    static final int N = (int) 1e2 + 9;
    static char[] a = new char[N], c = new char[N];
    static int[] t = new int[N];
    static int b, d;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        b = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        String inputA = br.readLine();
        String inputC = br.readLine();

        a = inputA.toCharArray();
        c = inputC.toCharArray();
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
        for (int i = 0; i < b; i++) {
            s += t[s % cn];
        }
        s /= cn * d;

        out.println(s);
        out.flush();
    }
}
