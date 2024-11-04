












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
id6 ()
{
  if (*input_ptr) return *input_ptr++;
  int read_bytes = read (0, input_buffer, BUFFER_SIZE);
  input_buffer[read_bytes] = 0;
  input_ptr = input_buffer;
  return *input_ptr++;
}
char
id7 ()
{
  if (*input_ptr) return *input_ptr;
  int read_bytes = read (0, input_buffer, BUFFER_SIZE);
  input_buffer[read_bytes] = 0;
  input_ptr = input_buffer;
  return *input_ptr;
}

void
id5 (uint n)
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

int
id3 ()
{
  int res = 0;
  char ch;
 nextone:
  ch = id6 ();
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
id8 (struct mem *mem, void *ptr)
{
  assert (ptr >= mem->allocated && ptr < mem->allocated + mem->type_size * mem->max_elements);
  return (void*)((size_t)ptr & (size_t)mem->block_mask);
}
static void
mem_free (struct mem *mem, void *ptr)
{
  assert (ptr >= mem->allocated && ptr < mem->allocated + mem->type_size * mem->max_elements);
  assert (id8 (mem, ptr) == ptr);
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
id1 (size_t value_size, size_t max_values)
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
id4 (struct flatmem *mem)
{
  void *ptr = mem->past_end_ptr;
  mem->past_end_ptr += mem->value_size;
  return ptr;
}
void
id2 (struct flatmem *mem)
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
    struct typename *node = id4 (&typename
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
    struct typename *node = id4 (&typename
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
  size_t len;								\
  size_t capacity;							\
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




DEFINE_XARR(ints, int);
DEFINE_XARR(string, char);

int
main ()
{
  int t = ruint;
  while (t--)
    {
      struct ints ixs[26];
      for (int i = 0; i < 26; i++)
	{
	  ixs[i] = ints_make ();
	}
      char ch;
      struct string s = string_make ();
      while ((ch = rchar) != '\n')
	{
	  string_insert (&s, ch);
	}
      int i = 1;
      fx (ch, s)
	{
	  ints_insert (&ixs[*ch - 'a'], i);
	  i++;
	}
      char f = s.front[0];
      char l = s.back[-1];
      int min = l - f;
      if (min < 0) min = -min;
      int m = 0;
      if (f <= l)
	for (char ch = f; ch <= l; ch++)
	  {
	    m += ixs[ch - 'a'].len;
	  }
      else
	for (char ch = f; ch >= l; ch--)
	  {
	    m += ixs[ch - 'a'].len;
	  }
      wuint ((uint) min), wchar (' '), wuint ((uint) m), wchar ('\n');
      if (f <= l) for (char ch = f; ch <= l; ch++)
		    {
		      fx (ix, ixs[ch - 'a'])
			{
			  wuint (*ix), wchar (' ');
			}
		    }
      else for (char ch = f; ch >= l; ch--)
	     {
	       
	       fx (ix, ixs[ch - 'a'])
		 {
		   wuint (*ix), wchar (' ');
		 }
	     }
      wchar ('\n');
    }
  
}
