import java.util.*;
import java.io.*;

class Modular {
    private long val;
    private static final int MODVALUE = 1000000007;

    public Modular() {
        this.val = 0;
    }

    public Modular(int val) {
        this.val = (val % MODVALUE + MODVALUE) % MODVALUE;
    }

    public Modular(long val) {
        this.val = (val % MODVALUE + MODVALUE) % MODVALUE;
    }

    public Modular add(Modular other) {
        return new Modular((this.val + other.val) % MODVALUE);
    }

    public Modular subtract(Modular other) {
        return new Modular((this.val - other.val + MODVALUE) % MODVALUE);
    }

    public Modular multiply(Modular other) {
        return new Modular((this.val * other.val) % MODVALUE);
    }

    public Modular pow(long power) {
        Modular m = this, ans = new Modular(1);
        while (power > 0) {
            if ((power & 1) == 1) ans = ans.multiply(m);
            m = m.multiply(m);
            power >>= 1;
        }
        return ans;
    }

    public Modular inv() {
        return this.pow(MODVALUE - 2);
    }

    public long getVal() {
        return val;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Modular)) return false;
        Modular other = (Modular) obj;
        return this.val == other.val;
    }

    @Override
    public String toString() {
        return Long.toString(val);
    }
}

class HashTable {
    private int size;
    private List<Modular> xp, hash;

    public HashTable(String s, Modular m) {
        int len = s.length();
        size = len;
        xp = new ArrayList<>(Collections.nCopies(len + 1, new Modular(0)));
        hash = new ArrayList<>(Collections.nCopies(len + 1, new Modular(0)));

        xp.set(0, new Modular(1));
        for (int i = 1; i <= len; i++)
            xp.set(i, xp.get(i - 1).multiply(m));

        hash.set(len, new Modular(0));
        for (int i = len - 1; i >= 0; i--)
            hash.set(i, hash.get(i + 1).multiply(m).add(s.charAt(i));
    }

    public Modular getHash(int l, int r) {
        assert l <= r && r <= size;
        return hash.get(l).subtract(hash.get(r + 1).multiply(xp.get(r - l + 1)));
    }
}

public class c0fd29effc3cc3cb62a11119d5e69f7d_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random rng = new Random();

        int n = scanner.nextInt();
        String t = scanner.next();

        List<Integer> zp = new ArrayList<>();
        for (int i = 0; i < t.length(); i++)
            if (t.charAt(i) == '0')
                zp.add(i);

        int zpl = zp.size();
        long[] mul = {7, 11, 13, 17, 19};
        Modular m = new Modular(mul[rng.nextInt(5)]);

        StringBuilder s = new StringBuilder();
        for (int i = 0; i < zpl; i++)
            s.append((char) ('0' + (zp.get(i) & 1)));

        HashTable hash = new HashTable(s.toString(), m);

        for (int i = 0; i < zpl; i++)
            s.setCharAt(i, (char) ('1' - (zp.get(i) & 1)));

        HashTable rhash = new HashTable(s.toString(), m);

        int q = scanner.nextInt();
        while (q-- > 0) {
            int l1 = scanner.nextInt() - 1;
            int l2 = scanner.nextInt() - 1;
            int len = scanner.nextInt();

            int d1 = Collections.binarySearch(zp, l1);
            if (d1 < 0) d1 = -d1 - 1;

            int d2 = Collections.binarySearch(zp, l2);
            if (d2 < 0) d2 = -d2 - 1;

            int z1 = Collections.binarySearch(zp, l1 + len - 1);
            if (z1 < 0) z1 = -z1 - 1;
            z1 -= d1;

            int z2 = Collections.binarySearch(zp, l2 + len - 1);
            if (z2 < 0) z2 = -z2 - 1;
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
            Modular hash2 = ((l1 & 1) == (l2 & 1) ? hash.getHash(d2, d2 + z1 - 1) : rhash.getHash(d2, d2 + z1 - 1));

            System.out.println(hash1.equals(hash2) ? "Yes" : "No");
        }
    }
}
