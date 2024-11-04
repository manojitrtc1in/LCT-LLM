






















using namespace std;




  
  

  
  



  


template<class T> ostream& operator<<(ostream& os, vector<T> v) 

{
  for(int i=0; i<v.size(); i++)
    os << v[i] << " ";
  os << endl;
  return os;
}  





clock_t time0;
clock_t time1;
void timeStart() {
  
  time0 = clock();
  time1 = time0;
  
  }
  
void timeStop(const char *sz) {
  
  clock_t time = clock();
  cerr << sz << " + " << ((time-time1)*1.0/CLOCKS_PER_SEC) << " = "
       << ((time-time0)*1.0/CLOCKS_PER_SEC) << endl;
  time1 = time;
  
  }




















                       if (rv >= 0 && (a < 0 || rv < a)) a = rv; }






class id4;


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



class id17 

{
  public:
  int L;
  int nLog; 

  const int *an;
  int *ai; 

           


  id17(int L, const int *an)
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
  
  ~id17()
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
    int id8 = ai[nPow*L + b - d + 1];
    if (an[id8] < an[iMin])
      iMin = id8;

    return iMin;
  }
  
}; 





template<class Key>
void bucketSort(const Key *anKeys, int L, int d, int *ai)
{
  array(acBuck, int, d+1);
  rep(i, L) acBuck[anKeys[i]]++;
  int id2 = 0;
  rep2(j, 0, d) {
    int c = acBuck[j];
    acBuck[j] = id2;
    id2 += c;
  }
  assert(id2 == L);
  array(a2, int, L);
  rep(i, L) a2[acBuck[anKeys[ai[i]]]++] = ai[i];
  rep(i, L) ai[i] = a2[i];
  free(acBuck); free(a2);
} 


class id4
{
  public:
  const char *buf;
  const char **asz;
  int *aisz; 

  int *id0;
  int L;
  int id10; 

  id17 *prmq;
  
  id4(const char *buf) 

  {
    if (bDebug2) cerr << "generating suffix table for " << buf << endl;
    this->buf = buf;
    L = strlen(buf);
    asz = new const char*[L]();
    id0 = new int[L]();
    aisz = new int[L]();

    

    

    int nLog = 0;
    while ((1<<nLog) <= L) nLog++;
    

    array(anKey, int, (nLog+1)*L);
    

    array(anKey2, int, L);
    

    array(aiSeq, int, L);
    int id15 = *max_element(buf, buf + L);
    setMax(id15, L);
    
    

    

    rep(i, L) aiSeq[i] = i;
    bucketSort(buf, L, id15, aiSeq);
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
      bucketSort(anKey2, L, id15, aiSeq);
      
      

      bucketSort(anKey + (k-1)*L, L, id15, aiSeq);
      if (bDebug2) {
        cerr << "sequence on level " << k << ", length " << (1<<k) << endl;
        rep(i, L) cerr << aiSeq[i] << " ";
        cerr << endl;
      }
      
      

      int nKey = 1;
      

      

      int id14, id11;
      int id12 = 0, id3 = 0;
      rep(i, L) {
        id14 = anKey[(k-1)*L + aiSeq[i]];
        id11 = (aiSeq[i] + d < L) ? anKey[(k-1)*L + aiSeq[i] + d] : 0;
        if (i > 0) {
          

          if (id14 != id12 || id11 != id3)
            nKey++;
        }
        anKey[k*L + aiSeq[i]] = nKey;
        id12 = id14, id3 = id11;
      }
      
      if (bDebug2) {
        cerr << "keys on level " << k << ", length " << (1<<k) << endl;
        rep(i, L) cerr << anKey[k*L + i] << " ";
        cerr << endl;
      }

    }
    rep(i, L) asz[i] = buf + aiSeq[i];
    
    

    rep(i, L) {
      id0[i] = 0;
      if (i == 0) continue;
      int x = aiSeq[i];
      int y = aiSeq[i-1];
      rep2d(k, nLog-1, 0) {
        int *anKeyK = anKey + k * L;
        if (x < L && y < L && anKeyK[x] == anKeyK[y]) {
          id0[i] += (1<<k);
          x += (1<<k), y += (1<<k);
        }
      }
    }

    free(anKey); free(anKey2); free(aiSeq);

    rep(i, L) {
      assert(asz[i] >= buf && asz[i] < buf + L);
      aisz[asz[i] - buf] = i;
    }
    
