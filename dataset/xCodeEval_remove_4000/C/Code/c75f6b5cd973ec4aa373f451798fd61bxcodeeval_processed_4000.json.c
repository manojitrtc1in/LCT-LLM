















































typedef unsigned int natural;
typedef natural tipo_dato;
typedef long long entero_largo;
typedef unsigned long long entero_largo_sin_signo;
typedef long long bitch_vector;
typedef char byteme;

typedef enum BOOLEANOS {
	falso = 0, verdadero
} bool;


















		do \
		{ \
			size_t id105 = 0; \
			void *array[id69]; \
 			id105 = backtrace(array, id69); \
			id77(formato,__FILE__, __func__, __LINE__,id105,
		} \
		while(0);







void id77(const char *format, ...);

void id73(struct timespec *ts) {


	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts->tv_sec = mts.tv_sec;
	ts->tv_nsec = mts.tv_nsec;


	clock_gettime(CLOCK_REALTIME, ts);



}

void id70(char *stime) {
	time_t ltime;
	struct tm result;
	long ms;

	struct timespec spec;

	char id89[50];

	ltime = time(NULL);


	localtime_r(&ltime, &result);
	asctime_r(&result, stime);


	*(stime + strlen(stime) - 1) = ' ';


	id73(&spec);
	ms = round(spec.tv_nsec / 1.0e3);

	sprintf(id89, "%ld", ms);
	strcat(stime, id89);
}

void id77(const char *format, ...) {

	va_list arg;
	va_list arg2;
	const char *id2 = "tiempo: %s; ";
	const char *HEADER =
	"archivo: %s; funcion: %s; linea %d; nivel: %zd caca 8====D ";
	char formato[id69 + sizeof(HEADER)
	+ sizeof(id2)] = {'\0'};
	char id32[sizeof(id2) + 100] = {'\0'};
	char cadena_timestamp[100] = {'\0'};

	id70(cadena_timestamp);
	sprintf(id32, id2, cadena_timestamp);

	strcpy(formato, id32);
	strcat(formato, HEADER);
	strcat(formato, format);
	strcat(formato, "\n");

	va_start(arg, format);
	va_copy(arg2, arg);
	vprintf(formato, arg2);
	va_end(arg2);
	va_end(arg);
	setbuf(stdout, NULL);
}



static char *id27(tipo_dato *arreglo, int id92,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id17 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id92; i++) {
		id17 += sprintf(ap_buffer + id17,
				"%12d", *(arreglo + i));
		if (i < id92 - 1) {
			*(ap_buffer + id17++) = ',';
		}
	}
	*(ap_buffer + id17) = '\0';
	return ap_buffer;
}

static char *id71(natural *arreglo,
		natural id92, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id17 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id92; i++) {
		id17 += sprintf(ap_buffer + id17, "%2u",
				*(arreglo + i));
		if (i < id92 - 1) {
			*(ap_buffer + id17++) = ',';
		}
	}
	*(ap_buffer + id17) = '\0';
	return ap_buffer;
}
char *id19(tipo_dato *matrix, natural id4,
		natural id0, char *buffer) {
	int i, j;
	natural id85 = 0;
	for (int i = 0; i < id4; i++) {
		id27(matrix + i * id0, id0,
				buffer + id85);
		id85 += strlen(buffer + id85);
		buffer[id85++] = '\n';
		
	}
	return buffer;
}

static char *id80(entero_largo_sin_signo *arreglo,
		entero_largo_sin_signo id92, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id17 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id92; i++) {
		id17 += sprintf(ap_buffer + id17, "%2llu",
				*(arreglo + i));
		if (i < id92 - 1) {
			*(ap_buffer + id17++) = ',';
		}
	}
	*(ap_buffer + id17) = '\0';
	return ap_buffer;
}

static char *id27(tipo_dato *arreglo, int id92,
		char *buffer) {
	return NULL;
}
static char *id71(natural *arreglo,
		natural id92, char *buffer) {
	return NULL;
}
char *id19(tipo_dato *matrix, natural id4,
		natural id0, char *buffer) {
	return NULL;
}

static char *id80(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id92,
		char *buffer) {
	return NULL;
}

void id18(char s[], char chr, char id104) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == chr) {
			s[i] = id104;
		}
		i++;
	}
}

