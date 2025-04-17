/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum planck_layers {
  _FRN,
  _ADJ,
  _KBD,
  _MUS,
  _MOU
};

enum planck_keycodes {
  PLSO1 = SAFE_RANGE,
  PLSO2,
  PLSO3,
  PLSO4,
  PLSO5,
  PLSO6,
  PLSO7,
  PLSO8,
  PLSO9,
  PLSO0,
  PLSOS,
  PLSOM,
  PLSTO
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_FRN] = LAYOUT_ortho_4x12( //left side configured for gaming, right side is a num pad
          QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    QK_LOCK,  KC_NUM,   KC_P7,    KC_P8,    KC_P9,    KC_PSLS,    
          KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_I,     KC_BSPC,  KC_P4,    KC_P5,    KC_P6,    KC_PAST,    
          KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_K,     MO(_MUS), KC_P1,    KC_P2,    KC_P3,    KC_PMNS,    
          KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_SPC,  KC_LALT, KC_M,     MO(_ADJ), KC_P0,    KC_PDOT,  KC_ENT,   KC_PPLS),
        [_ADJ] = LAYOUT_ortho_4x12( //extended keys
          KC_TRNS,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_NO,    KC_CALC,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
          KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,    KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
          KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT,KC_TRNS, KC_TRNS, KC_NO,    MO(_KBD), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PENT,  TG(_MOU)),
        [_KBD] = LAYOUT_ortho_4x12( //Internal keyboard functions
          QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
          KC_NO,    KC_NO,    RGB_TOG,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO),          
        [_MUS] = LAYOUT_ortho_4x12( //dumb sfx to annoy everybody in the room
          AU_TOGG,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    PLSO7,    PLSO8,    PLSO9,    KC_NO,
          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    PLSO4,    PLSO5,    PLSO6,    PLSOM,
          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  PLSO1,    PLSO2,    PLSO3,    PLSOS,
          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  PLSO0,    PLSTO,    KC_NO,    KC_NO),
        [_MOU] = LAYOUT_ortho_4x12( //mouse keys on the number pad
           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BTN1,  KC_MS_U,  KC_BTN2, KC_TRNS,
           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_L,  KC_NO,    KC_MS_R, KC_WH_U,
           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BTN3,  KC_MS_D,  KC_BTN4, KC_WH_D,
           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_L,  KC_WH_R,  KC_TRNS, KC_TRNS)
};

        // [_TMP] = LAYOUT_ortho_4x12( //template
        //   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        //   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        //   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
        //   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO)

float close_encounters_5_note[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
float imperial_march[][2] = SONG(IMPERIAL_MARCH);
float coin_sound[][2] = SONG(COIN_SOUND);
float one_up_sound[][2] = SONG(ONE_UP_SOUND);
float zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
float zelda_treasure[][2] = SONG(ZELDA_TREASURE);
float mario_theme[][2] = SONG(MARIO_THEME);
float mario_gameover[][2] = SONG(MARIO_GAMEOVER);
float mario_mushroom[][2] = SONG(MARIO_MUSHROOM);
float to_boldly_go[][2] = SONG(TO_BOLDLY_GO);
float rick_roll[][2] = SONG(RICK_ROLL);
float e1m1[][2] = SONG(E1M1_DOOM);
float no_sound[][2] = SONG(NO_SOUND);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PLSO1:
        PLAY_SONG(close_encounters_5_note);
      return false;
      break;
    case PLSO2:
        PLAY_SONG(imperial_march);
      return false;
      break;
    case PLSO3:
        PLAY_SONG(coin_sound);
      return false;
      break;
    case PLSO4:
        PLAY_SONG(e1m1);
      return false;
      break;
    case PLSO5:
        PLAY_SONG(one_up_sound);
      return false;
      break;
    case PLSO6:
        PLAY_SONG(zelda_puzzle);
      return false;
      break;
    case PLSOM:
        PLAY_SONG(zelda_treasure);
      return false;
      break;
    case PLSO8:
        PLAY_SONG(mario_theme);
      return false;
      break;
    case PLSO9:
        PLAY_SONG(mario_gameover);
      return false;
      break;
    case PLSO7:
        PLAY_SONG(mario_mushroom);
      return false;
      break;
    case PLSO0:
        PLAY_SONG(to_boldly_go);
      return false;
      break;
    case PLSOS:
        PLAY_SONG(rick_roll);
      return false;
      break;
    case PLSTO:
        PLAY_SONG(no_sound);
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    default:
      return true;
  }
}
