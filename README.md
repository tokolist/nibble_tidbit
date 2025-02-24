# Nibble and Tidbit Combo Alternative Firmware

This is alternative firmware for Nibble and Tidbit connection. Official firmware allows to connect Nibble with Tidbit through UART, but it's very limited. I developed firmware utilizing QMK split keyboard feature.

**DISCLAIMER:** this is not official alternative firmware, do everything at your own risk.

![image](https://github.com/tokolist/nibble_tidbit/assets/1922990/57587465-9963-4508-98e9-b471d8c5428e)

## What are Advantages?

* Split keyboard feature is officially supported by QMK and well-polished
* Split keyboard feature provides RGB, WPM, matrix, layer state and several other synchronizations out of the box. It also allows you to easily create your own synchronizations using RPC.
* It's single firmware configuration with single keymap that you flash to both Nibble and Tidbit

## Setup

### Prerequisites:

* Setup QMK environment according to guides provided on official website
* Nibble and Tidbit with soldered on TRRS sockets and connected through TRRS cable. **WARNING: TRRS connection is not safe to plug in or unplug while keyboard is powered on, you should make sure USB is unplugged before connecting or disconnecting TRRS cable.**

### Steps:

* Copy `nibble_tidbit` directory to QMK `keyboards/nullbitsco` directory
* Build and flash both Nibble and Tidbit with below corresponding commands. You must keep `left` flag for Nibble and `right` flag for Tidbit even if you use southpaw connection option (I personally have TRRS connector soldered on both sides of Nibble).

```
qmk flash -kb nullbitsco/nibble_tidbit -km default -e KBRD=NIBBLE -e TARGET=nullbitsco_nibble_split_default -bl dfu-split-left
qmk flash -kb nullbitsco/nibble_tidbit -km default -e KBRD=TIDBIT -e TARGET=nullbitsco_tidbit_split_default -bl dfu-split-right
```

Alternatively, you can build version with OLED spaceship animation (based on Admiralalleki's piece of art), big LED and tapdancing using below commands, but some RGB animations will be disabled due to limited MCU memory.

```
qmk flash -kb nullbitsco/nibble_tidbit -km fancy -e KBRD=NIBBLE -e TARGET=nullbitsco_nibble_split_fancy -bl dfu-split-left
qmk flash -kb nullbitsco/nibble_tidbit -km fancy -e KBRD=TIDBIT -e TARGET=nullbitsco_tidbit_split_fancy -bl dfu-split-right
```

* If everything went fine, now you can make your own customization, rebuild and reflash QMK firmware. `-bl dfu-split-*` argument is required only for first time flashing and in case you erase EEPROM. You should flash keyboards without `-bl dfu-split-*` as long as you don't erase EEPROM to save EEPROM write cycles.

```
qmk flash -kb nullbitsco/nibble_tidbit -km default -e KBRD=NIBBLE -e TARGET=nullbitsco_nibble_split_default
qmk flash -kb nullbitsco/nibble_tidbit -km default -e KBRD=TIDBIT -e TARGET=nullbitsco_tidbit_split_default
```

OR

```
qmk flash -kb nullbitsco/nibble_tidbit -km fancy -e KBRD=NIBBLE -e TARGET=nullbitsco_nibble_split_fancy
qmk flash -kb nullbitsco/nibble_tidbit -km fancy -e KBRD=TIDBIT -e TARGET=nullbitsco_tidbit_split_fancy
```

## Alternative Boards

Firmware was developed for Bit-C and tested with these boards, but it can be compiled and flashed onto other boards. You can leverage QMK Converters feature for this.

https://docs.qmk.fm/feature_converters

For instance, to compile it for Bit-C Pro, you should use `-e CONVERT_TO=bit_c_pro` switch, use UF2 instead of DFU bootloader flag `-bl uf2-split-left` and disable Bit-C LED `-e LED_TYPE=NONE`.

```
qmk flash -kb nullbitsco/nibble_tidbit -km default -e KBRD=NIBBLE -e TARGET=nullbitsco_nibble_split_default -bl uf2-split-left -e CONVERT_TO=bit_c_pro -e LED_TYPE=NONE
qmk flash -kb nullbitsco/nibble_tidbit -km default -e KBRD=TIDBIT -e TARGET=nullbitsco_tidbit_split_default -bl uf2-split-right -e CONVERT_TO=bit_c_pro -e LED_TYPE=NONE
```

## Known Issues

* I had to set `ENCODER_DEFAULT_POS 0x3` for Tidbit encoder since it was skipping steps on direction change (config.h), but your mileage might vary. If you are experiencing issues with encoders, adjust encoder configuration.
* In fancy keymap spaceship animation is slightly rough due to calling `oled_render_dirty` with `false` argument. If you pass `true`, it will be smoother, but encoder might skip steps. So, this is some sort of trade off. If you don't use Tidbit encoder, certainly go with `true`.

## Useful Links

* Nibble and Tidbit guides: https://nullbits.co/start/
* QMK environment setup guide: https://docs.qmk.fm/#/newbs_getting_started
* QMK split keyboard feature: https://docs.qmk.fm/#/feature_split_keyboard

## Thank You

* Nullbits for Nibble and Tidbit https://nullbits.co/
* QMK Team and community for developing and support https://qmk.fm/
* Admiralalleki for spaceship animation https://www.reddit.com/r/MechanicalKeyboards/comments/y916bk/i_programmed_my_corne_oled_via_qmk_to_show_a/
