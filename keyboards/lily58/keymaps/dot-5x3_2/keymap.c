 /* Copyright 2020 Naoki Katahira
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
#include <stdio.h>

//extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _SYM,
  _NAV,
  _NUM,
};

#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define NUM MO(_NUM)

const uint16_t PROGMEM combo_tab[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_bck[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_bck, KC_BSPC),
    COMBO(combo_ent, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT(
  _______, _______, _______,  _______,  _______,  _______,                    _______, _______, _______, _______, _______, _______,
  _______, KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
  _______, KC_A,    KC_S,     KC_D,     KC_F,     KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  _______, KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,    _______,  _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                              _______,  _______,  NAV,     KC_LSFT,  KC_SPC,  SYM,     _______, _______
),

[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  _______, KC_GRV,  KC_LPRN, KC_LCBR, KC_LBRC, KC_LT,                      KC_GT,   KC_RBRC, KC_RCBR, KC_RPRN, KC_TILD, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_PIPE, KC_RCMD, KC_RCTL, KC_RALT, KC_RSFT, _______,
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,  _______, KC_UNDS, KC_PLUS, KC_QUOT, KC_DQT,  KC_BSLS, _______,
                             _______, _______, NUM,     KC_LSFT,  KC_SPC,  _______, _______, _______
),

[_NAV] = LAYOUT(
  _______, _______,   _______,   _______,    _______,    _______,                    _______, _______, _______, _______, _______, _______,
  _______, G(KC_TAB), G(KC_SPC), G(KC_LCBR), G(KC_RCBR), KC_VOLU,                    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_DEL,  _______,
  _______, KC_LSFT,   KC_LALT,   KC_LCTL,    KC_LCMD,    KC_VOLD,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, _______,
  _______, _______,   G(KC_DLR), G(KC_LBRC), G(KC_RBRC), KC_MPLY, _______,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENT,  _______,
                                 _______,    _______,    _______, KC_LSFT,  KC_SPC,  NUM,     _______, _______
),

[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_F11,  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_F12,  _______,
                             _______, _______, _______, KC_LSFT,  KC_SPC,  _______, _______, _______
  )
};
