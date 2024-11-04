



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;



#ifdef DEBUG
  #define bDebug 1
  #define bDebug2 1
#else
  #define bDebug 0
  #define bDebug2 0
#endif
#define deb(a) #a << "=" << (a) << " "
#ifndef HOME
  #define assert(a) {}
#endif

template<class T> ostream& operator<<(ostream& os, vector<T> v) 

{
  for(int i=0; i<v.size(); i++)
    os << v[i] << " ";
  os << endl;
  return os;
}  




#include <time.h>
clock_t time0;
clock_t time1;
void timeStart() {
  #ifdef MIERZ
  time0 = clock();
  time1 = time0;
  #endif
  }
  
void timeStop(const char *sz) {
  #ifdef MIERZ
  clock_t time = clock();
  cerr << sz << " + " << ((time-time1)*1.0/CLOCKS_PER_SEC) << " = "
       << ((time-time0)*1.0/CLOCKS_PER_SEC) << endl;
  time1 = time;
  #endif
  }





#define array(a, type, count) type *a = (type*)calloc(sizeof(type), count)
#define eps 1e-9
#define eq(a, b) ( (a) > (b) - eps && (a) < (b) + eps )
#define eraseAll(v) v.erase(v.begin(), v.end())
#define fi first
#define rep(i,n) for(long i=0; i<(n); i++)
#define rep2(i,a,b) for(long i=(a); i<=(b); i++)
#define rep2d(i,a,b) for(long i=(a); i>=(b); i--)
#define zeroMem(a) memset(a, 0, sizeof(a))
#define zeroMem2(a, n) memset(a, 0, sizeof(*a) * n)
#define fore(it,L) for(typeof(L.begin()) it=L.begin(); it!=L.end(); it++)
#define eraseAll(v) v.erase(v.begin(), v.end())
#define se second
#define setMin(a,b) { typeof(a) rv = (b); if (rv < a) a = rv; }
#define setMinP(a,b) { typeof(a) rv = (b); \
                       if (rv >= 0 && (a < 0 || rv < a)) a = rv; }
#define setMax(a,b) { typeof(a) rv = (b); if (rv > a) a = rv; } 
#define swap(a,b) { typeof(a) swapVar = a; a = b; b = swapVar; }
#define Int long long



class SufTable;
#define M1 50055
#define M2 11
char buf[M1];
char szTest[M2][M1];
int acMin[M2];
int acMax[M2];
int n;
int anMinLen0[M1]; 

int anMaxLen0[M1]; 

int anMinLen[M2][M1]; 

int anMaxLen[M2][M1]; 

int cOp = 0;



class RangeMinQuery 

{
  public:
  int L;
  int nLog; 

  const int *an;
  int *ai; 

           


  RangeMinQuery(int L, const int *an)
  {
    this->L = L;
    this->an = an;
    nLog = 2;
    while ((1<<nLog) < L) nLog++;
    nLog--;
    ai = new int[(nLog+1) * L];
    
    rep(i, L) ai[0*L + i] = i;
    
    rep2(nPow, 1, nLog) {
      rep(i, L) {
        int j = ai[(nPow-1)*L + i];
        int d = (1<<(nPow-1));
        if (i+d < L && an[ai[(nPow-1)*L + i+d]] < an[j])
          j = ai[(nPow-1)*L + i+d];
        ai[nPow*L + i] = j;
      }
    }
  }
  
  ~RangeMinQuery()
  {
    delete[] ai;
  }
  
  int get(int a, int b)
  {
    

    

    if (a < 0) a = 0;
    if (b >= L) b = L - 1;
    if (a == b) return a;
    
    int iMin = a;
    int nPow = 31 - __builtin_clz(b-a);
    int d = (1<<nPow);
    assert(a + d <= b);
    assert(a + d + 1 >= b - d + 1);
    assert(b - d + 1 >= a);
    iMin = ai[nPow*L + a];
    int iMinB = ai[nPow*L + b - d + 1];
    if (an[iMinB] < an[iMin])
      iMin = iMinB;

    return iMin;
  }
  
}; 





template<class Key>
void bucketSort(const Key *anKeys, int L, int d, int *ai)
{
  array(acBuck, int, d+1);
  rep(i, L) acBuck[anKeys[i]]++;
  int iOfs = 0;
  rep2(j, 0, d) {
    int c = acBuck[j];
    acBuck[j] = iOfs;
    iOfs += c;
  }
  assert(iOfs == L);
  array(a2, int, L);
  rep(i, L) a2[acBuck[anKeys[ai[i]]]++] = ai[i];
  rep(i, L) ai[i] = a2[i];
  free(acBuck); free(a2);
} 


