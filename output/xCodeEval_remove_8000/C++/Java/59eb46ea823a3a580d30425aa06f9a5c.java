import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        List<Pair<Pair<Long, Long>, Integer>> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            long x = Long.parseLong(line[0]);
            long y = Long.parseLong(line[1]);
            p.add(new Pair<>(new Pair<>(x, y), i));
        }
        String s = br.readLine();
        List<Pair<Pair<Long, Long>, Integer>> perm = new ArrayList<>();
        int firstIdx = 0;
        for (int i = 0; i < n; i++) {
            if (p.get(i).compareTo(p.get(firstIdx)) < 0) {
                firstIdx = i;
            }
        }
        take(firstIdx, perm, p);
        for (int i = 0; i < n - 2; i++) {
            Pair<Long, Long> q = perm.get(perm.size() - 1).getKey();
            int best = 0;
            for (int j = 1; j < p.size(); j++) {
                if ((((p.get(best).getKey().getKey() - q.getKey()) * (p.get(j).getKey().getValue() - q.getValue())) -
                        ((p.get(best).getKey().getValue() - q.getValue()) * (p.get(j).getKey().getKey() - q.getKey()))) > 0 ==
                        (s.charAt(i) == 'R')) {
                    best = j;
                }
            }
            take(p.get(best).getValue(), perm, p);
        }
        take(p.get(0).getValue(), perm, p);
        for (int i = 0; i < perm.size(); i++) {
            pw.print(perm.get(i).getValue() + 1);
            if (i != perm.size() - 1) {
                pw.print(" ");
            }
        }
        pw.println();

        pw.close();
        br.close();
    }

    public static void take(int k, List<Pair<Pair<Long, Long>, Integer>> perm, List<Pair<Pair<Long, Long>, Integer>> points) {
        int n = points.size();
        for (int i = 0; i < n; i++) {
            if (points.get(i).getValue() == k) {
                Collections.swap(points, i, n - 1);
                break;
            }
        }
        perm.add(points.get(n - 1));
        points.remove(n - 1);
    }
}

class Pair<T, U> implements Comparable<Pair<T, U>> {
    private T key;
    private U value;

    public Pair(T key, U value) {
        this.key = key;
        this.value = value;
    }

    public T getKey() {
        return key;
    }

    public U getValue() {
        return value;
    }

    public void setKey(T key) {
        this.key = key;
    }

    public void setValue(U value) {
        this.value = value;
    }

    @Override
    public int compareTo(Pair<T, U> other) {
        if (this.key.equals(other.key)) {
            return ((Comparable) this.value).compareTo(other.value);
        }
        return ((Comparable) this.key).compareTo(other.key);
    }
}
