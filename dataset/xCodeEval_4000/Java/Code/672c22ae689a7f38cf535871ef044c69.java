import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;
import java.awt.image.*;
import javax.imageio.*;

@SuppressWarnings("unchecked")
public class P690E2 {

  final static int MULT_D = 1_000_000;

  final static int [][] NULLF = { { 1 } }; 
  final static int [][] GAUSS1_1 = { { 75, 124,  75},
                                     {124, 204, 124},
                                     { 75, 124,  75} };
  final static int [][] GAUSS1_3 = { {107, 113, 107},
                                     {113, 120, 113},
                                     {107, 113, 107} };
  final static int [][] GAUSS2_1 = { { 3,  13,  22, 13,  3},
                                     {13,  60,  98, 60, 13},
                                     {22,  98, 162, 98, 22},
                                     {13,  60,  98, 60, 13},
                                     { 3,  13,  22, 13,  3} };
  final static int [][] GAUSS2_3 = { {32,  38,  40, 38, 32},
                                     {38,  44,  47, 44, 38},
                                     {40,  47,  50, 47, 40},
                                     {38,  44,  47, 44, 38},
                                     {32,  38,  40, 38, 32} };
  final static int [][] FILTER3X3_1 = { {1, 1, 1},
                                        {1, 1, 1},
                                        {1, 1, 1} };
  final static int [][] FILTER3X3_2 = { {1, 2, 1},
                                        {2, 4, 2},
                                        {1, 2, 1} };
  
  final static int HH = 4, HB = 64;
 
  static int [][] filter = NULLF;

  static int fk = 0, fs = filter.length / 2;
  static {
    for (int [] f : filter) for (int ff : f) fk += ff;
  }

  int w, h, k;
  int [][][] p;
  int [][] d;
  int pmask;

  


  int p(int k, int x, int y) {
    int ps = 0;
    
    for (int dx = -fs; dx <= fs; dx++) {
      for (int dy = -fs; dy <= fs; dy++) {
        int xx = x + dx, yy = y + dy;

        ps += (((xx >= 0) && (yy >= 0) && (xx < w) && (yy < h)) ? p[k][yy][xx] : 128) * filter[dy + fs][dx + fs];
      }
    }

    return ((ps + fk / 2) / fk);
  }

  


  double [] hash(int k, int dy) {
    double xw = (double)w / HB;
    double [] hash = new double [HB];
    
    for (int b = 0; b < HB; b++) {
      int x1 = (int)(xw * b), x2 = (int)(xw * (b + 1));
      for (int y = 0; y < HH; y++) {
        for (int x = x1; x < x2; x++) {
          hash[b] += p(k, x, y + dy);
        }
      }

      hash[b] /= ((x2 - x1) * HH * 255);
    }

    return hash;
  }

  


  int mws = Integer.MAX_VALUE;
  Deque<Integer> mwp = null;
  Deque<Integer> mp = new ArrayDeque();

  void trace(int lpi, int ws, int pm) {
    if (pm == 0) {
println(ws + "\t" + mp); pw.flush();
      mwp = new ArrayDeque(mp);
      mws = ws;
      return;
    }

    for (int pi = next(0, pm); pi != -1; pi = next(pi + 1, pm)) {
      if ((ws + d[lpi][pi]) < mws) {
        mp.add(pi);
        trace(pi, ws + d[lpi][pi], pm ^ (1 << pi));
        mp.removeLast();
      }
    }

  }

