import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static String intToString(long n) {
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
        int[] vect = new int[a.length()];
        for (int i = a.length() - 1; i >= 0; i--) {
            vect[i] = (a.charAt(i) - '0') + (b.charAt(i) - '0');
        }
        for (int i = 0; i < vect.length; i++) {
            if (vect[i] > 9) {
                if (i == vect.length - 1) {
                    int carry = vect[i] / 10;
                    vect[i] %= 10;
                    String carryStr = Integer.toString(carry);
                    b = carryStr + b;
                    break;
                }
                int carry = vect[i] / 10;
                vect[i + 1] += carry;
                vect[i] %= 10;
            }
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < vect.length; i++) {
            res.append((char) (vect[i] + '0'));
        }
        return res.reverse().toString();
    }

    public static String multiply(String a, String b) {
        int[][] vect = new int[7000][];
        for (int i = a.length() - 1; i >= 0; i--) {
            vect[a.length() - i - 1] = new int[a.length() - i - 1];
            for (int u = 0; u < a.length() - i - 1; u++) {
                vect[a.length() - i - 1][u] = 0;
            }
            for (int j = b.length() - 1; j >= 0; j--) {
                vect[a.length() - i - 1][j + a.length() - i - 1] = (a.charAt(i) - '0') * (b.charAt(j) - '0');
            }
            for (int u = 0; u < vect[a.length() - i - 1].length; u++) {
                if (vect[a.length() - i - 1][u] > 9) {
                    if (u == vect[a.length() - i - 1].length - 1) {
                        int carry = vect[a.length() - i - 1][u] / 10;
                        vect[a.length() - i - 1][u] %= 10;
                        String carryStr = Integer.toString(carry);
                        b = carryStr + b;
                        break;
                    }
                    int carry = vect[a.length() - i - 1][u] / 10;
                    vect[a.length() - i - 1][u + 1] += carry;
                    vect[a.length() - i - 1][u] %= 10;
                }
            }
        }
        String[] res = new String[7000];
        for (int i = 0; i < a.length(); i++) {
            StringBuilder sb = new StringBuilder();
            for (int p = vect[i].length - 1; p >= 0; p--) {
                sb.append((char) (vect[i][p] + '0'));
            }
            res[i] = sb.toString();
        }
        String ans = "0";
        for (int i = 0; i < a.length(); i++) {
            ans = sum(ans, res[i]);
        }
        return ans;
    }

    public static long rec1(long n) {
        long ans = 0;
        if (n == 1) {
            for (int i = 0; i < 10; i++) {
                if (i != 0) {
                    ans++;
                }
            }
        } else if (n == 2) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    if (i != 0 && i != k) {
                        ans++;
                    }
                }
            }
        } else if (n == 3) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        if (i != 0 && i != k && i != c && k != c) {
                            ans++;
                        }
                    }
                }
            }
        } else if (n == 4) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            if (i != 0 && i != k && i != c && i != d && k != c && k != d && c != d) {
                                ans++;
                            }
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
                                if (i != 0 && i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) {
                                    ans++;
                                }
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
                                    if (i != 0 && i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) {
                                        ans++;
                                    }
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
                                        if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) {
                                            ans++;
                                        }
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
                    if (i != k) {
                        ans++;
                    }
                }
            }
        } else if (n == 3) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        if (i != k && i != c && k != c) {
                            ans++;
                        }
                    }
                }
            }
        } else if (n == 4) {
            for (int i = 0; i < 10; i++) {
                for (int k = 0; k < 10; k++) {
                    for (int c = 0; c < 10; c++) {
                        for (int d = 0; d < 10; d++) {
                            if (i != k && i != c && i != d && k != c && k != d && c != d) {
                                ans++;
                            }
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
                                if (i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) {
                                    ans++;
                                }
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
                                    if (i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) {
                                        ans++;
                                    }
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
                                        if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) {
                                            ans++;
                                        }
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
            for (int i = 0; i < 101; i++) {
                vis[i] = 0;
            }

            long CHn = 0;
            long F = 0;
            for (int i = 0; i < x.length(); i++) {
                if (Character.isLetter(x.charAt(i)) && i != 0 && vis[x.charAt(i) - 'A'] == 0) {
                    CHn++;
                    vis[x.charAt(i) - 'A'] = 1;
                } else if (Character.isLetter(x.charAt(i)) && i == 0 && vis[x.charAt(i) - 'A'] == 0) {
                    F++;
                    vis[x.charAt(i) - 'A'] = 1;
                }
            }
            long Zeros = 0;
            if (x.charAt(0) == '?') {
                ans = "9";
            }
            for (int i = 1; i < x.length(); i++) {
                if (x.charAt(i) == '?') {
                    Zeros++;
                }
            }
            if (F != 0) {
                ans = multiply(intToString(rec1(F + CHn)), ans);
            } else if (CHn > 0) {
                ans = multiply(intToString(rec(CHn)), ans);
            }

            System.out.print(ans);
            for (int i = 0; i < Zeros; i++) {
                System.out.print("0");
            }
            System.out.println();
        }
    }
}
