









using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector< vector< int > > VVI;
typedef vector< pair<int,int> > VP;
typedef vector< VP > VVP;
typedef VS::iterator VSit;
typedef VI::iterator VIit;
typedef VVI::iterator VVIit;
typedef VP::iterator VPit;
typedef VVP::iterator VVPit;
typedef vector< vector< pair<int,int> > > VVP;
typedef set< int > SI;
typedef SI::iterator SIit;
typedef vector< SI > VSI;
typedef VSI::iterator VSIit;
typedef queue< int > QI;

































static int bads[256];   

                        

                        

static int offsets[8];
static int valcormask[4][3];
static int corner1s[4][2];

enum          

{ CYZO=1      

, CYIGNORE=2  

, CYEDGE=4    

};

static string hex(int i) { char c[256]; sprintf( c, "%02x", i); return string(c); }

class CF_CLASS {
private:
 int* intAlloc;
 int* cys;         

 int* eights;      

 int* ingroup;     


public:
  ~CF_CLASS() { delete[] intAlloc; }
  CF_CLASS() {

    cys = intAlloc = new int[3000000];
    eights = cys + 1000000;
    ingroup = eights + 1000000;

    if (offsets[0] == 0) {

      offsets[0]=-1001; offsets[1]=-1000; offsets[2]= -999;
      offsets[7]=   -1;                   offsets[3]=   +1;
      offsets[6]= +999; offsets[5]=+1000; offsets[4]=+1001;

      int msk = 0b111;
      int val = 0b010;
      int csk = 0b10000011;
      for (int i=0; i<4; ++i) {
        

        valcormask[i][0] = msk;
        valcormask[i][1] = val;
        valcormask[i][2] = csk;
        msk = 0x0ff & ( msk<<2 | msk>>6 );
        val = 0x0ff & ( val<<2 | val>>6 );
        csk = 0x0ff & ( csk<<2 | csk>>6 );
      }
      for (int i=0; i<256; ++i) {
        for( int j=0; j<4; ++j) {
          bads[i] |= ((i & valcormask[j][0]) == valcormask[j][1]) ? 1 : 0;
        }
        

      }
      

    }
  }

