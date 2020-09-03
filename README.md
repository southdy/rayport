# rayport

Awesome [raylib](https://github.com/raysan5/raylib) wrapper for [rayfork](https://github.com/SasLuca/rayfork), All in a single header without worries!

rayport wraps raylib API depending on what rayfork supports from raylib to keep compatibiltiy, Also RLGL and raymath and easings wrapped!

Note that rayport doesn't require raylib as rayport uses rayfork functions!

### Why rayport?

- Port raylib games easily to iOS and Consoles via rayfork!
- Easy way to save porting time, You just need to rewrite window and input code (Depending on window and input library will used with rayfork)
- More independency to raylib code via rayfork (As rayfork can use any window and input library).
- rayport is written in C99, Making it portable and easy to use anywhere you name it!
- No compilation needed, Just include `rayport.h` with your game that includes rayfork and all done!

### Example

Here is a simple example for rayport with rayfork uses GLFW, Just include `rayport.h` (You don't need raylib to use rayport but make sure you included rayfork in your solution)

```c
#include "include/rayfork.h"
#include "glad.h"
#include "GLFW/glfw3.h"
#include "rayport.h"

int main()
{
    // Init glfw and opengl
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 450, "rayfork simple glfw example", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    gladLoadGL();

    // Init rayfork
    rf_context rf_ctx = {0};
    rf_default_render_batch rf_mem = {0};
    rf_init(&rf_ctx, &rf_mem, 800, 450, RF_DEFAULT_OPENGL_PROCS);

    // Load a texture with the default libc allocator and io callbacks.
    Texture2D texture = LoadTexture("bananya.png");

    // Main game loop
    while (!glfwWindowShouldClose(window))
    {
        // Render the image and clear the background to some nice shade of white
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0, 0, 100, 100, RED);
        DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}
```

Original code can be found [here](https://github.com/SasLuca/rayfork-tests/blob/master/special-setup-tests/simple-glfw/main.c).

### NOTES

1. Note that rayfork still miss some features unlike raylib, So some functions aren't wrapped yet!
2. Values of gamepad stuff in enums predefined for compatibility with raylib, As you use input library with rayfork!
3. API macros uses `RF_API` (rayfork API macro) instead of defining them as standalone ones.
4. Although rayfork still miss some stuff, I successed lately in wrapping more stuff (And will still do)!

> For list of available wrapped functions (As enums and colors wrapped), See [here](https://github.com/Rabios/rayport/blob/master/api.md).

> Also, See [changelog](https://github.com/Rabios/rayport/blob/master/changelog.md) for changes!

### Special Thanks

1. [Ramon Santamaria (raysan5)](https://github.com/raysan5), Who made [raylib](https://github.com/raysan5/raylib).
2. [Luca Sas (SasLuca)](https://github.com/SasLuca), Who made [rayfork](https://github.com/SasLuca/rayfork).
