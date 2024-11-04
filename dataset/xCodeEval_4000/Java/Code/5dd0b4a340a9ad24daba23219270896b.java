import java.util.*;
import java.io.*;
import java.math.*;

public class A1 {
    public static StreamTokenizer in = new StreamTokenizer(System.in);
    public static boolean bg = false;

    public static void main(String[] args) throws Exception {
        int n1 = ni();
        int[] l1 = intl(n1);
        
        long[] cum = new long[n1];
        long[] cum2 = new long[n1];
        {
            long k1 = 0;
            long k2 = 0;
            for (int i=0;i<l1.length;i++){
                if (l1[i]>=0){
                    k1 += (long)l1[i];
                    k2++;
                }
                cum[i] = k1;
            }
        }
        TreeMap<Integer,Integer> left = new TreeMap();
        for (int i=0;i<n1;i++){
            if (!left.containsKey(l1[i]) ){
                left.put(l1[i], i);
            }
        }
        TreeMap<Integer,Integer> right = new TreeMap();
        for (int i=l1.length-1; i>=0; i--){
            if (!right.containsKey(l1[i]) ){
                right.put(l1[i], i);
            }
        }
        
        int qq1 = -1;
        int qq2 = -1;
        long max = Long.MIN_VALUE;
        for (int e: left.keySet()){
            int ww1 = left.get(e);
            int ww2 = right.get(e);
            
            
            
            if (ww2-ww1>=1){
                if (bg) pn(ww1+" "+ww2);
                long val = cum[ww2-1];
                if (bg) pn(val);
                val -= cum[ww1];
                if (bg) pn(val);
                val += 2l * (long)(e);
                if (bg) pn(val);
                if (val > max){
                    max = val;
                    qq1 = ww1;
                    qq2 = ww2;
                }
                if (bg) pn("");
            }
        }
        boolean[] k1 = new boolean[n1];
        int count = 0;
        ArrayList<Integer> fin1 = new ArrayList();
        for (int i=0;i<n1;i++){
            if (i<qq1){
                k1[i]=true;
                
            }
            else if (i>qq2){
                k1[i]=true;
            }
            else if (i<=qq2-1 && i>=qq1+1){
                if (l1[i]<0){
                    k1[i]=true;
                }
            }
            if (k1[i]==true){
                fin1.add(i);
                count++;
            }
        }
        pn(max+" "+fin1.size());
        StringBuilder fin3 = new StringBuilder();
        for (int e: fin1){
            fin3.append((e+1)+" ");
        }
        pn(fin3);
    }

    private static int ni() throws Exception {
        in.nextToken();
        return (int) in.nval;
    }

    private static long nl() throws Exception {
        in.nextToken();
        return (long) in.nval;
    }

    private static double nd() throws Exception {
        in.nextToken();
        return in.nval;
    }

    private static String ns() throws Exception {
        in.nextToken();
        return in.sval;
    }

    private static int[] intl(int n1) throws Exception {
        int[] fin = new int[n1];
        for (int i = 0; i < n1; i++) {
            fin[i] = ni();
        }
        return fin;
    }

    private static long[] longl(int n1) throws Exception {
        long[] fin = new long[n1];
        for (int i = 0; i < n1; i++) {
            fin[i] = nl();
        }
        return fin;
    }

    private static double[] doublel(int n1) throws Exception {
        double[] fin = new double[n1];
        for (int i = 0; i < n1; i++) {
            fin[i] = nd();
        }
        return fin;
    }

    private static void pn(Object o1) {
        System.out.println(o1);
    }

    private static void p(Object o1) {
        System.out.print(o1);
    }

    private static void ex() {
        System.exit(0);
    }

    private static BigInteger bi(long n1) {
        return new BigInteger(n1 + "");
    }

    private static class LR {
        BufferedReader k1;

        public LR() throws Exception {
            k1 = new BufferedReader(new InputStreamReader(System.in));
        }

        public String nx() throws Exception {
            return k1.readLine();
        }
    }

    private static class Sorted<E extends Comparable<? super E>> {
        ArrayList<E> set = new ArrayList();
        ArrayList<Integer> count = new ArrayList();

