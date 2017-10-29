# ErgoDox EZ Code Friendly Qwerty Layout

- This layout aims to balance muscle memory from a typical QWERTY layout
  with having keys used for software development easily accessible.

  The this layout is a normalized qwerty,
  with some configurable keys left thumb cluster so you can use it more as needed.

- Arrow keys follow VIM convention
  (the media layer even uses arrow keys for HJKL).

- On the top row only symbols are used (not numbers),
  it's expected the symbol layer's number-pad layout will be used for numbers.

- Symbols match regular QWERTY.
  except for '()' which are grouped with other brackets.
  In their place -/= keys are placed, which almost matches a regular layout.

- Brackets are placed symmetrically along the center edges,
  if using keys from both sides is inconvenient - the symbol layer has macros
  at the same key locations to type matching pairs.

- The space-bar on the lower-left looks like it's in an obscure location,
  however using the larger thumb cluster
  ended up being more of a reach while typing.

## Configuration

Some optional behavior is configurable without editing the code
using `CFQ_` prefixed defines which can be set by passing `EXTRAFLAGS` to make.

- `CFQ_USER_KEY1` (1..4) are used for custom-keys
- `CFQ_USE_MOMENTARY_LAYER_KEYS` is used to prevent layer keys from toggling when tapped.
- `CFQ_USE_SWAP_RIGHT_SPACE_ENTER` swap Enter and Space on the right hand thumb cluster.
  While asymmetric, it makes Enter more easily accessible.
- `CFQ_USE_EXPEREMENTAL_LAYER` defines an extra layer for misc extra keys/macros.
  Currently it's mostly empty.

  Holding LShift, then RShift types: "" (then presses left).

  Holding RShift, then LShift types: '' (then presses left).

- `CFQ_WORD_[A-Z]`
  defines can bind a key to an entire user defined word.

- `CFQ_USE_80_KEYS`
  enables 80 key layout, none of the extra keys are bound,
  they need to be set with defines: `CFQ_USER_K80_L0K0` .. `CFQ_USER_K80_L3K4`.
  Where `L#` is the layer and `K#` is the key.

- `USR1` defaults to `KC_SPC`, otherwise use `CFQ_USER_KEY1`.
- `USR2` defaults to `KC_ENT`, otherwise use `CFQ_USER_KEY2`.
- `USR3` defaults to `KC_FN3`, otherwise use `CFQ_USER_KEY3`.
- `USR4` defaults to `APP`, otherwise use `CFQ_USER_KEY4`.

```
,--------------------------------------------------.           ,--------------------------------------------------.
| Grave  |   !  |   @  |   #  |   $  |   %  |   {  |           |  }   |   ^  |   &  |   *  |   -  |   =  | BSpace |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
| Tab    |   Q  |   W  |   E  |   R  |   T  |   (  |           |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
| Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
|--------+------+------+------+------+------|   [  |           |  ]   |------+------+------+------+------+--------|
| LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  | LCtl |Super | Alt  | USR4 |Space |                                       | Left | Down | Up   |Right | Del  |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       | Ins  | USR3 |       | Home | End  |
                                ,------|------|------|       |------+------+------.
                                |      |      | ~L2  |       | PgUp |      |      |
                                | USR1 | USR2 |------|       |------|Enter |Space |
                                |      |      | ~L1  |       | PgDn |      |      |
                                `--------------------'       `--------------------'
```
.--------------------------------------------------.  .--------------------------------------------------.
| Grave  |   !  |   @  |   #  |   $  |   %  |   {  |  |  }   |   ^  |   &  |   *  |   -  |   =  | BSpace |
|--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
| Tab    |   Q  |   W  |   E  |   R  |   T  |   (  |  |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
|--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
| Esc    |   A  |   S  |   D  |   F  |   G  |------|  |------|   H  |   J  |   K  |   L  |   ;  |   '    |
|--------+------+------+------+------+------|   [  |  |  ]   |------+------+------+------+------+--------|
| LShift |   Z  |   X  |   C  |   V  |   B  |      |  |      |   N  |   M  |   ,  |   .  |   /  | RShift |
'--------+------+------+------+------+-------------'  '-------------+------+------+------+------+--------'
  | LCtl |Super | Alt  | ~L1  |Space |                              | Left | Down | Up   |Right | Del  |
  '----------------------------------'                              '----------------------------------'
                                     .-------------.  .-------------.
                                     | Ins  |NumClk|  | Home | End  |
                              .------+------+------|  |------+------+------.
                              |      |      |CapsLk|  | PgUp |      |      |
                              |BSpace| Del  |------|  |------| ~L2  |Enter |
                              |      |      | ~L3  |  | PgDn |      |      |
                              '--------------------'  '--------------------'

Optional overrides: see CFQ_USER_KEY# defines.

.--------------------------------------------------.  .--------------------------------------------------.
|        |      |      |      |      |      |      |  |      |      |      |      |      |      | USR0   |
|--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
|        |      |      |      |      |      |      |  |      |      |      |      |      |      |        |
|--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
|        |      |      |      |      |      |------|  |------|      |      |      |      |      |        |
|--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
|        |      |      |      |      |      |      |  |      |      |      |      |      |      |        |
'--------+------+------+------+------+-------------'  '-------------+------+------+------+------+--------'
  |      |      |      | USR1 |      |                              |      |      |      |      | USR8 |
  '----------------------------------'                              '----------------------------------'
                                     .-------------.  .-------------.
                                     | USR2 | USR3 |  |      |      |
                              .------+------+------|  |------+------+------.
                              |      |      | USR6 |  |      |      |      |
                              | USR4 | USR5 |------|  |------|      |      |
                              |      |      | USR7 |  |      |      |      |
                              '--------------------'  '--------------------'
```