static int id51(tipo_dato *matrix, int *id37,
		int *id43, int id54, int id38) {
	int id96 = 0;
	int id34 = 0;
	tipo_dato numero = 0;
	char *id62 = NULL;
	char *id1 = NULL;
	char *linea = NULL;

	linea = calloc(CACA_COMUN_TAM_MAX_LINEA, sizeof(char));

	while (id96 < id54
			&& fgets(linea, CACA_COMUN_TAM_MAX_LINEA, stdin)) {
		id34 = 0;
		id1 = linea;
		id18(linea, '\n', '\0');
		if (!strlen(linea)) {
			caca_log_debug("weird, linea vacia");
			continue;
		}
		for (id62 = linea;; id62 =
				id1) {
			numero = strtol(id62, &id1, 10);
			if (id1 == id62) {
				break;
			}
			*(matrix + id96 * id38 + id34) =
					numero;
			id34++;
		}
		if (id43) {
			id43[id96] = id34;
		}
		id96++;
		caca_log_debug("las filas son %d, con clos %d", id96,
				id34);
	}

	*id37 = id96;
	free(linea);
	return 0;
}

static inline natural id99(tipo_dato num) {
	natural id67 = 0;
	tipo_dato num_mod = 0;
	num_mod = num;
	while (num_mod) {
		num_mod &= ~(num_mod & (-num_mod));
		id67++;
	}
	return id67;
}

static inline char id7(char letra) {
	return letra - 'a';
}

static inline natural id21(natural *nums, natural id50) {
	natural max = 0;

	for (int i = 0; i < id50; i++) {
		natural num_act = nums[i];
		if (num_act > max) {
			max = num_act;
		}
	}

	return max;
}







typedef struct stackaca_nodo {
	void *data;
	struct stackaca_nodo* next;
} stackaca_nodo;
typedef struct stackaca {
	stackaca_nodo *cabeza;
} stackaca;


static inline void id6(stackaca *ctx) {
	ctx->cabeza = NULL;
}


static inline void id72(stackaca *ctx, void *data) {
	stackaca_nodo* tmp = (stackaca_nodo*) malloc(sizeof(stackaca_nodo));
	assert_timeout(tmp);
	tmp->data = data;
	tmp->next = ctx->cabeza;
	ctx->cabeza = tmp;
}

static inline void *id74(stackaca *ctx) {
	stackaca_nodo* tmp = ctx->cabeza;
	void *caca = tmp->data;
	ctx->cabeza = tmp->next;
	free(tmp);
	return caca;
}

static inline bool id57(stackaca *ctx) {
	return ctx->cabeza == NULL ? verdadero : falso;
}

static inline void id97(stackaca *ctx) {
	while (!id57(ctx)) {
		id74(ctx);
	}
}



typedef natural hm_iter;

