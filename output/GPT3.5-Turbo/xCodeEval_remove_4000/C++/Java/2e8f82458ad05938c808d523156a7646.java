import java.util.*;
import java.io.*;

class Main {
    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Sparse {
        int n;
        ArrayList<ArrayList<Pair<Integer, Integer>>> sp;

        void construct(ArrayList<Pair<Integer, Integer>> v) {
            n = v.size();
            int r = id17(n - 1);
            sp = new ArrayList<>(r);
            for (int i = 0; i < r; ++i) {
                sp.add(new ArrayList<>(Collections.nCopies(n, new Pair<>(-1, -1))));
            }
            for (int i = 0; i < n; ++i) {
                sp.get(0).set(i, v.get(i));
            }
            for (int i = 1; i < r; ++i) {
                for (int j = 0; j < n; ++j) {
                    Pair<Integer, Integer> p1 = sp.get(i - 1).get(j);
                    Pair<Integer, Integer> p2 = sp.get(i - 1).get((j + (1 << (i - 1))) % n);
                    sp.get(i).set(j, id1(p1, p2, n));
                }
            }
        }

        Pair<Integer, Integer> segment(int l, int r) {
            if ((l == -1) || (r == -1)) {
                return new Pair<>(-1, -1);
            }
            int szz = raz(r, l, n);
            if (l == r) {
                return sp.get(0).get(l);
            }
            int g = id17(szz) - 1;
            return id1(sp.get(g).get(l), sp.get(g).get(((r + 1 - (1 << g)) % n + n) % n), n);
        }
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static Pair<Integer, Integer> id1(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2, int n) {
        if ((p1.first == -1) || (p2.first == -1)) {
            return new Pair<>(-1, -1);
        }
        Pair<Integer, Integer> np1 = new Pair<>(0, raz(p1.second, p1.first, n));
        Pair<Integer, Integer> np2 = new Pair<>(raz(p2.first, p1.first, n), raz(p2.second, p1.first, n));
        if (np2.first <= np2.second) {
            if (np2.second == n - 1) {
                return new Pair<>(-1, -1);
            } else {
                return new Pair<>(sum(np1.first, p1.first, n), sum(Math.max(np1.second, np2.second), p1.first, n));
            }
        } else {
            if (np2.first <= np1.second + 1) {
                return new Pair<>(-1, -1);
            } else {
                return new Pair<>(sum(np2.first, p1.first, n), sum(Math.max(np1.second, np2.second), p1.first, n));
            }
        }
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int id9(ArrayList<Integer> v) {
        int ans = 0, n = v.size();
        for (int i = 1; i < n; ++i) {
            if (v.get(i) < v.get(ans)) {
                ans = i;
            }
        }
        return ans;
    }

    static int prod(int a, int b, int M) {
        return (int) (((long) (a)) * b % M);
    }

    static int sum(int a, int b, int M) {
        int c = a + b;
        return c >= M ? c - M : c;
    }

    static int raz(int a, int b, int M) {
        int c = a - b;
        return c < 0 ? c + M : c;
    }

    static int id17(int r) {
        int ans = 0;
        while (r != 0) {
            ++ans;
            r >>= 1;
        }
        return ans;
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - __builtin_clz(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
        return 32 - Integer.numberOfLeadingZeros(r);
    }

    static int id17(int r) {
