SERIAL_DRIVER = vendor

VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes

# disable lighting
RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no    # Disable WS2812 RGB underlight.

BACKLIGHT_ENABLE = no

OLED_ENABLE     = yes
OLED_DRIVER     = ssd1306

QMK_SETTINGS        = yes


# mouse, media, and combos
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
COMBO_ENABLE = yes

# no tapdance feature
TAP_DANCE_ENABLE = yes

# handle right side pointing device
OPT_DEFS += -DPOINTING_DEVICE_POSITION_RIGHT
OPT_DEFS += -DPOINTING_DEVICE_CONFIGURATION_CIRQUE35
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c

# bootloader, for Sea Picro
BOOTLOADER = rp2040

# compile helpers
ifeq ($(strip $(MASTER)), left)
	OPT_DEFS += -DMASTER_L
else
	OPT_DEFS += -DMASTER_R
endif
