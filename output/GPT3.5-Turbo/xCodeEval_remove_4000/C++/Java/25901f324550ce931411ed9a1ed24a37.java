import java.util.*;

class pa3 implements Comparable<pa3> {
    public int x;
    public int y;
    public int z;

    public pa3(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public pa3() {
        this.x = 0;
        this.y = 0;
        this.z = 0;
    }

    public boolean lessThan(pa3 p) {
        if (x != p.x) return x < p.x;
        if (y != p.y) return y < p.y;
        return z < p.z;
    }

    public boolean greaterThan(pa3 p) {
        if (x != p.x) return x > p.x;
        if (y != p.y) return y > p.y;
        return z > p.z;
    }

    public boolean equals(pa3 p) {
        return x == p.x && y == p.y && z == p.z;
    }

    public boolean notEquals(pa3 p) {
        return !(x == p.x && y == p.y && z == p.z);
    }

    @Override
    public int compareTo(pa3 p) {
        if (x != p.x) return Integer.compare(x, p.x);
        if (y != p.y) return Integer.compare(y, p.y);
        return Integer.compare(z, p.z);
    }
}

class pa4 implements Comparable<pa4> {
    public int x;
    public int y;
    public int z;
    public int w;

    public pa4(int x, int y, int z, int w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    public pa4() {
        this.x = 0;
        this.y = 0;
        this.z = 0;
        this.w = 0;
    }

    public boolean lessThan(pa4 p) {
        if (x != p.x) return x < p.x;
        if (y != p.y) return y < p.y;
        if (z != p.z) return z < p.z;
        return w < p.w;
    }

    public boolean greaterThan(pa4 p) {
        if (x != p.x) return x > p.x;
        if (y != p.y) return y > p.y;
        if (z != p.z) return z > p.z;
        return w > p.w;
    }

    public boolean equals(pa4 p) {
        return x == p.x && y == p.y && z == p.z && w == p.w;
    }

    @Override
    public int compareTo(pa4 p) {
        if (x != p.x) return Integer.compare(x, p.x);
        if (y != p.y) return Integer.compare(y, p.y);
        if (z != p.z) return Integer.compare(z, p.z);
        return Integer.compare(w, p.w);
    }
}

class pa2 implements Comparable<pa2> {
    public int x;
    public int y;

    public pa2(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public pa2() {
        this.x = 0;
        this.y = 0;
    }

    public pa2 add(pa2 p) {
        return new pa2(x + p.x, y + p.y);
    }

    public pa2 subtract(pa2 p) {
        return new pa2(x - p.x, y - p.y);
    }

    public boolean lessThan(pa2 p) {
        return y != p.y ? y < p.y : x < p.x;
    }

    public boolean greaterThan(pa2 p) {
        return x != p.x ? x < p.x : y < p.y;
    }

    public boolean equals(pa2 p) {
        return Math.abs(x - p.x) == 0 && Math.abs(y - p.y) == 0;
    }

    public boolean notEquals(pa2 p) {
        return !(Math.abs(x - p.x) == 0 && Math.abs(y - p.y) == 0);
    }

    @Override
    public int compareTo(pa2 p) {
        if (y != p.y) return Integer.compare(y, p.y);
        return Integer.compare(x, p.x);
    }
}

class Sparsetable_min {
    private int beki = 19;
    private int cor = (1 << beki);
    private int[][] vec;
    private int[] lo;

    public void shoki1() {
        vec = new int[beki + 1][cor];
        lo = new int[cor + 1];
        lo[0] = -1;
        for (int i = 1; i <= cor; i++) lo[i] = lo[i >> 1] + 1;
    }

    public void shoki2() {
        for (int i = 1; i <= beki; i++) {
            for (int j = 0; j < cor; j++) {
                if ((j + (1 << (i - 1))) < cor) vec[i][j] = Math.min(vec[i - 1][j], vec[i - 1][j + (1 << (i - 1))]);
                else vec[i][j] = vec[i - 1][j];
            }
        }
    }

    public int rangemin(int i, int j) {
        int haba = lo[j - i];
        return Math.min(vec[haba][i], vec[haba][j - (1 << haba)]);
    }
}

class SAIS {
    private String STR;
    private List<Integer> S;
    private List<Integer> SL;
    private List<pa2> haba;
    private List<Integer> SA;
    private List<Integer> rank;
    private List<Integer> LCP;
    private int id3;
    private int len;

