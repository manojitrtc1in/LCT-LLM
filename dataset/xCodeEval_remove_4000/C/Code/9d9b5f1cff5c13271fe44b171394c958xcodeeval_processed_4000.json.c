






































typedef unsigned int natural;
typedef int tipo_dato;

typedef long long entero_largo;
typedef unsigned long long entero_largo_sin_signo;
typedef long long bitch_vector;

typedef enum BOOLEANOS {
	falso = 0, verdadero
} bool;




















		do \
		{ \
			size_t id73 = 0; \
			void *array[id52]; \
 			id73 = backtrace(array, id52); \
			id57(formato,__FILE__, __func__, __LINE__,id73,
		} \
		while(0);









void id57(const char *format, ...);


        __asm__ (\
                        "xor %%rdx,%%rdx\n"\
                        "movq %[bitch_posi],%%rax\n" \
                        "movq $64,%%r8\n"\
                        "divq %%r8\n"\
                        "mov $1,%[resul]\n"\
                        "mov %%rdx,%%rcx\n"\
                        "shlq %%cl,%[resul]\n"\
                        "and (%[vectors],%%rax,8),%[resul]\n"\
                        : [resul] "=b" (resultado)\
                        : [bitch_posi] "r" (posicion), [vectors] "r" (bits)\
            :"rax","rdx","rcx","r8")

static inline void id15(bitch_vector *bits,
		unsigned long posicion) {
	int id46 = 0;
	int id6 = 0;

	id46 = posicion / 64;
	id6 = posicion % 64;

	bits[id46] |= (bitch_vector) ((bitch_vector) 1 << id6);

}

static inline void id75(bitch_vector *bits,
		unsigned long posicion) {
	int id46 = 0;
	int id6 = 0;

	id46 = posicion / 64;
	id6 = posicion % 64;

	bits[id46] &= (bitch_vector) ~((bitch_vector) 1 << id6);

}

void id56(struct timespec *ts) {


	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts->tv_sec = mts.tv_sec;
	ts->tv_nsec = mts.tv_nsec;


	clock_gettime(CLOCK_REALTIME, ts);



}

void id53(char *stime) {
	time_t ltime;
	struct tm result;
	long ms;

	struct timespec spec;

	char id65[50];

	ltime = time(NULL );


	localtime_r(&ltime, &result);
	asctime_r(&result, stime);


	*(stime + strlen(stime) - 1) = ' ';


	id56(&spec);
	ms = round(spec.tv_nsec / 1.0e3);

	sprintf(id65, "%ld", ms);
	strcat(stime, id65);
}
void id57(const char *format, ...) {

	va_list arg;
	va_list arg2;
	const char *id3 = "tiempo: %s; ";
	const char *HEADER =
			"archivo: %s; funcion: %s; linea %d; nivel: %zd caca 8====D ";
	char formato[id52 + sizeof(HEADER)
			+ sizeof(id3)] = { '\0' };
	char id21[sizeof(id3) + 100] = { '\0' };
	char cadena_timestamp[100] = { '\0' };

	id53(cadena_timestamp);
	sprintf(id21, id3, cadena_timestamp);

	strcpy(formato, id21);
	strcat(formato, HEADER);
	strcat(formato, format);
	strcat(formato, "\n");

	va_start(arg, format);
	va_copy(arg2, arg);
	vprintf(formato, arg2);
	va_end(arg2);
	va_end(arg);


	setbuf(stdout, NULL );
}


static char *id18(tipo_dato *arreglo, int id67,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id13 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id67; i++) {
		id13 += sprintf(ap_buffer + id13,
				"%u", *(arreglo + i));
		if (i < id67 - 1) {
			*(ap_buffer + id13++) = ',';
		}
	}
	*(ap_buffer + id13) = '\0';
	return ap_buffer;
}

static char *id54(natural *arreglo,
		natural id67, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id13 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id67; i++) {
		id13 += sprintf(ap_buffer + id13, "%2u",
				*(arreglo + i));
		if (i < id67 - 1) {
			*(ap_buffer + id13++) = ',';
		}
	}
	*(ap_buffer + id13) = '\0';
	return ap_buffer;
}

void id14(char s[], char chr, char id72) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == chr) {
			s[i] = id72;
		}
		i++;
	}
}

