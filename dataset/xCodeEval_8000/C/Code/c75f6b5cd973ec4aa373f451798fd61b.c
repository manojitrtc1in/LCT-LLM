



#if 1
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include <stdint.h>

#ifdef CACA_COMUN_LOG
#include <execinfo.h>
#endif

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#else
#include <time.h>
#include <stdarg.h>
#endif

#if 1
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LONG_MAX
#endif

#define CACA_COMUN_TAM_MAX_LINEA (16*200000)
#define CACA_LOG_MAX_TAM_CADENA 2000

#define CACA_COMUN_BUF_STATICO (char[1000] ) { '\0' }

#define BITCH_VECTOR_NUM_BITS (sizeof(bitch_vector) * 8)

#define CACA_COMUN_ASSERT_DUROTE 0
#define CACA_COMUN_ASSERT_SUAVECITO 1
#define CACA_COMUN_ASSERT_NIMADRES 2

#define CACA_COMUN_VALOR_INVALIDO ((tipo_dato)UINT_MAX)
#define CACA_COMUN_IDX_INVALIDO ((natural)CACA_COMUN_VALOR_INVALIDO)

typedef unsigned int natural;
typedef natural tipo_dato;
typedef long long entero_largo;
typedef unsigned long long entero_largo_sin_signo;
typedef long long bitch_vector;
typedef char byteme;

typedef enum BOOLEANOS {
	falso = 0, verdadero
} bool;


#define CACA_COMUN_TIPO_ASSERT CACA_COMUN_ASSERT_DUROTE

#define assert_timeout_dummy(condition) 0;

#if CACA_COMUN_TIPO_ASSERT == CACA_COMUN_ASSERT_DUROTE
#define assert_timeout(condition) assert(condition);
#endif
#if CACA_COMUN_TIPO_ASSERT == CACA_COMUN_ASSERT_SUAVECITO
#define assert_timeout(condition) if(!(condition)){while(1){printf("");};abort();}
#endif
#if CACA_COMUN_TIPO_ASSERT == CACA_COMUN_ASSERT_NIMADRES
#define assert_timeout(condition) 0
#endif

#ifdef CACA_COMUN_LOG
#define caca_log_debug(formato, args...) \
		do \
		{ \
			size_t profundidad = 0; \
			void *array[CACA_LOG_MAX_TAM_CADENA]; \
 			profundidad = backtrace(array, CACA_LOG_MAX_TAM_CADENA); \
			caca_log_debug_func(formato,__FILE__, __func__, __LINE__,profundidad,##args); \
		} \
		while(0);
#else
#define caca_log_debug(formato, args...) 0;
#endif

#define caca_comun_max(x,y) ((x) < (y) ? (y) : (x))
#define caca_comun_min(x,y) ((x) < (y) ? (x) : (y))

void caca_log_debug_func(const char *format, ...);

void caca_comun_current_utc_time(struct timespec *ts) {

#ifdef __MACH__
	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts->tv_sec = mts.tv_sec;
	ts->tv_nsec = mts.tv_nsec;
#else
#ifdef CACA_COMUN_LOG
	clock_gettime(CLOCK_REALTIME, ts);
#endif
#endif

}

void caca_comun_timestamp(char *stime) {
	time_t ltime;
	struct tm result;
	long ms;
#ifndef ONLINE_JUDGE
	struct timespec spec;
#endif
	char parte_milisecundos[50];

	ltime = time(NULL);

#ifndef ONLINE_JUDGE
	localtime_r(&ltime, &result);
	asctime_r(&result, stime);
#endif

	*(stime + strlen(stime) - 1) = ' ';

#ifndef ONLINE_JUDGE
	caca_comun_current_utc_time(&spec);
	ms = round(spec.tv_nsec / 1.0e3);
#endif
	sprintf(parte_milisecundos, "%ld", ms);
	strcat(stime, parte_milisecundos);
}
#ifdef CACA_COMUN_LOG
void caca_log_debug_func(const char *format, ...) {

	va_list arg;
	va_list arg2;
	const char *PEDAZO_TIMESTAMP_HEADER = "tiempo: %s; ";
	const char *HEADER =
	"archivo: %s; funcion: %s; linea %d; nivel: %zd caca 8====D ";
	char formato[CACA_LOG_MAX_TAM_CADENA + sizeof(HEADER)
	+ sizeof(PEDAZO_TIMESTAMP_HEADER)] = {'\0'};
	char pedazo_timestamp[sizeof(PEDAZO_TIMESTAMP_HEADER) + 100] = {'\0'};
	char cadena_timestamp[100] = {'\0'};

	caca_comun_timestamp(cadena_timestamp);
	sprintf(pedazo_timestamp, PEDAZO_TIMESTAMP_HEADER, cadena_timestamp);

	strcpy(formato, pedazo_timestamp);
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
#endif

#ifdef CACA_COMUN_LOG
static char *caca_comun_arreglo_a_cadena(tipo_dato *arreglo, int tam_arreglo,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int characteres_escritos = 0;
#ifdef ONLINE_JUDGE
	return NULL;
#endif

	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < tam_arreglo; i++) {
		characteres_escritos += sprintf(ap_buffer + characteres_escritos,
				"%12d", *(arreglo + i));
		if (i < tam_arreglo - 1) {
			*(ap_buffer + characteres_escritos++) = ',';
		}
	}
	*(ap_buffer + characteres_escritos) = '\0';
	return ap_buffer;
}

static char *caca_comun_arreglo_a_cadena_natural(natural *arreglo,
		natural tam_arreglo, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int characteres_escritos = 0;
#ifdef ONLINE_JUDGE
	return NULL;
#endif

	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < tam_arreglo; i++) {
		characteres_escritos += sprintf(ap_buffer + characteres_escritos, "%2u",
				*(arreglo + i));
		if (i < tam_arreglo - 1) {
			*(ap_buffer + characteres_escritos++) = ',';
		}
	}
	*(ap_buffer + characteres_escritos) = '\0';
	return ap_buffer;
}
char *caca_comun_matrix_a_cadena(tipo_dato *matrix, natural filas_tam,
		natural columas_tam, char *buffer) {
	int i, j;
	natural inicio_buffer_act = 0;
	for (int i = 0; i < filas_tam; i++) {
		caca_comun_arreglo_a_cadena(matrix + i * columas_tam, columas_tam,
				buffer + inicio_buffer_act);
		inicio_buffer_act += strlen(buffer + inicio_buffer_act);
		buffer[inicio_buffer_act++] = '\n';
		
	}
	return buffer;
}

