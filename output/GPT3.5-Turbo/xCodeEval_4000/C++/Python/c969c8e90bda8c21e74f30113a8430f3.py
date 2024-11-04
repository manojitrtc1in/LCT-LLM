import math

pre = [
    4784, 4194, 4003, 3920, 3831, 3791, 3726, 3667, 3669, 3591, 3642, 3612, 3532, 3554, 3507, 3500, 3517, 3449, 3496, 3432,
    3462, 3406, 3394, 3376, 3378, 3445, 3362, 3368, 3371, 3305, 3369, 3386, 3336, 3320, 3302, 3273, 3356, 3286, 3307, 3284,
    3327, 3291, 3247, 3251, 3306, 3241, 3278, 3231, 3271, 3248, 3239, 3184, 3227, 3204, 3235, 3210, 3216, 3191, 3211, 3222,
    3193, 3206, 3234, 3157, 3149, 3191, 3188, 3193, 3225, 3192, 3182, 3138, 3152, 3135, 3106, 3167, 3211, 3130, 3141, 3137,
    3125, 3129, 3135, 3122, 3125, 3160, 3154, 3168, 3106, 3117, 3076, 3149, 3118, 3135, 3063, 3171, 3091, 3103, 3099, 3075,
    3087, 3126, 3071, 3086, 3114, 3074, 3101, 3069, 3091, 3080, 3080, 3101, 3067, 3111, 3079, 3117, 3093, 3089, 3103, 3073,
    3040, 3054, 3122, 3079, 3021, 3024, 3098, 3068, 3057, 3013, 3014, 3077, 3020, 3073, 3038, 3027, 3039, 3044, 3061, 3012,
    2998, 3043, 3054, 3066, 3018, 3025, 3037, 3035, 3015, 3010, 3004, 3014, 3018, 2931, 2994, 3015, 3025, 3032, 3075, 3031,
    2990, 2994, 3030, 2994, 3050, 2997, 2973, 3008, 3017, 3034, 2998, 2962, 3052, 2980, 2996, 3025, 3000, 2994, 2973, 3022,
    2961, 2981, 3039, 2964, 2968, 2941, 3016, 2992, 3014, 2978, 2983, 3006, 2970, 2968, 2999, 2936, 2985, 2983, 2950, 3034,
    2953, 2964, 2930, 2950, 2965, 2996, 2968, 2960, 2962, 2952, 2972, 2933, 3012, 2982, 3002, 2904, 2965, 2963, 2974, 3012,
    2915, 2921, 2947, 2908, 2934, 2998, 2925, 2951, 2971, 2936, 2986, 2949, 2951, 2958, 2936, 2930, 2957, 2895, 2926, 2934,
    2899, 2971, 3011, 2951, 2937, 2925, 2916, 2968, 2931, 2927, 2944, 2913, 2902, 2936, 2912, 2925, 2955, 2939, 2936, 2912,
    2935, 2905, 2928, 2956, 2968, 2923, 2953, 2902, 2938, 2928, 2928, 2902, 2886, 2942, 2873, 2980, 2886, 2911, 2920, 2922,
    2968, 2876, 2924, 2904, 2952, 2885, 2910, 2924, 2901, 2928, 2887, 2887, 2961, 2911, 2882, 2896, 2897, 2874, 2941, 2958,
    2898, 2926, 2916, 2933, 2873, 2969, 2886, 2907, 2938, 2845, 2855, 2898, 2883, 2900, 2902, 2887, 2889, 2877, 2905, 2879,
    2901, 2891, 2867, 2867, 2869, 2906, 2888, 2893, 2870, 2921, 2878, 2910, 2914, 2864, 2879, 2898, 2841, 2919, 2943, 2856,
    2817, 2837, 2899, 2823, 2901, 2878, 2824, 2888, 2880, 2906, 2855, 2854, 2907, 2902, 2862, 2859, 2918, 2890, 2835, 2847,
    2898, 2844, 2923, 2857, 2884, 2917, 2840, 2875, 2831, 2880, 2907, 2916, 2859, 2861, 2831, 2841, 2871, 2854, 2898, 2849,
    2905, 2896, 2903, 2868, 2835, 2845, 2853, 2926, 2874, 2849, 2832, 2876, 2859, 2885, 2887, 2853, 2913, 2828, 2842, 2820,
    2900, 2805, 2866, 2860, 2877, 2834, 2852, 2923, 2817, 2850, 2840, 2884, 2796, 2860, 2885, 2826, 2842, 2842, 2843, 2799,
    2817, 2871, 2909, 2841, 2853, 2791, 2809, 2854, 2815, 2832, 2818, 2866, 2800, 2872, 2877, 2865, 2774, 2846, 2881, 2890,
    2847, 2805, 2869, 2789, 2850, 2828, 2844, 2850, 2846, 2827, 2821, 2783, 2882, 2855, 2823, 2845, 2853, 2821, 2840, 2792,
    2822, 2788, 2859, 2846, 2819, 2805, 2890, 2830, 2846, 2881, 2755, 2890, 2829, 2813, 2862, 2820, 2835, 2828, 2871, 2810,
    2840, 2826, 2778, 2865, 2835, 2837, 2809, 2800, 2840, 2826, 2836, 2807, 2829, 2834, 2822, 2843, 2815, 2806, 2861, 2805,
    2786, 2842, 2792, 2813, 2841, 2840, 2817, 2827, 2795, 2816, 2780, 2799, 2796, 2897, 2789, 2820, 2738, 2852, 2791, 2818,
    2863, 2787, 2765, 2826, 2773, 2820, 2823, 2817, 2784, 2812, 2770, 2814, 2856, 2793, 2778, 2781, 2822, 2779, 2809, 2850,
    2793, 2835, 2765, 2790, 2760, 2869, 2785, 2801, 2769, 2866, 2861, 2767, 2812, 2767, 2790, 2765, 2841, 2805, 2816, 2811,
    2808, 2894, 2762, 2769, 2810, 2756, 2848, 2802, 2760, 2762, 2776, 2802, 2837, 2832, 2802, 2813, 2785, 2757, 2828, 2785,
    2791, 2765, 2781, 2835, 2755, 2835, 2779, 2784, 2802, 2765, 2765, 2800, 2756, 2746, 2808, 2797, 2802, 2800, 2830, 2795,
    2793, 2772, 2783, 2822, 2839, 2768, 2826, 2800, 2797, 2776, 2769, 2727, 2790, 2774, 2821, 2716, 2761, 2788, 2755, 2812,
    2854, 2782, 2796, 2789, 2746, 2762, 2767, 2807, 2770, 2774, 2784, 2805, 2744, 2805, 2772, 2761, 2768, 2844, 2807, 2778,
    2792, 2812, 2842, 2775, 2773, 2728, 2792, 2757, 2783, 2777, 2831, 2752, 2829, 2711, 2844, 2745, 2803, 2774, 2780, 2752,
    2791, 2809, 2749, 2806, 2771, 2777, 2801, 2768, 2725, 2786, 2728, 2779, 2792, 2809, 2820, 2767, 2745, 2771, 2768, 2815,
    2729, 2783, 2791, 2766, 2807, 2753, 2769, 2811, 2743, 2764, 2783, 2807, 2713, 2813, 2769, 2777, 2820, 2728, 2741, 2748,
    2765, 2791, 2760, 2745, 2781, 2788, 2755, 2741, 2739, 2746, 2767, 2767, 2808, 2735, 2778, 2787, 2766, 2695, 2826, 2731,
    2794, 2743, 2777, 2765, 2769, 2780, 2801, 2754, 2789, 2751, 2768, 2691, 2752, 2778, 2740, 2795, 2771, 2750, 2779, 2710,
    2718, 2741, 2764, 2799, 2749, 2788, 2741, 2785, 2768, 2735, 2761, 2728, 2759, 2777, 2809, 2775, 2738, 2771, 2786, 2776,
    2731, 2760, 2702, 2774, 2749, 2760, 2765, 2724, 2747, 2798, 2763, 2766, 2758, 2767, 2749, 2717, 2700, 2758, 2733, 2747,
    2734, 2766, 2764, 2765, 2728, 2757, 2705, 2792, 2683, 2754, 2773, 2739, 2720, 2747, 2781, 2726, 2769, 2756, 2734, 2698,
    2765, 2732, 2771, 2769, 2752, 2724, 2721, 2765, 2766, 2733, 2806, 2754, 2717, 2729, 2773, 2737, 2774, 2734, 2757, 2797,
    2772, 2680, 2716, 2745, 2736, 2758, 2746, 2748, 2776, 2777, 2723, 2669, 2760, 2689, 2758, 2748, 2750, 2718, 2809, 2824,