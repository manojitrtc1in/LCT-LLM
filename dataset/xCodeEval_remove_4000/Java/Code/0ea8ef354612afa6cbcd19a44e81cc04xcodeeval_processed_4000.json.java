

import java.io.*;
import java.util.Arrays;
import java.util.IllegalFormatException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

public class Main{

    public static void main(String[] args) throws FileNotFoundException {
        TextIO.readStream(System.in);
        while (true){
            int n=0;
            try{
            n=TextIO.getInt();
            }catch(Exception e){
                break;
            }
            String []pl=new String[n];
            int pairs=TextIO.getInt();
            boolean co[][]=new boolean[n][n];
            for(int i=0;i<n;i++)
                pl[i]=TextIO.getWord();
            Arrays.sort(pl);
            for(int i=0;i<pairs;i++){
               int indexI=Arrays.binarySearch(pl, TextIO.getWord());
               int indexJ=Arrays.binarySearch(pl, TextIO.getWord());
               co[indexI][indexJ]=true;
               co[indexJ][indexI]=true;
            }
            int max=0;
            for(int i=1;i<(1<<n);i++){
                boolean can[]=new boolean[n];
                for(int j=0;j<n;j++){
                    if(((1<<j)&i) !=0)
                        can[j]=true;
                }
                boolean stat=true;
                for(int j=0;j<n;j++){
                    for(int z=0;z<n;z++){
                        if(co[j][z] && can[j] && can[z]){
                           stat=false;
                           break;
                        }
                          
                    }
                    if(!stat) 
                              break;
                }
                if(stat && count(i,n)>count(max,n))
                    max=i;
            }
            int counter=0;
            for(int j=0;j<n;j++){
                    if(((1<<j)&max) !=0)
                        counter++;
                }
            System.out.println(counter);
            for(int j=0;j<n;j++){
                    if(((1<<j)&max) !=0)
                        System.out.println(pl[j]);
                }
        }
    }
    
    static int count (int x,int n){
        int counter=0;
         for(int j=0;j<n;j++){
                    if(((1<<j)&x) !=0)
                        counter++;
                }
         return counter;
    }
}

class TextIO {

   public final static char EOF = (char)0xFFFF; 

   public final static char id0 = '\n';          

   
   public static void id20() {
      if (id19)
         return;
      try {
         in.close();
      }
      catch (Exception e) {
      }
      emptyBuffer();  
      in = standardInput;
      id5 = null;
      id19 = true;
      id13 = 0;
   }

   public static void readStream(InputStream inputStream) {
      if (inputStream == null)
         id20();
      else
         readStream(new InputStreamReader(inputStream));
   }
   
   public static void readStream(Reader inputStream) {
      if (inputStream == null)
         id20();
      else {
         if ( inputStream instanceof BufferedReader)
            in = (BufferedReader)inputStream;
         else
            in = new BufferedReader(inputStream);
         emptyBuffer();  

         id5 = null;
         id19 = false;
         id13 = 0;
      }
   }
   
   public static void readFile(String fileName) {
      if (fileName == null) 
         id20();
      else {
         BufferedReader newin;
         try {
            newin = new BufferedReader( new FileReader(fileName) );
         }
         catch (Exception e) {
            throw new IllegalArgumentException("Can't open file \"" + fileName + "\" for input.\n"
                           + "(Error :" + e + ")");
         }
         if (! id19) { 
            try {
               in.close();
            }
            catch (Exception e) {
            }
         }
         emptyBuffer();  

         in = newin;
         id19 = false;
         id13 = 0;
         id5 = fileName;
      }
   }

   public static boolean id21() {
      if (fileDialog == null)
         fileDialog = new JFileChooser();
      fileDialog.setDialogTitle("Select File for Input");
      int option = fileDialog.showOpenDialog(null);
      if (option != JFileChooser.APPROVE_OPTION)
         return false;
      File selectedFile = fileDialog.getSelectedFile();
      BufferedReader newin;
      try {
         newin = new BufferedReader( new FileReader(selectedFile) );
      }
      catch (Exception e) {
         throw new IllegalArgumentException("Can't open file \"" + selectedFile.getName() + "\" for input.\n"
                        + "(Error :" + e + ")");
      }
      if (!id19) { 
         try {
            in.close();
         }
         catch (Exception e) {
         }
      }
      emptyBuffer();  

      in = newin;
      id5 = selectedFile.getName();
      id19 = false;
      id13 = 0;
      return true;
   }
   
   public static void id26() {
      if (id27)
         return;
      try {
         out.close();
      }
      catch (Exception e) {
      }
      id8 = null;
      id17 = 0;
      out = standardOutput;
      id27 = true;
   }
   
   public static void writeStream(OutputStream outputStream) {
      if (outputStream == null)
         id26();
      else
         writeStream(new PrintWriter(outputStream));
   }
   
