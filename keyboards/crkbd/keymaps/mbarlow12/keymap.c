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
 * Combos
 */
// enum combos {
//     JK_ESC
// };

// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(jk_combo, KC_ESC)
// };

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

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// scrolling state for drag scroll key
bool scrolling = false;

// update mouse record for scrolling when scroll pressed
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y * -1;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}


/*
 * QMK cannot use "shifted" keys as arguments to the mod-tap keys. So, we intercept
 * the key press and manually send the appropriate code.
 */

/*
 * Helper function for sending keycodes on tap
*/
bool fix_tap(keyrecord_t *rec, uint16_t send) {
    if (rec->event.pressed && rec->tap.count) {
        tap_code16(send);
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool retval = true;
    switch (keycode) {

        case ALT_AMP:
            retval = fix_tap(record, KC_AMPR);
            break;

        case CTL_RPN:
            retval = fix_tap(record, KC_RPRN);
                break;

        case SFT_LPN:
            retval = fix_tap(record, KC_LPRN);
            break;

        case CTL_DLR:
            retval = fix_tap(record, KC_DLR);
            break;

        case SFT_PCT:
            retval = fix_tap(record, KC_PERC);
            break;

        case ALT_CRC:
            retval = fix_tap(record, KC_CIRC);
            break;

        case GUI_CLN:
            retval = fix_tap(record, KC_COLN);
            break;

        case DRAG_SCROLL:
            if (record->event.pressed)
                scrolling = !scrolling;
            break;
        default:
            return true;
    }
    return retval;
}


