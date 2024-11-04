
#define typeof(x) __typeof__(x)
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#define fz(i, n) for (int i = 0; i < n; i++)
#define fi(n) fz (i, n)
#define fj(n) fz (j, n)
#define fn fi (n)
#define fm fj (m)
#define fnm fn fm
#define makeident _ident_##__COUNTER__
#define _rep(ident, n) __auto_type ident = (n); while (ident--)
#define rep(n) _rep(makeident, n)
#define var __auto_type
#define DEFINE_LIST(typename, T)				\
struct typename							\
{								\
  T payload;							\
  struct typename *next;					\
};								\
								\
static struct typename *					\
typename##_new (T payload, struct typename *next)		\
{								\
  struct typename *list = malloc (sizeof(struct typename));	\
  list->payload = payload;					\
  list->next = next;						\
  return list;							\
}								\
								\
static struct typename *					\
typename##_add (struct typename *list, T payload)		\
{								\
  return typename##_new (payload, list);			\
}								\
								\
static struct typename *					\
 typename##_remove (struct typename *list, T* payload)		\
{								\
  assert (list);						\
  assert (payload);						\
  *payload = list->payload;					\
  struct typename *next = list->next;				\
  free (list);							\
  return next;							\
}
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
typedef unsigned int uint;
typedef long long lon;
typedef unsigned long long ulon;




#ifdef _WIN32
#include <windows.h>
#define read _read
#define write _write
#else
#include <unistd.h>
#endif 
#define BUFFER_SIZE 4096
char input_buffer[BUFFER_SIZE+1];
char output_buffer[BUFFER_SIZE+1];
char *input_ptr;
char *output_ptr;
__attribute__ ((destructor)) void
fst_flush ()
{
  write (1, output_buffer, output_ptr-output_buffer);
  output_ptr = output_buffer;
}
#define flush (fst_flush ())
void
fst_write_char (char ch)
{
  *output_ptr++ = ch;
  if (!*output_ptr)
    {
      write (1, output_buffer, BUFFER_SIZE);
      output_ptr = output_buffer;
    }
}
#define wchar fst_write_char
char
fst_read_char ()
{
  if (*input_ptr) return *input_ptr++;
  int read_bytes = read (0, input_buffer, BUFFER_SIZE);
  input_buffer[read_bytes] = 0;
  input_ptr = input_buffer;
  return *input_ptr++;
}
char
fst_peek_char ()
{
  if (*input_ptr) return *input_ptr;
  int read_bytes = read (0, input_buffer, BUFFER_SIZE);
  input_buffer[read_bytes] = 0;
  input_ptr = input_buffer;
  return *input_ptr;
}
#define rchar (fst_read_char ())
void
fst_write_uint (uint n)
{
  static char digs[24];
  uint nodigs = 0;
  do
    {
      int div = n/10;
      int d = '0' + n - div * 10;
      digs[nodigs++] = d;
      n = div;
    }
  while (n);
  while (nodigs)
    {
      fst_write_char (digs[--nodigs]);
    }
}
void
fst_write_int (int n)
{
  if (n < 0) fst_write_char ('-'), n = -n;
  fst_write_uint (n);
}
#define wuint fst_write_uint

uint
fst_read_uint ()
{
  while (isspace (fst_peek_char ()))
    fst_read_char ();
  uint res = 0;
  char ch;
  for (;;)
    {
      switch (ch = fst_peek_char ())
	{
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	  res *= 10;
	  res += ch - '0';
	  fst_read_char ();
	  break;
	default: return res;
	}
    }
}
#define ruint (fst_read_uint ())
__attribute__ ((constructor)) void
fst_init ()
{
  output_ptr = output_buffer;
  memset (output_buffer, -1, BUFFER_SIZE);
  output_buffer[BUFFER_SIZE] = 0;
  input_ptr = input_buffer;
  input_ptr[0] = 0;
}



