import java.util.*;
import java.util.function.Function;

public class 6886f2fe7b92dcf1b3e045025ca2253f_nc {
    static final long MAX_MOD = 1000000007L;
    static final long MOD = 998244353L;
    static final double eps = 1e-12;
    static List<Long> cnter = new ArrayList<>();
    static Pair<ModInt, ModInt>[] hoge = new Pair[300000];
    static Pair<ModInt, ModInt>[] rev = new Pair[300000];

    static class Point {
        double real, imag;

        Point(double real, double imag) {
            this.real = real;
            this.imag = imag;
        }

        Point subtract(Point other) {
            return new Point(this.real - other.real, this.imag - other.imag);
        }

        double abs() {
            return Math.sqrt(real * real + imag * imag);
        }

        double dot(Point other) {
            return this.real * other.real + this.imag * other.imag;
        }

        double cross(Point other) {
            return this.real * other.imag - this.imag * other.real;
        }
    }

    static class Line {
        Point first, second;

        Line(Point first, Point second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Circle {
        Point center;
        double r;

        Circle(Point center, double r) {
            this.center = center;
            this.r = r;
        }
    }

    static class ModInt {
        long value;

        ModInt() {
            this.value = 0;
        }

        ModInt(long a) {
            this.value = ((a % MAX_MOD) + 2 * MAX_MOD) % MAX_MOD;
        }

        ModInt add(ModInt rhs) {
            return new ModInt(this.value + rhs.value >= MAX_MOD ? this.value + rhs.value - MAX_MOD : this.value + rhs.value);
        }

        ModInt subtract(ModInt rhs) {
            return new ModInt(this.value < rhs.value ? this.value + MAX_MOD - rhs.value : this.value - rhs.value);
        }

        ModInt multiply(ModInt rhs) {
            return new ModInt((this.value * rhs.value) % MAX_MOD);
        }

        ModInt divide(ModInt rhs) {
            long rem = MAX_MOD - 2;
            ModInt result = new ModInt(1);
            while (rem > 0) {
                if (rem % 2 == 1) {
                    result = result.multiply(rhs);
                }
                rhs = rhs.multiply(rhs);
                rem /= 2;
            }
            return result;
        }
    }

    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }

    static void init() {
        // Initialization logic if needed
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        String t = scanner.next();
        for (int i = 0; i < t.length(); i++) {
            if (t.charAt(i) == '0') {
                cnter.add(i * 2 + i % 2);
            }
        }
        Pair<ModInt, ModInt> nexts = new Pair<>(new ModInt(1), new ModInt(1));
        for (int i = 0; i < cnter.size(); i++) {
            hoge[i + 1] = new Pair<>(hoge[i].first.add(nexts.first.multiply(cnter.get(i) % 2)), 
                                         hoge[i].second.add(nexts.second.multiply(cnter.get(i) % 2)));
            rev[i + 1] = new Pair<>(rev[i].first.add(nexts.first.multiply((cnter.get(i) + 1) % 2)), 
                                                       rev[i].second.add(nexts.second.multiply((cnter.get(i) + 1) % 2)));
            nexts.first = nexts.first.multiply(new ModInt(2));
            nexts.second = nexts.second.multiply(new ModInt(2));
        }
        int query = scanner.nextInt();
        for (int i = 0; i < query; i++) {
            long a = scanner.nextLong() - 1;
            long b = scanner.nextLong() - 1;
            long c = scanner.nextLong();
            Pair<Integer, Integer> Left = new Pair<>(lowerBound(cnter, a * 2), lowerBound(cnter, (a + c) * 2));
            Pair<Integer, Integer> Right = new Pair<>(lowerBound(cnter, b * 2), lowerBound(cnter, (b + c) * 2));
            if (Left.second - Left.first != Right.second - Right.first) {
                System.out.println("No");
                continue;
            }
            int ok = 1;
            Pair<ModInt, ModInt> aa = new Pair<>(hoge[Left.second].first.subtract(hoge[Left.first].first),
                                                  hoge[Left.second].second.subtract(hoge[Left.first].second));
            Pair<ModInt, ModInt> bb;
            if (a % 2 == b % 2) {
                bb = new Pair<>(hoge[Right.second].first.subtract(hoge[Right.first].first),
                                hoge[Right.second].second.subtract(hoge[Right.first].second));
            } else {
                bb = new Pair<>(rev[Right.second].first.subtract(rev[Right.first].first),
                                rev[Right.second].second.subtract(rev[Right.first].second));
            }
            if (Left.first != 0) {
                aa.first = aa.first.divide(pows(new ModInt(2), Left.first));
                aa.second = aa.second.divide(pows(new ModInt(2), Left.first));
            }
            if (Right.first != 0) {
                bb.first = bb.first.divide(pows(new ModInt(2), Right.first));
                bb.second = bb.second.divide(pows(new ModInt(2), Right.first));
            }
            if (aa.first.value != bb.first.value || aa.second.value != bb.second.value) {
                ok = 0;
            }
            System.out.println(ok == 1 ? "Yes" : "No");
        }
        scanner.close();
    }

    static int lowerBound(List<Long> list, long value) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static ModInt pows(ModInt val, long b) {
        ModInt ans = val;
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

    public static void main(String[] args) {
        init();
        solve();
    }
}
