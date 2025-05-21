# 🏓 Pong_mlx

A simple Pong clone built using [`minilibx-linux`](https://github.com/42Paris/minilibx-linux), the minimalist graphics library from 42 Paris.

---

## 📦 About

This project was developed as a fun side project using C and `minilibx-linux`. It features basic game mechanics, window management, and rendering — all handled at a low level with the MLX library.

## 🤝 Collaboration

Developed alongside my friend [@therappha](https://github.com/therappha) 

---

## 🛠 Requirements

- Linux
- `minilibx-linux` (automatically cloned by the Makefile)
- A compiler like `gcc` or `clang`
- X11 libraries (`libXext`, `libX11`, etc.)

---

## 🚀 Build & Run

### ▶️ If you're on a 42 campus (Linux environment)

```bash
make
./pong
```

### 💻 If you're on your personal computer

Install dependencies:

```bash
sudo apt update
sudo apt install libx11-dev libxext-dev libxrandr-dev libxrender-dev libxcb1-dev libx11-xcb-dev
sudo apt install libbsd-dev
```

Then build and run:

```bash
make
./pong
```

---

## Gameplay Preview

![Pong Gameplay](./gif/pong.gif)
