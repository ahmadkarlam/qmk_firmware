#include QMK_KEYBOARD_H

enum combos {
    WF_LBRC,
    FP_SH9,
    XC_SGRV,
    CV_GRV,

    LU_RBRC,
    UY_SH0,
    LY_QOT,
    MCOM_BSLSH,
    COMDOT_SBSLSH,

    COMBO_LENGTH,
};

// Left side
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
// Right side
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ly_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // Left side
    [WF_LBRC] = COMBO(wf_combo, KC_LBRC),
    [FP_SH9] = COMBO(fp_combo, S(KC_9)),
    [XC_SGRV] = COMBO(xc_combo, S(KC_GRV)),
    [CV_GRV] = COMBO(cv_combo, KC_GRV),
    // Right side
    [LU_RBRC] = COMBO(lu_combo, S(KC_0)),
    [UY_SH0] = COMBO(uy_combo, KC_RBRC),
    [LY_QOT] = COMBO(ly_combo, KC_QUOT),
    [MCOM_BSLSH] = COMBO(mcom_combo, KC_BSLS),
    [COMDOT_SBSLSH] = COMBO(comdot_combo, S(KC_BSLS))
};

enum layer_number {
  _DEF = 0,
  _SYM,
  _NAV,
  _FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DEF
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |  Tab | Esc  | /BSpace /       \Space \  |Enter |  Del |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_DEF] = LAYOUT(
  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_NO,
  KC_NO,  CTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_D,                    KC_H,    RSFT_T(KC_N),    RALT_T(KC_E),    RGUI_T(KC_I),    RCTL_T(KC_O), KC_NO,
  KC_NO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_NO,             KC_NO,            KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                           KC_NO,   LGUI_T(KC_TAB),  LCTL_T(KC_ESC), LT(_NAV, KC_BSPC), LT(_SYM, KC_SPC), LSFT_T(KC_ENT),  RALT_T(KC_DEL),  KC_NO
),
/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   \  |   7  |   8  |   9  |   ,  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ^  |   &  |   *  |   _  |   -  |-------.    ,-------|   0  |   4  |   5  |   6  |   .  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |   =  |   +  |-------|    |-------|   ;  |   1  |   2  |   3  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |  Gui |Space | /BSpace /       \[HOLD]\  |Shift |  Alt |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______,    _______,                   _______, _______, _______, _______,  _______, _______,
  _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4),    S(KC_5),                   KC_BSLS, KC_7,    KC_8,    KC_9,     KC_COMM, _______,
  _______, S(KC_6), S(KC_7), S(KC_8), S(KC_MINS), KC_MINS,                   KC_0,    KC_4,    KC_5,    KC_6,     KC_DOT,  _______,
  _______, _______, _______, _______, KC_EQL,    S(KC_EQL), _______, _______, KC_SCLN, KC_1,    KC_2,    KC_3,     KC_SLSH, _______,
                             _______, KC_LGUI,    KC_SPC,  _______, _______, KC_LSFT, KC_LALT, _______
),

[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_VOLU,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______,
  _______, _______, _______, _______, _______, KC_VOLD,                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, KC_MPLY,  _______, _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                             _______, KC_LGUI, KC_LCTL,  _______, _______, KC_LSFT, KC_LALT, _______
),

[_FUN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      _______, _______, _______, _______, _______, _______,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_F11,  KC_F12,  _______, _______,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NAV, _FUN);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
