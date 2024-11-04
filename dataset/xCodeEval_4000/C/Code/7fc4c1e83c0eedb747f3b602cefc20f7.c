

#define fz(i, n) for (uint i = 0; i < n; i++)
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
#define wuint fst_write_uint
int
fst_read_uint ()
{
  int res = 0;
  char ch;
 nextone:
  ch = fst_read_char ();
  switch (ch)
    {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      res *= 10;
      res += ch - '0';
      goto nextone;
    default: return res;
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
									\
									\
  void									\
  typename##_db_print_nodes (struct typename *root)			\
  {									\
    fprintf (dotfile, "\n%lld [label=%d, color=%s];\n",			\
	     (long long) root,						\
	     root->value,						\
	     root->color? "BLACK" : "RED");				\
    for (int i = 0; i < 2; i++)						\
      {									\
	if (root->connection[i])					\
	  {								\
	    typename##_db_print_nodes (root->connection[i]);		\
	  }								\
      }									\
  }									\
									\
  void									\
  typename##_db_print_connections (struct typename *root)		\
  {									\
    for (int i = 0; i < 2; i++)						\
      {									\
	if (root->connection[i])					\
	  {								\
	    fprintf (dotfile, "\n%lld -> %lld;\n", (long long) root,	\
		     (long long) (root->connection[i]));		\
	    typename##_db_print_connections (root->connection[i]);	\
	  }								\
      }									\
  }									\
									\
  void									\
  typename##_db_break (struct typename *root)				\
  {									\
    if (dotfile)							\
      {									\
	fclose (dotfile);						\
      }									\
    dotfile = fopen ("out.gv", "w");					\
    fprintf (dotfile, "digraph {\n");					\
    typename##_db_print_nodes (root);					\
    typename##_db_print_connections (root);				\
    fprintf (dotfile, "}\n");						\
    fflush (dotfile);							\
    system ("dot -Tpdf -O out.gv");					\
  }									\
									\
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
  size_t len;								\
  size_t capacity;							\
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

#define fx(ai, xarr) for (__auto_type ai = xarr.front; ai != xarr.back; ai++)


#include <ctype.h>

DEFINE_XARR(string, char);

struct string
fst_read_string ()
{
  struct string s = string_make ();
  char ch;
 next:
  ch = fst_read_char ();
  if (isspace (ch)) return s;
  string_insert (&s, ch);
  goto next;
}

struct op
{
  uint which;
  uint i;
};
DEFINE_XARR(ops, struct op);

#define rs (fst_read_string ())

int
main ()
{
  uint ntc = ruint;
  fz (tc, ntc)
    {
      struct string t = rs;
      uint n = ruint;
      struct ops ops = ops_make ();
      struct string s[n];
      fn
	{
	  s[i] = rs;
	}
      uint get_max (uint from, uint* which)
      {
	uint best = from;
	fn
	  {
	    uint back = from + s[i].len;
	    if (back <= t.len && memcmp (t.front + from, s[i].front, s[i].len) == 0)
	      {
		if (back > best)
		  {
		    best = back;
		    *which = i;
		  }
	      }
	  }
	return best;
      }
      uint mx = 0;
      uint which = -1u;
      uint i_apply = -1u;
      uint good = 1;
      for (uint i = 0; i < t.len;)
	{
	  uint next_which = -1u;
	  uint next_mx = get_max (i, &next_which);
	  if (next_mx > mx)
	    {
	      mx = next_mx;
	      which = next_which;
	      i_apply = i;
	    }
	  if (mx == i)
	    {
	      good = 0;
	      break;
	    }
	  else
	    {
	      assert (which != -1u);
	      ops_insert (&ops, (struct op) {which, i_apply});
	      uint mx_after = mx;
	      uint which_after = -1u;
	      for (uint j = i + 1; j < mx; j++) 
		{
		  uint next_which = -1u;
		  uint next_mx = get_max (j, &next_which);
		  if (next_mx > mx_after)
		    {
		      mx_after = next_mx;
		      which_after = next_which;
		      i_apply = j;
		    }
		}
	      i = mx;
	      mx = mx_after;
	      which = which_after;
	    }
	}
      if (good)
	{
	  wuint (ops.len), wchar ('\n');
	  fx (op, ops)
	    {
	      wuint (op->which + 1), wchar (' '), wuint (op->i + 1), wchar ('\n');
	    }
	  wchar ('\n');
	}
      else
	{
	  wchar ('-'), wchar ('1'), wchar ('\n');
	}
      
    }
}
