import java.util.*;
import java.io.*;

class Main {
    static int id9(int[] arr, int n, int key) {
        int left = 0;
        int right = n - 1;

        int count = 0;

        while (left <= right) {
            int mid = (right + left) / 2;

            if (arr[mid] <= key) {
                count = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return count;
    }

    static int countGreater(int[] arr, int n, int k) {
        int l = 0;
        int r = n - 1;

        int leftGreater = n;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] >= k) {
                leftGreater = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return (n - leftGreater);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = br.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        String[] lStr = br.readLine().split(" ");
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(lStr[i]) % k;
        }
        if (n == 1) {
            System.out.println(l[0]);
            System.exit(0);
        }
        int[] l1 = Arrays.copyOfRange(l, 0, n / 2);
        int[] l2 = Arrays.copyOfRange(l, n / 2, n);
        Set<Integer> s = new HashSet<>();
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        for (int i = 0; i < n / 2; i++) {
            for (int j : s) {
                s2.add((j + l1[i]) % k);
            }
            s.add(l1[i]);
            for (int j : s2) {
                s.add(j);
            }
            s2.clear();
        }
        for (int i = 0; i < n - n / 2; i++) {
            for (int j : s1) {
                s2.add((j + l2[i]) % k);
            }
            s1.add(l2[i]);
            for (int j : s2) {
                s1.add(j);
            }
            s2.clear();
        }
        List<Integer> sList = new ArrayList<>(s);
        List<Integer> s1List = new ArrayList<>(s1);
        Collections.sort(sList);
        Collections.sort(s1List);
        int ans = Math.max(Collections.max(sList), Collections.max(s1List));
        for (int i = 0; i < sList.size(); i++) {
            int t = k - 1 - sList.get(i);
            int ind = id9(s1List.stream().mapToInt(Integer::intValue).toArray(), s1List.size(), t);
            int r = s1List.get(ind - 1);
            int rt = s1List.get(s1List.size() - 1);
            int temp = ans;
            ans = Math.max((r + sList.get(i)) % k, (sList.get(i) + rt) % k);
            ans = Math.max(ans, temp);
        }
        System.out.println(ans);
    }
}
