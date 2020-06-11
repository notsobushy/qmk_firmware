/* Notsobushy
 * Planck Layout
 * v5
 */


#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Light| Ctrl | Alt  | Del  |  GUI | Space| Lower| Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    BL_STEP, KC_LCTL, KC_LALT, LT(ADJUST, KC_DEL),  KC_LGUI, KC_SPC,  LOWER,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  - _ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  = + |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   |  |   _  |   +  |   -  |   /  |   *  |   =  |   [  |   ]  |  \ | |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ADJUST|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    _______, KC_BSLS, KC_PIPE, KC_UNDS, KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, ADJUST, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Prev | Play | Next |      | MLeft|  MUp |MRight|      |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Vol- | Mute | Vol+ |      |  M1  | MDown|  M2  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |ADJUST|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_MS_L, KC_MS_U, KC_MS_R, _______, KC_F12,
    _______, _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, KC_BTN1, KC_MS_D, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______, ADJUST,  _______, _______, _______, _______, _______
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug |TermOn|TermOf|      |      |QWERTY|LOWER |RAISE |ADJUST|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BLBrea|BLDown|BL Up |BL Off|BL On |GUI/CT|CT/GUI|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|MUSmod|Audio |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   TERM_ON, TERM_OFF, _______, _______, DF(_QWERTY), DF(_LOWER), DF(_RAISE), DF(_ADJUST), _______,
    BL_BRTG, BL_DEC,  BL_INC,  BL_OFF,  BL_ON,    LCG_SWP, LCG_NRM, _______,     _______,    _______,    _______,     _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,   _______, _______,  MU_MOD,     AU_TOG,     _______,     _______,     _______,
    _______, _______, _______, _______, _______,  _______, _______, _______,     _______,    _______,    _______,     _______
)

};

/*
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
    case RAISE:
    case LOWER:
    case ADJUST:
      return false;
    default:
      return true;
  }
}
*/
