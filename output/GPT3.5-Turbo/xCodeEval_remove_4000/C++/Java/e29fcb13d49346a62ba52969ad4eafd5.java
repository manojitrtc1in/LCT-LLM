import java.io.*;
import java.util.*;

class Main {
    static final int mod = 998244353;
    static class modint {
        int v;
        modint(int val) {
            v = val;
        }
        modint add(modint m) {
            return new modint((v + m.v) % mod);
        }
        modint subtract(modint m) {
            return new modint((v - m.v + mod) % mod);
        }
        modint multiply(modint m) {
            return new modint((int)((long)v * m.v % mod));
        }
        modint divide(modint m) {
            return multiply(m.inverse());
        }
        modint inverse() {
            return power(mod - 2);
        }
        modint power(int n) {
            modint ans = new modint(1);
            modint x = new modint(v);
            while (n > 0) {
                if ((n & 1) == 1) {
                    ans = ans.multiply(x);
                }
                x = x.multiply(x);
                n >>= 1;
            }
            return ans;
        }
        int intValue() {
            return v;
        }
        public String toString() {
            return Integer.toString(v);
        }
    }
    static int popcount(int u) {
        return Integer.bitCount(u);
    }
    static int id0(int u) {
        return u == 0 ? 0 : 32 - Integer.numberOfLeadingZeros(u);
    }
    static int id6(int u) {
        return id0(u);
    }
    static int id4(int u) {
        return Integer.lowestOneBit(u);
    }
    static int clog(int u) {
        return u == 0 ? 0 : 32 - Integer.numberOfLeadingZeros(u - 1);
    }
    static boolean id2(int u) {
        return u != 0 && (u & (u - 1)) == 0;
    }
    static int ceil2(int u) {
        return 1 << clog(u);
    }
    static int floor2(int u) {
        return 1 << (id0(u) - 1);
    }
    static boolean btest(int mask, int ind) {
        return ((mask >> ind) & 1) == 1;
    }
    static void bset(int[] mask, int ind) {
        mask[0] |= 1 << ind;
    }
    static void breset(int[] mask, int ind) {
        mask[0] &= ~(1 << ind);
    }
    static void bflip(int[] mask, int ind) {
        mask[0] ^= 1 << ind;
    }
    static void bset(int[] mask, int ind, boolean b) {
        if (b) {
            bset(mask, ind);
        } else {
            breset(mask, ind);
        }
    }
    static int bcut(int mask, int ind) {
        return ind == 0 ? 0 : (mask << (32 - ind)) >>> (32 - ind);
    }
    static <T> boolean chmin(T[] a, T b) {
        if (((Comparable<T>)a[0]).compareTo(b) > 0) {
            a[0] = b;
            return true;
        }
        return false;
    }
    static <T> boolean chmax(T[] a, T b) {
        if (((Comparable<T>)a[0]).compareTo(b) < 0) {
            a[0] = b;
            return true;
        }
        return false;
    }
    static final int inf = Integer.MAX_VALUE / 4;
    static final double eps = 1e-9;
    static final double pi = Math.PI;
    static final int[] dx = {1, 0, -1, 0, 1, -1, -1, 1};
    static final int[] dy = {0, 1, 0, -1, 1, 1, -1, -1};
    static final int[] dx8 = {1, 1, 0, -1, -1, -1, 0, 1, 0};
    static final int[] dy8 = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    static final int[] dx4 = {1, 0, -1, 0};
    static final int[] dy4 = {0, 1, 0, -1};
    static final int[] dx2 = {1, -1};
    static final int[] dy2 = {1, -1};
    static final int[] dx9 = {1, 1, 1, 0, 0, 0, -1, -1, -1};
    static final int[] dy9 = {1, 0, -1, 1, 0, -1, 1, 0, -1};
    static final int[] dx91 = {2, 1, -1, -2, -2, -1, 1, 2};
    static final int[] dy91 = {1, 2, 2, 1, -1, -2, -2, -1};
    static final int[] dx81 = {1, 1, 1, 0, 0, 0, -1, -1, -1};
    static final int[] dy81 = {1, 0, -1, 1, 0, -1, 1, 0, -1};
    static final int[] dx41 = {1, 0, -1, 0};
    static final int[] dy41 = {0, 1, 0, -1};
    static final int[] dx21 = {1, -1};
    static final int[] dy21 = {1, -1};
    static final int[] dx61 = {0, 1, 1, 1, 0, -1, -1, -1};
    static final int[] dy61 = {1, 1, 0, -1, -1, -1, 0, 1};
    static final int[] dx51 = {0, 1, 0, -1, 0};
    static final int[] dy51 = {2, 0, -2, 0, 0};
    static final int[] dx31 = {1, 1, 0, -1, -1};
    static final int[] dy31 = {0, 1, 1, 1, 0};
    static final int[] dx11 = {1, 0, -1, 0, 1};
    static final int[] dy11 = {0, 1, 0, -1, 0};
    static final int[] dx71 = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    static final int[] dy71 = {1, 1, 0, -1, -1, -1, 0, 1, 0};
    static final int[] dx01 = {0, 1, 0, -1, 0};
    static final int[] dy01 = {1, 0, -1, 0, 0};
    static final int[] dx01r = {0, -1, 0, 1, 0};
    static final int[] dy01r = {-1, 0, 1, 0, 0};
    static final int[] dx81r = {0, -1, -1, -1, 0, 1, 1, 1, 0};
    static final int[] dy81r = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
    static final int[] dx41r = {0, -1, 0, 1};
    static final int[] dy41r = {-1, 0, 1, 0};
    static final int[] dx21r = {0, 1};
    static final int[] dy21r = {-1, 1};
    static final int[] dx61r = {0, -1, -1, -1, 0, 1, 1, 1};
    static final int[] dy61r = {-1, -1, 0, 1, 1, 1, 0, -1};
    static final int[] dx51r = {0, -1, 0, 1, 0};
    static final int[] dy51r = {-2, 0, 2, 0, 0};
    static final int[] dx31r = {0, -1, -1, -1, 0};
    static final int[] dy31r = {-1, -1, 0, 1, 0};
    static final int[] dx11r = {0, -1, 0, 1, 0};
    static final int[] dy11r = {-1, 0, 1, 0, 0};
    static final int[] dx71r = {0, -1, -1, -1, 0, 1, 1, 1, 0};
    static final int[] dy71r = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
    static final int[] dx01r1 = {0, -1, 0, 1, 0};
    static final int[] dy01r1 = {1, 0, -1, 0, 0};
    static final int[] dx81r1 = {0, -1, -1, -1, 0, 1, 1, 1, 0};
    static final int[] dy81r1 = {1, 1, 0, -1, -1, -1, 0, 1, 0};
    static final int[] dx41r1 = {0, -1, 0, 1};
    static final int[] dy41r1 = {1, 0, -1, 0};
    static final int[] dx21r1 = {0, 1};
    static final int[] dy21r1 = {1, -1};
    static final int[] dx61r1 = {0, -1, -1, -1, 0, 1, 1, 1};
    static final int[] dy61r1 = {1, 1, 0, -1, -1, -1, 0, 1};
    static final int[] dx51r1 = {0, -1, 0, 1, 0};
    static final int[] dy51r1 = {2, 0, -2, 0, 0};
    static final int[] dx31r1 = {0, -1, -1, -1, 0};
    static final int[] dy31r1 = {1, 1, 0, -1, 0};
    static final int[] dx11r1 = {0, -1, 0, 1, 0};
    static final int[] dy11r1 = {1, 0, -1, 0, 0};
    static final int[] dx71r1 = {0, -1, -1, -1, 0, 1, 1, 1, 0};
    static final int[] dy71r1 = {1, 1, 0, -1, -1, -1, 0, 1, 0};
    static final int[] dx01r2 = {0, 1, 0, -1, 0};
    static final int[] dy01r2 = {-1, 0, 1, 0, 0};
    static final int[] dx81r2 = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    static final int[] dy81r2 = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
    static final int[] dx41r2 = {0, 1, 0, -1};
    static final int[] dy41r2 = {-1, 0, 1, 0};
    static final int[] dx21r2 = {0, -1};
    static final int[] dy21r2 = {-1, 1};
    static final int[] dx61r2 = {0, 1, 1, 1, 0, -1, -1, -1};
    static final int[] dy61r2 = {-1, -1, 0, 1, 1, 1, 0, -1};
    static final int[] dx51r2 = {0, 1, 0, -1, 0};
    static final int[] dy51r2 = {-2, 0, 2, 0, 0};
    static final int[] dx31r2 = {0, 1, 1, 1, 0};
    static final int[] dy31r2 = {-1, -1, 0, 1, 0};
    static final int[] dx11r2 = {0, 1, 0, -1, 0};
    static final int[] dy11r2 = {-1, 0, 1, 0, 0};
    static final int[] dx71r2 = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    static final int[] dy71r2 = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
    static final int[] dx01r3 = {0, 1, 0, -1, 0};
    static final int[] dy01r3 = {1, 0, -1, 0, 0};
    static final int[] dx81r3 = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    static final int[] dy81r3 = {1, 1, 0, -1, -1, -1, 0, 1, 0};
    static final int[] dx41r3 = {0, 1, 0, -1};
    static final int[] dy41r3 = {1, 0, -1, 0};
    static final int[] dx21r3 = {0, -1};
    static final int[] dy21r3 = {1, -1};
    static final int[] dx61r3 = {0, 1, 1, 1, 0, -1, -1, -1};
    static final int[] dy61r3 = {1, 1, 0, -1, -1, -1, 0, 1};
    static final int[] dx51r3 = {0, 1, 0, -1, 0};
    static final int[] dy51r3 = {2, 0, -2, 0, 0};
