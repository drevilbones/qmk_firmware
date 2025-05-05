
 /* Copyright 2021 Dane Evans & 2024 Nick Scratch
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
  // SOFLE RGB
#include <stdio.h>
#include "keymap_introspection.h"
#include QMK_KEYBOARD_H

enum my_keycodes {
  MB1HLD = SAFE_RANGE
};

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

// Some other alias abbreviations
#define CT_LEFT LCTL(KC_LEFT)
#define CT_RGHT RCTL(KC_RGHT)

// default layer color: dull cyan
#define HSV_DEF 128, 255, 75

enum layer_names {
  BASE,
  GAME,
  NAVI,
  FUNC,
  MAUS,
  NUMP, 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT( //base
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_GRV,   KC_A,   MT_S,    MT_D,    MT_F,    KC_G,                      KC_H,    MT_J,   MT_K,    MT_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  _______,   _______, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LBRC, KC_RBRC, MO(3),   MO(2), KC_ENT,    MO(2),   KC_SPC,   MO(3),  KC_MINS, KC_EQL
),

[GAME] = LAYOUT( //games (disabling the tap-hold keys and shifting wasd over to turn it into esdf)
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL,  KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_B,   KC_Z,    KC_X,    KC_C,    KC_V,  _______,   _______, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_I,    KC_M,    KC_GRV,KC_LALT, MO(3),     KC_SPC,  KC_RALT, KC_RCTL,KC_MINS, KC_EQL 
),

[NAVI] = LAYOUT( //navigation
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,  KC_DEL,
  _______, _______, KC_PGUP, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_HOME, KC_PGDN, KC_END,  _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[FUNC] = LAYOUT( //function
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11,  
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_F12,
  _______, _______, _______, _______, _______, _______,                   CT_LEFT, _______, _______, CT_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______, TO(1),
                    _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, TO(0),   _______, TG(5)
),

[MAUS] = LAYOUT( //mouse
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, MS_BTN2, MS_BTN3, MS_BTN1, MB1HLD,                    _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[NUMP] = LAYOUT( //Numpad
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_NUM, XXXXXXX, XXXXXXX,XXXXXXX, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, XXXXXXX,
                    XXXXXXX, XXXXXXX, TG(5),   _______, _______, _______, _______, KC_P0,  KC_PDOT, XXXXXXX
)

/*
[8] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
*/

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MB1HLD:
      return false;
    default:
      return true;
  }
}


bool mb1held = false;
bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
      case MB1HLD:
        if (record->event.pressed) {
          if (mb1held) {
            SEND_STRING(SS_UP(X_BTN1));
            auto_mouse_toggle();
            mb1held = false;
          } else {
            SEND_STRING(SS_DOWN(X_BTN1));
            auto_mouse_toggle();
            mb1held = true;
          }
        }
        return true;
      default:
        return false;
    }
    return false;
}


void pointing_device_init_user(void) {
  set_auto_mouse_enable(true);
}

void keyboard_post_init_user(void) {
  rgb_matrix_sethsv(HSV_DEF);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(get_highest_layer(layer_state)) {
    case NAVI:
      if (clockwise) {
        tap_code(MS_WHLR);
      } else {
        tap_code(MS_WHLL);
      }
      break;
    case GAME:
    case FUNC:
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
      break;
    default:
      if (clockwise) {
        tap_code(MS_WHLD);
      } else {
        tap_code(MS_WHLU);
      }
  }
  return false;
 }


