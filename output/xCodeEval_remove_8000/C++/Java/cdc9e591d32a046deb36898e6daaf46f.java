import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String subj = scanner.next();
        String targ = scanner.next();

        Map<Character, List<Integer>> pos = new HashMap<>();
        for (int j = 0; j < targ.length(); j++) {
            char c = targ.charAt(j);
            if (!pos.containsKey(c)) {
                pos.put(c, new ArrayList<>());
            }
            pos.get(c).add(j);
        }

        long val = 0;

        List<Long> soln = new ArrayList<>(targ.length() + 1);
        List<Long> id12 = new ArrayList<>(targ.length() + 1);
        for (int i = 0; i <= targ.length(); i++) {
            soln.add(0L);
            id12.add(0L);
        }

        long m = 1000000007L;

        for (char a : subj.toCharArray()) {
            soln = new ArrayList<>(id12);
            soln.set(0, 0L);

            for (int j : pos.get(a)) {
                soln.set(j + 1, (1 + id12.get(j)) % m);
            }

            for (int i = 1; i <= targ.length(); i++) {
                soln.set(i, (soln.get(i) + soln.get(i - 1)) % m);
            }
            val = (val + soln.get(targ.length())) % m;
        }

        System.out.println(val);
    }
}