    prmq = new id17(L, id0);
  } 

  
  ~id4() 

  {
    delete[] asz;
    delete[] id0;
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

    int &id6; 

    int &id18; 

    const id4 &m_t;
    Comp(const id4 &t, const char *sz, int &nLen, int &isz)
      : m_t(t), id6(nLen), id18(isz)
    {
      m_sz = sz;
      id6 = 0;
      id18 = 0;
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
      int c = min(m_t.lcp(id18, isz2), id6);
      while (sz1[c] == sz2[c] && sz1[c])
        c++, cOp++;
      bool bRv = sz1[c] < sz2[c];
      if (c > id6) id18 = isz2, id6 = c;
      

        

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
    

    

    

    

    int id16, iszComp; 

    Comp comp(*this, sz, id16, iszComp);
    int i = upper_bound(asz, asz + L, sz, comp) - asz;
    

    

    

    if (i < L) {
      id10 = min(lcp(iszComp, i), id16);
      while (sz[id10] && asz[i][id10] == sz[id10])
        id10++, cOp++;
    } else
      id10 = 0;
    

    if (i > 0) {
      int id9 = min(lcp(iszComp, i-1), id16);
      while (sz[id9] && asz[i-1][id9] == sz[id9])
        id9++, cOp++;
      if (id9 > id10) {
        i--;
        id10 = id9;
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
      v = id0[i];
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
      os << id0[i] << " " << asz[i] << endl;
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
  id4 *at[n];
  rep(i, n) {
    cin >> szTest[i];
    cin >> acMin[i];
    cin >> acMax[i];
    at[i] = new id4(szTest[i]);
  }
  id4 t0(buf);
  if (bDebug) t0.dump(cerr);
  timeStop("suffix tables constructed");
  
  

  rep(iTest, n) {
    id4 &t = *at[iTest];
    int id1, id13;
    rep(isz, t.L) {
      id1 = 1;
      id13 = t.len(isz);
      if (acMax[iTest] == 0)
        

        id13 = 0;
      else {
        if (acMin[iTest] > 1)
          id13 = t.lcp(isz, isz + acMin[iTest] - 1);
        if (isz + 1 < t.L)
          id1 = t.lcp(isz, isz + acMax[iTest]) + 1;
      }
      

      

      if (id1 <= t.id0[isz])
        setMax(id1, min(anMinLen[iTest][isz-1], t.id0[isz] + 1));
      if (isz > 0)
        setMax(id13, min(anMaxLen[iTest][isz-1], t.id0[isz]));
      anMinLen[iTest][isz] = id1;
      anMaxLen[iTest][isz] = id13;
      if (bDebug) cerr << "inner lengths for " << szTest[iTest]
        << ":" << acMin[iTest] << ":" << acMax[iTest] << ", " << t.asz[isz]
        << ": " << id1 << " " << id13 << endl;
    }
  }
  timeStop("inner lengths calculated");
  
  rep2(i, 0, t0.L - 1) {
    anMinLen0[i] = t0.id0[i] + 1, anMaxLen0[i] = t0.len(i);
  }

  rep(iTest, n) {
    id4 &t = *at[iTest];
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
          c2 = min(c2, t.id0[k]);
          while (t0.asz[i][c2] && t0.asz[i][c2] == t.asz[k][c2]) c2++, cOp++;
        } else {
          c2 = 0;
        }
      }
      
      int j = k;
      int id10 = c2;
      if (j == t.L || (j > 0 && c2 < c1))
        j--, id10 = c1;
      

      int id5 = anMinLen0[i], id7 = anMaxLen0[i];
      if (bDebug) cerr << "found: " << t0.asz[i] << " "
        << t.asz[j] << " " << deb(id10)
        << ", inner " << anMinLen[iTest][j] << ":" << anMaxLen[iTest][j]
        << endl;
      if (acMax[iTest] == 0) {
        setMax(id5, id10 + 1);
      } else {
        if (anMinLen[iTest][j] > id10) 
          

          setMax(id5, id10 + 1)
        else
          setMax(id5, anMinLen[iTest][j]);
        if (acMin[iTest] != 0) {
          if (anMaxLen[iTest][j] >= id10)
            setMin(id7, id10)
          else
            setMin(id7, anMaxLen[iTest][j]);
        }
      }
      anMinLen0[i] = id5, anMaxLen0[i] = id7;

      if (bDebug2) cerr << deb(i) << deb(iTest) << deb(id5)
        << deb(id7) << endl;
      
      i++;
      

      

      

      if (i < t0.L) {
        if (k > 0) {
          c1 = min(c1, t0.id0[i]);
          while (t0.asz[i][c1] && t0.asz[i][c1] == t.asz[k-1][c1])
            c1++, cOp++;
        } else
          c1 = 0;
        if (k < t.L) {
          c2 = min(c2, t0.id0[i]);
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
  
  cerr << deb(cOp) << endl;
  
}