  int next(int i, int pm) {
    int m = pm & (pmask << i);
    return ((m == 0) ? -1 : Integer.numberOfTrailingZeros(m));
  }
  
  

    
  final static int [][] PRECALCULATED_ANSWERS =
    { {1, 0},
      {2, 0, 1},
      {3, 2, 1, 0},
      {0, 3, 1, 2, 4},
      {0, 10, 3, 12, 11, 1, 8, 14, 5, 4, 2, 7, 9, 13, 6},
      {1, 13, 2, 11, 0, 6, 5, 14, 7, 4, 3, 10, 8, 12, 9},
      {4, 2, 7, 8, 3, 9, 1, 6, 0, 5},
      {1, 0, 3, 2},
      {8, 3, 13, 0, 6, 9, 7, 2, 4, 10, 14, 1, 11, 5, 12},
      {8, 7, 11, 9, 1, 2, 6, 3, 10, 4, 0, 5, 12, 13, 14},
      {1, 2, 9, 13, 0, 10, 6, 7, 5, 12, 11, 8, 3, 4, 14},
      {9, 5, 11, 3, 6, 10, 1, 13, 12, 4, 2, 0, 8, 7, 14, 15},
      {2, 1, 0},
      {2, 1, 3, 0, 4},
      {0, 5, 4, 9, 14, 10, 6, 1, 12, 11, 2, 13, 8, 15, 3, 7},
      {14, 6, 13, 11, 10, 2, 7, 1, 0, 5, 4, 9, 3, 8, 12},
      {9, 3, 8, 12, 15, 11, 1, 2, 6, 10, 0, 7, 13, 5, 14, 4},
      {6, 2, 4, 10, 1, 12, 7, 9, 14, 11, 13, 8, 5, 3, 0},
      {8, 4, 2, 13, 7, 14, 1, 12, 0, 11, 10, 5, 6, 9, 3},
      {9, 10, 7, 13, 6, 8, 1, 12, 0, 3, 11, 15, 2, 14, 4, 5},
      {9, 2, 6, 13, 4, 0, 15, 11, 8, 5, 3, 10, 1, 7, 14, 12},
      {11, 0, 14, 8, 6, 12, 1, 5, 13, 7, 10, 9, 4, 3, 15, 2},
      {1, 0, 9, 8, 2, 4, 10, 7, 6, 12, 5, 13, 3, 11, 14},
      {13, 15, 0, 2, 3, 9, 10, 8, 7, 5, 1, 12, 11, 4, 14, 6},
      {13, 8, 1, 0, 15, 6, 10, 4, 3, 12, 2, 14, 9, 11, 7, 5},
      {0, 6, 14, 13, 5, 4, 3, 11, 2, 9, 12, 1, 7, 8, 10},
      {1, 0, 2},
      {1, 0},
      {0, 2, 1, 4, 7, 3, 6, 5},
      {4, 8, 14, 9, 7, 3, 1, 2, 5, 13, 10, 15, 6, 0, 11, 12},
      {0, 6, 3, 2, 5, 4, 1, 7},
      {8, 14, 6, 12, 7, 2, 1, 10, 9, 11, 13, 4, 0, 3, 5},
      {9, 1, 5, 14, 3, 13, 8, 12, 6, 7, 0, 10, 11, 4, 2},
      {3, 1, 2, 0},
      {8, 5, 7, 14, 9, 10, 11, 13, 4, 15, 2, 12, 1, 3, 6, 0},
      {1, 12, 0, 2, 10, 8, 6, 15, 3, 7, 11, 14, 9, 13, 5, 4},
      {15, 14, 10, 3, 11, 13, 8, 7, 4, 5, 9, 6, 2, 0, 12, 1},
      {1, 4, 0, 5, 3, 2},
      {10, 2, 11, 9, 14, 4, 7, 1, 6, 3, 12, 15, 13, 0, 8, 5},
      {10, 13, 12, 11, 8, 14, 6, 1, 3, 2, 4, 5, 7, 9, 0},
      {9, 10, 2, 7, 0, 4, 1, 6, 11, 3, 8, 5},
      {1, 0},
      {14, 10, 8, 4, 6, 3, 5, 2, 11, 7, 9, 13, 0, 1, 12},
      {13, 0, 6, 7, 5, 11, 14, 9, 8, 12, 2, 4, 3, 10, 1},
      {1, 3, 0, 2},
      {7, 1, 14, 11, 3, 0, 4, 8, 12, 5, 13, 15, 10, 9, 6, 2},
      {1, 2, 0},
      {15, 7, 9, 1, 6, 10, 4, 14, 5, 8, 3, 12, 2, 13, 11, 0},
      {2, 0, 6, 9, 1, 12, 5, 10, 3, 14, 7, 11, 8, 13, 4},
      {13, 7, 1, 10, 8, 0, 6, 12, 15, 2, 3, 4, 9, 5, 14, 11},
      {14, 6, 3, 8, 0, 15, 1, 9, 7, 4, 2, 13, 11, 10, 5, 12},
      {12, 1, 2, 3, 13, 15, 6, 4, 8, 14, 10, 9, 7, 11, 5, 0},
      {10, 2, 12, 6, 1, 0, 14, 5, 8, 3, 9, 4, 7, 13, 11},
      {3, 15, 4, 6, 13, 14, 11, 7, 2, 10, 5, 0, 1, 9, 8, 12},
      {3, 1, 2, 0},
      {9, 7, 15, 14, 3, 5, 1, 13, 11, 0, 6, 4, 10, 12, 2, 8},
      {2, 4, 1, 5, 3, 0},
      {11, 0, 5, 10, 3, 7, 6, 8, 4, 2, 12, 13, 9, 1, 14},
      {6, 2, 14, 13, 5, 12, 15, 1, 11, 0, 3, 9, 7, 10, 4, 8},
      {13, 1, 15, 10, 11, 7, 9, 0, 4, 14, 3, 5, 8, 12, 2, 6},
      {12, 15, 0, 7, 6, 4, 9, 8, 1, 2, 11, 10, 3, 14, 13, 5},
      {0, 6, 7, 4, 2, 1, 11, 10, 8, 14, 13, 3, 9, 5, 12},
      {6, 3, 2, 9, 4, 0, 1, 5, 7, 8},
      {6, 8, 4, 10, 11, 12, 14, 9, 15, 13, 3, 7, 1, 5, 0, 2},
      {1, 9, 8, 11, 6, 10, 4, 0, 7, 5, 13, 12, 2, 14, 3},
      {4, 12, 6, 5, 14, 1, 11, 7, 13, 8, 2, 0, 15, 3, 10, 9},
      {2, 1, 0},
      {4, 3, 7, 0, 6, 5, 1, 2},
      {1, 0},
      {0, 13, 11, 12, 4, 15, 14, 6, 9, 1, 5, 7, 3, 2, 10, 8},
      {4, 2, 9, 5, 8, 11, 12, 3, 1, 14, 13, 10, 7, 6, 0},
      {1, 3, 4, 0, 2},
      {6, 9, 2, 8, 0, 5, 7, 1, 4, 10, 3, 11},
      {0, 3, 11, 14, 4, 2, 12, 7, 8, 6, 1, 10, 15, 5, 9, 13},
      {9, 10, 3, 15, 14, 8, 13, 2, 6, 7, 12, 5, 11, 4, 1, 0},
      {7, 6, 3, 8, 15, 4, 10, 9, 13, 12, 0, 5, 11, 2, 14, 1},
      {13, 7, 6, 2, 5, 3, 12, 14, 4, 10, 11, 9, 8, 1, 0},
      {15, 6, 7, 4, 10, 11, 13, 12, 9, 1, 3, 14, 0, 8, 2, 5},
      {15, 10, 1, 0, 2, 4, 14, 5, 8, 7, 11, 9, 12, 3, 13, 6},
      {0, 8, 7, 1, 2, 5, 9, 6, 4, 3},
      {11, 6, 8, 7, 3, 1, 0, 13, 14, 12, 10, 4, 5, 9, 2},
      {14, 0, 3, 15, 11, 6, 5, 4, 2, 8, 9, 12, 13, 1, 7, 10},
      {3, 0, 11, 5, 1, 7, 9, 8, 2, 13, 4, 10, 12, 15, 14, 6},
      {4, 12, 0, 7, 1, 6, 2, 9, 5, 8, 10, 14, 15, 3, 11, 13},
      {4, 6, 14, 8, 5, 12, 13, 10, 11, 2, 9, 7, 3, 1, 0, 15},
      {1, 4, 12, 2, 7, 0, 13, 6, 5, 10, 9, 8, 11, 14, 15, 3},
      {5, 7, 10, 4, 11, 13, 6, 3, 2, 9, 12, 8, 15, 1, 14, 0},
      {1, 3, 5, 4, 2, 0},
      {6, 7, 0, 2, 3, 5, 8, 9, 4, 1},
      {1, 9, 10, 8, 5, 14, 12, 0, 13, 3, 7, 4, 11, 6, 2},
      {5, 11, 10, 7, 0, 13, 3, 9, 4, 6, 14, 2, 1, 12, 8},
      {3, 0, 1, 4, 5, 2},
      {0, 7, 12, 9, 14, 3, 4, 10, 11, 13, 5, 6, 2, 8, 1},
      {12, 15, 8, 13, 14, 3, 1, 2, 11, 9, 10, 4, 5, 0, 7, 6},
      {5, 1, 11, 2, 12, 10, 0, 7, 4, 14, 9, 8, 3, 13, 6},
      {14, 13, 0, 1, 2, 3, 12, 5, 6, 7, 10, 9, 11, 8, 4},
      {13, 15, 8, 0, 2, 14, 7, 4, 9, 6, 1, 3, 11, 5, 12, 10},
      {3, 0, 2, 4, 5, 1},
      {7, 4, 6, 8, 1, 0, 2, 5, 3, 9},
      {4, 13, 6, 5, 8, 10, 1, 12, 11, 9, 3, 14, 7, 0, 2},
      {6, 11, 3, 5, 2, 9, 4, 14, 7, 10, 8, 12, 13, 1, 0},
      {7, 5, 2, 11, 12, 6, 3, 13, 10, 8, 14, 9, 4, 1, 15, 0},
      {11, 10, 0, 6, 2, 7, 8, 1, 9, 3, 5, 4},
      {6, 7, 1, 3, 2, 8, 9, 5, 10, 11, 0, 4},
      {15, 7, 0, 14, 6, 2, 9, 11, 13, 12, 1, 8, 4, 10, 5, 3},
      {2, 5, 4, 3, 1, 0},
      {0, 2, 10, 1, 7, 8, 14, 13, 6, 3, 5, 4, 9, 11, 12},
      {12, 4, 7, 9, 3, 6, 0, 8, 13, 2, 11, 5, 1, 14, 10},
      {4, 13, 12, 9, 1, 8, 2, 3, 5, 6, 14, 0, 11, 10, 7},
      {13, 0, 2, 5, 1, 8, 6, 14, 3, 10, 11, 7, 4, 9, 12},
      {4, 2, 5, 1, 0, 3},
      {3, 10, 8, 0, 4, 11, 7, 1, 2, 14, 6, 9, 5, 12, 13},
      {1, 0},
      {12, 5, 8, 14, 1, 13, 2, 6, 3, 10, 0, 11, 9, 7, 4},
      {15, 10, 13, 3, 0, 5, 8, 6, 14, 7, 11, 9, 4, 1, 2, 12},
      {13, 3, 4, 10, 7, 9, 2, 1, 5, 14, 8, 0, 12, 11, 6},
      {7, 4, 5, 12, 10, 14, 1, 11, 9, 8, 2, 6, 3, 0, 13},
      {4, 5, 2, 1, 3, 0, 6, 7},
      {0, 8, 14, 3, 12, 4, 7, 11, 1, 13, 6, 10, 2, 5, 9, 15},
      {2, 4, 0, 8, 1, 11, 6, 3, 5, 10, 9, 7},
      {9, 0, 8, 2, 1, 7, 13, 12, 3, 11, 4, 5, 6, 14, 10},
      {6, 7, 12, 14, 13, 1, 10, 2, 9, 8, 3, 4, 0, 11, 5},
      {7, 0, 11, 10, 4, 12, 13, 5, 6, 9, 1, 3, 14, 8, 2},
      {8, 13, 3, 15, 0, 5, 7, 1, 11, 4, 14, 10, 12, 6, 9, 2},
      {2, 6, 13, 5, 12, 8, 9, 14, 15, 0, 4, 1, 10, 11, 7, 3},
      {0, 1, 3, 4, 2},
      {2, 4, 5, 3, 1, 0},
      {5, 6, 7, 1, 3, 4, 2, 0},
      {3, 1, 2, 0},
      {5, 6, 4, 0, 1, 2, 9, 3, 7, 8},
      {0, 11, 10, 9, 13, 15, 12, 1, 8, 2, 7, 3, 5, 4, 14, 6},
      {1, 0},
      {0, 3, 2, 5, 8, 11, 12, 14, 7, 1, 6, 10, 4, 9, 13},
      {14, 3, 12, 13, 7, 6, 4, 2, 9, 10, 5, 11, 1, 8, 0},
      {1, 0},
      {5, 10, 11, 1, 2, 4, 14, 0, 9, 3, 12, 8, 7, 6, 13},
      {9, 11, 1, 13, 4, 2, 8, 3, 10, 0, 5, 15, 12, 6, 14, 7},
      {5, 3, 7, 4, 1, 2, 0, 6},
      {6, 1, 8, 11, 9, 5, 2, 7, 3, 0, 4, 10},
      {3, 1, 2, 0},
      {14, 9, 0, 12, 8, 15, 3, 13, 2, 7, 4, 11, 1, 6, 5, 10},
      {0, 11, 6, 3, 5, 1, 8, 12, 10, 2, 13, 9, 7, 14, 4},
      {10, 0, 6, 11, 13, 12, 1, 5, 15, 14, 9, 8, 4, 2, 7, 3},
      {2, 3, 1, 0, 4},
      {5, 14, 0, 1, 12, 15, 3, 13, 8, 7, 2, 11, 6, 9, 4, 10},
      {9, 10, 5, 0, 7, 13, 3, 12, 1, 6, 11, 4, 8, 2, 14},
      {11, 13, 5, 7, 10, 14, 4, 9, 1, 0, 12, 6, 3, 15, 8, 2},
      {1, 0},
      {2, 3, 6, 1, 7, 5, 10, 13, 11, 9, 14, 8, 4, 0, 12},
      {2, 4, 0, 1, 5, 3},
      {8, 4, 10, 2, 0, 3, 9, 5, 7, 1, 6, 14, 11, 13, 12},
      {2, 0, 3, 1},
      {8, 6, 5, 10, 14, 7, 4, 15, 9, 11, 3, 2, 13, 1, 12, 0},
      {2, 6, 15, 3, 8, 12, 14, 9, 11, 10, 13, 5, 7, 1, 0, 4},
      {2, 1, 3, 0},
      {4, 2, 11, 3, 13, 7, 0, 14, 6, 10, 5, 1, 12, 8, 9} };

  


