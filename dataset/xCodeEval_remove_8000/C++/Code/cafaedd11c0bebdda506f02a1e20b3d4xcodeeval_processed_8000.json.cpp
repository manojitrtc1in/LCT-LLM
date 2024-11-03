











namespace Blacher {








namespace avx2{
namespace _internal {



  _mm256_storeu_si256(reinterpret_cast<__m256i *>(arr), vec)





    auto vec_tmp = a;                  \
    a = _mm256_min_epi32(a, b);        \
    b = _mm256_max_epi32(vec_tmp, b);}



    _mm256_castps_si256 (_mm256_shuffle_ps(                         \
        _mm256_castsi256_ps (a), _mm256_castsi256_ps (b), mask));


inline void id16(__m256i &v1, __m256i &v2) {
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


  (((h < 7) << 7) | ((g < 6) << 6) | ((f < 5) << 5) | ((e < 4) << 4) | \
      ((d < 3) << 3) | ((c < 2) << 2) | ((b < 1) << 1) | (a < 0))


    __m256i id39 = _mm256_setr_epi32(a, b, c, d, e, f, g, h);  \
    __m256i id38 = _mm256_permutevar8x32_epi32(vec, id39); \
    __m256i min = _mm256_min_epi32(id38, vec);                     \
    __m256i max = _mm256_max_epi32(id38, vec);                     \
    constexpr int blend_mask = MASK(a, b, c, d, e, f, g, h);           \
    vec = _mm256_blend_epi32(min, max, blend_mask);}


    constexpr int shuffle_mask = _MM_SHUFFLE(d, c, b, a);              \
    __m256i shuffled = _mm256_shuffle_epi32(vec, shuffle_mask);        \
    __m256i min = _mm256_min_epi32(shuffled, vec);                     \
    __m256i max = _mm256_max_epi32(shuffled, vec);                     \
    constexpr int blend_mask = MASK(a, b, c, d, e, f, g, h);           \
    vec = _mm256_blend_epi32(min, max, blend_mask);}


    vec = _mm256_permutevar8x32_epi32(                                 \
        vec, _mm256_setr_epi32(7, 6, 5, 4, 3, 2, 1, 0));}



  COEX_SHUFFLE(vec, 1, 0, 3, 2, 5, 4, 7, 6, ASC);                           \
  COEX_SHUFFLE(vec, 2, 3, 0, 1, 6, 7, 4, 5, ASC);                           \
  COEX_SHUFFLE(vec, 0, 2, 1, 3, 4, 6, 5, 7, ASC);                           \
  COEX_PERMUTE(vec, 7, 6, 5, 4, 3, 2, 1, 0, ASC);                           \
  COEX_SHUFFLE(vec, 2, 3, 0, 1, 6, 7, 4, 5, ASC);                           \
  COEX_SHUFFLE(vec, 1, 0, 3, 2, 5, 4, 7, 6, ASC);}