typedef struct hash_map_entry {
	entero_largo llave;
	entero_largo valor;
} hm_entry;
typedef struct hash_map_cubeta {
	uint64_t hash;
	hm_entry *entry;
} hm_cubeta;
typedef struct hash_map_robin_hood_back_shift {
	hm_cubeta *buckets_;
	uint64_t num_buckets_;
	uint64_t num_buckets_used_;
	uint64_t probing_min_;
	uint64_t probing_max_;
} hm_rr_bs_tabla;
int id11(hm_rr_bs_tabla *ht, int id98) {
	ht->num_buckets_ = id98;
	ht->buckets_ = (hm_cubeta *) calloc(ht->num_buckets_, sizeof(hm_cubeta));
	ht->num_buckets_used_ = 0;
	ht->probing_max_ = id98;
	return 0;
}
int id107(hm_rr_bs_tabla *ht) {
	if (ht->buckets_ != NULL) {
		for (uint32_t i = 0; i < ht->num_buckets_; i++) {
			if (ht->buckets_[i].entry != NULL) {
				free(ht->buckets_[i].entry);
				ht->buckets_[i].entry = NULL;
			}
		}
		free(ht->buckets_);
	}
	return 0;
}
static inline int id29(
		hm_rr_bs_tabla *ht, uint64_t id15, uint64_t *distance) {
	hm_cubeta cubeta = ht->buckets_[id15];
	*distance = 0;
	if (cubeta.entry == NULL)
		return -1;
	uint64_t id98 = ht->num_buckets_;
	uint64_t index_init = cubeta.hash % id98;
	if (index_init <= id15) {
		*distance = id15 - index_init;
	} else {
		*distance = id15 + (id98 - index_init);
	}
	return 0;
}
hm_iter id33(hm_rr_bs_tabla *ht,
		const entero_largo key, entero_largo *value) {
	uint64_t id98 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;


	uint64_t hash = key % id98;
	uint64_t index_init = hash;
	uint64_t probe_distance = 0;
	uint64_t index_current;
	bool found = falso;
	uint32_t i;
	*value = id64;
	for (i = 0; i < id98; i++) {
		index_current = (index_init + i) % id98;
		hm_entry *entrada = ht->buckets_[index_current].entry;
		if (entrada == NULL) {
			break;
		}
		id29(ht,
				index_current, &probe_distance);
		if (i > probe_distance) {
			break;
		}
		if (entrada->llave == key) {
			*value = entrada->valor;
			found = verdadero;
			break;
		}
	}
	if (found)
		return index_current;
	return id64;
}
hm_iter id14(hm_rr_bs_tabla *ht, entero_largo key,
		entero_largo value, bool *nuevo_entry) {
	uint64_t id98 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_min_;
	hm_cubeta *cubetas = ht->buckets_;
	*nuevo_entry = verdadero;
	if (ht->num_buckets_used_ == id98) {
		*nuevo_entry = falso;
		return id64;
	}
	ht->num_buckets_used_ += 1;


	uint64_t hash = key % id98;
	uint64_t index_init = hash;
	hm_entry *entry = (hm_entry *) calloc(1, sizeof(hm_entry));
	entry->llave = key;
	entry->valor = value;
	uint64_t index_current = index_init % id98;
	uint64_t probe_current = 0;
	uint64_t probe_distance;
	hm_entry *entry_temp;
	uint64_t hash_temp;
	uint64_t i;
	for (i = 0; i < id98; i++) {
		index_current = (index_init + i) % id98;
		hm_cubeta *cubeta = cubetas + index_current;
		if (cubeta->entry == NULL) {
			cubeta->entry = entry;
			cubeta->hash = hash;
			if (index_current > prob_max) {
				ht->probing_max_ = index_current;
			}
			if (index_current < prob_min) {
				ht->probing_min_ = index_current;
			}
			break;
		} else {
			if (cubeta->entry->llave == key) {
				free(entry);
				*nuevo_entry = falso;
				break;
			}
			id29(ht,
					index_current, &probe_distance);
			if (probe_current > probe_distance) {
				

				entry_temp = cubeta->entry;
				hash_temp = cubeta->hash;
				cubeta->entry = entry;
				cubeta->hash = hash;
				entry = entry_temp;
				hash = hash_temp;
				probe_current = probe_distance;
			}
		}
		probe_current++;
	}
	return index_current;
}
int id83(hm_rr_bs_tabla *ht,
		const tipo_dato key) {
	uint64_t id98 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_max_;
	uint64_t hash = key % id98;
	uint64_t index_init = hash;
	bool found = falso;
	uint64_t index_current = 0;
	uint64_t probe_distance = 0;
	hm_entry *entrada = NULL;
	for (uint64_t i = 0; i < id98; i++) {
		index_current = (index_init + i) % id98;
		entrada = ht->buckets_[index_current].entry;
		id29(ht,
				index_current, &probe_distance);
		if (entrada == NULL || i > probe_distance) {
			break;
		}
		if (entrada->llave == key) {
			found = verdadero;
			break;
		}
	}
	if (found) {
		free(entrada);
		uint64_t i = 1;
		uint64_t index_previous = 0, index_swap = 0;
		for (i = 1; i < id98; i++) {
			index_previous = (index_current + i - 1) % id98;
			index_swap = (index_current + i) % id98;
			hm_cubeta *id53 = ht->buckets_ + index_swap;
			hm_cubeta *id23 = ht->buckets_ + index_previous;
			if (id53->entry == NULL) {
				id23->entry = NULL;
				break;
			}
			uint64_t distance;
			if (id29(
					ht, index_swap, &distance) != 0) {
				fprintf(stderr, "Error in FillDistanceToInitIndex()");
			}
			if (!distance) {
				id23->entry = NULL;
				break;
			}
			id23->entry = id53->entry;
			id23->hash = id53->hash;
		}
		if (i < id98) {
			if (index_previous == prob_min) {
				prob_min++;
				if (prob_min >= id98) {
					prob_min = 0;
				} else {
					while (prob_min < id98
							&& ht->buckets_[prob_min].entry) {
						prob_min++;
					}
					if (prob_min >= id98) {
						prob_min = id98;
					}
				}
				ht->probing_min_ = prob_min;
			}
			if (index_previous == prob_max) {
				prob_max--;
				if (prob_max >= id98) {
					prob_max = id98;
				} else {
					while (((int64_t) prob_max) >= 0
							&& ht->buckets_[prob_max].entry) {
						prob_max--;
					}
					if (prob_max >= id98) {
						prob_max = 0;
					}
				}
				ht->probing_max_ = prob_max;
			}
		}
		ht->num_buckets_used_--;
		return 0;
	}
	return 1;
}
static inline int id81(
		hm_rr_bs_tabla *ht) {
	return ht->probing_min_;
}
static inline int id55(
		hm_rr_bs_tabla *ht) {
	return ht->probing_max_;
}
static inline bool id48(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	return !!ht->buckets_[indice].entry;
}
static inline entero_largo id100(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	return entrada->llave;
}
static inline void id87(
		hm_rr_bs_tabla *ht, hm_iter indice, entero_largo valor) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	entrada->valor = valor;
}
int id46(hm_rr_bs_tabla *ht,
		hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	uint64_t id98 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_max_;
	uint64_t index_current = indice;
	hm_entry *entrada = ht->buckets_[index_current].entry;
	assert_timeout(entrada);
	free(entrada);
	uint64_t i = 1;
	uint64_t index_previous = 0, index_swap = 0;
	for (i = 1; i < id98; i++) {
		index_previous = (index_current + i - 1) % id98;
		index_swap = (index_current + i) % id98;
		hm_cubeta *id53 = ht->buckets_ + index_swap;
		hm_cubeta *id23 = ht->buckets_ + index_previous;
		if (id53->entry == NULL) {
			id23->entry = NULL;
			break;
		}
		uint64_t distance;
		if (id29(ht,
				index_swap, &distance) != 0) {
			fprintf(stderr, "Error in FillDistanceToInitIndex()");
		}
		if (!distance) {
			id23->entry = NULL;
			break;
		}
		id23->entry = id53->entry;
		id23->hash = id53->hash;
	}
	if (i < id98) {
		if (index_previous == prob_min) {
			prob_min++;
			if (prob_min >= id98) {
				prob_min = 0;
			} else {
				while (prob_min < id98 && ht->buckets_[prob_min].entry) {
					prob_min++;
				}
				if (prob_min >= id98) {
					prob_min = id98;
				}
			}
			ht->probing_min_ = prob_min;
		}
		if (index_previous == prob_max) {
			prob_max--;
			if (prob_max >= id98) {
				prob_max = id98;
			} else {
				while (((int64_t) prob_max) >= 0 && ht->buckets_[prob_max].entry) {
					prob_max--;
				}
				if (prob_max >= id98) {
					prob_max = 0;
				}
			}
			ht->probing_max_ = prob_max;
		}
	}
	ht->num_buckets_used_--;
	return 0;
}
static inline entero_largo id84(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	return entrada->valor;
}
static inline bool id49(hm_rr_bs_tabla *ht) {
	assert_timeout(ht->num_buckets_used_ <= ht->num_buckets_);
	return !ht->num_buckets_used_;
}

