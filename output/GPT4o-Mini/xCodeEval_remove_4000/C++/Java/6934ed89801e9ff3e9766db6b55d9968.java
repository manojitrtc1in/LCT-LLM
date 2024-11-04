import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class id32 {
    // Define the necessary types and classes here
    // ...

    public id32(long numNodes, long id13) {
        // Constructor implementation
    }

    public void setArc(long id10, long id28, long lowBound, long upBound, long cost) {
        // Method implementation
    }

    public void setSupplyDemandOfNode(long id, long excess) {
        // Method implementation
    }

    public void runCs2() {
        // Method implementation
    }

    // Other methods...
}

public class 6934ed89801e9ff3e9766db6b55d9968xcodeeval_processed_4000.json {
    static int n, m;

    static int f(int r, int c) {
        return r * m + c + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        int[][] grid = new int[n][m];
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        List<Integer> c = new ArrayList<>();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                grid[i][j] = scanner.nextInt();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if ((i + j) % 2 != 0) {
                    if (i > 0) {
                        a.add(f(i, j));
                        b.add(f(i - 1, j));
                        c.add(grid[i][j] != grid[i - 1][j] ? 1 : 0);
                    }
                    if (j > 0) {
                        a.add(f(i, j));
                        b.add(f(i, j - 1));
                        c.add(grid[i][j] != grid[i][j - 1] ? 1 : 0);
                    }
                    if (i + 1 < n) {
                        a.add(f(i, j));
                        b.add(f(i + 1, j));
                        c.add(grid[i][j] != grid[i + 1][j] ? 1 : 0);
                    }
                    if (j + 1 < m) {
                        a.add(f(i, j));
                        b.add(f(i, j + 1));
                        c.add(grid[i][j] != grid[i][j + 1] ? 1 : 0);
                    }
                }

        int numNodes = n * m * 4;
        int id13 = a.size();

        id32 id8 = new id32(numNodes, id13);
        for (int i = 0; i < id13; ++i)
            id8.setArc(a.get(i), b.get(i), 0, 1, c.get(i));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if ((i + j) % 2 != 0) {
                    id8.setSupplyDemandOfNode(f(i, j), 1);
                } else {
                    id8.setSupplyDemandOfNode(f(i, j), -1);
                }
        id8.runCs2();
    }
}
