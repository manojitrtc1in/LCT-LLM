import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static final long MAX_MOD = 1000000007L;
    static final long MOD = 998244353L;

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class ModInt<T> {
        T value;

        ModInt(T value) {
            this.value = value;
        }

        ModInt<T> add(ModInt<T> rhs) {
            return new ModInt<>((T) ((value + rhs.value) % MOD));
        }

        ModInt<T> subtract(ModInt<T> rhs) {
            return new ModInt<>((T) ((value - rhs.value + MOD) % MOD));
        }

        ModInt<T> multiply(ModInt<T> rhs) {
            return new ModInt<>((T) ((value * rhs.value) % MOD));
        }

        ModInt<T> divide(ModInt<T> rhs) {
            return multiply(rhs.inverse());
        }

        ModInt<T> inverse() {
            return pow(MOD - 2);
        }

        ModInt<T> pow(long b) {
            ModInt<T> ans = new ModInt<>((T) value);
            ModInt<T> val = new ModInt<>((T) value);
            b--;
            while (b > 0) {
                if (b % 2 == 1) {
                    ans = ans.multiply(val);
                }
                val = val.multiply(val);
                b /= 2;
            }
            return ans;
        }

        @Override
        public String toString() {
            return value.toString();
        }
    }

    static class Fraction {
        long a;
        long b;

        Fraction() {
            a = 0L;
            b = 1L;
        }

        Fraction(long c, long d) {
            long hoge = gcd(Math.abs(c), Math.abs(d));
            c /= hoge;
            d /= hoge;
            if (d < 0) {
                d *= -1;
                c *= -1;
            }
            a = c;
            b = d;
        }

        boolean lessThan(Fraction rhs) {
            return a * rhs.b < rhs.a * b;
        }

        long gcd(long a, long b) {
            if (b == 0) {
                return a;
            }
            return gcd(b, a % b);
        }
    }

    static class Matrix<T> {
        List<List<T>> data;

        Matrix(List<List<T>> a) {
            data = a;
        }

        Matrix<T> add(Matrix<T> obj) {
            List<List<T>> ans = new ArrayList<>();
            assert obj.data.size() == this.data.size();
            assert obj.data.get(0).size() == this.data.get(0).size();
            for (int i = 0; i < obj.data.size(); ++i) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(i).size(); ++q) {
                    T hoge = obj.data.get(i).get(q) + this.data.get(i).get(q);
                    ans.get(i).add(hoge);
                }
            }
            return new Matrix<>(ans);
        }

        Matrix<T> subtract(Matrix<T> obj) {
            List<List<T>> ans = new ArrayList<>();
            assert obj.data.size() == this.data.size();
            assert obj.data.get(0).size() == this.data.get(0).size();
            for (int i = 0; i < obj.data.size(); ++i) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(i).size(); ++q) {
                    T hoge = this.data.get(i).get(q) - obj.data.get(i).get(q);
                    ans.get(i).add(hoge);
                }
            }
            return new Matrix<>(ans);
        }

        Matrix<T> multiply(Matrix<T> obj) {
            List<List<T>> ans = new ArrayList<>();
            assert obj.data.size() == this.data.get(0).size();
            for (int i = 0; i < this.data.size(); ++i) {
                ans.add(new ArrayList<>());
                for (int q = 0; q < obj.data.get(0).size(); ++q) {
                    T hoge = this.data.get(i).get(0) * obj.data.get(0).get(q);
                    for (int t = 1; t < obj.data.get(i).size(); ++t) {
                        hoge += this.data.get(i).get(t) * obj.data.get(t).get(q);
                    }
                    ans.get(i).add(hoge);
                }
            }
            return new Matrix<>(ans);
        }

        Matrix<T> multiplyAssign(Matrix<T> obj) {
            this = this.multiply(obj);
            return this;
        }

        Matrix<T> addAssign(Matrix<T> obj) {
            this = this.add(obj);
            return this;
        }

        Matrix<T> subtractAssign(Matrix<T> obj) {
            this = this.subtract(obj);
            return this;
        }
    }

    static class Dice {
        List<Long> vertexs;

        Dice(List<Long> init) {
            vertexs = init;
        }

        void RtoL() {
            for (int q = 1; q < 4; ++q) {
                Collections.swap(vertexs, q, q + 1);
            }
        }

        void LtoR() {
            for (int q = 3; q >= 1; --q) {
                Collections.swap(vertexs, q, q + 1);
            }
        }

        void UtoD() {
            Collections.swap(vertexs, 5, 4);
            Collections.swap(vertexs, 2, 5);
            Collections.swap(vertexs, 0, 2);
        }

        void DtoU() {
            Collections.swap(vertexs, 0, 2);
            Collections.swap(vertexs, 2, 5);
            Collections.swap(vertexs, 5, 4);
        }

        boolean ReachAble(Dice now) {
            Set<Dice> hoge = new HashSet<>();
            Queue<Dice> next = new LinkedList<>();
            next.add(now);
            hoge.add(now);
            while (!next.isEmpty()) {
                Dice seeing = next.poll();
                if (seeing.equals(this)) {
                    return true;
                }
                seeing.RtoL();
                if (!hoge.contains(seeing)) {
                    hoge.add(seeing);
                    next.add(seeing);
                }
                seeing.LtoR();
                seeing.LtoR();
                if (!hoge.contains(seeing)) {
                    hoge.add(seeing);
                    next.add(seeing);
                }
                seeing.RtoL();
                seeing.UtoD();
                if (!hoge.contains(seeing)) {
                    hoge.add(seeing);
                    next.add(seeing);
                }
                seeing.DtoU();
                seeing.DtoU();
                if (!hoge.contains(seeing)) {
                    hoge.add(seeing);
                    next.add(seeing);
                }
            }
            return false;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null || getClass() != obj.getClass()) {
                return false;
            }
            Dice dice = (Dice) obj;
            return vertexs.equals(dice.vertexs);
        }

        @Override
        public int hashCode() {
            return Objects.hash(vertexs);
        }
    }

    static Pair<Dice, Dice> TwoDimDice(int center, int up) {
        int target = 1;
        while (true) {
            if (center != target && 7 - center != target && up != target && 7 - up != target) {
                break;
            }
            target++;
        }
        return new Pair<>(new Dice(Arrays.asList((long) up, (long) target, (long) center, (long) (7 - target), (long) (7 - center), (long) (7 - up))),
                new Dice(Arrays.asList((long) up, (long) (7 - target), (long) center, (long) target, (long) (7 - center), (long) (7 - up))));
    }

    static List<Dice> OneDimDice(int center) {
        int bo = Math.min(center, 7 - center);
        Pair<Integer, Integer> goa;
        if (bo == 1) {
            goa = new Pair<>(2, 3);
        } else if (bo == 2) {
            goa = new Pair<>(1, 3);
        } else {
            goa = new Pair<>(1, 2);
        }
        List<Dice> now = new ArrayList<>();
        now.add(new Dice(Arrays.asList((long) goa.first, (long) goa.second, (long) center, (long) (7 - goa.second), (long) (7 - center), (long) (7 - goa.first))));
        now.add(new Dice(Arrays.asList((long) goa.first, (long) (7 - goa.second), (long) center, (long) goa.second, (long) (7 - center), (long) (7 - goa.first))));
        now.add(new Dice(Arrays.asList((long) (7 - goa.first), (long) goa.second, (long) center, (long) (7 - goa.second), (long) (7 - center), (long) goa.first)));
        now.add(new Dice(Arrays.asList((long) (7 - goa.first), (long) (7 - goa.second), (long) center, (long) goa.second, (long) (7 - center), (long) goa.first)));
        return now;
    }

    static class KMP {
        List<Integer> table;
        List<Integer> pattern;

        KMP(List<Integer> a) {
            build(a);
        }

        void build(List<Integer> a) {
            pattern = a;
            table = new ArrayList<>(a.size() + 1);
            for (int i = 0; i < a.size() + 1; ++i) {
                table.add(-1);
            }
            int j = -1;
            for (int i = 0; i < a.size(); ++i) {
                while (j >= 0 && !pattern.get(i).equals(pattern.get(j))) {
                    j = table.get(j);
                }
                table.set(i + 1, ++j);
            }
        }

        List<Integer> search(List<Integer> a) {
            List<Integer> ans = new ArrayList<>();
            for (int i = 0, k = 0; i < a.size(); ++i) {
                while (k >= 0 && !a.get(i).equals(pattern.get(k))) {
                    k = table.get(k);
                }
                ++k;
                if (k >= pattern.size()) {
                    ans.add(i - pattern.size() + 1);
                    k = table.get(k);
                }
            }
            return ans;
        }
    }

    static int xor128() {
        long x = 123456789L, y = 362436069L, z = 521288629L, w = 88675123L;
        long t = (x ^ (x << 11));
        x = y;
        y = z;
        z = w;
        return (int) ((w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)))));
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String t = sc.next();
        List<Integer> cnter = new ArrayList<>();
        for (int i = 0; i < t.length(); ++i) {
            if (t.charAt(i) == '0') {
                cnter.add(i * 2 + i % 2);
            }
        }
        Pair<ModInt<Long>, ModInt<Long>>[] hoge = new Pair[300000];
        Pair<ModInt<Long>, ModInt<Long>>[] rev = new Pair[300000];
        for (int i = 0; i < 300000; ++i) {
            hoge[i] = new Pair<>(new ModInt<>(0L), new ModInt<>(0L));
            rev[i] = new Pair<>(new ModInt<>(0L), new ModInt<>(0L));
        }
        Pair<ModInt<Long>, ModInt<Long>> nexts = new Pair<>(new ModInt<>(1L), new ModInt<>(1L));
        for (int i = 0; i < cnter.size(); ++i) {
            hoge[i + 1] = new Pair<>(hoge[i].first.add(nexts.first.multiply(cnter.get(i) % 2)),
                    hoge[i].second.add(nexts.second.multiply(cnter.get(i) % 2)));
            rev[i + 1] = new Pair<>(rev[i].first.add(nexts.first.multiply((cnter.get(i) + 1) % 2)),
                    rev[i].second.add(nexts.second.multiply((cnter.get(i) + 1) % 2)));
            nexts.first = nexts.first.multiply(2L);
            nexts.second = nexts.second.multiply(2L);
        }
        int query = sc.nextInt();
        for (int i = 0; i < query; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            a--;
            b--;
            Pair<Integer, Integer> Left = new Pair<>(Collections.binarySearch(cnter, a * 2),
                    Collections.binarySearch(cnter, (a + c) * 2));
            Pair<Integer, Integer> Right = new Pair<>(Collections.binarySearch(cnter, b * 2),
                    Collections.binarySearch(cnter, (b + c) * 2));
            if (Left.second - Left.first != Right.second - Right.first) {
                System.out.println("No");
                continue;
            }
            int ok = 1;
            Pair<ModInt<Long>, ModInt<Long>> aa, bb;
            aa = new Pair<>(hoge[Left.second].first.subtract(hoge[Left.first].first),
                    hoge[Left.second].second.subtract(hoge[Left.first].second));
            if (a % 2 == b % 2) {
                bb = new Pair<>(hoge[Right.second].first.subtract(hoge[Right.first].first),
                        hoge[Right.second].second.subtract(hoge[Right.first].second));
            } else {
                bb = new Pair<>(rev[Right.second].first.subtract(rev[Right.first].first),
                        rev[Right.second].second.subtract(rev[Right.first].second));
            }
            if (Left.first != 0) {
                aa.first = aa.first.divide(new ModInt<>(pow(2L, Left.first)));
                aa.second = aa.second.divide(new ModInt<>(pow(2L, Left.first)));
            }
            if (Right.first != 0) {
                bb.first = bb.first.divide(new ModInt<>(pow(2L, Right.first)));
                bb.second = bb.second.divide(new ModInt<>(pow(2L, Right.first)));
            }
            if (!aa.first.value.equals(bb.first.value) || !aa.second.value.equals(bb.second.value)) {
                ok = 0;
            }
            if (ok == 1) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }

    public static void main(String[] args) {
        solve();
    }
}
