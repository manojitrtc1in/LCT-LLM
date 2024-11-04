



using namespace std;





int sais(const char *T, int *SA, int n);

char s[100001];
int sa[100001], len;

int main() {
    map<int,int> occurs;
    int begin = 0, end;

    cin >> s;
    len = strlen(s);
    end = len - 1;

    sais(s, sa, len);

    FOR(i,0,len) {
        while(s[sa[begin] + i] < s[i]) begin++; 

        while(s[sa[end] + i] > s[i]) end--; 


        if(s[sa[begin]+i+1] == 0)
            occurs[i+1] = end - begin + 1;
    }

    cout << occurs.size() << endl;
    for(auto it = occurs.begin(); it != occurs.end(); ++it)
        cout << it->first << " " << it->second << endl;

    return 0;
}






















static
void
getCounts(const void *T, id2 *C, id2 n, id2 k, int cs) {
  id2 i;
  for(i = 0; i < k; ++i) { C[i] = 0; }
  for(i = 0; i < n; ++i) { ++C[chr(i)]; }
}
static
void
getBuckets(const id2 *C, id2 *B, id2 k, sais_bool_type end) {
  id2 i, sum = 0;
  if(end) { for(i = 0; i < k; ++i) { sum += C[i]; B[i] = sum; } }
  else { for(i = 0; i < k; ++i) { sum += C[i]; B[i] = sum - C[i]; } }
}


static
void
id5(const void *T, id2 *SA,
         id2 *C, id2 *B,
         id2 n, id2 k, int cs) {
  id2 *b, i, j;
  id2 c0, c1;

  
  if(C == B) { getCounts(T, C, n, k, cs); }
  getBuckets(C, B, k, 0); 
  j = n - 1;
  b = SA + B[c1 = chr(j)];
  --j;
  *b++ = (chr(j) < c1) ? ~j : j;
  for(i = 0; i < n; ++i) {
    if(0 < (j = SA[i])) {
      assert(chr(j) >= chr(j + 1));
      if((c0 = chr(j)) != c1) { B[c1] = b - SA; b = SA + B[c1 = c0]; }
      assert(i < (b - SA));
      --j;
      *b++ = (chr(j) < c1) ? ~j : j;
      SA[i] = 0;
    } else if(j < 0) {
      SA[i] = ~j;
    }
  }
  
  if(C == B) { getCounts(T, C, n, k, cs); }
  getBuckets(C, B, k, 1); 
  for(i = n - 1, b = SA + B[c1 = 0]; 0 <= i; --i) {
    if(0 < (j = SA[i])) {
      assert(chr(j) <= chr(j + 1));
      if((c0 = chr(j)) != c1) { B[c1] = b - SA; b = SA + B[c1 = c0]; }
      assert((b - SA) <= i);
      --j;
      *--b = (chr(j) > c1) ? ~(j + 1) : j;
      SA[i] = 0;
    }
  }
}
static
id2
id0(const void *T, id2 *SA,
             id2 n, id2 m, int cs) {
  id2 i, j, p, q, plen, qlen, name;
  id2 c0, c1;
  sais_bool_type diff;

  
  assert(0 < n);
  for(i = 0; (p = SA[i]) < 0; ++i) { SA[i] = ~p; assert((i + 1) < n); }
  if(i < m) {
    for(j = i, ++i;; ++i) {
      assert(i < n);
      if((p = SA[i]) < 0) {
        SA[j++] = ~p; SA[i] = 0;
        if(j == m) { break; }
      }
    }
  }

  
  i = n - 1; j = n - 1; c0 = chr(n - 1);
  do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) >= c1));
  for(; 0 <= i;) {
    do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) <= c1));
    if(0 <= i) {
      SA[m + ((i + 1) >> 1)] = j - i; j = i + 1;
      do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) >= c1));
    }
  }

  
  for(i = 0, name = 0, q = n, qlen = 0; i < m; ++i) {
    p = SA[i], plen = SA[m + (p >> 1)], diff = 1;
    if((plen == qlen) && ((q + plen) < n)) {
      for(j = 0; (j < plen) && (chr(p + j) == chr(q + j)); ++j) { }
      if(j == plen) { diff = 0; }
    }
    if(diff != 0) { ++name, q = p, qlen = plen; }
    SA[m + (p >> 1)] = name;
  }

  return name;
}
static
void
id8(const void *T, id2 *SA,
         id2 *C, id2 *B, id2 *D,
         id2 n, id2 k, int cs) {
  id2 *b, i, j, t, d;
  id2 c0, c1;
  assert(C != B);

  
  getBuckets(C, B, k, 0); 
  j = n - 1;
  b = SA + B[c1 = chr(j)];
  --j;
  t = (chr(j) < c1);
  j += n;
  *b++ = (t & 1) ? ~j : j;
  for(i = 0, d = 0; i < n; ++i) {
    if(0 < (j = SA[i])) {
      if(n <= j) { d += 1; j -= n; }
      assert(chr(j) >= chr(j + 1));
      if((c0 = chr(j)) != c1) { B[c1] = b - SA; b = SA + B[c1 = c0]; }
      assert(i < (b - SA));
      --j;
      t = c0; t = (t << 1) | (chr(j) < c1);
      if(D[t] != d) { j += n; D[t] = d; }
      *b++ = (t & 1) ? ~j : j;
      SA[i] = 0;
    } else if(j < 0) {
      SA[i] = ~j;
    }
  }
  for(i = n - 1; 0 <= i; --i) {
    if(0 < SA[i]) {
      if(SA[i] < n) {
        SA[i] += n;
        for(j = i - 1; SA[j] < n; --j) { }
        SA[j] -= n;
        i = j;
      }
    }
  }

  
  getBuckets(C, B, k, 1); 
  for(i = n - 1, d += 1, b = SA + B[c1 = 0]; 0 <= i; --i) {
    if(0 < (j = SA[i])) {
      if(n <= j) { d += 1; j -= n; }
      assert(chr(j) <= chr(j + 1));
      if((c0 = chr(j)) != c1) { B[c1] = b - SA; b = SA + B[c1 = c0]; }
      assert((b - SA) <= i);
      --j;
      t = c0; t = (t << 1) | (chr(j) > c1);
      if(D[t] != d) { j += n; D[t] = d; }
      *--b = (t & 1) ? ~(j + 1) : j;
      SA[i] = 0;
    }
  }
}
static
id2
id3(id2 *SA, id2 n, id2 m) {
  id2 i, j, d, name;

  
  assert(0 < n);
  for(i = 0, name = 0; (j = SA[i]) < 0; ++i) {
    j = ~j;
    if(n <= j) { name += 1; }
    SA[i] = j;
    assert((i + 1) < n);
  }
  if(i < m) {
    for(d = i, ++i;; ++i) {
      assert(i < n);
      if((j = SA[i]) < 0) {
        j = ~j;
        if(n <= j) { name += 1; }
        SA[d++] = j; SA[i] = 0;
        if(d == m) { break; }
      }
    }
  }
  if(name < m) {
    
    for(i = m - 1, d = name + 1; 0 <= i; --i) {
      if(n <= (j = SA[i])) { j -= n; --d; }
      SA[m + (j >> 1)] = d;
    }
  } else {
    
    for(i = 0; i < m; ++i) {
      if(n <= (j = SA[i])) { j -= n; SA[i] = j; }
    }
  }

  return name;
}