   public static void writeStream(PrintWriter outputStream) {
      if (outputStream == null)
         id26();
      else {
         out = outputStream;
         id8 = null;
         id17 = 0;
         id27 = false;
      }
   }
   
   public static void writeFile(String fileName) {
      if (fileName == null)  

         id26();
      else {
         PrintWriter newout;
         try {
            newout = new PrintWriter(new FileWriter(fileName));
         }
         catch (Exception e) {
            throw new IllegalArgumentException("Can't open file \"" + fileName + "\" for output.\n"
                           + "(Error :" + e + ")");
         }
         if (!id27) {
            try {
               out.close();
            }
            catch (Exception e) {
            }
         }
         out = newout;
         id27 = false;
         id8 = fileName;
         id17 = 0;
      }
   }
   
   public static boolean id7() {
      if (fileDialog == null)
         fileDialog = new JFileChooser();
      fileDialog.setDialogTitle("Select File for Output");
      File selectedFile;
      while (true) {
         int option = fileDialog.showSaveDialog(null);
         if (option != JFileChooser.APPROVE_OPTION)
            return false;  
         selectedFile = fileDialog.getSelectedFile();
         if (selectedFile.exists()) {
            int response = JOptionPane.showConfirmDialog(null,
                  "The file \"" + selectedFile.getName() + "\" already exists.  Do you want to replace it?",
                  "Replace existing file?",
                  JOptionPane.YES_NO_OPTION, JOptionPane.WARNING_MESSAGE);
            if (response == JOptionPane.YES_OPTION)
               break;
         }
         else {
            break;
         }
      }
      PrintWriter newout;
      try {
         newout = new PrintWriter(new FileWriter(selectedFile));
      }
      catch (Exception e) {
         throw new IllegalArgumentException("Can't open file \"" + selectedFile.getName() + "\" for output.\n"
                        + "(Error :" + e + ")");
      }
      if (!id27) {
         try {
            out.close();
         }
         catch (Exception e) {
         }
      }
      out = newout;
      id27 = false;
      id8 = selectedFile.getName();
      id17 = 0;
      return true;
   }
   
   public static String id24() {
      return id5;
   }
   
   public static String id6() {
      return id8;
   }
   
   public static void put(Object x) { 
      out.print(x); 
      out.flush();
      if (out.checkError())
         outputError("Error while writing output.");
   }
   

   public static void put(Object x, int minChars)  { 
      if (minChars <= 0)
         out.print(x);
      else
         out.printf("%" + minChars + "s", x);
      out.flush();
      if (out.checkError())
         outputError("Error while writing output.");
   }
      
   public static void putln(Object x) { 
      out.println(x);
      out.flush();
      if (out.checkError())
         outputError("Error while writing output.");
   }
   
   public static void putln(Object x, int minChars) {
      put(x,minChars);
      out.println();
      out.flush();
      if (out.checkError())
         outputError("Error while writing output.");
   }

   public static void putln() {
      out.println();
      out.flush();
      if (out.checkError())
         outputError("Error while writing output.");
   }
   
   public static void putf(String format, Object... items) {
      if (format == null)
         throw new IllegalArgumentException("Null format string in TextIO.putf() method.");
      try {
         out.printf(format,items);
      }
      catch (IllegalFormatException e) {
         throw new IllegalArgumentException("Illegal format string in TextIO.putf() method.");
      }
      out.flush();
      if (out.checkError())
         outputError("Error while writing output.");
   }
   
   public static boolean id10() { 
      return peek() == '\n'; 
   }

   public static boolean eof()  { 
      return peek() == EOF; 
   }
   
      public static int filesize() throws IOException{
        int count = 0;
	File file = new File(id5);
	if (file.exists()){
		FileReader fr = new FileReader(file);
		LineNumberReader ln = new LineNumberReader(fr);
		while (ln.readLine() != null){
			count++;
			}
		ln.close();
	    }
	else{
		System.out.println("File does not exists!");
	    }
       return count;
   }
      
   public static char id2() { 
      return readChar(); 
   }

   public static char peek() { 
      return lookChar();
   }
   
   public static void id18() { 
      char ch=lookChar();
      while (ch != EOF && ch != '\n' && Character.isWhitespace(ch)) {
         readChar();
         ch = lookChar();
      }
   }

   private static void skipWhitespace() {
      char ch=lookChar();
      while (ch != EOF && Character.isWhitespace(ch)) {
         readChar();
         if (ch == '\n' && id19 && id27) {
            out.print("? ");
            out.flush();
         }
         ch = lookChar();
      }
   }

   public static byte id22() { 
      byte x=getByte(); 
      emptyBuffer(); 
      return x; 
   }
   
   public static short id15() {
      short x=getShort();
      emptyBuffer(); 
      return x; 
   }
   
