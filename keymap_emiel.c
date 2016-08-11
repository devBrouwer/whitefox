/*
	I changed keymap_common.h so I only have to define the keys my True Fox has.
	If you copy my keymaps either add a NO key on the: 
			-3th row 13th key
			-4th row 2nd key
			-5th row 7th key
	Or change keymap_common.h like I did
*/
#include "keymap_common.h"
#include "led_controller.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|F12| 16 keys
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del| 15 keys
     * |---------------------------------------------------------------|
     * | FN5  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU| 12k, 2k
     * |---------------------------------------------------------------| 
     * |  FN2   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |FN2| 1k, 13k
     * |---------------------------------------------------------------|
     * |Ctl |Alt |Gui |         Space         |Alt |FN5 |_|Lef|Dow|Rig| 6k, 3k
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV, F12,\
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,     DEL,\
        FN6,  A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,     MPLY,\
        FN2,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     UP,  SLCK,\
        LCTL,LALT,LGUI,               SPC,           RALT,FN6,     LEFT,DOWN,RGHT \
    ),
	//----------------------------------------------------------------------------------------
	/* Layer 1: Dvorak-layer
     * ,---------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |---------------------------------------------------------------|
     * |     | ' | , | . | P | Y | F | G | C | R | L | / | = |     |   |
     * |---------------------------------------------------------------|
     * |      | A | O | E | U | I | D | H | T  |N |S  |-  |        |   |
     * |---------------------------------------------------------------|
     * |        | ; | Q | J | X | B | M | W | V | Z |   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                    |   |   |   |___|   |   |   |
     * `---------------------------------------------------------------'
     */
    [1] = KEYMAP( \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,\
        TRNS,QUOT,COMM,DOT , P  , Y  , F  , G  , C  , R  , L  ,BSLS,EQL ,TRNS,    TRNS, \
        TRNS, A  , O  , E  , U  , I  , D  , H  , T  , N  , S  ,MINS,TRNS,    TRNS, \
        TRNS,SCLN, Q  , J  , K  , X  , B  , M  , W  , V  , Z  ,TRNS,    TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,    TRNS,TRNS,TRNS  \
    ),
	
	//----------------------------------------------------------------------------------------
	/* Shift Action Layer so shift-esc is ~
    	*/
	[2] = KEYMAP( \
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,    TRNS,TRNS,TRNS \
    ),
	//disable windows key and normal shift behaviour, for windows gaming
	[3] = KEYMAP( \
        TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        LSFT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS, \
        TRNS,TRNS,NO,               TRNS,          TRNS,TRNS,    TRNS,TRNS,TRNS \
    ),
	//swap windows and alt, to the more traditional positions
	[4] = KEYMAP( \
	TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS, \
        TRNS,LGUI,LALT,               TRNS,          TRNS,TRNS,    TRNS,TRNS,TRNS \
    ),
	
    //normal shift, for gaming
    [5] = KEYMAP( \
	TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        LSFT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,    TRNS,TRNS,TRNS \
    ),
    //----------------------------------------------------------------------------------------
	/* FN-layer
     * ,---------------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|VoM|Vo-|Vo+|
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |HM |PD |PU |END|   |   |   | DEL |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   | <-| DN| UP |->|   |   |        |   |
     * |---------------------------------------------------------------|
     * |         |   |   |   |   |MPRV|MPLY|MNXT|   |   |      | PU|FN1|
     * |---------------------------------------------------------------|
     * |    |FN4|FN3|                    |   |   |   |___| HM| PD|END|
     * `---------------------------------------------------------------'
     */
    [6] = KEYMAP( \
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, MUTE,VOLD,VOLU,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END ,TRNS,TRNS,TRNS,DEL ,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,DOWN, UP ,RGHT,TRNS,TRNS,TRNS,    TRNS, \
        FN5,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    PGUP,FN1, \
        TRNS,FN4,FN3,               TRNS,          TRNS,TRNS,    HOME,PGDN,END  \
    ),
	
};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MODS(0, MOD_LCTL), //UNUSED
	[1] = ACTION_LAYER_TOGGLE(1),
	[2] = ACTION_LAYER_MODS(2, MOD_LSFT),
	[3] = ACTION_LAYER_TOGGLE(3),
	[4] = ACTION_LAYER_TOGGLE(4),
	[5] = ACTION_LAYER_TOGGLE(5),
	[6] = ACTION_LAYER_MOMENTARY(6),
};
