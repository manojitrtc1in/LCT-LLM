import java.util.*;

class pa3 implements Comparable<pa3> {
    int x, y, z;

    pa3(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public int compareTo(pa3 p) {
        if (x != p.x) return Integer.compare(x, p.x);
        if (y != p.y) return Integer.compare(y, p.y);
        return Integer.compare(z, p.z);
    }

    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof pa3)) return false;
        pa3 p = (pa3) obj;
        return x == p.x && y == p.y && z == p.z;
    }

    public int hashCode() {
        return Objects.hash(x, y, z);
    }
}

class pa4 implements Comparable<pa4> {
    int x, y, z, w;

    pa4(int x, int y, int z, int w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    public int compareTo(pa4 p) {
        if (x != p.x) return Integer.compare(x, p.x);
        if (y != p.y) return Integer.compare(y, p.y);
        if (z != p.z) return Integer.compare(z, p.z);
        return Integer.compare(w, p.w);
    }

    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof pa4)) return false;
        pa4 p = (pa4) obj;
        return x == p.x && y == p.y && z == p.z && w == p.w;
    }

    public int hashCode() {
        return Objects.hash(x, y, z, w);
    }
}

class pa2 implements Comparable<pa2> {
    int x, y;

    pa2(int x, int y) {
        this.x = x;
        this.y = y;
    }

    pa2 add(pa2 p) {
        return new pa2(x + p.x, y + p.y);
    }

    pa2 subtract(pa2 p) {
        return new pa2(x - p.x, y - p.y);
    }

    public int compareTo(pa2 p) {
        return (y != p.y) ? Integer.compare(y, p.y) : Integer.compare(x, p.x);
    }

    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof pa2)) return false;
        pa2 p = (pa2) obj;
        return x == p.x && y == p.y;
    }

    public int hashCode() {
        return Objects.hash(x, y);
    }
}

class Sparsetable_min {
    int beki = 19;
    int cor = (1 << beki);
    int[][] vec;
    int[] lo;

    void shoki1() {
        vec = new int[beki + 1][cor];
        lo = new int[cor + 1];
        lo[0] = -1;
        for (int i = 1; i <= cor; i++) lo[i] = lo[i >> 1] + 1;
    }

    void shoki2() {
        for (int i = 1; i <= beki; i++) {
            for (int j = 0; j < cor; j++) {
                if ((j + (1 << (i - 1))) < cor) {
                    vec[i][j] = Math.min(vec[i - 1][j], vec[i - 1][j + (1 << (i - 1))]);
                } else {
                    vec[i][j] = vec[i - 1][j];
                }
            }
        }
    }

    int rangemin(int i, int j) {
        int haba = lo[j - i];
        return Math.min(vec[haba][i], vec[haba][j - (1 << haba)]);
    }
}

class SAIS {
    String STR;
    List<Integer> S = new ArrayList<>();
    List<Integer> SL = new ArrayList<>();
    List<pa> haba = new ArrayList<>();
    List<Integer> SA = new ArrayList<>();
    List<Integer> rank = new ArrayList<>();
    List<Integer> LCP = new ArrayList<>();
    int id3;
    int len;

    void make_suffix_array_string(String str) {
        STR = str;
        Set<Character> setc = new HashSet<>();
        Map<Character, Integer> mapc = new HashMap<>();
        for (char c : str.toCharArray()) setc.add(c);
        int cnt = 1;
        for (char c : setc) {
            mapc.put(c, cnt++);
        }
        for (char c : str.toCharArray()) S.add(mapc.get(c));
        id3 = cnt;
        S.add(0);
        make_suffix_array_naibu();
    }