        public Sorted(ArrayList<E> o1) {
            Collections.sort(o1);
            for (int i = 0; i < o1.size(); i++) {
                if (i == 0) {
                    set.add(o1.get(i));
                    count.add(1);
                    continue;
                }
                E cur = o1.get(i);
                if (cur.equals(o1.get(i - 1))) {
                    count.set(count.size() - 1, count.get(count.size() - 1) + 1);
                } else {
                    set.add(cur);
                    count.add(1);
                }
            }
        }
    }

    private static class CS<E> {
        public long total = 0;
        public HashMap<E, Integer> m1 = new HashMap();

        public void add(E k1) {
            add(k1, 1);
        }

        public void remove(E k1) {
            add(k1, -1);
        }

        public void add(E k1, int n1) {
            int nv = 0;
            if (m1.containsKey(k1)) {
                nv = m1.get(k1);
            }
            m1.put(k1, nv + n1);
            total += n1;
            if (nv + n1 == 0) {
                m1.remove(k1);
            }
        }

        public void set(E k1, int n1) {
            int nv = 0;
            if (m1.containsKey(k1)) {
                nv = m1.get(k1);
            }
            m1.put(k1, n1);
            total += n1 - nv;
            if (n1 == 0) {
                m1.remove(k1);
            }
        }

        public int get(E k1) {
            if (!m1.containsKey(k1)) {
                return 0;
            } else {
                return m1.get(k1);
            }
        }

        public String toString() {
            return m1.toString();
        }
    }

    private static class DJS<E> {
        public HashMap<E, Integer> mapping = new HashMap();
        public ArrayList<E> value = new ArrayList();
        public ArrayList<Integer> p = new ArrayList();
        public ArrayList<Integer> size = new ArrayList();
        public int n = 0;

        public void add(E k1) {
            if (!mapping.containsKey(k1)) {
                mapping.put(k1, n);
                value.add(k1);
                p.add(n);
                size.add(1);
                n++;
            }
        }

        public int find(int x) {
            if (p.get(x) == x)
                return x;
            else
                return find(p.get(x));
        }

        public void union(E k1, E k2) {
            if (!mapping.containsKey(k1))
                add(k1);
            if (!mapping.containsKey(k2))
                add(k2);
            int s1 = mapping.get(k1);
            int s2 = mapping.get(k2);
            int r1 = find(s1);
            int r2 = find(s2);
            if (r1 == r2)
                return;
            if (size.get(r1) >= size.get(r2)) {
                size.set(r1, size.get(r1) + size.get(r2));
                p.set(r2, r1);
            } else {
                size.set(r2, size.get(r1) + size.get(r2));
                p.set(r1, r2);
            }
        }

        public void print() {
            System.out.println("value\n" + value);
            System.out.println("p\n" + p);
            System.out.println("size\n" + size);
        }

        public HashMap<Integer, ArrayList<E>> partition() {
            HashMap<Integer, ArrayList<E>> temp1 = new HashMap();
            for (int i = 0; i < p.size(); i++) {
                int classNo = find(i);
                if (!temp1.containsKey(classNo))
                    temp1.put(classNo, new ArrayList());
                ArrayList curList = temp1.get(classNo);
                curList.add(value.get(i));
            }
            return temp1;
        }
    }

    private static class Bit {
        public static String bin8(int n1) {
            String k1 = Integer.toBinaryString(n1);
            k1 = String.format("%8s", k1).replace(' ', '0');
            return k1;
        }

        public static String bin32(int n1) {
            String k1 = Integer.toBinaryString(n1);
            k1 = String.format("%32s", k1).replace(' ', '0');
            return k1;
        }
    }

    private static class Fenwick {
        long[] l1 = null;

        public Fenwick(int n1) {
            l1 = new long[n1];
        }

        public static int[] temp = new int[100];
        public static int len = -1;

        public long get(int n1) {
            int k1 = n1 + 1;
            int ptr = 0;
            for (int i = 0;; i++) {
                if (k1 == 0)
                    break;
                if (k1 % 2 == 1) {
                    temp[ptr++] = i;
                }
                k1 = k1 >> 1;
            }
            len = ptr;
            int ptr1 = -1;
            long fin = 0;
            for (int i = len - 1; i >= 0; i--) {
                int cur = temp[i];
                ptr1 += 1 << cur;
                fin += l1[ptr1];
            }
            return fin;
        }

        public void add(int id) {
            add(id, 1);
        }