// index 0 and 36: indicator LEDs
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  hsv_t layer_color_hsv = (hsv_t){HSV_DEF};
  bool indicators = false;
  uint8_t layer = get_highest_layer(layer_state);
  switch(layer) {
    case GAME: //games
      layer_color_hsv = (hsv_t){HSV_RED};
      rgb_matrix_sethsv_noeeprom(HSV_RED);
      break;
    case NAVI: // nav
      layer_color_hsv = (hsv_t){HSV_GREEN};
      break;
    case FUNC: //func
      layer_color_hsv = (hsv_t){HSV_ORANGE};
      break;
    case MAUS: //mouse
      indicators = true;
      layer_color_hsv = (hsv_t){HSV_WHITE};
      break;
    case NUMP: //numpad
      layer_color_hsv = (hsv_t){HSV_PURPLE};
      break;
    default:
      rgb_matrix_sethsv_noeeprom(HSV_DEF);
      break;      
  }

  if (indicators) {
    rgb_matrix_set_color(0, RGB_CYAN);
    rgb_matrix_set_color(36, RGB_CYAN);
  } else {
    rgb_matrix_set_color(0, RGB_OFF);
    rgb_matrix_set_color(36, RGB_OFF);
 } 

  rgb_t lrgb = hsv_to_rgb(layer_color_hsv);

  for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t index = g_led_config.matrix_co[row][col];

        uint16_t kcatkml = keycode_at_keymap_location(layer, row, col);
        if (index >= led_min && index < led_max && index != NO_LED) {
          if (kcatkml == XXXXXXX) { rgb_matrix_set_color(index, RGB_OFF); } // if the key isn't active, turn LED off
          else if (kcatkml == KC_TRNS) { /* do nothing, just let it be the default color */ }
          else { rgb_matrix_set_color(index, lrgb.r, lrgb.g, lrgb.b); } // else make it the right color
        }
    }
  }
  return false;
}


// space saving
#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
#endif
#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void print_layer(void) {
  oled_set_cursor(0, 0);
  oled_write_P(PSTR("Layer"), false);

  uint8_t i;
  for (i = 5; i < 14; i++) {
    oled_set_cursor(0, i);
    if (i == 13 || i == 11 || i == 9 || i == 7) {
      oled_write_P(PSTR("\xAD\xCD\xCD\xCD\xB5"), false);
    } else if (i == 5) {
      oled_write_P(PSTR("\xAD\xCD\xCD\xCD\xB8"), false);
    } else {
      oled_write_ln_P(PSTR("    \xB3"), false);
    }
  }
  
  oled_set_cursor(0, 15);
  oled_write_P(PSTR("\xAD\xCD\xCD\xCD\xBE"), false);

  switch (get_highest_layer(layer_state)) {
      case BASE:
        oled_set_cursor(0, 14); 
        oled_write_P(PSTR("BASE\xB3"), false);
        break;        
      case GAME:
        oled_set_cursor(0, 14); 
        oled_write_P(PSTR("GAME\xB3"), false);
        break;
      case NAVI:
        oled_set_cursor(0, 12);
        oled_write_P(PSTR("NAVI\xB3"), false);
        break;
      case FUNC:
        oled_set_cursor(0, 10);
        oled_write_P(PSTR("FUNC\xB3"), false);
        break;
      case MAUS:
        oled_set_cursor(0, 8);
        oled_write_P(PSTR("MAUS\xB3"), false);
        break;
      case NUMP:
        oled_set_cursor(0, 6);
        oled_write_P(PSTR("NUMP\xB3"), false);
        break;
      default:
        oled_write_ln_P(PSTR("something is broken in layers"), false);
  }
}


void print_caps(void) {
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
      oled_set_cursor(0, 0);
      oled_write_P(PSTR("CAP"), false);
    } else {
      oled_set_cursor(0, 0);
      oled_write_P(PSTR("   "), false);
    }

    if (led_usb_state.num_lock) {
      oled_set_cursor(0, 6); 
      oled_write_P(PSTR("NUM"), false);
    } else {
      oled_set_cursor(0, 6);
      oled_write_P(PSTR("   "), false);
    }
}


bool oled_task_user(void) {
  if (is_keyboard_left()) {
    print_caps();
  } else {
    print_layer();
  }
  return false;
}

#endif //OLED_ENABLE