   public static int id3() { 
      int x=getInt(); 
      emptyBuffer(); 
      return x; 
   }
   
   public static long id9() {
      long x=getLong(); 
      emptyBuffer(); 
      return x;
   }
   
   public static float id16() {
      float x=getFloat(); 
      emptyBuffer(); 
      return x;
   }
   
   public static double id25() { 
      double x=getDouble(); 
      emptyBuffer(); 
      return x; 
   }
   
   public static char id14() {
      char x=getChar(); 
      emptyBuffer(); 
      return x;
   }
   
   public static boolean id4() { 
      boolean x=getBoolean(); 
      emptyBuffer();
      return x; 
   }
   
   public static String id1() {
      String x=getWord(); 
      emptyBuffer(); 
      return x; 
   }
   
   public static String id12() {
      return getln();
   } 
   
   public static String getln() {
      StringBuffer s = new StringBuffer(100);
      char ch = readChar();
      while (ch != '\n') {
         s.append(ch);
         ch = readChar();
      }
      return s.toString();
   }
   
   public static byte getByte()   { 
      return (byte)readInteger(-128L,127L); 
   }

   public static short getShort() { 
      return (short)readInteger(-32768L,32767L);
   }   
   
   public static int getInt()     { 
      return (int)readInteger(Integer.MIN_VALUE, Integer.MAX_VALUE);
   }
   
   public static long getLong()   { 
      return readInteger(Long.MIN_VALUE, Long.MAX_VALUE); 
   }
   
   public static char getChar() { 
      skipWhitespace();
      return readChar();
   }
   
   public static float getFloat() {
      float x = 0.0F;
      while (true) {
         String str = id11();
         if (str == null) {
            errorMessage("Floating point number not found.",
                  "Real number in the range " + (-Float.MAX_VALUE) + " to " + Float.MAX_VALUE);
         }
         else {
            try { 
               x = Float.parseFloat(str); 
            }
            catch (NumberFormatException e) {
               errorMessage("Illegal floating point input, " + str + ".",
                     "Real number in the range " +  (-Float.MAX_VALUE) + " to " + Float.MAX_VALUE);
               continue;
            }
            if (Float.isInfinite(x)) {
               errorMessage("Floating point input outside of legal range, " + str + ".",
                     "Real number in the range " +  (-Float.MAX_VALUE) + " to " + Float.MAX_VALUE);
               continue;
            }
            break;
         }
      }
      id13 = 0;
      return x;
   }
   
   public static double getDouble() {
      double x = 0.0;
      while (true) {
         String str = id11();
         if (str == null) {
            errorMessage("Floating point number not found.",
                  "Real number in the range " + (-Double.MAX_VALUE) + " to " + Double.MAX_VALUE);
         }
         else {
            try { 
               x = Double.parseDouble(str); 
            }
            catch (NumberFormatException e) {
               errorMessage("Illegal floating point input, " + str + ".",
                     "Real number in the range " + (-Double.MAX_VALUE) + " to " + Double.MAX_VALUE);
               continue;
            }
            if (Double.isInfinite(x)) {
               errorMessage("Floating point input outside of legal range, " + str + ".",
                     "Real number in the range " + (-Double.MAX_VALUE) + " to " + Double.MAX_VALUE);
               continue;
            }
            break;
         }
      }
      id13 = 0;
      return x;
   }
   
   public static String getWord() {
      skipWhitespace();
      StringBuffer str = new StringBuffer(50);
      char ch = lookChar();
      while (ch == EOF || !Character.isWhitespace(ch)) {
         str.append(readChar());
         ch = lookChar();
      }
      return str.toString();
   }
   
   public static boolean getBoolean() {
      boolean ans = false;
      while (true) {
         String s = getWord();
         if ( s.equalsIgnoreCase("true") || s.equalsIgnoreCase("t") ||
               s.equalsIgnoreCase("yes")  || s.equalsIgnoreCase("y") ||
               s.equals("1") ) {
            ans = true;
            break;
         }
         else if ( s.equalsIgnoreCase("false") || s.equalsIgnoreCase("f") ||
               s.equalsIgnoreCase("no")  || s.equalsIgnoreCase("n") ||
               s.equals("0") ) {
            ans = false;
            break;
         }
         else
            errorMessage("Illegal boolean input value.",
            "one of:  true, false, t, f, yes, no, y, n, 0, or 1");
      }
      id13 = 0;
      return ans;
   }
   
   

   
   private static String id5;  
   private static String id8; 
   
   private static JFileChooser fileDialog;
   
   private final static BufferedReader standardInput = new BufferedReader(new InputStreamReader(System.in));  
   private final static PrintWriter standardOutput = new PrintWriter(System.out);  

   private static BufferedReader in = standardInput;  
   private static PrintWriter out = standardOutput;   
   
