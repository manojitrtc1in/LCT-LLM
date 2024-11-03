

#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
#include <ctime>


namespace Blacher {


#include <immintrin.h>
#include <cstdint>
#include <algorithm>
#define _mm256_setr_epi32(__A, __B, __C, __D, __E, __F, __G, __H) __extension__ (__m256i)(__v8si) {__A, __B, __C, __D, __E, __F, __G, __H}




namespace avx2{
namespace _internal {

#define LOAD_VECTOR(arr) _mm256_loadu_si256(reinterpret_cast<__m256i *>(arr))
#define STORE_VECTOR(arr, vec)           \
  _mm256_storeu_si256(reinterpret_cast<__m256i *>(arr), vec)




#define COEX(a, b){           \
    auto vec_tmp = a;                  \
    a = _mm256_min_epi32(a, b);        \
    b = _mm256_max_epi32(vec_tmp, b);}


#define SHUFFLE_2_VECS(a, b, mask)                                       \
    _mm256_castps_si256 (_mm256_shuffle_ps(                         \
        _mm256_castsi256_ps (a), _mm256_castsi256_ps (b), mask));


inline void sort_16(__m256i &v1, __m256i &v2) {
  COEX(v1, v2);                                  

  v2 = _mm256_shuffle_epi32(v2, _MM_SHUFFLE(2, 3, 0, 1)); 
  COEX(v1, v2);

  auto tmp = v1;  
  v1 = SHUFFLE_2_VECS(v1, v2, 0b10001000);
  v2 = SHUFFLE_2_VECS(tmp, v2, 0b11011101);
  COEX(v1, v2);

  v2 = _mm256_shuffle_epi32(v2, _MM_SHUFFLE(0, 1, 2, 3)); 
  COEX(v1, v2);

  tmp = v1;       
  v1 = SHUFFLE_2_VECS(v1, v2, 0b01000100);
  v2 = SHUFFLE_2_VECS(tmp, v2, 0b11101110);
  COEX(v1, v2);

  tmp = v1;       
  v1 = SHUFFLE_2_VECS(v1, v2, 0b11011000);
  v2 = SHUFFLE_2_VECS(tmp, v2, 0b10001101);
  COEX(v1, v2);

  v2 = _mm256_permutevar8x32_epi32(v2, _mm256_setr_epi32(7,6,5,4,3,2,1,0));
  COEX(v1, v2);   

  tmp = v1;       
  v1 = SHUFFLE_2_VECS(v1, v2, 0b11011000);
  v2 = SHUFFLE_2_VECS(tmp, v2, 0b10001101);
  COEX(v1, v2);

  tmp = v1;       
  v1 = SHUFFLE_2_VECS(v1, v2, 0b11011000);
  v2 = SHUFFLE_2_VECS(tmp, v2, 0b10001101);
  COEX(v1, v2);

  
  v1 = _mm256_permutevar8x32_epi32(v1, _mm256_setr_epi32(0,4,1,5,6,2,7,3));
  v2 = _mm256_permutevar8x32_epi32(v2, _mm256_setr_epi32(0,4,1,5,6,2,7,3));

  tmp = v1;      
  v1 = SHUFFLE_2_VECS(v1, v2, 0b10001000);
  v2 = SHUFFLE_2_VECS(tmp, v2, 0b11011101);
  COEX(v1, v2);

  
  auto b2 = _mm256_shuffle_epi32(v2,0b10110001);
  auto b1 = _mm256_shuffle_epi32(v1,0b10110001);
  v1 = _mm256_blend_epi32(v1, b2, 0b10101010);
  v2 = _mm256_blend_epi32(b1, v2, 0b10101010);
}

#define ASC(a, b, c, d, e, f, g, h)                                    \
  (((h < 7) << 7) | ((g < 6) << 6) | ((f < 5) << 5) | ((e < 4) << 4) | \
      ((d < 3) << 3) | ((c < 2) << 2) | ((b < 1) << 1) | (a < 0))

#define COEX_PERMUTE(vec, a, b, c, d, e, f, g, h, MASK){               \
    __m256i permute_mask = _mm256_setr_epi32(a, b, c, d, e, f, g, h);  \
    __m256i permuted = _mm256_permutevar8x32_epi32(vec, permute_mask); \
    __m256i min = _mm256_min_epi32(permuted, vec);                     \
    __m256i max = _mm256_max_epi32(permuted, vec);                     \
    constexpr int blend_mask = MASK(a, b, c, d, e, f, g, h);           \
    vec = _mm256_blend_epi32(min, max, blend_mask);}

#define COEX_SHUFFLE(vec, a, b, c, d, e, f, g, h, MASK){               \
    constexpr int shuffle_mask = _MM_SHUFFLE(d, c, b, a);              \
    __m256i shuffled = _mm256_shuffle_epi32(vec, shuffle_mask);        \
    __m256i min = _mm256_min_epi32(shuffled, vec);                     \
    __m256i max = _mm256_max_epi32(shuffled, vec);                     \
    constexpr int blend_mask = MASK(a, b, c, d, e, f, g, h);           \
    vec = _mm256_blend_epi32(min, max, blend_mask);}

#define REVERSE_VEC(vec){      \
    vec = _mm256_permutevar8x32_epi32(                                 \
        vec, _mm256_setr_epi32(7, 6, 5, 4, 3, 2, 1, 0));}


#define SORT_8(vec){           \
  COEX_SHUFFLE(vec, 1, 0, 3, 2, 5, 4, 7, 6, ASC);                           \
  COEX_SHUFFLE(vec, 2, 3, 0, 1, 6, 7, 4, 5, ASC);                           \
  COEX_SHUFFLE(vec, 0, 2, 1, 3, 4, 6, 5, 7, ASC);                           \
  COEX_PERMUTE(vec, 7, 6, 5, 4, 3, 2, 1, 0, ASC);                           \
  COEX_SHUFFLE(vec, 2, 3, 0, 1, 6, 7, 4, 5, ASC);                           \
  COEX_SHUFFLE(vec, 1, 0, 3, 2, 5, 4, 7, 6, ASC);}


inline void bitonic_merge_16(__m256i *vecs, const int N, const int s = 2) {
  for (int t = s * 2; t < 2 * N; t *= 2) {
    for (int l = 0; l < N; l += t) {
      for (int j = std::max(l + t - N, 0); j < t/2 ; j += 2) {
        REVERSE_VEC(vecs[l + t - 1 - j]);
        REVERSE_VEC(vecs[l + t - 2 - j]);
        COEX(vecs[l + j], vecs[l + t - 1 - j]);
        COEX(vecs[l + j + 1], vecs[l + t - 2 - j]); }}
    for (int m = t / 2; m > 4; m /= 2) {
      for (int k = 0; k < N - m / 2; k += m) {
        const int bound = std::min((k + m / 2), N - (m / 2));
        for (int j = k; j < bound; j += 2) {
          COEX(vecs[j], vecs[m / 2 + j]);
          COEX(vecs[j + 1], vecs[m / 2 + j + 1]); }}}
    for (int j = 0; j < N-2; j += 4) {
      COEX(vecs[j], vecs[j + 2]);
      COEX(vecs[j + 1], vecs[j + 3]);
    }
    for (int j = 0; j < N; j += 2) {
      COEX(vecs[j], vecs[j + 1]); }
    for (int i = 0; i < N; i += 2) {
      COEX_PERMUTE(vecs[i], 4, 5, 6, 7, 0, 1, 2, 3, ASC);
      COEX_PERMUTE(vecs[i + 1], 4, 5, 6, 7, 0, 1, 2, 3, ASC);
      auto tmp = vecs[i];
      vecs[i] = _mm256_unpacklo_epi32(vecs[i], vecs[i + 1]);
      vecs[i + 1] = _mm256_unpackhi_epi32(tmp, vecs[i + 1]);
      COEX(vecs[i], vecs[i + 1]);
      tmp = vecs[i];
      vecs[i] = _mm256_unpacklo_epi32(vecs[i], vecs[i + 1]);
      vecs[i + 1] = _mm256_unpackhi_epi32(tmp, vecs[i + 1]);
      COEX(vecs[i], vecs[i + 1]);
      tmp = vecs[i];
      vecs[i] = _mm256_unpacklo_epi32(vecs[i], vecs[i + 1]);
      vecs[i + 1] = _mm256_unpackhi_epi32(tmp, vecs[i + 1]); }}}