DEFINE_LIST(freelist, void*);
struct mem
{
  void *allocated;
  struct freelist *freelist;
  size_t type_size;
  size_t max_elements;
  size_t effective_type_size;
  void *block_mask;
};
static struct mem
mem_init (size_t type_size, size_t max_elements)
{
  struct mem mem;
  mem.freelist = NULL;
  mem.type_size = type_size;
  mem.max_elements = max_elements;
  mem.effective_type_size = type_size;
  mem.block_mask = (void*) ~(mem.effective_type_size - 1);
  mem.allocated = malloc (mem.effective_type_size * max_elements);
  void *ptr = mem.allocated;
  for (int i = 0; i < max_elements; i++, ptr += mem.effective_type_size)
    {
      mem.freelist = freelist_add (mem.freelist, ptr);
    }
  return mem;
}
static void *
mem_allocate (struct mem *mem)
{
  if (mem->freelist)
    {
      void *given_memory = NULL;
      mem->freelist = freelist_remove (mem->freelist, &given_memory);
      return given_memory;
    }
  return NULL;
}
static void *
mem_get_block (struct mem *mem, void *ptr)
{
  assert (ptr >= mem->allocated && ptr < mem->allocated + mem->type_size * mem->max_elements);
  return (void*)((size_t)ptr & (size_t)mem->block_mask);
}
static void
mem_free (struct mem *mem, void *ptr)
{
  assert (ptr >= mem->allocated && ptr < mem->allocated + mem->type_size * mem->max_elements);
  assert (mem_get_block (mem, ptr) == ptr);
  mem->freelist = freelist_add (mem->freelist, ptr);
}
struct flatmem
{
  void *allocated;
  size_t value_size;
  size_t max_values;
  void *past_end_ptr;
};
struct flatmem
flatmem_make (size_t value_size, size_t max_values)
{
  struct flatmem flatmem;
  size_t rounded_size = 1;
  while (rounded_size < value_size)
    rounded_size <<= 1;
  flatmem.value_size = rounded_size;
  flatmem.allocated = malloc (flatmem.value_size * max_values);
  flatmem.max_values = max_values;
  flatmem.past_end_ptr = flatmem.allocated;
  return flatmem;
}
void *
flatmem_allocate (struct flatmem *mem)
{
  void *ptr = mem->past_end_ptr;
  mem->past_end_ptr += mem->value_size;
  return ptr;
}
void
flatmem_reset (struct flatmem *mem)
{
  mem->past_end_ptr = mem->allocated;
}


