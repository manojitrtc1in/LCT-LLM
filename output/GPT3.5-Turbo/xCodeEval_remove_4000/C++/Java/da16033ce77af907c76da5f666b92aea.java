import java.util.*;
import java.io.*;

class Main {
    static long pi = 2 * Math.acos(0.0);
    static int id1, test_case = 1;
    static ArrayList<ArrayList<Long>> main_array;
    static ArrayList<ArrayList<Long>> dp_table;

    static void function_name() {
        Scanner sc = new Scanner(System.in);
        int array_number = sc.nextInt();
        int operation_number = sc.nextInt();

        ArrayList<ArrayList<Long>> id3 = new ArrayList<>(operation_number);
        for (int i = 0; i < operation_number; i++) {
            id3.add(new ArrayList<>(Collections.nCopies(array_number, 0L)));
        }

        main_array = new ArrayList<>(array_number);
        for (int i = 0; i < array_number; i++) {
            main_array.add(new ArrayList<>(Collections.nCopies(operation_number, 0L)));
        }

        int maximum = 0;
        dp_table = new ArrayList<>(array_number);
        for (int i = 0; i < array_number; i++) {
            dp_table.add(new ArrayList<>(Collections.nCopies(operation_number + 1, (long) maximum)));
        }

        for (int i = 0; i < array_number; i++) {
            int element_number = sc.nextInt();
            for (int j = 0; j < element_number; j++) {
                long element = sc.nextLong();
                if (j < operation_number) {
                    main_array.get(i).set(j, element + (j > 0 ? main_array.get(i).get(j - 1) : 0));
                    id3.get(j).set(i, main_array.get(i).get(j));
                }
            }
        }

        for (int i = 0; i < operation_number; i++) {
            Collections.sort(id3.get(i), Collections.reverseOrder());
        }

        for (int i = 0; i < array_number; i++) {
            for (int j = 0; j < operation_number; j++) {
                if (main_array.get(i).get(j) < id3.get(j).get(Math.min(operation_number / (j + 1), array_number - 1))) {
                    main_array.get(i).set(j, 0L);
                }
            }
        }

        for (int id0 = 0; id0 < array_number; id0++) {
            if (id0 > 0) {
                dp_table.set(id0, new ArrayList<>(dp_table.get(id0 - 1)));
            }

            for (int id2 = 0; id2 < operation_number; id2++) {
                if (main_array.get(id0).get(id2) != 0) {
                    for (int operation_left = operation_number, old = operation_number - (id2 + 1); operation_left > id2; operation_left--, old--) {
                        if (id0 == 0) {
                            dp_table.get(id0).set(operation_left, Math.max(dp_table.get(id0).get(operation_left), main_array.get(id0).get(id2)));
                        } else {
                            dp_table.get(id0).set(operation_left, Math.max(dp_table.get(id0).get(operation_left), main_array.get(id0).get(id2) + dp_table.get(id0 - 1).get(old)));
                        }
                    }
                }
            }
        }

        long answer = dp_table.get(array_number - 1).get(operation_number);
        System.out.println(answer);
    }

    static void function_name(int v1, int v2, int v3) {

    }

    static void function_name(String line) {

    }

    static class InitialWorks {
        void withTestCaseNumber() {
            Scanner sc = new Scanner(System.in);
            id1 = sc.nextInt();

            while (test_case <= id1) {
                function_name();
                test_case++;
            }
        }

        void singleIteration() {
            function_name();
        }

        void withoutTestCaseNumber() {
            Scanner sc = new Scanner(System.in);
            int v1, v2, v3;
            while ((v1 = sc.nextInt()) != 0) {
                v2 = sc.nextInt();
                v3 = sc.nextInt();
                function_name(v1, v2, v3);
                test_case++;
            }
        }

        void eoof() {
            Scanner sc = new Scanner(System.in);
            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                function_name(line);
                test_case++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        InitialWorks a = new InitialWorks();
        a.singleIteration();
    }
}