    public void make_suffix_array_string(String str) {
        STR = str;
        Set<Character> setc = new HashSet<>();
        Map<Character, Integer> mapc = new HashMap<>();
        for (char c : str.toCharArray()) setc.add(c);
        int cnt = 1;
        for (char c : setc) mapc.put(c, cnt++);
        S = new ArrayList<>();
        for (char c : str.toCharArray()) S.add(mapc.get(c));
        id3 = cnt;
        S.add(0);
        make_suffix_array_naibu();
    }

    public void make_suffix_array_saiki(List<Integer> ve, int id0) {
        S = ve;
        S.add(0);
        id3 = id0 + 1;
        make_suffix_array_naibu();
    }

    private void make_suffix_array_naibu() {
        int cnt = id3;
        len = S.size();
        int[] kosuu = new int[cnt];
        for (int c : S) kosuu[c]++;
        haba = new ArrayList<>();
        haba.add(new pa2(0, 0));
        for (int i = 1; i < cnt; i++) {
            haba.add(new pa2(haba.get(i - 1).y + 1, haba.get(i - 1).y + kosuu[i]));
        }
        SL = new ArrayList<>();
        for (int i = len - 1; i >= 0; i--) {
            if (i == len - 1) SL.add(1);
            else {
                if (S.get(i) < S.get(i + 1)) SL.add(1);
                else if (S.get(i) > S.get(i + 1)) SL.add(0);
                else SL.add(SL.get(i + 1));
            }
        }
        int id7 = 0;
        List<Integer> LMS = new ArrayList<>();
        int[] id6 = new int[len];
        int rt = 0;
        for (int i = 1; i < len; i++) {
            if (SL.get(i - 1) == 0 && SL.get(i) == 1) {
                LMS.add(i);
                id6[i] = rt;
                id7++;
                rt++;
            }
        }
        for (int i = 0; i < id7 - 1; i++) {
            SL.set(LMS.get(i), -(LMS.get(i + 1) - LMS.get(i) + 1));
        }
        SL.set(len - 1, -1);
        SA = new ArrayList<>();
        for (int i = 0; i < len; i++) SA.add(-1);
        int[] pos = new int[cnt];
        for (int c = 0; c < len; c++) {
            if (SL.get(c) < 0) {
                SA.set(haba.get(S.get(c)).y - pos[S.get(c)], c);
                pos[S.get(c)]++;
            }
        }
        induced_sort(SA, len, cnt);
        induced_sort(SA, len, cnt);
        List<pa2> id1 = new ArrayList<>();
        int id2 = 0;
        for (int i = 0; i < len; i++) {
            if (SL.get(SA.get(i)) < 0) {
                if (i == 0) {
                    id1.add(new pa2(SA.get(i), 1));
                } else if (id1.get(id1.size() - 1).y == 1) {
                    id1.add(new pa2(SA.get(i), 2));
                } else if (!SL.get(SA.get(id2)).equals(SL.get(SA.get(i)))) {
                    id1.add(new pa2(SA.get(i), id1.get(id1.size() - 1).y + 1));
                } else {
                    int id5 = -SL.get(SA.get(id2));
                    boolean bo = true;
                    for (int j = 0; j < id5; j++) {
                        if (!S.get(SA.get(id2) + j).equals(S.get(SA.get(i) + j))) {
                            bo = false;
                            break;
                        }
                    }
                    if (bo) id1.add(new pa2(SA.get(i), id1.get(id1.size() - 1).y));
                    else id1.add(new pa2(SA.get(i), id1.get(id1.size() - 1).y + 1));
                }
                id2 = i;
            }
        }
        for (int i = 0; i < cnt; i++) pos[i] = 0;
        for (int i = 0; i < len; i++) SA.set(i, -1);
        if (id7 == id1.get(id1.size() - 1).y) {
            for (int i = id7 - 1; i >= 0; i--) {
                int c = id1.get(i).x;
                SA.set(haba.get(S.get(c)).y - pos[S.get(c)], c);
                pos[S.get(c)]++;
            }
        } else {
            List<Integer> rec = new ArrayList<>();
            for (int i = 0; i < id7; i++) {
                rec.add(id6[id1.get(i).x]);
            }
            SAIS id4 = new SAIS();
            id4.make_suffix_array_saiki(rec, id1.get(id1.size() - 1).y);
            for (int i = id7; i > 0; i--) {
                int c = LMS.get(id4.SA.get(i));
                SA.set(haba.get(S.get(c)).y - pos[S.get(c)], c);
                pos[S.get(c)]++;
            }
        }
        induced_sort(SA, len, cnt);
        rank = new ArrayList<>();
        for (int i = 0; i < len; i++) rank.add(0);
        for (int i = 0; i < len; i++) rank.set(SA.get(i), i);
    }

