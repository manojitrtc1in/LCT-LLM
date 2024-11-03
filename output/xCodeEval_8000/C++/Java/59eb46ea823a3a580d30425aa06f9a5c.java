import java.util.*;
import java.io.*;

class Main {
    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Pair<Pair<Long, Long>, Integer>> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            long x = Long.parseLong(input[0]);
            long y = Long.parseLong(input[1]);
            p.add(new Pair<>(new Pair<>(x, y), i));
        }
        String s = br.readLine();
        List<Pair<Pair<Long, Long>, Integer>> perm = new ArrayList<>();
        int firstIdx = 0;
        for (int i = 0; i < n; i++) {
            if (p.get(i).first.compareTo(p.get(firstIdx).first) < 0) {
                firstIdx = i;
            }
        }
        take(firstIdx, perm, p);
        for (int i = 0; i < n - 2; i++) {
            Pair<Long, Long> q = perm.get(perm.size() - 1).first;
            int best = 0;
            for (int j = 1; j < p.size(); j++) {
                if ((((p.get(best).first.first - q.first) * (p.get(j).first.second - q.second)) -
                        ((p.get(best).first.second - q.second) * (p.get(j).first.first - q.first))) > 0 ==
                        (s.charAt(i) == 'R')) {
                    best = j;
                }
            }
            take(p.get(best).second, perm, p);
        }
        take(p.get(0).second, perm, p);
        for (int i = 0; i < perm.size(); i++) {
            System.out.print((perm.get(i).second + 1) + " ");
        }
        System.out.println();
    }

    static void take(int k, List<Pair<Pair<Long, Long>, Integer>> perm, List<Pair<Pair<Long, Long>, Integer>> points) {
        int n = points.size();
        for (int i = 0; i < n; i++) {
            if (points.get(i).second == k) {
                Collections.swap(points, i, n - 1);
                break;
            }
        }
        perm.add(points.get(n - 1));
        points.remove(n - 1);
    }
}
