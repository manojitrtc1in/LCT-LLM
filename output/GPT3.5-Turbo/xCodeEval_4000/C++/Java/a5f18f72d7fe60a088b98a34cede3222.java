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
        ArrayList<Integer> d = divisorTable(5001);
        ArrayList<ArrayList<Integer>> divisors = new ArrayList<>();
        divisors.add(new ArrayList<>());
        divisors.add(new ArrayList<>());
        for (int i = 2; i < 5001; i++) {
            divisors.add(new ArrayList<>(divisors.get(i - 1)));
            if (d.get(i) == i) {
                divisors.get(i).add(1);
            } else {
                int q = i;
                while (q > 1) {
                    divisors.get(i).add(p.indexOf(d.get(q)));
                    q /= d.get(q);
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
                if (still[i] && !divisors.get(i).isEmpty()) {
                    cur[divisors.get(i).size() - 1] += q[i];
                }
            }
            int pos = 0;
            for (int i = 0; i < cur.length; i++) {
                if (cur[i] > cur[pos]) {
                    pos = i;
                }
            }
            if (cur[pos] <= n / 2) {
                pos = -2;
            }
            int step = Integer.MAX_VALUE;
            for (int i = 0; i < 5001; i++) {
                if (still[i] && divisors.get(i).size() - 1 != pos) {
                    answer += q[i] * divisors.get(i).stream().mapToLong(Integer::longValue).sum();
                    lost += q[i];
                    still[i] = false;
                } else if (still[i]) {
                    step = Math.min(step, divisors.get(i).get(divisors.get(i).size() - 1));
                }
            }
            if (pos == -2) {
                break;
            }
            answer += (long) step * lost;
            for (int i = 0; i < 5001; i++) {
                if (still[i]) {
                    divisors.get(i).set(divisors.get(i).size() - 1, divisors.get(i).get(divisors.get(i).size() - 1) - step);
                    if (divisors.get(i).get(divisors.get(i).size() - 1) == 0) {
                        divisors.get(i).remove(divisors.get(i).size() - 1);
                    }
                }
            }
        }
        out.println(answer);
        out.close();
    }

    static ArrayList<Integer> primes(int n) {
        ArrayList<Integer> res = new ArrayList<>();
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        if (n > 0) {
            isPrime[0] = false;
        }
        if (n > 1) {
            isPrime[1] = false;
        }
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                res.add(i);
            }
        }
        return res;
    }

    static ArrayList<Integer> divisorTable(int n) {
        ArrayList<Integer> res = new ArrayList<>();
        int[] d = new int[n];
        if (n > 1) {
            d[1] = 1;
        }
        for (int i = 2; i < n; i++) {
            if (d[i] == 0) {
                d[i] = i;
                if ((long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        d[j] = i;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            res.add(d[i]);
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
