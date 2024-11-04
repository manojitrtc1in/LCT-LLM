






































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
			size_t id70 = 0; \
			void *array[id50]; \
 			id70 = backtrace(array, id50); \
			id55(formato,__FILE__, __func__, __LINE__,id70,
		} \
		while(0);









void id55(const char *format, ...);


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

static inline void id13(bitch_vector *bits,
		unsigned long posicion) {
	int id44 = 0;
	int id4 = 0;

	id44 = posicion / 64;
	id4 = posicion % 64;

	bits[id44] |= (bitch_vector) ((bitch_vector) 1 << id4);

}

static inline void id72(bitch_vector *bits,
		unsigned long posicion) {
	int id44 = 0;
	int id4 = 0;

	id44 = posicion / 64;
	id4 = posicion % 64;

	bits[id44] &= (bitch_vector) ~((bitch_vector) 1 << id4);

}

void id54(struct timespec *ts) {


	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts->tv_sec = mts.tv_sec;
	ts->tv_nsec = mts.tv_nsec;


	clock_gettime(CLOCK_REALTIME, ts);



}

void id51(char *stime) {
	time_t ltime;
	struct tm result;
	long ms;

	struct timespec spec;

	char id62[50];

	ltime = time(NULL );


	localtime_r(&ltime, &result);
	asctime_r(&result, stime);


	*(stime + strlen(stime) - 1) = ' ';


	id54(&spec);
	ms = round(spec.tv_nsec / 1.0e3);

	sprintf(id62, "%ld", ms);
	strcat(stime, id62);
}
void id55(const char *format, ...) {

	va_list arg;
	va_list arg2;
	const char *id1 = "tiempo: %s; ";
	const char *HEADER =
			"archivo: %s; funcion: %s; linea %d; nivel: %zd caca 8====D ";
	char formato[id50 + sizeof(HEADER)
			+ sizeof(id1)] = { '\0' };
	char id19[sizeof(id1) + 100] = { '\0' };
	char cadena_timestamp[100] = { '\0' };

	id51(cadena_timestamp);
	sprintf(id19, id1, cadena_timestamp);

	strcpy(formato, id19);
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


static char *id16(tipo_dato *arreglo, int id64,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id11 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id64; i++) {
		id11 += sprintf(ap_buffer + id11,
				"%u", *(arreglo + i));
		if (i < id64 - 1) {
			*(ap_buffer + id11++) = ',';
		}
	}
	*(ap_buffer + id11) = '\0';
	return ap_buffer;
}

static char *id52(natural *arreglo,
		natural id64, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id11 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id64; i++) {
		id11 += sprintf(ap_buffer + id11, "%2u",
				*(arreglo + i));
		if (i < id64 - 1) {
			*(ap_buffer + id11++) = ',';
		}
	}
	*(ap_buffer + id11) = '\0';
	return ap_buffer;
}

void id12(char s[], char chr, char id69) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == chr) {
			s[i] = id69;
		}
		i++;
	}
}