class SufTable
{
  public:
  const char *buf;
  const char **asz;
  int *aisz; 

  int *aLCP;
  int L;
  int nPrefLen; 

  RangeMinQuery *prmq;
  
  SufTable(const char *buf) 

  {
    if (bDebug2) cerr << "generating suffix table for " << buf << endl;
    this->buf = buf;
    L = strlen(buf);
    asz = new const char*[L]();
    aLCP = new int[L]();
    aisz = new int[L]();

    

    

    int nLog = 0;
    while ((1<<nLog) <= L) nLog++;
    

    array(anKey, int, (nLog+1)*L);
    

    array(anKey2, int, L);
    

    array(aiSeq, int, L);
    int nMaxKey = *max_element(buf, buf + L);
    setMax(nMaxKey, L);
    
    

    

    rep(i, L) aiSeq[i] = i;
    bucketSort(buf, L, nMaxKey, aiSeq);
    int nKey = 1;
    rep(i, L) {
      if (i > 0 && buf[aiSeq[i]] != buf[aiSeq[i-1]])
        nKey++;
      anKey[0*L + aiSeq[i]] = nKey;
    }
    if (bDebug2) {
      cerr << "initial keys:" << endl;
      rep(i, L) cerr << anKey[0*L + i] << " ";
      cerr << endl;
      cerr << "initial sequence:" << endl;
      rep(i, L) cerr << aiSeq[i] << " ";
      cerr << endl;
    }

    rep2(k, 1, nLog) {
      int d = 1 << (k-1);

      

      rep(i, L)
        anKey2[i] = (i + d < L) ? anKey[(k-1)*L + i + d] : 0;
      bucketSort(anKey2, L, nMaxKey, aiSeq);
      
      

      bucketSort(anKey + (k-1)*L, L, nMaxKey, aiSeq);
      if (bDebug2) {
        cerr << "sequence on level " << k << ", length " << (1<<k) << endl;
        rep(i, L) cerr << aiSeq[i] << " ";
        cerr << endl;
      }
      
      

      int nKey = 1;
      

      

      int nKey1a, nKey1b;
      int nKey2a = 0, nKey2b = 0;
      rep(i, L) {
        nKey1a = anKey[(k-1)*L + aiSeq[i]];
        nKey1b = (aiSeq[i] + d < L) ? anKey[(k-1)*L + aiSeq[i] + d] : 0;
        if (i > 0) {
          

          if (nKey1a != nKey2a || nKey1b != nKey2b)
            nKey++;
        }
        anKey[k*L + aiSeq[i]] = nKey;
        nKey2a = nKey1a, nKey2b = nKey1b;
      }
      
      if (bDebug2) {
        cerr << "keys on level " << k << ", length " << (1<<k) << endl;
        rep(i, L) cerr << anKey[k*L + i] << " ";
        cerr << endl;
      }

    }
    rep(i, L) asz[i] = buf + aiSeq[i];
    
    

    rep(i, L) {
      aLCP[i] = 0;
      if (i == 0) continue;
      int x = aiSeq[i];
      int y = aiSeq[i-1];
      rep2d(k, nLog-1, 0) {
        int *anKeyK = anKey + k * L;
        if (x < L && y < L && anKeyK[x] == anKeyK[y]) {
          aLCP[i] += (1<<k);
          x += (1<<k), y += (1<<k);
        }
      }
    }

    free(anKey); free(anKey2); free(aiSeq);

    rep(i, L) {
      assert(asz[i] >= buf && asz[i] < buf + L);
      aisz[asz[i] - buf] = i;
    }
    
    prmq = new RangeMinQuery(L, aLCP);
  } 

  
  ~SufTable() 

  {
    delete[] asz;
    delete[] aLCP;
    delete[] aisz;
    delete prmq;
  } 

  
  int getInd(const char *sz) const 

  {
    

    if (sz < buf || sz >= buf + L) return -1;
    return aisz[sz - buf];
  } 

  
  private:
  class Comp 

  {
    

    

    

    

    

    

    

    

    

    public:
    const char *m_sz; 

    int &m_nLen; 