static inline void id106(hm_rr_bs_tabla *ht,
		entero_largo llave, entero_largo valor) {
	hm_iter iter = 0;
	entero_largo *valor_int = &(entero_largo ) { 0 };

	iter = id33(ht, llave, valor_int);
	

	assert_timeout(iter!=id64);

	id87(ht, iter, valor);
}

static inline void id20(
		hm_rr_bs_tabla *ht, entero_largo llave, entero_largo valor) {
	hm_iter iter = 0;
	bool nuevo = falso;
	iter = id14(ht, llave, valor, &nuevo);

	assert_timeout(iter!=id64);
	assert_timeout(nuevo);
}











typedef struct heap_shit_nodo {
	void *valor;
} heap_shit_nodo;
typedef struct heap_shit heap_shit;

typedef int (*heap_shit_compara_prioridad)(void *a, void *b);
typedef int (*heap_shit_compara_llave)(void *valor);
typedef entero_largo (*heap_shit_obten_llave)(void *valor);

struct heap_shit {
	bool min;
	natural heap_size;
	heap_shit_nodo heap[id79];
	hm_rr_bs_tabla *tablon_llave_a_idx_heap;
	heap_shit_compara_llave id36;
	heap_shit_compara_prioridad id78;
	heap_shit_obten_llave id28;
};


