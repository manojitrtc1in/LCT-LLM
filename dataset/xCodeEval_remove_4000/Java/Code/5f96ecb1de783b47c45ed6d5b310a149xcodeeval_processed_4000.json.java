import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        id0 solver = new id0();
        solver.solve(1, in, out);
        out.close();
    }

    static class id0 {
        public void solve(int testNumber, Scanner sc, PrintWriter pw) {
            int t = 1;
            t = sc.nextInt();
            while (t-- > 0) {
                int n = sc.nextInt();
                int m = sc.nextInt();
                int[][] arr = new int[n][m];
                for (int i = 0; i < n; i++) {
                    char[] tmp = sc.nextLine().toCharArray();
                    for (int j = 0; j < m; j++) {
                        arr[i][j] = tmp[j] - '0';
                    }
                }
                

                int cnt = 0;
                StringBuilder ans = new StringBuilder();
                wloop:
                for (int i = 0; i < n - 2; i++) {
                    int c;
                    StringBuilder tmp;


                    loop1:
                    for (int j = 0; j < m - 1; j += 2) {
                        c = 0;
                        tmp = new StringBuilder();
                        if (arr[i][j] == 0 && arr[i][j + 1] == 0) continue loop1;
                        if (arr[i][j] == 1) {
                            c++;
                            arr[i][j] = 1 - arr[i][j];
                            tmp.append((i + 1) + " " + (j + 1) + " ");
                        }
                        if (arr[i][j + 1] == 1) {
                            c++;
                            arr[i][j + 1] = 1 - arr[i][j + 1];

                            tmp.append((i + 1) + " " + (j + 2) + " ");
                        }
                        if (c < 3) {
                            c++;
                            arr[i + 1][j] = 1 - arr[i + 1][j];

                            tmp.append((i + 2) + " " + (j + 1) + " ");
                        }
                        if (c < 3) {
                            c++;
                            arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                            tmp.append((i + 2) + " " + (j + 2) + " ");
                        }
                        cnt++;
                        ans.append(tmp + "\n");
                    }

                    if (m % 2 != 0) {
                        c = 0;
                        tmp = new StringBuilder();
                        int j = m - 2;
                        if (arr[i][j] == 0 && arr[i][j + 1] == 0) continue wloop;
                        if (arr[i][j] == 1) {
                            c++;
                            arr[i][j] = 1 - arr[i][j];
                            tmp.append((i + 1) + " " + (j + 1) + " ");
                        }
                        if (arr[i][j + 1] == 1) {
                            c++;
                            arr[i][j + 1] = 1 - arr[i][j + 1];

                            tmp.append((i + 1) + " " + (j + 2) + " ");
                        }
                        if (c < 3) {
                            c++;
                            arr[i + 1][j] = 1 - arr[i + 1][j];

                            tmp.append((i + 2) + " " + (j + 1) + " ");
                        }
                        if (c < 3) {
                            c++;
                            arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                            tmp.append((i + 2) + " " + (j + 2) + " ");
                        }
                        cnt++;
                        ans.append(tmp + "\n");
                    }


                }

                

                int i = n - 2;
                loop2:
                for (int j = 0; j < m - 2; j++) {
                    if (arr[i][j] == 0 && arr[i + 1][j] == 0) continue loop2;
                    int c = 0;
                    StringBuilder tmp = new StringBuilder();
                    if (arr[i][j] == 1) {
                        c++;
                        arr[i][j] = 1 - arr[i][j];
                        tmp.append((i + 1) + " " + (j + 1) + " ");
                    }
                    if (arr[i + 1][j] == 1) {
                        c++;
                        arr[i + 1][j] = 1 - arr[i + 1][j];

                        tmp.append((i + 2) + " " + (j + 1) + " ");
                    }
                    if (c < 3) {
                        c++;
                        arr[i][j + 1] = 1 - arr[i][j + 1];

                        tmp.append((i + 1) + " " + (j + 2) + " ");
                    }
                    if (c < 3) {
                        c++;
                        arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                        tmp.append((i + 2) + " " + (j + 2) + " ");
                    }
                    cnt++;
                    ans.append(tmp + "\n");
                }
                

                int c = 0;
                i = n - 2;
                int j = m - 2;
                if (arr[i][j] == 1) c++;
                if (arr[i + 1][j] == 1) c++;
                if (arr[i][j + 1] == 1) c++;
                if (arr[i + 1][j + 1] == 1) c++;
                if (c == 1) {
                    i = n - 2;
                    j = m - 2;
                    int id = 0;
                    int jd = 0;
                    if (arr[i][j] == 1) {
                        id = i;
                        jd = j;
                    }
                    if (arr[i + 1][j] == 1) {
                        id = i + 1;
                        jd = j;
                    }
                    if (arr[i][j + 1] == 1) {
                        id = i;
                        jd = j + 1;
                    }
                    if (arr[i + 1][j + 1] == 1) {
                        id = i + 1;
                        jd = j + 1;
                    }
                    int iid = id == n - 1 ? n - 2 : n - 1;
                    int jjd = jd == m - 1 ? m - 2 : m - 1;
                    cnt++;
                    ans.append((id + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jd + 1) + " " + (id + 1) + " " + (jjd + 1) + "\n");
                    arr[id][jd] = 1 - arr[id][jd];
                    arr[iid][jd] = 1 - arr[iid][jd];
                    arr[id][jjd] = 1 - arr[id][jjd];
                    cnt++;
                    ans.append((id + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jjd + 1) + "\n");
                    arr[id][jd] = 1 - arr[id][jd];
                    arr[iid][jd] = 1 - arr[iid][jd];
                    arr[iid][jjd] = 1 - arr[iid][jjd];
                    cnt++;
                    if (arr[i][j] == 1) {
                        ans.append((i + 1) + " " + (j + 1) + " ");
                        arr[i][j] = 1 - arr[i][j];
                    }
                    if (arr[i + 1][j] == 1) {
                        ans.append((i + 2) + " " + (j + 1) + " ");
                        arr[i + 1][j] = 1 - arr[i + 1][j];

                    }
                    if (arr[i][j + 1] == 1) {
                        ans.append((i + 1) + " " + (j + 2) + " ");
                        arr[i][j + 1] = 1 - arr[i][j + 1];

                    }
                    if (arr[i + 1][j + 1] == 1) {
                        ans.append((i + 2) + " " + (j + 2) + " ");
                        arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                    }
                    ans.append("\n");

                } else if (c == 2) {
                    i = n - 2;
                    j = m - 2;
                    cnt++;
                    boolean f1 = false;
                    boolean f2 = false;
                    boolean f3 = false;
                    boolean f4 = false;
                    if (arr[i][j] == 1) {
                        f1 = true;
                        ans.append((i + 1) + " " + (j + 1) + " ");
                        arr[i][j] = 1 - arr[i][j];
                    }
                    if (arr[i + 1][j] == 1) {
                        f2 = true;
                        ans.append((i + 2) + " " + (j + 1) + " ");
                        arr[i + 1][j] = 1 - arr[i + 1][j];

                    }
                    if (arr[i][j + 1] == 1) {
                        f3 = true;
                        ans.append((i + 1) + " " + (j + 2) + " ");
                        arr[i][j + 1] = 1 - arr[i][j + 1];

                    }
                    if (arr[i + 1][j + 1] == 1) {
                        f4 = true;
                        ans.append((i + 2) + " " + (j + 2) + " ");
                        arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                    }
                    if (!f1) {
                        ans.append((i + 1) + " " + (j + 1) + "\n");
                        arr[i][j] = 1 - arr[i][j];
                    } else if (!f2) {
                        ans.append((i + 2) + " " + (j + 1) + "\n");
                        arr[i + 1][j] = 1 - arr[i + 1][j];
                    } else if (!f3) {
                        ans.append((i + 1) + " " + (j + 2) + "\n");
                        arr[i][j + 1] = 1 - arr[i][j + 1];
                    } else if (!f4) {
                        ans.append((i + 2) + " " + (j + 2) + "\n");
                        arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                    }
                    i = n - 2;
                    j = m - 2;
                    int id = 0;
                    int jd = 0;
                    if (arr[i][j] == 1) {
                        id = i;
                        jd = j;
                    }
                    if (arr[i + 1][j] == 1) {
                        id = i + 1;
                        jd = j;
                    }
                    if (arr[i][j + 1] == 1) {
                        id = i;
                        jd = j + 1;
                    }
                    if (arr[i + 1][j + 1] == 1) {
                        id = i + 1;
                        jd = j + 1;
                    }
                    int iid = id == n - 1 ? n - 2 : n - 1;
                    int jjd = jd == m - 1 ? m - 2 : m - 1;
                    cnt++;
                    ans.append((id + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jd + 1) + " " + (id + 1) + " " + (jjd + 1) + "\n");
                    arr[id][jd] = 1 - arr[id][jd];
                    arr[iid][jd] = 1 - arr[iid][jd];
                    arr[id][jjd] = 1 - arr[id][jjd];
                    cnt++;
                    ans.append((id + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jjd + 1) + "\n");
                    arr[id][jd] = 1 - arr[id][jd];
                    arr[iid][jd] = 1 - arr[iid][jd];
                    arr[iid][jjd] = 1 - arr[iid][jjd];
                    cnt++;
                    if (arr[i][j] == 1) {
                        ans.append((i + 1) + " " + (j + 1) + " ");
                        arr[i][j] = 1 - arr[i][j];
                    }
                    if (arr[i + 1][j] == 1) {
                        ans.append((i + 2) + " " + (j + 1) + " ");
                        arr[i + 1][j] = 1 - arr[i + 1][j];

                    }
                    if (arr[i][j + 1] == 1) {
                        ans.append((i + 1) + " " + (j + 2) + " ");
                        arr[i][j + 1] = 1 - arr[i][j + 1];

                    }
                    if (arr[i + 1][j + 1] == 1) {
                        ans.append((i + 2) + " " + (j + 2) + " ");
                        arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                    }
                    ans.append("\n");
                } else if (c == 3) {
                    cnt++;
                    if (arr[i][j] == 1) {
                        ans.append((i + 1) + " " + (j + 1) + " ");
                        arr[i][j] = 1 - arr[i][j];
                    }
                    if (arr[i + 1][j] == 1) {
                        ans.append((i + 2) + " " + (j + 1) + " ");
                        arr[i + 1][j] = 1 - arr[i + 1][j];

                    }
                    if (arr[i][j + 1] == 1) {
                        ans.append((i + 1) + " " + (j + 2) + " ");
                        arr[i][j + 1] = 1 - arr[i][j + 1];

                    }
                    if (arr[i + 1][j + 1] == 1) {
                        ans.append((i + 2) + " " + (j + 2) + " ");
                        arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                    }
                    ans.append("\n");
                } else if (c == 4) {
                    cnt++;
                    ans.append((i + 1) + " " + (j + 1) + " ");
                    arr[i][j] = 1 - arr[i][j];
                    ans.append((i + 2) + " " + (j + 1) + " ");
                    arr[i + 1][j] = 1 - arr[i + 1][j];
                    ans.append((i + 1) + " " + (j + 2) + "\n");
                    arr[i][j + 1] = 1 - arr[i][j + 1];

                    i = n - 2;
                    j = m - 2;
                    int id = 0;
                    int jd = 0;
                    if (arr[i][j] == 1) {
                        id = i;
                        jd = j;
                    }
                    if (arr[i + 1][j] == 1) {
                        id = i + 1;
                        jd = j;
                    }
                    if (arr[i][j + 1] == 1) {
                        id = i;
                        jd = j + 1;
                    }
                    if (arr[i + 1][j + 1] == 1) {
                        id = i + 1;
                        jd = j + 1;
                    }
                    int iid = id == n - 1 ? n - 2 : n - 1;
                    int jjd = jd == m - 1 ? m - 2 : m - 1;
                    cnt++;
                    ans.append((id + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jd + 1) + " " + (id + 1) + " " + (jjd + 1) + "\n");
                    arr[id][jd] = 1 - arr[id][jd];
                    arr[iid][jd] = 1 - arr[iid][jd];
                    arr[id][jjd] = 1 - arr[id][jjd];
                    cnt++;
                    ans.append((id + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jd + 1) + " " + (iid + 1) + " " + (jjd + 1) + "\n");
                    arr[id][jd] = 1 - arr[id][jd];
                    arr[iid][jd] = 1 - arr[iid][jd];
                    arr[iid][jjd] = 1 - arr[iid][jjd];
                    cnt++;
                    if (arr[i][j] == 1) {
                        ans.append((i + 1) + " " + (j + 1) + " ");
                        arr[i][j] = 1 - arr[i][j];
                    }
                    if (arr[i + 1][j] == 1) {
                        ans.append((i + 2) + " " + (j + 1) + " ");
                        arr[i + 1][j] = 1 - arr[i + 1][j];

                    }
                    if (arr[i][j + 1] == 1) {
                        ans.append((i + 1) + " " + (j + 2) + " ");
                        arr[i][j + 1] = 1 - arr[i][j + 1];

                    }
                    if (arr[i + 1][j + 1] == 1) {
                        ans.append((i + 2) + " " + (j + 2) + " ");
                        arr[i + 1][j + 1] = 1 - arr[i + 1][j + 1];
                    }
                    ans.append("\n");
                }


                pw.println(cnt);
                pw.print(ans.toString());
            }
        }

    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String nextLine() {
            try {
                return br.readLine();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

    }
}

