# Angel
Angel is a 2D game engine written in c++ using SDL3 and miniaudio.

## To use it in you project:

```shell
# add it as a submodule
cd your_project
git submodule add https://github.com/nuuuclear/Angel Angel

# or clone it directly
cd your_project
git clone https://github.com/nuuuclear/Angel
```

Download and include SDL3, SDL3_ttf, SDL3_image, and miniaudio.

Include it in CMake:
```cmake
set(ANGEL_INSTALL OFF)
add_subdirectory(Angel) # or the directory you put it in.
```

And link it to your project:
```cmake
target_link_libraries(game PRIVATE angel::angel)
```

In your main.cpp:
```cpp
#include <Angel/Angel.h>

static int windowWidth = 100;
static int windowHeight = 100;

static const char* windowName = "Hello, world!";

int main(int argc, char *argv[]) {
  if (!Angel_Init()) // initializes Angel (returns true on success)
    return 1;
  
  // Create a window
  // NULL the is window creation flags, it uses the standard SDL window flags.
	if (!Angel_StartRenderer(windowName, windowWidth, windowHeight, NULL)) {
		Angel_Finish();
		return 1;
	}

  while (1) { // game loop
    input.beginFrame(); // clear input buffer
    input.poll(); // fill input buffer with input data.
  
    if (input.quitRequested()) // a more robust feature for this will come!
      running = false;
  
    // do stuff
  }
  
  Angel_Finish(); // finalize

  return 0;
}
```

And on how to actually use the game engine, for now just look throught the source code. 
I will be making a wiki/documentation on how to use it once it is a little further into development!
<hr>

As of now, this only works on Windows. although it shouldn't be too hard to get working else where.
