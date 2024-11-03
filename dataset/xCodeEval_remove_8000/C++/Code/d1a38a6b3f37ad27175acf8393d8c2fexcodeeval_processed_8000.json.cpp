
















using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;





















typedef long double ld;





inline int iszero(ld x) {
  return (x < EPS) && (x > -EPS);
}

typedef struct {
  ld s[DIM];
} pt; 



typedef struct {
  pt O;
  pt dir;
} lin; 


typedef struct {
  pt A;
  pt B;
} seg; 


typedef struct {
  pt O;
  ld R;
} circ; 


inline pt operator+ (const pt &A, const pt &B) {
  pt res;
  res.X = A.X + B.X;
  res.Y = A.Y + B.Y;
  return res;
}

inline pt operator- (const pt &A, const pt &B) {
  pt res;
  res.X = A.X - B.X;
  res.Y = A.Y - B.Y;
  return res;
}

inline pt operator* (const ld &lam, const pt &A) {
  pt res;
  res.X = lam * A.X;
  res.Y = lam * A.Y;
  return res;
}

inline bool operator== (const pt &A, const pt &B) {
  REP (i, DIM) if (!iszero(A.s[i] - B.s[i])) return 0;
  return 1; 
}



inline pt mpt (ld x, ld y) {
  pt res;
  res.X = x;
  res.Y = y;
  return res;
}

inline lin mlin (const pt &A, const pt &B) {
  lin res;
  res.O = A;
  res.dir = B - A;
  return res;
}

inline seg mseg (const pt &A, const pt &B) {
  seg res;
  res.A = A;
  res.B = B;
  return res;
}

inline circ mcirc (const pt &A, ld R) {
  circ res;
  res.O = A;
  res.R = R;
  return res;
}

inline ld cp (const pt &A, const pt &B) { 

  return A.X * B.Y - A.Y * B.X;
}



inline int id13 (const pt &A, const lin &L) {
  if (cp(A-L.O, L.dir) > 0.) return 1; return 0;
}

inline ld is (const pt &A, const pt &B) {
  return A.X * B.X + A.Y * B.Y;
}



int id8 (const lin &K, const lin &L, pt &res) { 

  if (abs(cp(K.dir, L.dir)) < EPS) return 0; 
  ld s = cp(K.dir, K.O - L.O) / cp (K.dir, L.dir);
  res = L.O + s * L.dir;
  return 1;
}







int triangle (ld x, ld y, ld z) {
  if (x < y) {ld t; t=x; x=y; y=t;}
  if (z < x) {ld t; t=x; x=z; z=t;}
  if (iszero(z-x-y)) return 0;
  if (z-x-y < 0) return 1;
  return -1;
}


pt rotate_origin (ld theta, const pt &A) { 
  pt res;
  ld si = sinl(theta);
  ld co = cosl(theta);
  res.X = A.X * co - A.Y * si;
  res.Y = A.X * si + A.Y * co;
  return res;
}


pt rotate (ld theta, const pt &A, const pt &O) { 
  return O + rotate_origin(theta, A-O);
}


inline pt id15 (const pt &A) {
  return mpt(-A.Y, A.X);
}


pt id3 (const pt &A, const pt &O) {
  return id15(A-O) + O;
}





ld angle (const pt &A, const pt &O, const pt &B) {
  ld res = atan2l((B-O).Y, (B-O).X) - atan2l((A-O).Y, (A-O).X);
  if (res < 0) res += 2.*PI;
  return res;
}



ld angle (const lin &K, const lin &L) {
  return angle(K.dir, mpt(0,0), L.dir);
}




pt rzut (const pt &A, const lin &L) {
  return (is(A - L.O,L.dir) / is(L.dir,L.dir)) * L.dir + L.O;
}





int parallel (const pt &A, const pt &B) {
  return iszero(cp(A,B));
}



int parallel (const lin &K, const lin &L) {
  return parallel(K.dir, L.dir);
}



lin perp (const pt &A, const pt &D) {
  return mlin(A, A + mpt(D.Y, -D.X));
}



int between (const pt &A, const pt &M, const pt &B) {
  if (!parallel(M-A,B-A)) return 0;
  return (is(M-A,M-B) < EPS);
}





int id19 (const lin &L, const seg &I, pt &W) {
  if (!id8(L, mlin(I.A,I.B),W)) return 0;
  if (between(I.A,W,I.B)) return 1; return 0;
}







