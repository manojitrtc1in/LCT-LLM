

import java.io.*;
import java.util.*;



public class NFS {

  
  public static final int YYEOF = -1;

  
  private static final int ZZ_BUFFERSIZE = 16384;

  
  public static final int YYINITIAL = 0;

  
  private static final int ZZ_LEXSTATE[] = { 
     0, 0
  };

  
  private static final String ZZ_CMAP_PACKED = 
    "\12\0\1\1\2\0\1\1\22\0\1\4\1\3\1\2\11\0\1\3"+
    "\1\0\1\3\1\0\12\3\5\0\1\3\1\0\32\3\6\0\32\3"+
    "\uff85\0";

  
  private static final char [] ZZ_CMAP = zzUnpackCMap(ZZ_CMAP_PACKED);

  
  private static final int [] ZZ_ACTION = zzUnpackAction();

  private static final String ZZ_ACTION_PACKED_0 =
    "\1\0\1\1\1\0\1\2\1\3\1\4";

  private static int [] zzUnpackAction() {
    int [] result = new int[6];
    int offset = 0;
    offset = zzUnpackAction(ZZ_ACTION_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackAction(String packed, int offset, int [] result) {
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


  
  private static final int [] ZZ_ROWMAP = zzUnpackRowMap();

  private static final String ZZ_ROWMAP_PACKED_0 =
    "\0\0\0\5\0\12\0\17\0\24\0\31";

  private static int [] zzUnpackRowMap() {
    int [] result = new int[6];
    int offset = 0;
    offset = zzUnpackRowMap(ZZ_ROWMAP_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackRowMap(String packed, int offset, int [] result) {
    int i = 0;  
    int j = offset;  
    int l = packed.length();
    while (i < l) {
      int high = packed.charAt(i++) << 16;
      result[j++] = high | packed.charAt(i++);
    }
    return j;
  }

  
  private static final int [] ZZ_TRANS = zzUnpackTrans();

  private static final String ZZ_TRANS_PACKED_0 =
    "\1\0\1\2\1\3\1\4\1\5\1\0\1\2\5\0"+
    "\1\6\2\3\3\0\1\4\5\0\1\5\5\0";

  private static int [] zzUnpackTrans() {
    int [] result = new int[30];
    int offset = 0;
    offset = zzUnpackTrans(ZZ_TRANS_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackTrans(String packed, int offset, int [] result) {
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


  
  private static final int ZZ_UNKNOWN_ERROR = 0;
  private static final int ZZ_NO_MATCH = 1;
  private static final int ZZ_PUSHBACK_2BIG = 2;

  
  private static final String ZZ_ERROR_MSG[] = {
    "Unkown internal scanner error",
    "Error: could not match input",
    "Error: pushback value was too large"
  };

  
  private static final int [] ZZ_ATTRIBUTE = zzUnpackAttribute();

  private static final String ZZ_ATTRIBUTE_PACKED_0 =
    "\1\0\1\1\1\0\2\1\1\11";

  private static int [] zzUnpackAttribute() {
    int [] result = new int[6];
    int offset = 0;
    offset = zzUnpackAttribute(ZZ_ATTRIBUTE_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackAttribute(String packed, int offset, int [] result) {
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

  
  private int zzLexicalState = YYINITIAL;

  
  private char zzBuffer[] = new char[ZZ_BUFFERSIZE];

  
  private int zzMarkedPos;

  
  private int zzCurrentPos;

  
  private int zzStartRead;

  
  private int zzEndRead;

  
  private int yyline;

  
  private int yychar;

  
  private int yycolumn;

  
  private boolean zzAtBOL = true;

  
  private boolean zzAtEOF;

  
  private boolean zzEOFDone;

  

	static PrintWriter out;

	public static void main( String[] argv ) {
		try {
			
			InputStreamReader in = new InputStreamReader(System.in);
			out = new PrintWriter(new OutputStreamWriter(System.out));
			
			NFS lexer = new NFS( in );
			lexer.yylex();
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

  
  private static char [] zzUnpackCMap(String packed) {
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


  
  private boolean zzRefill() throws java.io.IOException {

    
    if (zzStartRead > 0) {
      System.arraycopy(zzBuffer, zzStartRead,
                       zzBuffer, 0,
                       zzEndRead-zzStartRead);

      
      zzEndRead-= zzStartRead;
      zzCurrentPos-= zzStartRead;
      zzMarkedPos-= zzStartRead;
      zzStartRead = 0;
    }

    
    if (zzCurrentPos >= zzBuffer.length) {
      
      char newBuffer[] = new char[zzCurrentPos*2];
      System.arraycopy(zzBuffer, 0, newBuffer, 0, zzBuffer.length);
      zzBuffer = newBuffer;
    }

    
    int numRead = zzReader.read(zzBuffer, zzEndRead,
                                            zzBuffer.length-zzEndRead);

    if (numRead > 0) {
      zzEndRead+= numRead;
      return false;
    }
    

    if (numRead == 0) {
      int c = zzReader.read();
      if (c == -1) {
        return true;
      } else {
        zzBuffer[zzEndRead++] = (char) c;
        return false;
      }     
    }

	

    return true;
  }

    
  
  public final void yyclose() throws java.io.IOException {
    zzAtEOF = true;            
    zzEndRead = zzStartRead;  

    if (zzReader != null)
      zzReader.close();
  }


  
  public final void yyreset(java.io.Reader reader) {
    zzReader = reader;
    zzAtBOL  = true;
    zzAtEOF  = false;
    zzEOFDone = false;
    zzEndRead = zzStartRead = 0;
    zzCurrentPos = zzMarkedPos = 0;
    yyline = yychar = yycolumn = 0;
    zzLexicalState = YYINITIAL;
  }


  
  public final int yystate() {
    return zzLexicalState;
  }


  
  public final void yybegin(int newState) {
    zzLexicalState = newState;
  }


  
  public final String yytext() {
    return new String( zzBuffer, zzStartRead, zzMarkedPos-zzStartRead );
  }


  
  public final char yycharat(int pos) {
    return zzBuffer[zzStartRead+pos];
  }


  
  public final int yylength() {
    return zzMarkedPos-zzStartRead;
  }


  
  private void zzScanError(int errorCode) {
    String message;
    try {
      message = ZZ_ERROR_MSG[errorCode];
    }
    catch (ArrayIndexOutOfBoundsException e) {
      message = ZZ_ERROR_MSG[ZZ_UNKNOWN_ERROR];
    }

    throw new Error(message);
  } 


  
  public void yypushback(int number)  {
    if ( number > yylength() )
      zzScanError(ZZ_PUSHBACK_2BIG);

    zzMarkedPos -= number;
  }


  
  public Boolean yylex() throws java.io.IOException {
    int zzInput;
    int zzAction;

    

    int zzCurrentPosL;
    int zzMarkedPosL;
    int zzEndReadL = zzEndRead;
    char [] zzBufferL = zzBuffer;
    char [] zzCMapL = ZZ_CMAP;

    int [] zzTransL = ZZ_TRANS;
    int [] zzRowMapL = ZZ_ROWMAP;
    int [] zzAttrL = ZZ_ATTRIBUTE;

    while (true) {
      zzMarkedPosL = zzMarkedPos;

      zzAction = -1;

      zzCurrentPosL = zzCurrentPos = zzStartRead = zzMarkedPosL;
  
      zzState = ZZ_LEXSTATE[zzLexicalState];


      zzForAction: {
        while (true) {
    
          if (zzCurrentPosL < zzEndReadL)
            zzInput = zzBufferL[zzCurrentPosL++];
          else if (zzAtEOF) {
            zzInput = YYEOF;
            break zzForAction;
          }
          else {
            

            zzCurrentPos  = zzCurrentPosL;
            zzMarkedPos   = zzMarkedPosL;
            boolean eof = zzRefill();
            

            zzCurrentPosL  = zzCurrentPos;
            zzMarkedPosL   = zzMarkedPos;
            zzBufferL      = zzBuffer;
            zzEndReadL     = zzEndRead;
            if (eof) {
              zzInput = YYEOF;
              break zzForAction;
            }
            else {
              zzInput = zzBufferL[zzCurrentPosL++];
            }
          }
          int zzNext = zzTransL[ zzRowMapL[zzState] + zzCMapL[zzInput] ];
          if (zzNext == -1) break zzForAction;
          zzState = zzNext;

          int zzAttributes = zzAttrL[zzState];
          if ( (zzAttributes & 1) == 1 ) {
            zzAction = zzState;
            zzMarkedPosL = zzCurrentPosL;
            if ( (zzAttributes & 8) == 8 ) break zzForAction;
          }

        }
      }

      

      zzMarkedPos = zzMarkedPosL;

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
          if (zzInput == YYEOF && zzStartRead == zzCurrentPos) {
            zzAtEOF = true;
            return null;
          } 
          else {
            zzScanError(ZZ_NO_MATCH);
          }
      }
    }
  }


}
