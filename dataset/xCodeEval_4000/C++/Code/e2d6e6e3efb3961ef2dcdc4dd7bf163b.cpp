#define q4 struct
#define q8 )
#define q43 enum
#define q13 asm
#define q49 float
#define q38 export
#define q19 try
#define q31 [
#define q26 typename
#define q32 unsigned
#define q62 mutable
#define q54 protected
#define q57 new
#define q59 explicit
#define q44 using
#define q6 short
#define q29 else
#define q10 if
#define q15 default
#define q1 char
#define q72 break
#define q48 main
#define q22 ==
#define q14 printf
#define q34 typedef
#define q30 for
#define q11 const
#define q21 >=
#define q56 cin
#define q37 long
#define q67 throw
#define q74 true
#define q2 (
#define q16 void
#define q41 +=
#define q39 inline
#define q20 -=
#define q42 static
#define q23 ::
#define q60 switch
#define q24 case
#define q58 return
#define q35 class
#define q25 namespace
#define q70 typeid
#define q66 <<
#define q47 while
#define q40 friend
#define q50 cout
#define q7 double
#define q5 false
#define q28 do
#define q46 goto
#define q73 }
#define q63 <=
#define q53 sizeof
#define q71 signed
#define q64 continue
#define q36 bool
#define q61 catch
#define q65 ++
#define q68 private
#define q33 --
#define q17 >>
#define q45 {
#define q12 endl
#define q3 ]
#define q69 ;
#define q55 this
#define q18 union
#define q27 int 
#define q51 public
#define q52 auto
#define q0 !=
#define q9 int 
#include <bits/stdc++.h>
  q44     q25   std  q69  
 
  q11     q27  maxn = 3e5 + 10, P = 1e9 + 7  q69  
  q27  n, m, fa  q31  maxn  q3  , sz  q31  maxn  q3  , tid  q31  maxn  q3  , dep  q31  maxn  q3    q69  
 
  q39     q27  inc  q2    q27  x,   q27  y  q8  
  q45  
  q58   x + y < P ? x + y : x + y - P  q69  
  q73  
 
  q39     q27  dec  q2    q27  x,   q27  y  q8  
  q45  
  q58   x - y < 0 ? x - y + P : x - y  q69  
  q73  
 
  q4   BIT
  q45  
  q27  c  q31  maxn  q3    q69  
 
  q16   add  q2    q27  pos,   q27  x  q8  
  q45  
  q30     q2    q69   pos   q63   n  q69   pos   q41   pos & -pos  q8  
  q45  
c  q31  pos  q3   = inc  q2  c  q31  pos  q3  , x  q8    q69  
  q73  
  q73  
 
  q27  query  q2    q27  pos  q8  
  q45  
  q27  res = 0  q69  
  q30     q2    q69   pos  q69   pos &= pos - 1  q8  
  q45  
res = inc  q2  res, c  q31  pos  q3    q8    q69  
  q73  
  q58   res  q69  
  q73  
 
  q16   add  q2    q27  l,   q27  r,   q27  x  q8  
  q45  
add  q2  l, x  q8  , add  q2  r + 1, dec  q2  0, x  q8    q8    q69  
  q73  
  q73   t1, t2  q69  
 
vector<int> e  q31  maxn  q3    q69  
 
  q27  dfs  q2    q27  u  q8  
  q45  
  q42     q27  now  q69  
tid  q31  u  q3   =   q65  now  q69  
  q30     q2    q27  v : e  q31  u  q3    q8  
  q45  
sz  q31  u  q3     q41   dfs  q2  v  q8    q69  
  q73  
  q58     q65  sz  q31  u  q3    q69  
  q73  
 
  q27    q48    q2    q8  
  q45  
scanf  q2  "%d", &n  q8    q69  
  q30     q2    q27  i = 2  q69   i   q63   n  q69   i  q65    q8  
  q45  
scanf  q2  "%d", fa + i  q8    q69  
e  q31  fa  q31  i  q3    q3  .push_back  q2  i  q8    q69  
dep  q31  i  q3   = dep  q31  fa  q31  i  q3    q3   + 1  q69  
  q73  
dfs  q2  1  q8    q69  
scanf  q2  "%d", &m  q8    q69  
  q47     q2  m  q33    q8  
  q45  
  q27  op, u, x, k  q69  
scanf  q2  "%d %d", &op, &u  q8    q69  
  q27  l = tid  q31  u  q3  , r = tid  q31  u  q3   + sz  q31  u  q3   - 1  q69  
  q10     q2  op   q22   1  q8  
  q45  
scanf  q2  "%d %d", &x, &k  q8    q69  
t1.add  q2  l, r, inc  q2  x, 1ll * dep  q31  u  q3   * k % P  q8    q8    q69  
t2.add  q2  l, r, k  q8    q69  
  q73  
  q29  
  q45  
  q14    q2  "%d\n", dec  q2  t1.query  q2  l  q8  , 1ll * dep  q31  u  q3   * t2.query  q2  l  q8   % P  q8    q8    q69  
  q73  
  q73  
  q58   0  q69  
  q73  
 