static inline heap_shit *id41(bool es_min,
		heap_shit_compara_llave id36,
		heap_shit_compara_prioridad id78,
		heap_shit_obten_llave id28) {
	heap_shit *heap = calloc(1, sizeof(heap_shit));
	assert_timeout(heap);
	heap->heap_size = 0;
	heap->min = es_min;
	heap->id36 = id36;
	heap->id78 = id78;
	heap->id28 = id28;
	memset(heap->heap, HEAP_SHIT_VALOR_INVALIDO, sizeof(heap->heap));
	heap->tablon_llave_a_idx_heap = calloc(1, sizeof(hm_rr_bs_tabla));
	assert_timeout(heap->tablon_llave_a_idx_heap);
	id11(heap->tablon_llave_a_idx_heap,
	id79);
	return heap;
}

void id45(heap_shit *heap_ctx) {
	id107(heap_ctx->tablon_llave_a_idx_heap);
	free(heap_ctx->tablon_llave_a_idx_heap);
	free(heap_ctx);
}

static inline bool id10(heap_shit_nodo *nodo) {
	return nodo->valor != (void *) HEAP_SHIT_VALOR_INVALIDO;
}

static inline void id24(heap_shit *heap_ctx) {
	for (int i = 1; i <= heap_ctx->heap_size; i++) {
		assert_timeout(id10(heap_ctx->heap + i));
	}
}

static inline natural id42(natural id75) {
	return id75 >> 1;
}

static inline natural id60(natural id75) {
	return id75 << 1;
}


static inline void id56(heap_shit *heap_ctx,
		heap_shit_nodo *id3) {
	natural heap_size = heap_ctx->heap_size;
	heap_shit_nodo *heap = NULL;
	hm_rr_bs_tabla *id13 = heap_ctx->tablon_llave_a_idx_heap;
	bool nuevo;

	heap = heap_ctx->heap;

	heap_size++;
	heap[heap_size] = *id3; 
	
	natural now = heap_size;

	while (id10(heap + id42(now))
			&& ((heap_ctx->min
					&& heap_ctx->id78(
							heap[id42(now)].valor,
							id3->valor) > 0)

					|| (!heap_ctx->min
							&& heap_ctx->id78(
									heap[id42(now)].valor,
									id3->valor) < 0

					))) {


		natural id91 = id42(now);
		entero_largo id68 = heap_ctx->id28(
				heap[id91].valor);
		assert_timeout(id68!= HEAP_SHIT_VALOR_INVALIDO);

		heap[now] = heap[id91];
		id106(id13, id68, now);
		caca_log_debug("llave %d tiene valor %u ", id68, now);

		now = id91;
	}



	heap[now] = *id3;
	id20(id13,
			heap_ctx->id28(id3->valor), now);

	heap_ctx->heap_size = heap_size;
	assert_timeout(heap_size >= now);


}