FILE *dotfile = NULL;
#define PARENT_NO 2
#define LEFT_NO 0
#define RIGHT_NO 1
#define ROOT 2
#define RED 0
#define BLACK 1
#define PARENT(x) ((x)->connection[PARENT_NO])
#define LEFT(x) ((x)->connection[LEFT_NO])
#define RIGHT(x) ((x)->connection[RIGHT_NO])
#define CON(x, who) ((x)->connection[(who)])
#define COLOR(x) ({__auto_type _x = (x); _x? _x->color : 1;})
#define DEFINE_RED_BLACK_TREE(typename, T, CMP, EQL)			\
  struct typename							\
  {									\
    int color;								\
    struct typename *connection[3];					\
    T value;								\
  };									\
									\
  struct flatmem typename##_flatmem;					\
									\
  void									\
  typename##_init_memory (size_t max_elements)				\
  {									\
    typename##_flatmem = flatmem_make (sizeof (struct typename), max_elements); \
  }									\
  struct typename *							\
  typename##_new_red_node (T value)					\
  {									\
    struct typename *node = flatmem_allocate (&typename##_flatmem);	\
    node->connection[0] = 0;						\
    node->connection[1] = 0;						\
    node->connection[2] = 0;						\
    node->color = RED;							\
    node->value = value;						\
    return node;							\
  }									\
									\
  struct typename *							\
  typename##_new_black_node (T value)					\
  {									\
    struct typename *node = flatmem_allocate (&typename##_flatmem);	\
    node->connection[0] = 0;						\
    node->connection[1] = 0;						\
    node->connection[2] = 0;						\
    node->color = BLACK;						\
    node->value = value;						\
    return node;							\
  }									\
									\
  static inline struct typename *					\
  typename##_connect(struct typename *a, struct typename *b, struct typename *c)	\
  {									\
    RIGHT(b) = c;							\
    LEFT(b) = a;							\
    if (a) PARENT(a) = b;						\
    if (c) PARENT(c) = b;						\
    return b;								\
  }									\
									\
  __attribute__ ((hot)) static inline struct typename *			\
  typename##_set_right(struct typename *a, struct typename *b)			\
  {									\
    RIGHT(a) = b;							\
    if (b) PARENT(b) = a;						\
    return a;								\
  }									\
									\
  __attribute__ ((hot)) static inline struct typename *			\
  typename##_set_left (struct typename *a, struct typename *b)			\
  {									\
    LEFT(b) = a;							\
    if (a) PARENT(a) = b;						\
    return b;								\
  }									\
									\
  int check_depth;							\
  void									\
  typename##_check (struct typename *root, T min, T max, int has_min, int has_max, int prev_color, int depth) \
  {									\
    if (root == NULL)							\
      {									\
	if (check_depth == -1) check_depth = depth;			\
	else assert (check_depth == depth);				\
	return;								\
      }									\
    if (prev_color == RED)						\
      {									\
	assert (root->color == BLACK);					\
      }									\
    if (has_min)							\
      {									\
	assert (CMP(min, root->value));					\
      }									\
    if (has_max)							\
      {									\
	assert (CMP(root->value, max));					\
      }									\
    typename##_check (LEFT(root), min, root->value, has_min, 1, root->color, depth + root->color); \
    typename##_check (RIGHT(root), root->value, max, 1, has_max, root->color, depth + root->color); \
  }									\
									\
									\
  __attribute__ ((hot)) struct typename *				\
  typename##_insert (struct typename *root,				\
		     T value)						\
  {									\
    if (!root)								\
      {									\
	struct typename *root = typename##_new_black_node (value);	\
	return root;							\
      }									\
									\
    struct typename *v = NULL;						\
    struct typename *node;						\
    for (node = root;;)							\
      {									\
	int direction = CMP(node->value, value);			\
	if (EQL(node->value, value))					\
	  {								\
	    node->value = value;					\
	    return root;						\
	  }								\
	struct typename *new_node = node->connection[direction];	\
	if (new_node == NULL)						\
	  {								\
	    v = typename##_new_red_node (value);			\
	    PARENT(v) = node;						\
	    node->connection[direction] = v;				\
	    break;							\
	  }								\
	node = new_node;						\
      }									\
    assert (v);								\
    for (;;)								\
      {									\
	assert (v);							\
	assert (COLOR(v) == RED);					\
	struct typename *w = PARENT(v);					\
	if (w == NULL)							\
	  {								\
	    v->color = BLACK;						\
	    assert (root == v);						\
	    return v;							\
	  }								\
	assert (w);							\
	struct typename *x = LEFT(w);					\
	struct typename *q = NULL, *s = NULL, *t = NULL;		\
	struct typename *g = PARENT(w);					\
	if (COLOR(x) == BLACK)						\
	  {								\
	    register struct typename *a = LEFT(v);			\
	    register struct typename *b = RIGHT(v);			\
	    typename##_set_left(typename##_set_right(w, a), v);				\
	    v->color = w->color;					\
	    w->color = RED;						\
	    q = w;							\
	    s = v;							\
	    t = b;							\
	    if (g)							\
	      {								\
		int gdir = RIGHT(g) == w;				\
		g->connection[gdir] = s;				\
		PARENT(s) = g;						\
	      }								\
	    else							\
	      {								\
		root = s;						\
		PARENT(s) = NULL;					\
	      }								\
	  }								\
	else								\
	  {								\
	    q = LEFT(w);						\
	    s = w;							\
	    t = RIGHT(w);						\
	  }								\
	assert (q->color == RED);					\
	if (s->color == BLACK)						\
	  {								\
	    return root;						\
	  }								\
	assert (s->color == RED);					\
	assert (g);							\
	assert (g->color == BLACK);					\
	struct typename *gg = RIGHT(g);					\
	if (gg && gg->color == RED)					\
	  {								\
	    assert (COLOR(LEFT(g)) == RED);				\
	    LEFT(g)->color = BLACK;					\
	    RIGHT(g)->color = BLACK;					\
	    g->color = RED;						\
	    v = g;							\
	  }								\
	else								\
	  {								\
	    struct typename *pg = PARENT(g);				\
	    typename##_set_right(s, typename##_set_left(t, g));				\
	    s->color = BLACK;						\
	    g->color = RED;						\
	    if (pg)							\
	      {								\
		int dir = LEFT(pg) == g? LEFT_NO : RIGHT_NO;		\
		pg->connection[dir] = s;				\
		PARENT(s) = pg;						\
	      }								\
	    else							\
	      {								\
		root = s;						\
		PARENT(root) = NULL;					\
	      }								\
	    return root;						\
	  }								\
      }									\
    return root;							\
  }									\
									\
  T*									\
  typename##_search (struct typename *root, T value)			\
  {									\
    struct typename *node;						\
    for (node = root;;)							\
      {									\
	int direction = CMP(node->value, value);			\
	if (EQL(node->value, value)) return &node->value;		\
	struct typename *new_node = node->connection[direction];	\
	if (new_node == NULL) return NULL;				\
	node = new_node;						\
      }									\
    assert (0);								\
  }
		   
#include <stdlib.h>

#define DEFINE_XARR(typename, T)					\
struct typename								\
{									\
  T *front;								\
  T *back;								\
  int len;								\
  int capacity;								\
};									\
									\
struct typename								\
typename##_make ()							\
{									\
  struct typename xarr;							\
  xarr.front = malloc (sizeof (T));					\
  xarr.back = xarr.front;						\
  xarr.len = 0;								\
  xarr.capacity = 1;							\
  return xarr;								\
}									\
									\
void									\
typename##_insert (struct typename *xarr, T value)			\
{									\
  if (xarr->capacity < xarr->len + 1)					\
    {									\
      xarr->capacity <<= 1;						\
      xarr->front = realloc (xarr->front, xarr->capacity * sizeof (T));	\
      xarr->back = xarr->front + xarr->len;				\
    }									\
  xarr->len++;								\
  *(xarr->back++) = value;						\
}
#define fx(ai, xarr) for (__auto_type ai = (xarr).front; ai != (xarr).back; ai++)

#define xat(arr, i) (arr.front[i])
#define xab(arr, i) (arr.back[i])
#define xfront(arr) (xat(arr, 0))
#define xback(arr) (xab(arr, -1))

#define rng(arr) (arr).front, (arr).back
#define irng(arr) 0, arr.len - 1

#define xinit(_type, _i, _len, _init)				\
  ({								\
    _type xarr;							\
    int len = _len;						\
    xarr.capacity = len > 0? len : 1;				\
    xarr.front = malloc (sizeof (*xarr.front) * xarr.capacity);	\
    xarr.len = len;						\
    xarr.back = xarr.front + len;				\
    int _i = 0;							\
    fx (e, xarr) { *e = _init; _i++; }				\
    xarr;							\
  })


#define defxwr(_type, _start, _elem, _between, _end) void wr_##_type(_type t) { fst_write_stringz(_start); fx (_e, t) _elem (*_e), fst_write_stringz (_between); fst_write_stringz(_end); }

typedef int I;
typedef long long L;

DEFINE_XARR(Str, char);
typedef struct Str Str;
DEFINE_XARR(Is, I);
DEFINE_XARR(Ls, L);
typedef struct Is Is;
typedef struct Ls Ls;
DEFINE_XARR(Im, Is);
typedef struct Im Im;


struct Str
fst_read_word ()
{
  while (isspace (fst_peek_char ())) fst_read_char ();
  struct Str res = Str_make ();
  for (char ch; !isspace (ch = fst_peek_char ()) && ch; fst_read_char ())
    Str_insert (&res, ch);
  return res;
}
#define rword (fst_read_word ())

void
fst_write_string (struct Str string)
{
  fx (ch, string) wchar (*ch);
}
void
fst_write_stringz (const char *string)
{
  for (; *string; string++) wchar (*string);
}



#define fc int t = ruint; for (int tc = 0; tc < t; tc++)


typedef long long ll;
#define ad(x, y) ({__auto_type r = x + y; if (r >= mod) r -= mod; r;})
#define mu(x, y) ({__auto_type r = x * y; r %= mod;})
#define ng(x) ((x)?(mod - (x)):(x))
#define mod 1000000007LL
ll
adv(ll sum, ...)
{
  va_list args;
  va_start (args, sum);
  ll nxt;
  while ((nxt = va_arg (args, ll)) != -1)
      sum = ad(sum, nxt);
  va_end (args);
  return sum;
}

#define ris (xinit(Is, i, ruint, ruint))
#define wxarr(_x, _ew) ({wr ("[ "); fx (_a, _x) _ew (*_a), wr (" "); wr ("]");})
#define mkim(n, m, exp) xinit(Im, $i, n, xinit (Is, $j, m, (exp)))
#define mkis(n, exp) xinit (Is, $i, n, (exp))

ll
muv(ll prod, ...)
{
  va_list args; va_start (args, prod);
  for (ll nxt; (nxt = va_arg (args, ll)) != -1;) prod = mu (prod, nxt);
  return prod;
}

bool
streq(char *s1, char *s2, int len)
{
  fz (i, len)
    if (*(s1++) != *(s2++))
      return false;
  return true;
}
defxwr(Is, "[ ", fst_write_uint, " ", "]");
defxwr(Im, "<<\n", wr_Is, "\n", ">>");
#define wr(x) _Generic((x), int: fst_write_int, \
		       uint: fst_write_uint, \
		       char *: fst_write_stringz, \
		       Str: fst_write_string, \
		       Is: wr_Is,	      \
		       Im: wr_Im,\
		       pI: wr_pI, \
		       pIs: wr_pIs)(x)

