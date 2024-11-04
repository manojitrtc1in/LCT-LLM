import java.util.*;
import java.io.*;

class Main {
    static int test_case_number, test_case = 1;
    static List<List<Long>> main_array;
    static List<List<Long>> dp_table;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read the test case number
        test_case_number = Integer.parseInt(br.readLine());

        while (test_case <= test_case_number) {
            function_name();
            test_case++;
        }
    }

    static void function_name() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int array_number = Integer.parseInt(input[0]);
        int operation_number = Integer.parseInt(input[1]);

        List<List<Long>> reversed_array = new ArrayList<>();
        for (int i = 0; i < operation_number; i++) {
            reversed_array.add(new ArrayList<>());
            for (int j = 0; j < array_number; j++) {
                reversed_array.get(i).add(0L);
            }
        }

        main_array = new ArrayList<>();
        for (int i = 0; i < array_number; i++) {
            main_array.add(new ArrayList<>());
            for (int j = 0; j < operation_number; j++) {
                main_array.get(i).add(0L);
            }
        }

        int maximum = 0;
        dp_table = new ArrayList<>();
        for (int i = 0; i < array_number; i++) {
            dp_table.add(new ArrayList<>());
            for (int j = 0; j < operation_number + 1; j++) {
                dp_table.get(i).add((long) maximum);
            }
        }

        for (int i = 0; i < array_number; i++) {
            String[] elements = br.readLine().split(" ");
            int element_number = Integer.parseInt(elements[0]);
            for (int j = 1; j <= element_number; j++) {
                long element = Long.parseLong(elements[j]);
                if (j <= operation_number) {
                    main_array.get(i).set(j - 1, element + (j > 1 ? main_array.get(i).get(j - 2) : 0));
                    reversed_array.get(j - 1).set(i, main_array.get(i).get(j - 1));
                }
            }
        }

        for (int i = 0; i < operation_number; i++) {
            Collections.sort(reversed_array.get(i), Collections.reverseOrder());
        }

        for (int i = 0; i < array_number; i++) {
            for (int j = 0; j < operation_number; j++) {
                if (main_array.get(i).get(j) < reversed_array.get(j).get(Math.min(operation_number / (j + 1), array_number - 1))) {
                    main_array.get(i).set(j, 0L);
                }
            }
        }

        for (int current_array_no = 0; current_array_no < array_number; current_array_no++) {
            if (current_array_no > 0) {
                dp_table.set(current_array_no, new ArrayList<>(dp_table.get(current_array_no - 1)));
            }

            for (int current_column_no = 0; current_column_no < operation_number; current_column_no++) {
                if (main_array.get(current_array_no).get(current_column_no) != 0) {
                    for (int operation_left = operation_number, old = operation_number - (current_column_no + 1); operation_left > current_column_no; operation_left--, old--) {
                        if (current_array_no == 0) {
                            dp_table.get(current_array_no).set(operation_left, Math.max(dp_table.get(current_array_no).get(operation_left), main_array.get(current_array_no).get(current_column_no)));
                        } else {
                            dp_table.get(current_array_no).set(operation_left, Math.max(dp_table.get(current_array_no).get(operation_left), main_array.get(current_array_no).get(current_column_no) + dp_table.get(current_array_no - 1).get(old)));
                        }
                    }
                }
            }
        }

        long answer = dp_table.get(array_number - 1).get(operation_number);
        System.out.println(answer);
    }
}
