import java.io.*;
import java.util.*;

public class id1 {
    
    private final static boolean DEBUG = false;
    private final static String[] DEBUG_INPUT = {
















            "((4?3)?(((2?(4?((4?((2?(3?(7?3)))?(((((3?(6?2))?3)?(((((6?6)?(1?5))?((8?8)?1))?(5?((7?((6?((((3?8)?8)?(8?5))?7))?8))?((8?(2?8))?3))))?6))?(8?(7?5)))?8)))?((((7?(4?3))?4)?5)?((1?(((2?2)?((((4?((7?6)?(1?4)))?(8?(1?(((1?3)?(((2?2)?(3?(8?(9?((2?(4?6))?(7?8))))))?(9?(7?9))))?(7?3)))))?((2?((2?((8?6)?1))?(3?1)))?(7?1)))?5))?((((6?(9?(((5?4)?7)?((5?8)?8))))?5)?7)?(2?2))))?4)))))?2)?(7?(4?((6?6)?6)))))\n" +
                    "50 49",




    };



    
    

    

    

    

    

    private static class Solver {
        private static final int MIN = -9 * 10_000;
        private static final int MAX = 9 * 10_000;
        public void solve(Reader in, PrintWriter out) throws IOException {
            char[] ex = in.nextWord().toCharArray();
            int plus = in.nextInt();
            int minus = in.nextInt();



            int mine = solve(ex, plus, minus);
            out.print(mine);










        }

        private int solve(char[] ex, int plus, int minus) {
            Map<Integer, int[]> map = new HashMap<>(); 

            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < ex.length; i++) {
                if (ex[i] == '(') {
                    stack.push(i);
                    map.put(i, new int[3]);
                } else if (ex[i] == '?') {
                    map.get(stack.peek())[0] = i;
                } else if (ex[i] == ')') {
                    map.get(stack.peek())[1] = i;
                    stack.pop();
                }
            }

            count(0, ex.length-1, map);

            int id4 = Math.min(plus, minus);

            int[][][] dp = new int[ex.length][id4+1][2]; 

            for (int i = 0; i < ex.length; i++) {
                for (int j = 0; j < id4 + 1; j++) {
                    dp[i][j][0] = MAX;
                    dp[i][j][1] = MIN;
                }
            }

            int res = go(map, dp, ex, id4 == plus ? 1 : 0, id4, 1, 0);




















            return res;
        }

