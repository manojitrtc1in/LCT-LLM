#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

static inline int cmc_i64_cmp(int64_t x1, int64_t x2)
{
    return (x1 > x2) - (x1 < x2);
}
static inline int cmc_i32_cmp(int32_t x1, int32_t x2)
{
    return cmc_i64_cmp((int64_t)x1, (int64_t)x2);
}

static inline size_t cmc_i64_hash(int64_t e)
{
    size_t x = (size_t)e;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9UL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebUL;
    x = x ^ (x >> 31);
    return x;
}
static inline size_t cmc_i32_hash(int32_t e)
{
    return cmc_i64_hash((int64_t)e);
}

static struct cmc_alloc_node
{
    void *(*malloc)(size_t);
    void *(*calloc)(size_t, size_t);
    void *(*realloc)(void *, size_t);
    void (*free)(void *);
} cmc_alloc_node_default = { malloc, calloc, realloc, free };
struct cmc_callbacks
{
    void (*create)(void);
    void (*read)(void);
    void (*update)(void);
    void (*delete)(void);
    void (*resize)(void);
};
enum cmc_flags
{
    CMC_FLAG_OK = 0,
    CMC_FLAG_ALLOC = 1,
    CMC_FLAG_EMPTY = 2,
    CMC_FLAG_NOT_FOUND = 3,
    CMC_FLAG_INVALID = 4,
    CMC_FLAG_RANGE = 5,
    CMC_FLAG_DUPLICATE = 6,
    CMC_FLAG_ERROR = 7,
    CMC_FLAG_THREAD = 8,
    CMC_FLAG_MUTEX = 9
};
__attribute__((__unused__)) static const char *cmc_flags_to_str[10] = { "OK", "ALLOC", "EMPTY", "NOT_FOUND", "INVALID",
                                                       "RANGE", "DUPLICATE", "ERROR", "THREAD", "MUTEX" };
typedef uint32_t cmc_bitset_word;
static inline size_t cmc_bidx_to_widx(size_t idx)
{
    static const size_t shift =
        ((sizeof(cmc_bitset_word) * 8) >> 6) > 0
            ? 6
            : ((sizeof(cmc_bitset_word) * 8) >> 5) > 0 ? 5 : ((sizeof(cmc_bitset_word) * 8) >> 4) > 0 ? 4 : 3;
    return idx >> shift;
}
enum cmc_entry_state
{
    CMC_ES_DELETED = -1,
    CMC_ES_EMPTY = 0,
    CMC_ES_FILLED = 1
};
static const size_t cmc_hashtable_primes[] = {
    53, 97, 191, 383, 769,
    1531, 3067, 6143,
    12289, 24571, 49157, 98299,
    196613, 393209, 786431,
    1572869, 3145721, 6291449,
    12582917, 25165813, 50331653,
    100663291, 201326611, 402653189, 805306357,
    1610612741, 3221225473, 6442450939,
    12884901893, 25769803799, 51539607551,
    103079215111, 206158430209, 412316860441, 824633720831,
    1649267441651, 3298534883309, 6597069766657,
    13194139533299, 26388279066623, 52776558133303,
    105553116266489, 211106232532969, 422212465066001, 844424930131963,
    1688849860263953, 3377699720527861, 6755399441055731,
    13510798882111483, 27021597764222939, 54043195528445957,
    108086391056891903, 216172782113783773, 432345564227567621, 864691128455135207,
    1729382256910270481, 3458764513820540933, 6917529027641081903,
    13835058055282163729llu,
};
enum cmc_heap_order
{
    CMC_MAX_HEAP = 1,
    CMC_MIN_HEAP = -1
};

