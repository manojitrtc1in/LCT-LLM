import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable{

    FastScanner sc;
    BufferedReader reader;
    PrintWriter out;
    
    
    int n;
    int m; 
    int ans = 0;
    int col = 0;
    int iter = 0;
    int[][] b;
    int[][] a;
    int[][] dx = {{-1,-1,-1, 1}, {-1, 0, 0, 1}, {-1, 1, 1, 1}, {-1, 0, 0, 1}};
    int[][] dy = {{-1, 0, 1, 0}, { 1,-1, 1, 1}, { 0,-1, 0, 1}, {-1,-1, 1,-1}};
   
    boolean check(int x, int y, int z) {
        for (int i = 0;i < 4; ++ i) {
            if (a[x + dx[z][i]][y + dy[z][i]] != -1) {
                return false;
            }
        }
        return true;
    }
    
    void fill(int x, int y, int z) {
        a[x][y] = z;
        col ++;
        for (int i = 0;i < 4; ++ i) {
            a[x + dx[z][i]][y + dy[z][i]] = -2;
        }
    }
    
    void clear(int x, int y, int z) {
        a[x][y] = -1;
        col --;
        for (int i = 0;i < 4; ++ i) {
            a[x + dx[z][i]][y + dy[z][i]] = -1;
        }
    }
    
    void dfs() {
        
        ++ iter;
        if (iter > 50000000)
            return;
        
        boolean flag = false;
        
        for (int i = 1;i < n - 1; ++ i) {
            for (int j = 1;j < m - 1; ++ j) {
                if (a[i][j] == -1) {
                    for (int z = 0;z < 4; ++ z) {
                        if (check(i,j,z)) {
                            flag = true;
                            fill(i,j,z);
                            dfs();
                            clear(i,j,z);
                        }
                    }
                }
            }
        }
        
        if (!flag) {
            if (col > ans) {
                ans = col;
                for (int i = 0;i < n; ++ i) {
                    for (int j = 0;j < m; ++ j) {
                        b[i][j] = a[i][j];
                    }
                }
            }
        }
    }
    
    void solve() throws IOException {
        
        preCalc(sc.nextInt(), sc.nextInt());
        
        
    }   
    
    void preCalc(int n, int m) {
        if (n == 1 && m == 1) {
            out.println("0");
            out.println(".");
            }
            if (n == 1 && m == 2) {
            out.println("0");
            out.println("..");
            }
            if (n == 1 && m == 3) {
            out.println("0");
            out.println("...");
            }
            if (n == 1 && m == 4) {
            out.println("0");
            out.println("....");
            }
            if (n == 1 && m == 5) {
            out.println("0");
            out.println(".....");
            }
            if (n == 1 && m == 6) {
            out.println("0");
            out.println("......");
            }
            if (n == 1 && m == 7) {
            out.println("0");
            out.println(".......");
            }
            if (n == 1 && m == 8) {
            out.println("0");
            out.println("........");
            }
            if (n == 1 && m == 9) {
            out.println("0");
            out.println(".........");
            }
            if (n == 2 && m == 1) {
            out.println("0");
            out.println(".");
            out.println(".");
            }
            if (n == 2 && m == 2) {
            out.println("0");
            out.println("..");
            out.println("..");
            }
            if (n == 2 && m == 3) {
            out.println("0");
            out.println("...");
            out.println("...");
            }
            if (n == 2 && m == 4) {
            out.println("0");
            out.println("....");
            out.println("....");
            }
            if (n == 2 && m == 5) {
            out.println("0");
            out.println(".....");
            out.println(".....");
            }
            if (n == 2 && m == 6) {
            out.println("0");
            out.println("......");
            out.println("......");
            }
            if (n == 2 && m == 7) {
            out.println("0");
            out.println(".......");
            out.println(".......");
            }
            if (n == 2 && m == 8) {
            out.println("0");
            out.println("........");
            out.println("........");
            }
            if (n == 2 && m == 9) {
            out.println("0");
            out.println(".........");
            out.println(".........");
            }
            if (n == 3 && m == 1) {
            out.println("0");
            out.println(".");
            out.println(".");
            out.println(".");
            }
            if (n == 3 && m == 2) {
            out.println("0");
            out.println("..");
            out.println("..");
            out.println("..");
            }
            if (n == 3 && m == 3) {
            out.println("1");
            out.println("AAA");
            out.println(".A.");
            out.println(".A.");
            }
            if (n == 3 && m == 4) {
            out.println("1");
            out.println("AAA.");
            out.println(".A..");
            out.println(".A..");
            }
            if (n == 3 && m == 5) {
            out.println("2");
            out.println("AAA.B");
            out.println(".ABBB");
            out.println(".A..B");
            }
            if (n == 3 && m == 6) {
            out.println("2");
            out.println("AAA.B.");
            out.println(".ABBB.");
            out.println(".A..B.");
            }
            if (n == 3 && m == 7) {
            out.println("3");
            out.println("AAABCCC");
            out.println(".A.B.C.");
            out.println(".ABBBC.");
            }
            if (n == 3 && m == 8) {
            out.println("3");
            out.println("AAA.BCCC");
            out.println(".ABBB.C.");
            out.println(".A..B.C.");
            }
            if (n == 3 && m == 9) {
            out.println("4");
            out.println("AAABCCC.D");
            out.println(".A.B.CDDD");
            out.println(".ABBBC..D");
            }
            if (n == 4 && m == 1) {
            out.println("0");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            }
            if (n == 4 && m == 2) {
            out.println("0");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            }
            if (n == 4 && m == 3) {
            out.println("1");
            out.println("AAA");
            out.println(".A.");
            out.println(".A.");
            out.println("...");
            }
            if (n == 4 && m == 4) {
            out.println("2");
            out.println("AAA.");
            out.println(".AB.");
            out.println(".AB.");
            out.println(".BBB");
            }
            if (n == 4 && m == 5) {
            out.println("2");
            out.println("AAA.B");
            out.println(".ABBB");
            out.println(".A..B");
            out.println(".....");
            }
            if (n == 4 && m == 6) {
            out.println("3");
            out.println("AAABBB");
            out.println(".AC.B.");
            out.println(".AC.B.");
            out.println(".CCC..");
            }
            if (n == 4 && m == 7) {
            out.println("4");
            out.println("AAABBB.");
            out.println(".AC.BD.");
            out.println(".AC.BD.");
            out.println(".CCCDDD");
            }
            if (n == 4 && m == 8) {
            out.println("4");
            out.println("AAA.BCCC");
            out.println(".ABBBDC.");
            out.println(".A..BDC.");
            out.println("....DDD.");
            }
            if (n == 4 && m == 9) {
            out.println("5");
            out.println("AAABBBCCC");
            out.println(".AD.BE.C.");
            out.println(".AD.BE.C.");
            out.println(".DDDEEE..");
            }
            if (n == 5 && m == 1) {
            out.println("0");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            }
            if (n == 5 && m == 2) {
            out.println("0");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            }
            if (n == 5 && m == 3) {
            out.println("2");
            out.println("AAA");
            out.println(".A.");
            out.println(".AB");
            out.println("BBB");
            out.println("..B");
            }
            if (n == 5 && m == 4) {
            out.println("2");
            out.println("AAA.");
            out.println(".AB.");
            out.println(".AB.");
            out.println(".BBB");
            out.println("....");
            }
            if (n == 5 && m == 5) {
            out.println("4");
            out.println("AAA.B");
            out.println(".ABBB");
            out.println("CA.DB");
            out.println("CCCD.");
            out.println("C.DDD");
            }
            if (n == 5 && m == 6) {
            out.println("4");
            out.println("AAA.B.");
            out.println(".ABBB.");
            out.println(".AC.BD");
            out.println("CCCDDD");
            out.println("..C..D");
            }
            if (n == 5 && m == 7) {
            out.println("5");
            out.println("AAA.B..");
            out.println(".ABBBC.");
            out.println("DA.EBC.");
            out.println("DDDECCC");
            out.println("D.EEE..");
            }
            if (n == 5 && m == 8) {
            out.println("6");
            out.println("AAA.BCCC");
            out.println(".ABBBDC.");
            out.println("EA.FBDC.");
            out.println("EEEFDDD.");
            out.println("E.FFF...");
            }
            if (n == 5 && m == 9) {
            out.println("7");
            out.println("AAA.BCCC.");
            out.println(".ABBBDC..");
            out.println("EA.FBDCG.");
            out.println("EEEFDDDG.");
            out.println("E.FFF.GGG");
            }
            if (n == 6 && m == 1) {
            out.println("0");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            }
            if (n == 6 && m == 2) {
            out.println("0");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            }
            if (n == 6 && m == 3) {
            out.println("2");
            out.println("AAA");
            out.println(".A.");
            out.println(".AB");
            out.println("BBB");
            out.println("..B");
            out.println("...");
            }
            if (n == 6 && m == 4) {
            out.println("3");
            out.println("AAA.");
            out.println(".AB.");
            out.println(".AB.");
            out.println("CBBB");
            out.println("CCC.");
            out.println("C...");
            }
            if (n == 6 && m == 5) {
            out.println("4");
            out.println("AAA.B");
            out.println(".ABBB");
            out.println(".AC.B");
            out.println("CCCD.");
            out.println("..CD.");
            out.println("..DDD");
            }
            if (n == 6 && m == 6) {
            out.println("5");
            out.println("AAA.B.");
            out.println(".ABBB.");
            out.println(".A.CB.");
            out.println("DCCCE.");
            out.println("DDDCE.");
            out.println("D..EEE");
            }
            if (n == 6 && m == 7) {
            out.println("6");
            out.println("AAABCCC");
            out.println(".A.B.C.");
            out.println("DABBBCE");
            out.println("DDDFEEE");
            out.println("DFFF..E");
            out.println("...F...");
            }
            if (n == 6 && m == 8) {
            out.println("7");
            out.println("AAA.BCCC");
            out.println(".ABBBDC.");
            out.println(".AE.BDC.");
            out.println("EEEFDDDG");
            out.println("..EF.GGG");
            out.println("..FFF..G");
            }
            if (n == 6 && m == 9) {
            out.println("8");
            out.println("AAA.BCCC.");
            out.println(".ABBB.C..");
            out.println(".A.DBEC..");
            out.println("FDDDGEEEH");
            out.println("FFFDGEHHH");
            out.println("F..GGG..H");
            }
            if (n == 7 && m == 1) {
            out.println("0");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            }
            if (n == 7 && m == 2) {
            out.println("0");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            }
            if (n == 7 && m == 3) {
            out.println("3");
            out.println("AAA");
            out.println(".A.");
            out.println(".AB");
            out.println("BBB");
            out.println(".CB");
            out.println(".C.");
            out.println("CCC");
            }
            if (n == 7 && m == 4) {
            out.println("4");
            out.println("AAA.");
            out.println(".AB.");
            out.println(".AB.");
            out.println("CBBB");
            out.println("CCCD");
            out.println("CDDD");
            out.println("...D");
            }
            if (n == 7 && m == 5) {
            out.println("5");
            out.println("AAA.B");
            out.println(".ABBB");
            out.println(".AC.B");
            out.println("CCCD.");
            out.println(".ECD.");
            out.println(".EDDD");
            out.println("EEE..");
            }
            if (n == 7 && m == 6) {
            out.println("6");
            out.println("AAA.B.");
            out.println(".ABBB.");
            out.println(".AC.BD");
            out.println("CCCDDD");
            out.println(".EC.FD");
            out.println(".EFFF.");
            out.println("EEE.F.");
            }
            if (n == 7 && m == 7) {
            out.println("8");
            out.println("AAABCCC");
            out.println(".A.B.C.");
            out.println("DABBBCE");
            out.println("DDDFEEE");
            out.println("DG.F.HE");
            out.println(".GFFFH.");
            out.println("GGG.HHH");
            }
            if (n == 7 && m == 8) {
            out.println("9");
            out.println("AAA.BBB.");
            out.println(".ACCCBD.");
            out.println(".AEC.BD.");
            out.println("EEECFDDD");
            out.println("G.EHFFFI");
            out.println("GGGHFIII");
            out.println("G.HHH..I");
            }
            if (n == 7 && m == 9) {
            out.println("10");
            out.println("AAA.BC...");
            out.println(".ABBBCCCD");
            out.println("EA.FBCDDD");
            out.println("EEEF.GGGD");
            out.println("EHFFFIGJ.");
            out.println(".H.IIIGJ.");
            out.println("HHH..IJJJ");
            }
            if (n == 8 && m == 1) {
            out.println("0");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            }
            if (n == 8 && m == 2) {
            out.println("0");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            }
            if (n == 8 && m == 3) {
            out.println("3");
            out.println("AAA");
            out.println(".A.");
            out.println(".AB");
            out.println("BBB");
            out.println(".CB");
            out.println(".C.");
            out.println("CCC");
            out.println("...");
            }
            if (n == 8 && m == 4) {
            out.println("4");
            out.println("AAA.");
            out.println(".AB.");
            out.println(".AB.");
            out.println("CBBB");
            out.println("CCCD");
            out.println("CDDD");
            out.println("...D");
            out.println("....");
            }
            if (n == 8 && m == 5) {
            out.println("6");
            out.println("AAA.B");
            out.println(".ABBB");
            out.println("CA.DB");
            out.println("CCCD.");
            out.println("CEDDD");
            out.println(".EFFF");
            out.println("EEEF.");
            out.println("...F.");
            }
            if (n == 8 && m == 6) {
            out.println("7");
            out.println("AAA.B.");
            out.println(".ABBB.");
            out.println(".AC.BD");
            out.println("CCCDDD");
            out.println("..CE.D");
            out.println("FEEEG.");
            out.println("FFFEG.");
            out.println("F..GGG");
            }
            if (n == 8 && m == 7) {
            out.println("9");
            out.println("AAAB..C");
            out.println(".A.BCCC");
            out.println("DABBBEC");
            out.println("DDDEEE.");
            out.println("DFFF.EG");
            out.println(".HFIGGG");
            out.println(".HFIIIG");
            out.println("HHHI...");
            }
            if (n == 8 && m == 8) {
            out.println("10");
            out.println("AAA.BCCC");
            out.println(".ABBBDC.");
            out.println("EA.FBDC.");
            out.println("EEEFDDDG");
            out.println("EHFFFGGG");
            out.println(".HIII.JG");
            out.println("HHHIJJJ.");
            out.println("...I..J.");
            }
            if (n == 8 && m == 9) {
            out.println("12");
            out.println("A.EEE.JJJ");
            out.println("AAAEHHHJ.");
            out.println("AB.EFHKJ.");
            out.println(".BFFFHKKK");
            out.println("BBBDFIK..");
            out.println("CDDDGIIIL");
            out.println("CCCDGILLL");
            out.println("C..GGG..L");
            }
            if (n == 9 && m == 1) {
            out.println("0");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            out.println(".");
            }
            if (n == 9 && m == 2) {
            out.println("0");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            out.println("..");
            }
            if (n == 9 && m == 3) {
            out.println("4");
            out.println("AAA");
            out.println(".A.");
            out.println(".AB");
            out.println("BBB");
            out.println("C.B");
            out.println("CCC");
            out.println("C.D");
            out.println("DDD");
            out.println("..D");
            }
            if (n == 9 && m == 4) {
            out.println("5");
            out.println("AAA.");
            out.println(".AB.");
            out.println(".AB.");
            out.println("CBBB");
            out.println("CCCD");
            out.println("CDDD");
            out.println("EEED");
            out.println(".E..");
            out.println(".E..");
            }
            if (n == 9 && m == 5) {
            out.println("7");
            out.println("AAA.B");
            out.println(".ABBB");
            out.println("CA.DB");
            out.println("CCCD.");
            out.println("CEDDD");
            out.println(".EEEF");
            out.println("GEFFF");
            out.println("GGG.F");
            out.println("G....");
            }
            if (n == 9 && m == 6) {
            out.println("8");
            out.println("AAA.B.");
            out.println(".ABBB.");
            out.println(".AC.BD");
            out.println("CCCDDD");
            out.println("E.CF.D");
            out.println("EEEF..");
            out.println("EGFFFH");
            out.println(".G.HHH");
            out.println("GGG..H");
            }
            if (n == 9 && m == 7) {
            out.println("10");
            out.println("AAA.B..");
            out.println(".ABBBC.");
            out.println(".AD.BC.");
            out.println("DDDECCC");
            out.println("F.DEEEG");
            out.println("FFFEGGG");
            out.println("FHIIIJG");
            out.println(".H.I.J.");
            out.println("HHHIJJJ");
            }
            if (n == 9 && m == 8) {
            out.println("12");
            out.println("AAA.BCCC");
            out.println(".ABBBDC.");
            out.println("EA.FBDC.");
            out.println("EEEFDDDG");
            out.println("EHFFFGGG");
            out.println(".HHHIIIG");
            out.println("JHKKKIL.");
            out.println("JJJK.IL.");
            out.println("J..K.LLL");
            }
            if (n == 9 && m == 9) {
                out.println("13");
                out.println("AAA.BCCC.");
                out.println(".ABBB.CD.");
                out.println(".AE.BFCD.");
                out.println("EEEFFFDDD");
                out.println("G.E.HFIII");
                out.println("GGGJHHHI.");
                out.println("GK.JHL.IM");
                out.println(".KJJJLMMM");
                out.println("KKK.LLL.M");
            }

    }
    
    public static void main(String[] argv) {
        new Thread(null, new Main(), "", 16 * 1024 * 1024).start();
    }

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            sc = new FastScanner(reader);
            

            out = new PrintWriter(new OutputStreamWriter(System.out));
            solve();
        } catch (Exception e) {
            throw new RuntimeException(e);
        } finally {
            out.close();
        }
    }
    
    
    class FastScanner {
        BufferedReader reader;
        StringTokenizer strtok;
        
        public FastScanner(BufferedReader reader) {
            this.reader = reader;
        }
        
        String nextToken() throws IOException {
            if (strtok == null || !strtok.hasMoreElements()) {
                strtok = new StringTokenizer(reader.readLine());
            }
            
            return strtok.nextToken(); 
        }
        
        double nextDouble() throws IOException {
            return Double.parseDouble(nextToken());
        }
        
        int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }
        
        long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }
    }
}