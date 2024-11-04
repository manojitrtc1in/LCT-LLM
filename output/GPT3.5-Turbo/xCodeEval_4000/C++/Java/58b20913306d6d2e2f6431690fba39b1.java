import java.util.*;

class Main {
    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int tot = 0;
        List<List<Integer>> data = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int k = sc.nextInt();
            int a = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            int m = sc.nextInt();
            tot += k;
            List<Integer> tmp = new ArrayList<>();
            tmp.add(a);
            for (int j = 2; j <= k; j++) {
                tmp.add((tmp.get(tmp.size() - 1) * x + y) % m);
            }
            data.add(tmp);
        }
        TreeSet<Pair> q = new TreeSet<>((a, b) -> {
            if (a.first != b.first) {
                return a.first - b.first;
            } else if (a.second != b.second) {
                return a.second - b.second;
            } else {
                return 0;
            }
        });
        for (int i = 0; i < n; i++) {
            q.add(new Pair(data.get(i).get(0), new Pair(i, 0)));
        }
        List<Integer> ans = new ArrayList<>();
        List<Pair> sol = new ArrayList<>();
        int p = 0;
        while (ans.size() < tot) {
            Pair it = q.ceiling(new Pair(p, -1));
            if (it == null) {
                it = q.first();
            }
            int v = it.first;
            p = v;
            Pair o = it.second;
            ans.add(v);
            sol.add(new Pair(v, o.first + 1));
            q.remove(it);
            if (o.second + 1 < data.get(o.first).size()) {
                q.add(new Pair(data.get(o.first).get(o.second + 1), new Pair(o.first, o.second + 1)));
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