static inline void *id39(heap_shit *heap_ctx, natural id22) {
	natural heap_size = heap_ctx->heap_size;
	natural child, now;
	heap_shit_nodo minElement = { 0 };
	heap_shit_nodo lastElement = { 0 };
	heap_shit_nodo *heap;
	hm_rr_bs_tabla *id13 = heap_ctx->tablon_llave_a_idx_heap;
	void *resultado;
	bool nuevo;

	heap = heap_ctx->heap;

	assert_timeout(heap_size >= id22);
	assert_timeout(id22);

	
	minElement = heap[id22];
	resultado = minElement.valor;
	lastElement = heap[heap_size--];

	now = id22;
	if (id22 != heap_size + 1) {
		if (id10(heap + id42(now))
				&& ((heap_ctx->min
						&& heap_ctx->id78(
								heap[id42(now)].valor,
								lastElement.valor) > 0)
						|| (!heap_ctx->min
								&& (heap_ctx->id78(
										heap[id42(now)].valor,
										lastElement.valor))))) {

			while (id10(heap + id42(now))
					&& ((heap_ctx->min
							&& heap_ctx->id78(
									heap[id42(now)].valor,
									lastElement.valor) > 0)
							|| (!heap_ctx->min
									&& (heap_ctx->id78(
											heap[id42(now)].valor,
											lastElement.valor) < 0)))) {
				assert_timeout(now <= heap_size);
				natural id91 = id42(now);
				entero_largo id68 = heap_ctx->id28(
						heap[id91].valor);

				assert_timeout(id68 != HEAP_SHIT_VALOR_INVALIDO);

				heap[now] = heap[id91];

				id106(id13,
						id68, now);

				caca_log_debug("llave %d tiene valor %u", id68, now);

				now = id91;
			}
		} else {

			
			for (now = id22; id60(now) <= heap_size;
					now = child) {
				
				
				child = id60(now);
				assert_timeout(child <= heap_size);
				
				if (child != heap_size
						&& ((heap_ctx->min
								&& heap_ctx->id78(
										heap[child + 1].valor,
										heap[child].valor) < 0)
								|| (!heap_ctx->min
										&& heap_ctx->id78(
												heap[child + 1].valor,
												heap[child].valor) > 0))) {
					child++;
				}
				assert_timeout(child <= heap_size);
				
				

				if ((heap_ctx->min
						&& heap_ctx->id78(lastElement.valor,
								heap[child].valor) > 0)
						|| (!heap_ctx->min
								&& heap_ctx->id78(
										lastElement.valor, heap[child].valor))) {
					heap[now] = heap[child];

					id106(id13,
							heap_ctx->id28(heap[child].valor), now);
					caca_log_debug("llave %d tiene valor %u",
							heap_ctx->id28(heap[child].valor), now);
				} else 
				{
					break;
				}
			}
		}
	}

	id83(id13,
			heap_ctx->id28(minElement.valor));
	caca_log_debug("borrada llave %d",
			heap_ctx->id28( minElement.valor));
	if (heap_size && id22 != heap_size + 1) {
		assert_timeout(now <= heap_size);
		heap[now] = lastElement;
		id106(id13,
				heap_ctx->id28(lastElement.valor), now);
		caca_log_debug("llave %d tiene valor %u ",
				heap_ctx->id28(lastElement.valor), now);
	}
	heap_ctx->heap_size = heap_size;
	

	return resultado;
}

static inline void *id101(heap_shit *heap_ctx,
		tipo_dato llave) {
	natural heap_size = heap_ctx->heap_size;
	hm_rr_bs_tabla *id58 = heap_ctx->tablon_llave_a_idx_heap;
	entero_largo id22;

	assert_timeout(heap_size);

	natural id90 = id33(id58,
			llave, &id22);
	assert_timeout(id22 <= heap_size);
	caca_log_debug("borrando llave %d en idx %u en idx hm %u con heap size %u",
			llave, id22, id90, heap_size);
	assert_timeout(id90!=id64);
	assert_timeout(id22 != HEAP_SHIT_VALOR_INVALIDO);

	return id39(heap_ctx, id22);
}

static inline void *id30(heap_shit *heap_ctx) {
	if (heap_ctx->heap_size) {
		return id101(heap_ctx,
				heap_ctx->id28(heap_ctx->heap[1].valor));
	} else {
		assert_timeout(!heap_ctx->heap[0].valor);
		return NULL;
	}
}

static inline void id16(heap_shit *ctx, void *valor) {
	entero_largo llave = ctx->id28(valor);
	id101(ctx, llave);
	heap_shit_insertar(ctx, valor);
}






typedef struct my_struct {
	void *valor;
	struct my_struct* next;
} listilla_nodo;

typedef struct my_list {
	struct my_struct* head;
	struct my_struct* tail;
	natural elementos_cnt;
} listilla_fifo;

typedef struct listilla_iterador {
	listilla_fifo *ctx;
	listilla_nodo *id66;
	bool primera_llamada;
	natural llamadas;
} listilla_iterador;


struct my_list* id9(struct my_list* s, void *valor) {
	struct my_struct* p = malloc(1 * sizeof(*p));

	if ( NULL == p) {
		fprintf(stderr, "IN %s, %s: malloc() failed\n", __FILE__, "list_add");
		return s;
	}

	p->valor = valor;
	p->next = NULL;

	if ( NULL == s) {
		printf("Queue not initialized\n");
		free(p);
		return s;
	} else if ( NULL == s->head && NULL == s->tail) {
		
		s->head = s->tail = p;
		return s;
	} else if ( NULL == s->head || NULL == s->tail) {
		fprintf(stderr,
				"There is something seriously wrong with your assignment of head/tail to the list\n");
		free(p);
		return NULL;
	} else {
		
		s->tail->next = p;
		s->tail = p;
	}
	s->elementos_cnt++;

	return s;
}


