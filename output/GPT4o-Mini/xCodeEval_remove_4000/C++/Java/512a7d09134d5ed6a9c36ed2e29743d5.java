import java.util.*;
import java.io.*;

public class 512a7d09134d5ed6a9c36ed2e29743d5xcodeeval_processed_4000.json {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        String s = br.readLine();
        String t = br.readLine();
        int n = s.length(), m = t.length();

        int[] front = new int[m];
        int[] back = new int[m];
        int pos = 0;

        for (int i = 0; i < m; i++) {
            front[i] = s.indexOf(t.charAt(i), pos);
            pos = front[i] + 1;
        }

        pos = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            back[i] = s.lastIndexOf(t.charAt(i), pos);
            pos = back[i] - 1;
        }

        int ans = Math.max(back[0], n - 1 - front[m - 1]);
        for (int i = 0; i < m - 1; i++) {
            ans = Math.max(ans, back[i + 1] - front[i] - 1);
        }

        out.println(ans);
        out.flush();
    }
}
