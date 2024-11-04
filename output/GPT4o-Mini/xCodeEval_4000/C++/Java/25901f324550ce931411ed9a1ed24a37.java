import java.util.*;

class Sparsetable_min {
    private int beki = 19;
    private int cor = (1 << beki);
    private int[][] vec;
    private int[] lo;

    public Sparsetable_min() {
        shoki1();
    }

    private void shoki1() {
        vec = new int[beki + 1][cor];
        lo = new int[cor + 1];
        lo[0] = -1;
        for (int i = 1; i <= cor; i++) {
            lo[i] = lo[i >> 1] + 1;
        }
    }

    public void shoki2() {
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

    public int rangemin(int i, int j) {
        int haba = lo[j - i];
        return Math.min(vec[haba][i], vec[haba][j - (1 << haba)]);
    }
}

class SAIS {
    private String STR;
    private List<Integer> S = new ArrayList<>();
    private List<Integer> SL = new ArrayList<>();
    private List<int[]> haba = new ArrayList<>();
    private List<Integer> SA = new ArrayList<>();
    private List<Integer> rank = new ArrayList<>();
    private List<Integer> LCP = new ArrayList<>();
    private int mojisu;
    private int len;

    public void make_suffix_array_string(String str) {
        STR = str;
        Set<Character> setc = new HashSet<>();
        Map<Character, Integer> mapc = new HashMap<>();
        for (char c : str.toCharArray()) setc.add(c);
        int cnt = 1;
        for (char c : setc) {
            mapc.put(c, cnt++);
        }
        for (char c : str.toCharArray()) S.add(mapc.get(c));
        mojisu = cnt;
        S.add(0);
        make_suffix_array_naibu();
    }

    public void make_suffix_array_saiki(List<Integer> ve, int max_valu) {
        S = ve;
        S.add(0);
        mojisu = max_valu + 1;
        make_suffix_array_naibu();
    }