static inline void *id5(struct my_list* s) {
	struct my_struct* h = NULL;
	struct my_struct* p = NULL;
	void *valor = NULL;

	if ( NULL == s) {
		printf("List is empty\n");
		return s;
	} else if ( NULL == s->head && NULL == s->tail) {
		printf("Well, List is empty\n");
		return s;
	} else if ( NULL == s->head || NULL == s->tail) {
		printf("There is something seriously wrong with your list\n");
		printf("One of the head/tail is empty while other is not \n");
		abort();
	}

	h = s->head;
	valor = h->valor;
	p = h->next;
	free(h);
	s->head = p;
	if ( NULL == s->head)
		s->tail = s->head; 

	s->elementos_cnt--;
	return valor;
}


struct my_list* list_free(struct my_list* s) {
	while (s->head) {
		id5(s);
	}

	return s;
}

struct my_list* list_new(void) {
	struct my_list* p = malloc(1 * sizeof(*p));

	assert_timeout(p);

	p->head = p->tail = NULL;

	return p;
}

void id44(const struct my_struct* p) {
	if (p) {
		printf("Num = %p\n", p->valor);
	} else {
		printf("Can not print NULL struct \n");
	}
}

void list_print(const struct my_list* ps) {
	struct my_struct* p = NULL;

	if (ps) {
		for (p = ps->head; p; p = p->next) {
			id44(p);
		}
	}

	printf("------------------\n");
}

static inline bool list_empty(struct my_list *s) {
	return !s->head;
}

static inline void id40(listilla_fifo *ctx,
		listilla_iterador *iter) {
	iter->ctx = ctx;
	iter->id66 = NULL;
	iter->primera_llamada = verdadero;
	iter->llamadas = 0;
}
static inline void id102(listilla_iterador *iter) {
	iter->ctx = NULL;
	iter->id66 = NULL;
}

static inline void *id82(listilla_iterador *iter) {
	return iter->id66 ? iter->id66->valor : NULL;
}
static inline void *id63(listilla_iterador *iter) {
	if (iter->id66) {
		iter->id66 = iter->id66->next;
	} else {
		if (iter->primera_llamada) {
			iter->primera_llamada = falso;
			iter->id66 = iter->ctx->head;
		}
	}
	if (iter->id66) {
		iter->llamadas++;
	}
	return iter->id66 ? iter->id66->valor : NULL;
}






typedef enum submierda_estado_nodo {
	id35 = 0,
	id25,
	id76
} submierda_estado_nodo;

typedef struct submierda_nodo {
	tipo_dato llave;
	tipo_dato valor;

	submierda_estado_nodo color;
	listilla_fifo *vecinos;
	listilla_iterador iter;
	natural vecinos_visitados_cnt;
	natural vecinos_por_visitar_cnt;

	listilla_fifo *previos;
	natural conteo_letras[id52];
	natural vecinos_por_procesar_cnt;
} submierda_nodo;

static inline bool id26(submierda_nodo *nodo) {
	bool caca = falso;
	stackaca *pila = &(stackaca ) { 0 };
	submierda_nodo *id66 = NULL;

	id6(pila);

	id66 = nodo;

	id72(pila, id66);

	while (!id57(pila)) {
		bool id12 = falso;
		id66 = id74(pila);
		if (id66->vecinos_por_visitar_cnt) {
			submierda_nodo *vecino = NULL;
			listilla_fifo *vecinos = id66->vecinos;
			listilla_iterador *iter = &id66->iter;
			id66->color = id25;
			if (!id66->vecinos_visitados_cnt) {
				id40(vecinos, iter);
			}

			assert_timeout(id66->vecinos_visitados_cnt == iter->llamadas);

			vecino = id63(iter);
			id66->vecinos_por_visitar_cnt--;
			id66->vecinos_visitados_cnt++;

			caca_log_debug("en nodo %u vecino %u (color %u)", id66->llave,
					vecino->llave, vecino->color);
			switch (vecino->color) {
			case id35:
				id72(pila, id66);
				id72(pila, vecino);
				break;
			case id25:
				id12 = verdadero;
				break;
			default:
				assert_timeout(vecino->color == id76)
				;
				id72(pila, id66);
				break;
			}

			if (id12) {
				caca = verdadero;
				break;
			}

		} else {
			id66->color = id76;
			caca_log_debug("se consumio %u", id66->llave);
			id102(&id66->iter);
		}
	}

	id97(pila);
	return caca;
}
static inline bool id59(submierda_nodo *nodos,
		natural id88) {
	bool id47 = falso;
	for (int i = 1; i < id88 + 1; i++) {
		submierda_nodo *id66 = nodos + i;
		if (id66->color == id35) {
			caca_log_debug("empezando dfs en %u", id66->llave);
			id47 = id26(id66);
			if (id47) {
				break;
			}
		}
	}
	return id47;
}

