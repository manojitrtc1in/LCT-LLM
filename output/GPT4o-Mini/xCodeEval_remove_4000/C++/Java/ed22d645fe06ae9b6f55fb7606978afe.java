import java.util.*;
import java.io.*;

public class ed22d645fe06ae9b6f55fb7606978afexcodeeval_processed_4000.json {
    static final int N = (int) 1e2 + 9;
    static char[] a = new char[N], c = new char[N];
    static int[] t = new int[N];
    static PII[] tt = new PII[N];
    static int b, d;

    static class PII {
        int fi, se;

        PII() {
            this.fi = -1;
            this.se = -1;
        }
    }

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

        Arrays.fill(tt, new PII());
        int s = 0;
        boolean bj = false;

        for (int i = 0; i < b; i++) {
            s += t[s % cn];

            if (bj) continue;

            if (tt[s % cn].fi == -1) {
                tt[s % cn].fi = i;
                tt[s % cn].se = s;
            } else {
                int r = i - tt[s % cn].fi;
                s += (s - tt[s % cn].se) * ((b - i) / r);
                i += ((b - i) / r) * r;
                bj = true;
            }
        }
        s /= cn * d;
        System.out.println(s);
    }
}
