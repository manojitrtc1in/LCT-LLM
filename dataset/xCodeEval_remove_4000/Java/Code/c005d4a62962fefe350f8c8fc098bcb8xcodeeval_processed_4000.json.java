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
            int n = readInt(), k = readInt();
            Map<Integer, Integer> cnt = new TreeMap<>();
            Set<Integer> vals = new TreeSet<>();
            for (int j = 0; j < n; j++) {
                int v = readInt(); vals.add(v);
                cnt.put(v, cnt.getOrDefault(v, 0)+1);
            }
            int ans = -1, l = -1, r = -1;
            List<Integer> list = new ArrayList<>(vals);
            for (int j = 0; j < list.size(); j++) {
                if (cnt.get(list.get(j))<k) continue;
                if (ans<0) {
                    ans = 0;
                    l = r = list.get(j);
                }
                int pre = list.get(j), first = list.get(j);
                boolean term = false;
                for (int m = j+1; m < list.size(); m++) {
                    if (list.get(m)!=pre+1) {
                        j = m-1;
                        term = true;
                        break;
                    }
                    else {
                        if (cnt.get(list.get(m))<k) {
                            j = m;
                            term = true;
                            break;
                        }
                        if (ans<list.get(m) - first) {
                            ans = list.get(m) - first;
                            l = first; r = list.get(m);
                        }
                        pre = list.get(m);
                    }
                }
                if (!term) break;
            }
            if (ans==-1) System.out.println(-1);
            else {
                System.out.print(l);
                System.out.print(" ");
                System.out.print(r);
                System.out.println();
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
    static int id0() throws IOException{
        int x = 0, c;
        while((c = br.read()) != ' ' && c != '\n')
            x = x * 10 + (c - '0');
        return x;
    }
}