int id0 (const seg &I, const seg &J, pt &W) {
  if (!id8(mlin(I.A,I.B), mlin(J.A,J.B), W)) return 0;
  if (between(I.A,W,I.B) && between(J.A,W,J.B)) return 1; return 0;
}



int online (const lin &L, const pt &A) {
  return (is(A-L.O,A-L.O) < EPS) || parallel(L.dir, A-L.O);
}

ld lgt (pt A) {
  return sqrt(is(A,A));
}

ld dist (pt A, pt B) {
  return lgt(A-B);
}



inline int id21(const pt &A, const circ &C) {
  return (iszero(dist(A,C.O) - C.R));
}



int id4 (const lin &K, const circ &C, pt &W1, pt &W2) {
  pt M = rzut(C.O, K);
	if (id21(M, C)) {W1 = M; return 1;}
  ld dao = dist(M,C.O);
  if (dao > C.R) return 0;
  if (dao < EPS) {
    W1 = C.O + (C.R / lgt(K.dir)) * K.dir;
    W2 = C.O - (C.R / lgt(K.dir)) * K.dir;
    return 2;
  }
  ld theta = acosl(dao / C.R);
  M = (C.R / dao) * (M - C.O) + C.O;
  W1 = rotate(theta,M,C.O);
  W2 = rotate(-theta,M,C.O);
	if (is(K.dir, W2-W1) < -EPS) {M = W1; W1 = W2; W2 = M;}
  return 2;
}







int id20 (const pt &A, const circ &C, lin &W1, lin &W2) { 
  if (id21(A,C)) { 

    W1 = perp(A, C.O - A);
    return 1;
  }
  ld dao = dist(A,C.O);
  if (dao <= C.R) return 0;
  ld theta = asinl(C.R / dao);
  pt temp = (sqrt(SQR(dao) - SQR(C.R)) / dao) * (C.O - A) + A;
  W2 = mlin(A, rotate(theta, temp, A));
  W1 = mlin(A, rotate(-theta, temp, A));
  return 2;
}











int id16 (const circ &C1, const circ &C2, pt &W1, pt &W2) {
  ld doo = dist(C1.O, C2.O);
  if (triangle(doo, C1.R, C2.R) == -1) return 0;
	if (doo < EPS) return -1;
  if (triangle(doo, C1.R, C2.R) == 0 ) { 

    id4(mlin(C1.O, C2.O), C1, W1, W2);
    if (id21(W2,C2)) W1 = W2;
    return 1;
  }
	

  ld alpha = acos((SQR(C1.R) - SQR(C2.R) + SQR(doo)) / (2.0 * C1.R * doo)); 
  pt start = C1.O + (C1.R / doo) * (C2.O - C1.O);
  W1 = rotate(alpha, start, C1.O);
  W2 = rotate(-alpha, start, C1.O);
  return 2;
}







ld id17(const circ &C, const lin &L) {
	pt A, B;
	if (id4(L,C,A,B) < 2) {
		if (id13(C.O, L)) return 0.; 
		return PI * C.R * C.R;
	}
	return (angle(A, C.O, B) * SQR(C.R) - cp(A-C.O,B-C.O)) / 2.;
}





ld id14(const circ &C1, const circ &C2) {
	ld dao = dist(C1.O, C2.O);
	if (C1.R + C2.R < dao + EPS) return 0.;
	if (C1.R + dao < C2.R + EPS) return PI * SQR(C1.R);
	if (C2.R + dao < C1.R + EPS) return PI * SQR(C2.R);
	pt A, B;
	assert(id16(C1,C2,A,B) == 2);
	return id17(C1, mlin(B,A)) + id17(C2, mlin(A,B));
}



int three_points (const pt &A, const pt &B, const pt &C, circ &R) {
  if (!id8(perp(0.5 * (A+B), B-A), perp(0.5 * (A+C), C-A), R.O)) 
    return 0;
  R.R = dist(R.O, A);
  return 1;
}







int id5(const circ &C1, const circ &C2, lin &W1, lin &W2) {
  pt mid = (C1.R / (C1.R + C2.R)) * C2.O + (C2.R / (C1.R + C2.R)) * C1.O;
  return id20(mid, C1, W1, W2);
}







