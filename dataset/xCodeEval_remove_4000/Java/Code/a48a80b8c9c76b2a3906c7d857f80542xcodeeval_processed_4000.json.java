import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class id6 {
  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);
    id3 solver = new id3();
    int n = in.nextInt();
    for (int i = 0; i < n; i++) {
      solver.solve(i, in, out);
    }
    out.close();
  }

  static class id3 {
    public static final int[][][][] id2 = new int[2][2][3][6];

    public static final int[][][][][][] id4 = new int[2][2][2][2][2][6];

    public static final int[][] id1 = new int[][]{
        {0, 1, 1, 0, 1, 1}, {0, 0, 0, 1, 1, 0}, {0, 0, 1, 0, 1, 1}, {0, 0, 0, 1, 1, 1}
    };

    private void id0(int[][][][] id2) {
      Set<Integer> set = new HashSet<>();

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i == 0 && j == 0) {
            id2[i][j] = new int[][]{
                {0, 0, 0, 1, 1, 0}, {0, 1, 0, 0, 1, 1}, {0, 0, 1, 0, 1, 1}
            };
          } else if (i == 0 && j == 1) {
            id2[i][j] = new int[][]{
                {0, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 1}, {0, 1, 1, 0, 1, 1}
            };
          } else if (i == 1 && j == 0) {
            id2[i][j] = new int[][]{
                {0, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 1, 1}
            };
          } else if (i == 1 && j == 1) {
            id2[i][j] = new int[][]{
                {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 1, 1}, {0, 0, 1, 0, 1, 1}
            };
          }
        
        }
      }
    }

    private void id5(int[][][][][][] id4) {
      Set<Integer> set = new HashSet<>();

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          set.add(i * 2 + j);
          for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
              if (i == x && j == y) {
                continue;
              }

              if (i == 0 && j == 0 && x == 0 && y == 1) {
                id4[i][j][x][y] = new int[][]{
                    {0, 0, 1, 0, 1, 1}, {0, 1, 1, 0, 1, 1}
                };
              } else if (i == 0 && j == 0 && x == 1 && y == 0) {
                id4[i][j][x][y] = new int[][]{
                    {0, 0, 0, 1, 1, 1}, {1, 0, 0, 1, 1, 1}
                };
              } else if (i == 0 && j == 0 && x == 1 && y == 1) {
                id4[i][j][x][y] = new int[][]{
                    {0, 0, 1, 0, 0, 1}, {1, 1, 1, 0, 0, 1}
                };
              } else if (i == 0 && j == 1 && x == 1 && y == 0) {
                id4[i][j][x][y] = new int[][]{
                    {0, 1, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 1}
                };
              } else if (i == 0 && j == 1 && x == 1 && y == 1) {
                id4[i][j][x][y] = new int[][]{
                    {0, 1, 1, 0, 0, 0}, {1, 1, 1, 0, 0, 0}
                };
              } else if (i == 1 && j == 0 && x == 1 && y == 1) {
                id4[i][j][x][y] = new int[][]{
                    {1, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 1}
                };
              }

              
            }
          }
        }
      }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int n = in.nextInt(), m = in.nextInt();
      char[][] b = new char[n][m];
      for (int i = 0; i < n; i++) {
        String s = in.next();
        b[i] = s.toCharArray();
      }

      id0(id2);
      id5(id4);

      
      List<List<Integer>> res = new ArrayList<>();

      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
          
          List<Integer> tmp = new ArrayList<>();
          if (i != n - 2) {
            

            if (b[i][j] == '0' && b[i][j + 1] == '0') {
              continue;
            }
            

            if (b[i][j] == '1') {
              tmp.add(i+1);
              tmp.add(j+1);
              b[i][j] = '0';
            }
            if (b[i][j+1] == '1') {
              tmp.add(i+1);
              tmp.add(j+2);
              b[i][j+1] = '0';
            }
            if (tmp.size() == 2) {
              tmp.add(i + 2);
              tmp.add(j + 1);
              tmp.add(i + 2);
              tmp.add(j + 2);
              b[i+1][j] = (b[i+1][j] == '1') ? '0' : '1';
              b[i+1][j+1] = (b[i+1][j+1] == '1') ? '0' : '1';
            } else {
              if (b[i + 1][j] == '1') {
                tmp.add(i + 2);
                tmp.add(j + 1);
                b[i+1][j] = '0';
              }
              if (tmp.size() == 4 && b[i + 1][j+1] == '1') {
                tmp.add(i + 2);
                tmp.add(j + 2);
                b[i+1][j+1] = '0';
              }
              if (tmp.size() == 4) {
                tmp.add(i + 2);
                tmp.add(j + 2);
                b[i+1][j+1] = (b[i+1][j+1] == '1') ? '0' : '1';
              }
            }
            res.add(tmp);
          } else if (j != m - 2) {
            

            if (b[i][j] == '0' && b[i+1][j] == '0') {
              continue;
            }
            

            if (b[i][j] == '1') {
              tmp.add(i+1);
              tmp.add(j+1);
              b[i][j] = '0';
            }
            if (b[i+1][j] == '1') {
              tmp.add(i+2);
              tmp.add(j+1);
              b[i+1][j] = '0';
            }
            if (tmp.size() == 2) {
              tmp.add(i + 1);
              tmp.add(j + 2);
              tmp.add(i + 2);
              tmp.add(j + 2);
              b[i][j+1] = (b[i][j+1] == '1') ? '0' : '1';
              b[i+1][j+1] = (b[i+1][j+1] == '1') ? '0' : '1';
            } else {
              if (b[i][j+1] == '1') {
                tmp.add(i + 1);
                tmp.add(j + 2);
                b[i][j+1] = '0';
              }
              if (tmp.size() == 4 && b[i + 1][j+1] == '1') {
                tmp.add(i + 2);
                tmp.add(j + 2);
                b[i+1][j+1] = '0';
              }
              if (tmp.size() == 4) {
                tmp.add(i + 2);
                tmp.add(j + 2);
                b[i+1][j+1] = (b[i+1][j+1] == '1') ? '0' : '1';
              }
            }
            res.add(tmp);
          } else {
            


            tmp.clear();
            for (int k = 0; k < 2; k++) {
              for (int l = 0; l < 2; l++) {
                if (b[i+k][j+l] == '1') {
                  tmp.add(i+k+1);
                  tmp.add(j+l+1);
                }
              }
            }
            if (tmp.size() == 6) {
              res.add(tmp);
              for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                  b[i+k][j+l] = '0';
                }
              }
            } else {
              res.addAll(genSeq(i, j, b));
            }
          }

          
          
        }
      }

      out.println(res.size());
      for (List<Integer> item : res) {
        for (int i = 0; i < 6; i++) {
          if (i > 0) {
            out.print(" ");
          }
          out.print(item.get(i));
        }
        out.println();
      }
    }

    private List<List<Integer>> genSeq(int x, int y, char[][] b) {
      List<List<Integer>> res = new ArrayList<>();
      int cnt = 0;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (b[x+i][y+j] == '1') {
            cnt++;
          }
        }
      }

      if (cnt == 1) {
        int x1 = -1, y1 = -1;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (b[x+i][y+j] == '1') {
              x1 = i;
              y1 = j;
            }
          }
        }

        for (int[] item : id2[x1][y1]) {
          List<Integer> list = new ArrayList<>();
          for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
              list.add(x + item[i] + 1);
            } else {
              list.add(y + item[i] + 1);
            }
          }
          res.add(list);
        }
      } else if (cnt == 2) {
        int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (b[x+i][y+j] == '1') {
              if (x1 < 0) {
                x1 = i;
                y1 = j;
              } else {
                x2 = i;
                y2 = j;
              }
            }
          }
        }
        for (int[] item : id4[x1][y1][x2][y2]) {
          List<Integer> list = new ArrayList<>();
          for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
              list.add(x + item[i] + 1);
            } else {
              list.add(y + item[i] + 1);
            }
          }
          res.add(list);
        }
      } else if (cnt == 4) {
        for (int[] item : id1) {
          List<Integer> list = new ArrayList<>();
          for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) {
              list.add(x + item[i] + 1);
            } else {
              list.add(y + item[i] + 1);
            }
          }
          res.add(list);
        }
      }

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          b[x+i][y+j] = '0';
        }
      }
      return res;
    }
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}