inline void id25(__m256i *vecs, const int N, const int s = 2) {
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

inline void id15(__m256i *vecs, const int N, const int s = 16) {
  const int id35 = N - N % 16;
  const int id8 = N - N % 8;
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
    for (int j = 0; j < id35; j += 16) {
      COEX(vecs[j], vecs[j + 8]);
      COEX(vecs[j + 1], vecs[j + 9]);
      COEX(vecs[j + 2], vecs[j + 10]);
      COEX(vecs[j + 3], vecs[j + 11]);
      COEX(vecs[j + 4], vecs[j + 12]);
      COEX(vecs[j + 5], vecs[j + 13]);
      COEX(vecs[j + 6], vecs[j + 14]);
      COEX(vecs[j + 7], vecs[j + 15]);
    }
    for (int j = id35 + 8; j < N; j += 1) {
      COEX(vecs[j - 8], vecs[j]);
    }
    for (int j = 0; j < id8; j += 8) {
      COEX(vecs[j], vecs[j + 4]);
      COEX(vecs[j + 1], vecs[j + 5]);
      COEX(vecs[j + 2], vecs[j + 6]);
      COEX(vecs[j + 3], vecs[j + 7]);
    }
    for (int j = id8 + 4; j < N; j += 1) {
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


inline void id51(__m256i* vecs){
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


void inline id49(__m256i* vecs){
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

inline void id18(int *arr, int *buff, int n) {
  if(n < 2) return;
  __m256i *buffer = reinterpret_cast<__m256i *>(buff);

  const auto remainder = int(n % 8 ? n % 8 : 8);
  const int id3 = n - remainder;
  const auto mask = _mm256_add_epi32(_mm256_set1_epi32(-remainder), _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7));
  auto id13 = _mm256_blendv_epi8(_mm256_set1_epi32(id42),_mm256_maskload_epi32(arr + id3, mask), mask);

  for (int i = 0; i < id3 / 8; ++i) {
    buffer[i] = LOAD_VECTOR(arr + i * 8);
  }
  buffer[id3 / 8] = id13;
  buffer[id3 / 8 + 1] = _mm256_set1_epi32(id42);

  const int N = ((id3 % 16 == 0) * 8 + id3 + 8) / 8;

  for (int j = 0; j < N - N % 16; j += 16) {
    id51(buffer + j);
    id49(buffer + j);
  }
  for (int i = N - N % 16; i < N; i += 2) {
    id16(buffer[i], buffer[i + 1]);
  }
  id25(buffer + N - N % 16, N % 16, 2);
  id15(buffer, N, 16);
  for (int i = 0; i < id3 / 8; i += 1) {
    STORE_VECTOR(arr + i * 8, buffer[i]);
  }
  _mm256_maskstore_epi32(arr + id3, mask, buffer[id3 / 8]);
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
                         __m256i &id1, __m256i &id20){
  
  __m256i compared = _mm256_cmpgt_epi32(curr_vec, pivot_vec);
  
  id1 = _mm256_min_epi32(curr_vec, id1);
  id20 = _mm256_max_epi32(curr_vec, id20);
  
  int mm = _mm256_movemask_ps(_mm256_castsi256_ps(compared));
  
  int id36 = _mm_popcnt_u32((mm));
  
  curr_vec = _mm256_permutevar8x32_epi32(curr_vec, permutation_masks[mm]);
  
  return id36; }

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

inline int id27(int *arr, int left, int right,
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
    int id36 = partition_vec(v, pivot_vec, sv, bv);
    STORE_VECTOR(arr + left, v);
    smallest = calc_min(sv); biggest = calc_max(bv);
    return left + (8 - id36); }

  
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
    
    int id36 = partition_vec(curr_vec, pivot_vec, sv, bv);;
    STORE_VECTOR(arr + l_store, curr_vec); STORE_VECTOR(arr + r_store, curr_vec);
    
    r_store -= id36; l_store += (8 - id36); }

  
  int id36 = partition_vec(vec_left, pivot_vec, sv, bv);
  STORE_VECTOR(arr + l_store, vec_left); STORE_VECTOR(arr + r_store, vec_left);
  l_store += (8 - id36);
  
  id36 = partition_vec(vec_right, pivot_vec, sv, bv);
  STORE_VECTOR(arr + l_store, vec_right);
  l_store += (8 - id36);

  smallest = calc_min(sv); 
  biggest = calc_max(bv); 
  return l_store; }


inline int id43(int *arr, int left, int right,
                                   int pivot, int &smallest, int &biggest) {
  if (right - left < 129) { 
    return id27(arr, left, right, pivot, smallest, biggest); }

    
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
    int id36 = _mm_popcnt_u32((mm));
    __m256i id38 = _mm256_permutevar8x32_epi32(vec_L, permutation_masks[mm]);

    
    __m256i blend_mask = _mm256_cmpgt_epi32(id38, pivot_vec);
    __m256i vec_R = LOAD_VECTOR(arr + right - 8);
    __m256i id45 = _mm256_blendv_epi8(id38, vec_R, blend_mask);
    __m256i id0 = _mm256_blendv_epi8(vec_R, id38, blend_mask);
    STORE_VECTOR(arr + left, id45); STORE_VECTOR(arr + right - 8, id0);
    left += (8 - id36); right -= id36; }

  
  auto vec_left = LOAD_VECTOR(arr + left), id34 = LOAD_VECTOR(arr + left + 8);
  auto id41 = LOAD_VECTOR(arr + left + 16), id23 = LOAD_VECTOR(arr + left + 24);
  auto id24 = LOAD_VECTOR(arr + left + 32), id52 = LOAD_VECTOR(arr + left + 40);
  auto id46 = LOAD_VECTOR(arr + left + 48), id21 = LOAD_VECTOR(arr + left + 56);
  auto vec_right = LOAD_VECTOR(arr + (right - 64)), id14 = LOAD_VECTOR(arr + (right - 56));
  auto id6 = LOAD_VECTOR(arr + (right - 48)), id5 = LOAD_VECTOR(arr + (right - 40));
  auto id7 = LOAD_VECTOR(arr + (right - 32)), id48 = LOAD_VECTOR(arr + (right - 24));
  auto id4 = LOAD_VECTOR(arr + (right - 16)), id28 = LOAD_VECTOR(arr + (right - 8));

  
  int r_store = right - 64; 
  int l_store = left; 
  
  left += 64; 
  right -= 64; 

  while (right - left != 0) { 
    __m256i curr_vec, id22, id10, id40, id19, id44, id29, id37;

    
    if ((r_store + 64) - right < left - l_store) {
      right -= 64;
      curr_vec = LOAD_VECTOR(arr + right); id22 = LOAD_VECTOR(arr + right + 8);
      id10 = LOAD_VECTOR(arr + right + 16); id40 = LOAD_VECTOR(arr + right + 24);
      id19 = LOAD_VECTOR(arr + right + 32); id44 = LOAD_VECTOR(arr + right + 40);
      id29 = LOAD_VECTOR(arr + right + 48); id37 = LOAD_VECTOR(arr + right + 56); }
    else {
      curr_vec = LOAD_VECTOR(arr + left); id22 = LOAD_VECTOR(arr + left + 8);
      id10 = LOAD_VECTOR(arr + left + 16); id40 = LOAD_VECTOR(arr + left + 24);
      id19 = LOAD_VECTOR(arr + left + 32); id44 = LOAD_VECTOR(arr + left + 40);
      id29 = LOAD_VECTOR(arr + left + 48); id37 = LOAD_VECTOR(arr + left + 56);
      left += 64; }

    
    int id36 = partition_vec(curr_vec, pivot_vec, sv, bv);
    int id9 = partition_vec(id22, pivot_vec, sv, bv);
    int id12 = partition_vec(id10, pivot_vec, sv, bv);
    int id31 = partition_vec(id40, pivot_vec, sv, bv);
    int id26 = partition_vec(id19, pivot_vec, sv, bv);
    int id32 = partition_vec(id44, pivot_vec, sv, bv);
    int id2 = partition_vec(id29, pivot_vec, sv, bv);
    int id11 = partition_vec(id37, pivot_vec, sv, bv);

    STORE_VECTOR(arr + l_store, curr_vec); l_store += (8 - id36);
    STORE_VECTOR(arr + l_store, id22); l_store += (8 - id9);
    STORE_VECTOR(arr + l_store, id10); l_store += (8 - id12);
    STORE_VECTOR(arr + l_store, id40); l_store += (8 - id31);
    STORE_VECTOR(arr + l_store, id19); l_store += (8 - id26);
    STORE_VECTOR(arr + l_store, id44); l_store += (8 - id32);
    STORE_VECTOR(arr + l_store, id29); l_store += (8 - id2);
    STORE_VECTOR(arr + l_store, id37); l_store += (8 - id11);

    STORE_VECTOR(arr + r_store + 56, curr_vec); r_store -= id36;
    STORE_VECTOR(arr + r_store + 56, id22); r_store -= id9;
    STORE_VECTOR(arr + r_store + 56, id10); r_store -= id12;
    STORE_VECTOR(arr + r_store + 56, id40); r_store -= id31;
    STORE_VECTOR(arr + r_store + 56, id19); r_store -= id26;
    STORE_VECTOR(arr + r_store + 56, id44); r_store -= id32;
    STORE_VECTOR(arr + r_store + 56, id29); r_store -= id2;
    STORE_VECTOR(arr + r_store + 56, id37); r_store -= id11;
  }

  
  int id36 = partition_vec(vec_left, pivot_vec, sv, bv);
  int id9 = partition_vec(id34, pivot_vec, sv, bv);
  int id12 = partition_vec(id41, pivot_vec, sv, bv);
  int id31 = partition_vec(id23, pivot_vec, sv, bv);
  int id26 = partition_vec(id24, pivot_vec, sv, bv);
  int id32 = partition_vec(id52, pivot_vec, sv, bv);
  int id2 = partition_vec(id46, pivot_vec, sv, bv);
  int id11 = partition_vec(id21, pivot_vec, sv, bv);

  STORE_VECTOR(arr + l_store, vec_left); l_store += (8 - id36);
  STORE_VECTOR(arr + l_store, id34); l_store += (8 - id9);
  STORE_VECTOR(arr + l_store, id41); l_store += (8 - id12);
  STORE_VECTOR(arr + l_store, id23); l_store += (8 - id31);
  STORE_VECTOR(arr + l_store, id24); l_store += (8 - id26);
  STORE_VECTOR(arr + l_store, id52); l_store += (8 - id32);
  STORE_VECTOR(arr + l_store, id46); l_store += (8 - id2);
  STORE_VECTOR(arr + l_store, id21); l_store += (8 - id11);

  STORE_VECTOR(arr + r_store + 56, vec_left); r_store -= id36;
  STORE_VECTOR(arr + r_store + 56, id34); r_store -= id9;
  STORE_VECTOR(arr + r_store + 56, id41); r_store -= id12;
  STORE_VECTOR(arr + r_store + 56, id23); r_store -= id31;
  STORE_VECTOR(arr + r_store + 56, id24); r_store -= id26;
  STORE_VECTOR(arr + r_store + 56, id52); r_store -= id32;
  STORE_VECTOR(arr + r_store + 56, id46); r_store -= id2;
  STORE_VECTOR(arr + r_store + 56, id21); r_store -= id11;

  
  id36 = partition_vec(vec_right, pivot_vec, sv, bv);
  id9 = partition_vec(id14, pivot_vec, sv, bv);
  id12 = partition_vec(id6, pivot_vec, sv, bv);
  id31 = partition_vec(id5, pivot_vec, sv, bv);
  id26 = partition_vec(id7, pivot_vec, sv, bv);
  id32 = partition_vec(id48, pivot_vec, sv, bv);
  id2 = partition_vec(id4, pivot_vec, sv, bv);
  id11 = partition_vec(id28, pivot_vec, sv, bv);

  STORE_VECTOR(arr + l_store, vec_right); l_store += (8 - id36);
  STORE_VECTOR(arr + l_store, id14); l_store += (8 - id9);
  STORE_VECTOR(arr + l_store, id6); l_store += (8 - id12);
  STORE_VECTOR(arr + l_store, id5); l_store += (8 - id31);
  STORE_VECTOR(arr + l_store, id7); l_store += (8 - id26);
  STORE_VECTOR(arr + l_store, id48); l_store += (8 - id32);
  STORE_VECTOR(arr + l_store, id4); l_store += (8 - id2);
  STORE_VECTOR(arr + l_store, id28); l_store += (8 - id11);

  STORE_VECTOR(arr + r_store + 56, vec_right); r_store -= id36;
  STORE_VECTOR(arr + r_store + 56, id14); r_store -= id9;
  STORE_VECTOR(arr + r_store + 56, id6); r_store -= id12;
  STORE_VECTOR(arr + r_store + 56, id5); r_store -= id31;
  STORE_VECTOR(arr + r_store + 56, id7); r_store -= id26;
  STORE_VECTOR(arr + r_store + 56, id48); r_store -= id32;
  STORE_VECTOR(arr + r_store + 56, id4); r_store -= id2;
  STORE_VECTOR(arr + r_store + 56, id28);

  smallest = calc_min(sv); biggest = calc_max(bv);
  return l_store; }





  _mm256_or_si256(_mm256_slli_epi64((x),(k)),_mm256_srli_epi64((x),64-(k)))

inline __m256i vnext(__m256i &s0, __m256i &s1) {
  s1 = _mm256_xor_si256(s0, s1); 
  s0 = _mm256_xor_si256(_mm256_xor_si256(VROTL(s0, 24), s1),
                        _mm256_slli_epi64(s1, 16));
  s1 = VROTL(s1, 37);
  return _mm256_add_epi64(s0, s1); } 


inline __m256i id33(__m256i rnd_vec, __m256i bound) {
  __m256i even = _mm256_srli_epi64(_mm256_mul_epu32(rnd_vec, bound), 32);
  __m256i odd = _mm256_mul_epu32(_mm256_srli_epi64(rnd_vec, 32), bound);
  return _mm256_blend_epi32(odd, even, 0b01010101); }


inline int average(int a, int b) { return (a & b) + ((a ^ b) >> 1); }

inline int id17(int *arr, const int left, const int right){
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
    result = id33(result, bound); 
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
    id18(arr + left, buff, right - left + 1);
    return; }
  
  int pivot = L | 1 << bt;
  int smallest = id42; 
  int biggest = id50;  
  int bound = id43(arr, left, right + 1, pivot, smallest, biggest);
  if (pivot != smallest) 
    qs_core<bt - 1>(arr, left, bound - 1, L);
  if (pivot + 1 != biggest)  
    qs_core<bt - 1>(arr, bound, right, pivot); }}
}