    void make_suffix_array_naibu() {
        int cnt = id3;
        len = S.size();
        List<Integer> kosuu = new ArrayList<>(Collections.nCopies(cnt, 0));
        for (int c : S) kosuu.set(c, kosuu.get(c) + 1);

        haba.add(new pa(0, 0));
        for (int i = 1; i < cnt; i++) {
            haba.add(new pa(haba.get(haba.size() - 1).second + 1, haba.get(haba.size() - 1).second + kosuu.get(i)));
        }

        SL = new ArrayList<>(Collections.nCopies(len, 0));
        for (int i = len - 1; i >= 0; i--) {
            if (i == len - 1) {
                SL.set(i, 1);
            } else {
                if (S.get(i) < S.get(i + 1)) SL.set(i, 1);
                else if (S.get(i) > S.get(i + 1)) SL.set(i, 0);
                else SL.set(i, SL.get(i + 1));
            }
        }

        int id7 = 0;
        List<Integer> LMS = new ArrayList<>();
        List<Integer> id6 = new ArrayList<>(Collections.nCopies(len, 0));
        int rt = 0;
        for (int i = 1; i < len; i++) {
            if (SL.get(i - 1) == 0 && SL.get(i) == 1) {
                LMS.add(i);
                id6.set(i, rt);
                id7++;
                rt++;
            }
        }
        for (int i = 0; i < id7 - 1; i++) {
            SL.set(LMS.get(i), -(LMS.get(i + 1) - LMS.get(i) + 1));
        }
        SL.set(len - 1, -1);

        for (int i = 0; i < len; i++) SA.add(-1);
        List<Integer> pos = new ArrayList<>(Collections.nCopies(cnt, 0));
        for (int c = 0; c < len; c++) {
            if (SL.get(c) < 0) {
                SA.set(haba.get(S.get(c)).second - pos.get(S.get(c)), c);
                pos.set(S.get(c), pos.get(S.get(c)) + 1);
            }
        }

        induced_sort(SA, len, cnt);

        List<pa> id1 = new ArrayList<>();
        int id2 = 0;
        for (int i = 0; i < len; i++) {
            if (SL.get(SA.get(i)) < 0) {
                if (i == 0) {
                    id1.add(new pa(SA.get(i), 1));
                } else if (id1.get(id1.size() - 1).second == 1) {
                    id1.add(new pa(SA.get(i), 2));
                } else if (SL.get(SA.get(id2)) != SL.get(SA.get(i))) {
                    id1.add(new pa(SA.get(i), id1.get(id1.size() - 1).second + 1));
                } else {
                    int id5 = -SL.get(SA.get(id2));
                    boolean bo = true;
                    for (int j = 0; j < id5; j++) {
                        if (S.get(SA.get(id2) + j) != S.get(SA.get(i) + j)) {
                            bo = false;
                            break;
                        }
                    }
                    if (bo) id1.add(new pa(SA.get(i), id1.get(id1.size() - 1).second));
                    else id1.add(new pa(SA.get(i), id1.get(id1.size() - 1).second + 1));
                }
                id2 = i;
            }
        }

        for (int i = 0; i < cnt; i++) pos.set(i, 0);
        for (int i = 0; i < len; i++) SA.set(i, -1);

        if (id7 == id1.get(id1.size() - 1).second) {
            for (int i = id7 - 1; i >= 0; i--) {
                int c = id1.get(i).first;
                SA.set(haba.get(S.get(c)).second - pos.get(S.get(c)), c);
                pos.set(S.get(c), pos.get(S.get(c)) + 1);
            }
        } else {
            List<Integer> rec = new ArrayList<>(Collections.nCopies(LMS.size(), 0));
            for (int i = 0; i < id7; i++) {
                rec.set(id6.get(id1.get(i).first), id1.get(i).second);
            }
            SAIS id4 = new SAIS();
            id4.make_suffix_array_saiki(rec, id1.get(id1.size() - 1).second);

            for (int i = id7; i > 0; i--) {
                int c = LMS.get(id4.SA.get(i));
                SA.set(haba.get(S.get(c)).second - pos.get(S.get(c)), c);
                pos.set(S.get(c), pos.get(S.get(c)) + 1);
            }
        }

        induced_sort(SA, len, cnt);
        rank = new ArrayList<>(Collections.nCopies(len, 0));
        for (int i = 0; i < len; i++) rank.set(SA.get(i), i);
    }

