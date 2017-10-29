/* -*- Mode:C; c-basic-offset:2; tab-width:2; indent-tabs-mode:nil; evil-indent-convert-tabs:t; -*- */

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

/**
 * See `readme.md` for notes on each define.
 */

/**
 * Optionally support 80 key layout.
 *
 * No default keys defined: use 'CFQ_USER_K80_L0K0' .. etc.
 */
/* #define CFQ_USE_80_KEYS */

/** Personal preference (enable by passing 'EXTRAFLAGS=...' to make). */
/* #define CFQ_USE_MOMENTARY_LAYER_KEYS */

/** Holding right/left or left/right shift for single or double quote pair */
/* #define CFQ_USE_SHIFT_QUOTES */

#define CFQ_USE_DYNAMIC_MACRO


// keep enabled for now
#define CFQ_USE_DYNAMIC_MACRO

#if !defined(CFQ_USER_KEY1)
#define CFQ_USER_KEY1 KC_SPC
#endif
#if !defined(CFQ_USER_KEY2)
#define CFQ_USER_KEY2 KC_ENT
#endif
#if !defined(CFQ_USER_KEY3)
#define CFQ_USER_KEY3 CFQ_KC_FN3
#endif
#if !defined(CFQ_USER_KEY4)
#define CFQ_USER_KEY4 KC_APP
#endif

/**
 * Used to generate lines below:
 * \code{.py}
 * text = '#  ifndef CFQ_USER_K80_L0K0\n#    define CFQ_USER_K80_L0K0 KC_TRNS\n#  endif'
 * print('\n'.join([text.replace('L0', f'L{l}').replace('K0', f'K{k}') for l in range(3) for k in range(4)]))
 * \endcode
 */
#ifdef CFQ_USE_80_KEYS
#  ifndef CFQ_USER_K80_L0K0
#    define CFQ_USER_K80_L0K0 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L0K1
#    define CFQ_USER_K80_L0K1 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L0K2
#    define CFQ_USER_K80_L0K2 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L0K3
#    define CFQ_USER_K80_L0K3 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L1K0
#    define CFQ_USER_K80_L1K0 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L1K1
#    define CFQ_USER_K80_L1K1 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L1K2
#    define CFQ_USER_K80_L1K2 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L1K3
#    define CFQ_USER_K80_L1K3 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L2K0
#    define CFQ_USER_K80_L2K0 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L2K1
#    define CFQ_USER_K80_L2K1 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L2K2
#    define CFQ_USER_K80_L2K2 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L2K3
#    define CFQ_USER_K80_L2K3 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L3K0
#    define CFQ_USER_K80_L3K0 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L3K1
#    define CFQ_USER_K80_L3K1 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L3K2
#    define CFQ_USER_K80_L3K2 KC_TRNS
#  endif
#  ifndef CFQ_USER_K80_L3K3
#    define CFQ_USER_K80_L3K3 KC_TRNS
#  endif
#endif

#ifndef CFQ_WORD_A
#define CFQ_WORD_A ""
#endif
#ifndef CFQ_WORD_B
#define CFQ_WORD_B ""
#endif
#ifndef CFQ_WORD_C
#define CFQ_WORD_C ""
#endif
#ifndef CFQ_WORD_D
#define CFQ_WORD_D ""
#endif
#ifndef CFQ_WORD_E
#define CFQ_WORD_E ""
#endif
#ifndef CFQ_WORD_F
#define CFQ_WORD_F ""
#endif
#ifndef CFQ_WORD_G
#define CFQ_WORD_G ""
#endif
#ifndef CFQ_WORD_H
#define CFQ_WORD_H ""
#endif
#ifndef CFQ_WORD_I
#define CFQ_WORD_I ""
#endif
#ifndef CFQ_WORD_J
#define CFQ_WORD_J ""
#endif
#ifndef CFQ_WORD_K
#define CFQ_WORD_K ""
#endif
#ifndef CFQ_WORD_L
#define CFQ_WORD_L ""
#endif
#ifndef CFQ_WORD_M
#define CFQ_WORD_M ""
#endif
#ifndef CFQ_WORD_N
#define CFQ_WORD_N ""
#endif
#ifndef CFQ_WORD_O
#define CFQ_WORD_O ""
#endif
#ifndef CFQ_WORD_P
#define CFQ_WORD_P ""
#endif
#ifndef CFQ_WORD_Q
#define CFQ_WORD_Q ""
#endif
#ifndef CFQ_WORD_R
#define CFQ_WORD_R ""
#endif
#ifndef CFQ_WORD_S
#define CFQ_WORD_S ""
#endif
#ifndef CFQ_WORD_T
#define CFQ_WORD_T ""
#endif
#ifndef CFQ_WORD_U
#define CFQ_WORD_U ""
#endif
#ifndef CFQ_WORD_V
#define CFQ_WORD_V ""
#endif
#ifndef CFQ_WORD_W
#define CFQ_WORD_W ""
#endif
#ifndef CFQ_WORD_X
#define CFQ_WORD_X ""
#endif
#ifndef CFQ_WORD_Y
#define CFQ_WORD_Y ""
#endif
#ifndef CFQ_WORD_Z
#define CFQ_WORD_Z ""
#endif

