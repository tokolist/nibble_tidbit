#pragma once

// Workarounds for sleep/wake issues
//#define USB_SUSPEND_WAKEUP_DELAY 250

#define EE_HANDS

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 16

//Nibble
#define MATRIX_ROW_PINS { B1, B3, B2, B6, D4 }
#define MATRIX_COL_MUX_PINS { F4, F5, F6, F7 }
#define MATRIX_COL_PINS { }
#define MATRIX_MUX_COLS 4

//Tidbit matrix is configured in info.json

#ifdef CURR_KBRD_NIBBLE
	#define WS2812_DI_PIN E6
	#define SOFT_SERIAL_PIN D3
#else
	#define WS2812_DI_PIN B6
	#define SOFT_SERIAL_PIN D2
	//below line might not be needed for your encoder
	//mine was skipping pulses on direction change 
	#define ENCODER_DEFAULT_POS 0x3
#endif

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