    int &m_isz; 

    const SufTable &m_t;
    Comp(const SufTable &t, const char *sz, int &nLen, int &isz)
      : m_t(t), m_nLen(nLen), m_isz(isz)
    {
      m_sz = sz;
      m_nLen = 0;
      m_isz = 0;
    }
    
    bool operator() (const char *sz1, const char *sz2)
    {
      

      

      if (sz1 != m_sz && sz2 != m_sz)
        return (strcmp(sz1, sz2) < 0);
      assert(sz1 == m_sz || sz2 == m_sz);
      bool bInv = (sz1 != m_sz);
      if (bInv) swap(sz1, sz2);
      assert(sz1 == m_sz && sz2 >= m_t.buf && sz2 < m_t.buf + m_t.L);
      int isz2 = m_t.getInd(sz2);
      int c = min(m_t.lcp(m_isz, isz2), m_nLen);
      while (sz1[c] == sz2[c] && sz1[c])
        c++, cOp++;
      bool bRv = sz1[c] < sz2[c];
      if (c > m_nLen) m_isz = isz2, m_nLen = c;
      

        

      cOp++;
      return bInv ? !bRv : bRv;
    }
  }; 


  public:
  int count(int iWord, int nLen) const 

  {
    

    

    int c = 0;
    rep(i, L)
      if (comPrefLen(asz[iWord], asz[i]) >= nLen)
        c++;
    

    return c;
  } 

  
  int find(const char *sz) 

  {
    

    

    

    

    int nLenComp, iszComp; 

    Comp comp(*this, sz, nLenComp, iszComp);
    int i = upper_bound(asz, asz + L, sz, comp) - asz;
    

    

    

    if (i < L) {
      nPrefLen = min(lcp(iszComp, i), nLenComp);
      while (sz[nPrefLen] && asz[i][nPrefLen] == sz[nPrefLen])
        nPrefLen++, cOp++;
    } else
      nPrefLen = 0;
    

    if (i > 0) {
      int nPrefLen2 = min(lcp(iszComp, i-1), nLenComp);
      while (sz[nPrefLen2] && asz[i-1][nPrefLen2] == sz[nPrefLen2])
        nPrefLen2++, cOp++;
      if (nPrefLen2 > nPrefLen) {
        i--;
        nPrefLen = nPrefLen2;
      }
    }
    return i;
  } 

  
  int lcp(int a, int b) const 

  {
    

    if (a == b) {
      return len(a);
    }
    if (a > b) swap(a, b);
    int v = 0;
    if (a >= 0 && b < L && a < b) {
      int i = prmq->get(a + 1, b);
      assert(i >= 0 && i < L);
      v = aLCP[i];
    }
    if (bDebug2) cerr << "minLCP " << deb(a) << deb(b) << deb(L)
      << " : " << v << endl;
    return v;
  } 

  
  static bool less(const char *sz1, const char *sz2) 

  {
    return strcmp(sz1, sz2) < 0;
  } 

  
  static int comPrefLen(const char *sz1, const char *sz2) 

  {
    int c = 0;
    while (sz1[c] == sz2[c] && sz1[c]) c++;
    return c;
  } 

  
  int len(int i) const 

  {
    return buf + L - asz[i];
  } 

  
  void dump(ostream &os) 

  {
    rep(i, L) {
      os << aLCP[i] << " " << asz[i] << endl;
    }
    os << endl;
  } 

};