/* lower and title capitals versions (setup at start). */
static char *cfq_word_lut[2][26] = {
  {
    CFQ_WORD_A, CFQ_WORD_B, CFQ_WORD_C, CFQ_WORD_D, CFQ_WORD_E, CFQ_WORD_F,
    CFQ_WORD_G, CFQ_WORD_H, CFQ_WORD_I, CFQ_WORD_J, CFQ_WORD_K, CFQ_WORD_L,
    CFQ_WORD_M, CFQ_WORD_N, CFQ_WORD_O, CFQ_WORD_P, CFQ_WORD_Q, CFQ_WORD_R,
    CFQ_WORD_S, CFQ_WORD_T, CFQ_WORD_U, CFQ_WORD_V, CFQ_WORD_W, CFQ_WORD_X,
    CFQ_WORD_Y, CFQ_WORD_Z,
  },
  {NULL}
};

/* Storage for title-caps strings. */
static char cfq_word_lut_title_caps[
    sizeof(CFQ_WORD_A) + sizeof(CFQ_WORD_B) + sizeof(CFQ_WORD_C) + sizeof(CFQ_WORD_D) +
    sizeof(CFQ_WORD_E) + sizeof(CFQ_WORD_F) + sizeof(CFQ_WORD_G) + sizeof(CFQ_WORD_H) +
    sizeof(CFQ_WORD_I) + sizeof(CFQ_WORD_J) + sizeof(CFQ_WORD_K) + sizeof(CFQ_WORD_L) +
    sizeof(CFQ_WORD_M) + sizeof(CFQ_WORD_N) + sizeof(CFQ_WORD_O) + sizeof(CFQ_WORD_P) +
    sizeof(CFQ_WORD_Q) + sizeof(CFQ_WORD_R) + sizeof(CFQ_WORD_S) + sizeof(CFQ_WORD_T) +
    sizeof(CFQ_WORD_U) + sizeof(CFQ_WORD_V) + sizeof(CFQ_WORD_W) + sizeof(CFQ_WORD_X) +
    sizeof(CFQ_WORD_Y) + sizeof(CFQ_WORD_Z)
];

#define LAYER_BASE 0 /* default layer */
#define LAYER_KPAD 1 /* keypad */
#define LAYER_MDIA 2 /* media keys */
#define LAYER_FKEY 3 /* F-Keys & Words */

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
#ifdef CFQ_USE_DYNAMIC_MACRO
  DYNAMIC_MACRO_RANGE,
#endif
};

#ifdef CFQ_USE_DYNAMIC_MACRO
#include "dynamic_macro.h"
#endif

// macros
#ifdef CFQ_USE_EXPEREMENTAL_LAYER
#define M_SPACES_1 2
#define M_SPACES_2 3
#define M_SPACES_3 4
#define M_SPACES_4 5
#define M_SPACES_5 6
#define M_SPACES_6 7
#define M_SPACES_7 8
#define M_SPACES_8 9
#endif
#define M_BRACKET_IN_CBR 10
#define M_BRACKET_IN_PRN 11
#define M_BRACKET_IN_BRC 12
#define M_BRACKET_IN_ANG 13
#define M_BRACKET_OUT_CBR 14
#define M_BRACKET_OUT_PRN 15
#define M_BRACKET_OUT_BRC 16
#define M_BRACKET_OUT_ANG 17
#define M_ARROW_RMINUS 18
#define M_ARROW_LMINUS 19
#define M_ARROW_REQL 20
#define M_ARROW_LEQL 21