  vector<string> CF_CLASS_METHOD( vector<string> inputs ) {
  vector<string> actuals;
  int rtn = 0;
  int nRow, nCol;
    sscanf( inputs[0].c_str(), "%d %d", &nRow, &nCol);
    if ( nRow<2 || nCol<2 ) {
      ADDACTUAL( 0 );
      return actuals;
    }
    int i;
    char id0[1024] = { "" };
    char *p = id0;

    memset( intAlloc, 0, 3000000 * sizeof(int));

    


    int iInput = 0;
    for (int i=0; i<(nRow*1000); ) {
      if ( !*p ) {
        strcpy( p=id0, inputs[++iInput].c_str());
      }
      char nextChar = *(p++);
      switch (nextChar) {
      case '0': case '1':
        cys[i++] = (((int)nextChar) & 1) ? CYZO : 0;
        

        if (((i%1000)%nCol)==0) i = ((i+999)/1000) * 1000;
        break;
      default: break;
      }
    }

    if ( nRow==2 || nCol==2 ) {
      for ( int iRow=0; iRow<(nRow-1); ++iRow ) {
        i = 1000 * iRow;
        for ( int jCol=0; jCol<(nCol-1); ++jCol,++i ) {
          if ( !(cys[i           ] & CYZO) ) continue;
          if ( !(cys[i+offsets[3]] & CYZO) ) continue;
          if ( !(cys[i+offsets[4]] & CYZO) ) continue;
          if ( !(cys[i+offsets[5]] & CYZO) ) continue;
          ADDACTUAL( 4 );
          return actuals;
        }
      }
    }

    


    for (int iRow=0; iRow<nRow; ++iRow) {
      i = 1000 * iRow;
      int id2 = (iRow%(nRow-1))==0 ? 1 : 0;
      cys[i++] |= CYEDGE;
      for (int jCol=1; jCol<(nCol-1); ++jCol, ++i) {
        if ( id2 ) {
          cys[i] |= CYEDGE;         

          continue;                 

        }
        int sum;
        for ( int k=sum=0; k<8; ++k) {
          sum += (cys[i+offsets[k]]&CYZO) << k;
        }
        if ( (eights[i]=sum) == 0 ) cys[i] |= CYIGNORE;
        else if (sum==255 && !(cys[i]&CYZO)) rtn = 8;
        else if ( !rtn && sum && (cys[i]&CYZO)) {  

          for (int m=0; m<4; ++m ) {              

            if ( (sum&valcormask[m][2]) == valcormask[m][2] ) {
              rtn = 4;
              break;
            }
          }
        }
        

      }
      cys[i++] |= CYEDGE;
    }

    


    vector< bool > coolGroup;
    QI zfifo;
    

    


    int curGroup = 0;

    for (int iRow=1; iRow<(nRow-1); ++iRow) {
      i = 1000 * iRow + 1;
      for (int jCol=1; jCol<(nCol-1); ++jCol, ++i) {
        int onesCount = 0;
        int id3 = 1000001;
        if ( (cys[i]&CYZO) ) continue;  

        if ( ingroup[i] ) continue;     


        


        curGroup++;                                 

        coolGroup.push_back( bads[eights[i]]==0 );  

        

        

        zfifo.push( i );                            

        while ( !zfifo.empty() ) {                  

        int ii = zfifo.front();                     

          zfifo.pop();                                             


          

          

          


          if ( ingroup[ii] ) continue;                             

          ingroup[ii] = curGroup;                                  

          int eight = eights[ii];                                  

          if ( coolGroup[iGroup] ) {                               

            if ( bads[eight] ) {
              

              coolGroup[iGroup] = false;
            }
          }
          for (int k=0; k<8; ++k) {                                

          int bit = eight & CYZO;                                    

          int iii = ii + offsets[k];                                 

            eight >>= 1;                                             

            if ( bit ) {                                             

              if ( ingroup[iii] < curGroup ) {                         

                

                ++onesCount;                                             

                if ( iii < id3 ) id3 = iii;                    

                ingroup[iii] = curGroup;                                 

              }
              continue;                                                

            }
            if ( ingroup[iii] ) continue;                            

            if ( (cys[iii] & CYEDGE) ) {                             

              if ( coolGroup[iGroup] ) {                               

                

                coolGroup[iGroup] = false;                               

              }
              continue;                                                

            }
            zfifo.push( iii );                                       

          } 

        } 


        

        

        

        


        if ( !coolGroup[iGroup] ) continue;                        

        

        if ( onesCount <= rtn ) continue;                          


        

        

        

        

        

        

        


        int stepCount;
        

        int original1 = id3;
        int backtrack = original1;
        int current1 = original1;

        for ( stepCount=0; (!stepCount || current1!=original1) && coolGroup[iGroup] ; ++stepCount) {
        int nAdj = 0;
        int nextIs[2];
        int currentRow = current1 / 1000;
        int currentCol = current1 % 1000;
          for ( int iOffset=1; iOffset<8 && coolGroup[iGroup]; iOffset+=2 ) {    

          int nextI = current1 + offsets[iOffset];      

            if ( cys[current1] & CYEDGE ) {               

              switch( offsets[iOffset] ) {
              case     1: if ( currentCol==(nCol-1) ) nextI = -1; break;
              case  1000: if ( currentRow==(nRow-1) ) nextI = -1; break;
              case    -1: if ( currentCol==       0 ) nextI = -1; break;
              case -1000: if ( currentRow==       0 ) nextI = -1; break;
              }
            }
            if ( nextI==-1 ) continue;                  

            if ( ingroup[nextI] != curGroup) continue;  

            if ( !(cys[nextI]&CYZO) ) continue;         

            nextIs[nAdj++] = nextI;                     

            

            if ( nAdj > 2) break;                       

          }

          if ( nAdj != 2 ) {                            

            coolGroup[iGroup] = false;                    

            break;                                        

          } else {
            if ( nextIs[0]!=backtrack ) {                 

              backtrack = current1;
              current1 = nextIs[0];
            } else {
              backtrack = current1;
              current1 = nextIs[1];
            }
            

            

          }
        } 

        

        

        if ( stepCount == onesCount ) rtn = onesCount;
      } 

    } 

    

    ADDACTUAL( rtn );
    return actuals;
  }
};











