#include QMK_KEYBOARD_H

enum layers {
  _ESCODEBAR = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define CTL_ESC  LCTL_T(KC_ESC)
#define CTL_ENT  RCTL_T(KC_ENT)
#define LSFT_SPC LSFT_T(KC_SPC)
#define RSFT_SPC RSFT_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ESCODEBAR] = LAYOUT_ortho_5x15( \
    _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQUAL, KC_BSPC, \
    _______, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS, \
    _______, CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT, CTL_ENT,  _______, \
    _______, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     _______,  KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_UP,    KC_RSFT, \
    _______, KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LSFT_SPC, RSFT_SPC, RAISE,   KC_RGUI,  KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN,  KC_RGHT \
  ),

  [_LOWER] = LAYOUT_ortho_5x15( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, KC_DEL, \
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_EQL,  KC_PLUS, KC_LBRC, KC_RBRC, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [_RAISE] = LAYOUT_ortho_5x15( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,       _______,     _______,        _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, G(KC_LEFT),    G(KC_DOWN),    G(KC_UP),    G(KC_RIGHT),    _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT,       KC_DOWN,       KC_UP,       KC_RIGHT,       _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SGUI(KC_LEFT), SGUI(KC_DOWN), SGUI(KC_UP), SGUI(KC_RIGHT), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,       _______,     _______,        _______ \
  ),

  [_ADJUST] = LAYOUT_ortho_5x15( \
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
