import java.io.*;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;


public class CodeForcesSolution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static int mod = (int) 1e9+7, n;
    public static void main(String[] args) throws IOException {
        int T = readInt();
        for (int i = 0; i < T; i++) {
            n = readInt();
            int[] A = new int[n+1], B = new int[n+1];
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int j = 1; j <= n; j++) {
                A[j] = readInt();
                cnt.put(A[j], cnt.getOrDefault(A[j], 0)+1);
            }
            for (int j = 1; j <= n; j++) {
                B[j] = readInt();
                cnt.put(A[j], cnt.getOrDefault(A[j], 0)+1);
            }
            List<int[]> pair = new ArrayList<>();
            for (int j = 1; j <= n; j++) {
                pair.add(new int[] {A[j], B[j]});
            }
            Collections.sort(pair, (a, b) -> {
                if (a[0]==b[0]) return a[1]-b[1];
                else return a[0]-b[0];
            });
            List<int[]> all = new ArrayList<>();
            for (int j = 1; j <= n; j++) {
                if (!(A[j]==pair.get(j-1)[0] && B[j]==pair.get(j-1)[1])) {
                    for (int k = j+1; k <= n; k++) {
                        if (A[k]==pair.get(j-1)[0] && B[k]==pair.get(j-1)[1]) {
                            int s = A[j];
                            A[j] = A[k];
                            A[k] = s;
                            s = B[j];
                            B[j] = B[k];
                            B[k] = s;
                            all.add(new int[] {j, k});
                        }
                    }
                }
            }
            boolean valid = true;
            for (int j = 2; j <= n; j++) {
                if (!(pair.get(j-1)[0]>=pair.get(j-2)[0] && pair.get(j-1)[1]>=pair.get(j-2)[1])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) System.out.println(-1);
            else {
                System.out.println(all.size());
                for (int[] v : all) {
                    System.out.println(v[0]+ " "+v[1]);
                }
            }
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