static
void
id4(const void *T, id2 *SA,
         id2 *C, id2 *B,
         id2 n, id2 k, int cs) {
  id2 *b, i, j;
  id2 c0, c1;
  
  if(C == B) { getCounts(T, C, n, k, cs); }
  getBuckets(C, B, k, 0); 
  j = n - 1;
  b = SA + B[c1 = chr(j)];
  *b++ = ((0 < j) && (chr(j - 1) < c1)) ? ~j : j;
  for(i = 0; i < n; ++i) {
    j = SA[i], SA[i] = ~j;
    if(0 < j) {
      --j;
      assert(chr(j) >= chr(j + 1));
      if((c0 = chr(j)) != c1) { B[c1] = b - SA; b = SA + B[c1 = c0]; }
      assert(i < (b - SA));
      *b++ = ((0 < j) && (chr(j - 1) < c1)) ? ~j : j;
    }
  }
  
  if(C == B) { getCounts(T, C, n, k, cs); }
  getBuckets(C, B, k, 1); 
  for(i = n - 1, b = SA + B[c1 = 0]; 0 <= i; --i) {
    if(0 < (j = SA[i])) {
      --j;
      assert(chr(j) <= chr(j + 1));
      if((c0 = chr(j)) != c1) { B[c1] = b - SA; b = SA + B[c1 = c0]; }
      assert((b - SA) <= i);
      *--b = ((j == 0) || (chr(j - 1) > c1)) ? ~j : j;
    } else {
      SA[i] = ~j;
    }
  }
}
static
id2
id1(const void *T, id2 *SA,
           id2 *C, id2 *B,
           id2 n, id2 k, int cs) {
  id2 *b, i, j, pidx = -1;
  id2 c0, c1;
  
  if(C == B) { getCounts(T, C, n, k, cs); }
  getBuckets(C, B, k, 0); 
  j = n - 1;
  b = SA + B[c1 = chr(j)];
  *b++ = ((0 < j) && (chr(j - 1) < c1)) ? ~j : j;
  for(i = 0; i < n; ++i) {
    if(0 < (j = SA[i])) {
      --j;
      assert(chr(j) >= chr(j + 1));
      SA[i] = ~((id2)(c0 = chr(j)));
      if(c0 != c1) { B[c1] = b - SA; b = SA + B[c1 = c0]; }
      assert(i < (b - SA));
      *b++ = ((0 < j) && (chr(j - 1) < c1)) ? ~j : j;
    } else if(j != 0) {
      SA[i] = ~j;
    }
  }
  
  if(C == B) { getCounts(T, C, n, k, cs); }
  getBuckets(C, B, k, 1); 
  for(i = n - 1, b = SA + B[c1 = 0]; 0 <= i; --i) {
    if(0 < (j = SA[i])) {
      --j;
      assert(chr(j) <= chr(j + 1));
      SA[i] = (c0 = chr(j));
      if(c0 != c1) { B[c1] = b - SA; b = SA + B[c1 = c0]; }
      assert((b - SA) <= i);
      *--b = ((0 < j) && (chr(j - 1) > c1)) ? ~((id2)chr(j - 1)) : j;
    } else if(j != 0) {
      SA[i] = ~j;
    } else {
      pidx = i;
    }
  }
  return pidx;
}