int id18(const circ &C1, const circ &C2, lin &W1, lin &W2) {
  if (iszero(C1.R - C2.R)) {
    if (iszero(dist(C1.O,C2.O))) return 0;
    pt start = C1.O + ((C1.R / dist(C1.O,C2.O)) * id15(C2.O - C1.O));
    W1 = mlin(start, start + C2.O - C1.O);
    W2 = mlin(C1.O + C1.O - start, C1.O + C2.O - start);
    return 2;
  }
  pt start = (C2.R / (C2.R - C1.R)) * C1.O - (C1.R / (C2.R - C1.R)) * C2.O;
  return id20(start, C1, W1, W2);
}









pt invert_origin (const pt &A) {
  return (1. / (SQR(A.X) + SQR(A.Y))) * A;
}

pt invert (const pt &A, const pt &O) {
  return invert_origin(A-O) + O;
}





typedef struct {
  int typ; 

  union {
    lin L;
    circ C;
  } V;
} lincirc;

lincirc id7 (const lin &L) {
  lincirc res;
  res.typ = 0;
  res.V.L = L;
  return res;
}

lincirc id7 (const circ &C) {
  lincirc res;
  res.typ = 1;
  res.V.C = C;
  return res;
}



lincirc invert (const lin &L, const pt &O) {
  lincirc res;
  if (online(L,O)) {
    res.typ = 0;
    res.V.L = L;
    return res;
  }
  res.typ = 1;
  three_points(invert(L.O,O), invert(L.O + L.dir,O), O, res.V.C);
  return res;
}

lincirc invert (const circ &C, const pt &O) {
  lincirc res;
  if (iszero(dist(O, C.O) - C.R)) {
    res.typ = 0;
    pt A = id3(O, C.O);
    pt B = id3(A, C.O);
    res.V.L = mlin(invert(A,O),invert(B,O));
    return res;
  }
  res.typ = 1;
  pt A = C.O; A.X += C.R; 

  pt B = id3(A,C.O);
  pt D = id3(B,C.O);
  three_points(invert(A,O), invert(B,O), invert(D,O), res.V.C);
  return res;
}

lincirc invert (const lincirc &LC, const pt &O) {
  if (LC.typ == 0) return invert(LC.V.L, O);
  return invert(LC.V.C, O);
}













vector<lin> id1 (const lincirc &LC, const pt &P) {
  vector<lin> res;
  if (LC.typ == 0) { 

    res.PB(mlin(P,P + LC.V.L.dir));
    return res;
  }
  res.resize(2);
  int nres = id20(P, LC.V.C, res[0], res[1]);
  res.resize(nres);
  return res;
}





vector<lincirc> id9 (const lincirc &LC, const pt &P1, const pt &P2) {
  pt IP = invert(P2, P1);
  lincirc IC = invert(LC, P1);
  vector<lin> tangs = id1(IC, IP);
  vector<lincirc> res;
  REP (i, SIZE(tangs)) res.PB(invert(tangs[i], P1));
  return res;
}











vector<lincirc> id11 (const lincirc &LC1, const lincirc &LC2, const pt &P) {
  vector<lincirc> res;
  lincirc id2, id12;
  lin W1, W2;
  int nw;

  id2 = invert(LC1, P);
  if (id2.typ == 0) {
    id12 = id2;
    id2 = invert(LC2, P);
  } else id12 = invert(LC2, P); 

  if (id2.typ == 0) {res.PB(id7(mcirc(P,0))); return res;}
  if (id12.typ == 0) {
    pt MV = (id2.V.C.R / lgt(id12.V.L.dir)) * id15(id12.V.L.dir);
    res.PB(invert(mlin(id2.V.C.O + MV, id2.V.C.O + MV + id12.V.L.dir),P));
    res.PB(invert(mlin(id2.V.C.O - MV, id2.V.C.O - MV + id12.V.L.dir),P));
    return res;
  }
  nw = id5(id2.V.C, id12.V.C, W1, W2);
  if (nw) res.PB(invert(W1, P));
  if (nw > 1) res.PB(invert(W2, P));
  nw = id18(id2.V.C, id12.V.C, W1, W2);
  if (nw) res.PB(invert(W1, P));
  if (nw > 1) res.PB(invert(W2, P));
  return res;
}



