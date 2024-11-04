import java.util.*;

public class ded83978f81fc80d57edb2f50897ea7fxcodeeval_processed_4000.json {
    static int nA, nB, nV, mx = 0, cans;
    static int[][][] d = new int[101][101][101];
    static int[][][] c = new int[101][101][101];
    static int[][] prefix = new int[101][1001];
    static String A, B, V;
    static Stack<Character> ans = new Stack<>();

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        A = scanner.nextLine();
        B = scanner.nextLine();
        V = scanner.nextLine();
        nA = A.length();
        nB = B.length();
        nV = V.length();

        for (int iV = 0; iV < nV; iV++) {
            for (char C = 'A'; C <= 'Z'; C++) {
                prefix[iV][C] = iV + 1;
                while (prefix[iV][C] > 0) {
                    if (V.substring(0, prefix[iV][C]).equals(V.substring(iV + 2 - prefix[iV][C], prefix[iV][C] - 1) + C)) {
                        break;
                    }
                    prefix[iV][C]--;
                }
            }
        }

        for (int iA = 1; iA <= nA; iA++) {
            for (int iB = 1; iB <= nB; iB++) {
                for (int iV = 0; iV < nV; iV++) {
                    d[iA][iB][iV] = -1;
                    if (d[iA][iB][iV] < d[iA - 1][iB][iV]) {
                        d[iA][iB][iV] = d[iA - 1][iB][iV];
                        c[iA][iB][iV] = -1;
                    }
                    if (d[iA][iB][iV] < d[iA][iB - 1][iV]) {
                        d[iA][iB][iV] = d[iA][iB - 1][iV];
                        c[iA][iB][iV] = -2;
                    }
                }
                for (int iV = 0; iV < nV; iV++) {
                    if (A.charAt(iA - 1) == B.charAt(iB - 1)) {
                        if (d[iA][iB][prefix[iV][A.charAt(iA - 1)]] < d[iA - 1][iB - 1][iV] + 1) {
                            d[iA][iB][prefix[iV][A.charAt(iA - 1)]] = d[iA - 1][iB - 1][iV] + 1;
                            c[iA][iB][prefix[iV][A.charAt(iA - 1)]] = iV;
                        }
                    }
                }
            }
        }

        for (int iV = 0; iV < nV; iV++) {
            if (mx < d[nA][nB][iV]) {
                mx = d[nA][nB][iV];
                cans = iV;
            }
        }

        if (mx == 0) {
            System.out.println(0);
        } else {
            int iA = nA, iB = nB, iV = cans;
            while (iA > 0 && iB > 0) {
                if (c[iA][iB][iV] == -1) {
                    iA--;
                } else if (c[iA][iB][iV] == -2) {
                    iB--;
                } else {
                    ans.push(A.charAt(iA - 1));
                    iV = c[iA][iB][iV];
                    iA--;
                    iB--;
                }
            }
        }

        while (!ans.isEmpty()) {
            System.out.print(ans.pop());
        }
        System.out.println();
    }

    static void prep() {
        // Preparation logic if needed
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        prep();
        if (scanner.hasNextInt()) {
            int test_num = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            for (int test_count = 1; test_count <= test_num; test_count++) {
                System.out.printf("Case %d:\n", test_count);
                solve();
            }
        } else {
            solve();
        }
    }
}