        public void add(int id, long val) {
            int k1 = id;
            int v = 1;
            for (;;) {
                int idx = k1 * v + v - 1;
                if (idx >= l1.length) {
                    break;
                }
                if (k1 % 2 == 0)
                    l1[idx] += val;
                v = v << 1;
                k1 = k1 >> 1;
            }
        }

        public String toString() {
            long[] fin = new long[l1.length];
            for (int i = 0; i < l1.length; i++)
                fin[i] = get(i);
            return Arrays.toString(fin);
        }
    }

    private static class CBT {
        public static BigInteger fact(int n1) {
            BigInteger fin = BigInteger.ONE;
            for (int i = 2; i <= n1; i++) {
                fin = fin.multiply(new BigInteger(n1 + ""));
            }
            return fin;
        }

        public static BigInteger choose(int n1, int n2) {
            BigInteger fin = fact(n1);
            fin = fin.divide(fact(n2));
            fin = fin.divide(fact(n1 - n2));
            return fin;
        }
    }

    private static class NT {
        public static ArrayList<Integer> factor(int n1) {
            ArrayList<Integer> l1 = new ArrayList();
            for (int i = 1; i <= Math.sqrt(n1); i++) {
                if (n1 % i == 0) {
                    l1.add(i);
                    if (i != n1 / i)
                        l1.add(n1 / i);
                }
            }
            return l1;
        }

        public static int[] factor2(int n1) {
            ArrayList<Integer> l1 = new ArrayList();
            ArrayList<Integer> l2 = new ArrayList();
            for (int i = 1; i <= Math.sqrt(n1); i++) {
                if (n1 % i == 0) {
                    l1.add(i);
                    if (i != n1 / i)
                        l2.add(n1 / i);
                }

            }
            int[] fin = new int[l1.size() + l2.size()];
            for (int i = 0; i < l1.size(); i++) {
                fin[i] = l1.get(i);
            }
            for (int i = l1.size(); i < l1.size() + l2.size(); i++) {
                fin[i] = l2.get(l2.size() - 1 - (i - l1.size()));
            }
            return fin;
        }

        public static HashMap<Integer, int[]> facts = new HashMap();

        public static int[] facts(int n1) {
            if (facts.containsKey(n1))
                return facts.get(n1);
            int[] fin = factor2(n1);
            facts.put(n1, fin);
            return fin;
        }

        public static ArrayList<ArrayList<Integer>> mults(int k1) {
            ArrayList<ArrayList<Integer>> fin = new ArrayList();
            mults(k1, new ArrayList(), 1, fin);
            return fin;
        }

        public static void mults(int k1, ArrayList<Integer> stk, int max,
                ArrayList<ArrayList<Integer>> result) {
            if (k1 == 1) {
                result.add((ArrayList<Integer>) stk.clone());
                return;
            }
            int[] f1 = facts(k1);
            for (int i = 1; i < f1.length; i++) {
                if (f1[i] < max) {
                    continue;
                }
                stk.add(f1[i]);
                int max1 = max;
                if (f1[i] > max1)
                    max1 = f1[i];
                mults(k1 / f1[i], stk, max1, result);
                stk.remove(stk.size() - 1);
            }
        }

        public static int gcd(int n1, int n2) {
            int k1 = n1 > n2 ? n1 : n2;
            int k2 = k1 == n1 ? n2 : n1;
            int rm = k1 % k2;
            while (rm != 0) {
                k1 = k2;
                k2 = rm;
                rm = k1 % k2;
            }
            return k2;
        }

        public static long xgcd(long n1, long n2) {
            long k1 = n1;
            long k2 = n2;
            long[] l1 = { 1, 0 };
            long[] l2 = { 0, 1 };
            for (;;) {
                long f1 = k1 / k2;
                long f2 = k1 % k2;
                if (f2 == 0)
                    break;

                long[] l3 = { 0, 0 };
                l3[0] = l1[0] - f1 * l2[0];
                l3[1] = l1[1] - f1 * l2[1];
                l1 = l2;
                l2 = l3;

                k1 = k2;
                k2 = f2;
            }
            long fin = l2[1] % n1;
            if (fin < 0) {
                fin += n1;
            }
            return fin;
        }

