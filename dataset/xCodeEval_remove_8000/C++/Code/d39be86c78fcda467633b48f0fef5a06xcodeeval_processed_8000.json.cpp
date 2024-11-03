



































namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION


  inline _GLIBCXX_CONSTEXPR double
  abs(double __x)
  { return __builtin_fabs(__x); }



  inline _GLIBCXX_CONSTEXPR float
  abs(float __x)
  { return __builtin_fabsf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  abs(long double __x)
  { return __builtin_fabsl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    abs(_Tp __x)
    { return __builtin_fabs(__x); }

  using ::acos;


  inline _GLIBCXX_CONSTEXPR float
  acos(float __x)
  { return __builtin_acosf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  acos(long double __x)
  { return __builtin_acosl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    acos(_Tp __x)
    { return __builtin_acos(__x); }

  using ::asin;


  inline _GLIBCXX_CONSTEXPR float
  asin(float __x)
  { return __builtin_asinf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  asin(long double __x)
  { return __builtin_asinl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    asin(_Tp __x)
    { return __builtin_asin(__x); }

  using ::atan;


  inline _GLIBCXX_CONSTEXPR float
  atan(float __x)
  { return __builtin_atanf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  atan(long double __x)
  { return __builtin_atanl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    atan(_Tp __x)
    { return __builtin_atan(__x); }

  using ::atan2;


  inline _GLIBCXX_CONSTEXPR float
  atan2(float __y, float __x)
  { return __builtin_atan2f(__y, __x); }

  inline _GLIBCXX_CONSTEXPR long double
  atan2(long double __y, long double __x)
  { return __builtin_atan2l(__y, __x); }


  template<typename _Tp, typename _Up>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    atan2(_Tp __y, _Up __x)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return atan2(__type(__y), __type(__x));
    }

  using ::ceil;


  inline _GLIBCXX_CONSTEXPR float
  ceil(float __x)
  { return __builtin_ceilf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  ceil(long double __x)
  { return __builtin_ceill(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    ceil(_Tp __x)
    { return __builtin_ceil(__x); }

  using ::cos;


  inline _GLIBCXX_CONSTEXPR float
  cos(float __x)
  { return __builtin_cosf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  cos(long double __x)
  { return __builtin_cosl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    cos(_Tp __x)
    { return __builtin_cos(__x); }

  using ::cosh;


  inline _GLIBCXX_CONSTEXPR float
  cosh(float __x)
  { return __builtin_coshf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  cosh(long double __x)
  { return __builtin_coshl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    cosh(_Tp __x)
    { return __builtin_cosh(__x); }

  using ::exp;


  inline _GLIBCXX_CONSTEXPR float
  exp(float __x)
  { return __builtin_expf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  exp(long double __x)
  { return __builtin_expl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    exp(_Tp __x)
    { return __builtin_exp(__x); }

  using ::fabs;


  inline _GLIBCXX_CONSTEXPR float
  fabs(float __x)
  { return __builtin_fabsf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  fabs(long double __x)
  { return __builtin_fabsl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    fabs(_Tp __x)
    { return __builtin_fabs(__x); }

  using ::floor;


  inline _GLIBCXX_CONSTEXPR float
  floor(float __x)
  { return __builtin_floorf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  floor(long double __x)
  { return __builtin_floorl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    floor(_Tp __x)
    { return __builtin_floor(__x); }

  using ::fmod;


  inline _GLIBCXX_CONSTEXPR float
  fmod(float __x, float __y)
  { return __builtin_fmodf(__x, __y); }

  inline _GLIBCXX_CONSTEXPR long double
  fmod(long double __x, long double __y)
  { return __builtin_fmodl(__x, __y); }


  template<typename _Tp, typename _Up>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    fmod(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return fmod(__type(__x), __type(__y));
    }

  using ::frexp;


  inline float
  frexp(float __x, int* __exp)
  { return __builtin_frexpf(__x, __exp); }

  inline long double
  frexp(long double __x, int* __exp)
  { return __builtin_frexpl(__x, __exp); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    frexp(_Tp __x, int* __exp)
    { return __builtin_frexp(__x, __exp); }

  using ::ldexp;


  inline _GLIBCXX_CONSTEXPR float
  ldexp(float __x, int __exp)
  { return __builtin_ldexpf(__x, __exp); }

  inline _GLIBCXX_CONSTEXPR long double
  ldexp(long double __x, int __exp)
  { return __builtin_ldexpl(__x, __exp); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    ldexp(_Tp __x, int __exp)
    { return __builtin_ldexp(__x, __exp); }

  using ::log;


  inline _GLIBCXX_CONSTEXPR float
  log(float __x)
  { return __builtin_logf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  log(long double __x)
  { return __builtin_logl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    log(_Tp __x)
    { return __builtin_log(__x); }

  using ::log10;


  inline _GLIBCXX_CONSTEXPR float
  log10(float __x)
  { return __builtin_log10f(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  log10(long double __x)
  { return __builtin_log10l(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                    double>::__type
    log10(_Tp __x)
    { return __builtin_log10(__x); }

  using ::modf;


  inline float
  modf(float __x, float* __iptr)
  { return __builtin_modff(__x, __iptr); }

  inline long double
  modf(long double __x, long double* __iptr)
  { return __builtin_modfl(__x, __iptr); }


  using ::pow;


  inline _GLIBCXX_CONSTEXPR float
  pow(float __x, float __y)
  { return __builtin_powf(__x, __y); }

  inline _GLIBCXX_CONSTEXPR long double
  pow(long double __x, long double __y)
  { return __builtin_powl(__x, __y); }


  

  

  inline double
  pow(double __x, int __i)
  { return __builtin_powi(__x, __i); }

  inline float
  pow(float __x, int __n)
  { return __builtin_powif(__x, __n); }

  inline long double
  pow(long double __x, int __n)
  { return __builtin_powil(__x, __n); }



  template<typename _Tp, typename _Up>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    pow(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return pow(__type(__x), __type(__y));
    }

  using ::sin;


  inline _GLIBCXX_CONSTEXPR float
  sin(float __x)
  { return __builtin_sinf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  sin(long double __x)
  { return __builtin_sinl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    sin(_Tp __x)
    { return __builtin_sin(__x); }

  using ::sinh;


  inline _GLIBCXX_CONSTEXPR float
  sinh(float __x)
  { return __builtin_sinhf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  sinh(long double __x)
  { return __builtin_sinhl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    sinh(_Tp __x)
    { return __builtin_sinh(__x); }

  using ::sqrt;


  inline _GLIBCXX_CONSTEXPR float
  sqrt(float __x)
  { return __builtin_sqrtf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  sqrt(long double __x)
  { return __builtin_sqrtl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    sqrt(_Tp __x)
    { return __builtin_sqrt(__x); }

  using ::tan;


  inline _GLIBCXX_CONSTEXPR float
  tan(float __x)
  { return __builtin_tanf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  tan(long double __x)
  { return __builtin_tanl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    tan(_Tp __x)
    { return __builtin_tan(__x); }

  using ::tanh;


  inline _GLIBCXX_CONSTEXPR float
  tanh(float __x)
  { return __builtin_tanhf(__x); }

  inline _GLIBCXX_CONSTEXPR long double
  tanh(long double __x)
  { return __builtin_tanhl(__x); }


  template<typename _Tp>
    inline _GLIBCXX_CONSTEXPR
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    double>::__type
    tanh(_Tp __x)
    { return __builtin_tanh(__x); }

_GLIBCXX_END_NAMESPACE_VERSION
} 




















namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION


  constexpr int
  id14(float __x)
  { return __builtin_fpclassify(FP_NAN, FP_INFINITE, FP_NORMAL,
				FP_SUBNORMAL, FP_ZERO, __x); }

  constexpr int
  id14(double __x)
  { return __builtin_fpclassify(FP_NAN, FP_INFINITE, FP_NORMAL,
				FP_SUBNORMAL, FP_ZERO, __x); }

  constexpr int
  id14(long double __x)
  { return __builtin_fpclassify(FP_NAN, FP_INFINITE, FP_NORMAL,
				FP_SUBNORMAL, FP_ZERO, __x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              int>::__type
    id14(_Tp __x)
    { return __x != 0 ? FP_NORMAL : FP_ZERO; }

  constexpr bool
  isfinite(float __x)
  { return __builtin_isfinite(__x); }

  constexpr bool
  isfinite(double __x)
  { return __builtin_isfinite(__x); }

  constexpr bool
  isfinite(long double __x)
  { return __builtin_isfinite(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    isfinite(_Tp __x)
    { return true; }

  constexpr bool
  isinf(float __x)
  { return __builtin_isinf(__x); }

  constexpr bool
  isinf(double __x)
  { return __builtin_isinf(__x); }

  constexpr bool
  isinf(long double __x)
  { return __builtin_isinf(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    isinf(_Tp __x)
    { return false; }

  constexpr bool
  isnan(float __x)
  { return __builtin_isnan(__x); }

  constexpr bool
  isnan(double __x)
  { return __builtin_isnan(__x); }

  constexpr bool
  isnan(long double __x)
  { return __builtin_isnan(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    isnan(_Tp __x)
    { return false; }

  constexpr bool
  isnormal(float __x)
  { return __builtin_isnormal(__x); }

  constexpr bool
  isnormal(double __x)
  { return __builtin_isnormal(__x); }

  constexpr bool
  isnormal(long double __x)
  { return __builtin_isnormal(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    isnormal(_Tp __x)
    { return __x != 0 ? true : false; }

  

  constexpr bool
  signbit(float __x)
  { return __builtin_signbitf(__x); }

  constexpr bool
  signbit(double __x)
  { return __builtin_signbit(__x); }

  constexpr bool
  signbit(long double __x)
  { return __builtin_signbitl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value,
                                              bool>::__type
    signbit(_Tp __x)
    { return __x < 0 ? true : false; }

  constexpr bool
  isgreater(float __x, float __y)
  { return __builtin_isgreater(__x, __y); }

  constexpr bool
  isgreater(double __x, double __y)
  { return __builtin_isgreater(__x, __y); }

  constexpr bool
  isgreater(long double __x, long double __y)
  { return __builtin_isgreater(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
			    && __is_arithmetic<_Up>::__value), bool>::__type
    isgreater(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_isgreater(__type(__x), __type(__y));
    }

  constexpr bool
  id10(float __x, float __y)
  { return __builtin_isgreaterequal(__x, __y); }

  constexpr bool
  id10(double __x, double __y)
  { return __builtin_isgreaterequal(__x, __y); }

  constexpr bool
  id10(long double __x, long double __y)
  { return __builtin_isgreaterequal(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
			    && __is_arithmetic<_Up>::__value), bool>::__type
    id10(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_isgreaterequal(__type(__x), __type(__y));
    }

  constexpr bool
  isless(float __x, float __y)
  { return __builtin_isless(__x, __y); }

  constexpr bool
  isless(double __x, double __y)
  { return __builtin_isless(__x, __y); }

  constexpr bool
  isless(long double __x, long double __y)
  { return __builtin_isless(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
			    && __is_arithmetic<_Up>::__value), bool>::__type
    isless(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_isless(__type(__x), __type(__y));
    }

  constexpr bool
  id8(float __x, float __y)
  { return __builtin_islessequal(__x, __y); }

  constexpr bool
  id8(double __x, double __y)
  { return __builtin_islessequal(__x, __y); }

  constexpr bool
  id8(long double __x, long double __y)
  { return __builtin_islessequal(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
			    && __is_arithmetic<_Up>::__value), bool>::__type
    id8(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_islessequal(__type(__x), __type(__y));
    }

  constexpr bool
  id9(float __x, float __y)
  { return __builtin_islessgreater(__x, __y); }

  constexpr bool
  id9(double __x, double __y)
  { return __builtin_islessgreater(__x, __y); }

  constexpr bool
  id9(long double __x, long double __y)
  { return __builtin_islessgreater(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
			    && __is_arithmetic<_Up>::__value), bool>::__type
    id9(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_islessgreater(__type(__x), __type(__y));
    }

  constexpr bool
  isunordered(float __x, float __y)
  { return __builtin_isunordered(__x, __y); }

  constexpr bool
  isunordered(double __x, double __y)
  { return __builtin_isunordered(__x, __y); }

  constexpr bool
  isunordered(long double __x, long double __y)
  { return __builtin_isunordered(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename
    __gnu_cxx::__enable_if<(__is_arithmetic<_Tp>::__value
			    && __is_arithmetic<_Up>::__value), bool>::__type
    isunordered(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return __builtin_isunordered(__type(__x), __type(__y));
    }



  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    id14(_Tp __f)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_fpclassify(FP_NAN, FP_INFINITE, FP_NORMAL,
				  FP_SUBNORMAL, FP_ZERO, __type(__f));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    isfinite(_Tp __f)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_isfinite(__type(__f));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    isinf(_Tp __f)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_isinf(__type(__f));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    isnan(_Tp __f)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_isnan(__type(__f));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    isnormal(_Tp __f)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_isnormal(__type(__f));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    signbit(_Tp __f)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_signbit(__type(__f));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    isgreater(_Tp id6, _Tp id3)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_isgreater(__type(id6), __type(id3));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    id10(_Tp id6, _Tp id3)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_isgreaterequal(__type(id6), __type(id3));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    isless(_Tp id6, _Tp id3)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_isless(__type(id6), __type(id3));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    id8(_Tp id6, _Tp id3)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_islessequal(__type(id6), __type(id3));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    id9(_Tp id6, _Tp id3)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_islessgreater(__type(id6), __type(id3));
    }

  template<typename _Tp>
    inline typename __gnu_cxx::__enable_if<__is_arithmetic<_Tp>::__value,
					   int>::__type
    isunordered(_Tp id6, _Tp id3)
    {
      typedef typename __gnu_cxx::__promote<_Tp>::__type __type;
      return __builtin_isunordered(__type(id6), __type(id3));
    }



_GLIBCXX_END_NAMESPACE_VERSION
} 



















































































































namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  

  using ::double_t;
  using ::float_t;

  

  using ::acosh;
  using ::acoshf;
  using ::acoshl;

  using ::asinh;
  using ::asinhf;
  using ::asinhl;

  using ::atanh;
  using ::atanhf;
  using ::atanhl;

  using ::id13;
  using ::cbrtf;
  using ::cbrtl;

  using ::id4;
  using ::copysignf;
  using ::copysignl;

  using ::erf;
  using ::erff;
  using ::erfl;

  using ::erfc;
  using ::erfcf;
  using ::erfcl;

  using ::exp2;
  using ::exp2f;
  using ::exp2l;

  using ::id11;
  using ::expm1f;
  using ::expm1l;

  using ::fdim;
  using ::fdimf;
  using ::fdiml;

  using ::fma;
  using ::fmaf;
  using ::fmal;

  using ::fmax;
  using ::fmaxf;
  using ::fmaxl;

  using ::fmin;
  using ::fminf;
  using ::fminl;

  using ::hypot;
  using ::hypotf;
  using ::hypotl;

  using ::ilogb;
  using ::ilogbf;
  using ::ilogbl;

  using ::lgamma;
  using ::lgammaf;
  using ::lgammal;

  using ::id12;
  using ::llrintf;
  using ::llrintl;

  using ::llround;
  using ::llroundf;
  using ::llroundl;

  using ::id2;
  using ::log1pf;
  using ::log1pl;

  using ::log2;
  using ::log2f;
  using ::log2l;

  using ::logb;
  using ::logbf;
  using ::logbl;

  using ::lrint;
  using ::lrintf;
  using ::lrintl;

  using ::lround;
  using ::lroundf;
  using ::lroundl;

  using ::nan;
  using ::nanf;
  using ::nanl;

  using ::id7;
  using ::nearbyintf;
  using ::nearbyintl;

  using ::nextafter;
  using ::nextafterf;
  using ::nextafterl;

  using ::id1;
  using ::nexttowardf;
  using ::nexttowardl;

  using ::remainder;
  using ::remainderf;
  using ::remainderl;

  using ::remquo;
  using ::remquof;
  using ::remquol;

  using ::rint;
  using ::rintf;
  using ::rintl;

  using ::round;
  using ::roundf;
  using ::roundl;

  using ::id5;
  using ::scalblnf;
  using ::scalblnl;

  using ::id0;
  using ::scalbnf;
  using ::scalbnl;

  using ::tgamma;
  using ::tgammaf;
  using ::tgammal;

  using ::trunc;
  using ::truncf;
  using ::truncl;

  

  constexpr float
  acosh(float __x)
  { return __builtin_acoshf(__x); }

  constexpr long double
  acosh(long double __x)
  { return __builtin_acoshl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    acosh(_Tp __x)
    { return __builtin_acosh(__x); }

  constexpr float
  asinh(float __x)
  { return __builtin_asinhf(__x); }

  constexpr long double
  asinh(long double __x)
  { return __builtin_asinhl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    asinh(_Tp __x)
    { return __builtin_asinh(__x); }

  constexpr float
  atanh(float __x)
  { return __builtin_atanhf(__x); }

  constexpr long double
  atanh(long double __x)
  { return __builtin_atanhl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    atanh(_Tp __x)
    { return __builtin_atanh(__x); }

  constexpr float
  id13(float __x)
  { return __builtin_cbrtf(__x); }

  constexpr long double
  id13(long double __x)
  { return __builtin_cbrtl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    id13(_Tp __x)
    { return __builtin_cbrt(__x); }

  constexpr float
  id4(float __x, float __y)
  { return __builtin_copysignf(__x, __y); }

  constexpr long double
  id4(long double __x, long double __y)
  { return __builtin_copysignl(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    id4(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return id4(__type(__x), __type(__y));
    }

  constexpr float
  erf(float __x)
  { return __builtin_erff(__x); }

  constexpr long double
  erf(long double __x)
  { return __builtin_erfl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    erf(_Tp __x)
    { return __builtin_erf(__x); }

  constexpr float
  erfc(float __x)
  { return __builtin_erfcf(__x); }

  constexpr long double
  erfc(long double __x)
  { return __builtin_erfcl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    erfc(_Tp __x)
    { return __builtin_erfc(__x); }

  constexpr float
  exp2(float __x)
  { return __builtin_exp2f(__x); }

  constexpr long double
  exp2(long double __x)
  { return __builtin_exp2l(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    exp2(_Tp __x)
    { return __builtin_exp2(__x); }

  constexpr float
  id11(float __x)
  { return __builtin_expm1f(__x); }

  constexpr long double
  id11(long double __x)
  { return __builtin_expm1l(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    id11(_Tp __x)
    { return __builtin_expm1(__x); }

  constexpr float
  fdim(float __x, float __y)
  { return __builtin_fdimf(__x, __y); }

  constexpr long double
  fdim(long double __x, long double __y)
  { return __builtin_fdiml(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    fdim(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return fdim(__type(__x), __type(__y));
    }

  constexpr float
  fma(float __x, float __y, float __z)
  { return __builtin_fmaf(__x, __y, __z); }

  constexpr long double
  fma(long double __x, long double __y, long double __z)
  { return __builtin_fmal(__x, __y, __z); }

  template<typename _Tp, typename _Up, typename _Vp>
    constexpr typename __gnu_cxx::__promote_3<_Tp, _Up, _Vp>::__type
    fma(_Tp __x, _Up __y, _Vp __z)
    {
      typedef typename __gnu_cxx::__promote_3<_Tp, _Up, _Vp>::__type __type;
      return fma(__type(__x), __type(__y), __type(__z));
    }

  constexpr float
  fmax(float __x, float __y)
  { return __builtin_fmaxf(__x, __y); }

  constexpr long double
  fmax(long double __x, long double __y)
  { return __builtin_fmaxl(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    fmax(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return fmax(__type(__x), __type(__y));
    }

  constexpr float
  fmin(float __x, float __y)
  { return __builtin_fminf(__x, __y); }

  constexpr long double
  fmin(long double __x, long double __y)
  { return __builtin_fminl(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    fmin(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return fmin(__type(__x), __type(__y));
    }

  constexpr float
  hypot(float __x, float __y)
  { return __builtin_hypotf(__x, __y); }

  constexpr long double
  hypot(long double __x, long double __y)
  { return __builtin_hypotl(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    hypot(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return hypot(__type(__x), __type(__y));
    }

  constexpr int
  ilogb(float __x)
  { return __builtin_ilogbf(__x); }

  constexpr int
  ilogb(long double __x)
  { return __builtin_ilogbl(__x); }

  template<typename _Tp>
    constexpr
    typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                    int>::__type
    ilogb(_Tp __x)
    { return __builtin_ilogb(__x); }

  constexpr float
  lgamma(float __x)
  { return __builtin_lgammaf(__x); }

  constexpr long double
  lgamma(long double __x)
  { return __builtin_lgammal(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    lgamma(_Tp __x)
    { return __builtin_lgamma(__x); }

  constexpr long long
  id12(float __x)
  { return __builtin_llrintf(__x); }

  constexpr long long
  id12(long double __x)
  { return __builtin_llrintl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              long long>::__type
    id12(_Tp __x)
    { return __builtin_llrint(__x); }

  constexpr long long
  llround(float __x)
  { return __builtin_llroundf(__x); }

  constexpr long long
  llround(long double __x)
  { return __builtin_llroundl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              long long>::__type
    llround(_Tp __x)
    { return __builtin_llround(__x); }

  constexpr float
  id2(float __x)
  { return __builtin_log1pf(__x); }

  constexpr long double
  id2(long double __x)
  { return __builtin_log1pl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    id2(_Tp __x)
    { return __builtin_log1p(__x); }

  

  constexpr float
  log2(float __x)
  { return __builtin_log2f(__x); }

  constexpr long double
  log2(long double __x)
  { return __builtin_log2l(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    log2(_Tp __x)
    { return __builtin_log2(__x); }

  constexpr float
  logb(float __x)
  { return __builtin_logbf(__x); }

  constexpr long double
  logb(long double __x)
  { return __builtin_logbl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    logb(_Tp __x)
    { return __builtin_logb(__x); }

  constexpr long
  lrint(float __x)
  { return __builtin_lrintf(__x); }

  constexpr long
  lrint(long double __x)
  { return __builtin_lrintl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              long>::__type
    lrint(_Tp __x)
    { return __builtin_lrint(__x); }

  constexpr long
  lround(float __x)
  { return __builtin_lroundf(__x); }

  constexpr long
  lround(long double __x)
  { return __builtin_lroundl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              long>::__type
    lround(_Tp __x)
    { return __builtin_lround(__x); }

  constexpr float
  id7(float __x)
  { return __builtin_nearbyintf(__x); }

  constexpr long double
  id7(long double __x)
  { return __builtin_nearbyintl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    id7(_Tp __x)
    { return __builtin_nearbyint(__x); }

  constexpr float
  nextafter(float __x, float __y)
  { return __builtin_nextafterf(__x, __y); }

  constexpr long double
  nextafter(long double __x, long double __y)
  { return __builtin_nextafterl(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    nextafter(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return nextafter(__type(__x), __type(__y));
    }

  constexpr float
  id1(float __x, long double __y)
  { return __builtin_nexttowardf(__x, __y); }

  constexpr long double
  id1(long double __x, long double __y)
  { return __builtin_nexttowardl(__x, __y); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    id1(_Tp __x, long double __y)
    { return __builtin_nexttoward(__x, __y); }

  constexpr float
  remainder(float __x, float __y)
  { return __builtin_remainderf(__x, __y); }

  constexpr long double
  remainder(long double __x, long double __y)
  { return __builtin_remainderl(__x, __y); }

  template<typename _Tp, typename _Up>
    constexpr typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    remainder(_Tp __x, _Up __y)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return remainder(__type(__x), __type(__y));
    }

  inline float
  remquo(float __x, float __y, int* __pquo)
  { return __builtin_remquof(__x, __y, __pquo); }

  inline long double
  remquo(long double __x, long double __y, int* __pquo)
  { return __builtin_remquol(__x, __y, __pquo); }

  template<typename _Tp, typename _Up>
    inline typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    remquo(_Tp __x, _Up __y, int* __pquo)
    {
      typedef typename __gnu_cxx::__promote_2<_Tp, _Up>::__type __type;
      return remquo(__type(__x), __type(__y), __pquo);
    }

  constexpr float
  rint(float __x)
  { return __builtin_rintf(__x); }

  constexpr long double
  rint(long double __x)
  { return __builtin_rintl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    rint(_Tp __x)
    { return __builtin_rint(__x); }

  constexpr float
  round(float __x)
  { return __builtin_roundf(__x); }

  constexpr long double
  round(long double __x)
  { return __builtin_roundl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    round(_Tp __x)
    { return __builtin_round(__x); }

  constexpr float
  id5(float __x, long __ex)
  { return __builtin_scalblnf(__x, __ex); }

  constexpr long double
  id5(long double __x, long __ex)
  { return __builtin_scalblnl(__x, __ex); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    id5(_Tp __x, long __ex)
    { return __builtin_scalbln(__x, __ex); }
 
  constexpr float
  id0(float __x, int __ex)
  { return __builtin_scalbnf(__x, __ex); }

  constexpr long double
  id0(long double __x, int __ex)
  { return __builtin_scalbnl(__x, __ex); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    id0(_Tp __x, int __ex)
    { return __builtin_scalbn(__x, __ex); }

  constexpr float
  tgamma(float __x)
  { return __builtin_tgammaf(__x); }

  constexpr long double
  tgamma(long double __x)
  { return __builtin_tgammal(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    tgamma(_Tp __x)
    { return __builtin_tgamma(__x); }
 
  constexpr float
  trunc(float __x)
  { return __builtin_truncf(__x); }

  constexpr long double
  trunc(long double __x)
  { return __builtin_truncl(__x); }

  template<typename _Tp>
    constexpr typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, 
                                              double>::__type
    trunc(_Tp __x)
    { return __builtin_trunc(__x); }

_GLIBCXX_END_NAMESPACE_VERSION
} 














using namespace std;

typedef long long ll;

int main()
{
	int T;
    cin>>T;
    ll u,v,c,d;
    while(T--)
    {
        ll p,q;
        cin>>p>>q;
        ll res,r;
        if(p%q!=0)
        {
        	cout<<p<<endl;
        	continue;
        }
	    res=0,r=q;
	    FORR
	    {
		    if(r%i==0)
		    {
	            u=0,v=0,c=q;
		        WH(c,i)
		        	c/=i,u++;
		        c=p;
		        WH(c,i)
		        	c/=i,v++;
		        d=p;
		        for(int j=1;j<=v-u+1;j++)
		        	d/=i;
			    res=max(res,d);
			    WH(r,i)
			    	r/=i;
			}
		}
	    if(r>1)
	    {
            u=0,v=0,c=q;
	        WH(c,r)
	        	c/=r,u++;
	        c=p;
	        WH(c,r)
	        	c/=r,v++;
	        d=p;
	        for(int i=1;i<=v-u+1;i++)
	        	d/=r;
		    res=max(res,d);
        }
	    cout<<res<<endl;
    }
    return 0;
}