int
main( int ac, char** av) {
CF_CLASS Ainst = CF_CLASS( CF_CLASS_CTOR_ARGS );
VS vTxt;

  vTxt.clear();
  while ( cin.good() ) {
  char id0[CF_MAXINPLINELENGTH];
    cin.getline( id0, CF_MAXINPLINELENGTH);
    vTxt.push_back( string(id0) );
  }
  VS id4 = Ainst.CF_CLASS_METHOD( vTxt);
  for (int i=0; i<id4.size(); ++i ) cout << id4[i] << endl;
  return 0;
}


int
CFtest( VS& inputs, VS& expecteds, int iTest) {
int nInp = inputs.size();
int nExp = expecteds.size();

  CF_CLASS testInstance = CF_CLASS( CF_CLASS_CTOR_ARGS );
  VS actuals = testInstance.CF_CLASS_METHOD( inputs);
  int nAct = actuals.size();
  int err = 0;
  if ( nAct != nExp ) {
    err = 1;
  }
  for ( int i=0; i<min(nAct,nExp); ++i ) err |= (actuals[i]==expecteds[i]) ? 0 : 1;

  cout << "Test " << iTest;
  if ( err ) {
    cout << " <<<FAILURE>>>" << endl;
    if ( nAct != nExp ) cout << "  >>> Actuals (" << nAct << ") != Expecteds (" << nExp << ")" << endl;
    for ( int i=0; i<max(nAct,nExp) ; ++i) {
      cout << "  >>> EXP " << i << ":  <" << (i>=nExp ? "missing" : expecteds[i]) << ">" << endl;
      cout << "  >>> ACT " << i << ":  <" << (i>=nAct ? "missing" : actuals[i])   << ">" << endl;
    }
  } else {
    cout << " <<<SUCCESS>>>" << endl;
  }
  if ( getenv( "CF_LOG" ) ) {
    cout << "  " << nInp << " INPUT(S):" << endl;
    for ( int i=0; i<nInp; ++i) cout << "    <" << inputs[i] << ">" << endl;
    if ( !err ) {
      cout << "  " << nExp << " EXPECTED(S):" << endl;
      for ( int i=0; i<nExp; ++i) cout << "    <" << expecteds[i] << ">" << endl;
    }
  }

  return iTest+1;
}

int
main( int ac, char** av) {
ifstream istr;
char id0[CF_MAXINPLINELENGTH];
string inp;
char guardStart[1024];
char guardEnd[1024];
char guardInput[1024];
char guardOutput[1024];
enum { STINIT=0
     , id1
     , STINPUT
     , STOUTPUT
     , STDONE
     , STLAST
     };
VS inputs;
VS expecteds;

  sprintf( guardStart, "input[%s]start", __FILE__);
  sprintf( guardEnd, "input[%s]end", __FILE__);
  sprintf( guardInput, "Input");
  sprintf( guardOutput, "Output");

  int state = STINIT;
  int iTest = 0;

  istr.open( __FILE__ );
  while ( istr.good() && state!=STDONE ) {
    istr.getline( id0, CF_MAXINPLINELENGTH);

    switch (state) {
    case STINIT:
      if ( !strcmp(guardStart,id0) ) state = id1;
      break;

    case id1:
      if ( !strcmp( guardInput, id0) ) {
        inputs.clear();
        state=STINPUT;
      }
      break;

    case STINPUT:
      if ( !strcmp( guardOutput, id0) ) {
        state=STOUTPUT;
        expecteds.clear();
      } else {

        if ( strlen(id0) )


          inputs.push_back( id0);
      }
      break;

    case STOUTPUT:
      if ( !strcmp( guardInput, id0) || !strcmp( guardEnd,id0) ) {
        iTest = CFtest( inputs, expecteds, iTest);
        if ( !strcmp( guardInput, id0) ) {
          inputs.clear();
          state=STINPUT;
        } else {
          state=STDONE;
        }
      } else {  


        if ( strlen(id0) )


          expecteds.push_back( id0);
      }
      break;

    default: break;
    }

  } 

  istr.close();
  return 0;
}