static
id2
id6(const void *T, id2 *SA,
          id2 fs, id2 n, id2 k, int cs,
          sais_bool_type isbwt) {
  id2 *C, *B, *D, *RA, *b;
  id2 i, j, m, p, q, t, name, pidx = 0, newfs;
  id2 c0, c1;
  unsigned int flags;

  assert((T != NULL) && (SA != NULL));
  assert((0 <= fs) && (0 < n) && (1 <= k));

  if(k <= MINBUCKETSIZE) {
    if((C = SAIS_MYMALLOC(k, id2)) == NULL) { return -2; }
    if(k <= fs) {
      B = SA + (n + fs - k);
      flags = 1;
    } else {
      if((B = SAIS_MYMALLOC(k, id2)) == NULL) { SAIS_MYFREE(C, k, id2); return -2; }
      flags = 3;
    }
  } else if(k <= fs) {
    C = SA + (n + fs - k);
    if(k <= (fs - k)) {
      B = C - k;
      flags = 0;
    } else if(k <= (MINBUCKETSIZE * 4)) {
      if((B = SAIS_MYMALLOC(k, id2)) == NULL) { return -2; }
      flags = 2;
    } else {
      B = C;
      flags = 8;
    }
  } else {
    if((C = B = SAIS_MYMALLOC(k, id2)) == NULL) { return -2; }
    flags = 4 | 8;
  }
  if((n <= SAIS_LMSSORT2_LIMIT) && (2 <= (n / k))) {
    if(flags & 1) { flags |= ((k * 2) <= (fs - k)) ? 32 : 16; }
    else if((flags == 0) && ((k * 2) <= (fs - k * 2))) { flags |= 32; }
  }

  
  getCounts(T, C, n, k, cs); getBuckets(C, B, k, 1); 
  for(i = 0; i < n; ++i) { SA[i] = 0; }
  b = &t; i = n - 1; j = n; m = 0; c0 = chr(n - 1);
  do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) >= c1));
  for(; 0 <= i;) {
    do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) <= c1));
    if(0 <= i) {
      *b = j; b = SA + --B[c1]; j = i; ++m;
      do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) >= c1));
    }
  }

  if(1 < m) {
    if(flags & (16 | 32)) {
      if(flags & 16) {
        if((D = SAIS_MYMALLOC(k * 2, id2)) == NULL) {
          if(flags & (1 | 4)) { SAIS_MYFREE(C, k, id2); }
          if(flags & 2) { SAIS_MYFREE(B, k, id2); }
          return -2;
        }
      } else {
        D = B - k * 2;
      }
      assert((j + 1) < n);
      ++B[chr(j + 1)];
      for(i = 0, j = 0; i < k; ++i) {
        j += C[i];
        if(B[i] != j) { assert(SA[B[i]] != 0); SA[B[i]] += n; }
        D[i] = D[i + k] = 0;
      }
      id8(T, SA, C, B, D, n, k, cs);
      name = id3(SA, n, m);
      if(flags & 16) { SAIS_MYFREE(D, k * 2, id2); }
    } else {
      id5(T, SA, C, B, n, k, cs);
      name = id0(T, SA, n, m, cs);
    }
  } else if(m == 1) {
    *b = j + 1;
    name = 1;
  } else {
    name = 0;
  }

  
  if(name < m) {
    if(flags & 4) { SAIS_MYFREE(C, k, id2); }
    if(flags & 2) { SAIS_MYFREE(B, k, id2); }
    newfs = (n + fs) - (m * 2);
    if((flags & (1 | 4 | 8)) == 0) {
      if((k + name) <= newfs) { newfs -= k; }
      else { flags |= 8; }
    }
    assert((n >> 1) <= (newfs + m));
    RA = SA + m + newfs;
    for(i = m + (n >> 1) - 1, j = m - 1; m <= i; --i) {
      if(SA[i] != 0) {
        RA[j--] = SA[i] - 1;
      }
    }
    if(id6(RA, SA, newfs, m, name, sizeof(id2), 0) != 0) {
      if(flags & 1) { SAIS_MYFREE(C, k, id2); }
      return -2;
    }

    i = n - 1; j = m - 1; c0 = chr(n - 1);
    do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) >= c1));
    for(; 0 <= i;) {
      do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) <= c1));
      if(0 <= i) {
        RA[j--] = i + 1;
        do { c1 = c0; } while((0 <= --i) && ((c0 = chr(i)) >= c1));
      }
    }
    for(i = 0; i < m; ++i) { SA[i] = RA[SA[i]]; }
    if(flags & 4) {
      if((C = B = SAIS_MYMALLOC(k, int)) == NULL) { return -2; }
    }
    if(flags & 2) {
      if((B = SAIS_MYMALLOC(k, int)) == NULL) {
        if(flags & 1) { SAIS_MYFREE(C, k, id2); }
        return -2;
      }
    }
  }

  
  if(flags & 8) { getCounts(T, C, n, k, cs); }
  
  if(1 < m) {
    getBuckets(C, B, k, 1); 
    i = m - 1, j = n, p = SA[m - 1], c1 = chr(p);
    do {
      q = B[c0 = c1];
      while(q < j) { SA[--j] = 0; }
      do {
        SA[--j] = p;
        if(--i < 0) { break; }
        p = SA[i];
      } while((c1 = chr(p)) == c0);
    } while(0 <= i);
    while(0 < j) { SA[--j] = 0; }
  }
  if(isbwt == 0) { id4(T, SA, C, B, n, k, cs); }
  else { pidx = id1(T, SA, C, B, n, k, cs); }
  if(flags & (1 | 4)) { SAIS_MYFREE(C, k, id2); }
  if(flags & 2) { SAIS_MYFREE(B, k, id2); }

  return pidx;
}





