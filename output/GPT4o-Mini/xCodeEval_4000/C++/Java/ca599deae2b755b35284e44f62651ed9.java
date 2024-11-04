import java.util.*;
import java.util.stream.Collectors;

public class ca599deae2b755b35284e44f62651ed9_nc {

    static class ScopeTimer {
        private final long tic;
        private final String msg;

        public ScopeTimer(String msg) {
            this.tic = System.currentTimeMillis();
            this.msg = msg;
        }

        @Override
        protected void finalize() {
            long toc = System.currentTimeMillis();
            long dt = toc - tic;

            long mil = dt % 1000;
            long sec = (dt / 1000) % 60;
            long min = (dt / 60000) % 60;
            long hrs = (dt / 3600000);

            System.out.println("\n" + msg + "\n\telapsed time: ");
            if (hrs > 0) System.out.print(hrs + " hrs, ");
            if (min > 0) System.out.print(min + " min, ");
            if (sec > 0) System.out.print(sec + " sec, ");
            System.out.println(mil + " mil-sec");
        }
    }

    static int c132() {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        int n = scanner.nextInt();

        int[][] soln = new int[2][n + 1];
        int[][] xsoln = new int[2][n + 1];

        if (str.charAt(str.length() - 1) == 'F') {
            for (int j = 0; j < n + 1; ++j)
                soln[0][j] = j % 2 == 0 ? 1 : 0;
        } else {
            for (int j = 0; j < n + 1; ++j)
                soln[0][j] = j % 2 == 0 ? 0 : 1;
        }

        System.arraycopy(soln[0], 0, soln[1], 0, soln[0].length);

        for (int iter = str.length() - 2; iter >= 0; --iter) {
            int[][] temp = xsoln;
            xsoln = soln;
            soln = temp;

            if (str.charAt(iter) == 'F') {
                soln[0][0] = 1 + xsoln[0][0];
                soln[1][0] = 1 + xsoln[1][0];

                for (int j = 1; j < n + 1; ++j) {
                    soln[0][j] = Math.max(1 + xsoln[0][j], -xsoln[1][j - 1]);
                    soln[1][j] = Math.min(1 + xsoln[1][j], -xsoln[0][j - 1]);
                }
            } else {
                soln[0][0] = -xsoln[1][0];
                soln[1][0] = -xsoln[0][0];

                for (int j = 1; j < n + 1; ++j) {
                    soln[0][j] = Math.max(-xsoln[1][j], 1 + xsoln[0][j - 1]);
                    soln[1][j] = Math.min(-xsoln[0][j], 1 + xsoln[1][j - 1]);
                }
            }
        }

        return Math.max(soln[0][n], -soln[1][n]);
    }

    static int sched(int i, List<Integer> m, List<List<Integer>> rev, List<Integer> deps, List<List<Integer>> load) {
        int val = 0;
        List<Integer> unload;

        for (int n = m.size(); n > 0; i = (i + 1) % 3, ++val) {
            while (!load.get(i).isEmpty()) {
                n -= load.get(i).size();

                unload = new ArrayList<>(load.get(i));
                load.set(i, new ArrayList<>());

                for (int j : unload) {
                    for (int k : rev.get(j)) {
                        deps.set(k, deps.get(k) - 1);
                        if (deps.get(k) == 0) {
                            load.get(m.get(k)).add(k);
                        }
                    }
                }
            }
        }

        return val - 1;
    }

    static int a213() {
        Scanner scanner = new Scanner(System.in);
        List<Integer> m = Arrays.stream(scanner.nextLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        m.replaceAll(x -> x - 1);

        int n = m.size();
        List<List<Integer>> rev = new ArrayList<>(Collections.nCopies(n, new ArrayList<>()));
        List<Integer> deps = new ArrayList<>(Collections.nCopies(n, 0));

        for (int j = 0; j < n; ++j) {
            List<Integer> xs = Arrays.stream(scanner.nextLine().split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());

            deps.set(j, xs.size());

            for (int i : xs) {
                rev.get(i - 1).add(j);
            }
        }

        List<List<Integer>> load = new ArrayList<>(Collections.nCopies(3, new ArrayList<>()));
        for (int j = 0; j < n; ++j) {
            if (deps.get(j) == 0) {
                load.get(m.get(j)).add(j);
            }
        }

        return Math.min(Math.min(sched(0, m, rev, deps, load),
                sched(1, m, rev, deps, load)),
                sched(2, m, rev, deps, load)) + n;
    }

    public static void main(String[] args) {
        System.out.println(a213());
    }
}