## Keymap 1: KeyPad, Macro Record

Notes:

Notes:

- The double bracket keys on this layer press left to position the cursor between them.
- The left thumb cluster is used for macro record/replay.

```
,--------------------------------------------------.           ,--------------------------------------------------.
|        |  F1  |  F2  |  F3  |  F4  |  F5  |  {}  |           |  }{  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|        |      |      |      |      |  =>  |  ()  |           |  )(  |  <=  |   7  |   8  |   9  |   \  |   F11  |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |      |      |      |      |  ->  |------|           |------|  <-  |   4  |   5  |   6  |   *  |   F12  |
|--------+------+------+------+------+------|  []  |           |  ][  |------+------+------+------+------+--------|
|        |      |      |      |      |  <>  |      |           |      |  ><  |   1  |   2  |   3  |   -  |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |      |      |      |      |                                       |   0  |      |   .  |   +  |      |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,---------------.
                                       |Start1|Start2|       |      |        |
                                ,------|------|------|       |------+--------+------.
                                |      |      | Stop |       |      |        |      |
                                |Play1 |Play2 |------|       |------|        |      |
                                |      |      |      |       |      |        |      |
                                `--------------------'       `----------------------'
```

## Keymap 2: F-Keys, Media & Mouse Keys

```
.--------------------------------------------------.  .--------------------------------------------------.
|        |      |      |      |      |      |      |  | Mute |      |  F10 |  F11 |  F12 |      |        |
|--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
|        |      |      | MsUp |      |      |MWhlUp|  |VolUp |      |  F7  |  F8  |  F9  |      |        |
|--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
|        |      |MsLeft|MsDown|MsRght|      |------|  |------|      |  F4  |  F5  |  F6  |      |        |
|--------+------+------+------+------+------|MWhlDn|  |VolDn |------+------+------+------+------+--------|
|        |      | Rclk | Mclk | Lclk |      |      |  |      |      |  F1  |  F2  |  F3  |      |        |
'--------+------+------+------+------+-------------'  '-------------+------+------+------+------+--------'
  |      |      |      |      |      |                              |      |      |      |      |      |
  '----------------------------------'                              '----------------------------------'
                                     .-------------.  .-------------.
                                     |      |      |  | MRwd | MFwd |
                              .------+------+------|  |------+------+------.
                              |      |      |      |  | MPrv |      |      |
                              |      |      |------|  |------|      | Play |
                              |      |      |      |  | MNxt |      |      |
                              '--------------------'  '--------------------'
```

## Keymap 3: User Defined Words & Numbers

This is for assigning whole words to single keys.
You can define the arguments (which must be quoted) using: `CFQ_WORD_[A-Z]`
eg: `-DCFQ_WORD_E=\"my@email.com\"`

Notes:

- Numbers are included on this layer since some applications differentiate
  between numbers top row and keypad.

```
.--------------------------------------------------.  .--------------------------------------------------.
|        |   1  |   2  |   3  |   4  |   5  |      |  |      |   6  |   7  |   8  |   9  |   0  |        |
|--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
|        |   Q  |   W  |   E  |   R  |   T  |      |  |      |   Y  |   U  |   I  |   O  |   P  |        |
|--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
|        |   A  |   S  |   D  |   F  |   G  |------|  |------|   H  |   J  |   K  |   L  |      |        |
|--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
|        |   Z  |   X  |   C  |   V  |   B  |      |  |      |   N  |   M  |      |      |      |        |
'--------+------+------+------+------+-------------'  '-------------+------+------+------+------+--------'
  |      |      |      |      |      |                              |      |      |      |      |      |
  '----------------------------------'                              '----------------------------------'
                                     .-------------.  .-------------.
                                     |      |      |  |      |      |
                              .------+------+------|  |------+------+------.
                              |      |      |      |  |      |      |      |
                              |      |      |------|  |------|      |      |
                              |      |      |      |  |      |      |      |
                              '--------------------'  '--------------------'
```

## Changelog

- 2017/10/28
  Make more keys user defined on the left thumb cluster.
  Add macro record/replay keys.

- 2017/10/4
  Move Insert key to the left thumb cluster (away from the modifier keys).
  Replace with `USR2` which defaults to `APP`.
