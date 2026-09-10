*This project has been created as part of the 42 curriculum by skarayil and asari.*

# cub3D

## Description

**cub3D** is a raycasting engine inspired by the classic 1992 game *Wolfenstein 3D*. The goal of the project is to render a simple pseudo-3D representation of a maze-like map, described in a custom `.cub` configuration file, using the raycasting rendering technique.

The project focuses on:
- Parsing and rigorously validating a map file describing walls, floor and ceiling colors, wall textures, and the player's starting position/orientation.
- Implementing a raycasting algorithm (based on the Digital Differential Analysis / DDA technique) to project a 2D map into a first-person 3D view.
- Applying textures to walls depending on their orientation (North, South, East, West).
- Handling real-time keyboard input to let the player move and rotate freely inside the map, using the MiniLibX graphics library.

This project is a great introduction to computer graphics fundamentals such as vectors, ray-wall intersection, texture mapping, and to writing clean, modular, norm-compliant C code.

### Key features

- **Custom map parser** (`.cub` files) validating:
  - Texture paths for all four cardinal directions (`NO`, `SO`, `WE`, `EA`)
  - Floor (`F`) and ceiling (`C`) RGB colors
  - A valid 2D grid map made of `0` (empty), `1` (wall), spaces, and exactly one player spawn character (`N`, `S`, `E`, `W`)
  - That the map is fully enclosed by walls (no open path to the outside)
- **Raycasting engine** using the DDA algorithm to compute wall distances and render vertical wall slices.
- **Textured walls** loaded from XPM images, with different textures depending on which side of a wall is hit.
- **Real-time player movement** (forward/backward, strafing) and **rotation** using MiniLibX event hooks.
- **Custom `get_next_line`** and a small **libft** used throughout the project instead of relying on the standard library where forbidden.

## Instructions

### Requirements

- A Linux environment (the project relies on **MiniLibX** for X11, along with `libXext` and `libX11`).
- `gcc`/`cc`, `make`.

### Compilation

The project is built with the provided `Makefile`, which also builds the MiniLibX library and the internal `libft` as dependencies.

```bash
make        # builds libft, minilibx and the cub3D binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # rebuilds everything from scratch
```

This produces an executable named `cub3D` at the root of the repository.

### Running the program

```bash
./cub3D <path_to_map.cub>
```

A sample map is provided at `maps/test.cub`.

```bash
./cub3D maps/test.cub
```

### Map file format (`.cub`)

A `.cub` file must define, in any order, before the map grid:

```
NO ./textures/north.xpm   # North wall texture
SO ./textures/south.xpm   # South wall texture
WE ./textures/west.xpm    # West wall texture
EA ./textures/east.xpm    # East wall texture
F 153,135,74              # Floor color (RGB)
C 225,225,120             # Ceiling color (RGB)
```

Followed by the map itself, using:
- `1` for a wall
- `0` for walkable floor
- ` ` (space) for void (as long as the map stays properly enclosed)
- `N`, `S`, `E`, `W` for the player's starting position and initial facing direction (exactly one required)

The map must be surrounded by walls; any opening onto the void makes the map invalid.

### Controls

| Key            | Action                     |
|----------------|-----------------------------|
| `W` / `A` / `S` / `D` | Move forward / strafe left / move backward / strafe right |
| `←` / `→`      | Rotate the camera left / right |
| `ESC`          | Close the window and quit  |

## Resources

- [Wikipedia — Ray casting](https://en.wikipedia.org/wiki/Ray_casting) — general explanation of the raycasting technique.
- [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html) — a widely-used, detailed reference implementation and explanation of the DDA raycasting algorithm used as the theoretical basis for this project.
- [42 MiniLibX documentation / man pages](https://github.com/42Paris/minilibx-linux) — reference for the MiniLibX graphics library used to open windows, handle events, and manipulate images.
- 42 Norm documentation — for code style and formatting constraints.

### AI usage

An AI assistant (Claude) was used in a supporting role during the development of this project:
- Generating and structuring this `README.md` file based on a full read-through of the codebase (Makefile, headers, and source files).
- Discussing and clarifying general concepts related to raycasting, DDA, and vector math to better understand the algorithm before implementation.

All core logic — map parsing, validation, raycasting, rendering, texture mapping, and input handling — was designed and implemented by the project author. No AI-generated code was directly copied into the source files of the project.