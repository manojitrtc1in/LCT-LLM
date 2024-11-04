import java.io.*;
import java.util.*;

class TaskD {
    static class Pair {
        int first;
        long second;

        Pair(int first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static Pair[][] answer = new Pair[3000][3002];

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(in.readLine());
        int m = Integer.parseInt(in.readLine());
        int[] b = new int[n];
        int[] w = new int[n];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
        }
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            graph[x].add(y);
            graph[y].add(x);
        }
        int[] q = new int[n];
        calcQ(graph, q, 0, -1);

        Pair[] temp = new Pair[n + 2];
        go(graph, answer, temp, q, b, w, 0, -1);

        out.println(answer[0][m].first);
        out.flush();
    }

    static int calcQ(List<Integer>[] graph, int[] q, int vert, int last) {
        int res = 1;
        for (int next : graph[vert]) {
            if (next == last) {
                continue;
            }
            res += calcQ(graph, q, next, vert);
        }
        q[vert] = res;
        return res;
    }

    static void go(List<Integer>[] graph, Pair[][] answer, Pair[] temp, int[] q, int[] b, int[] w, int vert, int last) {
        int id = -1;
        for (int next : graph[vert]) {
            if (next == last) {
                continue;
            }
            go(graph, answer, temp, q, b, w, next, vert);
            if (id == -1 || q[next] > q[id]) {
                id = next;
            }
        }
        Pair[] cur = answer[vert];
        long delta = w[vert] - b[vert];
        if (id == -1) {
            cur[0] = new Pair(0, delta);
            cur[1] = new Pair(delta > 0 ? 1 : 0, 0);
            return;
        }
        Pair[] aid = answer[id];
        for (int i = 0; i <= q[id]; i++) {
            cur[i] = new Pair(aid[i].first, aid[i].second + delta);
        }
        int sz = q[id];
        for (int i = sz + 1; i <= q[vert]; i++) {
            cur[i] = new Pair(-1, 0);
        }
        for (int next : graph[vert]) {
            if (next == last || next == id) {
                continue;
            }
            Pair[] anext = answer[next];
            for (int i = 0; i <= sz; i++) {
                temp[i] = cur[i];
                cur[i] = new Pair(-1, 0);
            }
            int nsz = sz + q[next];
            for (int i = 0; i <= sz; i++) {
                for (int j = 0; j <= q[next]; j++) {
                    if (temp[i].first + anext[j].first > cur[i + j].first) {
                        cur[i + j] = new Pair(temp[i].first + anext[j].first, temp[i].second + anext[j].second);
                    }
                }
            }
            sz = nsz;
        }
        if (vert == 0) {
            for (int i = n - 1; i >= 0; i--) {
                cur[i + 1] = new Pair(cur[i].first + (cur[i].second > 0 ? 1 : 0), 0);
            }
            return;
        }
        for (int i = sz; i >= 0; i--) {
            cur[i + 1] = new Pair(cur[i].first + (cur[i].second > 0 ? 1 : 0), 0);
        }
    }
}