#define prs fst_write_stringz (
#define pri fst_write_uint (
#define ands ), fst_write_stringz (
#define andi ), fst_write_uint (
#define end )
#define endf ), fst_flush ()
#define and ),

#define log(x) wr (#x " = "), wr (x)
#define def(name, args, precond, _ret) _ret name args { assert (precond);
#define ret(_x) {assert (_post(_x)); return _x;}
#define fed }
#define firstllthat(_lo, _hi, _cond)		\
  ({						\
    ll lo = _lo, hi = _hi;			\
    ll ans = hi + 1;				\
    while (lo <= hi)				\
      {						\
	ll $x = (lo + hi) / 2;			\
	if (_cond)				\
	  {					\
	    ans = $x;				\
	    hi = $x - 1;			\
	  }					\
	else					\
	  {					\
	    lo = $x + 1;			\
	  }					\
      }						\
    ans;					\
  })

#define fixt(_arr, _cond) (firstllthat(0, _arr.len - 1, _cond))
#define fiet(_arr, _cond) (xat(_arr, fixt(_arr, _cond)))

#define lastllthat(_lo, _hi, _cond)		\
  ({						\
    ll lo = _lo, hi = _hi;			\
    ll ans = lo - 1;				\
    while (lo <= hi)				\
      {						\
	ll $x = (lo + hi) / 2;			\
	if (_cond)				\
	  {					\
	    ans = $x;				\
	    lo = $x + 1;			\
	  }					\
	else					\
	  {					\
	    hi = $x - 1;			\
	  }					\
      }						\
    ans;					\
  })