static char *caca_comun_arreglo_a_cadena_entero_largo_sin_signo(entero_largo_sin_signo *arreglo,
		entero_largo_sin_signo tam_arreglo, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int characteres_escritos = 0;
#ifdef ONLINE_JUDGE
	return NULL;
#endif

	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < tam_arreglo; i++) {
		characteres_escritos += sprintf(ap_buffer + characteres_escritos, "%2llu",
				*(arreglo + i));
		if (i < tam_arreglo - 1) {
			*(ap_buffer + characteres_escritos++) = ',';
		}
	}
	*(ap_buffer + characteres_escritos) = '\0';
	return ap_buffer;
}
#else
static char *caca_comun_arreglo_a_cadena(tipo_dato *arreglo, int tam_arreglo,
		char *buffer) {
	return NULL;
}
static char *caca_comun_arreglo_a_cadena_natural(natural *arreglo,
		natural tam_arreglo, char *buffer) {
	return NULL;
}
char *caca_comun_matrix_a_cadena(tipo_dato *matrix, natural filas_tam,
		natural columas_tam, char *buffer) {
	return NULL;
}

static char *caca_comun_arreglo_a_cadena_entero_largo_sin_signo(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo tam_arreglo,
		char *buffer) {
	return NULL;
}
#endif
void caca_comun_strreplace(char s[], char chr, char repl_chr) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == chr) {
			s[i] = repl_chr;
		}
		i++;
	}
}

static int caca_comun_lee_matrix_long_stdin(tipo_dato *matrix, int *num_filas,
		int *num_columnas, int num_max_filas, int num_max_columnas) {
	int indice_filas = 0;
	int indice_columnas = 0;
	tipo_dato numero = 0;
	char *siguiente_cadena_numero = NULL;
	char *cadena_numero_actual = NULL;
	char *linea = NULL;

	linea = calloc(CACA_COMUN_TAM_MAX_LINEA, sizeof(char));

	while (indice_filas < num_max_filas
			&& fgets(linea, CACA_COMUN_TAM_MAX_LINEA, stdin)) {
		indice_columnas = 0;
		cadena_numero_actual = linea;
		caca_comun_strreplace(linea, '\n', '\0');
		if (!strlen(linea)) {
			caca_log_debug("weird, linea vacia");
			continue;
		}
		for (siguiente_cadena_numero = linea;; siguiente_cadena_numero =
				cadena_numero_actual) {
			numero = strtol(siguiente_cadena_numero, &cadena_numero_actual, 10);
			if (cadena_numero_actual == siguiente_cadena_numero) {
				break;
			}
			*(matrix + indice_filas * num_max_columnas + indice_columnas) =
					numero;
			indice_columnas++;
		}
		if (num_columnas) {
			num_columnas[indice_filas] = indice_columnas;
		}
		indice_filas++;
		caca_log_debug("las filas son %d, con clos %d", indice_filas,
				indice_columnas);
	}

	*num_filas = indice_filas;
	free(linea);
	return 0;
}

static inline natural caca_comun_cuenta_bitchs(tipo_dato num) {
	natural bitch_cnt = 0;
	tipo_dato num_mod = 0;
	num_mod = num;
	while (num_mod) {
		num_mod &= ~(num_mod & (-num_mod));
		bitch_cnt++;
	}
	return bitch_cnt;
}

static inline char caca_comun_letra_a_valor_minuscula(char letra) {
	return letra - 'a';
}

static inline natural caca_comun_max_natural(natural *nums, natural nums_tam) {
	natural max = 0;

	for (int i = 0; i < nums_tam; i++) {
		natural num_act = nums[i];
		if (num_act > max) {
			max = num_act;
		}
	}

	return max;
}

#endif
#endif

#if 1


typedef struct stackaca_nodo {
	void *data;
	struct stackaca_nodo* next;
} stackaca_nodo;
typedef struct stackaca {
	stackaca_nodo *cabeza;
} stackaca;


static inline void stackaca_init(stackaca *ctx) {
	ctx->cabeza = NULL;
}


