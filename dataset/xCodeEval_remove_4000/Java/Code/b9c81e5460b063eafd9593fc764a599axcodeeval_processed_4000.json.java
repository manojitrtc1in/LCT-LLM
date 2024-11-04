

import java.io.*;
import java.util.*;



public class NFS {

  
  public static final int YYEOF = -1;

  
  private static final int id12 = 16384;

  
  public static final int YYINITIAL = 0;

  
  private static final int id13[] = { 
     0, 0
  };

  
  private static final String id18 = 
    "\12\0\1\1\2\0\1\1\22\0\1\4\1\3\1\2\11\0\1\3"+
    "\1\0\1\3\1\0\12\3\5\0\1\3\1\0\32\3\6\0\32\3"+
    "\uff85\0";

  
  private static final char [] id31 = id0(id18);

  
  private static final int [] ZZ_ACTION = id37();

  private static final String id1 =
    "\1\0\1\1\1\0\1\2\1\3\1\4";

  private static int [] id37() {
    int [] result = new int[6];
    int offset = 0;
    offset = id37(id1, offset, result);
    return result;
  }

  private static int id37(String packed, int offset, int [] result) {
    int i = 0;       
    int j = offset;  
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }


  
  private static final int [] id33 = id4();

  private static final String id21 =
    "\0\0\0\5\0\12\0\17\0\24\0\31";

  private static int [] id4() {
    int [] result = new int[6];
    int offset = 0;
    offset = id4(id21, offset, result);
    return result;
  }

  private static int id4(String packed, int offset, int [] result) {
    int i = 0;  
    int j = offset;  
    int l = packed.length();
    while (i < l) {
      int high = packed.charAt(i++) << 16;
      result[j++] = high | packed.charAt(i++);
    }
    return j;
  }

  
  private static final int [] ZZ_TRANS = id14();

  private static final String id22 =
    "\1\0\1\2\1\3\1\4\1\5\1\0\1\2\5\0"+
    "\1\6\2\3\3\0\1\4\5\0\1\5\5\0";

  private static int [] id14() {
    int [] result = new int[30];
    int offset = 0;
    offset = id14(id22, offset, result);
    return result;
  }

  private static int id14(String packed, int offset, int [] result) {
    int i = 0;       
    int j = offset;  
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      value--;
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }


  
  private static final int id7 = 0;
  private static final int id2 = 1;
  private static final int id29 = 2;

  
  private static final String id15[] = {
    "Unkown internal scanner error",
    "Error: could not match input",
    "Error: pushback value was too large"
  };

  
  private static final int [] ZZ_ATTRIBUTE = id16();

  private static final String id26 =
    "\1\0\1\1\1\0\2\1\1\11";

  private static int [] id16() {
    int [] result = new int[6];
    int offset = 0;
    offset = id16(id26, offset, result);
    return result;
  }

  private static int id16(String packed, int offset, int [] result) {
    int i = 0;       
    int j = offset;  
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }

  
  private java.io.Reader zzReader;

  
  private int zzState;

  
  private int id28 = YYINITIAL;

  
  private char zzBuffer[] = new char[id12];

  
  private int id38;

  
  private int id23;

  
  private int id20;

  
  private int id9;

  
  private int yyline;

  
  private int yychar;

  
  private int yycolumn;

  
  private boolean id6 = true;

  
  private boolean id32;

  
  private boolean id34;

  

	static PrintWriter out;

