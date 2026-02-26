# Fractal Trees

A procedural graphics program written in **C** using **raylib** that generates a dynamic *fractal canopy* through a recursive branching algorithm.

The project demonstrates recursive geometry and real-time rendering using a lightweight graphics framework.

---

## Overview

**Fractal Trees** renders a tree-like fractal structure by recursively subdividing branches. Each branch spawns child branches at configurable angles and scaling factors, forming a canopy-like structure.

The program highlights:

- Recursive rendering techniques
- Procedural geometry generation
- Basic trigonometric transformations
- Real-time rendering with raylib

---

## Features

- Recursive branch generation
- Real-time window rendering
- Lightweight and dependency-minimal (raylib only)

---

## How It Works

The fractal is generated using a recursive function:

1. Draw the current branch.
2. Compute the endpoint using trigonometry.
3. Recursively generate child branches:
   - Reduced length
   - Reduced thickness
   - Modified angle

The recursion terminates when the depth reaches zero.

---

## Requirements

- GCC (MinGW-w64 recommended on Windows)
- raylib installed
- OpenGL (automatically linked on Windows)

---

## Build Instructions (Windows – w64devkit)

- Open: C:\raylib\w64devkit\w64devkit.exe (or wherever your raylib path is located)
- Navigate to your project directory
- Compile: gcc fractaltrees.c -o fractaltrees.exe -I/c/raylib/include -L/c/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm (If you're having trouble compiling take a look at [raylib official website](https://www.raylib.com))
- Run: ./fractaltrees.exe

---

## License

This project is provided for educational and experimental purposes.  
You are free to modify and distribute it.
