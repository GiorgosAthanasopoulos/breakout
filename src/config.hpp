#pragma once

// window
#define WIN_FLAGS FLAG_WINDOW_RESIZABLE
#define WIN_W 1280
#define WIN_H 720
#define WIN_TITLE "Breakout"
#define WIN_FPS 60
#define WIN_MIN_W 640
#define WIN_MIN_H 480
#define WIN_MAX_W 3840
#define WIN_MAX_H 2160
#define WIN_BG BLACK

// keybind
#define KEY_EXIT KEY_NULL
#define KEY_PADDLE_MOVE_LEFT KEY_A
#define KEY_PADDLE_MOVE_RIGHT KEY_D

// debug
#define DEBUG true

// block
#define BLOCK_COLOR WHITE
#define BLOCK_SIZE_RATIO 10

// paddle
#define PADDLE_SIZE_RATIO_X 8
#define PADDLE_SIZE_RATIO_Y 12
#define PADDLE_SPEED_RATIO 3
#define PADDLE_BOTTOM_PADDING 1
#define PADDLE_COLOR WHITE

// ball
#define BALL_COLOR WHITE
#define BALL_SPEED_RATIO 3
#define BALL_SIZE_RATIO 25
#define BALL_BOTTOM_PADDING 4

// game
#define BALL_COUNT_X 8
#define BALL_COUNT_Y 4
#define BLOCKS_PADDING_X 45
#define BLOCKS_INNER_PADDING_X 45
#define BLOCKS_PADDING_Y 45
#define BLOCKS_INNER_PADDING_Y 45