#ifdef CFQ_USE_MOMENTARY_LAYER_KEYS
#define CFQ_KC_FN1 MO(1)
#define CFQ_KC_FN2 MO(2)
#define CFQ_KC_FN3 MO(3)
#else
#define CFQ_KC_FN1 KC_FN1
#define CFQ_KC_FN2 KC_FN2
#define CFQ_KC_FN3 KC_FN3
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grave  |   !  |   @  |   #  |   $  |   %  |   {  |           |  }   |   ^  |   &  |   *  |   -  |   =  | BSpace |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   (  |           |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|   [  |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl |Super | Alt  | USR4 |Space |                                       | Left | Down | Up   |Right | Del  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ins  | USR3 |       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | ~L2  |       | PgUp |      |      |
 *                                 | USR1 | USR2 |------|       |------|Enter |Space |
 *                                 |      |      | ~L1  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */

/* If it accepts an argument (i.e, is a function), it doesn't need KC_.
 * Otherwise, it needs KC_* */
[LAYER_BASE] = LAYOUT_ergodox_76_or_80(  /* layer 0 : default */
  /* left hand */
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH,       KC_DLR, KC_PERC, KC_LCBR,
  KC_TAB,  KC_Q,    KC_W,    KC_E,          KC_R,   KC_T,    KC_LPRN,
  KC_ESC,  KC_A,    KC_S,    KC_D,          KC_F,   KC_G,
  KC_LSFT, KC_Z,    KC_X,    KC_C,          KC_V,   KC_B,    KC_LBRC,
  KC_LCTL, KC_LGUI, KC_LALT, CFQ_USER_KEY4, KC_SPC,
                                                    KC_INS,        CFQ_USER_KEY3,
                                                                   CFQ_KC_FN2,
                                     CFQ_USER_KEY1, CFQ_USER_KEY2, CFQ_KC_FN1,
  // right hand
  KC_RCBR,     KC_CIRC, KC_AMPR, KC_ASTR,KC_MINS, KC_EQL,    KC_BSPC,
  KC_RPRN,     KC_Y,    KC_U,    KC_I,   KC_O,    KC_P,      KC_BSLS,
               KC_H,    KC_J,    KC_K,   KC_L,    KC_SCLN,   KC_QUOT,
  KC_RBRC,     KC_N,    KC_M,    KC_COMM,KC_DOT,  KC_SLSH,   KC_RSFT,
                        KC_LEFT, KC_DOWN,KC_UP,   KC_RGHT,   CFQ_USER_KEY8,
  KC_HOME, KC_END,
  KC_PGUP, K80(L0K2),  K80(L0K3),
  KC_PGDN, CFQ_KC_FN2, KC_ENT
),
/* Keymap 1: KeyPad, Macro Record
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  {}  |           |  }{  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |  =>  |  ()  |           |  )(  |  <=  |   7  |   8  |   9  |   \  |   F11  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |  ->  |------|           |------|  <-  |   4  |   5  |   6  |   *  |   F12  |
 * |--------+------+------+------+------+------|  []  |           |  ][  |------+------+------+------+------+--------|
 * |        |      |      |      |      |  <>  |      |           |      |  ><  |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |   .  |   +  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |Start1|Start2|       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Stop |       |      |        |      |
 *                                 |Play1 |Play2 |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
/* KEYPAD & MACRO */
[LAYER_KPAD] = LAYOUT_ergodox_76_or_80(
  /* left hand */
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          M_BRACKET_IN_CBR,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_ARROW_REQL,     M_BRACKET_IN_PRN,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_ARROW_RMINUS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_BRACKET_IN_ANG, M_BRACKET_IN_BRC,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
#ifdef CFQ_USE_DYNAMIC_MACRO
                               DYN_REC_START1, DYN_REC_START2,
                                               DYN_REC_STOP,
                              DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_TRNS,
#else
                                      KC_TRNS, KC_TRNS,
                                               KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS,
#endif
  // right hand
  M(M_BRACKET_OUT_CBR), KC_F6,                KC_F7,   KC_F8,   KC_F9,     KC_F10,         KC_TRNS,
  M(M_BRACKET_OUT_PRN), M(M_ARROW_LEQL),      KC_KP_7, KC_KP_8, KC_KP_9,   KC_KP_SLASH,    KC_F11,
                        M(M_ARROW_LMINUS),    KC_KP_4, KC_KP_5, KC_KP_6,   KC_KP_ASTERISK, KC_F12,
  M(M_BRACKET_OUT_BRC), M(M_BRACKET_OUT_ANG), KC_KP_1, KC_KP_2, KC_KP_3,   KC_KP_MINUS,    KC_TRNS,
                                              KC_KP_0, KC_TRNS, KC_KP_DOT, KC_KP_PLUS,     KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS, K80(L1K2), K80(L1K3),
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: FKeys, media & mouse keys
 *
 * .--------------------------------------------------.  .--------------------------------------------------.
 * |        |      |      |      |      |      |      |  | Mute |      |  F10 |  F11 |  F12 |      |        |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |MWhlUp|  |VolUp |      |  F7  |  F8  |  F9  |      |        |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|  |------|      |  F4  |  F5  |  F6  |      |        |
 * |--------+------+------+------+------+------|MWhlDn|  |VolDn |------+------+------+------+------+--------|
 * |        |      | Rclk | Mclk | Lclk |      |      |  |      |      |  F1  |  F2  |  F3  |      |        |
 * '--------+------+------+------+------+-------------'  '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                              |      |      |      |      |      |
 *   '----------------------------------'                              '----------------------------------'
 *                                      .-------------.  .-------------.
 *                                      |      |      |  | MRwd | MFwd |
 *                               .------+------+------|  |------+------+------.
 *                               |      |      |      |  | MPrv |      |      |
 *                               |      |      |------|  |------|      | Play |
 *                               |      |      |      |  | MNxt |      |      |
 *                               '--------------------'  '--------------------'
 */
/* MEDIA, MOUSE & NUMBERS */
[LAYER_MDIA] = LAYOUT_ergodox_76_or_80(
  /* left hand */
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_WH_U,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN3, KC_BTN1, KC_TRNS, KC_WH_D,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS,   KC_TRNS,
                           K80(L2K0), K80(L2K1), KC_TRNS,
                           KC_TRNS,   KC_TRNS,   KC_TRNS,
  /* right hand */
  KC_MUTE,  KC_TRNS, KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
  KC_VOLU,  KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_TRNS, KC_TRNS,
            KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_TRNS,
  KC_VOLD,  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_TRNS, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_MRWD, KC_MFFD,
  KC_MPRV, K80(L2K2), K80(L2K3),
  KC_MNXT, KC_TRNS, KC_MPLY
),
/* Keymap 3: Entire Words (one for each key) & Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |  {   |   }  |      |   }  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  (   |   )  |      |   )  |           |      | Spc7 | Spc8 |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  [   |   ]  |      |------|           |------| Spc4 | Spc5 | Spc6 |      |      |        |
 * |--------+------+------+------+------+------|   ]  |           |      |------+------+------+------+------+--------|
 * |        |      |      |  <   |   >  |      |      |           |      | Spc1 | Spc2 | Spc3 |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// EXPERIMENT
[EXPR] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR,    KC_RCBR,    KC_TRNS, KC_RCBR,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN,    KC_RPRN,    KC_TRNS, KC_RPRN,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC,    KC_RBRC,	 KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, S(KC_COMM), S(KC_DOT),  KC_TRNS, KC_RBRC,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,
                                         KC_TRNS, KC_TRNS,
                                                  KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, M(M_SPACES_7), M(M_SPACES_8), KC_TRNS,       KC_TRNS, KC_TRNS,
           KC_TRNS, M(M_SPACES_4), M(M_SPACES_5), M(M_SPACES_6), KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, M(M_SPACES_1), M(M_SPACES_2), M(M_SPACES_3), KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS, K80(L3K2), K80(L3K3),
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(LAYER_KPAD),               /* FN1 - Momentary Layer 1 (KeyPad) */
  [2] = ACTION_LAYER_TAP_TOGGLE(LAYER_MDIA),               /* FN2 - Momentary Layer 2 (Media, Mouse) */
  [3] = ACTION_LAYER_TAP_TOGGLE(LAYER_FKEY),               /* FN3 - Momentary Layer 3 (FKey's & Words) */
};