	public static void main( String[] argv ) {
		try {
			
			InputStreamReader in = new InputStreamReader(System.in);
			out = new PrintWriter(new OutputStreamWriter(System.out));
			
			NFS lexer = new NFS( in );
			lexer.id35();
			in.close();
		}
		catch ( Exception exception ) {
			System.err.println( "Exception in Main " + exception.toString() );
			exception.printStackTrace();
		}
	}


  
  public NFS(java.io.Reader in) {
    this.zzReader = in;
  }

  
  public NFS(java.io.InputStream in) {
    this(new java.io.InputStreamReader(in));
  }

  
  private static char [] id0(String packed) {
    char [] map = new char[0x10000];
    int i = 0;  
    int j = 0;  
    while (i < 42) {
      int  count = packed.charAt(i++);
      char value = packed.charAt(i++);
      do map[j++] = value; while (--count > 0);
    }
    return map;
  }


  
  private boolean id3() throws java.io.IOException {

    
    if (id20 > 0) {
      System.arraycopy(zzBuffer, id20,
                       zzBuffer, 0,
                       id9-id20);

      
      id9-= id20;
      id23-= id20;
      id38-= id20;
      id20 = 0;
    }

    
    if (id23 >= zzBuffer.length) {
      
      char newBuffer[] = new char[id23*2];
      System.arraycopy(zzBuffer, 0, newBuffer, 0, zzBuffer.length);
      zzBuffer = newBuffer;
    }

    
    int numRead = zzReader.read(zzBuffer, id9,
                                            zzBuffer.length-id9);

    if (numRead > 0) {
      id9+= numRead;
      return false;
    }
    

    if (numRead == 0) {
      int c = zzReader.read();
      if (c == -1) {
        return true;
      } else {
        zzBuffer[id9++] = (char) c;
        return false;
      }     
    }

	

    return true;
  }

    
  
  public final void yyclose() throws java.io.IOException {
    id32 = true;            
    id9 = id20;  

    if (zzReader != null)
      zzReader.close();
  }


  
  public final void yyreset(java.io.Reader reader) {
    zzReader = reader;
    id6  = true;
    id32  = false;
    id34 = false;
    id9 = id20 = 0;
    id23 = id38 = 0;
    yyline = yychar = yycolumn = 0;
    id28 = YYINITIAL;
  }


  
  public final int yystate() {
    return id28;
  }


  
  public final void yybegin(int newState) {
    id28 = newState;
  }


  
  public final String yytext() {
    return new String( zzBuffer, id20, id38-id20 );
  }


  
  public final char id10(int pos) {
    return zzBuffer[id20+pos];
  }


  
  public final int id36() {
    return id38-id20;
  }


  
  private void id11(int errorCode) {
    String message;
    try {
      message = id15[errorCode];
    }
    catch (ArrayIndexOutOfBoundsException e) {
      message = id15[id7];
    }

    throw new Error(message);
  } 


  
  public void id39(int number)  {
    if ( number > id36() )
      id11(id29);

    id38 -= number;
  }


  
  public Boolean id35() throws java.io.IOException {
    int zzInput;
    int zzAction;

    

    int id19;
    int id25;
    int id24 = id9;
    char [] id30 = zzBuffer;
    char [] id5 = id31;

    int [] id8 = ZZ_TRANS;
    int [] id17 = id33;
    int [] id27 = ZZ_ATTRIBUTE;

    while (true) {
      id25 = id38;

      zzAction = -1;

      id19 = id23 = id20 = id25;
  
      zzState = id13[id28];


      zzForAction: {
        while (true) {
    
          if (id19 < id24)
            zzInput = id30[id19++];
          else if (id32) {
            zzInput = YYEOF;
            break zzForAction;
          }
          else {
            

            id23  = id19;
            id38   = id25;
            boolean eof = id3();
            

            id19  = id23;
            id25   = id38;
            id30      = zzBuffer;
            id24     = id9;
            if (eof) {
              zzInput = YYEOF;
              break zzForAction;
            }
            else {
              zzInput = id30[id19++];
            }
          }
          int zzNext = id8[ id17[zzState] + id5[zzInput] ];
          if (zzNext == -1) break zzForAction;
          zzState = zzNext;

          int zzAttributes = id27[zzState];
          if ( (zzAttributes & 1) == 1 ) {
            zzAction = zzState;
            id25 = id19;
            if ( (zzAttributes & 8) == 8 ) break zzForAction;
          }

        }
      }

      

      id38 = id25;

      switch (zzAction < 0 ? zzAction : ZZ_ACTION[zzAction]) {
        case 1: 
          { System.exit(0); out.flush(); out.close();
          }
        case 5: break;
        case 3: 
          { 
          }
        case 6: break;
        case 2: 
          { System.out.println("<" + yytext() + ">");
          }
        case 7: break;
        case 4: 
          { System.out.println("<" + yytext().substring(1, yytext().length()-1) + ">");
          }
        case 8: break;
        default: 
          if (zzInput == YYEOF && id20 == id23) {
            id32 = true;
            return null;
          } 
          else {
            id11(id2);
          }
      }
    }
  }


}