struct hashmap { struct hashmap_entry * buffer; size_t capacity; size_t count; double load; int flag; struct hashmap_fkey * f_key; struct hashmap_fval * f_val; struct cmc_alloc_node *alloc; struct cmc_callbacks *callbacks; }; struct hashmap_entry { int32_t key; int32_t value; size_t dist; enum cmc_entry_state state; }; struct hashmap_fkey { int (*cmp)(int32_t, int32_t); int32_t (*cpy)(int32_t); _Bool (*str)(FILE *, int32_t); void (*free)(int32_t); size_t (*hash)(int32_t); int (*pri)(int32_t, int32_t); }; struct hashmap_fval { int (*cmp)(int32_t, int32_t); int32_t (*cpy)(int32_t); _Bool (*str)(FILE *, int32_t); void (*free)(int32_t); size_t (*hash)(int32_t); int (*pri)(int32_t, int32_t); }; struct hashmap *hm_new(size_t capacity, double load, struct hashmap_fkey * f_key, struct hashmap_fval * f_val); struct hashmap *hm_new_custom(size_t capacity, double load, struct hashmap_fkey * f_key, struct hashmap_fval * f_val, struct cmc_alloc_node * alloc, struct cmc_callbacks * callbacks); void hm_clear(struct hashmap * _map_); void hm_free(struct hashmap * _map_); void hm_customize(struct hashmap * _map_, struct cmc_alloc_node * alloc, struct cmc_callbacks * callbacks); _Bool hm_insert(struct hashmap * _map_, int32_t key, int32_t value); _Bool hm_update(struct hashmap * _map_, int32_t key, int32_t new_value, int32_t * old_value); _Bool hm_remove(struct hashmap * _map_, int32_t key, int32_t * out_value); _Bool hm_max(struct hashmap * _map_, int32_t * key, int32_t * value); _Bool hm_min(struct hashmap * _map_, int32_t * key, int32_t * value); int32_t hm_get(struct hashmap * _map_, int32_t key); int32_t *hm_get_ref(struct hashmap * _map_, int32_t key); _Bool hm_contains(struct hashmap * _map_, int32_t key); _Bool hm_empty(struct hashmap * _map_); _Bool hm_full(struct hashmap * _map_); size_t hm_count(struct hashmap * _map_); size_t hm_capacity(struct hashmap * _map_); double hm_load(struct hashmap * _map_); int hm_flag(struct hashmap * _map_); _Bool hm_resize(struct hashmap * _map_, size_t capacity); struct hashmap *hm_copy_of(struct hashmap * _map_); _Bool hm_equals(struct hashmap * _map1_, struct hashmap * _map2_); struct hashmap hm_init(size_t capacity, double load, struct hashmap_fkey * f_key, struct hashmap_fval * f_val); struct hashmap hm_init_custom(size_t capacity, double load, struct hashmap_fkey * f_key, struct hashmap_fval * f_val, struct cmc_alloc_node * alloc, struct cmc_callbacks * callbacks); void hm_release(struct hashmap _map_); struct hashmap_iter { struct hashmap *target; size_t cursor; size_t index; size_t first; size_t last; _Bool start; _Bool end; }; struct hashmap_iter hm_iter_start(struct hashmap * target); struct hashmap_iter hm_iter_end(struct hashmap * target); _Bool hm_iter_at_start(struct hashmap_iter * iter); _Bool hm_iter_at_end(struct hashmap_iter * iter); _Bool hm_iter_to_start(struct hashmap_iter * iter); _Bool hm_iter_to_end(struct hashmap_iter * iter); _Bool hm_iter_next(struct hashmap_iter * iter); _Bool hm_iter_prev(struct hashmap_iter * iter); _Bool hm_iter_advance(struct hashmap_iter * iter, size_t steps); _Bool hm_iter_rewind(struct hashmap_iter * iter, size_t steps); _Bool hm_iter_go_to(struct hashmap_iter * iter, size_t index); int32_t hm_iter_key(struct hashmap_iter * iter); int32_t hm_iter_value(struct hashmap_iter * iter); int32_t *hm_iter_rvalue(struct hashmap_iter * iter); size_t hm_iter_index(struct hashmap_iter * iter); _Bool hm_to_string(struct hashmap * _map_, FILE * fptr); _Bool hm_print(struct hashmap * _map_, FILE * fptr, const char *start, const char *separator, const char *end, const char *key_val_sep); static struct hashmap_entry * hm_impl_get_entry(struct hashmap * _map_, int32_t key); static size_t hm_impl_calculate_size(size_t required); struct hashmap *hm_new(size_t capacity, double load, struct hashmap_fkey * f_key, struct hashmap_fval * f_val) { return hm_new_custom(capacity, load, f_key, f_val, ((void *)0), ((void *)0)); } struct hashmap *hm_new_custom(size_t capacity, double load, struct hashmap_fkey * f_key, struct hashmap_fval * f_val, struct cmc_alloc_node * alloc, struct cmc_callbacks * callbacks) { ; if (capacity == 0 || load <= 0 || load >= 1) return ((void *)0); if (capacity >= (18446744073709551615UL) * load) return ((void *)0); if (!f_key || !f_val) return ((void *)0); size_t real_capacity = hm_impl_calculate_size(capacity / load); if (!alloc) alloc = &cmc_alloc_node_default; struct hashmap *_map_ = alloc->malloc(sizeof(struct hashmap)); if (!_map_) return ((void *)0); _map_->buffer = alloc->calloc(real_capacity, sizeof(struct hashmap_entry)); if (!_map_->buffer) { alloc->free(_map_); return ((void *)0); } _map_->count = 0; _map_->capacity = real_capacity; _map_->load = load; _map_->flag = CMC_FLAG_OK; _map_->f_key = f_key; _map_->f_val = f_val; _map_->alloc = alloc; (_map_)->callbacks = callbacks; return _map_; } void hm_clear(struct hashmap * _map_) { if (_map_->f_key->free || _map_->f_val->free) { for (size_t i = 0; i < _map_->capacity; i++) { struct hashmap_entry *entry = &(_map_->buffer[i]); if (entry->state == CMC_ES_FILLED) { if (_map_->f_key->free) _map_->f_key->free(entry->key); if (_map_->f_val->free) _map_->f_val->free(entry->value); } } } memset(_map_->buffer, 0, sizeof(struct hashmap_entry) * _map_->capacity); _map_->count = 0; _map_->flag = CMC_FLAG_OK; } void hm_free(struct hashmap * _map_) { if (_map_->f_key->free || _map_->f_val->free) { for (size_t i = 0; i < _map_->capacity; i++) { struct hashmap_entry *entry = &(_map_->buffer[i]); if (entry->state == CMC_ES_FILLED) { if (_map_->f_key->free) _map_->f_key->free(entry->key); if (_map_->f_val->free) _map_->f_val->free(entry->value); } } } _map_->alloc->free(_map_->buffer); _map_->alloc->free(_map_); } void hm_customize(struct hashmap * _map_, struct cmc_alloc_node * alloc, struct cmc_callbacks * callbacks) { ; if (!alloc) _map_->alloc = &cmc_alloc_node_default; else _map_->alloc = alloc; (_map_)->callbacks = callbacks; _map_->flag = CMC_FLAG_OK; } _Bool hm_insert(struct hashmap * _map_, int32_t key, int32_t value) { if (hm_full(_map_)) { if (!hm_resize(_map_, _map_->capacity + 1)) return 0; } if (hm_impl_get_entry(_map_, key) != ((void *)0)) { _map_->flag = CMC_FLAG_DUPLICATE; return 0; } size_t hash = _map_->f_key->hash(key); size_t original_pos = hash % _map_->capacity; size_t pos = original_pos; struct hashmap_entry *target = &(_map_->buffer[pos]); if (target->state == CMC_ES_EMPTY || target->state == CMC_ES_DELETED) { target->key = key; target->value = value; target->dist = 0; target->state = CMC_ES_FILLED; } else { while (1) { pos++; target = &(_map_->buffer[pos % _map_->capacity]); if (target->state == CMC_ES_EMPTY || target->state == CMC_ES_DELETED) { target->key = key; target->value = value; target->dist = pos - original_pos; target->state = CMC_ES_FILLED; break; } else if (target->dist < pos - original_pos) { int32_t tmp_k = target->key; int32_t tmp_v = target->value; size_t tmp_dist = target->dist; target->key = key; target->value = value; target->dist = pos - original_pos; key = tmp_k; value = tmp_v; original_pos = pos - tmp_dist; } } } _map_->count++; _map_->flag = CMC_FLAG_OK; if ((_map_)->callbacks && (_map_)->callbacks->create) (_map_)->callbacks->create();; return 1; } _Bool hm_update(struct hashmap * _map_, int32_t key, int32_t new_value, int32_t * old_value) { if (hm_empty(_map_)) { _map_->flag = CMC_FLAG_EMPTY; return 0; } struct hashmap_entry *entry = hm_impl_get_entry(_map_, key); if (!entry) { _map_->flag = CMC_FLAG_NOT_FOUND; return 0; } if (old_value) *old_value = entry->value; entry->value = new_value; _map_->flag = CMC_FLAG_OK; if ((_map_)->callbacks && (_map_)->callbacks->update) (_map_)->callbacks->update();; return 1; } _Bool hm_remove(struct hashmap * _map_, int32_t key, int32_t * out_value) { if (hm_empty(_map_)) { _map_->flag = CMC_FLAG_EMPTY; return 0; } struct hashmap_entry *result = hm_impl_get_entry(_map_, key); if (result == ((void *)0)) { _map_->flag = CMC_FLAG_NOT_FOUND; return 0; } if (out_value) *out_value = result->value; result->key = (int32_t){ 0 }; result->value = (int32_t){ 0 }; result->dist = 0; result->state = CMC_ES_DELETED; _map_->count--; _map_->flag = CMC_FLAG_OK; if ((_map_)->callbacks && (_map_)->callbacks->delete) (_map_)->callbacks->delete();; return 1; } _Bool hm_max(struct hashmap * _map_, int32_t * key, int32_t * value) { if (hm_empty(_map_)) { _map_->flag = CMC_FLAG_EMPTY; return 0; } int32_t max_key = (int32_t) { 0 }; int32_t max_val = (int32_t) { 0 }; size_t first = 0; for (; first < _map_->capacity; first++) { if (_map_->buffer[first].state == CMC_ES_FILLED) { max_key = _map_->buffer[first].key; max_val = _map_->buffer[first].value; break; } } for (size_t i = first + 1; i < _map_->capacity; i++) { if (_map_->buffer[i].state == CMC_ES_FILLED) { if (_map_->f_key->cmp(_map_->buffer[i].key, max_key) > 0) { max_key = _map_->buffer[i].key; max_val = _map_->buffer[i].value; } } } if (key) *key = max_key; if (value) *value = max_val; if ((_map_)->callbacks && (_map_)->callbacks->read) (_map_)->callbacks->read();; return 1; } _Bool hm_min(struct hashmap * _map_, int32_t * key, int32_t * value) { if (hm_empty(_map_)) { _map_->flag = CMC_FLAG_EMPTY; return 0; } int32_t min_key = (int32_t) { 0 }; int32_t min_val = (int32_t) { 0 }; size_t first = 0; for (; first < _map_->capacity; first++) { if (_map_->buffer[first].state == CMC_ES_FILLED) { min_key = _map_->buffer[first].key; min_val = _map_->buffer[first].value; break; } } for (size_t i = first + 1; i < _map_->capacity; i++) { if (_map_->buffer[i].state == CMC_ES_FILLED) { if (_map_->f_key->cmp(_map_->buffer[i].key, min_key) < 0) { min_key = _map_->buffer[i].key; min_val = _map_->buffer[i].value; } } } if (key) *key = min_key; if (value) *value = min_val; if ((_map_)->callbacks && (_map_)->callbacks->read) (_map_)->callbacks->read();; return 1; } int32_t hm_get(struct hashmap * _map_, int32_t key) { if (hm_empty(_map_)) { _map_->flag = CMC_FLAG_EMPTY; return (int32_t){ 0 }; } struct hashmap_entry *entry = hm_impl_get_entry(_map_, key); if (!entry) { _map_->flag = CMC_FLAG_NOT_FOUND; return (int32_t){ 0 }; } _map_->flag = CMC_FLAG_OK; if ((_map_)->callbacks && (_map_)->callbacks->read) (_map_)->callbacks->read();; return entry->value; } int32_t *hm_get_ref(struct hashmap * _map_, int32_t key) { if (hm_empty(_map_)) { _map_->flag = CMC_FLAG_EMPTY; return ((void *)0); } struct hashmap_entry *entry = hm_impl_get_entry(_map_, key); if (!entry) { _map_->flag = CMC_FLAG_NOT_FOUND; return ((void *)0); } _map_->flag = CMC_FLAG_OK; if ((_map_)->callbacks && (_map_)->callbacks->read) (_map_)->callbacks->read();; return &(entry->value); } _Bool hm_contains(struct hashmap * _map_, int32_t key) { _map_->flag = CMC_FLAG_OK; _Bool result = hm_impl_get_entry(_map_, key) != ((void *)0); if ((_map_)->callbacks && (_map_)->callbacks->read) (_map_)->callbacks->read();; return result; } _Bool hm_empty(struct hashmap * _map_) { return _map_->count == 0; } _Bool hm_full(struct hashmap * _map_) { return (double)_map_->capacity * _map_->load <= (double)_map_->count; } size_t hm_count(struct hashmap * _map_) { return _map_->count; } size_t hm_capacity(struct hashmap * _map_) { return _map_->capacity; } double hm_load(struct hashmap * _map_) { return _map_->load; } int hm_flag(struct hashmap * _map_) { return _map_->flag; } _Bool hm_resize(struct hashmap * _map_, size_t capacity) { _map_->flag = CMC_FLAG_OK; if (_map_->capacity == capacity) goto success; if (_map_->capacity > capacity / _map_->load) goto success; if (capacity >= (18446744073709551615UL) * _map_->load) { _map_->flag = CMC_FLAG_ERROR; return 0; } size_t theoretical_size = hm_impl_calculate_size(capacity); if (theoretical_size < _map_->count / _map_->load) { _map_->flag = CMC_FLAG_INVALID; return 0; } struct hashmap *_new_map_ = hm_new_custom(capacity, _map_->load, _map_->f_key, _map_->f_val, _map_->alloc, ((void *)0)); if (!_new_map_) { _map_->flag = CMC_FLAG_ALLOC; return 0; } for (size_t i = 0; i < _map_->capacity; i++) { if (_map_->buffer[i].state == CMC_ES_FILLED) { int32_t key = _map_->buffer[i].key; int32_t value = _map_->buffer[i].value; hm_insert(_new_map_, key, value); } } if (_map_->count != _new_map_->count) { hm_free(_new_map_); _map_->flag = CMC_FLAG_ERROR; return 0; } struct hashmap_entry *tmp_b = _map_->buffer; _map_->buffer = _new_map_->buffer; _new_map_->buffer = tmp_b; size_t tmp_c = _map_->capacity; _map_->capacity = _new_map_->capacity; _new_map_->capacity = tmp_c; _new_map_->f_key = &(struct hashmap_fkey){ ((void *)0) }; _new_map_->f_val = &(struct hashmap_fval){ ((void *)0) }; hm_free(_new_map_); success: if ((_map_)->callbacks && (_map_)->callbacks->resize) (_map_)->callbacks->resize();; return 1; } struct hashmap *hm_copy_of(struct hashmap * _map_) { struct hashmap *result = hm_new_custom(_map_->capacity * _map_->load, _map_->load, _map_->f_key, _map_->f_val, _map_->alloc, ((void *)0)); if (!result) { _map_->flag = CMC_FLAG_ERROR; return ((void *)0); } (result)->callbacks = _map_->callbacks; if (_map_->f_key->cpy || _map_->f_val->cpy) { for (size_t i = 0; i < _map_->capacity; i++) { struct hashmap_entry *scan = &(_map_->buffer[i]); if (scan->state != CMC_ES_EMPTY) { struct hashmap_entry *target = &(result->buffer[i]); if (scan->state == CMC_ES_DELETED) target->state = CMC_ES_DELETED; else { target->state = scan->state; target->dist = scan->dist; if (_map_->f_key->cpy) target->key = _map_->f_key->cpy(scan->key); else target->key = scan->key; if (_map_->f_val->cpy) target->value = _map_->f_val->cpy(scan->value); else target->value = scan->value; } } } } else memcpy(result->buffer, _map_->buffer, sizeof(struct hashmap_entry) * _map_->capacity); result->count = _map_->count; _map_->flag = CMC_FLAG_OK; return result; } _Bool hm_equals(struct hashmap * _map1_, struct hashmap * _map2_) { _map1_->flag = CMC_FLAG_OK; _map2_->flag = CMC_FLAG_OK; if (_map1_->count != _map2_->count) return 0; struct hashmap *_map_a_; struct hashmap *_map_b_; _map_a_ = _map1_->capacity < _map2_->capacity ? _map1_ : _map2_; _map_b_ = _map_a_ == _map1_ ? _map2_ : _map1_; for (size_t i = 0; i < _map_a_->capacity; i++) { if (_map_a_->buffer[i].state == CMC_ES_FILLED) { struct hashmap_entry *entry_a = &(_map_a_->buffer[i]); struct hashmap_entry *entry_b = hm_impl_get_entry(_map_b_, entry_a->key); if (!entry_b) return 0; if (_map_a_->f_val->cmp(entry_a->value, entry_b->value) != 0) return 0; } } return 1; } static struct hashmap_entry * hm_impl_get_entry(struct hashmap * _map_, int32_t key) { size_t hash = _map_->f_key->hash(key); size_t pos = hash % _map_->capacity; struct hashmap_entry *target = &(_map_->buffer[pos]); while (target->state == CMC_ES_FILLED || target->state == CMC_ES_DELETED) { if (_map_->f_key->cmp(target->key, key) == 0) return target; pos++; target = &(_map_->buffer[pos % _map_->capacity]); } return ((void *)0); } static size_t hm_impl_calculate_size(size_t required) { const size_t count = sizeof(cmc_hashtable_primes) / sizeof(cmc_hashtable_primes[0]); if (cmc_hashtable_primes[count - 1] < required) return required; size_t i = 0; while (cmc_hashtable_primes[i] < required) i++; return cmc_hashtable_primes[i]; } struct hashmap hm_init(size_t capacity, double load, struct hashmap_fkey * f_key, struct hashmap_fval * f_val) { return hm_init_custom(capacity, load, f_key, f_val, ((void *)0), ((void *)0)); } struct hashmap hm_init_custom(size_t capacity, double load, struct hashmap_fkey * f_key, struct hashmap_fval * f_val, struct cmc_alloc_node * alloc, struct cmc_callbacks * callbacks) { ; struct hashmap _map_ = { 0 }; if (capacity == 0 || load <= 0 || load >= 1) return _map_; if (capacity >= (18446744073709551615UL) * load) return _map_; if (!f_key || !f_val) return _map_; size_t real_capacity = hm_impl_calculate_size(capacity / load); if (!alloc) alloc = &cmc_alloc_node_default; _map_.buffer = alloc->calloc(real_capacity, sizeof(struct hashmap_entry)); if (!_map_.buffer) return _map_; _map_.count = 0; _map_.capacity = real_capacity; _map_.load = load; _map_.flag = CMC_FLAG_OK; _map_.f_key = f_key; _map_.f_val = f_val; _map_.alloc = alloc; (&_map_)->callbacks = callbacks; return _map_; } void hm_release(struct hashmap _map_) { if (_map_.f_key->free || _map_.f_val->free) { for (size_t i = 0; i < _map_.capacity; i++) { struct hashmap_entry *entry = &(_map_.buffer[i]); if (entry->state == CMC_ES_FILLED) { if (_map_.f_key->free) _map_.f_key->free(entry->key); if (_map_.f_val->free) _map_.f_val->free(entry->value); } } } _map_.alloc->free(_map_.buffer); } struct hashmap_iter hm_iter_start(struct hashmap * target) { struct hashmap_iter iter; iter.target = target; iter.cursor = 0; iter.index = 0; iter.first = 0; iter.last = 0; iter.start = 1; iter.end = hm_empty(target); if (!hm_empty(target)) { for (size_t i = 0; i < target->capacity; i++) { if (target->buffer[i].state == CMC_ES_FILLED) { iter.first = i; break; } } iter.cursor = iter.first; for (size_t i = target->capacity; i > 0; i--) { if (target->buffer[i - 1].state == CMC_ES_FILLED) { iter.last = i - 1; break; } } } return iter; } struct hashmap_iter hm_iter_end(struct hashmap * target) { struct hashmap_iter iter; iter.target = target; iter.cursor = 0; iter.index = 0; iter.first = 0; iter.last = 0; iter.start = hm_empty(target); iter.end = 1; if (!hm_empty(target)) { for (size_t i = 0; i < target->capacity; i++) { if (target->buffer[i].state == CMC_ES_FILLED) { iter.first = i; break; } } for (size_t i = target->capacity; i > 0; i--) { if (target->buffer[i - 1].state == CMC_ES_FILLED) { iter.last = i - 1; break; } } iter.cursor = iter.last; iter.index = target->count - 1; } return iter; } _Bool hm_iter_at_start(struct hashmap_iter * iter) { return hm_empty(iter->target) || iter->start; } _Bool hm_iter_at_end(struct hashmap_iter * iter) { return hm_empty(iter->target) || iter->end; } _Bool hm_iter_to_start(struct hashmap_iter * iter) { if (!hm_empty(iter->target)) { iter->cursor = iter->first; iter->index = 0; iter->start = 1; iter->end = hm_empty(iter->target); return 1; } return 0; } _Bool hm_iter_to_end(struct hashmap_iter * iter) { if (!hm_empty(iter->target)) { iter->cursor = iter->last; iter->index = iter->target->count - 1; iter->start = hm_empty(iter->target); iter->end = 1; return 1; } return 0; } _Bool hm_iter_next(struct hashmap_iter * iter) { if (iter->end) return 0; if (iter->index + 1 == iter->target->count) { iter->end = 1; return 0; } iter->start = hm_empty(iter->target); struct hashmap_entry *scan = &(iter->target->buffer[iter->cursor]); iter->index++; while (1) { iter->cursor++; scan = &(iter->target->buffer[iter->cursor]); if (scan->state == CMC_ES_FILLED) break; } return 1; } _Bool hm_iter_prev(struct hashmap_iter * iter) { if (iter->start) return 0; if (iter->index == 0) { iter->start = 1; return 0; } iter->end = hm_empty(iter->target); struct hashmap_entry *scan = &(iter->target->buffer[iter->cursor]); iter->index--; while (1) { iter->cursor--; scan = &(iter->target->buffer[iter->cursor]); if (scan->state == CMC_ES_FILLED) break; } return 1; } _Bool hm_iter_advance(struct hashmap_iter * iter, size_t steps) { if (iter->end) return 0; if (iter->index + 1 == iter->target->count) { iter->end = 1; return 0; } if (steps == 0 || iter->index + steps >= iter->target->count) return 0; for (size_t i = 0; i < steps; i++) hm_iter_next(iter); return 1; } _Bool hm_iter_rewind(struct hashmap_iter * iter, size_t steps) { if (iter->start) return 0; if (iter->index == 0) { iter->start = 1; return 0; } if (steps == 0 || iter->index < steps) return 0; for (size_t i = 0; i < steps; i++) hm_iter_prev(iter); return 1; } _Bool hm_iter_go_to(struct hashmap_iter * iter, size_t index) { if (index >= iter->target->count) return 0; if (iter->index > index) return hm_iter_rewind(iter, iter->index - index); else if (iter->index < index) return hm_iter_advance(iter, index - iter->index); return 1; } int32_t hm_iter_key(struct hashmap_iter * iter) { if (hm_empty(iter->target)) return (int32_t){ 0 }; return iter->target->buffer[iter->cursor].key; } int32_t hm_iter_value(struct hashmap_iter * iter) { if (hm_empty(iter->target)) return (int32_t){ 0 }; return iter->target->buffer[iter->cursor].value; } int32_t *hm_iter_rvalue(struct hashmap_iter * iter) { if (hm_empty(iter->target)) return ((void *)0); return &(iter->target->buffer[iter->cursor].value); } size_t hm_iter_index(struct hashmap_iter * iter) { return iter->index; } _Bool hm_to_string(struct hashmap * _map_, FILE * fptr) { struct hashmap *m_ = _map_; return 0 <= fprintf(fptr, "struct %s<%s, %s> " "at %p { " "buffer:%p, " "capacity:%" "l" "u" ", " "count:%" "l" "u" ", " "load:%lf, " "flag:%d, " "f_key:%p, " "f_val:%p, " "alloc:%p, " "callbacks:%p }", "hashmap", "int32_t", "int32_t", m_, m_->buffer, m_->capacity, m_->count, m_->load, m_->flag, m_->f_key, m_->f_val, m_->alloc, (m_)->callbacks); } _Bool hm_print(struct hashmap * _map_, FILE * fptr, const char *start, const char *separator, const char *end, const char *key_val_sep) { fprintf(fptr, "%s", start); size_t last = 0; for (size_t i = _map_->capacity; i > 0; i--) { if ((_map_->buffer[i - 1]).state == CMC_ES_FILLED) { last = i - 1; break; } } for (size_t i = 0; i < _map_->capacity; i++) { struct hashmap_entry *entry = &(_map_->buffer[i]); if (entry->state == CMC_ES_FILLED) { if (!_map_->f_key->str(fptr, entry->key)) return 0; fprintf(fptr, "%s", key_val_sep); if (!_map_->f_val->str(fptr, entry->value)) return 0; if (i + 1 < last) fprintf(fptr, "%s", separator); } } fprintf(fptr, "%s", end); return 1; }

int main() {  
  int tests;
  scanf("%d", &tests);
  for (int i = 0; i < tests; ++i) {
    int32_t n;
    scanf("%"SCNd32, &n);
    char *s = (char*)malloc(n + 1);
    struct hashmap *sum_cnt = hm_new(1000, 0.9, 
    &(struct hashmap_fkey) {\
      .cmp = cmc_i32_cmp,
      .hash = cmc_i32_hash
    }, 
    &(struct hashmap_fval) {
      .cmp = cmc_i32_cmp
    });
    hm_insert(sum_cnt, 0, 1);
    scanf("%s", s);
    int32_t sum = 0;
    int64_t sol = 0;    
    for (int32_t i = 0; i < n; ++i) {
      sum += (s[i] - '0' - 1);
      int32_t *p = hm_get_ref(sum_cnt, sum);
      if (p) {
        sol += *p;
        ++(*p);
      } else {
        hm_insert(sum_cnt, sum, 1);
      }
    }
    printf("%"SCNd64"\n", sol);
    free(s);
    hm_free(sum_cnt);
  }
  return 0;
}