int id95(void *pa, void *pb) {
	int res = 0;
	submierda_nodo *a = pa;
	submierda_nodo *b = pb;

	res = a->vecinos_por_procesar_cnt - b->vecinos_por_procesar_cnt;

	return res;
}

entero_largo id31(void *a) {
	return ((submierda_nodo *) a)->llave;
}

static inline tipo_dato id86(submierda_nodo *nodos,
		natural id94) {
	tipo_dato res = 0;
	heap_shit *pq = NULL;
	submierda_nodo *id93 = &(submierda_nodo ) { 0 };

	pq = id41(verdadero, NULL, id95,
			id31);

	id93->vecinos = list_new();

	for (int i = 1; i < id94 + 1; i++) {
		submierda_nodo *id66 = nodos + i;

		id66->conteo_letras[id7(
				id66->valor)] = 1;

		heap_shit_insertar(pq, id66);

		id93->vecinos_por_procesar_cnt++;
		id93->vecinos_por_visitar_cnt =
				id93->vecinos_por_procesar_cnt;

		id9(id93->vecinos, id66);

		id9(id66->previos, id93);

	}

	id93->previos = list_new();
	heap_shit_insertar(pq, id93);

	while (pq->heap_size) {
		submierda_nodo *id66 = id30(pq);
		caca_log_debug("procesando nodo %u", id66->llave);
		listilla_iterador *iter = &(listilla_iterador ) { 0 };
		submierda_nodo *vecino = NULL;
		submierda_nodo *previo = NULL;
		natural id65[id52] = { 0 };

		assert_timeout(!id66->vecinos_por_procesar_cnt);

		id40(id66->vecinos, iter);

		while ((vecino = id63(iter))) {
			for (char c = 'a'; c <= 'z'; c++) {
				natural ci = id7(c);
				if (id65[ci] < vecino->conteo_letras[ci]) {
					id65[ci] = vecino->conteo_letras[ci];
				}
			}
		}

		for (char c = 'a', ci = id7(c); c <= 'z';
				c++, ci++) {
			id66->conteo_letras[ci] += id65[ci];
		}

		id102(iter);

		id40(id66->previos, iter);
		while ((previo = id63(iter))) {
			previo->vecinos_por_procesar_cnt--;
			id16(pq, previo);
		}
		id102(iter);
	}

	id45(pq);

	res = id21(id93->conteo_letras,
	id52);

	return res;
}

static inline int id103(submierda_nodo *nodos, natural id88) {
	int res = 0;
	bool id47 = id59(nodos, id88);

	if (id47) {
		res = -1;
	} else {
		res = id86(nodos, id88);
	}
	return res;
}

submierda_nodo *nodos = NULL;
char cadena[SUBMIERDA_MAX_NODOS + 1] = { '\0' };

static inline void id8() {
	natural id88 = 0;
	natural id61 = 0;

	scanf("%u %u\n", &id88, &id61);
	nodos = calloc(SUBMIERDA_MAX_NODOS + 1, sizeof(submierda_nodo));
	assert(nodos);

	scanf("%s", cadena + 1);

	caca_log_debug("carmen se me perdio la cadenita %s", cadena+1);
	for (int i = 1; i < id88 + 1; i++) {
		submierda_nodo *id66 = nodos + i;
		id66->color = id35;
		id66->llave = i;
		id66->conteo_letras[id7(cadena[i])] =
				1;
		id66->valor = cadena[i];
		id66->vecinos = list_new();
		id66->previos = list_new();
	}

	for (int i = 0; i < id61; i++) {
		natural x = 0;
		natural y = 0;
		submierda_nodo *origen = NULL;
		submierda_nodo *destino = NULL;

		scanf("%u %u\n", &x, &y);

		origen = nodos + x;
		destino = nodos + y;

		origen->vecinos_por_procesar_cnt = ++origen->vecinos_por_visitar_cnt;

		id9(origen->vecinos, destino);
		id9(destino->previos, origen);
	}

	int res = id103(nodos, id88);
	caca_log_debug("cca %d", res);
	printf("%d\n", res);
	free(nodos);
}

int main(void) {
	id8();
	return EXIT_SUCCESS;
}
