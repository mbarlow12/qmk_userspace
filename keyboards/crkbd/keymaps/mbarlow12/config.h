/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_RIGHT
// #define MASTER_LEFT
// #define EE_HAND#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100
#define TAPPING_TERM 200
// #define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD



#ifdef HOLD_ON_OTHER_KEY_PRESS
    #undef HOLD_ON_OTHER_KEY_PRESS
#endif

// #define COMBO_COUNT 2
// #define COMBO_TERM 40

// #define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
// #define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */

// cirque 35 pointing configuration
#ifdef POINTING_DEVICE_DRIVER_cirque_pinnacle_i2c
#define CIRQUE_PINNACLE_DIAMETER_MM 35
// Tap for left click.
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