#define WITHOUT_MODS(...) \
  do { \
    uint8_t _real_mods = get_mods(); \
    clear_mods(); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CFQ_USE_DYNAMIC_MACRO
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
#endif
  switch (keycode) {
    /* dynamically generate these. */
    case RGB_SLD:
      if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
#endif
      }
      return false;
      break;
    case M_BRACKET_IN_CBR:  /* {} */
      if (record->event.pressed) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACKET_IN_PRN:  /* () */
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACKET_IN_BRC:  /* [] */
      if (record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACKET_IN_ANG:  /* <> */
      if (record->event.pressed) {
        SEND_STRING("<>" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACKET_OUT_CBR:  /* }{ */
      if (record->event.pressed) {
        SEND_STRING("}{" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACKET_OUT_PRN:  /* )( */
      if (record->event.pressed) {
        SEND_STRING(")(" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACKET_OUT_BRC:  /* ][ */
      if (record->event.pressed) {
        SEND_STRING("][" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_BRACKET_OUT_ANG:  /* >< */
      if (record->event.pressed) {
        SEND_STRING("><" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case M_ARROW_LMINUS:  /* <- */
      if (record->event.pressed) {
        SEND_STRING("<-");
        return false;
      }
      break;
    case M_ARROW_RMINUS:  /* -> */
      if (record->event.pressed) {
        SEND_STRING("->");
        return false;
      }
      break;
    case M_ARROW_LEQL:  /* <= */
      if (record->event.pressed) {
        SEND_STRING("<=");
        return false;
      }
      break;
    case M_ARROW_REQL:  /* => */
      if (record->event.pressed) {
        SEND_STRING("=>");
        return false;
      }
      break;
#ifdef CFQ_USE_SHIFT_QUOTES
    case KC_LSHIFT:  /* '' */
      if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_RSFT)))) {
        WITHOUT_MODS({
            SEND_STRING("''" SS_TAP(X_LEFT) SS_DOWN(X_RSHIFT) SS_DOWN(X_LSHIFT));
          });
        return false;
      }
      break;
    case KC_RSHIFT:  /* "" */
      if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_LSFT)))) {
        WITHOUT_MODS({
            SEND_STRING("\x22\x22" SS_TAP(X_LEFT) SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT));
          });
        return false;
      }
      break;
#endif  /* CFQ_USE_SHIFT_QUOTES */
    case M_WORD_A...M_WORD_Z:
    {
      uint8_t shift_index = (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) ? 1 : 0;
      const char *word = cfq_word_lut[shift_index][keycode - M_WORD_A];
      if (record->event.pressed) {
        if (*word) {
          WITHOUT_MODS({
              send_string(word);
            });
        }
        return false;
      }
      break;
    }
  }

  return true;
}

/* Runs just one time when the keyboard initializes. */
void matrix_init_user(void) {

  /* Duplicate 'cfq_word_lut[0][...]' into 'cfq_word_lut[1][...]' */
  {
    char *d = cfq_word_lut_title_caps;
    for (uint16_t i = 0; i < 26; i++) {
      char *s = cfq_word_lut[0][i];
      cfq_word_lut[1][i] = d;
      while ((*d++ = *s++)) {}
    }
  }
  /* Title caps. */
  for (uint16_t i = 0; i < 26; i++) {
    char *w = cfq_word_lut[1][i];
    bool prev_is_alpha = false;
    if (*w) {
      while (*w) {
        bool is_lower = (*w >= 'a' && *w <= 'z');
        bool is_upper = (*w >= 'A' && *w <= 'Z');
        if (prev_is_alpha == false && is_lower) {
          *w -= ('a' - 'A');
        }
        prev_is_alpha = is_lower || is_upper;
        w++;
      }
    }
  }
};

/* Runs constantly in the background, in a loop. */
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    default:
      /* none */
      break;
  }

};
