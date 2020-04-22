# Peanut Butter Engine

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)

Peanut Butter Engine aims to solve a simple and specific problem: creating 2D games in a tile-based environment. All that while having a framework that is lightweight, readable, easily extendable and, the most important of all, easy to use. All that while being open-source C++ for people that wants to create their own 2D games with C++. In the future it is aimed to be multiplataform, but currently it is windows-only.

The engine is on early stages and is going to be developed in an iterative way through the time. The end goal is to have a versatile engine that can be used to create different 2D tile-based games.

## Goals

* The goal is to be written with easily understable and modern C++
* Really easy to use
* Supports 2D Tile-based games

## Future

This is some sort of roadmap of things that I want to add to Peanut Butter engine, I might not be able to do all of them, or maybe I will, only time will tell.

- [ ] Write first simple game using Penut Butter Engine
- [ ] Abstract core modules (Window, Input, Renderer, Events, ...)
- [ ] Improve Sprite and Animations
- [ ] Improve how Input is handled
- [ ] Link all dependencies with Premake
- [ ] Peanut Butter engine works on other platforms that are not Windows
- [ ] Unit Testing
- [ ] Continuous Integration
- [ ] Website
- [ ] Official Documentation
- [ ] Editor and User Interface
- [ ] 2D Platformer Engine (Raycasting, Physics, etc...)
- [ ] 2D Roguelike Engine (Pathfinding, Level Generation, Field of View, ...)

## Dependencies

* [spdlog](https://github.com/gabime/spdlog): Included as a submodule, should be automatically included when cloning using ```--recursive```
* [SDL2](https://www.libsdl.org/download-2.0.php)
* [SDL2 Image](https://www.libsdl.org/projects/SDL_image/)

## Getting Started

Soon.

## How to Contribute

Maybe take a look at the issues, wiki, and everything else?

## References

#### Other Engines and Frameworks
* [halley engine](https://github.com/amzeratul/halley) by amzeratul
* [Hazel engine](https://github.com/TheCherno/Hazel) by TheCherno
* [libtcod](https://github.com/libtcod/libtcod)
* [Foster](https://github.com/NoelFB/Foster) by NoelFB
* [DOOM Open Source Release](https://github.com/id-Software/DOOM) by id-Software
* [Quake Open Source Release](https://github.com/id-Software/Quake) by id-Software
* [Birch Engine](https://github.com/carlbirch/BirchEngine) by carlbirch

#### Books, videos, etc...

* **Game Engine Architecture** by Jason Gregory (duh)
* **Game Development with SDL** by Shaun Mitchell
* [C++ Series](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb) by TheCherno
* [OpenGL Series](https://www.youtube.com/playlist?list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2) by TheCherno
* [Game Engine Series](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) by TheCherno
* [Fundamentals of 2D Game Engines with C++, SDL and Lua](https://www.udemy.com/course/cpp-2d-game-engine) by Gustavo Pezzi (Pikuma)
* [Raycasting Game Development with JavaScript SDL & C](https://www.udemy.com/course/raycasting-c) by Gustavo Pezzi (Pikuma)
