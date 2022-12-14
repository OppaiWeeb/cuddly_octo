# Led file generator (cuddly octo)

cuddly octo is a cute tool written in C/C++ with
[Raylib](https://github.com/raysan5/raylib)/[Raygui](https://github.com/raysan5/raygui)
it allow the user to create a LED file to control the SmartRoom Led project.

# Build

To build it you need to install the latest (from source) static version of
raylib [to see the doc](https://github.com/raysan5/raylib/wiki) if you use it under wayland you need to install a
custom version of GLFW (the
graphical engine of raylib) build on top of wayland

As say, you need to have at least the 4.5-dev version of raylib in order to work. (with external glfw or not)

once you have raylib installed, just use Cmake to compile the software
