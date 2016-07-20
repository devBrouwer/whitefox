/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "keymap_common.h"

#include "led_controller.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|Ins| 16 keys
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del| 15 keys
     * |---------------------------------------------------------------|
     * | FN2  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU| 12k, NO, 2k
     * |---------------------------------------------------------------| 
     * |  FN3   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD| 1k, NO, 13k
     * |---------------------------------------------------------------|
     * |Ctl |Gui |Alt |         Space         |Alt |FN2 |  |Lef|Dow|Rig| 6k, NO, 3k
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV, INS,\
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,     DEL,\
        FN2,  A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,ENT,     PGUP,\
        FN3,NO,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     UP,  PGDN,\
        LCTL,LGUI,LALT,               SPC,           RALT,FN2,NO,     LEFT,DOWN,RGHT \
    ),
	/* Layer 1: Dvorak-layer
     * ,---------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |---------------------------------------------------------------|
     * |     | ' | , | . | P | Y | F | G | C | R | L | / | = |     |   |
     * |---------------------------------------------------------------|
     * |      | A | O | E | U | I | D | H | T  |N |S  |-  |NO|     |   |
     * |---------------------------------------------------------------|
     * |    |NO | ; | Q | J | X | B | M | W | V | Z |   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                    |   |   |   | NO|   |   |   |
     * `---------------------------------------------------------------'
     */
    [1] = KEYMAP( \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,\
        TRNS,QUOT,COMM,DOT , P  , Y  , F  , G  , C  , R  , L  ,BSLS,EQL ,TRNS,    TRNS, \
        TRNS, A  , O  , E  , U  , I  , D  , H  , T  , N  , S  ,MINS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,SCLN, Q  , J  , K  , X  , B  , M  , W  , V  , Z  ,TRNS,    PGUP,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,    HOME,PGDN,END  \
    ),
	/* Layer 2: FN-layer
     * ,---------------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|VoM|Vo-|Vo+|
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |HM |PD |PU |END|   |   |   | DEL |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   | <-| DN| UP |->|   |   |NO|     |   |
     * |---------------------------------------------------------------|
     * |    |NO |   |   |   |   |   |   |   |   |   |   |      | PU|FN1|
     * |---------------------------------------------------------------|
     * |    |    |    |                    |   |   |   | NO| HM| PD|END|
     * `---------------------------------------------------------------'
     */
    [2] = KEYMAP( \
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, MUTE,VOLD,VOLU,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END ,TRNS,TRNS,TRNS,DEL ,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN, UP ,RGHT,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    PGUP,FN1, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,    HOME,PGDN,END  \
    ),
	/* Layer 3: Shift Action Layer so shift-esc is ~
     * ,---------------------------------------------------------------.
     * | ` |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |NO|     |   |
     * |---------------------------------------------------------------|
     * |    |NO |   |   |   |   |   |   |   |   |   |   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                    |   |   |   | NO|   |   |   |
     * `---------------------------------------------------------------'
     */
	[3] = KEYMAP( \
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS \
    ),
	
	
};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MODS(0, MOD_LCTL),
	[1] = ACTION_LAYER_TOGGLE(1),
	[2] = ACTION_LAYER_MOMENTARY(2),
	[3] = ACTION_LAYER_MODS(3, MOD_LSFT),
};
