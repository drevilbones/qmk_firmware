/* Copyright 2021 Jay Greco & 2024 Nick Scratch
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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
           KC_NUM,  KC_BSPC, KC_PSLS,
    KC_P7, KC_P8,   KC_P9,   KC_PAST,
    KC_P4, KC_P5,   KC_P6,   KC_PMNS,
    KC_P1, KC_P2,   KC_P3,   KC_PPLS,
    KC_P0, KC_PDOT, LT(1,KC_PEQL), KC_PENT
    ),

    [1] = LAYOUT(
             _______, RGB_TOG, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    TG(2),   _______, _______, _______
    ),

    [2] = LAYOUT(
             _______, _______, QK_BOOT,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
    )
};

void keyboard_post_init_user(void) {
  rgblight_setrgb(RGB_RED);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 2:
      rgblight_setrgb(RGB_GREEN);
      break;
    default:
      rgblight_setrgb(RGB_RED);
      break;
  }
  return state;
}