vector<pt> make_candidates(circ C[3], int P[3]) {
  vector<pt> res;
  if (iszero(C[2].R)) {
    circ T;
    if (three_points(C[0].O, C[1].O, C[2].O, T)) res.PB(T.O);
    return res;
  }
  vector<lincirc> LCs;
  if (iszero(C[1].R)) LCs = id9(id7(C[2]), C[1].O, C[0].O);
  else LCs = id11(id7(C[2]), id7(C[1]), C[0].O);
  REP (i, SIZE(LCs)) if (LCs[i].typ == 1) res.PB(LCs[i].V.C.O);
  return res;
}

int id10 (circ C[3], int P[3], const pt &CP, circ &CR) {
  ld Rs[3];
  REP (i, 3) if(P[i]) Rs[i] = C[i].R - dist(C[i].O, CP);
             else     Rs[i] = dist(C[i].O, CP) - C[i].R;
  REP (i, 2) if (!iszero(Rs[i] - Rs[2])) return 0;
  if (Rs[2] < -EPS) return 0;
  CR.O = CP;
  CR.R = Rs[0];
  return 1;
}



vector<circ> id6 (const circ &C1, const int &P1, const circ &C2, const int &P2, const circ &C3, const int &P3) {
  if (C1.R > C2.R) return id6(C2,P2,C1,P1,C3,P3);
  if (C1.R > C3.R) return id6(C3,P3,C1,P1,C2,P2); 

  if (C2.R > C3.R) return id6(C1,P1,C3,P3,C2,P2); 

  circ C[3];
  int P[3];
  C[0] = C1; C[1] = C2; C[2] = C3; P[0] = P1; P[1] = P2; P[2] = P3;
  ld mr = P[0] ? -C[0].R : C[0].R;
  REP (i, 3) C[i].R += (P[i] ? mr : -mr);
  vector<pt> candidates = make_candidates(C,P);
  REP (i, 3) C[i].R -= (P[i] ? mr : -mr);
  vector<circ> res;
  circ CR;
  REP (i, SIZE(candidates)) if (id10(C,P,candidates[i],CR)) res.PB(CR);
  return res; 
}
































































































































int check(pt w1, pt w2, pt w3, pt w4){
  ld d1 = dist(w1,w2);
  if (fabsl(d1 - dist(w1,w4)) > EPS) return 0;
  if (fabsl(d1 - dist(w2,w3)) > EPS) return 0;

  pt tab[] = {w4, w1, w2, w3, w4, w1, w2};
  REP(i,4){
    

    ld kat = angle(tab[i], tab[i+1], tab[i+2]);
    if (kat >= PI - EPS) return 0;
    if (kat <= EPS) return 0;
  }
  puts("YES");
  REP(i,4){
    if (i) printf(" ");
    printf("%.9lf %.9lf",(double)tab[i].s[0], (double)tab[i].s[1]);
  }
  puts("");
  return 1;
}

int licz(VPII v){
  pt p1 = mpt(v[0].ST, v[0].ND);
  pt p2 = mpt(v[1].ST, v[1].ND);
  pt p3 = mpt(v[2].ST, v[2].ND);
  pt wektor = rotate_origin(PI/2.0, p2 - p1);
  pt sr = p1 + 0.5 * (p2-p1);

  ld l = 0.0;
  ld r = 100;
  FORD(foo,49,0){
    ld m = (l+r)/2.0;
    pt R1 = sr + m * wektor;
    assert(!id13(R1, mlin(p1,p2)));

    pt W1 = R1;
    pt W2 = W1 + 2 * (p2 - W1);

    if (foo == 0){
      

      pt W3 = W2 + 2 * (p3 - W2);
      pt W4 = W1 + 2 * (p1 - W1);
      return check(W1, W2, W3, W4);
    } else {
      if (dist(p2, W2) > dist(W2, p3)) r = m;
      else l = m;
    }
  }
  return 0;
}

int main(){
  int testy;
  scanf("%d",&testy);
  while (testy--){
    VPII v;
    REP(i,3){
      int a,b;
      scanf("%d %d",&a,&b);
      v.PB(MP(a,b));
    }
    sort(ALL(v));
    int found = 0;
    do {
      if (licz(v)){
        found = 1;
        break;
      }
    } while (next_permutation(ALL(v)));
    if (!found) puts("NO\n");
  }
  return 0;
}
