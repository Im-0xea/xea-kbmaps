#include QMK_KEYBOARD_H

#define KC_BSPW LCTL(KC_BSPC)

enum levinson_layers { _BASE, _COMPAT, _SPECIAL, _SPECIAL_COMPAT, _MOVE, _FUNCTION };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_4x12(
    KC_TAB,      KC_QUOT, KC_COMM, KC_DOT,   KC_P,   KC_Y,   KC_F,    KC_G,    KC_C,      KC_R,          KC_L,    KC_BSPC,
    KC_ESC,      KC_A,    KC_O,    KC_E,     KC_U,   KC_I,   KC_D,    KC_H,    KC_T,      KC_N,          KC_S,    KC_ENT,
    MO(_SPECIAL),KC_SCLN, KC_Q,    KC_J,     KC_K,   KC_X,   KC_B,    KC_M,    KC_W,      KC_V,          KC_Z,    MO(_SPECIAL),
    KC_LCTL,     KC_LALT, KC_LGUI, MO(_MOVE),KC_SPC, KC_SPC, KC_BSPW, KC_LSFT, MO(_MOVE), MO(_FUNCTION), KC_RALT, KC_RCTL
),

[_COMPAT] = LAYOUT_ortho_4x12(
    KC_TAB,              KC_Q,    KC_W,    KC_E,      KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,      KC_O,          KC_P,    KC_BSPC,
    KC_ESC,              KC_A,    KC_S,    KC_D,      KC_F,   KC_G,   KC_H,    KC_J,    KC_K,      KC_L,          KC_SCLN, KC_ENT,
    MO(_SPECIAL_COMPAT), KC_Z,    KC_X,    KC_C,      KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM,   KC_DOT,        KC_SLSH, MO(_SPECIAL_COMPAT),
    KC_LCTL,             KC_LALT, KC_LGUI, MO(_MOVE), KC_SPC, KC_SPC, KC_BSPW, KC_LSFT, MO(_MOVE), MO(_FUNCTION), KC_RALT, KC_RCTL
),

[_SPECIAL] = LAYOUT_ortho_4x12(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_ASTR, KC_7,   KC_8,   KC_9,    KC_PLUS, KC_EQL,
    KC_PIPE, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_UNDS, KC_BSLS, KC_4,   KC_5,   KC_6,    KC_SLSH, KC_MINS,
    _______, KC_LBRC, KC_RBRC, KC_QUES, KC_TILD, KC_AMPR, XXXXXXX, KC_1,   KC_2,   KC_3,    XXXXXXX, _______,
    KC_LCTL, KC_LALT, KC_LGUI, _______, KC_SPC,  KC_SPC,  KC_BSPC, KC_LSFT,KC_0,   _______, KC_RALT, KC_RCTL
),

[_SPECIAL_COMPAT] = LAYOUT_ortho_4x12(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_ASTR, KC_7,   KC_8,   KC_9,    KC_RCBR, KC_RBRC,
    KC_PIPE, KC_UNDS, KC_PLUS, KC_LPRN, KC_RPRN, KC_DQUO, KC_BSLS, KC_4,   KC_5,   KC_6,    KC_LBRC, KC_QUOT,
    _______, KC_MINUS, KC_EQL, KC_LCBR, KC_TILD, KC_AMPR, XXXXXXX, KC_1,   KC_2,   KC_3,    XXXXXXX, _______,
    KC_LCTL, KC_LALT, KC_LGUI, _______, KC_SPC,  KC_SPC,  KC_BSPC, KC_LSFT,KC_0,   _______, KC_RALT, KC_RCTL
),

[_MOVE] = LAYOUT_ortho_4x12(
    _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______,
    _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_FUNCTION] = LAYOUT_ortho_4x12(
    KC_F7,   KC_F8,   KC_F9,  KC_F17,  KC_F18, KC_F19,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F4,   KC_F5,   KC_F6,  KC_F14,  KC_F15, KC_F16,  KC_F24,  DF(_BASE), DF(_COMPAT),  XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F1,   KC_F2,   KC_F3,  KC_F11,  KC_F12, KC_F13,  KC_F21,  KC_F22,    KC_F23,  XXXXXXX, XXXXXXX, _______,
    _______, _______, _______,_______, KC_F10, _______, XXXXXXX, XXXXXXX,   _______, _______, XXXXXXX, XXXXXXX
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
