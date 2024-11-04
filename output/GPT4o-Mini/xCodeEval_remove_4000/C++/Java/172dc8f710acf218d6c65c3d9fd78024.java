import java.util.*;
import java.io.*;

class Main {
    static String s;
    static Pair[] tr = new Pair[1010101];

    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static Pair merge(Pair a, Pair b) {
        if (b.first == 0) {
            a.second += b.second;
            return a;
        } else {
            b.first += a.first;
            return b;
        }
    }

    static void build(int cur, int l, int r) {
        if (l == r) {
            if (s.charAt(l) == 'A') {
                tr[cur] = new Pair(0, 1);
            } else {
                tr[cur] = new Pair(1, 0);
            }
        } else {
            int m = (l + r) / 2;
            int dcur = cur + cur;
            build(dcur, l, m);
            build(dcur + 1, m + 1, r);
            tr[cur] = merge(tr[dcur], tr[dcur + 1]);
        }
    }

    static Pair get(int cur, int l, int r, int x, int y) {
        if (x > r || y < l) return new Pair(0, 0);
        if (x <= l && r <= y) return tr[cur];
        int m = (l + r) / 2;
        int dcur = cur + cur;
        return merge(get(dcur, l, m, x, y), get(dcur + 1, m + 1, r, x, y));
    }

    static String solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        s = st.nextToken();
        String t = st.nextToken();
        int n = s.length();
        s += t;
        int sn = s.length();
        build(1, 0, sn - 1);
        int q = Integer.parseInt(br.readLine());
        StringBuilder ans = new StringBuilder();
        
        while (q-- > 0) {
            int[] l = new int[2];
            int[] r = new int[2];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 2; i++) {
                l[i] = Integer.parseInt(st.nextToken());
                r[i] = Integer.parseInt(st.nextToken());
            }
            l[1] += n;
            r[1] += n;
            for (int i = 0; i < 2; i++) {
                l[i]--;
                r[i]--;
            }
            Pair a = get(1, 0, sn - 1, l[0], r[0]);
            Pair b = get(1, 0, sn - 1, l[1], r[1]);
            if (a.first > b.first || a.first % 2 != b.first % 2 || a.second < b.second) {
                ans.append('0');
                continue;
            }
            ans.append(((a.first == b.first && a.second % 3 == b.second % 3) ||
                    (a.first != b.first && a.first > 0) ||
                    (a.second > b.second && a.first != b.first)) ? '1' : '0');
        }
        return ans.toString();
    }

    public static void main(String[] args) throws IOException {
        System.out.println(solve());
    }
}