main ()
{
  timeStart();
  

  

  cin >> buf;
  cin >> n;
  if (bDebug) cerr << "input string: " << buf << endl;
  SufTable *at[n];
  rep(i, n) {
    cin >> szTest[i];
    cin >> acMin[i];
    cin >> acMax[i];
    at[i] = new SufTable(szTest[i]);
  }
  SufTable t0(buf);
  if (bDebug) t0.dump(cerr);
  timeStop("suffix tables constructed");
  
  

  rep(iTest, n) {
    SufTable &t = *at[iTest];
    int nMinLen, nMaxLen;
    rep(isz, t.L) {
      nMinLen = 1;
      nMaxLen = t.len(isz);
      if (acMax[iTest] == 0)
        

        nMaxLen = 0;
      else {
        if (acMin[iTest] > 1)
          nMaxLen = t.lcp(isz, isz + acMin[iTest] - 1);
        if (isz + 1 < t.L)
          nMinLen = t.lcp(isz, isz + acMax[iTest]) + 1;
      }
      

      

      if (nMinLen <= t.aLCP[isz])
        setMax(nMinLen, min(anMinLen[iTest][isz-1], t.aLCP[isz] + 1));
      if (isz > 0)
        setMax(nMaxLen, min(anMaxLen[iTest][isz-1], t.aLCP[isz]));
      anMinLen[iTest][isz] = nMinLen;
      anMaxLen[iTest][isz] = nMaxLen;
      if (bDebug) cerr << "inner lengths for " << szTest[iTest]
        << ":" << acMin[iTest] << ":" << acMax[iTest] << ", " << t.asz[isz]
        << ": " << nMinLen << " " << nMaxLen << endl;
    }
  }
  timeStop("inner lengths calculated");
  
  rep2(i, 0, t0.L - 1) {
    anMinLen0[i] = t0.aLCP[i] + 1, anMaxLen0[i] = t0.len(i);
  }

  rep(iTest, n) {
    SufTable &t = *at[iTest];
    int i = 0, k = 0;
    int c1 = 0; 

    int c2 = 0; 

    while (t0.asz[i][c2] && t0.asz[i][c2] == t.asz[k][c2])
      c2++, cOp++;
    while (i < t0.L) {
      if (bDebug) cerr << endl << "trying " << deb(i) << deb(t0.len(i))
        << t0.asz[i] << endl;
      

      while (k < t.L) {
        

        if (t0.asz[i][c2] < t.asz[k][c2])
          break;
        if (k > 0 && t0.asz[i][c1] >= t.asz[k-1][c1] && t0.asz[i][c2] < t.asz[k][c2])
          break;
        k++;
        

        

        

        c1 = c2;
        if (k < t.L) {
          c2 = min(c2, t.aLCP[k]);
          while (t0.asz[i][c2] && t0.asz[i][c2] == t.asz[k][c2]) c2++, cOp++;
        } else {
          c2 = 0;
        }
      }
      
      int j = k;
      int nPrefLen = c2;
      if (j == t.L || (j > 0 && c2 < c1))
        j--, nPrefLen = c1;
      

      int nLenMin = anMinLen0[i], nLenMax = anMaxLen0[i];
      if (bDebug) cerr << "found: " << t0.asz[i] << " "
        << t.asz[j] << " " << deb(nPrefLen)
        << ", inner " << anMinLen[iTest][j] << ":" << anMaxLen[iTest][j]
        << endl;
      if (acMax[iTest] == 0) {
        setMax(nLenMin, nPrefLen + 1);
      } else {
        if (anMinLen[iTest][j] > nPrefLen) 
          

          setMax(nLenMin, nPrefLen + 1)
        else
          setMax(nLenMin, anMinLen[iTest][j]);
        if (acMin[iTest] != 0) {
          if (anMaxLen[iTest][j] >= nPrefLen)
            setMin(nLenMax, nPrefLen)
          else
            setMin(nLenMax, anMaxLen[iTest][j]);
        }
      }
      anMinLen0[i] = nLenMin, anMaxLen0[i] = nLenMax;

      if (bDebug2) cerr << deb(i) << deb(iTest) << deb(nLenMin)
        << deb(nLenMax) << endl;
      
      i++;
      

      

      

      if (i < t0.L) {
        if (k > 0) {
          c1 = min(c1, t0.aLCP[i]);
          while (t0.asz[i][c1] && t0.asz[i][c1] == t.asz[k-1][c1])
            c1++, cOp++;
        } else
          c1 = 0;
        if (k < t.L) {
          c2 = min(c2, t0.aLCP[i]);
          while (t0.asz[i][c2] && t0.asz[i][c2] == t.asz[k][c2])
            c2++, cOp++;
        } else {
          c2 = 0;
        }
      }
    }
  }

  Int nRes = 0;
  rep2(i, 0, t0.L - 1)
    if (anMinLen0[i] > 0 && anMaxLen0[i] >= anMinLen0[i]) {
      nRes += anMaxLen0[i] - anMinLen0[i] + 1;
      if (bDebug) cerr << "adding " << t0.asz[i] << " "
        << deb(anMinLen0[i]) << deb(anMaxLen0[i]) << endl;
    }
  
  cout << nRes << endl;
  timeStop("done");
  #ifdef MIERZ
  cerr << deb(cOp) << endl;
  #endif
}



