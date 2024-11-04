import java.util.*;

public class 33fb2fed98a8abf073820fec4490a399xcodeeval_processed_4000.json {
    public static String id0(long n) {
        return Long.toString(n);
    }

    public static String sum(String a, String b) {
        int k;
        if (a.length() > b.length()) {
            k = a.length() - b.length();
            for (int i = 0; i < k; i++) {
                b = "0" + b;
            }
        } else {
            k = b.length() - a.length();
            for (int i = 0; i < k; i++) {
                a = "0" + a;
            }
        }
        List<Long> vect = new ArrayList<>();
        int qw = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            vect.add((long) (a.charAt(i) - '0') + (b.charAt(i) - '0'));
        }
        for (int i = 0; i < vect.size(); i++) {
            if (vect.get(i) > 9) {
                if (i == vect.size() - 1) {
                    vect.add(vect.get(i) / 10);
                    vect.set(i, vect.get(i) % 10);
                    break;
                }
                vect.set(i + 1, vect.get(i + 1) + (vect.get(i) / 10));
                vect.set(i, vect.get(i) % 10);
            }
        }
        StringBuilder res = new StringBuilder();
        for (Long value : vect) {
            res.append(value);
        }
        return res.reverse().toString();
    }

    public static String multiply(String a, String b) {
        List<List<Integer>> vect = new ArrayList<>();
        for (int i = 0; i < a.length(); i++) {
            vect.add(new ArrayList<>());
        }
        for (int i = a.length() - 1; i >= 0; i--) {
            for (int u = 0; u < a.length() - i - 1; u++) {
                vect.get(a.length() - i - 1).add(0);
            }
            for (int j = b.length() - 1; j >= 0; j--) {
                vect.get(a.length() - i - 1).add((a.charAt(i) - '0') * (b.charAt(j) - '0'));
            }
            for (int u = 0; u < vect.get(a.length() - i - 1).size(); u++) {
                if (vect.get(a.length() - i - 1).get(u) > 9) {
                    if (u == vect.get(a.length() - i - 1).size() - 1) {
                        vect.get(a.length() - i - 1).add(vect.get(a.length() - i - 1).get(u) / 10);
                        vect.get(a.length() - i - 1).set(u, vect.get(a.length() - i - 1).get(u) % 10);
                        break;
                    }
                    vect.get(a.length() - i - 1).set(u + 1, vect.get(a.length() - i - 1).get(u + 1) + (vect.get(a.length() - i - 1).get(u) / 10));
                    vect.get(a.length() - i - 1).set(u, vect.get(a.length() - i - 1).get(u) % 10);
                }
            }
        }
        String[] res = new String[7000];
        for (int i = 0; i < a.length(); i++) {
            res[i] = "";
            for (int p = vect.get(i).size() - 1; p >= 0; p--) {
                res[i] += (char) (vect.get(i).get(p) + '0');
            }
        }
        String ans = "0";
        for (String s : res) {
            ans = sum(ans, s);
        }
        return ans;
    }

    public static long rec1(long n) {
        long ans = 0;
        if (n == 1) {
            for (int i = 0; i < 10; i++) {
                if (i != 0) ans++;
            }
        } else if (n == 2) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    if (i != 0 && i != k) ans++;
                }
            }
        } else if (n == 3) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        if (i != 0 && i != k && i != c && k != c) ans++;
                    }
                }
            }
        } else if (n == 4) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            if (i != 0 && i != k && i != c && i != d && k != c && k != d && c != d) ans++;
                        }
                    }
                }
            }
        } else if (n == 5) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            for (int e = 0; e < 10; e++) {
                                if (i != 0 && i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) ans++;
                            }
                        }
                    }
                }
            }
        } else if (n == 6) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            for (int e = 0; e < 10; e++) {
                                for (int f = 0; f < 10; f++) {
                                    if (i != 0 && i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) ans++;
                                }
                            }
                        }
                    }
                }
            }
        } else if (n == 7) {
            for (int i = 1; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            for (int e = 0; e < 10; e++) {
                                for (int f = 0; f < 10; f++) {
                                    for (int g = 0; g < 10; g++) {
                                        if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (n == 8) {
            ans = 1632960;
        } else if (n == 9) {
            ans = 3265920;
        } else if (n == 10) {
            ans = 3265920;
        }
        return ans;
    }

    public static long rec(long n) {
        long ans = 0;
        if (n == 1) {
            for (int i = 0; i < 10; i++) {
                ans++;
            }
        } else if (n == 2) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    if (i != k) ans++;
                }
            }
        } else if (n == 3) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        if (i != k && i != c && k != c) ans++;
                    }
                }
            }
        } else if (n == 4) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            if (i != k && i != c && i != d && k != c && k != d && c != d) ans++;
                        }
                    }
                }
            }
        } else if (n == 5) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            for (int e = 0; e < 10; e++) {
                                if (i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) ans++;
                            }
                        }
                    }
                }
            }
        } else if (n == 6) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            for (int e = 0; e < 10; e++) {
                                for (int f = 0; f < 10; f++) {
                                    if (i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) ans++;
                                }
                            }
                        }
                    }
                }
            }
        } else if (n == 7) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            for (int e = 0; e < 10; e++) {
                                for (int f = 0; f < 10; f++) {
                                    for (int g = 0; g < 10; g++) {
                                        if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (n == 8) {
            ans = 1814400;
        } else if (n == 9) {
            ans = 3628800;
        } else if (n == 10) {
            ans = 3628800;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String x = scanner.next();
            String ans = "1";
            int[] vis = new int[101];
            Arrays.fill(vis, 0);

            long CHn = 0;
            long F = 0;
            for (int i = 0; i < x.length(); i++) {
                if ((x.charAt(i) >= 'A' && x.charAt(i) <= 'J') && i != 0 && vis[x.charAt(i) - 'A'] == 0) {
                    CHn++;
                    vis[x.charAt(i) - 'A'] = 1;
                } else if ((x.charAt(i) >= 'A' && x.charAt(i) <= 'J') && i == 0 && vis[x.charAt(i) - 'A'] == 0) {
                    F++;
                    vis[x.charAt(i) - 'A'] = 1;
                }
            }
            long Zeros = 0;
            if (x.charAt(0) == '?') ans = "9";
            for (int i = 1; i < x.length(); i++) {
                if (x.charAt(i) == '?') {
                    Zeros++;
                }
            }
            if (F != 0) {
                ans = multiply(id0(rec1(F + CHn)), ans);
            } else if (CHn > 0) {
                ans = multiply(id0(rec(CHn)), ans);
            }

            System.out.print(ans);
            for (int i = 0; i < Zeros; i++) System.out.print('0');
            System.out.println();
        }
        scanner.close();
    }
}