inline void id30(int *arr, int n) { _internal::qs_core(arr, 0, n - 1); }
} 

}


struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
    bufptr = buf;
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      b[i] = {};
    }
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  auto operator()(Ts&... xs) -> std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)> {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr < '0') {
        ++b;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

using namespace std;

bool id47 =
                    
                    1;
                    
                    0;
                    
struct { using X = int; template <typename T = X> T operator()() { T t; reader(t); return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } template <class T = string> T operator~() { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range() {} range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } int size() const { return last - first; } const auto& operator[](int i) const { return first[i]; } auto& operator[](int i) { return first[i]; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (a > 0) - (a < 0); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 3e5;


struct Hash {
  static uint64_t& global_seed() { static uint64_t global_seed = chrono::steady_clock::now().time_since_epoch().count(); return global_seed; }

  Hash(uint64_t seed = 0) : seed{seed += global_seed() += 0x9e3779b97f4a7c15} {
  }

  size_t operator()(uint64_t x) const {
    x += seed;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  const uint64_t seed;
};

struct HPII {
  Hash h;

  size_t operator()(const auto& pii) const {
    return h(int64_t(pii.first) << 32 ^ pii.second);
  }

  static auto dec(const auto& pii) {
    return uint64_t(pii.first) << 32 ^ pii.second;
  }
};


struct Bloom {
  static constexpr int am = 2;
  static constexpr int sz = 1 << 22;
  static constexpr __attribute__ ((vector_size (128))) uint64_t vsz{sz - 1, sz - 1};
  static constexpr __attribute__ ((vector_size (128))) uint64_t m1{0xbf58476d1ce4e5b9, 0xbf58476d1ce4e5b9};
  static constexpr __attribute__ ((vector_size (128))) uint64_t m2{0x94d049bb133111eb, 0x94d049bb133111eb};
  using T = pair<int, int>;
  using H = HPII;

  bitset<sz> a[am];
  H h[am];


    __attribute__ ((vector_size (128))) uint64_t val{HPII::dec(v) + h[0].h.seed, HPII::dec(v) + h[1].h.seed};\
    val ^= val >> 30;\
    val *= m1;\
    val ^= val >> 27;\
    val *= m2;\
    val &= vsz

  void insert(const T& v) {
    $hsh;
    a[0][val[0]] = 1;
    a[1][val[1]] = 1;
  }

  void erase(const T& v) {
    $hsh;
    a[0][val[0]] = 0;
    a[1][val[1]] = 0;
  }

  void clear() {
    for (int i = 0; i < am; ++i) {
      a[i].reset();
    }
  }

  bool contains(const T& v) const {
    $hsh;
    return a[0][val[0]] & a[1][val[1]];
  }

} forbidden;

auto canonize(auto pii) {
  return pair{min(pii.first, pii.second), max(pii.first, pii.second)};
}

bool check(auto pii) {
  return pii.first != pii.second && !forbidden.contains(canonize(pii));
}

int a[N];
pair<int, int> fb[N];
vector<int> c2v[N];

int main() {
  for (int testcase = $; testcase; --testcase) {
    int n = $, m = $;
    int64_t ans = 0;
    reader(a, n);
    Blacher::avx2::id30(a, n);
    reader(&fb[0].first, 2 * m);
    for (int i = 0; i < m; ++i) {
      forbidden.insert(fb[i]);
    }
    for (int i = 0; i < n; ) {
      int j = i;
      while (j < n && a[i] == a[j]) {
        ++j;
      }
      c2v[j - i].push_back(a[i]);
      i = j;
    }
    for (int i = n - 1; i > -1; ) {
      int j = i;
      while (j > -1 && a[i] == a[j]) {
        --j;
      }
      int cnt = i - j;
      for (int c = cnt; c; --c)
      for (int j = c2v[c].size(); j-- && (cnt + c) * int64_t(a[i] + c2v[c][j]) > ans; ) if (check(pair{a[i], c2v[c][j]})) {
        ans = (cnt + c) * int64_t(a[i] + c2v[c][j]);
      }
      i = j;
    }
    print(ans);
    if (testcase == 1) {
      break;
    }
    if (m >= Bloom::sz / 32) {
      forbidden.clear();
    } else {
      for (int i = 0; i < m; ++i) {
        forbidden.erase(fb[i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      c2v[i].clear();
    }
  }
}
