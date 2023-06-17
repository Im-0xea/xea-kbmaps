#include QMK_KEYBOARD_H

enum planck_layers { _BASE, _COMPAT, _SPECIAL, _MOVE, _FUNCTION };

enum planck_keycodes { BASE = SAFE_RANGE, COMPAT };

/* clang-format off */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COMPAT] = LAYOUT_planck_grid(
    KC_TAB,      KC_QUOT, KC_COMM, KC_DOT,   KC_P,   KC_Y,   KC_F,    KC_G,    KC_C,      KC_R,          KC_L,    KC_BSPC,
    KC_ESC,      KC_A,    KC_O,    KC_E,     KC_U,   KC_I,   KC_D,    KC_H,    KC_T,      KC_N,          KC_S,    KC_ENT,
    MO(_SPECIAL),KC_SCLN, KC_Q,    KC_J,     KC_K,   KC_X,   KC_B,    KC_M,    KC_W,      KC_V,          KC_Z,    MO(_SPECIAL),
    KC_LCTL,     KC_LALT, KC_LGUI, MO(_MOVE),KC_SPC, KC_SPC, KC_BSPC, KC_LSFT, MO(_MOVE), MO(_FUNCTION), KC_RALT, KC_RCTL
),

[_BASE] = LAYOUT_planck_grid(
    KC_TAB,       KC_Q,    KC_W,    KC_E,      KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,      KC_O,          KC_P,    KC_BSPC,
    KC_ESC,       KC_A,    KC_S,    KC_D,      KC_F,   KC_G,   KC_H,    KC_J,    KC_K,      KC_L,          KC_SCLN, KC_ENT,
    MO(_SPECIAL), KC_Z,    KC_X,    KC_C,      KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM,   KC_DOT,        KC_SLSH, MO(_SPECIAL),
    KC_LCTL,      KC_LALT, KC_LGUI, MO(_MOVE), KC_SPC, KC_SPC, KC_BSPC, KC_LSFT, MO(_MOVE), MO(_FUNCTION), KC_RALT, KC_RCTL
),

[_SPECIAL] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_ASTR, KC_7,   KC_8,   KC_9,    KC_PLUS, KC_EQL,
    KC_PIPE, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_UNDS, KC_BSLS, KC_4,   KC_5,   KC_6,    KC_SLSH, KC_MINS,
    _______, KC_LBRC, KC_RBRC, KC_QUES, KC_TILD, KC_AMPR, _______, KC_1,   KC_2,   KC_3,    _______, _______,
    KC_LCTL, KC_LALT, KC_LGUI, _______, KC_SPC,  KC_SPC,  KC_BSPC, KC_LSFT,_______,_______, KC_RALT, KC_RCTL
),

[_MOVE] = LAYOUT_planck_grid(
    _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______,
    _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_FUNCTION] = LAYOUT_planck_grid(
    KC_F7,   KC_F8,   KC_F9,  KC_F17,  KC_F18, KC_F19,  _______, _______, _______, _______, _______, _______,
    KC_F4,   KC_F5,   KC_F6,  KC_F14,  KC_F15, KC_F16,  KC_F24,  BASE,    COMPAT,  _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,  KC_F11,  KC_F12, KC_F13,  KC_F21,  KC_F22,  KC_F23,  _______, _______, _______,
    _______, _______, _______,_______, KC_F10, _______, _______, _______, _______, _______, _______, _______
)
};

/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _SPECIAL, _MOVE, _FUNCTION);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
            break;
        case COMPAT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COMPAT);
            }
            return false;
            break;
        default:
    }
    return true;
}

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    return true;
}
