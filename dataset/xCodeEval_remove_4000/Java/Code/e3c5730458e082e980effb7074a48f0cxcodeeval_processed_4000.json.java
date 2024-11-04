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
            int n = readInt(), m = readInt();
            int[][] A = new int[n][m];
            boolean ok = true;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    A[j][k] = readInt();
                }
            }
            Set<String> res = new HashSet<>();
            for (int j = 0; j < n && res.size()<=1; j++) {
                int f = -1, s = -1;
                int[] c = copy(A[j]);
                Arrays.sort(c);
                int dif = 0;
                for (int k = 0; k < c.length; k++) {
                    if (c[k] != A[j][k]) {
                        dif++;
                        if (f == -1) f = k;
                        else s = k;
                    }
                }
                if (dif > 2) {
                    ok = false;
                    break;
                }
                else if (dif==0) {
                    continue;
                }
                else {
                    res.add((f+1)+" "+(s+1));
                }
            }
            if (ok) {
                if (res.size()>1) {
                    System.out.println(-1);
                }
                else if (res.size()==0) {
                    System.out.println("1 1");
                }
                else {
                    boolean check = true;
                    String[] p = new ArrayList<>(res).get(0).split(" ");
                    int f = Integer.parseInt(p[0])-1;
                    int s = Integer.parseInt(p[1])-1;
                    for (int j = 0; j < n; j++) {
                        int[] c = copy(A[j]);
                        Arrays.sort(c);
                        int tmp = A[j][f];
                        A[j][f] = A[j][s];
                        A[j][s] = tmp;
                        if (!Arrays.equals(c, A[j])) {
                            check = false;
                            break;
                        }
                    }
                    if (check) {
                        System.out.println((f+1)+" "+(s+1));
                    }
                    else System.out.println(-1);
                }
            }
            else {
                System.out.println(-1);
            }
        }
    }
    public static int[] copy(int[] A) {
        int[] c = new int[A.length];
        System.arraycopy(A, 0, c, 0, A.length);
        return c;
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