        public static ArrayList<Integer> sieve(int n1) {
            ArrayList<Integer> fin = new ArrayList();
            boolean[] l1 = new boolean[n1 + 1];
            for (int m = 2; m <= Math.sqrt(n1); m++) {
                if (!l1[m]) {
                    fin.add(m);
                    for (int k = m * m; k <= n1; k += m) {
                        l1[k] = true;
                    }
                }
            }
            for (int m = (int) Math.sqrt(n1) + 1; m <= n1; m++) {
                if (!l1[m])
                    fin.add(m);
            }
            return fin;
        }

        public static BigInteger lcm(BigInteger n1, BigInteger n2) {
            BigInteger mul = n1.multiply(n2);
            return mul.divide(n1.gcd(n2));
        }

    }

    private static class MOD {
        public long mod = -1;

        public MOD(long k1) {
            mod = k1;
        }

        public long a(long n1, long n2) {
            long k1 = (n1 + n2) % mod;
            if (k1 < 0)
                k1 += mod;
            return k1;
        }

        public long s(long n1, long n2) {
            long k1 = (n1 - n2) % mod;
            if (k1 < 0)
                k1 += mod;
            return k1;
        }

        public long t(long n1, long n2) {
            long k1 = (n1 * n2) % mod;
            if (k1 < 0)
                k1 += mod;
            return k1;
        }

        public long d(long n1, long n2) {
            return (t(n1, xgcd(mod, n2))) % mod;
        }

        public static long xgcd(long n1, long n2) {
            long k1 = n1;
            long k2 = n2;
            long[] l1 = { 1, 0 };
            long[] l2 = { 0, 1 };
            for (;;) {
                long f1 = k1 / k2;
                long f2 = k1 % k2;
                if (f2 == 0)
                    break;

                long[] l3 = { 0, 0 };
                l3[0] = l1[0] - f1 * l2[0];
                l3[1] = l1[1] - f1 * l2[1];
                l1 = l2;
                l2 = l3;

                k1 = k2;
                k2 = f2;
            }
            long fin = l2[1] % n1;
            if (fin < 0) {
                fin += n1;
            }
            return fin;
        }

        public long pow(long n1, long pow) {
            if (pow == 0)
                return 1;
            else if (pow == 1)
                return t(1l, n1);
            else if (pow % 2 == 0) {
                long half = pow(n1, pow / 2);
                return t(half, half);
            } else {
                long half = pow(n1, pow / 2);
                return t(half, t(half, n1));
            }
        }
    }

    private static class Geometry {
        public static double dist1(double x1, double y1, double x2, double y2) {
            return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }

        public static double dist2(double k1, double k2) {
            return Math.sqrt(k1 * k1 + k2 * k2);
        }

        public static double sarea(double a, double b, double coseta) {
            return 0.5 * a * b * Math.sin(coseta);
        }

        public static double lcos(double a, double b, double coseta) {
            double k1 = a * a + b * b - 2 * a * b * Math.cos(coseta);
            return Math.sqrt(k1);
        }
    }

    private static class Palin {
        public static int[] map(String s1) {
            char[] l1 = s1.toCharArray();
            int[] l2 = new int[l1.length * 2 - 1];
            int ptr = 0;
            int k1 = 1;
            for (;;) {
                for (;;) {
                    int right = ptr / 2 + k1 / 2 + 1;
                    int left = ptr / 2 - k1 / 2 - 1;
                    if (ptr % 2 == 1)
                        left++;
                    if (right > l1.length - 1)
                        break;
                    if (left < 0)
                        break;
                    if (l1[left] == l1[right])
                        k1 += 2;
                    else
                        break;
                }
                if (ptr > l2.length - 1)
                    break;
                l2[ptr] = k1;
                boolean found = false;
                for (int i = 0; i < k1 - 1; i++) {
                    int temp = l2[ptr - i - 1];
                    if (temp + i + 1 == k1) {
                        ptr = ptr + i + 1;
                        k1 = temp;
                        found = true;
                        break;
                    } else {
                        l2[ptr + i + 1] = l2[ptr - i - 1];
                    }
                }
                if (!found) {
                    ptr += 1;
                    k1 = 0;
                    if (ptr % 2 == 0)
                        k1 = 1;
                }
            }
            return l2;
        }

        public static int[] idx(int id, int leng) {
            int left = (id) / 2 - leng / 2;
            if (id % 2 == 1)
                left += 1;
            int right = (id) / 2 + leng / 2;
            return new int[] { left, right };
        }
    }
}