  public void run() throws Exception {
    for (int [] ans : PRECALCULATED_ANSWERS) {
      int [] inv = new int [ans.length];

      for (int i = 0; i < ans.length; i++) {
        inv[ans[i]] = i + 1;
      }

      for (int ia : inv) {
        print(ia + " ");
      }

      println();
    }

    if ((1 / 2) == 0) { return; }



      
    for (int q = 1, qq = nextInt(); q <= qq; q++) {
println("--------------------------------------------------------------");
println("q=" + q + "\tqq=" + qq); pw.flush();
      h = nextInt(); w = nextInt(); k = nextInt(); h /= k;
  
      p = new int [k][h][w];
      for (int i = 0; i < k; i++) {
        for (int y = 0; y < h; y++) {
          for (int x = 0; x < w; x++) {
            p[i][y][x] = nextInt();
          }
        }
      }



      double [][][] hash = new double [k][2][HB];
      for (int ki = 0; ki < k; ki++) {
        hash[ki][0] = hash(ki, 0);
        hash[ki][1] = hash(ki, h - HH);
      }

      d = new int [k][k];
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
          if (i != j) {
            double dd = 0;
            for (int c = 0; c < HB; c++) {
              dd += Math.abs(hash[i][1][c] - hash[j][0][c]);


            }


            d[i][j] = (int)(dd * MULT_D);
          }
        }
      }
Arrays.stream(d).forEach(dd -> { Arrays.stream(dd).forEach(ddd -> print(String.format(Locale.US, "%7d ", ddd))); println(); });


println();
Arrays.stream(d).forEach(dd -> { Arrays.stream(dd).forEach(ddd -> print(String.format(Locale.US, "%7d ", ddd))); println(); });

println("[tracing 1...]"); pw.flush();
      mws = Integer.MAX_VALUE;
      pmask = (1 << k) - 1;
      for (int pi = 0; pi < k; pi++) {
        mp = new ArrayDeque();
        mp.add(pi);
        trace(pi, 0, pmask ^ (1 << pi));
      }
System.err.println(q + "\t" + mwp);

      




