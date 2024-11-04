import java.util.*;
import java.io.*;

class Main {
    static class Modular {
        private long val;

        private static <T> Modular id0(T m) {
            long val = (long) m;
            if (val < 0) val += MODVALUE;
            if (val >= MODVALUE) val -= MODVALUE;
            return new Modular(val);
        }

        public boolean equals(Modular other) {
            return val == other.val;
        }

        public boolean notEquals(Modular other) {
            return !(val == other.val);
        }

        public <T> boolean equals(T other) {
            return equals(new Modular(other));
        }

        public <T> boolean notEquals(T other) {
            return !equals(new Modular(other));
        }

        public boolean lessThan(Modular other) {
            return val < other.val;
        }

        public boolean lessThanOrEqual(Modular other) {
            return val <= other.val;
        }

        public boolean greaterThan(Modular other) {
            return val > other.val;
        }

        public boolean greaterThanOrEqual(Modular other) {
            return val >= other.val;
        }

        public <T> boolean lessThan(T other) {
            return lessThan(new Modular(other));
        }

        public <T> boolean lessThanOrEqual(T other) {
            return lessThanOrEqual(new Modular(other));
        }

        public <T> boolean greaterThan(T other) {
            return greaterThan(new Modular(other));
        }

        public <T> boolean greaterThanOrEqual(T other) {
            return greaterThanOrEqual(new Modular(other));
        }

        public Modular add(Modular other) {
            return id0(val + other.val);
        }

        public Modular addAssign(Modular other) {
            return this.add(other);
        }

        public <T> Modular add(T other) {
            return this.add(new Modular(other));
        }

        public <T> Modular addAssign(T other) {
            return this.addAssign(new Modular(other));
        }

        public Modular increment() {
            return this.add(new Modular(1));
        }

        public Modular incrementPostfix() {
            Modular tmp = new Modular(this);
            this.increment();
            return tmp;
        }

        public Modular negate() {
            return new Modular(-val);
        }

        public Modular subtract(Modular other) {
            return id0(val - other.val);
        }

        public Modular subtractAssign(Modular other) {
            return this.subtract(other);
        }

        public <T> Modular subtract(T other) {
            return this.subtract(new Modular(other));
        }

        public <T> Modular subtractAssign(T other) {
            return this.subtractAssign(new Modular(other));
        }

        public Modular decrement() {
            return this.subtract(new Modular(1));
        }

        public Modular decrementPostfix() {
            Modular tmp = new Modular(this);
            this.decrement();
            return tmp;
        }

        public Modular multiply(Modular other) {
            return id0(val * other.val % MODVALUE);
        }

        public Modular multiplyAssign(Modular other) {
            return this.multiply(other);
        }

        public <T> Modular multiply(T other) {
            return this.multiply(new Modular(other));
        }

        public <T> Modular multiplyAssign(T other) {
            return this.multiplyAssign(new Modular(other));
        }

        public Modular pow(long power) {
            Modular m = new Modular(this);
            Modular ans = new Modular(1);
            while (power > 0) {
                if ((power & 1) == 1) ans.multiplyAssign(m);
                m.multiplyAssign(m);
                power >>= 1;
            }
            return ans;
        }

        public Modular pow(Modular other) {
            return pow(other.val);
        }

        public Modular inverse() {
            return pow(MODVALUE - 2);
        }

        public Modular divide(Modular other) {
            return this.multiply(other.inverse());
        }

        public Modular divideAssign(Modular other) {
            return this.divide(other);
        }

        public <T> Modular divide(T other) {
            return this.divide(new Modular(other));
        }

        public <T> Modular divideAssign(T other) {
            return this.divideAssign(new Modular(other));
        }

        public Modular() {
            val = 0;
        }

        public Modular(int val) {
            this.val = val % MODVALUE;
        }

        public Modular(long val) {
            this.val = val % MODVALUE;
        }
    }

    static class HashTable {
        int size = 0;
        ArrayList<Modular> xp, hash;

        Modular getHash(int l, int r) {
            assert l <= r && r <= size;
            return hash.get(l).subtract(hash.get(r + 1).multiply(xp.get(r - l + 1)));
        }

        HashTable(String s, Modular m) {
            int len = s.length();
            size = len;
            xp = new ArrayList<>(len + 1);
            hash = new ArrayList<>(len + 1);

            xp.add(new Modular(1));
            for (int i = 1; i <= len; i++)
                xp.add(xp.get(i - 1).multiply(m));

            hash.add(new Modular(0));
            for (int i = len - 1; i >= 0; i--)
                hash.add(hash.get(i + 1).multiply(m).add((long) s.charAt(i)));

        }
    }

    static final int MODVALUE = (int) 1e9 + 7;
    static final int[] mul = {7, 11, 13, 17, 19};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        String t = br.readLine();

        ArrayList<Integer> zp = new ArrayList<>();
        for (int i = 0; i < t.length(); i++)
            if (t.charAt(i) == '0')
                zp.add(i);

        int zpl = zp.size();

        Modular m = new Modular(mul[new Random().nextInt(5)]);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < zpl; i++)
            sb.append((char) ('0' + (zp.get(i) & 1)));

        String s = sb.toString();

        HashTable hash = new HashTable(s, m);

        sb = new StringBuilder();
        for (int i = 0; i < zpl; i++)
            sb.append((char) ('1' - (zp.get(i) & 1)));

        String rs = sb.toString();

        HashTable rhash = new HashTable(rs, m);

        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int l1 = Integer.parseInt(st.nextToken()) - 1;
            int l2 = Integer.parseInt(st.nextToken()) - 1;
            int len = Integer.parseInt(st.nextToken());

            int d1 = Collections.binarySearch(zp, l1);
            if (d1 < 0) d1 = -d1 - 1;
            int d2 = Collections.binarySearch(zp, l2);
            if (d2 < 0) d2 = -d2 - 1;

            int z1 = Collections.binarySearch(zp, l1 + len - 1);
            if (z1 < 0) z1 = -z1 - 1;
            else z1++;
            int z2 = Collections.binarySearch(zp, l2 + len - 1);
            if (z2 < 0) z2 = -z2 - 1;
            else z2++;

            if (z1 != z2) {
                pw.println("No");
                continue;
            }

            if (z1 == 0) {
                pw.println("Yes");
                continue;
            }

            Modular hash1 = hash.getHash(d1, d1 + z1 - 1);
            Modular hash2 = ((l1 & 1) == (l2 & 1) ? hash.getHash(d2, d2 + z1 - 1) : rhash.getHash(d2, d2 + z1 - 1));

            pw.println(hash1.equals(hash2) ? "Yes" : "No");
        }

        pw.close();
    }
}
