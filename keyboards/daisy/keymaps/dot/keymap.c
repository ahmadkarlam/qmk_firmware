#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layer shorthand
#define _BL 0
#define _LW 1
#define _RS 2

enum {
 TD_BRACKET_LEFT = 0,
 TD_BRACKET_RIGHT,
};

void bracket_left_finish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LSFT);
    register_code(KC_9);
  } else if (state->count == 2) {
    register_code(KC_LBRC);
  } else {
    register_code(KC_LSFT);
    register_code(KC_LBRC);
  }
}

void bracket_left_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_LSFT);
    unregister_code(KC_9);
  } else if (state->count == 2) {
    unregister_code(KC_LBRC);
  } else {
    unregister_code(KC_LSFT);
    unregister_code(KC_LBRC);
  }
}

void bracket_right_finish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LSFT);
    register_code(KC_0);
  } else if (state->count == 2) {
    register_code(KC_RBRC);
  } else {
    register_code(KC_LSFT);
    register_code(KC_RBRC);
  }
}

void bracket_right_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_LSFT);
    unregister_code(KC_0);
  } else if (state->count == 2) {
    unregister_code(KC_RBRC);
  } else {
    unregister_code(KC_LSFT);
    unregister_code(KC_RBRC);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_BRACKET_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bracket_left_finish, bracket_left_reset),
 [TD_BRACKET_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bracket_right_finish, bracket_right_reset)
};

enum layer_keycodes {
    QWERTY = SAFE_RANGE, LOWER, RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,   KC_K,    KC_L,    _______,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SFTENT,
    TD(TD_BRACKET_LEFT), KC_LGUI, KC_LALT, LT(_LW, KC_SPC),  LT(_RS, KC_SPC), KC_RALT, KC_RGUI, TD(TD_BRACKET_RIGHT)
  ),

  [_LW] = LAYOUT(
    KC_GRV,  _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_0,    KC_DEL,
    _______, KC_EQL, KC_MINS, _______, KC_SCLN, KC_QUOT, KC_BSLS, KC_4, KC_5, KC_6, _______,
    _______, _______, _______, KC_SLSH, _______, _______, _______, KC_1, KC_2, KC_3, KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______, KC_VOLD
  ),

  [_RS] = LAYOUT(
    _______, KC_F1,   KC_F2,    KC_F3,   KC_F4, _______, _______, _______, _______, _______,  _______,  _______,
    _______, KC_F5,   KC_F6,   KC_F7, KC_F8, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
    _______, KC_F9,    KC_F10,   KC_F11,  KC_F12, RGB_TOG, RGB_MOD, _______, _______, BL_STEP,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),

};

const uint16_t PROGMEM fn_actions[] = {

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if(record->event.pressed){
        layer_on(_LW);
      } else {
        layer_off(_LW);
      }
      return false;
      break;
    case RAISE:
      if(record->event.pressed){
        layer_on(_RS);
      } else {
        layer_off(_RS);
      }
      return false;
      break;
  }
  return true;
};