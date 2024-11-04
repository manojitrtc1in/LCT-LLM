import java.util.*;
import java.io.*;

class DKhaotichnayaV {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] k = new int[n];
        for (int i = 0; i < n; i++) {
            k[i] = in.nextInt();
        }

        ArrayList<Integer> p = primes(5000);
        int[] d = id7(5001);
        ArrayList<ArrayList<Integer>> id0 = new ArrayList<>();
        id0.add(new ArrayList<>());
        id0.add(new ArrayList<>());
        for (int i = 2; i < 5001; i++) {
            id0.add(new ArrayList<>(id0.get(i - 1)));
            if (d[i] == i) {
                id0.get(i).add(1);
            } else {
                for (int q = i; q > 1; q /= d[q]) {
                    id0.get(i).add(Collections.binarySearch(p, d[q]));
                }
            }
        }
        long answer = 0;
        int[] q = getQty(k, 5001);
        int lost = 0;
        boolean[] still = new boolean[5001];
        Arrays.fill(still, true);
        int[] cur = new int[p.size()];
        while (true) {
            Arrays.fill(cur, 0);
            for (int i = 0; i < 5001; i++) {
                if (still[i] && !id0.get(i).isEmpty()) {
                    cur[id0.get(i).size() - 1] += q[i];
                }
            }
            int pos = -1;
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < cur.length; i++) {
                if (cur[i] > max) {
                    max = cur[i];
                    pos = i;
                }
            }
            if (cur[pos] <= n / 2) {
                pos = -2;
            }
            int step = Integer.MAX_VALUE;
            for (int i = 0; i < 5001; i++) {
                if (still[i] && id0.get(i).size() - 1 != pos) {
                    answer += (long) q[i] * id0.get(i).stream().mapToLong(Integer::intValue).sum();
                    lost += q[i];
                    still[i] = false;
                } else if (still[i]) {
                    step = Math.min(step, id0.get(i).get(id0.get(i).size() - 1));
                }
            }
            if (pos == -2) {
                break;
            }
            answer += (long) step * lost;
            for (int i = 0; i < 5001; i++) {
                if (still[i]) {
                    id0.get(i).set(id0.get(i).size() - 1, id0.get(i).get(id0.get(i).size() - 1) - step);
                    if (id0.get(i).get(id0.get(i).size() - 1) == 0) {
                        id0.get(i).remove(id0.get(i).size() - 1);
                    }
                }
            }
        }
        out.println(answer);
        out.close();
    }

    static ArrayList<Integer> primes(int n) {
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res.add(i);
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return res;
    }

    static int[] id7(int n) {
        int[] res = new int[n];
        if (n > 1) {
            res[1] = 1;
        }
        for (int i = 2; i < n; i++) {
            if (res[i] == 0) {
                res[i] = i;
                if ((long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        res[j] = i;
                    }
                }
            }
        }
        return res;
    }

    static int[] getQty(int[] arr, int length) {
        int[] res = new int[length];
        for (int i : arr) {
            res[i]++;
        }
        return res;
    }
}