    private void induced_sort(List<Integer> ve, int len, int cnt) {
        int[] ue = new int[cnt];
        for (int i = 0; i < len; i++) {
            if (ve.get(i) == -1) continue;
            if (ve.get(i) == 0) continue;
            if (SL.get(ve.get(i) - 1) == 0) {
                ve.set(haba.get(S.get(ve.get(i) - 1)).x + ue[S.get(ve.get(i) - 1)], ve.get(i) - 1);
                ue[S.get(ve.get(i) - 1)]++;
            }
            if (SL.get(ve.get(i)) < 0 && i > 0) ve.set(i, -1);
        }
        for (int i = 0; i < cnt; i++) ue[i] = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (ve.get(i) == -1) continue;
            if (ve.get(i) == 0) continue;
            if (SL.get(ve.get(i) - 1) != 0) {
                ve.set(haba.get(S.get(ve.get(i) - 1)).y - ue[S.get(ve.get(i) - 1)], ve.get(i) - 1);
                ue[S.get(ve.get(i) - 1)]++;
            }
        }
        for (int v : ve) if (v == -1) throw new AssertionError();
    }

    public void make_lcp() {
        LCP = new ArrayList<>();
        int h = 0;
        LCP.add(0);
        for (int i = 0; i < len - 1; i++) {
            int j = SA.get(rank.get(i) - 1);
            if (h > 0) h--;
            for (; j + h < len - 1 && i + h < len - 1; h++) {
                if (!S.get(j + h).equals(S.get(i + h))) break;
            }
            LCP.add(h);
        }
    }

    public int lower_bound(String p) {
        int m = p.length();
        int ue = len, si = 0, me;
        while (ue - si > 1) {
            me = (ue + si) / 2;
            if (STR.substring(SA.get(me)).compareTo(p) < 0) si = me;
            else ue = me;
        }
        return ue;
    }

    public boolean exist(String p) {
        int l = p.length();
        int id = lower_bound(p);
        return STR.substring(SA.get(id)).startsWith(p);
    }

    public pa2 range(String p) {
        return new pa2(lower_bound(p), lower_bound(p + "{"));
    }
}

public class 25901f324550ce931411ed9a1ed24a37xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        int[] ve = new int[n];
        int cnt = 0;
        StringBuilder t = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                ve[i] = cnt;
            } else {
                ve[i] = cnt;
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
        ve = Arrays.copyOf(ve, n + cnt);
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
            int r1 = l1 + p;
            int r2 = l2 + p;
            if (ve[r1] - ve[l1] != ve[r2] - ve[l2]) {
                System.out.println("No");
                continue;
            }
            if (l1 % 2 == l2 % 2) {
                if (ve[r1] == ve[l1] || ve[r1] == ve[r2]) {
                    System.out.println("Yes");
                    continue;
                }
                int e1 = ss.rank.get(ve[l1]);
                int e2 = ss.rank.get(ve[l2]);
                if (e1 > e2) {
                    int tmp = e1;
                    e1 = e2;
                    e2 = tmp;
                }
                if (sm.rangemin(e1, e2) >= ve[r1] - ve[l1]) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            } else {
                if (ve[r1] == ve[l1]) {
                    System.out.println("Yes");
                    continue;
                }
                if (ve[r1] == ve[r2]) {
                    System.out.println("No");
                    continue;
                }
                int e1 = ss.rank.get(ve[l1]);
                int e2 = ss.rank.get(ve[l2] + m);
                if (e1 > e2) {
                    int tmp = e1;
                    e1 = e2;
                    e2 = tmp;
                }
                if (sm.rangemin(e1, e2) >= ve[r1] - ve[l1]) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            }
        }
    }
}
