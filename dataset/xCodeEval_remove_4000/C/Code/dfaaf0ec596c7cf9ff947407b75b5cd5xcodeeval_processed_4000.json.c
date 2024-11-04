














struct typename							\
{								\
  T payload;							\
  struct typename *next;					\
};								\
								\
static struct typename *					\
typename
{								\
  struct typename *list = malloc (sizeof(struct typename));	\
  list->payload = payload;					\
  list->next = next;						\
  return list;							\
}								\
								\
static struct typename *					\
typename
{								\
  return typename
}								\
								\
static struct typename *					\
 typename
{								\
  assert (list);						\
  assert (payload);						\
  *payload = list->payload;					\
  struct typename *next = list->next;				\
  free (list);							\
  return next;							\
}





typedef unsigned int uint;
typedef long long lon;
typedef unsigned long long ulon;












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

void
id0 (char ch)
{
  *output_ptr++ = ch;
  if (!*output_ptr)
    {
      write (1, output_buffer, BUFFER_SIZE);
      output_ptr = output_buffer;
    }
}

char
id2 ()
{
  if (*input_ptr) return *input_ptr++;
  int read_bytes = read (0, input_buffer, BUFFER_SIZE);
  input_buffer[read_bytes] = 0;
  input_ptr = input_buffer;
  return *input_ptr++;
}
char
id12 ()
{
  if (*input_ptr) return *input_ptr;
  int read_bytes = read (0, input_buffer, BUFFER_SIZE);
  input_buffer[read_bytes] = 0;
  input_ptr = input_buffer;
  return *input_ptr;
}

void
id11 (uint n)
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
      id0 (digs[--nodigs]);
    }
}


uint
id10 ()
{
  while (isspace (id12 ()))
    id2 ();
  uint res = 0;
  char ch;
  for (;;)
    {
      switch (ch = id12 ())
	{
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	  res *= 10;
	  res += ch - '0';
	  id2 ();
	  break;
	default: return res;
	}
    }
}

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
id3 (struct mem *mem, void *ptr)
{
  assert (ptr >= mem->allocated && ptr < mem->allocated + mem->type_size * mem->max_elements);
  return (void*)((size_t)ptr & (size_t)mem->block_mask);
}
static void
mem_free (struct mem *mem, void *ptr)
{
  assert (ptr >= mem->allocated && ptr < mem->allocated + mem->type_size * mem->max_elements);
  assert (id3 (mem, ptr) == ptr);
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
id4 (size_t value_size, size_t max_values)
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
id6 (struct flatmem *mem)
{
  void *ptr = mem->past_end_ptr;
  mem->past_end_ptr += mem->value_size;
  return ptr;
}
void
id5 (struct flatmem *mem)
{
  mem->past_end_ptr = mem->allocated;
}


FILE *dotfile = NULL;












  struct typename							\
  {									\
    int color;								\
    struct typename *connection[3];					\
    T value;								\
  };									\
									\
  struct flatmem typename
									\
  void									\
  typename
  {									\
    typename
  }									\
  struct typename *							\
  typename
  {									\
    struct typename *node = id6 (&typename
    node->connection[0] = 0;						\
    node->connection[1] = 0;						\
    node->connection[2] = 0;						\
    node->color = RED;							\
    node->value = value;						\
    return node;							\
  }									\
									\
  struct typename *							\
  typename
  {									\
    struct typename *node = id6 (&typename
    node->connection[0] = 0;						\
    node->connection[1] = 0;						\
    node->connection[2] = 0;						\
    node->color = BLACK;						\
    node->value = value;						\
    return node;							\
  }									\
									\
  static inline struct typename *					\
  typename
  {									\
    RIGHT(b) = c;							\
    LEFT(b) = a;							\
    if (a) PARENT(a) = b;						\
    if (c) PARENT(c) = b;						\
    return b;								\
  }									\
									\
  __attribute__ ((hot)) static inline struct typename *			\
  typename
  {									\
    RIGHT(a) = b;							\
    if (b) PARENT(b) = a;						\
    return a;								\
  }									\
									\
  __attribute__ ((hot)) static inline struct typename *			\
  typename
  {									\
    LEFT(b) = a;							\
    if (a) PARENT(a) = b;						\
    return b;								\
  }									\
									\
  int check_depth;							\
  void									\
  typename
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
    typename
    typename
  }									\
									\
									\
  __attribute__ ((hot)) struct typename *				\
  typename
		     T value)						\
  {									\
    if (!root)								\
      {									\
	struct typename *root = typename
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
	    v = typename
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
	    typename
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
	    typename
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
  typename
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
		   



struct typename								\
{									\
  T *front;								\
  T *back;								\
  int len;								\
  int capacity;								\
};									\
									\
struct typename								\
typename
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
typename
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
id7 ()
{
  while (isspace (id12 ())) id2 ();
  struct Str res = Str_make ();
  for (char ch; !isspace (ch = id12 ()) && ch; id2 ())
    Str_insert (&res, ch);
  return res;
}


void
id1 (struct Str string)
{
  fx (ch, string) wchar (*ch);
}
void
id9 (const char *string)
{
  for (; *string; string++) wchar (*string);
}






typedef long long ll;




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


		       uint: id11, \
		       char *: id9, \
		       Str: id1)(x)

int
main ()
{
  fc
    {
      Str s = rword, t = rword;
      Is aps = Is_make ();
      fi (s.len - t.len + 1)
	{
	  if (streq (s.front + i, t.front, t.len))
	    {
	      Is_insert (&aps, i);
	    }
	}
      int n = aps.len;

      Is nxt = mkis (n, 0);
      int ptr = 0;
      fi (n)
	{
	  while (ptr < n && aps.front[ptr] < aps.front[i] + t.len)
	    ptr++;

	  nxt.front[i] = ptr;
	}
      
      bool computed[n + 1][n + 1];
      fi (n + 1) fj (n + 1) computed[i][j] = 0;
      int minmoves[n+1][n+1];
      ll id8[n+1][n+1];
      void compute (int i, int previ)
      {
	if (computed[i][previ]) return;
	assert (previ <= i);
	if (i == n)
	  {
	    id8[i][previ] = 1;
	    minmoves[i][previ] = 0;
	    computed[i][previ] = true;
	    return;
	  }
	assert (nxt.front[previ] > i);
	if (nxt.front[previ] == i + 1)
	  {
	    int afteri = nxt.front[i];
	    compute (afteri, afteri);
	    minmoves[i][previ] = minmoves[afteri][afteri] + 1;
	    id8[i][previ] = id8[afteri][afteri];
	  }
	else
	  {
	    int afteri = nxt.front[i];
	    compute (afteri, afteri);
	    compute (i + 1, previ);
	    int min1 = 1 + minmoves[afteri][afteri],
	      num1 = id8[afteri][afteri];
	    int min2 = minmoves[i + 1][previ],
	      num2 = id8[i + 1][previ];
	    if (min1 == min2)
	      {
		minmoves[i][previ] = min1;
		id8[i][previ] = ad(num1, num2);
	      }
	    else if (min1 < min2)
	      {
		minmoves[i][previ] = min1;
		id8[i][previ] = num1;
	      }
	    else
	      {
		minmoves[i][previ] = min2;
		id8[i][previ] = num2;
	      }
	  }
	computed[i][previ] = true;
      }
      if (n) compute (0, 0), wr (minmoves[0][0]), wr (" "), wr ((int)id8[0][0]), wr ("\n");
      else wr ("0 1\n");
    }
}