static inline void stackaca_push(stackaca *ctx, void *data) {
	stackaca_nodo* tmp = (stackaca_nodo*) malloc(sizeof(stackaca_nodo));
	assert_timeout(tmp);
	tmp->data = data;
	tmp->next = ctx->cabeza;
	ctx->cabeza = tmp;
}

static inline void *stackaca_pop(stackaca *ctx) {
	stackaca_nodo* tmp = ctx->cabeza;
	void *caca = tmp->data;
	ctx->cabeza = tmp->next;
	free(tmp);
	return caca;
}

static inline bool stackaca_empty(stackaca *ctx) {
	return ctx->cabeza == NULL ? verdadero : falso;
}

static inline void stackaca_fini(stackaca *ctx) {
	while (!stackaca_empty(ctx)) {
		stackaca_pop(ctx);
	}
}
#endif

#if 1
typedef natural hm_iter;
#define HASH_MAP_VALOR_INVALIDO ((hm_iter)CACA_COMUN_VALOR_INVALIDO)
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
int hash_map_robin_hood_back_shift_init(hm_rr_bs_tabla *ht, int num_cubetas) {
	ht->num_buckets_ = num_cubetas;
	ht->buckets_ = (hm_cubeta *) calloc(ht->num_buckets_, sizeof(hm_cubeta));
	ht->num_buckets_used_ = 0;
	ht->probing_max_ = num_cubetas;
	return 0;
}
int hash_map_robin_hood_back_shift_fini(hm_rr_bs_tabla *ht) {
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
static inline int hash_map_robin_hood_back_shift_llena_distancia_a_indice_inicio(
		hm_rr_bs_tabla *ht, uint64_t index_stored, uint64_t *distance) {
	hm_cubeta cubeta = ht->buckets_[index_stored];
	*distance = 0;
	if (cubeta.entry == NULL)
		return -1;
	uint64_t num_cubetas = ht->num_buckets_;
	uint64_t index_init = cubeta.hash % num_cubetas;
	if (index_init <= index_stored) {
		*distance = index_stored - index_init;
	} else {
		*distance = index_stored + (num_cubetas - index_init);
	}
	return 0;
}
hm_iter hash_map_robin_hood_back_shift_obten(hm_rr_bs_tabla *ht,
		const entero_largo key, entero_largo *value) {
	uint64_t num_cubetas = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;


	uint64_t hash = key % num_cubetas;
	uint64_t index_init = hash;
	uint64_t probe_distance = 0;
	uint64_t index_current;
	bool found = falso;
	uint32_t i;
	*value = HASH_MAP_VALOR_INVALIDO;
	for (i = 0; i < num_cubetas; i++) {
		index_current = (index_init + i) % num_cubetas;
		hm_entry *entrada = ht->buckets_[index_current].entry;
		if (entrada == NULL) {
			break;
		}
		hash_map_robin_hood_back_shift_llena_distancia_a_indice_inicio(ht,
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
	return HASH_MAP_VALOR_INVALIDO;
}
hm_iter hash_map_robin_hood_back_shift_pon(hm_rr_bs_tabla *ht, entero_largo key,
		entero_largo value, bool *nuevo_entry) {
	uint64_t num_cubetas = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_min_;
	hm_cubeta *cubetas = ht->buckets_;
	*nuevo_entry = verdadero;
	if (ht->num_buckets_used_ == num_cubetas) {
		*nuevo_entry = falso;
		return HASH_MAP_VALOR_INVALIDO;
	}
	ht->num_buckets_used_ += 1;


	uint64_t hash = key % num_cubetas;
	uint64_t index_init = hash;
	hm_entry *entry = (hm_entry *) calloc(1, sizeof(hm_entry));
	entry->llave = key;
	entry->valor = value;
	uint64_t index_current = index_init % num_cubetas;
	uint64_t probe_current = 0;
	uint64_t probe_distance;
	hm_entry *entry_temp;
	uint64_t hash_temp;
	uint64_t i;
	for (i = 0; i < num_cubetas; i++) {
		index_current = (index_init + i) % num_cubetas;
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
			hash_map_robin_hood_back_shift_llena_distancia_a_indice_inicio(ht,
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
int hash_map_robin_hood_back_shift_borra(hm_rr_bs_tabla *ht,
		const tipo_dato key) {
	uint64_t num_cubetas = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_max_;
	uint64_t hash = key % num_cubetas;
	uint64_t index_init = hash;
	bool found = falso;
	uint64_t index_current = 0;
	uint64_t probe_distance = 0;
	hm_entry *entrada = NULL;
	for (uint64_t i = 0; i < num_cubetas; i++) {
		index_current = (index_init + i) % num_cubetas;
		entrada = ht->buckets_[index_current].entry;
		hash_map_robin_hood_back_shift_llena_distancia_a_indice_inicio(ht,
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
		for (i = 1; i < num_cubetas; i++) {
			index_previous = (index_current + i - 1) % num_cubetas;
			index_swap = (index_current + i) % num_cubetas;
			hm_cubeta *cubeta_swap = ht->buckets_ + index_swap;
			hm_cubeta *cubeta_previous = ht->buckets_ + index_previous;
			if (cubeta_swap->entry == NULL) {
				cubeta_previous->entry = NULL;
				break;
			}
			uint64_t distance;
			if (hash_map_robin_hood_back_shift_llena_distancia_a_indice_inicio(
					ht, index_swap, &distance) != 0) {
				fprintf(stderr, "Error in FillDistanceToInitIndex()");
			}
			if (!distance) {
				cubeta_previous->entry = NULL;
				break;
			}
			cubeta_previous->entry = cubeta_swap->entry;
			cubeta_previous->hash = cubeta_swap->hash;
		}
		if (i < num_cubetas) {
			if (index_previous == prob_min) {
				prob_min++;
				if (prob_min >= num_cubetas) {
					prob_min = 0;
				} else {
					while (prob_min < num_cubetas
							&& ht->buckets_[prob_min].entry) {
						prob_min++;
					}
					if (prob_min >= num_cubetas) {
						prob_min = num_cubetas;
					}
				}
				ht->probing_min_ = prob_min;
			}
			if (index_previous == prob_max) {
				prob_max--;
				if (prob_max >= num_cubetas) {
					prob_max = num_cubetas;
				} else {
					while (((int64_t) prob_max) >= 0
							&& ht->buckets_[prob_max].entry) {
						prob_max--;
					}
					if (prob_max >= num_cubetas) {
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
static inline int hash_map_robin_hood_back_shift_indice_inicio(
		hm_rr_bs_tabla *ht) {
	return ht->probing_min_;
}
static inline int hash_map_robin_hood_back_shift_indice_final(
		hm_rr_bs_tabla *ht) {
	return ht->probing_max_;
}
static inline bool hash_map_robin_hood_back_shift_indice_existe(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	return !!ht->buckets_[indice].entry;
}
static inline entero_largo hash_map_robin_hood_back_shift_indice_obten_llave(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	return entrada->llave;
}
static inline void hash_map_robin_hood_back_shift_indice_pon_valor(
		hm_rr_bs_tabla *ht, hm_iter indice, entero_largo valor) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	entrada->valor = valor;
}
int hash_map_robin_hood_back_shift_indice_borra(hm_rr_bs_tabla *ht,
		hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	uint64_t num_cubetas = ht->num_buckets_;
	uint64_t prob_max = ht->probing_max_;
	uint64_t prob_min = ht->probing_max_;
	uint64_t index_current = indice;
	hm_entry *entrada = ht->buckets_[index_current].entry;
	assert_timeout(entrada);
	free(entrada);
	uint64_t i = 1;
	uint64_t index_previous = 0, index_swap = 0;
	for (i = 1; i < num_cubetas; i++) {
		index_previous = (index_current + i - 1) % num_cubetas;
		index_swap = (index_current + i) % num_cubetas;
		hm_cubeta *cubeta_swap = ht->buckets_ + index_swap;
		hm_cubeta *cubeta_previous = ht->buckets_ + index_previous;
		if (cubeta_swap->entry == NULL) {
			cubeta_previous->entry = NULL;
			break;
		}
		uint64_t distance;
		if (hash_map_robin_hood_back_shift_llena_distancia_a_indice_inicio(ht,
				index_swap, &distance) != 0) {
			fprintf(stderr, "Error in FillDistanceToInitIndex()");
		}
		if (!distance) {
			cubeta_previous->entry = NULL;
			break;
		}
		cubeta_previous->entry = cubeta_swap->entry;
		cubeta_previous->hash = cubeta_swap->hash;
	}
	if (i < num_cubetas) {
		if (index_previous == prob_min) {
			prob_min++;
			if (prob_min >= num_cubetas) {
				prob_min = 0;
			} else {
				while (prob_min < num_cubetas && ht->buckets_[prob_min].entry) {
					prob_min++;
				}
				if (prob_min >= num_cubetas) {
					prob_min = num_cubetas;
				}
			}
			ht->probing_min_ = prob_min;
		}
		if (index_previous == prob_max) {
			prob_max--;
			if (prob_max >= num_cubetas) {
				prob_max = num_cubetas;
			} else {
				while (((int64_t) prob_max) >= 0 && ht->buckets_[prob_max].entry) {
					prob_max--;
				}
				if (prob_max >= num_cubetas) {
					prob_max = 0;
				}
			}
			ht->probing_max_ = prob_max;
		}
	}
	ht->num_buckets_used_--;
	return 0;
}
static inline entero_largo hash_map_robin_hood_back_shift_indice_obten_valor(
		hm_rr_bs_tabla *ht, hm_iter indice) {
	assert_timeout(indice <= ht->probing_max_ && indice >= ht->probing_min_);
	hm_entry *entrada = ht->buckets_[indice].entry;
	assert_timeout(entrada);
	return entrada->valor;
}
static inline bool hash_map_robin_hood_back_shift_esta_vacio(hm_rr_bs_tabla *ht) {
	assert_timeout(ht->num_buckets_used_ <= ht->num_buckets_);
	return !ht->num_buckets_used_;
}

static inline void hash_map_robin_hood_back_shift_reemplazar(hm_rr_bs_tabla *ht,
		entero_largo llave, entero_largo valor) {
	hm_iter iter = 0;
	entero_largo *valor_int = &(entero_largo ) { 0 };

	iter = hash_map_robin_hood_back_shift_obten(ht, llave, valor_int);
	

	assert_timeout(iter!=HASH_MAP_VALOR_INVALIDO);

	hash_map_robin_hood_back_shift_indice_pon_valor(ht, iter, valor);
}

static inline void hash_map_robin_hood_back_shift_insertar_nuevo(
		hm_rr_bs_tabla *ht, entero_largo llave, entero_largo valor) {
	hm_iter iter = 0;
	bool nuevo = falso;
	iter = hash_map_robin_hood_back_shift_pon(ht, llave, valor, &nuevo);

	assert_timeout(iter!=HASH_MAP_VALOR_INVALIDO);
	assert_timeout(nuevo);
}

#endif

#if 1



#define HEAP_SHIT_MAX_NODOS (300002)
#define HEAP_SHIT_MAX_LLAVES HUARONVERGA_MAX_LLAVE
#define HEAP_SHIT_VALOR_INVALIDO ((entero_largo_sin_signo)(((entero_largo_sin_signo)CACA_COMUN_VALOR_INVALIDO)<<32 | CACA_COMUN_VALOR_INVALIDO))

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
	heap_shit_nodo heap[HEAP_SHIT_MAX_NODOS];
	hm_rr_bs_tabla *tablon_llave_a_idx_heap;
	heap_shit_compara_llave compara_llave_fn;
	heap_shit_compara_prioridad compara_prioridad_fn;
	heap_shit_obten_llave obten_llave_fn;
};


static inline heap_shit *heap_shit_init(bool es_min,
		heap_shit_compara_llave compara_llave_fn,
		heap_shit_compara_prioridad compara_prioridad_fn,
		heap_shit_obten_llave obten_llave_fn) {
	heap_shit *heap = calloc(1, sizeof(heap_shit));
	assert_timeout(heap);
	heap->heap_size = 0;
	heap->min = es_min;
	heap->compara_llave_fn = compara_llave_fn;
	heap->compara_prioridad_fn = compara_prioridad_fn;
	heap->obten_llave_fn = obten_llave_fn;
	memset(heap->heap, HEAP_SHIT_VALOR_INVALIDO, sizeof(heap->heap));
	heap->tablon_llave_a_idx_heap = calloc(1, sizeof(hm_rr_bs_tabla));
	assert_timeout(heap->tablon_llave_a_idx_heap);
	hash_map_robin_hood_back_shift_init(heap->tablon_llave_a_idx_heap,
	HEAP_SHIT_MAX_NODOS);
	return heap;
}

void heap_shit_fini(heap_shit *heap_ctx) {
	hash_map_robin_hood_back_shift_fini(heap_ctx->tablon_llave_a_idx_heap);
	free(heap_ctx->tablon_llave_a_idx_heap);
	free(heap_ctx);
}

static inline bool heap_shit_nodo_valido(heap_shit_nodo *nodo) {
	return nodo->valor != (void *) HEAP_SHIT_VALOR_INVALIDO;
}

static inline void heap_shit_valida_nodos(heap_shit *heap_ctx) {
	for (int i = 1; i <= heap_ctx->heap_size; i++) {
		assert_timeout(heap_shit_nodo_valido(heap_ctx->heap + i));
	}
}

static inline natural heap_shit_idx_padre(natural idx_nodo) {
	return idx_nodo >> 1;
}

static inline natural heap_shit_idx_hijo_izq(natural idx_nodo) {
	return idx_nodo << 1;
}


static inline void heap_shit_insert(heap_shit *heap_ctx,
		heap_shit_nodo *nodo_nuevo) {
	natural heap_size = heap_ctx->heap_size;
	heap_shit_nodo *heap = NULL;
	hm_rr_bs_tabla *mapeo_inv = heap_ctx->tablon_llave_a_idx_heap;
	bool nuevo;

	heap = heap_ctx->heap;

	heap_size++;
	heap[heap_size] = *nodo_nuevo; 
	
	natural now = heap_size;

	while (heap_shit_nodo_valido(heap + heap_shit_idx_padre(now))
			&& ((heap_ctx->min
					&& heap_ctx->compara_prioridad_fn(
							heap[heap_shit_idx_padre(now)].valor,
							nodo_nuevo->valor) > 0)

					|| (!heap_ctx->min
							&& heap_ctx->compara_prioridad_fn(
									heap[heap_shit_idx_padre(now)].valor,
									nodo_nuevo->valor) < 0

					))) {


		natural idx_padre = heap_shit_idx_padre(now);
		entero_largo llave_padre = heap_ctx->obten_llave_fn(
				heap[idx_padre].valor);
		assert_timeout(llave_padre!= HEAP_SHIT_VALOR_INVALIDO);

		heap[now] = heap[idx_padre];
		hash_map_robin_hood_back_shift_reemplazar(mapeo_inv, llave_padre, now);
		caca_log_debug("llave %d tiene valor %u ", llave_padre, now);

		now = idx_padre;
	}



	heap[now] = *nodo_nuevo;
	hash_map_robin_hood_back_shift_insertar_nuevo(mapeo_inv,
			heap_ctx->obten_llave_fn(nodo_nuevo->valor), now);

	heap_ctx->heap_size = heap_size;
	assert_timeout(heap_size >= now);


}


#define heap_shit_insertar(heap_ctx,valor_in) heap_shit_insert(heap_ctx,&(heap_shit_nodo) {.valor=valor_in})
#define heap_shit_insertar_valor_unico(heap_ctx,valor) heap_shit_insertar(heap_ctx,valor,valor,(void *)((entero_largo)valor))

static inline void *heap_shit_delete(heap_shit *heap_ctx, natural idx_a_borrar) {
	natural heap_size = heap_ctx->heap_size;
	natural child, now;
	heap_shit_nodo minElement = { 0 };
	heap_shit_nodo lastElement = { 0 };
	heap_shit_nodo *heap;
	hm_rr_bs_tabla *mapeo_inv = heap_ctx->tablon_llave_a_idx_heap;
	void *resultado;
	bool nuevo;

	heap = heap_ctx->heap;

	assert_timeout(heap_size >= idx_a_borrar);
	assert_timeout(idx_a_borrar);

	
	minElement = heap[idx_a_borrar];
	resultado = minElement.valor;
	lastElement = heap[heap_size--];

	now = idx_a_borrar;
	if (idx_a_borrar != heap_size + 1) {
		if (heap_shit_nodo_valido(heap + heap_shit_idx_padre(now))
				&& ((heap_ctx->min
						&& heap_ctx->compara_prioridad_fn(
								heap[heap_shit_idx_padre(now)].valor,
								lastElement.valor) > 0)
						|| (!heap_ctx->min
								&& (heap_ctx->compara_prioridad_fn(
										heap[heap_shit_idx_padre(now)].valor,
										lastElement.valor))))) {

			while (heap_shit_nodo_valido(heap + heap_shit_idx_padre(now))
					&& ((heap_ctx->min
							&& heap_ctx->compara_prioridad_fn(
									heap[heap_shit_idx_padre(now)].valor,
									lastElement.valor) > 0)
							|| (!heap_ctx->min
									&& (heap_ctx->compara_prioridad_fn(
											heap[heap_shit_idx_padre(now)].valor,
											lastElement.valor) < 0)))) {
				assert_timeout(now <= heap_size);
				natural idx_padre = heap_shit_idx_padre(now);
				entero_largo llave_padre = heap_ctx->obten_llave_fn(
						heap[idx_padre].valor);

				assert_timeout(llave_padre != HEAP_SHIT_VALOR_INVALIDO);

				heap[now] = heap[idx_padre];

				hash_map_robin_hood_back_shift_reemplazar(mapeo_inv,
						llave_padre, now);

				caca_log_debug("llave %d tiene valor %u", llave_padre, now);

				now = idx_padre;
			}
		} else {

			
			for (now = idx_a_borrar; heap_shit_idx_hijo_izq(now) <= heap_size;
					now = child) {
				
				
				child = heap_shit_idx_hijo_izq(now);
				assert_timeout(child <= heap_size);
				
				if (child != heap_size
						&& ((heap_ctx->min
								&& heap_ctx->compara_prioridad_fn(
										heap[child + 1].valor,
										heap[child].valor) < 0)
								|| (!heap_ctx->min
										&& heap_ctx->compara_prioridad_fn(
												heap[child + 1].valor,
												heap[child].valor) > 0))) {
					child++;
				}
				assert_timeout(child <= heap_size);
				
				

				if ((heap_ctx->min
						&& heap_ctx->compara_prioridad_fn(lastElement.valor,
								heap[child].valor) > 0)
						|| (!heap_ctx->min
								&& heap_ctx->compara_prioridad_fn(
										lastElement.valor, heap[child].valor))) {
					heap[now] = heap[child];

					hash_map_robin_hood_back_shift_reemplazar(mapeo_inv,
							heap_ctx->obten_llave_fn(heap[child].valor), now);
					caca_log_debug("llave %d tiene valor %u",
							heap_ctx->obten_llave_fn(heap[child].valor), now);
				} else 
				{
					break;
				}
			}
		}
	}

	hash_map_robin_hood_back_shift_borra(mapeo_inv,
			heap_ctx->obten_llave_fn(minElement.valor));
	caca_log_debug("borrada llave %d",
			heap_ctx->obten_llave_fn( minElement.valor));
	if (heap_size && idx_a_borrar != heap_size + 1) {
		assert_timeout(now <= heap_size);
		heap[now] = lastElement;
		hash_map_robin_hood_back_shift_reemplazar(mapeo_inv,
				heap_ctx->obten_llave_fn(lastElement.valor), now);
		caca_log_debug("llave %d tiene valor %u ",
				heap_ctx->obten_llave_fn(lastElement.valor), now);
	}
	heap_ctx->heap_size = heap_size;
	

	return resultado;
}

static inline void *heap_shit_borrar_directo(heap_shit *heap_ctx,
		tipo_dato llave) {
	natural heap_size = heap_ctx->heap_size;
	hm_rr_bs_tabla *indices_valores = heap_ctx->tablon_llave_a_idx_heap;
	entero_largo idx_a_borrar;

	assert_timeout(heap_size);

	natural idx_hm = hash_map_robin_hood_back_shift_obten(indices_valores,
			llave, &idx_a_borrar);
	assert_timeout(idx_a_borrar <= heap_size);
	caca_log_debug("borrando llave %d en idx %u en idx hm %u con heap size %u",
			llave, idx_a_borrar, idx_hm, heap_size);
	assert_timeout(idx_hm!=HASH_MAP_VALOR_INVALIDO);
	assert_timeout(idx_a_borrar != HEAP_SHIT_VALOR_INVALIDO);

	return heap_shit_delete(heap_ctx, idx_a_borrar);
}

static inline void *heap_shit_borra_torpe(heap_shit *heap_ctx) {
	if (heap_ctx->heap_size) {
		return heap_shit_borrar_directo(heap_ctx,
				heap_ctx->obten_llave_fn(heap_ctx->heap[1].valor));
	} else {
		assert_timeout(!heap_ctx->heap[0].valor);
		return NULL;
	}
}

static inline void heap_shit_actualiza(heap_shit *ctx, void *valor) {
	entero_largo llave = ctx->obten_llave_fn(valor);
	heap_shit_borrar_directo(ctx, llave);
	heap_shit_insertar(ctx, valor);
}
#endif

#if 1



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
	listilla_nodo *nodo_act;
	bool primera_llamada;
	natural llamadas;
} listilla_iterador;


struct my_list* list_add_element(struct my_list* s, void *valor) {
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


static inline void *list_remove_element(struct my_list* s) {
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
		list_remove_element(s);
	}

	return s;
}

struct my_list* list_new(void) {
	struct my_list* p = malloc(1 * sizeof(*p));

	assert_timeout(p);

	p->head = p->tail = NULL;

	return p;
}

void list_print_element(const struct my_struct* p) {
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
			list_print_element(p);
		}
	}

	printf("------------------\n");
}

static inline bool list_empty(struct my_list *s) {
	return !s->head;
}

static inline void list_iterador_init(listilla_fifo *ctx,
		listilla_iterador *iter) {
	iter->ctx = ctx;
	iter->nodo_act = NULL;
	iter->primera_llamada = verdadero;
	iter->llamadas = 0;
}
static inline void list_iterador_fini(listilla_iterador *iter) {
	iter->ctx = NULL;
	iter->nodo_act = NULL;
}

static inline void *list_iterador_peekea_actual(listilla_iterador *iter) {
	return iter->nodo_act ? iter->nodo_act->valor : NULL;
}
static inline void *list_iterador_obten_siguiente(listilla_iterador *iter) {
	if (iter->nodo_act) {
		iter->nodo_act = iter->nodo_act->next;
	} else {
		if (iter->primera_llamada) {
			iter->primera_llamada = falso;
			iter->nodo_act = iter->ctx->head;
		}
	}
	if (iter->nodo_act) {
		iter->llamadas++;
	}
	return iter->nodo_act ? iter->nodo_act->valor : NULL;
}

#endif

#define SUBMIERDA_MAX_LETRAS ('z'-'a'+1)
#define SUBMIERDA_MAX_NODOS ((natural)3E5)

typedef enum submierda_estado_nodo {
	no_visitado_submierda_estado_nodo = 0,
	en_pila_submierda_estado_nodo,
	consumido_submierda_estado_nodo
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
	natural conteo_letras[SUBMIERDA_MAX_LETRAS];
	natural vecinos_por_procesar_cnt;
} submierda_nodo;

static inline bool submierda_encuentra_hay_ciclo_caca_dfs(submierda_nodo *nodo) {
	bool caca = falso;
	stackaca *pila = &(stackaca ) { 0 };
	submierda_nodo *nodo_act = NULL;

	stackaca_init(pila);

	nodo_act = nodo;

	stackaca_push(pila, nodo_act);

	while (!stackaca_empty(pila)) {
		bool ciclo_encontrado = falso;
		nodo_act = stackaca_pop(pila);
		if (nodo_act->vecinos_por_visitar_cnt) {
			submierda_nodo *vecino = NULL;
			listilla_fifo *vecinos = nodo_act->vecinos;
			listilla_iterador *iter = &nodo_act->iter;
			nodo_act->color = en_pila_submierda_estado_nodo;
			if (!nodo_act->vecinos_visitados_cnt) {
				list_iterador_init(vecinos, iter);
			}

			assert_timeout(nodo_act->vecinos_visitados_cnt == iter->llamadas);

			vecino = list_iterador_obten_siguiente(iter);
			nodo_act->vecinos_por_visitar_cnt--;
			nodo_act->vecinos_visitados_cnt++;

			caca_log_debug("en nodo %u vecino %u (color %u)", nodo_act->llave,
					vecino->llave, vecino->color);
			switch (vecino->color) {
			case no_visitado_submierda_estado_nodo:
				stackaca_push(pila, nodo_act);
				stackaca_push(pila, vecino);
				break;
			case en_pila_submierda_estado_nodo:
				ciclo_encontrado = verdadero;
				break;
			default:
				assert_timeout(vecino->color == consumido_submierda_estado_nodo)
				;
				stackaca_push(pila, nodo_act);
				break;
			}

			if (ciclo_encontrado) {
				caca = verdadero;
				break;
			}

		} else {
			nodo_act->color = consumido_submierda_estado_nodo;
			caca_log_debug("se consumio %u", nodo_act->llave);
			list_iterador_fini(&nodo_act->iter);
		}
	}

	stackaca_fini(pila);
	return caca;
}
static inline bool submierda_encuentra_hay_ciclo_caca(submierda_nodo *nodos,
		natural nodos_tam) {
	bool hay_caca = falso;
	for (int i = 1; i < nodos_tam + 1; i++) {
		submierda_nodo *nodo_act = nodos + i;
		if (nodo_act->color == no_visitado_submierda_estado_nodo) {
			caca_log_debug("empezando dfs en %u", nodo_act->llave);
			hay_caca = submierda_encuentra_hay_ciclo_caca_dfs(nodo_act);
			if (hay_caca) {
				break;
			}
		}
	}
	return hay_caca;
}

int submierda_compara_hijos_visitados_fn(void *pa, void *pb) {
	int res = 0;
	submierda_nodo *a = pa;
	submierda_nodo *b = pb;

	res = a->vecinos_por_procesar_cnt - b->vecinos_por_procesar_cnt;

	return res;
}

entero_largo submierda_obten_llave_fn(void *a) {
	return ((submierda_nodo *) a)->llave;
}

static inline tipo_dato submierda_calcula_largote(submierda_nodo *nodos,
		natural nodos_cnt) {
	tipo_dato res = 0;
	heap_shit *pq = NULL;
	submierda_nodo *nodo_ultimo = &(submierda_nodo ) { 0 };

	pq = heap_shit_init(verdadero, NULL, submierda_compara_hijos_visitados_fn,
			submierda_obten_llave_fn);

	nodo_ultimo->vecinos = list_new();

	for (int i = 1; i < nodos_cnt + 1; i++) {
		submierda_nodo *nodo_act = nodos + i;

		nodo_act->conteo_letras[caca_comun_letra_a_valor_minuscula(
				nodo_act->valor)] = 1;

		heap_shit_insertar(pq, nodo_act);

		nodo_ultimo->vecinos_por_procesar_cnt++;
		nodo_ultimo->vecinos_por_visitar_cnt =
				nodo_ultimo->vecinos_por_procesar_cnt;

		list_add_element(nodo_ultimo->vecinos, nodo_act);

		list_add_element(nodo_act->previos, nodo_ultimo);

	}

	nodo_ultimo->previos = list_new();
	heap_shit_insertar(pq, nodo_ultimo);

	while (pq->heap_size) {
		submierda_nodo *nodo_act = heap_shit_borra_torpe(pq);
		caca_log_debug("procesando nodo %u", nodo_act->llave);
		listilla_iterador *iter = &(listilla_iterador ) { 0 };
		submierda_nodo *vecino = NULL;
		submierda_nodo *previo = NULL;
		natural max_cnt_letras[SUBMIERDA_MAX_LETRAS] = { 0 };

		assert_timeout(!nodo_act->vecinos_por_procesar_cnt);

		list_iterador_init(nodo_act->vecinos, iter);

		while ((vecino = list_iterador_obten_siguiente(iter))) {
			for (char c = 'a'; c <= 'z'; c++) {
				natural ci = caca_comun_letra_a_valor_minuscula(c);
				if (max_cnt_letras[ci] < vecino->conteo_letras[ci]) {
					max_cnt_letras[ci] = vecino->conteo_letras[ci];
				}
			}
		}

		for (char c = 'a', ci = caca_comun_letra_a_valor_minuscula(c); c <= 'z';
				c++, ci++) {
			nodo_act->conteo_letras[ci] += max_cnt_letras[ci];
		}

		list_iterador_fini(iter);

		list_iterador_init(nodo_act->previos, iter);
		while ((previo = list_iterador_obten_siguiente(iter))) {
			previo->vecinos_por_procesar_cnt--;
			heap_shit_actualiza(pq, previo);
		}
		list_iterador_fini(iter);
	}

	heap_shit_fini(pq);

	res = caca_comun_max_natural(nodo_ultimo->conteo_letras,
	SUBMIERDA_MAX_LETRAS);

	return res;
}

static inline int submierda_core(submierda_nodo *nodos, natural nodos_tam) {
	int res = 0;
	bool hay_caca = submierda_encuentra_hay_ciclo_caca(nodos, nodos_tam);

	if (hay_caca) {
		res = -1;
	} else {
		res = submierda_calcula_largote(nodos, nodos_tam);
	}
	return res;
}

submierda_nodo *nodos = NULL;
char cadena[SUBMIERDA_MAX_NODOS + 1] = { '\0' };

static inline void submierda_main() {
	natural nodos_tam = 0;
	natural aristas_tam = 0;

	scanf("%u %u\n", &nodos_tam, &aristas_tam);
	nodos = calloc(SUBMIERDA_MAX_NODOS + 1, sizeof(submierda_nodo));
	assert(nodos);

	scanf("%s", cadena + 1);

	caca_log_debug("carmen se me perdio la cadenita %s", cadena+1);
	for (int i = 1; i < nodos_tam + 1; i++) {
		submierda_nodo *nodo_act = nodos + i;
		nodo_act->color = no_visitado_submierda_estado_nodo;
		nodo_act->llave = i;
		nodo_act->conteo_letras[caca_comun_letra_a_valor_minuscula(cadena[i])] =
				1;
		nodo_act->valor = cadena[i];
		nodo_act->vecinos = list_new();
		nodo_act->previos = list_new();
	}

	for (int i = 0; i < aristas_tam; i++) {
		natural x = 0;
		natural y = 0;
		submierda_nodo *origen = NULL;
		submierda_nodo *destino = NULL;

		scanf("%u %u\n", &x, &y);

		origen = nodos + x;
		destino = nodos + y;

		origen->vecinos_por_procesar_cnt = ++origen->vecinos_por_visitar_cnt;

		list_add_element(origen->vecinos, destino);
		list_add_element(destino->previos, origen);
	}

	int res = submierda_core(nodos, nodos_tam);
	caca_log_debug("cca %d", res);
	printf("%d\n", res);
	free(nodos);
}

int main(void) {
	submierda_main();
	return EXIT_SUCCESS;
}
