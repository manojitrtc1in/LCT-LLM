import java.util.*;

class Main {
    static int nA, nB, nV, len, mx = 0, cans;
    static int[][][] d = new int[101][101][101];
    static int[][][] c = new int[101][101][101];
    static int[][] prefix = new int[101][1001];
    static String A, B, V, t;
    static Stack<Character> ans = new Stack<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        nA = scanner.nextInt();
        nB = scanner.nextInt();
        nV = scanner.nextInt();
        A = scanner.next();
        B = scanner.next();
        V = scanner.next();
        A = " " + A;
        B = " " + B;
        V = " " + V;

        for (int iV = 0; iV < nV; iV++) {
            for (char C = 'A'; C <= 'Z'; C++) {
                prefix[iV][C] = iV + 1;
                while (prefix[iV][C] > 0) {
                    if (V.substring(1, prefix[iV][C]).equals(V.substring(iV + 2 - prefix[iV][C], iV + 1) + C)) {
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
                    if (d[iA - 1][iB][iV] > d[iA][iB][iV]) {
                        d[iA][iB][iV] = d[iA - 1][iB][iV];
                        c[iA][iB][iV] = -1;
                    }
                    if (d[iA][iB - 1][iV] > d[iA][iB][iV]) {
                        d[iA][iB][iV] = d[iA][iB - 1][iV];
                        c[iA][iB][iV] = -2;
                    }
                }
                for (int iV = 0; iV < nV; iV++) {
                    if (A.charAt(iA) == B.charAt(iB)) {
                        if (d[iA - 1][iB - 1][iV] + 1 > d[iA][iB][prefix[iV][A.charAt(iA)]]) {
                            d[iA][iB][prefix[iV][A.charAt(iA)]] = d[iA - 1][iB - 1][iV] + 1;
                            c[iA][iB][prefix[iV][A.charAt(iA)]] = iV;
                        }
                    }
                }
            }
        }

        for (int iV = 0; iV < nV; iV++) {
            if (d[nA][nB][iV] > mx) {
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
}