    void induced_sort(List<Integer> ve, int len, int cnt) {
        List<Integer> ue = new ArrayList<>(Collections.nCopies(cnt, 0));
        for (int i = 0; i < len; i++) {
            if (ve.get(i) == -1) continue;
            if (ve.get(i) == 0) continue;
            if (SL.get(ve.get(i) - 1) == 0) {
                ve.set(haba.get(S.get(ve.get(i) - 1)).first + ue.get(S.get(ve.get(i) - 1)), ve.get(i) - 1);
                ue.set(S.get(ve.get(i) - 1), ue.get(S.get(ve.get(i) - 1)) + 1);
            }
            if (SL.get(ve.get(i)) < 0 && i > 0) ve.set(i, -1);
        }
        for (int i = 0; i < cnt; i++) ue.set(i, 0);

        for (int i = len - 1; i >= 0; i--) {
            if (ve.get(i) == -1) continue;
            if (ve.get(i) == 0) continue;
            if (SL.get(ve.get(i) - 1) != 0) {
                ve.set(haba.get(S.get(ve.get(i) - 1)).second - ue.get(S.get(ve.get(i) - 1)), ve.get(i) - 1);
                ue.set(S.get(ve.get(i) - 1), ue.get(S.get(ve.get(i) - 1)) + 1);
            }
        }
        for (int v : ve) if (v == -1) throw new AssertionError();
    }

    void make_lcp() {
        S.clear();
        SL.clear();
        haba.clear();
        LCP = new ArrayList<>(Collections.nCopies(len, 0));
        int h = 0;
        LCP.set(0, 0);
        for (int i = 0; i < len - 1; i++) {
            int j = SA.get(rank.get(i) - 1);
            if (h > 0) h--;
            for (; j + h < len - 1 && i + h < len - 1; h++) {
                if (S.get(j + h) != S.get(i + h)) break;
            }
            LCP.set(rank.get(i) - 1, h);
        }
    }

    int lower_bound(String p) {
        int m = p.length();
        int ue = len, si = 0, me;
        while (ue - si > 1) {
            me = (ue + si) / 2;
            if (STR.substring(SA.get(me), m).compareTo(p) < 0) si = me;
            else ue = me;
        }
        return ue;
    }

    boolean exist(String p) {
        int l = p.length();
        int id = lower_bound(p);
        return 0 == STR.substring(SA.get(id), l).compareTo(p);
    }

    pa range(String p) {
        return new pa(lower_bound(p), lower_bound(p + '{'));
    }
}

public class 25901f324550ce931411ed9a1ed24a37xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        List<Integer> ve = new ArrayList<>(Collections.nCopies(n, 0));
        int cnt = 0;
        StringBuilder t = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                ve.set(i, cnt);
            } else {
                ve.set(i, cnt);
                cnt++;
                if (i % 2 == 1) t.append('b');
                else t.append('a');
            }
        }
        int m = t.length();
        if (m == 0) {
            int e = scanner.nextInt();
            for (int i = 0; i < e; i++) System.out.println("Yes");
            return;
        }
        for (int i = 0; i < m; i++) t.append((char) ('a' ^ 'b' ^ t.charAt(i)));

        ve.add(cnt);
        SAIS ss = new SAIS();
        ss.make_suffix_array_string(t.toString());
        ss.make_lcp();
        Sparsetable_min sm = new Sparsetable_min();
        sm.shoki1();
        for (int i = 0; i < ss.LCP.size(); i++) sm.vec[0][i] = ss.LCP.get(i);

        sm.shoki2();
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int l1 = scanner.nextInt() - 1;
            int l2 = scanner.nextInt() - 1;
            int p = scanner.nextInt();
            int r1 = l1 + p, r2 = l2 + p;
            if (ve.get(r1) - ve.get(l1) != ve.get(r2) - ve.get(l2)) {
                System.out.println("No");
                continue;
            }
            if (l1 % 2 == l2 % 2) {
                if (ve.get(r1) == ve.get(l1) || ve.get(r1) == ve.get(r2)) {
                    System.out.println("Yes");
                    continue;
                }
                int e1 = ss.rank.get(ve.get(l1));
                int e2 = ss.rank.get(ve.get(l2));
                if (e1 > e2) {
                    int temp = e1;
                    e1 = e2;
                    e2 = temp;
                }
                if (sm.rangemin(e1, e2) >= ve.get(r1) - ve.get(l1)) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            } else {
                if (ve.get(r1) == ve.get(l1)) {
                    System.out.println("Yes");
                    continue;
                }
                if (ve.get(r1) == ve.get(r2)) {
                    System.out.println("No");
                    continue;
                }

                int e1 = ss.rank.get(ve.get(l1));
                int e2 = ss.rank.get(ve.get(l2) + m);
                if (e1 > e2) {
                    int temp = e1;
                    e1 = e2;
                    e2 = temp;
                }

                if (sm.rangemin(e1, e2) >= ve.get(r1) - ve.get(l1)) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            }
        }
    }
}