   private static boolean id19 = true;
   private static boolean id27 = true;
   
   private static int id13;  
   private static int id17;  
   
   private static Matcher integerMatcher; 
   private static Matcher floatMatcher;   
   private final static Pattern integerRegex = Pattern.compile("(\\+|-)?[0-9]+");
   private final static Pattern floatRegex = Pattern.compile("(\\+|-)?(([0-9]+(\\.[0-9]*)?)|(\\.[0-9]+))((e|E)(\\+|-)?[0-9]+)?");
   
   private static String buffer = null;  
   private static int pos = 0;           
   
   private static String id11() {   
      skipWhitespace();
      if (lookChar() == EOF)
         return null;
      if (floatMatcher == null)
         floatMatcher = floatRegex.matcher(buffer);
      floatMatcher.region(pos,buffer.length());
      if (floatMatcher.lookingAt()) {
         String str = floatMatcher.group();
         pos = floatMatcher.end();
         return str;
      }
      else 
         return null;
   }
   
   private static String id23() {  
      skipWhitespace();
      if (lookChar() == EOF)
         return null;
      if (integerMatcher == null)
         integerMatcher = integerRegex.matcher(buffer);
      integerMatcher.region(pos,buffer.length());
      if (integerMatcher.lookingAt()) {
         String str = integerMatcher.group();
         pos = integerMatcher.end();
         return str;
      }
      else 
         return null;
   }
   
   private static long readInteger(long min, long max) {  
      long x=0;
      while (true) {
         String s = id23();
         if (s == null){
            errorMessage("Integer value not found in input.",
                  "Integer in the range " + min + " to " + max);
         }
         else {
            String str = s.toString();
            try { 
               x = Long.parseLong(str);
            }
            catch (NumberFormatException e) {
               errorMessage("Illegal integer input, " + str + ".",
                     "Integer in the range " + min + " to " + max);
               continue;
            }
            if (x < min || x > max) {
               errorMessage("Integer input outside of legal range, " + str + ".",
                     "Integer in the range " + min + " to " + max);
               continue;
            }
            break;
         }
      }
      id13 = 0;
      return x;
   }
   
   
   private static void errorMessage(String message, String expecting) {  
      if (id19 && id27) {
         out.println();
         out.print("  *** Error in input: " + message + "\n");
         out.print("  *** Expecting: " + expecting + "\n");
         out.print("  *** Discarding Input: ");
         if (lookChar() == '\n')
            out.print("(end-of-line)\n\n");
         else {
            while (lookChar() != '\n')    
               out.print(readChar());
            out.print("\n\n");
         }
         out.print("Please re-enter: ");
         out.flush();
         readChar();  
         id13++;
         if (id13 >= 10)
            throw new IllegalArgumentException("Too many input consecutive input errors on standard input.");
      }
      else if (id5 != null)
         throw new IllegalArgumentException("Error while reading from file \"" + id5 + "\":\n" 
               + message + "\nExpecting " + expecting);
      else
         throw new IllegalArgumentException("Error while reading from inptu stream:\n" 
               + message + "\nExpecting " + expecting);
   }
   
   private static char lookChar() {  
      if (buffer == null || pos > buffer.length())
         fillBuffer();
      if (buffer == null)
         return EOF;
      else if (pos == buffer.length())
         return '\n';
      else 
         return buffer.charAt(pos);
   }
   
   private static char readChar() {  
      char ch = lookChar();
      if (buffer == null) {
         if (id19)
            throw new IllegalArgumentException("Attempt to read past end-of-file in standard input???");
         else
            throw new IllegalArgumentException("Attempt to read past end-of-file in file \"" + id5 + "\".");
      }
      pos++;
      return ch;
   }
      
   private static void fillBuffer() {   
      try {
         buffer = in.readLine();
      }
      catch (Exception e) {
         if (id19)
            throw new IllegalArgumentException("Error while reading standard input???");
         else if (id5 != null)
            throw new IllegalArgumentException("Error while attempting to read from file \"" + id5 + "\".");
         else
            throw new IllegalArgumentException("Errow while attempting to read form an input stream.");
      }
      pos = 0;
      floatMatcher = null;
      integerMatcher = null;
   }
   
   private static void emptyBuffer() {   
      buffer = null;
   }
   
   private static void outputError(String message) {  
      if (id27) {
         System.err.println("Error occurred in TextIO while writing to standard output!!");
         id17++;
         if (id17 >= 10) {
            id17 = 0;
            throw new IllegalArgumentException("Too many errors while writing to standard output.");
         }
      }
      else if (id8 != null){
         throw new IllegalArgumentException("Error occurred while writing to file \"" 
               + id8+ "\":\n   " + message);
      }
      else {
         throw new IllegalArgumentException("Error occurred while writing to output stream:\n   " + message);
      }
   }
      
}