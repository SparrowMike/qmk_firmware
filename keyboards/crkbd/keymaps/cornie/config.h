#pragma once

#define MASTER_LEFT

#ifdef RGBLIGHT_ENABLE
    /* #define RGBLIGHT_EFFECT_BREATHING */
    /* #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    /* #define RGBLIGHT_EFFECT_SNAKE */
    /* #define RGBLIGHT_EFFECT_KNIGHT */
    /* #define RGBLIGHT_EFFECT_CHRISTMAS */
    /* #define RGBLIGHT_EFFECT_STATIC_GRADIENT */
    /* #define RGBLIGHT_EFFECT_RGB_TEST */
    /* #define RGBLIGHT_EFFECT_ALTERNATING */
    /* #define RGBLIGHT_EFFECT_TWINKLE */
    /* #define RGBLIGHT_LIMIT_VAL 120 */
    /* #define RGBLIGHT_HUE_STEP 10 */
    /* #define RGBLIGHT_SAT_STEP 17 */
    /* #define RGBLIGHT_VAL_STEP 17 */
#endif

#define TAPPING_TERM 200

#ifdef OLED_DRIVER_ENABLE
#    include "oled_driver.h"
#    define OLED_RENDER_WPM_COUNTER " WPM: "
#endif

#ifdef BONGO_ENABLE
// #    define BONGO_ENABLE
#    include "./animation/bongo.h"
#endif

#ifdef LUNA_ENABLE
#    include "luna.h"
#endif

#ifdef OCEAN_DREAM_ENABLE
#    include "./animation/ocean_dream.h"
#endif