static inline int id33(tipo_dato *matrix,
		int *id24, int *id28, int id35,
		int id25) {
	int id65 = 0;
	int id22 = 0;
	tipo_dato numero = 0;
	char *id45 = NULL;
	char *id0 = NULL;
	char *linea = NULL;

	linea = calloc(CACA_COMUN_TAM_MAX_LINEA, sizeof(char));

	while (id65 < id35
			&& fgets(linea, CACA_COMUN_TAM_MAX_LINEA, stdin)) {
		id22 = 0;
		id0 = linea;
		id12(linea, '\n', '\0');
		if (!strlen(linea)) {
			caca_log_debug("weird, linea vacia");
			continue;
		}
		for (id45 = linea;; id45 =
				id0) {


			numero = strtol(id45, &id0, 10);
			if (id0 == id45) {
				break;
			}
			*(matrix + id65 * id25 + id22) =
					numero;




			id22++;


		}
		if (id28) {
			id28[id65] = id22;
		}
		id65++;
		caca_log_debug("las filas son %d, con clos %d", id65,
				id22);
	}

	*id24 = id65;
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
int id5(hm_rr_bs_tabla *ht, int id66) {
	ht->num_buckets_ = id66;
	ht->buckets_ = (hm_cubeta *) calloc(ht->num_buckets_, sizeof(hm_cubeta));
	ht->num_buckets_used_ = 0;
	ht->probing_max_ = id66;
	return 0;
}
int id71(hm_rr_bs_tabla *ht) {
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
static inline int id17(
		hm_rr_bs_tabla *ht, uint64_t id9, uint64_t *distance) {
	hm_cubeta cubeta = ht->buckets_[id9];
	*distance = 0;
	if (cubeta.entry == NULL )
		return -1;
	uint64_t id66 = ht->num_buckets_;
	uint64_t index_init = cubeta.hash % id66;
	if (index_init <= id9) {
		*distance = id9 - index_init;
	} else {
		*distance = id9 + (id66 - index_init);
	}
	return 0;
}
hm_iter id21(hm_rr_bs_tabla *ht,
		const entero_largo key, entero_largo *value) {
	uint64_t id66 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;


	uint64_t hash = key % id66;
	uint64_t index_init = hash;
	uint64_t probe_distance = 0;
	uint64_t index_current;
	bool found = falso;
	uint32_t i;
	*value = id46;
	for (i = 0; i < id66; i++) {
		index_current = (index_init + i) % id66;
		hm_entry *entrada = ht->buckets_[index_current].entry;
		if (entrada == NULL ) {
			break;
		}
		id17(ht,
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
	return id46 ;
}
hm_iter id8(hm_rr_bs_tabla *ht, entero_largo key,
		entero_largo value, bool *nuevo_entry) {
	uint64_t id66 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_min_;
	hm_cubeta *cubetas = ht->buckets_;
	*nuevo_entry = verdadero;
	if (ht->num_buckets_used_ == id66) {
		*nuevo_entry = falso;
		return id46 ;
	}
	ht->num_buckets_used_ += 1;


	uint64_t hash = key % id66;
	uint64_t index_init = hash;
	hm_entry *entry = (hm_entry *) calloc(1, sizeof(hm_entry));
	entry->llave = key;
	entry->valor = value;
	uint64_t index_current = index_init % id66;
	uint64_t probe_current = 0;
	uint64_t probe_distance;
	hm_entry *entry_temp;
	uint64_t hash_temp;
	uint64_t i;
	for (i = 0; i < id66; i++) {
		index_current = (index_init + i) % id66;
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
			id17(ht,
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
int id58(hm_rr_bs_tabla *ht,
		const tipo_dato key) {
	uint64_t id66 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_max_;
	uint64_t hash = key % id66;
	uint64_t index_init = hash;
	bool found = falso;
	uint64_t index_current = 0;
	uint64_t probe_distance = 0;
	hm_entry *entrada = NULL;
	for (uint64_t i = 0; i < id66; i++) {
		index_current = (index_init + i) % id66;
		entrada = ht->buckets_[index_current].entry;
		id17(ht,
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
		for (i = 1; i < id66; i++) {
			index_previous = (index_current + i - 1) % id66;
			index_swap = (index_current + i) % id66;
			hm_cubeta *id34 = ht->buckets_ + index_swap;
			hm_cubeta *id15 = ht->buckets_ + index_previous;
			if (id34->entry == NULL ) {
				id15->entry = NULL;
				break;
			}
			uint64_t distance;
			if (id17(
					ht, index_swap, &distance) != 0) {
				fprintf(stderr, "Error in FillDistanceToInitIndex()");
			}
			if (!distance) {
				id15->entry = NULL;
				break;
			}
			id15->entry = id34->entry;
			id15->hash = id34->hash;
		}
		if (i < id66) {
			if (index_previous == prob_min) {
				prob_min++;
				if (prob_min >= id66) {
					prob_min = 0;
				} else {
					while (prob_min < id66
							&& ht->buckets_[prob_min].entry) {
						prob_min++;
					}
					if (prob_min >= id66) {
						prob_min = id66;
					}
				}
				ht->probing_min_ = prob_min;
			}
			if (index_previous == prob_max) {
				prob_max--;
				if (prob_max >= id66) {
					prob_max = id66;
				} else {
					while (((int64_t) prob_max) >= 0
							&& ht->buckets_[prob_max].entry) {
						prob_max--;
					}
					if (prob_max >= id66) {
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
static inline int id57(
		hm_rr_bs_tabla *ht) {
	return ht->probing_min_;
}
static inline int id36(
		hm_rr_bs_tabla *ht) {
	return ht->probing_max_;
}
static inline bool id30(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	return !!ht->buckets_[indice].entry;
}
static inline entero_largo id67(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	return entrada->llave;
}
static inline void id60(
		hm_rr_bs_tabla *ht, hm_iter indice, entero_largo valor) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	entrada->valor = valor;
}
int id29(hm_rr_bs_tabla *ht,
		hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	uint64_t id66 = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_max_;
	uint64_t index_current = indice;
	hm_entry *entrada = ht->buckets_[index_current].entry;
	assert_timeout(entrada);
	free(entrada);
	uint64_t i = 1;
	uint64_t index_previous = 0, index_swap = 0;
	for (i = 1; i < id66; i++) {
		index_previous = (index_current + i - 1) % id66;
		index_swap = (index_current + i) % id66;
		hm_cubeta *id34 = ht->buckets_ + index_swap;
		hm_cubeta *id15 = ht->buckets_ + index_previous;
		if (id34->entry == NULL ) {
			id15->entry = NULL;
			break;
		}
		uint64_t distance;
		if (id17(ht,
				index_swap, &distance) != 0) {
			fprintf(stderr, "Error in FillDistanceToInitIndex()");
		}
		if (!distance) {
			id15->entry = NULL;
			break;
		}
		id15->entry = id34->entry;
		id15->hash = id34->hash;
	}
	if (i < id66) {
		if (index_previous == prob_min) {
			prob_min++;
			if (prob_min >= id66) {
				prob_min = 0;
			} else {
				while (prob_min < id66 && ht->buckets_[prob_min].entry) {
					prob_min++;
				}
				if (prob_min >= id66) {
					prob_min = id66;
				}
			}
			ht->probing_min_ = prob_min;
		}
		if (index_previous == prob_max) {
			prob_max--;
			if (prob_max >= id66) {
				prob_max = id66;
			} else {
				while (((int64_t) prob_max) >= 0 && ht->buckets_[prob_max].entry) {
					prob_max--;
				}
				if (prob_max >= id66) {
					prob_max = 0;
				}
			}
			ht->probing_max_ = prob_max;
		}
	}
	ht->num_buckets_used_--;
	return 0;
}
static inline entero_largo id59(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	return entrada->valor;
}
static inline bool id32(hm_rr_bs_tabla *ht) {
	assert_timeout(ht->num_buckets_used_ <= ht->num_buckets_);
	return !ht->num_buckets_used_;
}



natural id26[CACA_PODEROSA_MAX_NUM + 2] = { 0 };


        __asm__ (\
                        "mov (%[ocurr],%[num],4),%%eax\n"\
                        "mov $2,%%edx\n"\
                        "mul %%edx\n"\
                        "sub $1,%%eax\n"\
                        "mov $-1,%%edx\n"\
                        "imul %%edx\n"\
                        "imul %[num]\n"\
                        "lea %[resu_low],%%esi\n"\
                        "add %%eax,%[resu_low]\n"\
                        "adc %%edx,4(%%esi)\n"\
                        "subl $1,(%[ocurr],%[num],4)\n"\
:[resu_low] "=m" (id10)\
: [num] "r" (numero), [ocurr] "r" (id26)\
            :"eax","edx","esi")


        __asm__ (\
                        "mov (%[ocurr],%[num],4),%%eax\n"\
                        "mov $2,%%edx\n"\
                        "mul %%edx\n"\
                        "add $1,%%eax\n"\
                        "mul %[num]\n"\
                        "lea %[resu_low],%%esi\n"\
                        "add %%eax,%[resu_low]\n"\
                        "adc %%edx,4(%%esi)\n"\
                        "addl $1,(%[ocurr],%[num],4)\n"\
:[resu_low] "=m" (id10)\
: [num] "r" (numero), [ocurr] "r" (id26)\
            :"eax","edx","esi")



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


natural id31 = 0;
entero_largo id10 = 0;

int id40(const void *pa, const void *pb) {
	int res = 0;
	mo_mada *a = (mo_mada *) pa;
	mo_mada *b = (mo_mada *) pb;
	natural id41 = a->intervalo_idx_ini / id31;
	natural id37 = b->intervalo_idx_ini / id31;
	natural id3 = a->intervalo_idx_fin;
	natural id63 = b->intervalo_idx_fin;
	natural id47 = a->intervalo_idx_ini;
	natural id61 = b->intervalo_idx_ini;

	if (id41 != id37) {
		res = id41 - id37;
	} else {
		if (id3 != id63) {
			res = id3 - id63;
		} else {
			if (id47 != id61) {
				res = id47 - id61;
			} else {
				res = a->orden - b->orden;
			}
		}
	}

	return res;
}

int id23(const void *pa, const void *pb) {
	int res = 0;
	mo_mada *a = (mo_mada *) pa;
	mo_mada *b = (mo_mada *) pb;

	res = a->idx_query - b->idx_query;
	return res;
}






static inline mo_mada *id6(mo_mada *consultas, tipo_dato *numeros,
		natural id39, natural id68) {
	natural id27 = 0;
	natural id7 = 0;
	id31 = ceil(sqrt(id68));
	caca_log_debug("total de nums %u, tam bloq %u\n", id68,
			id31);

	qsort(consultas, id39, sizeof(mo_mada), mo_mada_fn_ord_mo);

	id27 = id7 = (consultas)->intervalo_idx_ini;

	caca_log_debug("anadiendo inicialmente %u\n", numeros[id27]);
	mo_mada_fn_anade_caca((numeros[id27]));

	caca_log_debug("puta mierda %lld\n", id10);

	for (int i = 0; i < id39; i++) {
		natural id38 = (consultas + i)->intervalo_idx_ini;
		natural id48 = (consultas + i)->intervalo_idx_fin;

		if ((consultas + i)->tipo == mo_mada_actualizacion) {
			continue;
		}


		assert_timeout(
				ceil(abs((int )id27 - (int )id38))
				<= id31 * 2);


		caca_log_debug("vamos a bailar %u-%u\n", id38, id48);

		caca_log_debug("disminu izq act %u a izq consul %u\n", id27,
				id38);
		while (id27 > id38) {
			id27--;
			mo_mada_fn_anade_caca(numeros[id27]);
			caca_log_debug("puta mierda %lld\n", id10);
		}

		caca_log_debug("aumen der act %u a der consul %u\n", id7,
				id48);
		while (id7 < id48) {
			id7++;
			mo_mada_fn_anade_caca(numeros[id7]);
			caca_log_debug("puta mierda %lld\n", id10);
		}

		caca_log_debug("aumen izq act %u a izq consul %u\n", id27,
				id38);
		while (id27 < id38) {
			mo_mada_fn_quita_caca(numeros[id27]);
			caca_log_debug("perron %lld\n", id10);
			id27++;
		}

		caca_log_debug("disminu der act %u a der consul %u\n", id7,
				id48);
		while (id7 > id48) {
			mo_mada_fn_quita_caca(numeros[id7]);
			caca_log_debug("perron1 %lld\n", id10);
			id7--;
		}

		caca_log_debug("el conteo uniq de la consul %u es %lld\n", i,
				id10);
		(consultas + i)->resulcaca = id10;
	}

	qsort(consultas, id39, sizeof(mo_mada), mo_mada_fn_ord_idx);
	return consultas;
}






hm_rr_bs_tabla *tablon = &(hm_rr_bs_tabla ) { 0 };
mo_mada consultas[id49] = { 0 };
tipo_dato numeros[CACA_PODEROSA_MAX_NUMS + 2] = { 0 };
natural id56 = 0;
natural id53 = 0;
natural id2[id49][2] = { 0 };

static inline void id14() {
	id5(tablon, CACA_PODEROSA_MAX_NUMS << 1);
	for (int i = 1; i <= id53; i++) {
		bool id18 = falso;
		id8(tablon, numeros[i], 0,
				&id18);
	}
	id6(consultas, numeros, id56, id53);
	for (int i = 0; i < id56; i++) {
		mo_mada *id42 = (consultas + i);
		printf("%lld\n", id42->resulcaca);
	}
}

static inline void id20() {
	scanf("%u %u\n", &id53, &id56);
	caca_log_debug("num nums %u num consuls %u", id53, id56);
	id33((tipo_dato *) numeros + 1, &(int ) { 0 },
			NULL, 1, id53);
	id33((tipo_dato *) id2,
			&(int ) { 0 }, NULL, id56, 2);
	for (int i = 0; i < id56; i++) {
		natural *id43 = id2[i];
		mo_mada *id42 = (consultas + i);
		id42->orden = id42->idx_query = i;
		id42->intervalo_idx_ini = id43[0];
		id42->intervalo_idx_fin = id43[1];
		caca_log_debug("se q t %u: %u-%u", i, id42->intervalo_idx_ini,
				id42->intervalo_idx_fin);
	}
	id14();
}

int main(void) {
	id20();
	return EXIT_SUCCESS;
}