int
sais(const char *T, int *SA, int n) {
  if((T == NULL) || (SA == NULL) || (n < 0)) { return -1; }
  if(n <= 1) { if(n == 1) { SA[0] = 0; } return 0; }
  return id6((unsigned char *)T, SA, 0, n, UCHAR_SIZE, sizeof(unsigned char), 0);
}

int
id7(const int *T, int *SA, int n, int k) {
  if((T == NULL) || (SA == NULL) || (n < 0) || (k <= 0)) { return -1; }
  if(n <= 1) { if(n == 1) { SA[0] = 0; } return 0; }
  return id6(T, SA, 0, n, k, sizeof(int), 0);
}

int
id10(const unsigned char *T, unsigned char *U, int *A, int n) {
  int i, pidx;
  if((T == NULL) || (U == NULL) || (A == NULL) || (n < 0)) { return -1; }
  if(n <= 1) { if(n == 1) { U[0] = T[0]; } return n; }
  pidx = id6(T, A, 0, n, UCHAR_SIZE, sizeof(unsigned char), 1);
  if(pidx < 0) { return pidx; }
  U[0] = T[n - 1];
  for(i = 0; i < pidx; ++i) { U[i + 1] = (unsigned char)A[i]; }
  for(i += 1; i < n; ++i) { U[i] = (unsigned char)A[i]; }
  pidx += 1;
  return pidx;
}

int
id9(const int *T, int *U, int *A, int n, int k) {
  int i, pidx;
  if((T == NULL) || (U == NULL) || (A == NULL) || (n < 0) || (k <= 0)) { return -1; }
  if(n <= 1) { if(n == 1) { U[0] = T[0]; } return n; }
  pidx = id6(T, A, 0, n, k, sizeof(int), 1);
  if(pidx < 0) { return pidx; }
  U[0] = T[n - 1];
  for(i = 0; i < pidx; ++i) { U[i + 1] = A[i]; }
  for(i += 1; i < n; ++i) { U[i] = A[i]; }
  pidx += 1;
  return pidx;
}
