import java.util.*;
import java.io.*;

class Main {
    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple {
        int first;
        Pair second;

        Triple(int first, Pair second) {
            this.first = first;
            this.second = second;
        }
    }

    static int xor(int i) {
        if ((i & 3) == 0) return i;
        if ((i & 3) == 1) return 1;
        if ((i & 3) == 2) return i + 1;
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        long tot = 0;
        List<List<Integer>> data = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            tot += k;
            List<Integer> tmp = new ArrayList<>();
            tmp.add(a);
            for (int j = 2; j <= k; j++) {
                tmp.add((tmp.get(tmp.size() - 1) * x + y) % m);
            }
            data.add(tmp);
        }

        TreeSet<Triple> q = new TreeSet<>((a, b) -> {
            if (a.first != b.first) return Integer.compare(a.first, b.first);
            if (a.second.first != b.second.first) return Integer.compare(a.second.first, b.second.first);
            return Integer.compare(a.second.second, b.second.second);
        });

        for (int i = 0; i < n; i++) {
            q.add(new Triple(data.get(i).get(0), new Pair(i, 0)));
        }

        List<Integer> ans = new ArrayList<>();
        List<Pair> sol = new ArrayList<>();
        int p = 0;

        while (ans.size() < tot) {
            Triple it = q.ceiling(new Triple(p, new Pair(-1, -1)));
            if (it == null) it = q.first();
            int v = it.first;
            p = v;
            Pair o = it.second;
            ans.add(v);
            sol.add(new Pair(v, o.first + 1));
            q.remove(it);
            if (o.second + 1 < data.get(o.first).size()) {
                q.add(new Triple(data.get(o.first).get(o.second + 1), new Pair(o.first, o.second + 1)));
            }
        }

        int bad = 0;
        for (int i = 1; i < ans.size(); i++) {
            if (ans.get(i - 1) > ans.get(i)) {
                bad++;
            }
        }

        System.out.println(bad);
        if (tot <= 200000) {
            for (int i = 0; i < sol.size(); i++) {
                System.out.println(sol.get(i).first + " " + sol.get(i).second);
            }
        }
    }
}