inline void bitonic_merge_128(__m256i *vecs, const int N, const int s = 16) {
  const int remainder16 = N - N % 16;
  const int remainder8 = N - N % 8;
  for (int t = s * 2; t < 2 * N; t *= 2) {
    for (int l = 0; l < N; l += t) {
      for (int j = std::max(l + t - N, 0); j < t/2 ; j += 2) {
        REVERSE_VEC(vecs[l + t - 1 - j]);
        REVERSE_VEC(vecs[l + t - 2 - j]);
        COEX(vecs[l + j], vecs[l + t - 1 - j]);
        COEX(vecs[l + j + 1], vecs[l + t - 2 - j]); }}
    for (int m = t / 2; m > 16; m /= 2) {
      for (int k = 0; k < N - m / 2; k += m) {
        const int bound = std::min((k + m / 2), N - (m / 2));
        for (int j = k; j < bound; j += 2) {
          COEX(vecs[j], vecs[m / 2 + j]);
          COEX(vecs[j + 1], vecs[m / 2 + j + 1]); }}}
    for (int j = 0; j < remainder16; j += 16) {
      COEX(vecs[j], vecs[j + 8]);
      COEX(vecs[j + 1], vecs[j + 9]);
      COEX(vecs[j + 2], vecs[j + 10]);
      COEX(vecs[j + 3], vecs[j + 11]);
      COEX(vecs[j + 4], vecs[j + 12]);
      COEX(vecs[j + 5], vecs[j + 13]);
      COEX(vecs[j + 6], vecs[j + 14]);
      COEX(vecs[j + 7], vecs[j + 15]);
    }
    for (int j = remainder16 + 8; j < N; j += 1) {
      COEX(vecs[j - 8], vecs[j]);
    }
    for (int j = 0; j < remainder8; j += 8) {
      COEX(vecs[j], vecs[j + 4]);
      COEX(vecs[j + 1], vecs[j + 5]);
      COEX(vecs[j + 2], vecs[j + 6]);
      COEX(vecs[j + 3], vecs[j + 7]);
    }
    for (int j = remainder8 + 4; j < N; j += 1) {
      COEX(vecs[j - 4], vecs[j]);
    }
    for (int j = 0; j < N-2; j += 4) {
      COEX(vecs[j], vecs[j + 2]);
      COEX(vecs[j + 1], vecs[j + 3]);
    }
    for (int j = 0; j < N; j += 2) {
      COEX(vecs[j], vecs[j + 1]); }
    for (int i = 0; i < N; i += 2) {
      COEX_PERMUTE(vecs[i], 4, 5, 6, 7, 0, 1, 2, 3, ASC);
      COEX_PERMUTE(vecs[i + 1], 4, 5, 6, 7, 0, 1, 2, 3, ASC);
      auto tmp = vecs[i];
      vecs[i] = _mm256_unpacklo_epi32(vecs[i], vecs[i + 1]);
      vecs[i + 1] = _mm256_unpackhi_epi32(tmp, vecs[i + 1]);
      COEX(vecs[i], vecs[i + 1]);
      tmp = vecs[i];
      vecs[i] = _mm256_unpacklo_epi32(vecs[i], vecs[i + 1]);
      vecs[i + 1] = _mm256_unpackhi_epi32(tmp, vecs[i + 1]);
      COEX(vecs[i], vecs[i + 1]);
      tmp = vecs[i];
      vecs[i] = _mm256_unpacklo_epi32(vecs[i], vecs[i + 1]);
      vecs[i + 1] = _mm256_unpackhi_epi32(tmp, vecs[i + 1]); }}}


inline void sort_16_int_vertical(__m256i* vecs){
  COEX(vecs[0], vecs[1]); COEX(vecs[2], vecs[3]);  
  COEX(vecs[4], vecs[5]); COEX(vecs[6], vecs[7]);
  COEX(vecs[8], vecs[9]); COEX(vecs[10], vecs[11])
  COEX(vecs[12], vecs[13]); COEX(vecs[14], vecs[15])
  COEX(vecs[0], vecs[2]); COEX(vecs[1], vecs[3]);  
  COEX(vecs[4], vecs[6]); COEX(vecs[5], vecs[7]);
  COEX(vecs[8], vecs[10]); COEX(vecs[9], vecs[11]);
  COEX(vecs[12], vecs[14]); COEX(vecs[13], vecs[15]);
  COEX(vecs[0], vecs[4]); COEX(vecs[1], vecs[5]);  
  COEX(vecs[2], vecs[6]); COEX(vecs[3], vecs[7]);
  COEX(vecs[8], vecs[12]); COEX(vecs[9], vecs[13]);
  COEX(vecs[10], vecs[14]); COEX(vecs[11], vecs[15]);
  COEX(vecs[0], vecs[8]); COEX(vecs[1], vecs[9])   
  COEX(vecs[2], vecs[10]); COEX(vecs[3], vecs[11])
  COEX(vecs[4], vecs[12]); COEX(vecs[5], vecs[13])
  COEX(vecs[6], vecs[14]); COEX(vecs[7], vecs[15])
  COEX(vecs[5], vecs[10]); COEX(vecs[6], vecs[9]); 
  COEX(vecs[3], vecs[12]); COEX(vecs[7], vecs[11]);
  COEX(vecs[13], vecs[14]); COEX(vecs[4], vecs[8]);
  COEX(vecs[1], vecs[2]);
  COEX(vecs[1], vecs[4]); COEX(vecs[7], vecs[13]); 
  COEX(vecs[2], vecs[8]); COEX(vecs[11], vecs[14]);
  COEX(vecs[2], vecs[4]); COEX(vecs[5], vecs[6]);  
  COEX(vecs[9], vecs[10]); COEX(vecs[11], vecs[13]);
  COEX(vecs[3], vecs[8]); COEX(vecs[7], vecs[12]);
  COEX(vecs[3], vecs[5]); COEX(vecs[6], vecs[8]);  
  COEX(vecs[7], vecs[9]); COEX(vecs[10], vecs[12]);
  COEX(vecs[3], vecs[4]); COEX(vecs[5], vecs[6]);  
  COEX(vecs[7], vecs[8]); COEX(vecs[9], vecs[10]);
  COEX(vecs[11], vecs[12]);
  COEX(vecs[6], vecs[7]); COEX(vecs[8], vecs[9]); }


