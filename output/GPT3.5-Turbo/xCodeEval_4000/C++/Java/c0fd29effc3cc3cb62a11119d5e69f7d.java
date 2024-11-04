import java.util.*;
import java.io.*;

class Main {
    static class Modular {
        private long val;

        private static <T> Modular toModular(T m) {
            long val = (long) m;
            if (val < 0) val += MODVALUE;
            if (val >= MODVALUE) val -= MODVALUE;
            return new Modular(val);
        }

        public boolean equals(Modular other) {
            return val == other.val;
        }

        public boolean equals(T other) {
            return this.equals(new Modular(other));
        }

        public boolean notEquals(Modular other) {
            return !this.equals(other);
        }

        public boolean notEquals(T other) {
            return !this.equals(new Modular(other));
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

        public Modular add(Modular other) {
            return toModular(val + other.val);
        }

        public Modular add(T other) {
            return this.add(new Modular(other));
        }

        public Modular increment() {
            return this.add(1);
        }

        public Modular subtract(Modular other) {
            return toModular(val - other.val);
        }

        public Modular subtract(T other) {
            return this.subtract(new Modular(other));
        }

        public Modular negate() {
            return new Modular(-val);
        }

        public Modular multiply(Modular other) {
            return toModular(val * other.val % MODVALUE);
        }

        public Modular multiply(T other) {
            return this.multiply(new Modular(other));
        }

        public Modular pow(long power) {
            Modular m = this;
            Modular ans = new Modular(1);
            while (power > 0) {
                if ((power & 1) == 1) ans = ans.multiply(m);
                m = m.multiply(m);
                power >>= 1;
            }
            return ans;
        }

        public Modular inverse() {
            return this.pow(MODVALUE - 2);
        }

        public Modular divide(Modular other) {
            return this.multiply(other.inverse());
        }

        public Modular divide(T other) {
            return this.divide(new Modular(other));
        }

        public String toString() {
            return Long.toString(val);
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
        List<Modular> xp, hash;

        public Modular getHash(int l, int r) {
            assert l <= r && r <= size;
            return hash.get(l).subtract(hash.get(r + 1).multiply(xp.get(r - l + 1)));
        }

        public HashTable(String s, Modular m) {
            int len = s.length();
            size = len;
            xp = new ArrayList<>();
            hash = new ArrayList<>();

            xp.add(new Modular(1));
            for (int i = 1; i <= len; i++)
                xp.add(xp.get(i - 1).multiply(m));

            hash.add(new Modular(0));
            for (int i = len - 1; i >= 0; i--)
                hash.add(hash.get(i + 1).multiply(m).add((long) s.charAt(i)));
        }
    }

    static final int MODVALUE = 1000000007;
    static final long[] mul = {7, 11, 13, 17, 19};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String t = br.readLine();

        List<Integer> zp = new ArrayList<>();
        for (int i = 0; i < t.length(); i++)
            if (t.charAt(i) == '0')
                zp.add(i);

        int zpl = zp.size();

        Modular m = new Modular(mul[new Random().nextInt(5)]);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < zpl; i++)
            sb.append(zp.get(i) & 1);

        String s = sb.toString();

        HashTable hash = new HashTable(s, m);

        sb.setLength(0);
        for (int i = 0; i < zpl; i++)
            sb.append('1' - (zp.get(i) & 1));

        s = sb.toString();

        HashTable rhash = new HashTable(s, m);

        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int l1 = Integer.parseInt(st.nextToken()) - 1;
            int l2 = Integer.parseInt(st.nextToken()) - 1;
            int len = Integer.parseInt(st.nextToken());

            int d1 = Collections.binarySearch(zp, l1);
            int d2 = Collections.binarySearch(zp, l2);

            if (d1 < 0) d1 = -d1 - 1;
            if (d2 < 0) d2 = -d2 - 1;

            int z1 = Collections.binarySearch(zp, l1 + len - 1);
            int z2 = Collections.binarySearch(zp, l2 + len - 1);

            if (z1 < 0) z1 = -z1 - 2;
            if (z2 < 0) z2 = -z2 - 2;

            z1 -= d1;
            z2 -= d2;

            if (z1 != z2) {
                System.out.println("No");
                continue;
            }

            if (z1 == 0) {
                System.out.println("Yes");
                continue;
            }

            Modular hash1 = hash.getHash(d1, d1 + z1 - 1);
            Modular hash2 = ((l1 & 1) == (l2 & 1)) ? hash.getHash(d2, d2 + z1 - 1) : rhash.getHash(d2, d2 + z1 - 1);

            System.out.println(hash1.equals(hash2) ? "Yes" : "No");
        }
    }
}
