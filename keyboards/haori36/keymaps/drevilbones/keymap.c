#include QMK_KEYBOARD_H

// A bunch of aliases for home row mod-taps to keep the layout pretty
// Left-hand home row mods
#define MT_A LSFT_T(KC_A)
#define MT_S LCTL_T(KC_S)
#define MT_D LGUI_T(KC_D)
#define MT_F LALT_T(KC_F)

// Right-hand home row mods
#define MT_J LALT_T(KC_J)
#define MT_K RGUI_T(KC_K)
#define MT_L RCTL_T(KC_L)
#define MT_SCLN RSFT_T(KC_SCLN)

// shift keys
#define LS_Z LSFT_T(KC_Z)
#define RS_SLSH RSFT_T(KC_SLSH)

// ctrl+arrows left and right, for moving between words
#define CT_LEFT LCTL(KC_LEFT)
#define CT_RGHT RCTL(KC_RGHT)

// shift+insert for linux clipboard paste
#define SH_INS LSFT(KC_INS)

enum layer_names {
  BASE,
  NAV,
  FUNC,
  SYM,
  NUMP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    MT_S,    MT_D,    MT_F,    KC_G,             KC_H,    MT_J,    MT_K,    MT_L,    KC_BSPC,
        LS_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  RS_SLSH,
                          MO(FUNC, MO(NAV), KC_ENT,  _______, MO(NAV), KC_SPC,  MO(FUNC)
    ),
    [NAV] = LAYOUT(
        KC_ESC,  _______, KC_PGUP, _______, _______,          CT_LEFT, _______, _______, CT_RGHT, _______,
        KC_TAB,  KC_HOME, KC_PGDN,  KC_END, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
        QK_LOCK, _______, _______, _______, _______,          _______, _______, _______, _______, QK_LOCK,
                          _______, _______, _______, _______, _______, _______, _______
    ),
    [FUNC] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        CW_TOGG, _______, _______, _______, _______,          _______, _______, _______, _______, KC_CAPS,
                          _______, _______, _______, _______, _______, _______, _______
    ),
    [SYM] = LAYOUT(
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______
    ),
    [NUMP] = LAYOUT(
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______
    ),

//    [2] = LAYOUT(
//        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
//                          _______, _______, _______, _______, _______, _______, _______
//    ),
};
