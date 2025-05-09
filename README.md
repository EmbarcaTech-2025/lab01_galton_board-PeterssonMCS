# Galton Board - Embedded Simulation

This project simulates a **Galton Board** using the BitDogLab. A Galton Board demonstrates the **central limit theorem** by letting balls fall through a series of pegs, randomly bouncing left or right, and finally forming a binomial distribution in the bins at the bottom.

## Concept

- A ball drops from the top and hits pegs arranged in a triangle.
- At each peg, it randomly moves **left or right**.
- After several layers, it lands in one of the **bins**.
- After many balls, the bins show a **normal distribution**.

## Goals

- Simulate ball drops with configurable layers.
- Use a button to trigger a new ball drop.
- Store bin counts in memory.

## Hardware Requirements

- Raspberry pico W
- OLED display
- Push button

## Features

- Pseudo-random path generation using `my_rand()`
- Adjustable number of layers (via `#define` or runtime config)
- Bin count tracking
- Real-time visualization of ball distribution

## Video

https://www.youtube.com/shorts/Gi0iTMh8Ufw

## ⚙️ Configuration

```c
#define BIN_HEIGHT 50
#define BALL_START 32
#define HORIZONTAL_SPACING 5
#define OBSTACLES_ROWS ( 32/HORIZONTAL_SPACING )
