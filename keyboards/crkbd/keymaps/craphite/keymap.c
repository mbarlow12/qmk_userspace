/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

/*
 * Keycodes
 */
enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    SYMBOL,
    NUMBER,
    NAV,
    FUNC,
    MT_SCLN,
    MT_LCBR,
    MT_AMPR,
    MT_LBRC,
    MT_LPN,
    MT_RPN,
    MT_DLR,
    MT_PCT,
    MT_CIRC,
    MT_COLN,
    DRAG_SCROLL
};

/*
 * Layers
 */
enum layers {
    _BASE,
    _SYMBOL,
    _NUMBER,
    _NAV,
    _FUNC,
    _COLEMAK
};


/*
 * Key Macros
 */
#define LC_ESC   LCTL_T(KC_ESC)
#define RC_ESC   RCTL_T(KC_ESC)
#define RC_ENT  RCTL_T(KC_ENT)
#define SFT_TAB  LSFT_T(KC_TAB)
#define OS_ALT OSM(KC_LALT)

/*
* Home Row Mods
*/
// #define GUI_ = LGUI_T(KC_)

// #define ALT_ = LALT_T(KC_)
// #define SFT_ = LSFT_T(KC_)
// #define CTL_ = LCTL_T(KC_)
// QWERTY
#define GUI_A    LGUI_T(KC_A)
#define ALT_S    LALT_T(KC_S)
#define SFT_D    LSFT_T(KC_D)
#define CTL_F    LCTL_T(KC_F)
#define GUI_SCLN RGUI_T(KC_SCLN)
#define ALT_L    RALT_T(KC_L)
#define SFT_K    RSFT_T(KC_K)
#define CTL_J    RCTL_T(KC_J)

// dealing with an issue where the home row mods are registering as shifted
// when pressed, e.g. SFT_PCT should be '(', but it's 9 maybe its the transparency?
// it's on both sides: and the number layer appears to be correct.
// SYM
// GUI_T(/) ALT_T($) SFT_T(%) CTL_T(^)      CTL_T(() SFT_T()) ALT_T(|) GUI_T(`)
// #define GUI_SCN   LGUI_T(MT_SCLN)
// #define ALT_LCB  LALT_T(MT_AMPR)
#define GUI_CLN  LGUI_T(MT_COLN)
#define GUI_GRV  LGUI_T(KC_GRV)
#define ALT_AMP  LALT_T(MT_AMPR)
#define SFT_LPN  LSFT_T(MT_LPN)
#define CTL_RPN  LCTL_T(MT_RPN)

#define CTL_DLR  LCTL_T(MT_DLR)
#define SFT_PCT  RSFT_T(MT_PCT)
#define ALT_CRC  RALT_T(MT_CIRC)


// NUM
#define CTL_4 RCTL_T(KC_4)
#define SFT_5 RSFT_T(KC_5)
#define ALT_6 RALT_T(KC_6)
#define GUI_MINS RGUI_T(KC_MINS)

// NAV
#define SFT_M2 LSFT_T(KC_BTN2)
#define CTL_M1 LCTL_T(KC_BTN1)
#define CTL_DN RCTL_T(KC_DOWN)
#define SFT_UP RSFT_T(KC_UP)
#define ALT_RT RALT_T(KC_RGHT)
#define GUI_WBK RGUI_T(KC_WBAK)

// FUNC
#define CTL_VOLU RCTL_T(KC_VOLU)
#define SFT_VOLD RSFT_T(KC_VOLD)
#define ALT_MSP  RALT_T(KC_MSTP)
#define GUI_MPL  RGUI_T(KC_MPLY)

// COLEMAK
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTRL_T LCTL_T(KC_T)
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I RALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

// Layer shifts
#define _SYM_SP_   LT(_SYMBOL, KC_SPC)
#define _SYM_ENT_   LT(_SYMBOL, KC_ENT)
#define _NUM_SP_   LT(_NUMBER, KC_SPC)
#define _NUM_ENT_   LT(_NUMBER, KC_ENT)
#define _NAVBSP_   LT(_NAV, KC_BSPC)
#define _NUMDEL_ LT(_NUMBER, KC_DEL)
#define _FN_ENT_   LT(_FUNC, KC_ENT)
#define _CM_TG_    DF(_COLEMAK)
#define _BS_TG_    DF(_BASE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   GUI_A,   ALT_S,   SFT_D,   CTL_F,    KC_G,                         KC_H,   CTL_J,   SFT_K,   ALT_L,GUI_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _CM_TG_,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _NUMDEL_,_SYM_SP_,_NAVBSP_,   _FN_ENT_,_SYM_SP_,  KC_TAB
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_MINS,                      KC_ASTR, KC_AMPR, KC_ASTR, KC_TILD, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, GUI_GRV, ALT_AMP, SFT_LPN, CTL_RPN, KC_UNDS,                       KC_EQL, CTL_DLR, SFT_PCT, ALT_CRC,GUI_MINS,  KC_DQT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, KC_TILD,                      KC_PLUS, KC_EXLM,   KC_AT, KC_HASH, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, KC_BSPC,     KC_ENT, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_MINS,                      KC_ASTR,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, GUI_GRV, ALT_AMP, SFT_LPN, CTL_RPN, KC_UNDS,                       KC_EQL,   CTL_4,   SFT_5,   ALT_6,GUI_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, KC_TILD,                      KC_PLUS,    KC_1,    KC_2,    KC_3, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1,  KC_TAB,                      KC_HOME, KC_PGUP, KC_PGDN,  KC_END,RCTL(KC_PGUP),RCTL(KC_PGDN),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                      KC_LEFT,  CTL_DN,  SFT_UP,  ALT_RT, GUI_WBK, KC_WFWD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  KC_CUT, KC_PAST, KC_COPY, DRAG_SCROLL,                  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  XXXXXXX,                      XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,  EE_CLR,
  //|--------+--------+--------+--------+--------| -------+-                   |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F5,   KC_F6,   KC_F7,  KC_F8,  XXXXXXX,                      KC_MUTE,CTL_VOLU,SFT_VOLD, ALT_MSP, GUI_MPL, DB_TOGG,
  //|--------+--------+--------+--------+--------| -------+-                   |--------+--------+--------+--------+--------+--------|
      QK_BOOT,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   GUI_A,   ALT_R,   SFT_S,  CTRL_T,    KC_G,                         KC_M,   CTL_N,   SFT_E,   ALT_I,   GUI_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _BS_TG_,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,_SYM_ENT_,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DEL,_NUM_SP_,_NAVBSP_,   _FN_ENT_,_SYM_SP_,  KC_TAB
                                      //`--------------------------'  `--------------------------'
  ),
};


#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
