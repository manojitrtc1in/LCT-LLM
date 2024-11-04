import java.util.*;
import java.io.*;

public class 3258bffc0e01cc65ae06816d90e14176_nc {
    static long Mod = 1000000007L;
    static long INF = 1000000000L;
    static double Pi = 3.141592653589793116;
    static double EPS = 1e-9;
    static double Gold = ((1 + Math.sqrt(5)) / 2);
    
    static void ControlIO(String[] args) {
        String infile = "FILE.IN";
        String outfile = "FILE.OUT";
        
        #ifdef Akikaze
            Date now = new Date();
            System.out.println("Source code by #Team4T-Akikaze.");
            System.out.println("Current time: " + now.toString() + "\n");
            
            #ifdef OImode
                System.out.println("OI-Mode: ON");
                System.out.println("Input file: " + infile);
                System.out.println("Output file: " + outfile + "\n");
            #else
                System.out.println("OI-Mode: OFF");
                System.out.println("Input file: NULL");
                System.out.println("Output file: NULL\n");
            #endif
            
            #ifdef MultiTest
                System.out.println("MultiTest-Mode: ON\n");
            #else
                System.out.println("MultiTest-Mode: OFF\n");
            #endif
            
            #ifdef Interactive
                System.out.println("Interactive-Mode: ON\n");
            #else
                System.out.println("Interactive-Mode: OFF\n");
            #endif
            
            if (args.length > 0) {
                try {
                    System.setIn(new FileInputStream(args[0]));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            
            if (args.length > 1) {
                try {
                    System.setOut(new PrintStream(new FileOutputStream(args[1])));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        #elif OImode
            try {
                System.setIn(new FileInputStream(infile));
                System.setOut(new PrintStream(new FileOutputStream(outfile)));
            } catch (Exception e) {
                e.printStackTrace();
            }
        #endif
    }
    
    static void TimerStart() {
        #ifdef Akikaze
            TimeStart = System.nanoTime();
        #endif
    }
    
    static void TimerStop() {
        #ifdef Akikaze
            TimeEnd = System.nanoTime();
            double elapsedTime = (TimeEnd - TimeStart) / 1e9;
            System.out.println("\n\nTime elapsed: " + elapsedTime + " seconds.\n");
        #endif
    }
    
    static void Exit() {
        TimerStop();
        System.exit(0);
    }
    
    static void Input() {
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        sc.close();
    }
    
    static void Solve() {
        long baseAnswer = 1;
        for (char x : s.toCharArray()) {
            if (x >= '0' && x <= '9') continue;
            if (x == '?') {
                q++;
                continue;
            }
            Map.put(x, Map.getOrDefault(x, 0L) + 1);
        }
        for (long i = 10; i > 10 - Map.size(); i--) {
            baseAnswer *= i;
        }
        if (s.charAt(0) >= 'A' && s.charAt(0) <= 'J') {
            baseAnswer /= 10;
            baseAnswer *= 9;
        }
        if (s.charAt(0) == '?') {
            baseAnswer *= 9;
            q--;
        }
        System.out.print(baseAnswer);
        for (long i = 0; i < q; i++) {
            System.out.print("0");
        }
    }
    
    public static void main(String[] args) {
        ControlIO(args);
        
        #ifndef Interactive
            Input();
            TimerStart();
            Solve();
            TimerStop();
        #else
            Scanner sc = new Scanner(System.in);
            int T = sc.nextInt();
            TimerStart();
            while (T-- > 0) {
                Input();
                Solve();
            }
            TimerStop();
        #endif
    }
}