        private int go(Map<Integer, int[]> map, int[][][] dp, char[] ex, int minSign, int id4, int sign, int left) {
            int[] info = map.get(left);
            if (info == null) return ex[left] - '0';

            int id2 = info[2];
            int mid = info[0];
            int[] leftInfo = map.get(left + 1);
            int id3 = leftInfo == null ? 0 : leftInfo[2];
            int[] rightInfo = map.get(mid+1);
            int id0 = rightInfo == null ? 0 : rightInfo[2];
            int from, to;

            if (sign == 1) { 

                if (dp[left][id4][1] != MIN) return dp[left][id4][1];

                int res = MIN;
                if (minSign == 0) { 

                    

                    from = Math.max(0, id4-1 - id0);
                    to = Math.min(id4-1, id3);
                    for (int i = from; i <= to; i++) {
                        res = Math.max(
                                res, go(map, dp, ex, minSign, i, 1, left + 1) - go(map, dp, ex, minSign, id4-1 - i, 0, mid + 1)
                        );
                    }
                    

                    if (id2 > id4) {
                        from = Math.max(0, id4 - id0);
                        to = Math.min(id4, id3);
                        for (int i = from; i <= to; i++) {
                            res = Math.max(
                                    res, go(map, dp, ex, minSign, i, 1, left + 1) + go(map, dp, ex, minSign, id4 - i, 1, mid + 1) 

                            );
                        }
                    }
                } else { 

                    if (id2 > id4) {
                        from = Math.max(0, id4 - id0);
                        to = Math.min(id4, id3);
                        for (int i = from; i <= to; i++) {
                            res = Math.max(
                                    res, go(map, dp, ex, minSign, i, 1, left + 1) - go(map, dp, ex, minSign, id4 - i, 0, mid + 1) 

                            );
                        }
                    }
                    from = Math.max(0, id4-1 - id0);
                    to = Math.min(id4-1, id3);
                    for (int i = from; i <= to; i++) {
                        res = Math.max(
                                res, go(map, dp, ex, minSign, i, 1, left + 1) + go(map, dp, ex, minSign, id4-1 - i, 1, mid + 1) 

                        );
                    }
                }
                dp[left][id4][1] = res;
                return res;
            } else { 

                if (dp[left][id4][0] != MAX) return dp[left][id4][0];

                int res = MAX;
                if (minSign == 0) { 

                    from = Math.max(0, id4-1 - id0);
                    to = Math.min(id4-1, id3);
                    for (int i = from; i <= to; i++) {
                        res = Math.min(
                                res, go(map, dp, ex, minSign, i, 0, left + 1) - go(map, dp, ex, minSign, id4-1 - i, 1, mid + 1) 

                        );
                    }
                    if (id2 > id4) {
                        from = Math.max(0, id4 - id0);
                        to = Math.min(id4, id3);
                        for (int i = from; i <= to; i++) {
                            res = Math.min(
                                    res, go(map, dp, ex, minSign, i, 0, left + 1) + go(map, dp, ex, minSign, id4 - i, 0, mid + 1) 

                            );
                        }
                    }
                } else { 

                    from = Math.max(0, id4 - id0);
                    to = Math.min(id4, id3);
                    if (id2 > id4) {
                        for (int i = from; i <= to; i++) {
                            res = Math.min(
                                    res, go(map, dp, ex, minSign, i, 0, left + 1) - go(map, dp, ex, minSign, id4 - i, 1, mid + 1) 

                            );
                        }
                    }
                    from = Math.max(0, id4-1 - id0);
                    to = Math.min(id4-1, id3);
                    for (int i = from; i <= to; i++) {
                        res = Math.min(
                                res, go(map, dp, ex, minSign, i, 0, left + 1) + go(map, dp, ex, minSign, id4-1 - i, 0, mid + 1) 

                        );
                    }
                }
                dp[left][id4][0] = res;
                return res;
            }
        }

        private int count(int left, int right, Map<Integer, int[]> map) {
            if (left == right) return 0;
            int[] info = map.get(left);
            info[2] = 1 + count(left+1, info[0]-1, map) + count(info[0]+1, right-1, map);
            return info[2];
        }
    }

    
    public static void main(String[] args) throws IOException {
        PrintWriter out = null;
        Reader in;
        if (DEBUG) {
            for (String s : DEBUG_INPUT) {
                in = new Reader(new ByteArrayInputStream(s.getBytes()));
                out = new PrintWriter(System.out);
                out.println("===>>> INPUT");
                out.println(s + "\n\n");
                out.println("===>>> OUTPUT");
                long start = System.currentTimeMillis();
                new Solver().solve(in, out);
                long end = System.currentTimeMillis();
                out.println("\n");
                out.println("===========");
                out.println("Took: " + (end - start) + "ms");
                out.println("====================================================================");
                out.println();
                out.println();
                out.flush();
            }
        } else {
            in = new Reader(System.in);
            out = new PrintWriter(System.out);
            new Solver().solve(in, out);
        }
        if (out != null) out.flush();
    }

    
    private static class Reader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public Reader(InputStream input) {
            reader = new BufferedReader(
                    new InputStreamReader(input));
            tokenizer = new StringTokenizer("");
        }

        private String nextWord() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        private int nextInt() throws IOException {
            return Integer.parseInt(nextWord());
        }

        private long nextLong() throws IOException {
            return Long.parseLong(nextWord());
        }

        private double nextDouble() throws IOException {
            return Double.parseDouble(nextWord());
        }
    }
}























































































































































































































































































































































































































