#define lambda_aux(_funname, _args, _rettype, _exp)	\
  _rettype _funname _args { return _exp; }		\
  _funname;

#define lambda(_args, _rettype, _exp) ({			\
      lambda_aux(lambda_##__COUNTER__, _args, _rettype, _exp)	\
    })

#define lambdai(_ret, _exp) lambda((ll $x), _ret, _exp)
#define cmp(_t, _x, _y, _exp) lambda((const void *_px, const void *_py), int, ({_t _x = *(_t*)_px, _y = *(_t*)_py; _exp;}))

typedef struct pI
{
  int v[2];
} pI;
DEFINE_XARR(pIs, pI);
typedef struct pIs pIs;
pI mkpi (int f, int s) { return (pI) {{f, s}}; }

void
wr_pI(pI x)
{
  (fst_write_stringz("("),	
   fst_write_int(x.v[0]),			
   fst_write_stringz(", "),			
   fst_write_int(x.v[1]),
   fst_write_stringz(")"));
}
defxwr(pIs, "[ ", wr_pI, " ", "]");

#define bal(_x, _y) (((_x) > (_y)) - ((_x) < (_y)))
#define balor_aux(_ans, _x, _y, _or) ({__auto_type _ans = bal(_x, _y); if (_ans == 0) _ans = (_or); _ans;})
#define balor(_x, _y, _or) balor_aux(makeident, _x, _y, _or)