void inline merge_8_columns_with_16_elements(__m256i* vecs){
  vecs[8] = _mm256_shuffle_epi32(vecs[8], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[7], vecs[8]);
  vecs[9] = _mm256_shuffle_epi32(vecs[9], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[6], vecs[9]);
  vecs[10] = _mm256_shuffle_epi32(vecs[10], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[5], vecs[10]);
  vecs[11] = _mm256_shuffle_epi32(vecs[11], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[4], vecs[11]);
  vecs[12] = _mm256_shuffle_epi32(vecs[12], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[3], vecs[12]);
  vecs[13] = _mm256_shuffle_epi32(vecs[13], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[2], vecs[13]);
  vecs[14] = _mm256_shuffle_epi32(vecs[14], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[1], vecs[14]);
  vecs[15] = _mm256_shuffle_epi32(vecs[15], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[0], vecs[15]);
  vecs[4] = _mm256_shuffle_epi32(vecs[4], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[3], vecs[4]);
  vecs[5] = _mm256_shuffle_epi32(vecs[5], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[2], vecs[5]);
  vecs[6] = _mm256_shuffle_epi32(vecs[6], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[1], vecs[6]);
  vecs[7] = _mm256_shuffle_epi32(vecs[7], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[0], vecs[7]);
  vecs[12] = _mm256_shuffle_epi32(vecs[12], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[11], vecs[12]);
  vecs[13] = _mm256_shuffle_epi32(vecs[13], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[10], vecs[13]);
  vecs[14] = _mm256_shuffle_epi32(vecs[14], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[9], vecs[14]);
  vecs[15] = _mm256_shuffle_epi32(vecs[15], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[8], vecs[15]);
  vecs[2] = _mm256_shuffle_epi32(vecs[2], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[1], vecs[2]);
  vecs[3] = _mm256_shuffle_epi32(vecs[3], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[0], vecs[3]);
  vecs[6] = _mm256_shuffle_epi32(vecs[6], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[5], vecs[6]);
  vecs[7] = _mm256_shuffle_epi32(vecs[7], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[4], vecs[7]);
  vecs[10] = _mm256_shuffle_epi32(vecs[10], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[9], vecs[10]);
  vecs[11] = _mm256_shuffle_epi32(vecs[11], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[8], vecs[11]);
  vecs[14] = _mm256_shuffle_epi32(vecs[14], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[13], vecs[14]);
  vecs[15] = _mm256_shuffle_epi32(vecs[15], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[12], vecs[15]);
  vecs[1] = _mm256_shuffle_epi32(vecs[1], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[0], vecs[1]);
  vecs[3] = _mm256_shuffle_epi32(vecs[3], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[2], vecs[3]);
  vecs[5] = _mm256_shuffle_epi32(vecs[5], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[4], vecs[5]);
  vecs[7] = _mm256_shuffle_epi32(vecs[7], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[6], vecs[7]);
  vecs[9] = _mm256_shuffle_epi32(vecs[9], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[8], vecs[9]);
  vecs[11] = _mm256_shuffle_epi32(vecs[11], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[10], vecs[11]);
  vecs[13] = _mm256_shuffle_epi32(vecs[13], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[12], vecs[13]);
  vecs[15] = _mm256_shuffle_epi32(vecs[15], _MM_SHUFFLE(2,3,0,1)); COEX(vecs[14], vecs[15]);
  COEX_SHUFFLE(vecs[0], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_SHUFFLE(vecs[1], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[2], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_SHUFFLE(vecs[3], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[4], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_SHUFFLE(vecs[5], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[6], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_SHUFFLE(vecs[7], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[8], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_SHUFFLE(vecs[9], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[10], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_SHUFFLE(vecs[11], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[12], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_SHUFFLE(vecs[13], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[14], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_SHUFFLE(vecs[15], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  vecs[8] = _mm256_shuffle_epi32(vecs[8], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[7], vecs[8]);
  vecs[9] = _mm256_shuffle_epi32(vecs[9], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[6], vecs[9]);
  vecs[10] = _mm256_shuffle_epi32(vecs[10], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[5], vecs[10]);
  vecs[11] = _mm256_shuffle_epi32(vecs[11], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[4], vecs[11]);
  vecs[12] = _mm256_shuffle_epi32(vecs[12], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[3], vecs[12]);
  vecs[13] = _mm256_shuffle_epi32(vecs[13], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[2], vecs[13]);
  vecs[14] = _mm256_shuffle_epi32(vecs[14], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[1], vecs[14]);
  vecs[15] = _mm256_shuffle_epi32(vecs[15], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[0], vecs[15]);
  vecs[4] = _mm256_shuffle_epi32(vecs[4], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[3], vecs[4]);
  vecs[5] = _mm256_shuffle_epi32(vecs[5], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[2], vecs[5]);
  vecs[6] = _mm256_shuffle_epi32(vecs[6], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[1], vecs[6]);
  vecs[7] = _mm256_shuffle_epi32(vecs[7], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[0], vecs[7]);
  vecs[12] = _mm256_shuffle_epi32(vecs[12], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[11], vecs[12]);
  vecs[13] = _mm256_shuffle_epi32(vecs[13], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[10], vecs[13]);
  vecs[14] = _mm256_shuffle_epi32(vecs[14], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[9], vecs[14]);
  vecs[15] = _mm256_shuffle_epi32(vecs[15], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[8], vecs[15]);
  vecs[2] = _mm256_shuffle_epi32(vecs[2], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[1], vecs[2]);
  vecs[3] = _mm256_shuffle_epi32(vecs[3], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[0], vecs[3]);
  vecs[6] = _mm256_shuffle_epi32(vecs[6], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[5], vecs[6]);
  vecs[7] = _mm256_shuffle_epi32(vecs[7], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[4], vecs[7]);
  vecs[10] = _mm256_shuffle_epi32(vecs[10], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[9], vecs[10]);
  vecs[11] = _mm256_shuffle_epi32(vecs[11], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[8], vecs[11]);
  vecs[14] = _mm256_shuffle_epi32(vecs[14], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[13], vecs[14]);
  vecs[15] = _mm256_shuffle_epi32(vecs[15], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[12], vecs[15]);
  vecs[1] = _mm256_shuffle_epi32(vecs[1], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[0], vecs[1]);
  vecs[3] = _mm256_shuffle_epi32(vecs[3], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[2], vecs[3]);
  vecs[5] = _mm256_shuffle_epi32(vecs[5], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[4], vecs[5]);
  vecs[7] = _mm256_shuffle_epi32(vecs[7], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[6], vecs[7]);
  vecs[9] = _mm256_shuffle_epi32(vecs[9], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[8], vecs[9]);
  vecs[11] = _mm256_shuffle_epi32(vecs[11], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[10], vecs[11]);
  vecs[13] = _mm256_shuffle_epi32(vecs[13], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[12], vecs[13]);
  vecs[15] = _mm256_shuffle_epi32(vecs[15], _MM_SHUFFLE(0,1,2,3)); COEX(vecs[14], vecs[15]);
  COEX_SHUFFLE(vecs[0], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[0], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[1], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[1], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[2], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[2], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[3], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[3], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[4], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[4], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[5], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[5], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[6], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[6], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[7], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[7], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[8], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[8], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[9], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[9], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[10], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[10], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[11], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[11], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[12], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[12], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[13], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[13], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[14], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[14], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_SHUFFLE(vecs[15], 3, 2, 1, 0, 7, 6, 5, 4, ASC); COEX_SHUFFLE(vecs[15], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  REVERSE_VEC(vecs[8]); COEX(vecs[7], vecs[8]); REVERSE_VEC(vecs[9]); COEX(vecs[6], vecs[9]);
  REVERSE_VEC(vecs[10]); COEX(vecs[5], vecs[10]); REVERSE_VEC(vecs[11]); COEX(vecs[4], vecs[11]);
  REVERSE_VEC(vecs[12]); COEX(vecs[3], vecs[12]); REVERSE_VEC(vecs[13]); COEX(vecs[2], vecs[13]);
  REVERSE_VEC(vecs[14]); COEX(vecs[1], vecs[14]); REVERSE_VEC(vecs[15]); COEX(vecs[0], vecs[15]);
  REVERSE_VEC(vecs[4]); COEX(vecs[3], vecs[4]); REVERSE_VEC(vecs[5]); COEX(vecs[2], vecs[5]);
  REVERSE_VEC(vecs[6]); COEX(vecs[1], vecs[6]); REVERSE_VEC(vecs[7]); COEX(vecs[0], vecs[7]);
  REVERSE_VEC(vecs[12]); COEX(vecs[11], vecs[12]); REVERSE_VEC(vecs[13]); COEX(vecs[10], vecs[13]);
  REVERSE_VEC(vecs[14]); COEX(vecs[9], vecs[14]); REVERSE_VEC(vecs[15]); COEX(vecs[8], vecs[15]);
  REVERSE_VEC(vecs[2]); COEX(vecs[1], vecs[2]); REVERSE_VEC(vecs[3]); COEX(vecs[0], vecs[3]);
  REVERSE_VEC(vecs[6]); COEX(vecs[5], vecs[6]); REVERSE_VEC(vecs[7]); COEX(vecs[4], vecs[7]);
  REVERSE_VEC(vecs[10]); COEX(vecs[9], vecs[10]); REVERSE_VEC(vecs[11]); COEX(vecs[8], vecs[11]);
  REVERSE_VEC(vecs[14]); COEX(vecs[13], vecs[14]); REVERSE_VEC(vecs[15]); COEX(vecs[12], vecs[15]);
  REVERSE_VEC(vecs[1]); COEX(vecs[0], vecs[1]); REVERSE_VEC(vecs[3]); COEX(vecs[2], vecs[3]);
  REVERSE_VEC(vecs[5]); COEX(vecs[4], vecs[5]); REVERSE_VEC(vecs[7]); COEX(vecs[6], vecs[7]);
  REVERSE_VEC(vecs[9]); COEX(vecs[8], vecs[9]); REVERSE_VEC(vecs[11]); COEX(vecs[10], vecs[11]);
  REVERSE_VEC(vecs[13]); COEX(vecs[12], vecs[13]); REVERSE_VEC(vecs[15]); COEX(vecs[14], vecs[15]);
  COEX_PERMUTE(vecs[0], 7, 6, 5, 4, 3, 2, 1, 0, ASC); COEX_SHUFFLE(vecs[0], 2, 3, 0, 1, 6, 7, 4, 5, ASC);
  COEX_SHUFFLE(vecs[0], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_PERMUTE(vecs[1], 7, 6, 5, 4, 3, 2, 1, 0, ASC);
  COEX_SHUFFLE(vecs[1], 2, 3, 0, 1, 6, 7, 4, 5, ASC); COEX_SHUFFLE(vecs[1], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_PERMUTE(vecs[2], 7, 6, 5, 4, 3, 2, 1, 0, ASC); COEX_SHUFFLE(vecs[2], 2, 3, 0, 1, 6, 7, 4, 5, ASC);
  COEX_SHUFFLE(vecs[2], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_PERMUTE(vecs[3], 7, 6, 5, 4, 3, 2, 1, 0, ASC);
  COEX_SHUFFLE(vecs[3], 2, 3, 0, 1, 6, 7, 4, 5, ASC); COEX_SHUFFLE(vecs[3], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_PERMUTE(vecs[4], 7, 6, 5, 4, 3, 2, 1, 0, ASC); COEX_SHUFFLE(vecs[4], 2, 3, 0, 1, 6, 7, 4, 5, ASC);
  COEX_SHUFFLE(vecs[4], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_PERMUTE(vecs[5], 7, 6, 5, 4, 3, 2, 1, 0, ASC);
  COEX_SHUFFLE(vecs[5], 2, 3, 0, 1, 6, 7, 4, 5, ASC); COEX_SHUFFLE(vecs[5], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_PERMUTE(vecs[6], 7, 6, 5, 4, 3, 2, 1, 0, ASC); COEX_SHUFFLE(vecs[6], 2, 3, 0, 1, 6, 7, 4, 5, ASC);
  COEX_SHUFFLE(vecs[6], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_PERMUTE(vecs[7], 7, 6, 5, 4, 3, 2, 1, 0, ASC);
  COEX_SHUFFLE(vecs[7], 2, 3, 0, 1, 6, 7, 4, 5, ASC); COEX_SHUFFLE(vecs[7], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_PERMUTE(vecs[8], 7, 6, 5, 4, 3, 2, 1, 0, ASC); COEX_SHUFFLE(vecs[8], 2, 3, 0, 1, 6, 7, 4, 5, ASC);
  COEX_SHUFFLE(vecs[8], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_PERMUTE(vecs[9], 7, 6, 5, 4, 3, 2, 1, 0, ASC);
  COEX_SHUFFLE(vecs[9], 2, 3, 0, 1, 6, 7, 4, 5, ASC); COEX_SHUFFLE(vecs[9], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_PERMUTE(vecs[10], 7, 6, 5, 4, 3, 2, 1, 0, ASC); COEX_SHUFFLE(vecs[10], 2, 3, 0, 1, 6, 7, 4, 5, ASC);
  COEX_SHUFFLE(vecs[10], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_PERMUTE(vecs[11], 7, 6, 5, 4, 3, 2, 1, 0, ASC);
  COEX_SHUFFLE(vecs[11], 2, 3, 0, 1, 6, 7, 4, 5, ASC); COEX_SHUFFLE(vecs[11], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_PERMUTE(vecs[12], 7, 6, 5, 4, 3, 2, 1, 0, ASC); COEX_SHUFFLE(vecs[12], 2, 3, 0, 1, 6, 7, 4, 5, ASC);
  COEX_SHUFFLE(vecs[12], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_PERMUTE(vecs[13], 7, 6, 5, 4, 3, 2, 1, 0, ASC);
  COEX_SHUFFLE(vecs[13], 2, 3, 0, 1, 6, 7, 4, 5, ASC); COEX_SHUFFLE(vecs[13], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
  COEX_PERMUTE(vecs[14], 7, 6, 5, 4, 3, 2, 1, 0, ASC); COEX_SHUFFLE(vecs[14], 2, 3, 0, 1, 6, 7, 4, 5, ASC);
  COEX_SHUFFLE(vecs[14], 1, 0, 3, 2, 5, 4, 7, 6, ASC); COEX_PERMUTE(vecs[15], 7, 6, 5, 4, 3, 2, 1, 0, ASC);
  COEX_SHUFFLE(vecs[15], 2, 3, 0, 1, 6, 7, 4, 5, ASC); COEX_SHUFFLE(vecs[15], 1, 0, 3, 2, 5, 4, 7, 6, ASC);
}

inline void sort_int_sorting_network(int *arr, int *buff, int n) {
  if(n < 2) return;
  __m256i *buffer = reinterpret_cast<__m256i *>(buff);

  const auto remainder = int(n % 8 ? n % 8 : 8);
  const int idx_max_pad = n - remainder;
  const auto mask = _mm256_add_epi32(_mm256_set1_epi32(-remainder), _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7));
  auto max_pad_vec = _mm256_blendv_epi8(_mm256_set1_epi32(INT32_MAX),_mm256_maskload_epi32(arr + idx_max_pad, mask), mask);

  for (int i = 0; i < idx_max_pad / 8; ++i) {
    buffer[i] = LOAD_VECTOR(arr + i * 8);
  }
  buffer[idx_max_pad / 8] = max_pad_vec;
  buffer[idx_max_pad / 8 + 1] = _mm256_set1_epi32(INT32_MAX);

  const int N = ((idx_max_pad % 16 == 0) * 8 + idx_max_pad + 8) / 8;

  for (int j = 0; j < N - N % 16; j += 16) {
    sort_16_int_vertical(buffer + j);
    merge_8_columns_with_16_elements(buffer + j);
  }
  for (int i = N - N % 16; i < N; i += 2) {
    sort_16(buffer[i], buffer[i + 1]);
  }
  bitonic_merge_16(buffer + N - N % 16, N % 16, 2);
  bitonic_merge_128(buffer, N, 16);
  for (int i = 0; i < idx_max_pad / 8; i += 1) {
    STORE_VECTOR(arr + i * 8, buffer[i]);
  }
  _mm256_maskstore_epi32(arr + idx_max_pad, mask, buffer[idx_max_pad / 8]);
}





const __m256i permutation_masks[256] = {_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 0),
_mm256_setr_epi32(0, 2, 3, 4, 5, 6, 7, 1),
_mm256_setr_epi32(2, 3, 4, 5, 6, 7, 0, 1),
_mm256_setr_epi32(0, 1, 3, 4, 5, 6, 7, 2),
_mm256_setr_epi32(1, 3, 4, 5, 6, 7, 0, 2),
_mm256_setr_epi32(0, 3, 4, 5, 6, 7, 1, 2),
_mm256_setr_epi32(3, 4, 5, 6, 7, 0, 1, 2),
_mm256_setr_epi32(0, 1, 2, 4, 5, 6, 7, 3),
_mm256_setr_epi32(1, 2, 4, 5, 6, 7, 0, 3),
_mm256_setr_epi32(0, 2, 4, 5, 6, 7, 1, 3),
_mm256_setr_epi32(2, 4, 5, 6, 7, 0, 1, 3),
_mm256_setr_epi32(0, 1, 4, 5, 6, 7, 2, 3),
_mm256_setr_epi32(1, 4, 5, 6, 7, 0, 2, 3),
_mm256_setr_epi32(0, 4, 5, 6, 7, 1, 2, 3),
_mm256_setr_epi32(4, 5, 6, 7, 0, 1, 2, 3),
_mm256_setr_epi32(0, 1, 2, 3, 5, 6, 7, 4),
_mm256_setr_epi32(1, 2, 3, 5, 6, 7, 0, 4),
_mm256_setr_epi32(0, 2, 3, 5, 6, 7, 1, 4),
_mm256_setr_epi32(2, 3, 5, 6, 7, 0, 1, 4),
_mm256_setr_epi32(0, 1, 3, 5, 6, 7, 2, 4),
_mm256_setr_epi32(1, 3, 5, 6, 7, 0, 2, 4),
_mm256_setr_epi32(0, 3, 5, 6, 7, 1, 2, 4),
_mm256_setr_epi32(3, 5, 6, 7, 0, 1, 2, 4),
_mm256_setr_epi32(0, 1, 2, 5, 6, 7, 3, 4),
_mm256_setr_epi32(1, 2, 5, 6, 7, 0, 3, 4),
_mm256_setr_epi32(0, 2, 5, 6, 7, 1, 3, 4),
_mm256_setr_epi32(2, 5, 6, 7, 0, 1, 3, 4),
_mm256_setr_epi32(0, 1, 5, 6, 7, 2, 3, 4),
_mm256_setr_epi32(1, 5, 6, 7, 0, 2, 3, 4),
_mm256_setr_epi32(0, 5, 6, 7, 1, 2, 3, 4),
_mm256_setr_epi32(5, 6, 7, 0, 1, 2, 3, 4),
_mm256_setr_epi32(0, 1, 2, 3, 4, 6, 7, 5),
_mm256_setr_epi32(1, 2, 3, 4, 6, 7, 0, 5),
_mm256_setr_epi32(0, 2, 3, 4, 6, 7, 1, 5),
_mm256_setr_epi32(2, 3, 4, 6, 7, 0, 1, 5),
_mm256_setr_epi32(0, 1, 3, 4, 6, 7, 2, 5),
_mm256_setr_epi32(1, 3, 4, 6, 7, 0, 2, 5),
_mm256_setr_epi32(0, 3, 4, 6, 7, 1, 2, 5),
_mm256_setr_epi32(3, 4, 6, 7, 0, 1, 2, 5),
_mm256_setr_epi32(0, 1, 2, 4, 6, 7, 3, 5),
_mm256_setr_epi32(1, 2, 4, 6, 7, 0, 3, 5),
_mm256_setr_epi32(0, 2, 4, 6, 7, 1, 3, 5),
_mm256_setr_epi32(2, 4, 6, 7, 0, 1, 3, 5),
_mm256_setr_epi32(0, 1, 4, 6, 7, 2, 3, 5),
_mm256_setr_epi32(1, 4, 6, 7, 0, 2, 3, 5),
_mm256_setr_epi32(0, 4, 6, 7, 1, 2, 3, 5),
_mm256_setr_epi32(4, 6, 7, 0, 1, 2, 3, 5),
_mm256_setr_epi32(0, 1, 2, 3, 6, 7, 4, 5),
_mm256_setr_epi32(1, 2, 3, 6, 7, 0, 4, 5),
_mm256_setr_epi32(0, 2, 3, 6, 7, 1, 4, 5),
_mm256_setr_epi32(2, 3, 6, 7, 0, 1, 4, 5),
_mm256_setr_epi32(0, 1, 3, 6, 7, 2, 4, 5),
_mm256_setr_epi32(1, 3, 6, 7, 0, 2, 4, 5),
_mm256_setr_epi32(0, 3, 6, 7, 1, 2, 4, 5),
_mm256_setr_epi32(3, 6, 7, 0, 1, 2, 4, 5),
_mm256_setr_epi32(0, 1, 2, 6, 7, 3, 4, 5),
_mm256_setr_epi32(1, 2, 6, 7, 0, 3, 4, 5),
_mm256_setr_epi32(0, 2, 6, 7, 1, 3, 4, 5),
_mm256_setr_epi32(2, 6, 7, 0, 1, 3, 4, 5),
_mm256_setr_epi32(0, 1, 6, 7, 2, 3, 4, 5),
_mm256_setr_epi32(1, 6, 7, 0, 2, 3, 4, 5),
_mm256_setr_epi32(0, 6, 7, 1, 2, 3, 4, 5),
_mm256_setr_epi32(6, 7, 0, 1, 2, 3, 4, 5),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 7, 6),
_mm256_setr_epi32(1, 2, 3, 4, 5, 7, 0, 6),
_mm256_setr_epi32(0, 2, 3, 4, 5, 7, 1, 6),
_mm256_setr_epi32(2, 3, 4, 5, 7, 0, 1, 6),
_mm256_setr_epi32(0, 1, 3, 4, 5, 7, 2, 6),
_mm256_setr_epi32(1, 3, 4, 5, 7, 0, 2, 6),
_mm256_setr_epi32(0, 3, 4, 5, 7, 1, 2, 6),
_mm256_setr_epi32(3, 4, 5, 7, 0, 1, 2, 6),
_mm256_setr_epi32(0, 1, 2, 4, 5, 7, 3, 6),
_mm256_setr_epi32(1, 2, 4, 5, 7, 0, 3, 6),
_mm256_setr_epi32(0, 2, 4, 5, 7, 1, 3, 6),
_mm256_setr_epi32(2, 4, 5, 7, 0, 1, 3, 6),
_mm256_setr_epi32(0, 1, 4, 5, 7, 2, 3, 6),
_mm256_setr_epi32(1, 4, 5, 7, 0, 2, 3, 6),
_mm256_setr_epi32(0, 4, 5, 7, 1, 2, 3, 6),
_mm256_setr_epi32(4, 5, 7, 0, 1, 2, 3, 6),
_mm256_setr_epi32(0, 1, 2, 3, 5, 7, 4, 6),
_mm256_setr_epi32(1, 2, 3, 5, 7, 0, 4, 6),
_mm256_setr_epi32(0, 2, 3, 5, 7, 1, 4, 6),
_mm256_setr_epi32(2, 3, 5, 7, 0, 1, 4, 6),
_mm256_setr_epi32(0, 1, 3, 5, 7, 2, 4, 6),
_mm256_setr_epi32(1, 3, 5, 7, 0, 2, 4, 6),
_mm256_setr_epi32(0, 3, 5, 7, 1, 2, 4, 6),
_mm256_setr_epi32(3, 5, 7, 0, 1, 2, 4, 6),
_mm256_setr_epi32(0, 1, 2, 5, 7, 3, 4, 6),
_mm256_setr_epi32(1, 2, 5, 7, 0, 3, 4, 6),
_mm256_setr_epi32(0, 2, 5, 7, 1, 3, 4, 6),
_mm256_setr_epi32(2, 5, 7, 0, 1, 3, 4, 6),
_mm256_setr_epi32(0, 1, 5, 7, 2, 3, 4, 6),
_mm256_setr_epi32(1, 5, 7, 0, 2, 3, 4, 6),
_mm256_setr_epi32(0, 5, 7, 1, 2, 3, 4, 6),
_mm256_setr_epi32(5, 7, 0, 1, 2, 3, 4, 6),
_mm256_setr_epi32(0, 1, 2, 3, 4, 7, 5, 6),
_mm256_setr_epi32(1, 2, 3, 4, 7, 0, 5, 6),
_mm256_setr_epi32(0, 2, 3, 4, 7, 1, 5, 6),
_mm256_setr_epi32(2, 3, 4, 7, 0, 1, 5, 6),
_mm256_setr_epi32(0, 1, 3, 4, 7, 2, 5, 6),
_mm256_setr_epi32(1, 3, 4, 7, 0, 2, 5, 6),
_mm256_setr_epi32(0, 3, 4, 7, 1, 2, 5, 6),
_mm256_setr_epi32(3, 4, 7, 0, 1, 2, 5, 6),
_mm256_setr_epi32(0, 1, 2, 4, 7, 3, 5, 6),
_mm256_setr_epi32(1, 2, 4, 7, 0, 3, 5, 6),
_mm256_setr_epi32(0, 2, 4, 7, 1, 3, 5, 6),
_mm256_setr_epi32(2, 4, 7, 0, 1, 3, 5, 6),
_mm256_setr_epi32(0, 1, 4, 7, 2, 3, 5, 6),
_mm256_setr_epi32(1, 4, 7, 0, 2, 3, 5, 6),
_mm256_setr_epi32(0, 4, 7, 1, 2, 3, 5, 6),
_mm256_setr_epi32(4, 7, 0, 1, 2, 3, 5, 6),
_mm256_setr_epi32(0, 1, 2, 3, 7, 4, 5, 6),
_mm256_setr_epi32(1, 2, 3, 7, 0, 4, 5, 6),
_mm256_setr_epi32(0, 2, 3, 7, 1, 4, 5, 6),
_mm256_setr_epi32(2, 3, 7, 0, 1, 4, 5, 6),
_mm256_setr_epi32(0, 1, 3, 7, 2, 4, 5, 6),
_mm256_setr_epi32(1, 3, 7, 0, 2, 4, 5, 6),
_mm256_setr_epi32(0, 3, 7, 1, 2, 4, 5, 6),
_mm256_setr_epi32(3, 7, 0, 1, 2, 4, 5, 6),
_mm256_setr_epi32(0, 1, 2, 7, 3, 4, 5, 6),
_mm256_setr_epi32(1, 2, 7, 0, 3, 4, 5, 6),
_mm256_setr_epi32(0, 2, 7, 1, 3, 4, 5, 6),
_mm256_setr_epi32(2, 7, 0, 1, 3, 4, 5, 6),
_mm256_setr_epi32(0, 1, 7, 2, 3, 4, 5, 6),
_mm256_setr_epi32(1, 7, 0, 2, 3, 4, 5, 6),
_mm256_setr_epi32(0, 7, 1, 2, 3, 4, 5, 6),
_mm256_setr_epi32(7, 0, 1, 2, 3, 4, 5, 6),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(1, 2, 3, 4, 5, 6, 0, 7),
_mm256_setr_epi32(0, 2, 3, 4, 5, 6, 1, 7),
_mm256_setr_epi32(2, 3, 4, 5, 6, 0, 1, 7),
_mm256_setr_epi32(0, 1, 3, 4, 5, 6, 2, 7),
_mm256_setr_epi32(1, 3, 4, 5, 6, 0, 2, 7),
_mm256_setr_epi32(0, 3, 4, 5, 6, 1, 2, 7),
_mm256_setr_epi32(3, 4, 5, 6, 0, 1, 2, 7),
_mm256_setr_epi32(0, 1, 2, 4, 5, 6, 3, 7),
_mm256_setr_epi32(1, 2, 4, 5, 6, 0, 3, 7),
_mm256_setr_epi32(0, 2, 4, 5, 6, 1, 3, 7),
_mm256_setr_epi32(2, 4, 5, 6, 0, 1, 3, 7),
_mm256_setr_epi32(0, 1, 4, 5, 6, 2, 3, 7),
_mm256_setr_epi32(1, 4, 5, 6, 0, 2, 3, 7),
_mm256_setr_epi32(0, 4, 5, 6, 1, 2, 3, 7),
_mm256_setr_epi32(4, 5, 6, 0, 1, 2, 3, 7),
_mm256_setr_epi32(0, 1, 2, 3, 5, 6, 4, 7),
_mm256_setr_epi32(1, 2, 3, 5, 6, 0, 4, 7),
_mm256_setr_epi32(0, 2, 3, 5, 6, 1, 4, 7),
_mm256_setr_epi32(2, 3, 5, 6, 0, 1, 4, 7),
_mm256_setr_epi32(0, 1, 3, 5, 6, 2, 4, 7),
_mm256_setr_epi32(1, 3, 5, 6, 0, 2, 4, 7),
_mm256_setr_epi32(0, 3, 5, 6, 1, 2, 4, 7),
_mm256_setr_epi32(3, 5, 6, 0, 1, 2, 4, 7),
_mm256_setr_epi32(0, 1, 2, 5, 6, 3, 4, 7),
_mm256_setr_epi32(1, 2, 5, 6, 0, 3, 4, 7),
_mm256_setr_epi32(0, 2, 5, 6, 1, 3, 4, 7),
_mm256_setr_epi32(2, 5, 6, 0, 1, 3, 4, 7),
_mm256_setr_epi32(0, 1, 5, 6, 2, 3, 4, 7),
_mm256_setr_epi32(1, 5, 6, 0, 2, 3, 4, 7),
_mm256_setr_epi32(0, 5, 6, 1, 2, 3, 4, 7),
_mm256_setr_epi32(5, 6, 0, 1, 2, 3, 4, 7),
_mm256_setr_epi32(0, 1, 2, 3, 4, 6, 5, 7),
_mm256_setr_epi32(1, 2, 3, 4, 6, 0, 5, 7),
_mm256_setr_epi32(0, 2, 3, 4, 6, 1, 5, 7),
_mm256_setr_epi32(2, 3, 4, 6, 0, 1, 5, 7),
_mm256_setr_epi32(0, 1, 3, 4, 6, 2, 5, 7),
_mm256_setr_epi32(1, 3, 4, 6, 0, 2, 5, 7),
_mm256_setr_epi32(0, 3, 4, 6, 1, 2, 5, 7),
_mm256_setr_epi32(3, 4, 6, 0, 1, 2, 5, 7),
_mm256_setr_epi32(0, 1, 2, 4, 6, 3, 5, 7),
_mm256_setr_epi32(1, 2, 4, 6, 0, 3, 5, 7),
_mm256_setr_epi32(0, 2, 4, 6, 1, 3, 5, 7),
_mm256_setr_epi32(2, 4, 6, 0, 1, 3, 5, 7),
_mm256_setr_epi32(0, 1, 4, 6, 2, 3, 5, 7),
_mm256_setr_epi32(1, 4, 6, 0, 2, 3, 5, 7),
_mm256_setr_epi32(0, 4, 6, 1, 2, 3, 5, 7),
_mm256_setr_epi32(4, 6, 0, 1, 2, 3, 5, 7),
_mm256_setr_epi32(0, 1, 2, 3, 6, 4, 5, 7),
_mm256_setr_epi32(1, 2, 3, 6, 0, 4, 5, 7),
_mm256_setr_epi32(0, 2, 3, 6, 1, 4, 5, 7),
_mm256_setr_epi32(2, 3, 6, 0, 1, 4, 5, 7),
_mm256_setr_epi32(0, 1, 3, 6, 2, 4, 5, 7),
_mm256_setr_epi32(1, 3, 6, 0, 2, 4, 5, 7),
_mm256_setr_epi32(0, 3, 6, 1, 2, 4, 5, 7),
_mm256_setr_epi32(3, 6, 0, 1, 2, 4, 5, 7),
_mm256_setr_epi32(0, 1, 2, 6, 3, 4, 5, 7),
_mm256_setr_epi32(1, 2, 6, 0, 3, 4, 5, 7),
_mm256_setr_epi32(0, 2, 6, 1, 3, 4, 5, 7),
_mm256_setr_epi32(2, 6, 0, 1, 3, 4, 5, 7),
_mm256_setr_epi32(0, 1, 6, 2, 3, 4, 5, 7),
_mm256_setr_epi32(1, 6, 0, 2, 3, 4, 5, 7),
_mm256_setr_epi32(0, 6, 1, 2, 3, 4, 5, 7),
_mm256_setr_epi32(6, 0, 1, 2, 3, 4, 5, 7),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(1, 2, 3, 4, 5, 0, 6, 7),
_mm256_setr_epi32(0, 2, 3, 4, 5, 1, 6, 7),
_mm256_setr_epi32(2, 3, 4, 5, 0, 1, 6, 7),
_mm256_setr_epi32(0, 1, 3, 4, 5, 2, 6, 7),
_mm256_setr_epi32(1, 3, 4, 5, 0, 2, 6, 7),
_mm256_setr_epi32(0, 3, 4, 5, 1, 2, 6, 7),
_mm256_setr_epi32(3, 4, 5, 0, 1, 2, 6, 7),
_mm256_setr_epi32(0, 1, 2, 4, 5, 3, 6, 7),
_mm256_setr_epi32(1, 2, 4, 5, 0, 3, 6, 7),
_mm256_setr_epi32(0, 2, 4, 5, 1, 3, 6, 7),
_mm256_setr_epi32(2, 4, 5, 0, 1, 3, 6, 7),
_mm256_setr_epi32(0, 1, 4, 5, 2, 3, 6, 7),
_mm256_setr_epi32(1, 4, 5, 0, 2, 3, 6, 7),
_mm256_setr_epi32(0, 4, 5, 1, 2, 3, 6, 7),
_mm256_setr_epi32(4, 5, 0, 1, 2, 3, 6, 7),
_mm256_setr_epi32(0, 1, 2, 3, 5, 4, 6, 7),
_mm256_setr_epi32(1, 2, 3, 5, 0, 4, 6, 7),
_mm256_setr_epi32(0, 2, 3, 5, 1, 4, 6, 7),
_mm256_setr_epi32(2, 3, 5, 0, 1, 4, 6, 7),
_mm256_setr_epi32(0, 1, 3, 5, 2, 4, 6, 7),
_mm256_setr_epi32(1, 3, 5, 0, 2, 4, 6, 7),
_mm256_setr_epi32(0, 3, 5, 1, 2, 4, 6, 7),
_mm256_setr_epi32(3, 5, 0, 1, 2, 4, 6, 7),
_mm256_setr_epi32(0, 1, 2, 5, 3, 4, 6, 7),
_mm256_setr_epi32(1, 2, 5, 0, 3, 4, 6, 7),
_mm256_setr_epi32(0, 2, 5, 1, 3, 4, 6, 7),
_mm256_setr_epi32(2, 5, 0, 1, 3, 4, 6, 7),
_mm256_setr_epi32(0, 1, 5, 2, 3, 4, 6, 7),
_mm256_setr_epi32(1, 5, 0, 2, 3, 4, 6, 7),
_mm256_setr_epi32(0, 5, 1, 2, 3, 4, 6, 7),
_mm256_setr_epi32(5, 0, 1, 2, 3, 4, 6, 7),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(1, 2, 3, 4, 0, 5, 6, 7),
_mm256_setr_epi32(0, 2, 3, 4, 1, 5, 6, 7),
_mm256_setr_epi32(2, 3, 4, 0, 1, 5, 6, 7),
_mm256_setr_epi32(0, 1, 3, 4, 2, 5, 6, 7),
_mm256_setr_epi32(1, 3, 4, 0, 2, 5, 6, 7),
_mm256_setr_epi32(0, 3, 4, 1, 2, 5, 6, 7),
_mm256_setr_epi32(3, 4, 0, 1, 2, 5, 6, 7),
_mm256_setr_epi32(0, 1, 2, 4, 3, 5, 6, 7),
_mm256_setr_epi32(1, 2, 4, 0, 3, 5, 6, 7),
_mm256_setr_epi32(0, 2, 4, 1, 3, 5, 6, 7),
_mm256_setr_epi32(2, 4, 0, 1, 3, 5, 6, 7),
_mm256_setr_epi32(0, 1, 4, 2, 3, 5, 6, 7),
_mm256_setr_epi32(1, 4, 0, 2, 3, 5, 6, 7),
_mm256_setr_epi32(0, 4, 1, 2, 3, 5, 6, 7),
_mm256_setr_epi32(4, 0, 1, 2, 3, 5, 6, 7),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(1, 2, 3, 0, 4, 5, 6, 7),
_mm256_setr_epi32(0, 2, 3, 1, 4, 5, 6, 7),
_mm256_setr_epi32(2, 3, 0, 1, 4, 5, 6, 7),
_mm256_setr_epi32(0, 1, 3, 2, 4, 5, 6, 7),
_mm256_setr_epi32(1, 3, 0, 2, 4, 5, 6, 7),
_mm256_setr_epi32(0, 3, 1, 2, 4, 5, 6, 7),
_mm256_setr_epi32(3, 0, 1, 2, 4, 5, 6, 7),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(1, 2, 0, 3, 4, 5, 6, 7),
_mm256_setr_epi32(0, 2, 1, 3, 4, 5, 6, 7),
_mm256_setr_epi32(2, 0, 1, 3, 4, 5, 6, 7),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(1, 0, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7),
_mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7)};


inline int partition_vec(__m256i &curr_vec, const __m256i &pivot_vec,
                         __m256i &smallest_vec, __m256i &biggest_vec){
  
  __m256i compared = _mm256_cmpgt_epi32(curr_vec, pivot_vec);
  
  smallest_vec = _mm256_min_epi32(curr_vec, smallest_vec);
  biggest_vec = _mm256_max_epi32(curr_vec, biggest_vec);
  
  int mm = _mm256_movemask_ps(_mm256_castsi256_ps(compared));
  
  int amount_gt_pivot = _mm_popcnt_u32((mm));
  
  curr_vec = _mm256_permutevar8x32_epi32(curr_vec, permutation_masks[mm]);
  
  return amount_gt_pivot; }

inline int calc_min(__m256i vec) { 
  auto perm_mask = _mm256_setr_epi32(7, 6, 5, 4, 3, 2, 1, 0);
  vec = _mm256_min_epi32(vec, _mm256_permutevar8x32_epi32(vec, perm_mask));
  vec = _mm256_min_epi32(vec, _mm256_shuffle_epi32(vec, 0b10110001));
  vec = _mm256_min_epi32(vec, _mm256_shuffle_epi32(vec, 0b01001110));
  return _mm256_extract_epi32(vec, 0); }

inline int calc_max(__m256i vec){ 
  auto perm_mask = _mm256_setr_epi32(7, 6, 5, 4, 3, 2, 1, 0);
  vec = _mm256_max_epi32(vec, _mm256_permutevar8x32_epi32(vec, perm_mask));
  vec = _mm256_max_epi32(vec, _mm256_shuffle_epi32(vec, 0b10110001));
  vec = _mm256_max_epi32(vec, _mm256_shuffle_epi32(vec, 0b01001110));
  return _mm256_extract_epi32(vec, 0);
}

inline int partition_vectorized_8(int *arr, int left, int right,
                                  int pivot, int &smallest, int &biggest) {
  
  for (int i = (right - left) % 8; i > 0; --i) {
    smallest = std::min(smallest, arr[left]); biggest = std::max(biggest, arr[left]);
    if (arr[left] > pivot) { std::swap(arr[left], arr[--right]); }
    else { ++left; }}

  if(left == right) return left; 

  auto pivot_vec = _mm256_set1_epi32(pivot); 
  auto sv = _mm256_set1_epi32(smallest); 
  auto bv = _mm256_set1_epi32(biggest); 

  if(right - left == 8){ 
    auto v = LOAD_VECTOR(arr + left);
    int amount_gt_pivot = partition_vec(v, pivot_vec, sv, bv);
    STORE_VECTOR(arr + left, v);
    smallest = calc_min(sv); biggest = calc_max(bv);
    return left + (8 - amount_gt_pivot); }

  
  auto vec_left = LOAD_VECTOR(arr + left); 
  auto vec_right = LOAD_VECTOR(arr + (right - 8)); 
  
  int r_store = right - 8; 
  int l_store = left; 
  
  left += 8; 
  right -= 8; 

  while(right - left != 0) { 
    __m256i curr_vec; 
    
    if((r_store + 8) - right < left - l_store){
      right -= 8; curr_vec = LOAD_VECTOR(arr + right); }
    else { curr_vec = LOAD_VECTOR(arr + left); left += 8; }
    
    int amount_gt_pivot = partition_vec(curr_vec, pivot_vec, sv, bv);;
    STORE_VECTOR(arr + l_store, curr_vec); STORE_VECTOR(arr + r_store, curr_vec);
    
    r_store -= amount_gt_pivot; l_store += (8 - amount_gt_pivot); }

  
  int amount_gt_pivot = partition_vec(vec_left, pivot_vec, sv, bv);
  STORE_VECTOR(arr + l_store, vec_left); STORE_VECTOR(arr + r_store, vec_left);
  l_store += (8 - amount_gt_pivot);
  
  amount_gt_pivot = partition_vec(vec_right, pivot_vec, sv, bv);
  STORE_VECTOR(arr + l_store, vec_right);
  l_store += (8 - amount_gt_pivot);

  smallest = calc_min(sv); 
  biggest = calc_max(bv); 
  return l_store; }


inline int partition_vectorized_64(int *arr, int left, int right,
                                   int pivot, int &smallest, int &biggest) {
  if (right - left < 129) { 
    return partition_vectorized_8(arr, left, right, pivot, smallest, biggest); }

    
  for (int i = (right - left) % 8; i > 0; --i) {
    smallest = std::min(smallest, arr[left]); biggest = std::max(biggest, arr[left]);
    if (arr[left] > pivot) { std::swap(arr[left], arr[--right]); }
    else { ++left; }}

    auto pivot_vec = _mm256_set1_epi32(pivot); 
    auto sv = _mm256_set1_epi32(smallest); 
    auto bv = _mm256_set1_epi32(biggest); 

    
  for (int i = ((right - left) % 64) / 8; i > 0; --i) {
    __m256i vec_L = LOAD_VECTOR(arr + left);
    __m256i compared = _mm256_cmpgt_epi32(vec_L, pivot_vec);
    sv = _mm256_min_epi32(vec_L, sv); bv = _mm256_max_epi32(vec_L, bv);
    int mm = _mm256_movemask_ps(_mm256_castsi256_ps(compared));
    int amount_gt_pivot = _mm_popcnt_u32((mm));
    __m256i permuted = _mm256_permutevar8x32_epi32(vec_L, permutation_masks[mm]);

    
    __m256i blend_mask = _mm256_cmpgt_epi32(permuted, pivot_vec);
    __m256i vec_R = LOAD_VECTOR(arr + right - 8);
    __m256i vec_L_new = _mm256_blendv_epi8(permuted, vec_R, blend_mask);
    __m256i vec_R_new = _mm256_blendv_epi8(vec_R, permuted, blend_mask);
    STORE_VECTOR(arr + left, vec_L_new); STORE_VECTOR(arr + right - 8, vec_R_new);
    left += (8 - amount_gt_pivot); right -= amount_gt_pivot; }

  
  auto vec_left = LOAD_VECTOR(arr + left), vec_left2 = LOAD_VECTOR(arr + left + 8);
  auto vec_left3 = LOAD_VECTOR(arr + left + 16), vec_left4 = LOAD_VECTOR(arr + left + 24);
  auto vec_left5 = LOAD_VECTOR(arr + left + 32), vec_left6 = LOAD_VECTOR(arr + left + 40);
  auto vec_left7 = LOAD_VECTOR(arr + left + 48), vec_left8 = LOAD_VECTOR(arr + left + 56);
  auto vec_right = LOAD_VECTOR(arr + (right - 64)), vec_right2 = LOAD_VECTOR(arr + (right - 56));
  auto vec_right3 = LOAD_VECTOR(arr + (right - 48)), vec_right4 = LOAD_VECTOR(arr + (right - 40));
  auto vec_right5 = LOAD_VECTOR(arr + (right - 32)), vec_right6 = LOAD_VECTOR(arr + (right - 24));
  auto vec_right7 = LOAD_VECTOR(arr + (right - 16)), vec_right8 = LOAD_VECTOR(arr + (right - 8));

  
  int r_store = right - 64; 
  int l_store = left; 
  
  left += 64; 
  right -= 64; 

  while (right - left != 0) { 
    __m256i curr_vec, curr_vec2, curr_vec3, curr_vec4, curr_vec5, curr_vec6, curr_vec7, curr_vec8;

    
    if ((r_store + 64) - right < left - l_store) {
      right -= 64;
      curr_vec = LOAD_VECTOR(arr + right); curr_vec2 = LOAD_VECTOR(arr + right + 8);
      curr_vec3 = LOAD_VECTOR(arr + right + 16); curr_vec4 = LOAD_VECTOR(arr + right + 24);
      curr_vec5 = LOAD_VECTOR(arr + right + 32); curr_vec6 = LOAD_VECTOR(arr + right + 40);
      curr_vec7 = LOAD_VECTOR(arr + right + 48); curr_vec8 = LOAD_VECTOR(arr + right + 56); }
    else {
      curr_vec = LOAD_VECTOR(arr + left); curr_vec2 = LOAD_VECTOR(arr + left + 8);
      curr_vec3 = LOAD_VECTOR(arr + left + 16); curr_vec4 = LOAD_VECTOR(arr + left + 24);
      curr_vec5 = LOAD_VECTOR(arr + left + 32); curr_vec6 = LOAD_VECTOR(arr + left + 40);
      curr_vec7 = LOAD_VECTOR(arr + left + 48); curr_vec8 = LOAD_VECTOR(arr + left + 56);
      left += 64; }

    
    int amount_gt_pivot = partition_vec(curr_vec, pivot_vec, sv, bv);
    int amount_gt_pivot2 = partition_vec(curr_vec2, pivot_vec, sv, bv);
    int amount_gt_pivot3 = partition_vec(curr_vec3, pivot_vec, sv, bv);
    int amount_gt_pivot4 = partition_vec(curr_vec4, pivot_vec, sv, bv);
    int amount_gt_pivot5 = partition_vec(curr_vec5, pivot_vec, sv, bv);
    int amount_gt_pivot6 = partition_vec(curr_vec6, pivot_vec, sv, bv);
    int amount_gt_pivot7 = partition_vec(curr_vec7, pivot_vec, sv, bv);
    int amount_gt_pivot8 = partition_vec(curr_vec8, pivot_vec, sv, bv);

    STORE_VECTOR(arr + l_store, curr_vec); l_store += (8 - amount_gt_pivot);
    STORE_VECTOR(arr + l_store, curr_vec2); l_store += (8 - amount_gt_pivot2);
    STORE_VECTOR(arr + l_store, curr_vec3); l_store += (8 - amount_gt_pivot3);
    STORE_VECTOR(arr + l_store, curr_vec4); l_store += (8 - amount_gt_pivot4);
    STORE_VECTOR(arr + l_store, curr_vec5); l_store += (8 - amount_gt_pivot5);
    STORE_VECTOR(arr + l_store, curr_vec6); l_store += (8 - amount_gt_pivot6);
    STORE_VECTOR(arr + l_store, curr_vec7); l_store += (8 - amount_gt_pivot7);
    STORE_VECTOR(arr + l_store, curr_vec8); l_store += (8 - amount_gt_pivot8);

    STORE_VECTOR(arr + r_store + 56, curr_vec); r_store -= amount_gt_pivot;
    STORE_VECTOR(arr + r_store + 56, curr_vec2); r_store -= amount_gt_pivot2;
    STORE_VECTOR(arr + r_store + 56, curr_vec3); r_store -= amount_gt_pivot3;
    STORE_VECTOR(arr + r_store + 56, curr_vec4); r_store -= amount_gt_pivot4;
    STORE_VECTOR(arr + r_store + 56, curr_vec5); r_store -= amount_gt_pivot5;
    STORE_VECTOR(arr + r_store + 56, curr_vec6); r_store -= amount_gt_pivot6;
    STORE_VECTOR(arr + r_store + 56, curr_vec7); r_store -= amount_gt_pivot7;
    STORE_VECTOR(arr + r_store + 56, curr_vec8); r_store -= amount_gt_pivot8;
  }

  
  int amount_gt_pivot = partition_vec(vec_left, pivot_vec, sv, bv);
  int amount_gt_pivot2 = partition_vec(vec_left2, pivot_vec, sv, bv);
  int amount_gt_pivot3 = partition_vec(vec_left3, pivot_vec, sv, bv);
  int amount_gt_pivot4 = partition_vec(vec_left4, pivot_vec, sv, bv);
  int amount_gt_pivot5 = partition_vec(vec_left5, pivot_vec, sv, bv);
  int amount_gt_pivot6 = partition_vec(vec_left6, pivot_vec, sv, bv);
  int amount_gt_pivot7 = partition_vec(vec_left7, pivot_vec, sv, bv);
  int amount_gt_pivot8 = partition_vec(vec_left8, pivot_vec, sv, bv);

  STORE_VECTOR(arr + l_store, vec_left); l_store += (8 - amount_gt_pivot);
  STORE_VECTOR(arr + l_store, vec_left2); l_store += (8 - amount_gt_pivot2);
  STORE_VECTOR(arr + l_store, vec_left3); l_store += (8 - amount_gt_pivot3);
  STORE_VECTOR(arr + l_store, vec_left4); l_store += (8 - amount_gt_pivot4);
  STORE_VECTOR(arr + l_store, vec_left5); l_store += (8 - amount_gt_pivot5);
  STORE_VECTOR(arr + l_store, vec_left6); l_store += (8 - amount_gt_pivot6);
  STORE_VECTOR(arr + l_store, vec_left7); l_store += (8 - amount_gt_pivot7);
  STORE_VECTOR(arr + l_store, vec_left8); l_store += (8 - amount_gt_pivot8);

  STORE_VECTOR(arr + r_store + 56, vec_left); r_store -= amount_gt_pivot;
  STORE_VECTOR(arr + r_store + 56, vec_left2); r_store -= amount_gt_pivot2;
  STORE_VECTOR(arr + r_store + 56, vec_left3); r_store -= amount_gt_pivot3;
  STORE_VECTOR(arr + r_store + 56, vec_left4); r_store -= amount_gt_pivot4;
  STORE_VECTOR(arr + r_store + 56, vec_left5); r_store -= amount_gt_pivot5;
  STORE_VECTOR(arr + r_store + 56, vec_left6); r_store -= amount_gt_pivot6;
  STORE_VECTOR(arr + r_store + 56, vec_left7); r_store -= amount_gt_pivot7;
  STORE_VECTOR(arr + r_store + 56, vec_left8); r_store -= amount_gt_pivot8;

  
  amount_gt_pivot = partition_vec(vec_right, pivot_vec, sv, bv);
  amount_gt_pivot2 = partition_vec(vec_right2, pivot_vec, sv, bv);
  amount_gt_pivot3 = partition_vec(vec_right3, pivot_vec, sv, bv);
  amount_gt_pivot4 = partition_vec(vec_right4, pivot_vec, sv, bv);
  amount_gt_pivot5 = partition_vec(vec_right5, pivot_vec, sv, bv);
  amount_gt_pivot6 = partition_vec(vec_right6, pivot_vec, sv, bv);
  amount_gt_pivot7 = partition_vec(vec_right7, pivot_vec, sv, bv);
  amount_gt_pivot8 = partition_vec(vec_right8, pivot_vec, sv, bv);

  STORE_VECTOR(arr + l_store, vec_right); l_store += (8 - amount_gt_pivot);
  STORE_VECTOR(arr + l_store, vec_right2); l_store += (8 - amount_gt_pivot2);
  STORE_VECTOR(arr + l_store, vec_right3); l_store += (8 - amount_gt_pivot3);
  STORE_VECTOR(arr + l_store, vec_right4); l_store += (8 - amount_gt_pivot4);
  STORE_VECTOR(arr + l_store, vec_right5); l_store += (8 - amount_gt_pivot5);
  STORE_VECTOR(arr + l_store, vec_right6); l_store += (8 - amount_gt_pivot6);
  STORE_VECTOR(arr + l_store, vec_right7); l_store += (8 - amount_gt_pivot7);
  STORE_VECTOR(arr + l_store, vec_right8); l_store += (8 - amount_gt_pivot8);

  STORE_VECTOR(arr + r_store + 56, vec_right); r_store -= amount_gt_pivot;
  STORE_VECTOR(arr + r_store + 56, vec_right2); r_store -= amount_gt_pivot2;
  STORE_VECTOR(arr + r_store + 56, vec_right3); r_store -= amount_gt_pivot3;
  STORE_VECTOR(arr + r_store + 56, vec_right4); r_store -= amount_gt_pivot4;
  STORE_VECTOR(arr + r_store + 56, vec_right5); r_store -= amount_gt_pivot5;
  STORE_VECTOR(arr + r_store + 56, vec_right6); r_store -= amount_gt_pivot6;
  STORE_VECTOR(arr + r_store + 56, vec_right7); r_store -= amount_gt_pivot7;
  STORE_VECTOR(arr + r_store + 56, vec_right8);

  smallest = calc_min(sv); biggest = calc_max(bv);
  return l_store; }




#define VROTL(x, k)                \
  _mm256_or_si256(_mm256_slli_epi64((x),(k)),_mm256_srli_epi64((x),64-(k)))

inline __m256i vnext(__m256i &s0, __m256i &s1) {
  s1 = _mm256_xor_si256(s0, s1); 
  s0 = _mm256_xor_si256(_mm256_xor_si256(VROTL(s0, 24), s1),
                        _mm256_slli_epi64(s1, 16));
  s1 = VROTL(s1, 37);
  return _mm256_add_epi64(s0, s1); } 


inline __m256i rnd_epu32(__m256i rnd_vec, __m256i bound) {
  __m256i even = _mm256_srli_epi64(_mm256_mul_epu32(rnd_vec, bound), 32);
  __m256i odd = _mm256_mul_epu32(_mm256_srli_epi64(rnd_vec, 32), bound);
  return _mm256_blend_epi32(odd, even, 0b01010101); }


inline int average(int a, int b) { return (a & b) + ((a ^ b) >> 1); }

inline int get_pivot(int *arr, const int left, const int right){
  auto bound = _mm256_set1_epi32(right - left + 1);
  auto left_vec = _mm256_set1_epi32(left);

  
  auto s0 = _mm256_setr_epi64x(8265987198341093849, 3762817312854612374,
                               1324281658759788278, 6214952190349879213);
  auto s1 = _mm256_setr_epi64x(2874178529384792648, 1257248936691237653,
                               7874578921548791257, 1998265912745817298);
  s0 = _mm256_add_epi64(s0, _mm256_set1_epi64x(left));
  s1 = _mm256_sub_epi64(s1, _mm256_set1_epi64x(right));

  __m256i v[9];
  for (int i = 0; i < 9; ++i) { 
    auto result = vnext(s0, s1); 
    result = rnd_epu32(result, bound); 
    result = _mm256_add_epi32(result, left_vec); 
    v[i] = _mm256_i32gather_epi32(arr, result, sizeof(uint32_t)); }

  
  COEX(v[0], v[1]); COEX(v[2], v[3]); 
  COEX(v[4], v[5]); COEX(v[6], v[7]);
  COEX(v[0], v[2]); COEX(v[1], v[3]); 
  COEX(v[4], v[6]); COEX(v[5], v[7]);
  COEX(v[0], v[4]); COEX(v[1], v[2]); 
  COEX(v[5], v[6]); COEX(v[3], v[7]);
  COEX(v[1], v[5]); COEX(v[2], v[6]); 
  COEX(v[3], v[5]); COEX(v[2], v[4]); 
  COEX(v[3], v[4]);                   
  COEX(v[3], v[8]);                   
  COEX(v[4], v[8]);                   

  SORT_8(v[4]); 
  return average(_mm256_extract_epi32(v[4], 3), 
                 _mm256_extract_epi32(v[4], 4)); }



template <int bt = 29>
inline void qs_core(int *arr, int left, int right,
                    const int L = 0) { if constexpr (bt != -1) {
  if (right - left < 513) { 
    __m256i buffer[66]; 
    int* buff = reinterpret_cast<int *>(buffer);
    sort_int_sorting_network(arr + left, buff, right - left + 1);
    return; }
  
  int pivot = L | 1 << bt;
  int smallest = INT32_MAX; 
  int biggest = INT32_MIN;  
  int bound = partition_vectorized_64(arr, left, right + 1, pivot, smallest, biggest);
  if (pivot != smallest) 
    qs_core<bt - 1>(arr, left, bound - 1, L);
  if (pivot + 1 != biggest)  
    qs_core<bt - 1>(arr, bound, right, pivot); }}
}


inline void quicksort(int *arr, int n) { _internal::qs_core(arr, 0, n - 1); }
} 

}

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
auto operator>>(istream& in, auto&& p) -> decltype(p.first, p.second, in) { return in >> p.first >> p.second; }
auto operator<<(ostream& out, const auto& p) -> decltype(p.first, p.second, out) { return out << p.first << ' ' << p.second; }
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
template <int from, int which> auto getfield(const auto& a) -> const auto& { static_assert(1 <= which && which <= from && from <= 5); auto fix = [](auto& x) -> auto& { return x; }; if constexpr (from == 1) { auto& [a1] = a; if constexpr (which == 1) return fix(a1); } else if constexpr (from == 2) { auto& [a1, a2] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); } else if constexpr (from == 3) { auto& [a1, a2, a3] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); } else if constexpr (from == 4) { auto& [a1, a2, a3, a4] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); } else if constexpr (from == 5) { auto& [a1, a2, a3, a4, a5] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); } }
template <int from, int which, typename Cmp = equal_to<>> struct CompareField { bool operator()(const auto& a, const auto& b) const { return Cmp{}(getfield<from, which>(a), getfield<from, which>(b)); } };
template <int from, int which, int... whichs> struct Ordering { bool operator()(const auto& a, const auto& b) const { auto& aa = getfield<from, labs(which)>(a), & bb = getfield<from, labs(which)>(b); if (aa < bb) { return which > 0; } else if (bb < aa) { return which < 0; } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 5e1, M = 3e2;
vector<array<int, 3>> edges;
int64_t mst, balance;
int n, m, pq;
int p[N], w[N];

inline int getp(int v) {
  static int st[N], sz;
  if (p[v] == v) {
    return v;
  }
  sz = 0;
  #pragma GCC unroll 50
  do {
    st[sz++] = exchange(v, p[v]);
  } while (p[v] != v);
  #pragma GCC unroll 50
  do {
    p[st[--sz]] = v;
  } while (sz);
  return v;
}

inline bool uni(int u, int v) {
  if ((u = getp(u)) == (v = getp(v))) {
    return 0;
  }






  p[v] = u;


  return 1;
}

void solve(int w) {
  iota(p, p + n, 0);


  auto key = [&](int i) { return labs(edges[i][2] - w); };
  #pragma GCC unroll 300
  for (int i = 1; i < edges.size(); ++i) {
    int j = i, ki = key(i);
    if (key(--j) <= ki) {
      continue;
    }
    swap(edges[j], edges[j + 1]);
    if (!j || key(--j) <= ki) {
      continue;
    }
    swap(edges[j], edges[j + 1]);
    for (; j && key(j - 1) > ki; --j) {
      swap(edges[j], edges[j - 1]);
    }
  }
  int cnt = mst = balance = 0;
  for (auto [u, v, cw]: edges) if (uni(u - 1, v - 1)) {
    mst += labs(cw - w);
    balance += 2 * (cw < w) - 1;
    if (++cnt == n - 1) {
      break;
    }
  }
  mst -= w * balance;
}

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  n = $, m = $;


  edges.resize(m);
  cin >> edges;
  vector<int> ws;
  for (int i = 0; i < m; ++i)
  for (int j = 0; j <= i; ++j) {
    ws.push_back((edges[i][2] + edges[j][2]) / 2 + 1);
  }
  ws.push_back(0);
  sort(ws.begin(), ws.end());
  ws.erase(unique(ws.begin(), ws.end()), ws.end());
  ws.push_back(1e9);
  auto [p, k, a, b, c] = array<int64_t, 5>($);
  vector<int> qs;
  qs.resize(k);
  for (int i = 0; i < p; ++i) {
    qs[i] = $;
  }
  for (int i = p, qp = qs[i - 1]; i < k; ++i) {
    qs[i] = qp = (qp * a + b) % c;
  }
  Blacher::avx2::quicksort(qs.data(), qs.size());
  auto it = ws.begin();
  int64_t ans{};
  for (auto q: qs) {
    while (__builtin_expect(q >= *it, 0)) {
      solve(*it++);
    }
    ans ^= mst + balance * q;
  }
  print(ans);
}