static inline int id35(tipo_dato *matrix,
		int *id26, int *id30, int id37,
		int id27) {
	int id68 = 0;
	int id24 = 0;
	tipo_dato numero = 0;
	char *id47 = NULL;
	char *id1 = NULL;
	char *linea = NULL;

	linea = calloc(CACA_COMUN_TAM_MAX_LINEA, sizeof(char));

	while (id68 < id37
			&& fgets(linea, CACA_COMUN_TAM_MAX_LINEA, stdin)) {
		id24 = 0;
		id1 = linea;
		id14(linea, '\n', '\0');
		if (!strlen(linea)) {
			caca_log_debug("weird, linea vacia");
			continue;
		}
		for (id47 = linea;; id47 =
				id1) {


			numero = strtol(id47, &id1, 10);
			if (id1 == id47) {
				break;
			}
			*(matrix + id68 * id27 + id24) =
					numero;




			id24++;


		}
		if (id30) {
			id30[id68] = id24;
		}
		id68++;
		caca_log_debug("las filas son %d, con clos %d", id68,
				id24);
	}

	*id26 = id68;
	free(linea);
	return 0;
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
int id7(hm_rr_bs_tabla *ht, int id69) {
	ht->num_buckets_ = id69;
	ht->buckets_ = (hm_cubeta *) calloc(ht->num_buckets_, sizeof(hm_cubeta));
	ht->num_buckets_used_ = 0;
	ht->probing_max_ = id69;
	return 0;
}
int id74(hm_rr_bs_tabla *ht) {
	if (ht->buckets_ != NULL ) {
		for (uint32_t i = 0; i < ht->num_buckets_; i++) {
			if (ht->buckets_[i].entry != NULL ) {
				free(ht->buckets_[i].entry);
				ht->buckets_[i].entry = NULL;
			}
		}
		free(ht->buckets_);
	}
	return 0;
}
static inline int id19(
		hm_rr_bs_tabla *ht, uint64_t id11, uint64_t *distance) {
	hm_cubeta cubeta = ht->buckets_[id11];
	*distance = 0;
	if (cubeta.entry == NULL )
		return -1;
	uint64_t id69 = ht->num_buckets_;
	uint64_t index_init = cubeta.hash % id69;
	if (index_init <= id11) {
		*distance = id11 - index_init;
	} else {
		*distance = id11 + (id69 - index_init);
	}
	return 0;
}
hm_iter id23(hm_rr_bs_tabla *ht,
		const entero_largo key, entero_largo *value) {
	uint64_t id69 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;


	uint64_t hash = key % id69;
	uint64_t index_init = hash;
	uint64_t probe_distance = 0;
	uint64_t index_current;
	bool found = falso;
	uint32_t i;
	*value = id48;
	for (i = 0; i < id69; i++) {
		index_current = (index_init + i) % id69;
		hm_entry *entrada = ht->buckets_[index_current].entry;
		if (entrada == NULL ) {
			break;
		}
		id19(ht,
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
	return id48 ;
}
hm_iter id10(hm_rr_bs_tabla *ht, entero_largo key,
		entero_largo value, bool *nuevo_entry) {
	uint64_t id69 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_min_;
	hm_cubeta *cubetas = ht->buckets_;
	*nuevo_entry = verdadero;
	if (ht->num_buckets_used_ == id69) {
		*nuevo_entry = falso;
		return id48 ;
	}
	ht->num_buckets_used_ += 1;


	uint64_t hash = key % id69;
	uint64_t index_init = hash;
	hm_entry *entry = (hm_entry *) calloc(1, sizeof(hm_entry));
	entry->llave = key;
	entry->valor = value;
	uint64_t index_current = index_init % id69;
	uint64_t probe_current = 0;
	uint64_t probe_distance;
	hm_entry *entry_temp;
	uint64_t hash_temp;
	uint64_t i;
	for (i = 0; i < id69; i++) {
		index_current = (index_init + i) % id69;
		hm_cubeta *cubeta = cubetas + index_current;
		if (cubeta->entry == NULL ) {
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
			id19(ht,
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
int id60(hm_rr_bs_tabla *ht,
		const tipo_dato key) {
	uint64_t id69 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_max_;
	uint64_t hash = key % id69;
	uint64_t index_init = hash;
	bool found = falso;
	uint64_t index_current = 0;
	uint64_t probe_distance = 0;
	hm_entry *entrada = NULL;
	for (uint64_t i = 0; i < id69; i++) {
		index_current = (index_init + i) % id69;
		entrada = ht->buckets_[index_current].entry;
		id19(ht,
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
		for (i = 1; i < id69; i++) {
			index_previous = (index_current + i - 1) % id69;
			index_swap = (index_current + i) % id69;
			hm_cubeta *id36 = ht->buckets_ + index_swap;
			hm_cubeta *id17 = ht->buckets_ + index_previous;
			if (id36->entry == NULL ) {
				id17->entry = NULL;
				break;
			}
			uint64_t distance;
			if (id19(
					ht, index_swap, &distance) != 0) {
				fprintf(stderr, "Error in FillDistanceToInitIndex()");
			}
			if (!distance) {
				id17->entry = NULL;
				break;
			}
			id17->entry = id36->entry;
			id17->hash = id36->hash;
		}
		if (i < id69) {
			if (index_previous == prob_min) {
				prob_min++;
				if (prob_min >= id69) {
					prob_min = 0;
				} else {
					while (prob_min < id69
							&& ht->buckets_[prob_min].entry) {
						prob_min++;
					}
					if (prob_min >= id69) {
						prob_min = id69;
					}
				}
				ht->probing_min_ = prob_min;
			}
			if (index_previous == prob_max) {
				prob_max--;
				if (prob_max >= id69) {
					prob_max = id69;
				} else {
					while (((int64_t) prob_max) >= 0
							&& ht->buckets_[prob_max].entry) {
						prob_max--;
					}
					if (prob_max >= id69) {
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
static inline int id59(
		hm_rr_bs_tabla *ht) {
	return ht->probing_min_;
}
static inline int id38(
		hm_rr_bs_tabla *ht) {
	return ht->probing_max_;
}
static inline bool id32(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	return !!ht->buckets_[indice].entry;
}
static inline entero_largo id70(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	return entrada->llave;
}
static inline void id63(
		hm_rr_bs_tabla *ht, hm_iter indice, entero_largo valor) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	entrada->valor = valor;
}
int id31(hm_rr_bs_tabla *ht,
		hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	uint64_t id69 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_max_;
	uint64_t index_current = indice;
	hm_entry *entrada = ht->buckets_[index_current].entry;
	assert_timeout(entrada);
	free(entrada);
	uint64_t i = 1;
	uint64_t index_previous = 0, index_swap = 0;
	for (i = 1; i < id69; i++) {
		index_previous = (index_current + i - 1) % id69;
		index_swap = (index_current + i) % id69;
		hm_cubeta *id36 = ht->buckets_ + index_swap;
		hm_cubeta *id17 = ht->buckets_ + index_previous;
		if (id36->entry == NULL ) {
			id17->entry = NULL;
			break;
		}
		uint64_t distance;
		if (id19(ht,
				index_swap, &distance) != 0) {
			fprintf(stderr, "Error in FillDistanceToInitIndex()");
		}
		if (!distance) {
			id17->entry = NULL;
			break;
		}
		id17->entry = id36->entry;
		id17->hash = id36->hash;
	}
	if (i < id69) {
		if (index_previous == prob_min) {
			prob_min++;
			if (prob_min >= id69) {
				prob_min = 0;
			} else {
				while (prob_min < id69 && ht->buckets_[prob_min].entry) {
					prob_min++;
				}
				if (prob_min >= id69) {
					prob_min = id69;
				}
			}
			ht->probing_min_ = prob_min;
		}
		if (index_previous == prob_max) {
			prob_max--;
			if (prob_max >= id69) {
				prob_max = id69;
			} else {
				while (((int64_t) prob_max) >= 0 && ht->buckets_[prob_max].entry) {
					prob_max--;
				}
				if (prob_max >= id69) {
					prob_max = 0;
				}
			}
			ht->probing_max_ = prob_max;
		}
	}
	ht->num_buckets_used_--;
	return 0;
}
static inline entero_largo id61(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	return entrada->valor;
}
static inline bool id34(hm_rr_bs_tabla *ht) {
	assert_timeout(ht->num_buckets_used_ <= ht->num_buckets_);
	return !ht->num_buckets_used_;
}


void id0(tipo_dato numero);
void id2(tipo_dato numero);


typedef enum mo_mada_tipo_query {
	mo_mada_actualizacion = 'U', mo_mada_consulta = 0
} mo_mada_tipo_query;

typedef struct mo_mada {
	mo_mada_tipo_query tipo;
	natural idx_query;
	natural intervalo_idx_ini;
	natural intervalo_idx_fin;
	natural orden;
	entero_largo resulcaca;
} mo_mada;

natural id33 = 0;
entero_largo id12 = 0;

int id42(const void *pa, const void *pb) {
	int res = 0;
	mo_mada *a = (mo_mada *) pa;
	mo_mada *b = (mo_mada *) pb;
	natural id43 = a->intervalo_idx_ini / id33;
	natural id39 = b->intervalo_idx_ini / id33;
	natural id5 = a->intervalo_idx_fin;
	natural id66 = b->intervalo_idx_fin;
	natural id49 = a->intervalo_idx_ini;
	natural id64 = b->intervalo_idx_ini;

	if (id43 != id39) {
		res = id43 - id39;
	} else {
		if (id5 != id66) {
			res = id5 - id66;
		} else {
			if (id49 != id64) {
				res = id49 - id64;
			} else {
				res = a->orden - b->orden;
			}
		}
	}

	return res;
}

int id25(const void *pa, const void *pb) {
	int res = 0;
	mo_mada *a = (mo_mada *) pa;
	mo_mada *b = (mo_mada *) pb;

	res = a->idx_query - b->idx_query;
	return res;
}






static inline mo_mada *id8(mo_mada *consultas, tipo_dato *numeros,
		natural id41, natural id71) {
	natural id28 = 0;
	natural id9 = 0;
	id33 = ceil(sqrt(id71));
	caca_log_debug("total de nums %u, tam bloq %u\n", id71,
			id33);

	qsort(consultas, id41, sizeof(mo_mada), mo_mada_fn_ord_mo);

	id28 = id9 = (consultas)->intervalo_idx_ini;

	caca_log_debug("anadiendo inicialmente %u\n", numeros[id28]);
	mo_mada_fn_anade_caca((numeros[id28]));

	caca_log_debug("puta mierda %lld\n", id12);

	for (int i = 0; i < id41; i++) {
		natural id40 = (consultas + i)->intervalo_idx_ini;
		natural id50 = (consultas + i)->intervalo_idx_fin;

		if ((consultas + i)->tipo == mo_mada_actualizacion) {
			continue;
		}


		assert_timeout(
				ceil(abs((int )id28 - (int )id40))
				<= id33 * 2);


		caca_log_debug("vamos a bailar %u-%u\n", id40, id50);

		caca_log_debug("disminu izq act %u a izq consul %u\n", id28,
				id40);
		while (id28 > id40) {
			id28--;
			mo_mada_fn_anade_caca(numeros[id28]);
			caca_log_debug("puta mierda %lld\n", id12);
		}

		caca_log_debug("aumen der act %u a der consul %u\n", id9,
				id50);
		while (id9 < id50) {
			id9++;
			mo_mada_fn_anade_caca(numeros[id9]);
			caca_log_debug("puta mierda %lld\n", id12);
		}

		caca_log_debug("aumen izq act %u a izq consul %u\n", id28,
				id40);
		while (id28 < id40) {
			mo_mada_fn_quita_caca(numeros[id28]);
			id28++;
		}

		caca_log_debug("disminu der act %u a der consul %u\n", id9,
				id50);
		while (id9 > id50) {
			mo_mada_fn_quita_caca(numeros[id9]);
			id9--;
		}

		caca_log_debug("el conteo uniq de la consul %u es %lld\n", i,
				id12);
		(consultas + i)->resulcaca = id12;
	}

	qsort(consultas, id41, sizeof(mo_mada), mo_mada_fn_ord_idx);
	return consultas;
}







hm_rr_bs_tabla *tablon = &(hm_rr_bs_tabla ) { 0 };
mo_mada consultas[id51] = { 0 };
tipo_dato numeros[CACA_PODEROSA_MAX_NUMS + 2] = { 0 };
natural id58 = 0;
natural id55 = 0;
natural id4[id51][2] = { 0 };
natural id29[CACA_PODEROSA_MAX_NUM + 2] = { 0 };

void id2(tipo_dato numero) {
	entero_largo_sin_signo id62 = 0;
	id62 = id29[numero];

	id12 += ((id62 << 1) + 1) * numero;
	id29[numero] = id62 + 1;
}

void id0(tipo_dato numero) {
	entero_largo_sin_signo id62 = 0;
	id62 = id29[numero];

	id12 += (1 - (id62 << 1)) * numero;
	id29[numero] = id62 - 1;
}

static inline void id16() {
	id7(tablon, CACA_PODEROSA_MAX_NUMS << 1);
	for (int i = 1; i <= id55; i++) {
		bool id20 = falso;
		id10(tablon, numeros[i], 0,
				&id20);
	}
	id8(consultas, numeros, id58, id55);
	for (int i = 0; i < id58; i++) {
		mo_mada *id44 = (consultas + i);
		printf("%lld\n", id44->resulcaca);
	}
}

static inline void id22() {
	scanf("%u %u\n", &id55, &id58);
	caca_log_debug("num nums %u num consuls %u", id55, id58);
	id35((tipo_dato *) numeros + 1, &(int ) { 0 },
			NULL, 1, id55);
	id35((tipo_dato *) id4,
			&(int ) { 0 }, NULL, id58, 2);
	for (int i = 0; i < id58; i++) {
		natural *id45 = id4[i];
		mo_mada *id44 = (consultas + i);
		id44->orden = id44->idx_query = i;
		id44->intervalo_idx_ini = id45[0];
		id44->intervalo_idx_fin = id45[1];
		caca_log_debug("se q t %u: %u-%u", i, id44->intervalo_idx_ini,
				id44->intervalo_idx_fin);
	}
	id16();
}

int main(void) {
	id22();
	return EXIT_SUCCESS;
}