    private void make_suffix_array_naibu() {
        int cnt = mojisu;
        len = S.size();
        List<Integer> kosuu = new ArrayList<>(Collections.nCopies(cnt, 0));
        for (int c : S) kosuu.set(c, kosuu.get(c) + 1);

        haba.add(new int[]{0, 0});
        for (int i = 1; i < cnt; i++) {
            haba.add(new int[]{haba.get(haba.size() - 1)[1] + 1, haba.get(haba.size() - 1)[1] + kosuu.get(i)});
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

        int LMS_num = 0;
        List<Integer> LMS = new ArrayList<>();
        List<Integer> LMS_id = new ArrayList<>(Collections.nCopies(len, 0));
        int rt = 0;
        for (int i = 1; i < len; i++) {
            if (SL.get(i - 1) == 0 && SL.get(i) == 1) {
                LMS.add(i);
                LMS_id.set(i, rt);
                LMS_num++;
                rt++;
            }
        }
        for (int i = 0; i < LMS_num - 1; i++) {
            SL.set(LMS.get(i), -(LMS.get(i + 1) - LMS.get(i) + 1));
        }
        SL.set(len - 1, -1);

        for (int i = 0; i < len; i++) SA.add(-1);
        List<Integer> pos = new ArrayList<>(Collections.nCopies(cnt, 0));
        for (int c = 0; c < len; c++) {
            if (SL.get(c) < 0) {
                SA.set(haba.get(S.get(c))[1] - pos.get(S.get(c)), c);
                pos.set(S.get(c), pos.get(S.get(c)) + 1);
            }
        }

        induced_sort(SA, len, cnt);

        List<int[]> lms_sub_order = new ArrayList<>();
        int mae_ind;
        for (int i = 0; i < len; i++) {
            if (SL.get(SA.get(i)) < 0) {
                if (i == 0) {
                    lms_sub_order.add(new int[]{SA.get(i), 1});
                } else if (lms_sub_order.get(lms_sub_order.size() - 1)[1] == 1) {
                    lms_sub_order.add(new int[]{SA.get(i), 2});
                } else if (SL.get(SA.get(mae_ind)) != SL.get(SA.get(i))) {
                    lms_sub_order.add(new int[]{SA.get(i), lms_sub_order.get(lms_sub_order.size() - 1)[1] + 1});
                } else {
                    int lmslen = -SL.get(SA.get(mae_ind));
                    boolean bo = true;
                    for (int j = 0; j < lmslen; j++) {
                        if (S.get(SA.get(mae_ind) + j) != S.get(SA.get(i) + j)) {
                            bo = false;
                            break;
                        }
                    }
                    if (bo) lms_sub_order.add(new int[]{SA.get(i), lms_sub_order.get(lms_sub_order.size() - 1)[1]});
                    else lms_sub_order.add(new int[]{SA.get(i), lms_sub_order.get(lms_sub_order.size() - 1)[1] + 1});
                }
                mae_ind = i;
            }
        }

        for (int i = 0; i < cnt; i++) pos.set(i, 0);
        for (int i = 0; i < len; i++) SA.set(i, -1);

        if (LMS_num == lms_sub_order.get(lms_sub_order.size() - 1)[1]) {
            for (int i = LMS_num - 1; i >= 0; i--) {
                int c = LMS.get(lms_sub_order.get(i)[0]);
                SA.set(haba.get(S.get(c))[1] - pos.get(S.get(c)), c);
                pos.set(S.get(c), pos.get(S.get(c)) + 1);
            }
        } else {
            List<Integer> rec = new ArrayList<>(Collections.nCopies(LMS.size(), 0));
            for (int i = 0; i < LMS_num; i++) {
                rec.set(LMS_id.get(lms_sub_order.get(i)[0]), lms_sub_order.get(i)[1]);
            }
            SAIS ss_naibu = new SAIS();
            ss_naibu.make_suffix_array_saiki(rec, lms_sub_order.get(lms_sub_order.size() - 1)[1]);

            for (int i = LMS_num; i > 0; i--) {
                int c = LMS.get(ss_naibu.SA.get(i));
                SA.set(haba.get(S.get(c))[1] - pos.get(S.get(c)), c);
                pos.set(S.get(c), pos.get(S.get(c)) + 1);
            }
        }

        induced_sort(SA, len, cnt);
        rank = new ArrayList<>(Collections.nCopies(len, 0));
        for (int i = 0; i < len; i++) rank.set(SA.get(i), i);
    }

    private void induced_sort(List<Integer> ve, int len, int cnt) {
        List<Integer> ue = new ArrayList<>(Collections.nCopies(cnt, 0));
        for (int i = 0; i < len; i++) {
            if (ve.get(i) == -1) continue;
            if (ve.get(i) == 0) continue;
            if (SL.get(ve.get(i) - 1) == 0) {
                ve.set(haba.get(S.get(ve.get(i) - 1))[0] + ue.get(S.get(ve.get(i) - 1))), ve.get(i) - 1);
                ue.set(S.get(ve.get(i) - 1), ue.get(S.get(ve.get(i) - 1)) + 1);
            }
            if (SL.get(ve.get(i)) < 0 && i > 0) ve.set(i, -1);
        }
        for (int i = 0; i < cnt; i++) ue.set(i, 0);

        for (int i = len - 1; i >= 0; i--) {
            if (ve.get(i) == -1) continue;
            if (ve.get(i) == 0) continue;
            if (SL.get(ve.get(i) - 1) != 0) {
                ve.set(haba.get(S.get(ve.get(i) - 1))[1] - ue.get(S.get(ve.get(i) - 1))), ve.get(i) - 1);
                ue.set(S.get(ve.get(i) - 1), ue.get(S.get(ve.get(i) - 1)) + 1);
            }
        }
        for (int v : ve) {
            if (v == -1) throw new AssertionError();
        }
    }

    public void make_lcp() {
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

    public int lower_bound(String p) {
        int m = p.length();
        int ue = len, si = 0, me;
        while (ue - si > 1) {
            me = (ue + si) / 2;
            if (STR.compareTo(SA.get(me), m, p, 0, p.length()) < 0) si = me;
            else ue = me;
        }
        return ue;
    }

    public boolean exist(String p) {
        int l = p.length();
        int id = lower_bound(p);
        return 0 == STR.compareTo(SA.get(id), l, p, 0, p.length());
    }

    public int[] range(String p) {
        return new int[]{lower_bound(p), lower_bound(p + "{")};
    }
}

public class 25901f324550ce931411ed9a1ed24a37_nc {
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