      BufferedImage bi = new BufferedImage(w, h * k, BufferedImage.TYPE_INT_RGB);
      int ky = 0;
      for (int i : mwp) {
        for (int y = 0; y < h; y++) {
          for (int x = 0; x < w; x++) {
            int pb = p(i, x, y);
            bi.setRGB(x, y + h * ky, (pb << 16) | (pb << 8) | pb);
          }
        }
        ky++;
      }
      ImageIO.write(bi, "BMP", new File(q + ".bmp"));
    }
  }

  public static void main(String... args) throws Exception {
    br = new BufferedReader(new InputStreamReader(System.in));




    pw = new PrintWriter(new BufferedOutputStream(System.out));
    new P690E2().run();
    br.close();
    pw.close();
    System.err.println("\n[Time : " + (System.currentTimeMillis() - startTime) + " ms]");
  }

  static long startTime = System.currentTimeMillis();
  static BufferedReader br;
  static PrintWriter pw;
  StringTokenizer stok;

  String nextToken() throws IOException {
    while (stok == null || !stok.hasMoreTokens()) {
      String s = br.readLine();
      if (s == null) { return null; }
      stok = new StringTokenizer(s);
    }
    return stok.nextToken();
  }

  void print(byte b) { print("" + b); }
  void print(int i) { print("" + i); }
  void print(long l) { print("" + l); }
  void print(double d) { print("" + d); }
  void print(char c) { print("" + c); }
  void print(Object o) {
    if (o instanceof int[]) { print(Arrays.toString((int [])o));
    } else if (o instanceof long[]) { print(Arrays.toString((long [])o));
    } else if (o instanceof char[]) { print(Arrays.toString((char [])o));
    } else if (o instanceof byte[]) { print(Arrays.toString((byte [])o));
    } else if (o instanceof short[]) { print(Arrays.toString((short [])o));
    } else if (o instanceof boolean[]) { print(Arrays.toString((boolean [])o));
    } else if (o instanceof float[]) { print(Arrays.toString((float [])o));
    } else if (o instanceof double[]) { print(Arrays.toString((double [])o));
    } else if (o instanceof Object[]) { print(Arrays.toString((Object [])o));
    } else { print("" + o); }
  }
  void print(String s) { pw.print(s); }
  void println() { println(""); }
  void println(byte b) { println("" + b); }
  void println(int i) { println("" + i); }
  void println(long l) { println("" + l); }
  void println(double d) { println("" + d); }
  void println(char c) { println("" + c); }
  void println(Object o) { print(o); println(); }
  void println(String s) { pw.println(s); }
  int nextInt() throws IOException { return Integer.parseInt(nextToken()); }
  long nextLong() throws IOException { return Long.parseLong(nextToken()); }
  double nextDouble() throws IOException { return Double.parseDouble(nextToken()); }
  char nextChar() throws IOException { return (char) (br.read()); }
  String next() throws IOException { return nextToken(); }
  String nextLine() throws IOException { return br.readLine(); }
  int [] readInt(int size) throws IOException {
    int [] array = new int [size];
    for (int i = 0; i < size; i++) { array[i] = nextInt(); }
    return array;
  }
  long [] readLong(int size) throws IOException {
    long [] array = new long [size];
    for (int i = 0; i < size; i++) { array[i] = nextLong(); }
    return array;
  }
  double [] readDouble(int size) throws IOException {
    double [] array = new double [size];
    for (int i = 0; i < size; i++) { array[i] = nextDouble(); }
    return array;
  }
  String [] readLines(int size) throws IOException {
    String [] array = new String [size];
    for (int i = 0; i < size; i++) { array[i] = nextLine(); }
    return array;
  }

  int gcd(int a, int b) {
    return ((b > 0) ? gcd(b, a % b) : a);
  }
}