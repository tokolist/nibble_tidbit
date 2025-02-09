BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = yes        # Use rotary encoder
LTO_ENABLE = yes            # Link-time optimization

ifneq ($(LED_TYPE),NONE)
    OPT_DEFS += -DLED_TYPE_BITC
    SRC += common/bitc_led.c
endif

ifeq ($(KBRD),NIBBLE)
    OPT_DEFS += -DCURR_KBRD_NIBBLE
    CUSTOM_MATRIX = lite
    SRC += matrix.c \
           big_led.c
else ifneq ($(KBRD),TIDBIT)
    $(error "Must set KBRD to either NIBBLE or TIDBIT")
endif
