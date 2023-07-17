 /* Copyright 2020 Naoki Katahira
  * Copyright 2023 Elliot Powell
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

enum layer_number {
  _QWERTY = 0,
  _NUMBER,
  _SYMBOL,
  _NAV,
  _MOUSE,
  _RGB,
};

#define KC_I_COPY LGUI(KC_C)
#define KC_I_PASTE LGUI(KC_V)
#define KC_I_CUT LGUI(KC_X)
#define KC_I_UNDO LGUI(KC_Z)
#define KC_I_REDO LSG(KC_Z)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                                        ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                                        |   6  |   7  |   8  |   9  |   0  |  ~   |
 * |------+------+------+------+------+------|                                        |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                        |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                                        |------+------+------+------+------+------|
 * |LCTRL |   A|Shift  |   S|ctrl  |   D|alt  |   F|gui  |   G  |-------.    ,-------|   H  |   J|gui  |   K|alt  |   L|ctrl  |   ;|shift  |  '   |
 * |------+------+------+------+------+------|   [   |                                |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|                                |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /                                 \      \-----------------------------------------'
 *                   |LALT | LGUI |tab|nav| Space|mouse/                              \Enter|symbol|backspace|number | delete | RGB |
 *                   |      |      |      |/       /                                     \      \ |      |      |      |
 *                   `-------------------''-------'                                       '------''--------------------'
"LSFT_T(KC_A)", "LCTL_T(KC_S)", "LALT_T(KC_D)", "LGUI_T(KC_F)", "KC_G", "KC_H", "RGUI_T(KC_J)", "RALT_T(KC_K)", "RCTL_T(KC_L)", "RSFT_T(KC_SCLN)",
"KC_LALT", "KC_LGUI", "LT(3,KC_TAB)", "LT(4,KC_SPC)", "KC_ENT", "LT(1,KC_LGUI)", "LT(2,KC_AGIN)", "KC_RGUI"
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  LSFT_T(KC_A),   LCTL_T(KC_S),    LALT_T(KC_D),    LGUI_T(KC_F),    KC_G,                    KC_H,    RGUI_T(KC_J),    RALT_T(KC_K),    RCTL_T(KC_L),    RSFT_T(KC_SCLN), KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,                                           KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                    KC_LALT, KC_LGUI,  LT(_NAV,KC_SPC), LT(_MOUSE,KC_TAB),                         LT(_SYMBOL,KC_ENT),   LT(_NUMBER,KC_BSPC),  KC_DEL, MO(_RGB)
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   |  |   `  |   +  |   {  |   }  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_NUMBER] = LAYOUT(
  TO(_QWERTY),   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,                                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, KC_7, KC_8,   KC_9, XXXXXXX,  XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_4, KC_5,    KC_6,    XXXXXXX,    XXXXXXX,                      XXXXXXX, KC_RIGHT_GUI, KC_RIGHT_ALT, KC_RIGHT_SHIFT, KC_RIGHT_CTRL, XXXXXXX,
  XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, KC_EQUAL, KC_0, KC_MINUS, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTOG|RGBHUI|RGBSAI|RGBVAI|      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |RGBMOD|RGBHUD|RGBSAD|RGBVAD|      |      |-------|    |-------|   +  |   =  |   [  |   ]  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_RGB] = LAYOUT(
  TO(_QWERTY),   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,                                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
                TO(_QWERTY), TO(_QWERTY), TO(_QWERTY),  TO(_QWERTY), TO(_QWERTY),  TO(_QWERTY), TO(_QWERTY), TO(_QWERTY)
),

/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NAV] = LAYOUT(
  TO(_QWERTY),   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,                                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_F1, KC_I_CUT, KC_I_COPY,  KC_I_PASTE, KC_I_UNDO, XXXXXXX,                                     KC_I_REDO, KC_I_UNDO, KC_I_PASTE, KC_I_COPY, KC_I_CUT, XXXXXXX,
  XXXXXXX, KC_LEFT_SHIFT, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENTER,  KC_BACKSPACE, KC_DEL, XXXXXXX
  ),

  /* MOUSE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
    [_MOUSE] = LAYOUT(
    TO(_QWERTY),   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,                                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_F1, KC_I_CUT, KC_I_COPY,  KC_I_PASTE, KC_I_UNDO, XXXXXXX,                                    KC_I_REDO, KC_I_UNDO, KC_I_PASTE, KC_I_COPY, KC_I_CUT, XXXXXXX,
    XXXXXXX, KC_LEFT_SHIFT, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI, XXXXXXX,                   XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, XXXXXXX,
                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN1,  KC_MS_BTN2, KC_MS_BTN3, _______
    ),

    /* LOWER
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|   |  |   `  |   +  |   {  |   }  |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `-------------------''-------'           '------''--------------------'
    */
    [_SYMBOL] = LAYOUT(
  TO(_QWERTY),   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,                                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                               XXXXXXX, KC_RIGHT_GUI, KC_RIGHT_ALT, KC_RIGHT_SHIFT, KC_RIGHT_CTRL, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_RIGHT_BRACKET, KC_RIGHT_CURLY_BRACE, KC_RIGHT_PAREN, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, KC_LEFT_BRACKET, KC_LEFT_CURLY_BRACE, KC_LEFT_PAREN, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  )
};


