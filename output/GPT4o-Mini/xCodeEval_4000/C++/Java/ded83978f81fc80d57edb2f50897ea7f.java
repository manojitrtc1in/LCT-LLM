import java.util.*;
import java.io.*;

public class ded83978f81fc80d57edb2f50897ea7f_nc {
    static int nA, nB, nV, mx = 0, cans;
    static int[][][] d = new int[101][101][101];
    static int[][][] c = new int[101][101][101];
    static int[][] prefix = new int[101][1001];
    static String A, B, V;
    static Stack<Character> ans = new Stack<>();

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        A = scanner.next();
        B = scanner.next();
        V = scanner.next();
        nA = A.length();
        nB = B.length();
        nV = V.length();
        A = "#" + A + "#";
        B = "#" + B + "#";
        V = "#" + V + "#";

        for (int iV = 0; iV < nV; iV++) {
            for (char C = 'A'; C <= 'Z'; C++) {
                prefix[iV][C] = iV + 1;
                while (prefix[iV][C] > 0) {
                    if (V.substring(1, prefix[iV][C]).equals(V.substring(iV + 2 - prefix[iV][C], prefix[iV][C] - 1) + C)) {
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
                    if (maxSet(d[iA][iB][iV], d[iA - 1][iB][iV])) c[iA][iB][iV] = -1;
                    if (maxSet(d[iA][iB][iV], d[iA][iB - 1][iV])) c[iA][iB][iV] = -2;
                }
                for (int iV = 0; iV < nV; iV++) {
                    if (A.charAt(iA) == B.charAt(iB)) {
                        maxSet(d[iA][iB][prefix[iV][A.charAt(iA)]], d[iA - 1][iB - 1][iV] + 1);
                        if (c[iA][iB][prefix[iV][A.charAt(iA)]] == 0) c[iA][iB][prefix[iV][A.charAt(iA)]] = iV;
                    }
                }
            }
        }

        for (int iV = 0; iV < nV; iV++) {
            maxSet(mx, d[nA][nB][iV]);
            if (mx == d[nA][nB][iV]) cans = iV;
        }

        if (mx == 0) {
            System.out.print(0);
        } else {
            int iA = nA, iB = nB, iV = cans;
            while (iA > 0 && iB > 0) {
                if (c[iA][iB][iV] == -1) {
                    iA--;
                } else if (c[iA][iB][iV] == -2) {
                    iB--;
                } else {
                    ans.push(A.charAt(iA));
                    iV = c[iA][iB][iV];
                    iA--;
                    iB--;
                }
            }
        }

        while (!ans.isEmpty()) {
            System.out.print(ans.pop());
        }
    }

    static boolean maxSet(int a, int b) {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        solve();
    }
}
