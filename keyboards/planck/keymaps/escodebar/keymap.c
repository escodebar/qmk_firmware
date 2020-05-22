#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _ESCODEBAR,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  ESCODEBAR = SAFE_RANGE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ESCODEBAR] = LAYOUT_planck_grid(
  KC_TAB,         KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,           KC_F,            KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  LCTL_T(KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,           KC_D,            KC_H,    KC_T,    KC_N,    KC_S,    RCTL_T(KC_ENT), \
  KC_LSFT,        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,           KC_B,            KC_M,    KC_W,    KC_V,    KC_Z,    RSFT_T(KC_SLSH), \
  KC_CAPS,        KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LSFT_T(KC_SPC), RSFT_T(KC_SPC),  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, KC_CAPS \
),

[_LOWER] = LAYOUT_planck_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, KC_DEL, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_EQL,  KC_PLUS, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_RAISE] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, G(KC_LEFT),    G(KC_DOWN),    G(KC_UP),      G(KC_RGHT),    _______, \
  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       _______, \
  _______, _______, _______, _______, _______, _______, _______, SGUI(KC_LEFT), SGUI(KC_DOWN), SGUI(KC_UP),   SGUI(KC_RGHT), _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,       _______,       _______,       _______,       _______ \
),

[_ADJUST] = LAYOUT_planck_grid(
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_ASRP, KC_ASDN, KC_ASUP, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ESCODEBAR:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ESCODEBAR);
      }
      return false;
      break;
  }
  return true;
}