#define sort_aux(_name, _ord, _type)				\
  ({								\
    void _name (_type * front, _type * back)			\
    {								\
      int len = back - front;					\
      if (len <= 1)						\
	return;							\
      _type *mid = front + len/2;				\
      _name (front, mid);					\
      _name (mid, back);					\
      _type merged[len];					\
      int mlen = 0;						\
      _type *x = front, *y = mid;				\
      while (x != mid && y != back)				\
	if (_ord <= 0) merged[mlen++] = *(x++);			\
	else merged[mlen++] = *(y++);				\
      while (x != mid) merged[mlen++] = *(x++);			\
      while (y != back) merged[mlen++] = *(y++);		\
      memcpy (front, merged, sizeof (_type) * len);		\
    }								\
    _name;							\
 })
#define sort(_ord, _type) sort_aux(makeident, _ord, _type)

#define sortx_aux(_name, _ord, _seq)					\
  ({									\
    void _name (typeof(_seq.front) front, typeof(_seq.back) back)	\
    {									\
      int len = back - front;						\
      if (len <= 1)							\
	return;								\
      typeof(front) mid = front + len/2;				\
      _name (front, mid);						\
      _name (mid, back);						\
      typeof(*front) merged[len];					\
      int mlen = 0;							\
      typeof(*front) *x = front, *y = mid;				\
      while (x != mid && y != back)					\
	if (_ord <= 0) merged[mlen++] = *(x++);				\
	else merged[mlen++] = *(y++);					\
      while (x != mid) merged[mlen++] = *(x++);				\
      while (y != back) merged[mlen++] = *(y++);			\
      memcpy (front, merged, sizeof (*front) * len);			\
    }									\
    _name (_seq.front, _seq.back);					\
  })
#define sortx(_ord, _seq) sortx_aux(makeident, _ord, _seq)

typedef long long ll;

struct pair { ll l, h; };
DEFINE_XARR(pairs, struct pair);
typedef struct pairs Pairs;


int
main ()
{
  ll value[200000][2];
  fc
    {
      ll n = ruint, k = ruint;
      int p[n];
      Is chx[n];
      p[0] = -1;
      fn chx[i] = Is_make ();
      fz (i, n - 1) p[i + 1] = ruint - 1, Is_insert (&chx[p[i + 1]], i + 1);
      ll s[n];
      fn s[i] = ruint;
      ll accs[n];
      void dfsaccs (int v, ll acc)
      {
	acc += s[v];
	accs[v] = acc;
	fx (ch, chx[v])
	  dfsaccs (*ch, acc);
      }
      dfsaccs (0, 0);
      ll kdist[n];
      void dfsk (int v, int todist)
      {
	int nch = chx[v].len;
	if (nch == 0)
	  {
	    kdist[v] = todist;
	    return;
	  }
	ll div = todist / nch;
	kdist[v] = todist;
	fx (ch, chx[v])
	  dfsk (*ch, div);
      }
      dfsk (0, k);

      fn value[i][0] = -1, value[i][1] = -1;
      void calcvalue (int v, int ad)
      {
	if (value[v][ad] != -1)
	  {
	    return;
	  }
	
	int nch = chx[v].len;
	if (nch == 0)
	  {
	    value[v][ad] = (kdist[v] + ad) * accs[v];
	    return;
	  }
	Pairs pairs = pairs_make ();
	value[v][ad] = 0;
	fx (ch, chx[v])
	  {
	    calcvalue (*ch, 0), calcvalue (*ch, 1);
	    ll hv = value[*ch][1] - value[*ch][0];
	    assert (hv >= 0);
	    int i = ch - chx[v].front;
	    pairs_insert (&pairs, (struct pair) {.h = hv, .l = i});
	    value[v][ad] += value[*ch][0];
	  }
	sortx (balor(y->h, x->h, bal(y->l, x->l)), pairs);
	ll rem = (kdist[v] % nch) + ad;
	fz (i, rem) value[v][ad] += pairs.front[i].h;
	free (pairs.front);
      }
      calcvalue (0, 0);
      printf ("%lld\n", value[0][0]);
      fn free (chx[i].front);
    }
}

