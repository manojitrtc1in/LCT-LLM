import java.io.*;
import java.util.*;

public class 98f17ebeb532f8f9ab01cecf73d0d924_nc {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        char[][] board = new char[8][8];
        
        for (int i = 0; i < 8; i++) {
            String line = scanner.next();
            board[i] = line.toCharArray();
        }
        
        int total = 0;
        
        for (int i = 0; i < 8; i++) {
            int count = 0;
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'B') {
                    count++;
                }
            }
            if (count == 8) {
                Arrays.fill(board[i], 'A');
                total++;
            }
        }
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[j][i] == 'B') {
                    total++;
                    break;
                }
            }
        }
        
        System.out.printf("%d\n", total);
    }
}
