// Created by Rabia Alhaffar in 1/September/2020
// rayport, Awesome raylib wrapper for rayfork, All in a single header without worries!
// Built for: rayfork v0.9
// Last update: 4/September/2020
#pragma region
#ifndef RAYPORT_H
#define RAYPORT_H

#include "rayfork.h"

#define RLAPI RF_API        // Wrap of raylib API name (raylib.h)
#define RMDEF RF_API        // Wrap of raymath API name (raymath.h)
#define EASEDEF RF_API      // Wrap of raylib easings API name (easings.h)
#define DEG2RAD RF_DEG2RAD  // Wrap of DEG2RAD (raylib.h)
#define RAD2DEF RF_RAD2DEG  // Wrap of RAD2DEG (raylib.h)
#define PI      RF_PI       // Wrap of PI (raylib.h)

// Types
typedef rf_vec4 Vector4;
typedef rf_vec3 Vector3;
typedef rf_vec2 Vector2;
typedef rf_quaternion Quaternion;
typedef rf_color Color;
typedef rf_mat Matrix;
typedef rf_rec Rectangle;
typedef rf_bounding_box BoundingBox;
typedef rf_image Image;
typedef rf_texture2d Texture2D;
typedef rf_texture2d Texture;
typedef rf_texture2d TextureCubemap;
typedef rf_render_texture2d RenderTexture2D;
typedef rf_render_texture2d RenderTexture;
typedef rf_npatch_info NPatchInfo;
typedef rf_glyph_info CharInfo;
typedef rf_font Font;
typedef rf_font SpriteFont;
typedef rf_camera3d Camera3D;
typedef rf_camera3d Camera;
typedef rf_camera2d Camera2D;
typedef rf_mesh Mesh;
typedef rf_material_map MaterialMap;
typedef rf_material Material;
typedef rf_model Model;
typedef rf_transform Transform;
typedef rf_bone_info BoneInfo;
typedef rf_model_animation ModelAnimation;
typedef rf_ray Ray;
typedef rf_ray_hit_info RayHitInfo;
typedef rf_shader Shader;
typedef unsigned char byte;
typedef struct float3 { float v[3]; } float3;
typedef struct float16 { float v[16]; } float16;

// Colors
#define LIGHTGRAY  RF_LIGHTGRAY
#define GRAY       RF_GRAY
#define DARKGRAY   RF_DARKGRAY
#define YELLOW     RF_YELLOW
#define GOLD       RF_GOLD
#define ORANGE     RF_ORANGE
#define PINK       RF_PINK
#define RED        RF_RED
#define MAROON     RF_MAROON
#define GREEN      RF_GREEN
#define LIME       RF_LIME
#define DARKGREEN  RF_DARKGREEN
#define SKYBLUE    RF_SKYBLUE
#define BLUE       RF_BLUE
#define DARKBLUE   RF_DARKBLUE
#define PURPLE     RF_PURPLE
#define VIOLET     RF_VIOLET
#define DARKPURPLE RF_DARKPURPLE
#define BEIGE      RF_BEIGE
#define BROWN      RF_BROWN
#define DARKBROWN  RF_DARKBROWN
#define WHITE      RF_WHITE
#define BLACK      RF_BLACK
#define BLANK      RF_BLANK
#define MAGENTA    RF_MAGENTA
#define RAYWHITE   RF_RAYWHITE

// Variables
typedef enum {
    KEY_SPACE = 32,
    KEY_APOSTROPHE = 39,  /* ' */
    KEY_COMMA = 44,  /* , */
    KEY_MINUS = 45,  /* - */
    KEY_PERIOD = 46,  /* . */
    KEY_SLASH = 47,  /* / */
    KEY_0 = 48,
    KEY_1 = 49,
    KEY_2 = 50,
    KEY_3 = 51,
    KEY_4 = 52,
    KEY_5 = 53,
    KEY_6 = 54,
    KEY_7 = 55,
    KEY_8 = 56,
    KEY_9 = 57,
    KEY_SEMICOLON = 59,  /* ; */
    KEY_EQUAL = 61,  /* = */
    KEY_A = 65,
    KEY_B = 66,
    KEY_C = 67,
    KEY_D = 68,
    KEY_E = 69,
    KEY_F = 70,
    KEY_G = 71,
    KEY_H = 72,
    KEY_I = 73,
    KEY_J = 74,
    KEY_K = 75,
    KEY_L = 76,
    KEY_M = 77,
    KEY_N = 78,
    KEY_O = 79,
    KEY_P = 80,
    KEY_Q = 81,
    KEY_R = 82,
    KEY_S = 83,
    KEY_T = 84,
    KEY_U = 85,
    KEY_V = 86,
    KEY_W = 87,
    KEY_X = 88,
    KEY_Y = 89,
    KEY_Z = 90,
    KEY_LEFT_BRACKET = 91,  /* [ */
    KEY_BACKSLASH = 92,  /* \ */
    KEY_RIGHT_BRACKET = 93,  /* ] */
    KEY_GRAVE_ACCENT = 96,  /* ` */
    KEY_WORLD_1 = 161, /* non-US #1 */
    KEY_WORLD_2 = 162, /* non-US #2 */
    KEY_ESCAPE = 256,
    KEY_ENTER = 257,
    KEY_TAB = 258,
    KEY_BACKSPACE = 259,
    KEY_INSERT = 260,
    KEY_DELETE = 261,
    KEY_RIGHT = 262,
    KEY_LEFT = 263,
    KEY_DOWN = 264,
    KEY_UP = 265,
    KEY_PAGE_UP = 266,
    KEY_PAGE_DOWN = 267,
    KEY_HOME = 268,
    KEY_END = 269,
    KEY_CAPS_LOCK = 280,
    KEY_SCROLL_LOCK = 281,
    KEY_NUM_LOCK = 282,
    KEY_PRINT_SCREEN = 283,
    KEY_PAUSE = 284,
    KEY_F1 = 290,
    KEY_F2 = 291,
    KEY_F3 = 292,
    KEY_F4 = 293,
    KEY_F5 = 294,
    KEY_F6 = 295,
    KEY_F7 = 296,
    KEY_F8 = 297,
    KEY_F9 = 298,
    KEY_F10 = 299,
    KEY_F11 = 300,
    KEY_F12 = 301,
    KEY_F13 = 302,
    KEY_F14 = 303,
    KEY_F15 = 304,
    KEY_F16 = 305,
    KEY_F17 = 306,
    KEY_F18 = 307,
    KEY_F19 = 308,
    KEY_F20 = 309,
    KEY_F21 = 310,
    KEY_F22 = 311,
    KEY_F23 = 312,
    KEY_F24 = 313,
    KEY_F25 = 314,
    KEY_KP_0 = 320,
    KEY_KP_1 = 321,
    KEY_KP_2 = 322,
    KEY_KP_3 = 323,
    KEY_KP_4 = 324,
    KEY_KP_5 = 325,
    KEY_KP_6 = 326,
    KEY_KP_7 = 327,
    KEY_KP_8 = 328,
    KEY_KP_9 = 329,
    KEY_KP_DECIMAL = 330,
    KEY_KP_DIVIDE = 331,
    KEY_KP_MULTIPLY = 332,
    KEY_KP_SUBTRACT = 333,
    KEY_KP_ADD = 334,
    KEY_KP_ENTER = 335,
    KEY_KP_EQUAL = 336,
    KEY_LEFT_SHIFT = 340,
    KEY_LEFT_CONTROL = 341,
    KEY_LEFT_ALT = 342,
    KEY_LEFT_SUPER = 343,
    KEY_RIGHT_SHIFT = 344,
    KEY_RIGHT_CONTROL = 345,
    KEY_RIGHT_ALT = 346,
    KEY_RIGHT_SUPER = 347,
    //KEY_MENU = 348,
} KeyboardKey;

typedef enum {
    LOG_ALL = RF_LOG_TYPE_ALL,
    LOG_DEBUG = RF_LOG_TYPE_DEBUG,
    LOG_INFO = RF_LOG_TYPE_INFO,
    LOG_WARNING = RF_LOG_TYPE_WARNING,
    LOG_ERROR = RF_LOG_TYPE_ERROR,
    LOG_NONE = RF_LOG_TYPE_NONE
} TraceLogType;

typedef enum {
    KEY_BACK = 4,
    KEY_MENU = 82,
    KEY_VOLUME_UP = 24,
    KEY_VOLUME_DOWN = 25
} AndroidButton;

typedef enum {
    MOUSE_LEFT_BUTTON = 0,
    MOUSE_RIGHT_BUTTON = 1,
    MOUSE_MIDDLE_BUTTON = 2
} MouseButton;

typedef enum {
    GAMEPAD_PLAYER1 = 0,
    GAMEPAD_PLAYER2 = 1,
    GAMEPAD_PLAYER3 = 2,
    GAMEPAD_PLAYER4 = 3
} GamepadNumber;

// NOTE: This are predefined for compatibility with raylib, Not sure if with GLFW!
typedef enum {
    // This is here just for error checking
    GAMEPAD_BUTTON_UNKNOWN = 0,

    // This is normally a DPAD
    GAMEPAD_BUTTON_LEFT_FACE_UP = 1,
    GAMEPAD_BUTTON_LEFT_FACE_RIGHT = 2,
    GAMEPAD_BUTTON_LEFT_FACE_DOWN = 3,
    GAMEPAD_BUTTON_LEFT_FACE_LEFT = 4,

    // This normally corresponds with PlayStation and Xbox controllers
    // XBOX: [Y,X,A,B]
    // PS3: [Triangle,Square,Cross,Circle]
    // No support for 6 button controllers though..
    GAMEPAD_BUTTON_RIGHT_FACE_UP = 5,
    GAMEPAD_BUTTON_RIGHT_FACE_RIGHT = 6,
    GAMEPAD_BUTTON_RIGHT_FACE_DOWN = 7,
    GAMEPAD_BUTTON_RIGHT_FACE_LEFT = 8,

    // Triggers
    GAMEPAD_BUTTON_LEFT_TRIGGER_1 = 9,
    GAMEPAD_BUTTON_LEFT_TRIGGER_2 = 10,
    GAMEPAD_BUTTON_RIGHT_TRIGGER_1 = 11,
    GAMEPAD_BUTTON_RIGHT_TRIGGER_2 = 12,

    // These are buttons in the center of the gamepad
    GAMEPAD_BUTTON_MIDDLE_LEFT = 13,     //PS3 Select
    GAMEPAD_BUTTON_MIDDLE = -1,          //PS Button/XBOX Button
    GAMEPAD_BUTTON_MIDDLE_RIGHT = 15,    //PS3 Start

    // These are the joystick press in buttons
    GAMEPAD_BUTTON_LEFT_THUMB = 16,
    GAMEPAD_BUTTON_RIGHT_THUMB = 17
} GamepadButton;

typedef enum {
    // This is here just for error checking
    GAMEPAD_AXIS_UNKNOWN = 0,

    // Left stick
    GAMEPAD_AXIS_LEFT_X = 0,
    GAMEPAD_AXIS_LEFT_Y = 1,

    // Right stick
    GAMEPAD_AXIS_RIGHT_X = 2,
    GAMEPAD_AXIS_RIGHT_Y = 3,
 
    // Pressure levels for the back triggers
    GAMEPAD_AXIS_LEFT_TRIGGER,      // [1..-1] (pressure-level)
    GAMEPAD_AXIS_RIGHT_TRIGGER      // [1..-1] (pressure-level)
} GamepadAxis;

// Shader location point type
typedef enum {
    LOC_VERTEX_POSITION = RF_LOC_VERTEX_POSITION,
    LOC_VERTEX_TEXCOORD01 = RF_LOC_VERTEX_TEXCOORD01,
    LOC_VERTEX_TEXCOORD02 = RF_LOC_VERTEX_TEXCOORD02,
    LOC_VERTEX_NORMAL = RF_LOC_VERTEX_NORMAL,
    LOC_VERTEX_TANGENT = RF_LOC_VERTEX_TANGENT,
    LOC_VERTEX_COLOR = RF_LOC_VERTEX_COLOR,
    LOC_MATRIX_MVP = RF_LOC_MATRIX_MVP,
    LOC_MATRIX_MODEL = RF_LOC_MATRIX_MODEL,
    LOC_MATRIX_VIEW = RF_LOC_MATRIX_VIEW,
    LOC_MATRIX_PROJECTION = RF_LOC_MATRIX_PROJECTION,
    LOC_VECTOR_VIEW = RF_LOC_VECTOR_VIEW,
    LOC_COLOR_DIFFUSE = RF_LOC_COLOR_DIFFUSE,
    LOC_COLOR_SPECULAR = RF_LOC_COLOR_SPECULAR,
    LOC_COLOR_AMBIENT = RF_LOC_COLOR_AMBIENT,
    LOC_MAP_ALBEDO = RF_LOC_MAP_ALBEDO,          // LOC_MAP_DIFFUSE
    LOC_MAP_METALNESS = RF_LOC_MAP_METALNESS,       // LOC_MAP_SPECULAR
    LOC_MAP_NORMAL = RF_LOC_MAP_NORMAL,
    LOC_MAP_ROUGHNESS = RF_LOC_MAP_ROUGHNESS,
    LOC_MAP_OCCLUSION = RF_LOC_MAP_OCCLUSION,
    LOC_MAP_EMISSION = RF_LOC_MAP_EMISSION,
    LOC_MAP_HEIGHT = RF_LOC_MAP_HEIGHT,
    LOC_MAP_CUBEMAP = RF_LOC_MAP_CUBEMAP,
    LOC_MAP_IRRADIANCE = RF_LOC_MAP_IRRADIANCE,
    LOC_MAP_PREFILTER = RF_LOC_MAP_PREFILTER,
    LOC_MAP_BRDF = RF_LOC_MAP_BRDF
} ShaderLocationIndex;

#define LOC_MAP_DIFFUSE      LOC_MAP_ALBEDO
#define LOC_MAP_SPECULAR     LOC_MAP_METALNESS

// Shader uniform data types
typedef enum {
    UNIFORM_FLOAT = RF_UNIFORM_FLOAT,
    UNIFORM_VEC2 = RF_UNIFORM_VEC2,
    UNIFORM_VEC3 = RF_UNIFORM_VEC3,
    UNIFORM_VEC4 = RF_UNIFORM_VEC4,
    UNIFORM_INT = RF_UNIFORM_INT,
    UNIFORM_IVEC2 = RF_UNIFORM_IVEC2,
    UNIFORM_IVEC3 = RF_UNIFORM_IVEC3,
    UNIFORM_IVEC4 = RF_UNIFORM_IVEC4,
    UNIFORM_SAMPLER2D = RF_UNIFORM_SAMPLER2D
} ShaderUniformDataType;

// Material map type
typedef enum {
    MAP_ALBEDO = RF_MAP_ALBEDO,       // MAP_DIFFUSE
    MAP_METALNESS = RF_MAP_METALNESS, // MAP_SPECULAR
    MAP_NORMAL = RF_MAP_NORMAL,
    MAP_ROUGHNESS = RF_MAP_ROUGHNESS,
    MAP_OCCLUSION = RF_MAP_OCCLUSION,
    MAP_EMISSION = RF_MAP_EMISSION,
    MAP_HEIGHT = RF_MAP_HEIGHT,
    MAP_CUBEMAP = RF_MAP_CUBEMAP,             // NOTE: Uses GL_TEXTURE_CUBE_MAP
    MAP_IRRADIANCE = RF_MAP_IRRADIANCE,       // NOTE: Uses GL_TEXTURE_CUBE_MAP
    MAP_PREFILTER = RF_MAP_PREFILTER,         // NOTE: Uses GL_TEXTURE_CUBE_MAP
    MAP_BRDF = RF_MAP_BRDF
} MaterialMapType;

#define MAP_DIFFUSE      MAP_ALBEDO
#define MAP_SPECULAR     MAP_METALNESS

// Pixel formats
// NOTE: Support depends on OpenGL version and platform
typedef enum {
    UNCOMPRESSED_GRAYSCALE = RF_UNCOMPRESSED_GRAYSCALE,        // 8 bit per pixel (no alpha)
    UNCOMPRESSED_GRAY_ALPHA = RF_UNCOMPRESSED_GRAY_ALPHA,      // 8*2 bpp (2 channels)
    UNCOMPRESSED_R5G6B5 = RF_UNCOMPRESSED_R5G6B5,              // 16 bpp
    UNCOMPRESSED_R8G8B8 = RF_UNCOMPRESSED_R8G8B8,              // 24 bpp
    UNCOMPRESSED_R5G5B5A1 = RF_UNCOMPRESSED_R5G5B5A1,          // 16 bpp (1 bit alpha)
    UNCOMPRESSED_R4G4B4A4 = RF_UNCOMPRESSED_R4G4B4A4,          // 16 bpp (4 bit alpha)
    UNCOMPRESSED_R8G8B8A8 = RF_UNCOMPRESSED_R8G8B8A8,          // 32 bpp
    UNCOMPRESSED_R32 = RF_UNCOMPRESSED_R32,                    // 32 bpp (1 channel - float)
    UNCOMPRESSED_R32G32B32 = RF_UNCOMPRESSED_R32G32B32,        // 32*3 bpp (3 channels - float)
    UNCOMPRESSED_R32G32B32A32 = RF_UNCOMPRESSED_R32G32B32A32,  // 32*4 bpp (4 channels - float)
    COMPRESSED_DXT1_RGB = RF_COMPRESSED_DXT1_RGB,              // 4 bpp (no alpha)
    COMPRESSED_DXT1_RGBA = RF_COMPRESSED_DXT1_RGBA,            // 4 bpp (1 bit alpha)
    COMPRESSED_DXT3_RGBA = RF_COMPRESSED_DXT3_RGBA,            // 8 bpp
    COMPRESSED_DXT5_RGBA = RF_COMPRESSED_DXT5_RGBA,            // 8 bpp
    COMPRESSED_ETC1_RGB = RF_COMPRESSED_ETC1_RGB,              // 4 bpp
    COMPRESSED_ETC2_RGB = RF_COMPRESSED_ETC2_RGB,              // 4 bpp
    COMPRESSED_ETC2_EAC_RGBA = RF_COMPRESSED_ETC2_EAC_RGBA,    // 8 bpp
    COMPRESSED_PVRT_RGB = RF_COMPRESSED_PVRT_RGB,              // 4 bpp
    COMPRESSED_PVRT_RGBA = RF_COMPRESSED_PVRT_RGBA,            // 4 bpp
    COMPRESSED_ASTC_4x4_RGBA = RF_COMPRESSED_ASTC_4x4_RGBA,    // 8 bpp
    COMPRESSED_ASTC_8x8_RGBA = RF_COMPRESSED_ASTC_8x8_RGBA     // 2 bpp
} PixelFormat;

// Texture parameters: filter mode
// NOTE 1: Filtering considers mipmaps if available in the texture
// NOTE 2: Filter is accordingly set for minification and magnification
typedef enum {
    FILTER_POINT = RF_FILTER_POINT,               // No filter, just pixel aproximation
    FILTER_BILINEAR = RF_FILTER_BILINEAR,                // Linear filtering
    FILTER_TRILINEAR = RF_FILTER_TRILINEAR,               // Trilinear filtering (linear with mipmaps)
    FILTER_ANISOTROPIC_4X = RF_FILTER_ANISOTROPIC_4x,          // Anisotropic filtering 4x
    FILTER_ANISOTROPIC_8X = RF_FILTER_ANISOTROPIC_8x,          // Anisotropic filtering 8x
    FILTER_ANISOTROPIC_16X = RF_FILTER_ANISOTROPIC_16x,         // Anisotropic filtering 16x
} TextureFilterMode;

// Cubemap layout type
typedef enum {
    CUBEMAP_AUTO_DETECT = RF_CUBEMAP_AUTO_DETECT,                    // Automatically detect layout type
    CUBEMAP_LINE_VERTICAL = RF_CUBEMAP_LINE_VERTICAL,                // Layout is defined by a vertical line with faces
    CUBEMAP_LINE_HORIZONTAL = RF_CUBEMAP_LINE_HORIZONTAL,            // Layout is defined by an horizontal line with faces
    CUBEMAP_CROSS_THREE_BY_FOUR = RF_CUBEMAP_CROSS_THREE_BY_FOUR,    // Layout is defined by a 3x4 cross with cubemap faces
    CUBEMAP_CROSS_FOUR_BY_THREE = RF_CUBEMAP_CROSS_FOUR_BY_TREE,     // Layout is defined by a 4x3 cross with cubemap faces
    CUBEMAP_PANORAMA = RF_CUBEMAP_PANORAMA                           // Layout is defined by a panorama image (equirectangular map)
} CubemapLayoutType;

// Texture parameters: wrap mode
typedef enum {
    WRAP_REPEAT = RF_WRAP_REPEAT,                 // Repeats texture in tiled mode
    WRAP_CLAMP = RF_WRAP_CLAMP,                   // Clamps texture to edge pixel in tiled mode
    WRAP_MIRROR_REPEAT = RF_WRAP_MIRROR_REPEAT,   // Mirrors and repeats the texture in tiled mode
    WRAP_MIRROR_CLAMP = RF_WRAP_MIRROR_CLAMP      // Mirrors and clamps to border the texture in tiled mode
} TextureWrapMode;

// Color blending modes (pre-defined)
typedef enum {
    BLEND_ALPHA = RF_BLEND_ALPHA,           // Blend textures considering alpha (default)
    BLEND_ADDITIVE = RF_BLEND_ADDITIVE,     // Blend textures adding colors
    BLEND_MULTIPLIED = RF_BLEND_MULTIPLIED  // Blend textures multiplying colors
} BlendMode;

// Camera system modes
typedef enum {
    CAMERA_CUSTOM = RF_CAMERA_CUSTOM,
    CAMERA_FREE = RF_CAMERA_FREE,
    CAMERA_ORBITAL = RF_CAMERA_ORBITAL,
    CAMERA_FIRST_PERSON = RF_CAMERA_FIRST_PERSON,
    CAMERA_THIRD_PERSON = RF_CAMERA_THIRD_PERSON
} CameraMode;

// Camera projection modes
typedef enum {
    CAMERA_PERSPECTIVE = RF_CAMERA_PERSPECTIVE,
    CAMERA_ORTHOGRAPHIC = RF_CAMERA_ORTHOGRAPHIC
} CameraType;

// Type of n-patch
typedef enum {
    NPT_9PATCH = RF_NPT_9PATCH,
    NPT_3PATCH_VERTICAL = RF_NPT_3PATCH_VERTICAL,
    NPT_3PATCH_HORIZONTAL = RF_NPT_3PATCH_HORIZONTAL
} NPatchType;

// Functions
// Core
#define TraceLog(log_type, msg, ...) rf_log_impl(__FILE__, __LINE__, __FUNCTION__, (log_type), (msg), ##__VA_ARGS__)

// Drawing-related functions
RLAPI void ClearBackground(Color color) { rf_clear(color); }
RLAPI void BeginDrawing(void) { rf_begin(); }
RLAPI void EndDrawing(void) { rf_end(); }
RLAPI void BeginMode2D(Camera2D camera) { rf_begin_2d(camera); }
RLAPI void EndMode2D(void) { rf_end_2d(); }
RLAPI void BeginMode3D(Camera camera) { rf_begin_3d(camera); }
RLAPI void EndMode3D(void) { rf_end_3d(); }
RLAPI void BeginTextureMode(RenderTexture2D target) { rf_begin_render_to_texture(target); }
RLAPI void EndTextureMode(void) { rf_end_render_to_texture(); }
RLAPI void BeginScissorMode(int x, int y, int width, int height) { rf_begin_scissor_mode(x, y, width, height); }
RLAPI void EndScissorMode(void) { rf_end_scissor_mode(); }

// Screen-space-related functions
RLAPI Ray GetMouseRay(Vector2 mousePosition, Camera camera, int width, int height) { return rf_get_mouse_ray((rf_sizei) { width, height }, mousePosition, camera); }

RLAPI Matrix GetCameraMatrix(Camera camera) { return rf_get_camera_matrix(camera); }
RLAPI Matrix GetCameraMatrix2D(Camera2D camera) { return rf_get_camera_matrix2d(camera); }

RLAPI Vector2 GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height) { return rf_get_world_to_screen((rf_sizei) { width, height }, position, camera); }
RLAPI Vector2 GetWorldToScreen2D(Vector2 position, Camera2D camera) { return rf_get_world_to_screen2d(position, camera); }
RLAPI Vector2 GetScreenToWorld2D(Vector2 position, Camera2D camera) { return rf_get_screen_to_world2d(position, camera); }

// Color-related functions
RLAPI int ColorToInt(Color color) { return rf_color_to_int(color); }
RLAPI Vector4 ColorNormalize(Color color) { return rf_color_normalize(color); }
RLAPI Color ColorFromNormalized(Vector4 normalized) { return rf_color_from_normalized(normalized); }
RLAPI Vector3 ColorToHSV(Color color) { return rf_color_to_hsv(color); }
RLAPI Color ColorFromHSV(Vector3 hsv) { return rf_color_from_hsv(hsv); }
RLAPI Color Fade(Color color, float alpha) { return rf_fade(color, alpha); }
RLAPI Color* ColorAlpha = Fade; // Hack :)

//------------------------------------------------------------------------------------
// Camera System Functions (Module: camera)
//------------------------------------------------------------------------------------
RLAPI void SetCameraMode(Camera cam, int mode, rf_camera3d_state* state) { rf_set_camera3d_mode(state, cam, mode); }
RLAPI void UpdateCamera(Camera cam, rf_camera3d_state* state, rf_input_state_for_update_camera input_state) { rf_update_camera3d(&cam, state, input_state); }

// Shapes
// Basic shapes drawing functions
RLAPI void DrawPixel(int PosX, int PosY, Color color) { rf_draw_pixel(PosX, PosY, color); }
RLAPI void DrawPixelV(Vector2 position, Color color) { rf_draw_pixel_v(position, color); }
RLAPI void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color) { rf_draw_line(startPosX, startPosY, endPosX, endPosY, color); }
RLAPI void DrawLineV(Vector2 startPos, Vector2 endPos, Color color) { rf_draw_line_v(startPos, endPos, color); }
RLAPI void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color) { rf_draw_line_ex(startPos, endPos, thick, color); }
RLAPI void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color) { rf_draw_line_bezier(startPos, endPos, thick, color); }
RLAPI void DrawLineStrip(Vector2* points, int numPoints, Color color) { rf_draw_line_strip(points, numPoints, color); }
RLAPI void DrawCircle(int centerX, int centerY, float radius, Color color) { rf_draw_circle(centerX, centerY, radius, color); }
RLAPI void DrawCircleSector(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color) { rf_draw_circle_sector(center, radius, startAngle, endAngle, segments, color); }
RLAPI void DrawCircleSectorLines(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color) { rf_draw_circle_sector_lines(center, radius, startAngle, endAngle, segments, color); }
RLAPI void DrawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2) { rf_draw_circle_gradient(centerX, centerY, radius, color1, color2); }
RLAPI void DrawCircleV(Vector2 center, float radius, Color color) { rf_draw_circle_v(center, radius, color); }
RLAPI void DrawCircleLines(int centerX, int centerY, float radius, Color color) { rf_draw_circle_lines(centerX, centerY, radius, color); }
RLAPI void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color)
{
    if (rf_gfx_check_buffer_limit(3 * 36)) rf_gfx_draw();

    rf_gfx_begin(RF_TRIANGLES);
    for (int i = 0; i < 360; i += 10)
    {
        rf_gfx_color4ub(color.r, color.g, color.b, color.a);
        rf_gfx_vertex2f(centerX, centerY);
        rf_gfx_vertex2f(centerX + sinf(DEG2RAD * i) * radiusH, centerY + cosf(DEG2RAD * i) * radiusV);
        rf_gfx_vertex2f(centerX + sinf(DEG2RAD * (i + 10)) * radiusH, centerY + cosf(DEG2RAD * (i + 10)) * radiusV);
    }
    rf_gfx_end();
}
RLAPI void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color)
{
    if (rf_gfx_check_buffer_limit(3 * 36)) rf_gfx_draw();

    rf_gfx_begin(RF_LINES);
    for (int i = 0; i < 360; i += 10)
    {
        rf_gfx_color4ub(color.r, color.g, color.b, color.a);
        rf_gfx_vertex2f(centerX, centerY);
        rf_gfx_vertex2f(centerX + sinf(DEG2RAD * i) * radiusH, centerY + cosf(DEG2RAD * i) * radiusV);
        rf_gfx_vertex2f(centerX + sinf(DEG2RAD * (i + 10)) * radiusH, centerY + cosf(DEG2RAD * (i + 10)) * radiusV);
    }
    rf_gfx_end();
}
RLAPI void DrawRing(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color) { rf_draw_ring(center, innerRadius, outerRadius, startAngle, endAngle, segments, color); }
RLAPI void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color) { rf_draw_ring_lines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color); }
RLAPI void DrawRectangle(int posX, int posY, int width, int height, Color color) { rf_draw_rectangle(posX, posY, width, height, color); }
RLAPI void DrawRectangleV(Vector2 position, Vector2 size, Color color) { rf_draw_rectangle_v(position, size, color); }
RLAPI void DrawRectangleRec(Rectangle rec, Color color) { rf_draw_rectangle_rec(rec, color); }
RLAPI void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color) { rf_draw_rectangle_pro(rec, origin, rotation, color); }
RLAPI void DrawRectangleGradientV(int posX, int posY, int width, int height, Color color1, Color color2) { rf_draw_rectangle_gradient_v(posX, posY, width, height, color1, color2); }
RLAPI void DrawRectangleGradientH(int posX, int posY, int width, int height, Color color1, Color color2) { rf_draw_rectangle_gradient_h(posX, posY, width, height, color1, color2); }
RLAPI void DrawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4) { rf_draw_rectangle_gradient(rec, col1, col2, col3, col4); }
RLAPI void DrawRectangleLines(int posX, int posY, int width, int height, Color color) { rf_draw_rectangle_outline((rf_rec) { posX, posY, width, height }, 1, color); }
RLAPI void DrawRectangleLinesEx(Rectangle rec, int lineThick, Color color) { rf_draw_rectangle_outline(rec, lineThick, color); }
RLAPI void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color) { rf_draw_rectangle_rounded(rec, roundness, segments, color); }
RLAPI void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, int lineThick, Color color) { rf_draw_rectangle_rounded_lines(rec, roundness, segments, lineThick, color); }
RLAPI void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color) { rf_draw_triangle(v1, v2, v3, color); }
RLAPI void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color) { rf_draw_triangle_lines(v1, v2, v3, color); }
RLAPI void DrawTriangleFan(Vector2* points, int numPoints, Color color) { rf_draw_triangle_fan(points, numPoints, color); }
RLAPI void DrawTriangleStrip(Vector2* points, int pointsCount, Color color) { rf_draw_triangle_strip(points, pointsCount, color); }
RLAPI void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color) { rf_draw_poly(center, sides, radius, rotation, color); }
RLAPI void DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color) {
    if (sides < 3) sides = 3;
    float centralAngle = 0.0f;

    if (rf_gfx_check_buffer_limit(4 * (360 / sides))) rf_gfx_draw();

    rf_gfx_push_matrix();
    rf_gfx_translatef(center.x, center.y, 0.0f);
    rf_gfx_rotatef(rotation, 0.0f, 0.0f, 1.0f);
    rf_gfx_begin(RF_LINES);
    for (int i = 0; i < sides; i++)
    {
        rf_gfx_color4ub(color.r, color.g, color.b, color.a);

        rf_gfx_vertex2f(0, 0);
        rf_gfx_vertex2f(sinf(RF_DEG2RAD * centralAngle) * radius, cosf(RF_DEG2RAD * centralAngle) * radius);

        centralAngle += 360.0f / (float)sides;
        rf_gfx_vertex2f(sinf(RF_DEG2RAD * centralAngle) * radius, cosf(RF_DEG2RAD * centralAngle) * radius);
    }
    rf_gfx_end();

    rf_gfx_pop_matrix();
}

// Basic shapes collision detection functions
RLAPI bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2) { return rf_check_collision_recs(rec1, rec2); }
RLAPI bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2) { return rf_check_collision_circles(center1, radius1, center2, radius2); }
RLAPI bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec) { return rf_check_collision_circle_rec(center, radius, rec); }
RLAPI Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2) { return rf_get_collision_rec(rec1, rec2); }
RLAPI bool CheckCollisionPointRec(Vector2 point, Rectangle rec) { return rf_check_collision_point_rec(point, rec); }
RLAPI bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius) { return rf_check_collision_point_circle(point, center, radius); }
RLAPI bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3) { return rf_check_collision_point_triangle(point, p1, p2, p3); }

// Textures
// Image loading functions
RLAPI Image LoadImage(const char* fileName) { return rf_load_image_from_file_ez(fileName); }
RLAPI void UnloadImage(Image image) { rf_unload_image_ez(image); }

// Image generation functions
RLAPI Image GenImageColor(int width, int height, Color color) { return rf_gen_image_color_ez(width, height, color); }
RLAPI Image GenImageGradientV(int width, int height, Color top, Color bottom) { return rf_gen_image_gradient_v_ez(width, height, top, bottom); }
RLAPI Image GenImageGradientH(int width, int height, Color left, Color right) { return rf_gen_image_gradient_h_ez(width, height, left, right); }
RLAPI Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer) { return rf_gen_image_gradient_radial_ez(width, height, density, inner, outer); }
RLAPI Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2) { return rf_gen_image_checked_ez(width, height, checksX, checksY, col1, col2); }
RLAPI Image GenImageWhiteNoise(int width, int height, float factor) { return rf_gen_image_white_noise_ez(width, height, factor); }
RLAPI Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale) { return rf_gen_image_perlin_noise_ez(width, height, offsetX, offsetY, scale); }
RLAPI Image GenImageCellular(int width, int height, int tileSize) { return rf_gen_image_cellular_ez(width, height, tileSize); }

// Image manipulation functions
RLAPI Image ImageCopy(Image image) { return rf_image_copy_ez(image); }
RLAPI void ImageFormat(Image image, int newFormat) { rf_image_format_ez(image, newFormat); }
RLAPI void ImageAlphaMask(Image image, Image alphaMask, void* dst, int dst_size) { rf_image_alpha_mask_to_buffer(image, alphaMask, dst, dst_size); }
RLAPI void ImageAlphaClear(Image image, Color color, float threshold) { rf_image_alpha_clear_ez(image, color, threshold); }
RLAPI void ImageAlphaCrop(Image image, float threshold) { rf_image_alpha_crop_ez(image, threshold); }
RLAPI void ImageAlphaPremultiply(Image image) { rf_image_alpha_premultiply_ez(image); }
RLAPI void ImageCrop(Image image, Rectangle crop) { rf_image_crop_ez(image, crop); }
RLAPI void ImageResize(Image image, int newWidth, int newHeight) { rf_image_resize_ez(image, newWidth, newHeight); }
RLAPI void ImageResizeNN(Image image, int newWidth, int newHeight) { rf_image_resize_nn_ez(image, newWidth, newHeight); }
RLAPI void ImageMipmaps(Image image, int gen_mipmaps_count) { rf_image_gen_mipmaps_ez(image, gen_mipmaps_count); }
RLAPI void ImageDither(Image image, int rBpp, int gBpp, int bBpp, int aBpp) { rf_image_dither_ez(image, rBpp, gBpp, bBpp, aBpp); }
RLAPI void ImageFlipVertical(Image image) { rf_image_flip_vertical_ez(image); }
RLAPI void ImageFlipHorizontal(Image image) { rf_image_flip_horizontal_ez(image); }
RLAPI void ImageRotateCW(Image image) { rf_image_rotate_cw(image); }
RLAPI void ImageRotateCCW(Image image) { rf_image_rotate_ccw(image); }
RLAPI void ImageColorTint(Image image, Color color) { rf_image_color_tint(image, color); }
RLAPI void ImageColorInvert(Image image) { rf_image_color_invert(image); }
RLAPI void ImageColorGrayscale(Image image) { rf_image_color_grayscale(image); }
RLAPI void ImageColorContrast(Image image, float contrast) { rf_image_color_contrast(image, contrast); }
RLAPI void ImageColorBrightness(Image image, int brightness) { rf_image_color_brightness(image, brightness); }
RLAPI void ImageColorReplace(Image image, Color color, Color replace) { rf_image_color_replace(image, color, replace); }
RLAPI Color* ImageExtractPalette(Image image, int maxPaletteSize) { return rf_image_extract_palette_ez(image, maxPaletteSize).colors; }
RLAPI Rectangle GetImageAlphaBorder(Image image, float threshold) { return rf_image_alpha_border(image, threshold); }

// Image drawing functions
RLAPI void ImageClearBackground(Image* dst, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { 0, 0, dst->width, dst->height }, color); }
RLAPI void ImageDrawPixel(Image* dst, int x, int y, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { x, y, 1, 1 }, color); }
RLAPI void ImageDrawPixelV(Image* dst, Vector2 position, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { (int)position.x, (int)position.y, 1, 1 }, color); }
RLAPI void ImageDrawLine(Image* dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{
    int m = 2 * (endPosY - startPosY);
    int slopeError = m - (startPosY - startPosX);

    for (int x = startPosX, y = startPosY; x <= startPosY; x++)
    {
        ImageDrawPixel(dst, x, y, color);
        slopeError += m;

        if (slopeError >= 0)
        {
            y++;
            slopeError -= 2 * (startPosY - startPosX);
        }
    }
}
RLAPI void ImageDrawLineV(Image* dst, Vector2 start, Vector2 end, Color color) { ImageDrawLine(dst, (int)start.x, (int)start.y, (int)end.x, (int)end.y, color); }
RLAPI void ImageDrawRectangle(Image* dst, int posX, int posY, int width, int height, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { posX, posY, width, height }, color); }
RLAPI void ImageDrawRectangleV(Image* dst, Vector2 position, Vector2 size, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { position.x, position.y, size.x, size.y }, color); }
RLAPI void ImageDrawRectangleRec(Image* dst, Rectangle rec, Color color) { rf_image_draw_rectangle_ez(dst, rec, color); }
RLAPI void ImageDrawRectangleLines(Image* dst, Rectangle rec, int thick, Color color) { rf_image_draw_rectangle_lines_ez(dst, rec, thick, color); }
RLAPI void ImageDraw(Image* dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint) { rf_image_draw_ez(dst, src, srcRec, dstRec, tint); }
RLAPI void ImageDrawCircle(Image* dst, int centerX, int centerY, int radius, Color color)
{
    int x = 0, y = radius;
    int decesionParameter = 3 - 2 * radius;

    while (y >= x)
    {
        ImageDrawPixel(dst, centerX + x, centerY + y, color);
        ImageDrawPixel(dst, centerX - x, centerY + y, color);
        ImageDrawPixel(dst, centerX + x, centerY - y, color);
        ImageDrawPixel(dst, centerX - x, centerY - y, color);
        ImageDrawPixel(dst, centerX + y, centerY + x, color);
        ImageDrawPixel(dst, centerX - y, centerY + x, color);
        ImageDrawPixel(dst, centerX + y, centerY - x, color);
        ImageDrawPixel(dst, centerX - y, centerY - x, color);
        x++;

        if (decesionParameter > 0)
        {
            y--;
            decesionParameter = decesionParameter + 4 * (x - y) + 10;
        }
        else decesionParameter = decesionParameter + 4 * x + 6;
    }
}
RLAPI void ImageDrawCircleV(Image* dst, Vector2 center, int radius, Color color)
{
    ImageDrawCircle(dst, (int)center.x, (int)center.y, radius, color);
}

// Texture loading functions
RLAPI Texture2D LoadTexture(const char* fileName) { return rf_load_texture_from_file_ez(fileName); }
RLAPI Texture2D LoadTextureFromImage(Image image) { return rf_load_texture_from_image(image); }
RLAPI TextureCubemap LoadTextureCubemap(Image image, int layoutType) { return rf_load_texture_cubemap_from_image_ez(image, layoutType); }
RLAPI RenderTexture2D LoadRenderTexture(int width, int height) { return rf_load_render_texture(width, height); }
RLAPI void UnloadTexture(Texture2D texture) { rf_unload_texture(texture); }
RLAPI void UnloadRenderTexture(RenderTexture2D target) { rf_unload_render_texture(target); }
RLAPI void UpdateTexture(Texture2D texture, const void* pixels) { rf_update_texture(texture, pixels, 1); }
RLAPI Image GetScreenData(void) { return rf_get_screen_data_ez(); }

// Texture configuration functions
RLAPI void GenTextureMipmaps(Texture2D* texture) { rf_gen_texture_mipmaps(texture); }
RLAPI void SetTextureFilter(Texture2D texture, int filterMode) { rf_set_texture_filter(texture, filterMode); }
RLAPI void SetTextureWrap(Texture2D texture, int wrapMode) { rf_set_texture_wrap(texture, wrapMode); }

// Texture drawing functions
RLAPI void DrawTexture(Texture2D texture, int posX, int posY, Color tint) { rf_draw_texture(texture, posX, posY, tint); }
RLAPI void DrawTextureV(Texture2D texture, Vector2 position, Color tint) { rf_draw_texture(texture, position.x, position.y, tint); }
RLAPI void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint) { rf_draw_texture_ex(texture, position.x, position.y, texture.width * scale, texture.height * scale, rotation, tint); }
RLAPI void DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint) { rf_draw_texture_region(texture, sourceRec, (rf_rec) { sourceRec.x, sourceRec.y, texture.width, texture.height }, (rf_vec2) { 0, 0 }, 0.0, tint); }
RLAPI void DrawTextureQuad(Texture2D texture, Vector2 tiling, Vector2 offset, Rectangle quad, Color tint)
{
    rf_rec source = { offset.x * texture.width, offset.y * texture.height, tiling.x * texture.width, tiling.y * texture.height };
    rf_vec2 origin = { 0.0f, 0.0f };

    rf_draw_texture_region(texture, source, quad, origin, 0.0f, tint);
}
RLAPI void DrawTexturePro(Texture2D texture, Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint) { rf_draw_texture_region(texture, sourceRec, destRec, origin, rotation, tint); }
RLAPI void DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle destRec, Vector2 origin, float rotation, Color tint) { rf_draw_texture_npatch(texture, nPatchInfo, destRec, origin, rotation, tint); }

// Image/Texture misc functions
RLAPI int GetPixelDataSize(int width, int height, int format) { return rf_pixel_buffer_size(width, height, format); }

// Text
// Font loading/unloading functions
RLAPI Font GetFontDefault(void) { return rf_get_default_font(); }
RLAPI Font LoadFont(const char* fileName, int fontSize) { return rf_load_ttf_font_from_file_ez(fileName, RF_DEFAULT_FONT_SIZE, RF_FONT_ANTIALIAS); }
RLAPI Font LoadFontEx(const char* fileName, int fontSize, int* fontChars, int charsCount) { return rf_load_ttf_font_from_data_ez(fileName, fontSize, RF_FONT_ANTIALIAS, fontChars, charsCount); }
RLAPI Font LoadFontFromImage(Image image, Color key, int firstChar) { return rf_load_image_font_ez(image, key); }
RLAPI void UnloadFont(Font font) { rf_unload_font_ez(font); }

// Text drawing functions
RLAPI void DrawText(const char* text, int posX, int posY, int fontSize, Color color) { rf_draw_text(text, posX, posY, fontSize, color); }
RLAPI void DrawTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint) { rf_draw_text_ex(font, text, position, fontSize, spacing, tint); }
RLAPI void DrawTextRec(Font font, const char* text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint) { rf_draw_text_rec(font, text, rec, fontSize, spacing, wordWrap, tint); }

// Text misc. functions
RLAPI int MeasureText(const char* text, int fontSize) { return rf_measure_text(rf_get_default_font(), text, fontSize, 0.0f).width; }
RLAPI Vector2 MeasureTextEx(Font font, const char* text, float fontSize, float spacing) { rf_measure_text(font, text, fontSize, spacing); }
RLAPI int GetGlyphIndex(Font font, int codepoint) { return rf_get_glyph_index(font, codepoint); }

// Models
// Basic geometric 3D shapes drawing functions
RLAPI void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color) { rf_draw_line3d(startPos, endPos, color); }
RLAPI void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color) { rf_draw_circle3d(center, radius, rotationAxis, rotationAngle, color); }
RLAPI void DrawCube(Vector3 position, float width, float height, float length, Color color) { rf_draw_cube(position, width, height, length, color); }
RLAPI void DrawCubeV(Vector3 position, Vector3 size, Color color) { rf_draw_cube(position, size.x, size.y, size.z, color); }
RLAPI void DrawCubeWires(Vector3 position, float width, float height, float length, Color color) { rf_draw_cube_wires(position, width, height, length, color); }
RLAPI void DrawCubeWiresV(Vector3 position, Vector3 size, Color color) { rf_draw_cube_wires(position, size.x, size.y, size.z, color); }
RLAPI void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color) { rf_draw_cube_texture(texture, position, width, height, length, color); }
RLAPI void DrawSphere(Vector3 centerPos, float radius, Color color) { rf_draw_sphere(centerPos, radius, color); }
RLAPI void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color) { rf_draw_sphere_ex(centerPos, radius, rings, slices, color); }
RLAPI void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color) { rf_draw_sphere_wires(centerPos, radius, rings, slices, color); }
RLAPI void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) { rf_draw_cylinder(position, radiusTop, radiusBottom, height, slices, color); }
RLAPI void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) { rf_draw_cylinder_wires(position, radiusTop, radiusBottom, height, slices, color); }
RLAPI void DrawPlane(Vector3 centerPos, Vector2 size, Color color) { rf_draw_plane(centerPos, size, color); }
RLAPI void DrawRay(Ray ray, Color color) { rf_draw_ray(ray, color); }
RLAPI void DrawGrid(int slices, float spacing) { rf_draw_grid(slices, spacing); }
RLAPI void DrawGizmo(Vector3 position) { rf_draw_gizmo(position); }

// Model loading/unloading functions
RLAPI Model LoadModel(const char* fileName) { return rf_load_model_ez(fileName); }
RLAPI Model LoadModelFromMesh(Mesh mesh) { return rf_load_model_from_mesh_ez(mesh); }
RLAPI void UnloadModel(Model model) { rf_unload_model_ez(model); }

// Mesh loading/unloading functions
RLAPI void UnloadMesh(Mesh mesh) { rf_unload_mesh_ez(mesh); }

// Material loading/unloading functions
RLAPI Material LoadMaterialDefault(void) { return rf_load_default_material_ez(); }
RLAPI rf_materials_array LoadMaterials(const char* fileName) { return rf_load_materials_from_mtl_ez(&fileName); }
RLAPI void UnloadMaterial(Material material) { rf_unload_material_ez(material); }
RLAPI void SetMaterialTexture(Material* material, int mapType, Texture2D texture) { material->maps[mapType].texture = texture; }
RLAPI void SetModelMeshMaterial(Model* model, int meshId, int materialId) {
    if (!(meshId >= model->mesh_count) && !(materialId >= model->material_count)) model->mesh_material[meshId] = materialId;
}

// Model animations loading/unloading functions
RLAPI ModelAnimation* LoadModelAnimations(const char* fileName, int* animsCount) { rf_load_model_animations_from_iqm_ez(fileName, animsCount); }
RLAPI void UpdateModelAnimation(Model model, ModelAnimation anim, int frame) { rf_update_model_animation(model, anim, frame); }
RLAPI void UnloadModelAnimation(ModelAnimation anim) { rf_unload_model_animation_ez(anim); }
RLAPI bool IsModelAnimationValid(Model model, ModelAnimation anim) { return rf_is_model_animation_valid(model, anim); }

// Mesh generation functions
RLAPI Mesh GenMeshPoly(int sides, float radius) { return rf_gen_mesh_poly_ez(sides, radius); }
RLAPI Mesh GenMeshPlane(float width, float length, int resX, int resZ) { return rf_gen_mesh_plane_ez(width, length, resX, resZ); }
RLAPI Mesh GenMeshCube(float width, float height, float length) { return rf_gen_mesh_cube_ez(width, height, length); }
RLAPI Mesh GenMeshSphere(float radius, int rings, int slices) { return rf_gen_mesh_sphere_ez(radius, rings, slices); }
RLAPI Mesh GenMeshHemiSphere(float radius, int rings, int slices) { return rf_gen_mesh_hemi_sphere_ez(radius, rings, slices); }
RLAPI Mesh GenMeshCylinder(float radius, float height, int slices) { return rf_gen_mesh_cylinder_ez(radius, height, slices); }
RLAPI Mesh GenMeshTorus(float radius, float size, int radSeg, int sides) { return rf_gen_mesh_torus_ez(radius, size, radSeg, sides); }
RLAPI Mesh GenMeshKnot(float radius, float size, int radSeg, int sides) { return rf_gen_mesh_knot_ez(radius, size, radSeg, sides); }
RLAPI Mesh GenMeshHeightmap(Image heightmap, Vector3 size) { return rf_gen_mesh_heightmap_ez(heightmap, size); }
RLAPI Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize) { return rf_gen_mesh_cubicmap_ez(cubicmap, cubeSize); }

// Mesh manipulation functions
RLAPI BoundingBox MeshBoundingBox(Mesh mesh) { return rf_mesh_bounding_box(mesh); }
RLAPI void MeshTangents(Mesh* mesh) { rf_mesh_compute_tangents_ez(mesh); }
RLAPI void MeshBinormals(Mesh* mesh) { rf_mesh_compute_binormals(mesh); }

// Model drawing functions
RLAPI void DrawModel(Model model, Vector3 position, float scale, Color tint) { rf_draw_model(model, position, scale, tint); }
RLAPI void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) { rf_draw_model_ex(model, position, rotationAxis, rotationAngle, scale, tint); }
RLAPI void DrawModelWires(Model model, Vector3 position, float scale, Color tint) { rf_draw_model_wires(model, position, (rf_vec3) { 0, 0, 0 }, 0, (rf_vec3) { scale, scale, scale }, tint); }
RLAPI void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) { rf_draw_model_wires(model, position, rotationAxis, rotationAngle, scale, tint); }
RLAPI void DrawBoundingBox(BoundingBox box, Color color) { rf_draw_bounding_box(box, color); }
RLAPI void DrawBillboard(Camera camera, Texture2D texture, Vector3 center, float size, Color tint) { rf_draw_billboard(camera, texture, center, size, tint); }
RLAPI void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle sourceRec, Vector3 center, float size, Color tint) { rf_draw_billboard_rec(camera, texture, sourceRec, center, size, tint); }

// Collision detection functions
RLAPI bool CheckCollisionSpheres(Vector3 centerA, float radiusA, Vector3 centerB, float radiusB) { return rf_check_collision_spheres(centerA, radiusA, centerB, radiusB); }
RLAPI bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2) { return rf_check_collision_boxes(box1, box2); }
RLAPI bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius) { return rf_check_collision_box_sphere(box, center, radius); }
RLAPI bool CheckCollisionRaySphere(Ray ray, Vector3 center, float radius) { return rf_check_collision_ray_sphere(ray, center, radius); }
RLAPI bool CheckCollisionRaySphereEx(Ray ray, Vector3 center, float radius, Vector3* collisionPoint) { return rf_check_collision_ray_sphere_ex(ray, center, radius, collisionPoint); }
RLAPI bool CheckCollisionRayBox(Ray ray, BoundingBox box) { return rf_check_collision_ray_box(ray, box); }
RLAPI RayHitInfo GetCollisionRayModel(Ray ray, Model model) { return rf_collision_ray_model(ray, model); }
RLAPI RayHitInfo GetCollisionRayTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3) { return rf_collision_ray_triangle(ray, p1, p2, p3); }
RLAPI RayHitInfo GetCollisionRayGround(Ray ray, float groundHeight) { return rf_collision_ray_ground(ray, groundHeight); }

// Shaders
// Shader loading/unloading functions
RLAPI Shader LoadShaderCode(char* vsCode, char* fsCode) { return rf_gfx_load_shader(vsCode, fsCode); }
RLAPI void UnloadShader(Shader shader) { rf_gfx_unload_shader(shader); }

RLAPI Shader GetShaderDefault(void) { return rf_get_default_shader(); }
RLAPI Texture2D GetTextureDefault(void) { return rf_get_default_texture(); }
RLAPI Texture2D GetShapesTexture(void) { return rf_get_context()->tex_shapes; }
RLAPI Rectangle GetShapesTextureRec(void) { return rf_get_context()->rec_tex_shapes; }
RLAPI void SetShapesTexture(Texture2D texture, Rectangle source) { rf_set_shapes_texture(texture, source); }

// Shader configuration functions
RLAPI int GetShaderLocation(Shader shader, const char* uniformName) { return rf_gfx_get_shader_location(shader, uniformName); }
RLAPI void SetShaderValue(Shader shader, int uniformLoc, const void* value, int uniformType) { rf_gfx_set_shader_value(shader, uniformLoc, value, uniformType); }
RLAPI void SetShaderValueV(Shader shader, int uniformLoc, const void* value, int uniformType, int count) { rf_gfx_set_shader_value_v(shader, uniformLoc, value, uniformType, count); }
RLAPI void SetShaderValueMatrix(Shader shader, int uniformLoc, Matrix mat) { rf_gfx_set_shader_value_matrix(shader, uniformLoc, mat); }
RLAPI void SetShaderValueTexture(Shader shader, int uniformLoc, Texture2D texture) { rf_gfx_set_shader_value_texture(shader, uniformLoc, texture); }
RLAPI void SetMatrixProjection(Matrix proj) { rf_gfx_set_matrix_projection(proj); }
RLAPI void SetMatrixModelview(Matrix view) { rf_gfx_set_matrix_modelview(view); }
RLAPI Matrix GetMatrixModelview(void) { return rf_gfx_get_matrix_modelview(); }
RLAPI Matrix GetMatrixProjection(void) { return rf_gfx_get_matrix_projection(); }

// Texture maps generation (PBR)
RLAPI Texture2D GenTextureCubemap(Shader shader, Texture2D map, int size) { return rf_gen_texture_cubemap(shader, map, size); }
RLAPI Texture2D GenTextureIrradiance(Shader shader, Texture2D cubemap, int size) { return rf_gen_texture_irradiance(shader, cubemap, size); }
RLAPI Texture2D GenTexturePrefilter(Shader shader, Texture2D cubemap, int size) { return rf_gen_texture_prefilter(shader, cubemap, size); }
RLAPI Texture2D GenTextureBRDF(Shader shader, int size) { return rf_gen_texture_brdf(shader, size); }

// Shading begin/end functions
RLAPI void BeginShaderMode(Shader shader) { rf_begin_shader(shader); }
RLAPI void EndShaderMode(void) { rf_end_shader(); }
RLAPI void BeginBlendMode(int mode) { rf_gfx_blend_mode(mode); }
RLAPI void EndBlendMode(void) { rf_end_blend_mode(); }

// VR module will wrapped once rayfork supports it!
// Audio module will wrapped once rayfork supports it!

// RLGL
//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
enum {
    DEFAULT_BATCH_BUFFER_ELEMENTS = RF_DEFAULT_BATCH_ELEMENTS_COUNT,
    DEFAULT_BATCH_BUFFERS = RF_DEFAULT_BATCH_VERTEX_BUFFERS_COUNT,
    DEFAULT_BATCH_DRAWCALLS = RF_DEFAULT_BATCH_DRAW_CALLS_COUNT,
    MAX_MATRIX_STACK_SIZE = RF_MAX_MATRIX_STACK_SIZE,
    MAX_SHADER_LOCATIONS = RF_MAX_SHADER_LOCATIONS,
    MAX_MATERIAL_MAPS = RF_MAX_MATERIAL_MAPS,
    RL_TEXTURE_WRAP_S = 0x2802,
    RL_TEXTURE_WRAP_T = 0x2803,
    RL_TEXTURE_MAG_FILTER = 0x2800,
    RL_TEXTURE_MIN_FILTER = 0x2801,
    RL_TEXTURE_ANISOTROPIC_FILTER = 0x3000,
    RL_FILTER_NEAREST = 0x2600,
    RL_FILTER_LINEAR = 0x2601,
    RL_FILTER_MIP_NEAREST = 0x2700,
    RL_FILTER_NEAREST_MIP_LINEAR = 0x2702,
    RL_FILTER_LINEAR_MIP_NEAREST = 0x2701,
    RL_FILTER_MIP_LINEAR = 0x2703,
    RL_WRAP_REPEAT = RF_WRAP_REPEAT,
    RL_WRAP_CLAMP = RF_WRAP_CLAMP,
    RL_WRAP_MIRROR_REPEAT = RF_WRAP_MIRROR_REPEAT,
    RL_WRAP_MIRROR_CLAMP = RF_WRAP_MIRROR_CLAMP,
    RL_MODELVIEW = RF_MODELVIEW,
    RL_PROJECTION = RF_PROJECTION,
    RL_TEXTURE = RF_TEXTURE,
    RL_LINES = RF_LINES,
    RL_TRIANGLES = RF_TRIANGLES,
    RL_QUADS = RF_QUADS
};

//------------------------------------------------------------------------------------
// Functions Declaration - Matrix operations
//------------------------------------------------------------------------------------
RLAPI void rlMatrixMode(int mode) { rf_gfx_matrix_mode(mode); }
RLAPI void rlPushMatrix(void) { rf_gfx_push_matrix(); }
RLAPI void rlPopMatrix(void) { rf_gfx_pop_matrix(); }
RLAPI void rlLoadIdentity(void) { rf_gfx_load_identity(); }
RLAPI void rlTranslatef(float x, float y, float z) { rf_gfx_translatef(x, y, z); }
RLAPI void rlRotatef(float angleDeg, float x, float y, float z) { rf_gfx_rotatef(angleDeg, x, y, z); }
RLAPI void rlScalef(float x, float y, float z) { rf_gfx_scalef(x, y, z); }
RLAPI void rlMultMatrixf(float* matf) { rf_gfx_mult_matrixf(matf); }
RLAPI void rlFrustum(double left, double right, double bottom, double top, double znear, double zfar) { rf_gfx_frustum(left, right, bottom, top, znear, zfar); }
RLAPI void rlOrtho(double left, double right, double bottom, double top, double znear, double zfar) { rf_gfx_ortho(left, right, bottom, top, znear, zfar); }
RLAPI void rlViewport(int x, int y, int width, int height) { rf_gfx_viewport(x, y, width, height); }

//------------------------------------------------------------------------------------
// Functions Declaration - Vertex level operations
//------------------------------------------------------------------------------------
RLAPI void rlBegin(int mode) { rf_gfx_begin(mode); }
RLAPI void rlEnd(void) { rf_gfx_end(); }
RLAPI void rlVertex2i(int x, int y) { rf_gfx_vertex2i(x, y); }
RLAPI void rlVertex2f(float x, float y) { rf_gfx_vertex2f(x, y); }
RLAPI void rlVertex3f(float x, float y, float z) { rf_gfx_vertex3f(x, y, z); }
RLAPI void rlTexCoord2f(float x, float y) { rf_gfx_tex_coord2f(x, y); }
RLAPI void rlNormal3f(float x, float y, float z) { rf_gfx_normal3f(x, y, z); }
RLAPI void rlColor4ub(byte r, byte g, byte b, byte a) { rf_gfx_color4ub(r, g, b, a); }
RLAPI void rlColor3f(float x, float y, float z) { rf_gfx_color3f(x, y, z); }
RLAPI void rlColor4f(float x, float y, float z, float w) { rf_gfx_color4f(x, y, z, w); }
RLAPI Vector3 rlUnproject(Vector3 source, Matrix projection, Matrix view) { rf_unproject(source, projection, view); }

//------------------------------------------------------------------------------------
// Functions Declaration - OpenGL equivalent functions (common to 1.1, 3.3+, ES2)
//------------------------------------------------------------------------------------
RLAPI void rlEnableTexture(unsigned int id) { rf_gfx_enable_texture(id); }
RLAPI void rlDisableTexture(void) { rf_gfx_disable_texture(); }
RLAPI void rlTextureParameters(unsigned int id, int param, int value) { }
RLAPI void rlEnableRenderTexture(unsigned int id) { rf_gfx_enable_render_texture(id); }
RLAPI void rlDisableRenderTexture(void) { rf_gfx_disable_render_texture(); }
RLAPI void rlEnableDepthTest(void) { rf_gfx_enable_depth_test(); }
RLAPI void rlDisableDepthTest(void) { rf_gfx_disable_depth_test(); }
RLAPI void rlEnableBackfaceCulling(void) { rf_gfx_enable_backface_culling(); }
RLAPI void rlDisableBackfaceCulling(void) { rf_gfx_disable_backface_culling(); }
RLAPI void rlEnableScissorTest(void) { rf_gfx_enable_scissor_test(); }
RLAPI void rlDisableScissorTest(void) { rf_gfx_disable_scissor_test(); }
RLAPI void rlScissor(int x, int y, int width, int height) { rf_gfx_scissor(x, y, width, height); }
RLAPI void rlEnableWireMode(void) { rf_gfx_enable_wire_mode(); }
RLAPI void rlDisableWireMode(void) { rf_gfx_disable_wire_mode(); }
RLAPI void rlDeleteTextures(unsigned int id) { rf_gfx_delete_textures(id); }
RLAPI void rlDeleteRenderTextures(RenderTexture2D target) { rf_gfx_delete_render_textures(target); }
RLAPI void rlDeleteShader(unsigned int id) { rf_gfx_delete_shader(id); }
RLAPI void rlDeleteVertexArrays(unsigned int id) { rf_gfx_delete_vertex_arrays(id); }
RLAPI void rlDeleteBuffers(unsigned int id) { rf_gfx_delete_buffers(id); }
RLAPI void rlClearColor(byte r, byte g, byte b, byte a) { rf_gfx_clear_color(r, g, b, a); }
RLAPI void rlClearScreenBuffers(void) { rf_gfx_clear_screen_buffers(); }
RLAPI void rlUpdateBuffer(int bufferId, void* data, int dataSize) { rf_gfx_update_buffer(bufferId, data, dataSize); }
RLAPI unsigned int rlLoadAttribBuffer(unsigned int vaoId, int shaderLoc, void* buffer, int size, bool dynamic) { return rf_gfx_load_attrib_buffer(vaoId, shaderLoc, buffer, size, dynamic); }

//------------------------------------------------------------------------------------
// Functions Declaration - rlgl functionality
//------------------------------------------------------------------------------------
RLAPI void rlglClose(void) { rf_gfx_close(); }
RLAPI void rlglDraw(void) { rf_gfx_draw(); }

RLAPI bool rlCheckBufferLimit(int vCount) { return rf_gfx_check_buffer_limit(vCount); }
RLAPI void rlSetDebugMarker(const char* text) { rf_gfx_set_debug_marker(text); }

// Textures data management
RLAPI unsigned int rlLoadTexture(void* data, int width, int height, int format, int mipmapCount) { return rf_gfx_load_texture(data, width, height, format, mipmapCount); }
RLAPI unsigned int rlLoadTextureDepth(int width, int height, int bits, bool useRenderBuffer) { return rf_gfx_load_texture_depth(width, height, bits, useRenderBuffer); }
RLAPI unsigned int rlLoadTextureCubemap(void* data, int size, int format) { return rf_gfx_load_texture_cubemap(data, size, format); }
RLAPI void rlUpdateTexture(unsigned int id, int offsetX, int offsetY, int width, int height, int format, const void* data) { rf_gfx_update_texture(id, offsetX, offsetY, width, height, format, data); }
RLAPI void rlUnloadTexture(unsigned int id) { rf_gfx_unload_texture(id); }

RLAPI void rlGenerateMipmaps(Texture2D* texture) { rf_gfx_generate_mipmaps(texture); }
RLAPI void* rlReadTexturePixels(Texture2D texture) { rf_gfx_read_texture_pixels_ez(texture); }
RLAPI unsigned char* rlReadScreenPixels(int width, int height, Color* dstColor) { rf_gfx_read_screen_pixels(dstColor, width, height); }

// Render texture management (fbo)
RLAPI RenderTexture2D rlLoadRenderTexture(int width, int height, int format, int depthBits, bool useDepthTexture) { return rf_gfx_load_render_texture(width, height, format, depthBits, useDepthTexture); }
RLAPI void rlRenderTextureAttach(RenderTexture target, unsigned int id, int attachType) { rf_gfx_render_texture_attach(target, id, attachType); }
RLAPI bool rlRenderTextureComplete(RenderTexture target) { return rf_gfx_render_texture_complete(target); }

// Vertex data management
RLAPI void rlLoadMesh(Mesh* mesh, bool dynamic) { rf_gfx_load_mesh(mesh, dynamic); }
RLAPI void rlUpdateMesh(Mesh mesh, int buffer, int count) { rf_gfx_update_mesh(mesh, buffer, count); }
RLAPI void rlUpdateMeshAt(Mesh mesh, int buffer, int count, int index) { rf_gfx_update_mesh_at(mesh, buffer, count, index); }
RLAPI void rlDrawMesh(Mesh mesh, Material material, Matrix transform) { rf_gfx_draw_mesh(mesh, material, transform); }
RLAPI void rlUnloadMesh(Mesh mesh) { rf_gfx_unload_mesh(mesh); }

// raymath library
RMDEF float Clamp(float value, float min, float max) { return rf_clamp(value, min, max); }
RMDEF float Lerp(float start, float end, float amount) { return rf_lerp(start, end, amount); }

RMDEF Vector2 Vector2Zero(void) { return (Vector2) { 0, 0 }; }
RMDEF Vector2 Vector2One(void) { return (Vector2) { 1, 1 }; }
RMDEF Vector2 Vector2Add(Vector2 v1, Vector2 v2) { return rf_vec2_add(v1, v2); }
RMDEF Vector2 Vector2AddValue(Vector2 v, float add) { return (Vector2) { v.x + add, v.y + add }; }
RMDEF Vector2 Vector2Subtract(Vector2 v1, Vector2 v2) { return rf_vec2_sub(v1, v2); }
RMDEF Vector2 Vector2SubtractValue(Vector2 v, float sub) { return (Vector2) { v.x - sub, v.y - sub }; }
RMDEF float Vector2Length(Vector2 v) { return rf_vec2_len(v); }
RMDEF float Vector2LengthSqr(Vector2 v) { return sqrtf(rf_vec2_len(v)); }
RMDEF float Vector2DotProduct(Vector2 v1, Vector2 v2) { return rf_vec2_dot_product(v1, v2); }
RMDEF float Vector2Distance(Vector2 v1, Vector2 v2) { return rf_vec2_distance(v1, v2); }
RMDEF float Vector2Angle(Vector2 v1, Vector2 v2) { return rf_vec2_angle(v1, v2); }
RMDEF Vector2 Vector2Scale(Vector2 v, float scale) { return rf_vec2_scale(v, scale); }
RMDEF Vector2 Vector2Multiply(Vector2 v1, Vector2 v2) { return rf_vec2_mul_v(v1, v2); }
RMDEF Vector2 Vector2Negate(Vector2 v) { return rf_vec2_negate(v); }
RMDEF Vector2 Vector2Divide(Vector2 v1, Vector2 v2) { return rf_vec2_div_v(v1, v2); }
RMDEF Vector2 Vector2Normalize(Vector2 v) { return rf_vec2_normalize(v); }
RMDEF Vector2 Vector2Lerp(Vector2 v1, Vector2 v2, float amount) { return rf_vec2_lerp(v1, v2, amount); }
RMDEF Vector2 Vector2Rotate(Vector2 v, float degs) {
    float rads = degs * DEG2RAD;
    Vector2 result = { v.x * cosf(rads) - v.y * sinf(rads) , v.x * sinf(rads) + v.y * cosf(rads) };
    return result;
}
RMDEF Vector2 Vector2MoveTowards(Vector2 v, Vector2 target, float maxDistance) {
    Vector2 result = { 0 };
    float dx = target.x - v.x;
    float dy = target.y - v.y;
    float value = (dx * dx) + (dy * dy);

    if ((value == 0) || ((maxDistance >= 0) && (value <= maxDistance * maxDistance))) result = target;

    float dist = sqrtf(value);

    result.x = v.x + dx / dist * maxDistance;
    result.y = v.y + dy / dist * maxDistance;

    return result;
}

RMDEF Vector3 Vector3Zero(void) { return (Vector3) { 0, 0, 0 }; }
RMDEF Vector3 Vector3One(void) { return (Vector3) { 1, 1, 1 }; }
RMDEF Vector3 Vector3Add(Vector3 v1, Vector3 v2) { return rf_vec3_add(v1, v2); }
RMDEF Vector3 Vector3AddValue(Vector3 v, float add) { return (Vector3) { v.x + add, v.y + add, v.z + add }; }
RMDEF Vector3 Vector3Subtract(Vector3 v1, Vector3 v2) { return rf_vec3_sub(v1, v2); }
RMDEF Vector3 Vector3SubtractValue(Vector3 v, float sub) { return (Vector3) { v.x - sub, v.y - sub, v.z - sub }; }
RMDEF Vector3 Vector3Scale(Vector3 v, float scalar) { return rf_vec3_scale(v, scalar); }
RMDEF Vector3 Vector3Multiply(Vector3 v1, Vector3 v2) { return rf_vec3_mul_v(v1, v2); }
RMDEF Vector3 Vector3CrossProduct(Vector3 v1, Vector3 v2) { return rf_vec3_cross_product(v1, v2); }
RMDEF Vector3 Vector3Perpendicular(Vector3 v) { return rf_vec3_perpendicular(v); }
RMDEF float Vector3Length(const Vector3 v) { return rf_vec3_len(v); }
RMDEF float Vector3LengthSqr(const Vector3 v) { return sqrtf(rf_vec3_len(v)); }
RMDEF float Vector3DotProduct(Vector3 v1, Vector3 v2) { return rf_vec3_dot_product(v1, v2); }
RMDEF float Vector3Distance(Vector3 v1, Vector3 v2) { return rf_vec3_distance(v1, v2); }
RMDEF Vector3 Vector3Negate(Vector3 v) { return rf_vec3_negate(v); }
RMDEF Vector3 Vector3Divide(Vector3 v1, Vector3 v2) { return rf_vec3_div_v(v1, v2); }
RMDEF Vector3 Vector3Normalize(Vector3 v) { return rf_vec3_normalize(v); }
RMDEF void Vector3OrthoNormalize(Vector3* v1, Vector3* v2) { return rf_vec3_ortho_normalize(v1, v2); }
RMDEF Vector3 Vector3Transform(Vector3 v, Matrix mat) { return rf_vec3_transform(v, mat); }
RMDEF Vector3 Vector3RotateByQuaternion(Vector3 v, Quaternion q) { return rf_vec3_rotate_by_quaternion(v, q); }
RMDEF Vector3 Vector3Lerp(Vector3 v1, Vector3 v2, float amount) { return rf_vec3_lerp(v1, v2, amount); }
RMDEF Vector3 Vector3Reflect(Vector3 v, Vector3 normal) { return rf_vec3_reflect(v, normal); }
RMDEF Vector3 Vector3Min(Vector3 v1, Vector3 v2) { return rf_vec3_min(v1, v2); }
RMDEF Vector3 Vector3Max(Vector3 v1, Vector3 v2) { return rf_vec3_max(v1, v2); }
RMDEF Vector3 Vector3Barycenter(Vector3 p, Vector3 a, Vector3 b, Vector3 c) { return rf_vec3_barycenter(p, a, b, c); }
RMDEF float3 Vector3ToFloatV(Vector3 v) {
    float3 buffer = { 0 };

    buffer.v[0] = v.x;
    buffer.v[1] = v.y;
    buffer.v[2] = v.z;

    return buffer;
}
RMDEF float* Vector3ToFloat(Vector3 vec) { return Vector3ToFloatV(vec).v; };
RMDEF Vector3 Vector3Unproject(Vector3 source, Matrix projection, Matrix view) { rf_unproject(source, projection, view); }

RMDEF float MatrixDeterminant(Matrix mat) { return rf_mat_determinant(mat); }
RMDEF float MatrixTrace(Matrix mat) { return rf_mat_trace(mat); }
RMDEF Matrix MatrixTranspose(Matrix mat) { return rf_mat_transpose(mat); }
RMDEF Matrix MatrixInvert(Matrix mat) { return rf_mat_invert(mat); }
RMDEF Matrix MatrixNormalize(Matrix mat) { return rf_mat_normalize(mat); }
RMDEF Matrix MatrixIdentity(void) { return rf_mat_identity(); }
RMDEF Matrix MatrixAdd(Matrix left, Matrix right) { return rf_mat_add(left, right); }
RMDEF Matrix MatrixSubtract(Matrix left, Matrix right) { return rf_mat_sub(left, right); }
RMDEF Matrix MatrixTranslate(float x, float y, float z) { return rf_mat_translate(x, y, z); }
RMDEF Matrix MatrixRotate(Vector3 axis, float angle) { return rf_mat_rotate(axis, angle); }
RMDEF Matrix MatrixRotateXYZ(Vector3 ang) { return rf_mat_rotate_xyz(ang); }
RMDEF Matrix MatrixRotateX(float angle) { return rf_mat_rotate_x(angle); }
RMDEF Matrix MatrixRotateY(float angle) { return rf_mat_rotate_y(angle); }
RMDEF Matrix MatrixRotateZ(float angle) { return rf_mat_rotate_z(angle); }
RMDEF Matrix MatrixScale(float x, float y, float z) { return rf_mat_scale(x, y, z); }
RMDEF Matrix MatrixMultiply(Matrix left, Matrix right) { return rf_mat_mul(left, right); }
RMDEF Matrix MatrixFrustum(double left, double right, double bottom, double top, double near, double far) { return rf_mat_frustum(left, right, bottom, top, near, far); }
RMDEF Matrix MatrixPerspective(double fovy, double aspect, double near, double far) { return rf_mat_perspective(fovy, aspect, near, far); }
RMDEF Matrix MatrixOrtho(double left, double right, double bottom, double top, double near, double far) { return rf_mat_ortho(left, right, bottom, top, near, far); }
RMDEF Matrix MatrixLookAt(Vector3 eye, Vector3 target, Vector3 up) { return rf_mat_look_at(eye, target, up); }
RMDEF float16 MatrixToFloatV(Matrix mat) {
    float16 buffer = { 0 };

    buffer.v[0] = mat.m0;
    buffer.v[1] = mat.m1;
    buffer.v[2] = mat.m2;
    buffer.v[3] = mat.m3;
    buffer.v[4] = mat.m4;
    buffer.v[5] = mat.m5;
    buffer.v[6] = mat.m6;
    buffer.v[7] = mat.m7;
    buffer.v[8] = mat.m8;
    buffer.v[9] = mat.m9;
    buffer.v[10] = mat.m10;
    buffer.v[11] = mat.m11;
    buffer.v[12] = mat.m12;
    buffer.v[13] = mat.m13;
    buffer.v[14] = mat.m14;
    buffer.v[15] = mat.m15;

    return buffer;
}
RMDEF float* MatrixToFloat(Matrix mat) { return MatrixToFloatV(mat).v; }

RMDEF Quaternion QuaternionAdd(Quaternion q1, Quaternion q2) {
    Quaternion result = { q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w };
    return result;
}
RMDEF Quaternion QuaternionAddValue(Quaternion q, float add) {
    Quaternion result = { q.x + add, q.y + add, q.z + add, q.w + add };
    return result;
}
RMDEF Quaternion QuaternionSubtract(Quaternion q1, Quaternion q2) {
    Quaternion result = { q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w };
    return result;
}
RMDEF Quaternion QuaternionSubtractValue(Quaternion q, float sub) {
    Quaternion result = { q.x - sub, q.y - sub, q.z - sub, q.w - sub };
    return result;
}
RMDEF Quaternion QuaternionIdentity(void) { return rf_quaternion_identity(); }
RMDEF float QuaternionLength(Quaternion q) { return rf_quaternion_len(q); }
RMDEF Quaternion QuaternionNormalize(Quaternion q) { return rf_quaternion_normalize(q); }
RMDEF Quaternion QuaternionInvert(Quaternion q) { return rf_quaternion_invert(q); }
RMDEF Quaternion QuaternionMultiply(Quaternion q1, Quaternion q2) { return rf_quaternion_mul(q1, q2); }
RMDEF Quaternion QuaternionScale(Quaternion q, float mul) {
    Quaternion result = { 0 };

    float qax = q.x, qay = q.y, qaz = q.z, qaw = q.w;

    result.x = qax * mul + qaw * mul + qay * mul - qaz * mul;
    result.y = qay * mul + qaw * mul + qaz * mul - qax * mul;
    result.z = qaz * mul + qaw * mul + qax * mul - qay * mul;
    result.w = qaw * mul - qax * mul - qay * mul - qaz * mul;

    return result;
}
RMDEF Quaternion QuaternionDivide(Quaternion q1, Quaternion q2) {
    Quaternion result = { q1.x / q2.x, q1.y / q2.y, q1.z / q2.z, q1.w / q2.w };
    return result;
}
RMDEF Quaternion QuaternionLerp(Quaternion q1, Quaternion q2, float amount) { return rf_quaternion_lerp(q1, q2, amount); }
RMDEF Quaternion QuaternionNlerp(Quaternion q1, Quaternion q2, float amount) { return rf_quaternion_nlerp(q1, q2, amount); }
RMDEF Quaternion QuaternionSlerp(Quaternion q1, Quaternion q2, float amount) { return rf_quaternion_slerp(q1, q2, amount); }
RMDEF Quaternion QuaternionFromVector3ToVector3(Vector3 from, Vector3 to) {
    Quaternion result = { 0 };

    float cos2Theta = Vector3DotProduct(from, to);
    Vector3 cross = Vector3CrossProduct(from, to);

    result.x = cross.x;
    result.y = cross.y;
    result.z = cross.y;
    result.w = 1.0f + cos2Theta;     // NOTE: Added QuaternioIdentity()

    // Normalize to essentially nlerp the original and identity to 0.5
    result = QuaternionNormalize(result);

    // Above lines are equivalent to:
    //Quaternion result = QuaternionNlerp(q, QuaternionIdentity(), 0.5f);

    return result;
}
RMDEF Quaternion QuaternionFromMatrix(Matrix mat) {
    Quaternion result = { 0 };

    float trace = MatrixTrace(mat);

    if (trace > 0.0f)
    {
        float s = sqrtf(trace + 1) * 2.0f;
        float invS = 1.0f / s;

        result.w = s * 0.25f;
        result.x = (mat.m6 - mat.m9) * invS;
        result.y = (mat.m8 - mat.m2) * invS;
        result.z = (mat.m1 - mat.m4) * invS;
    }
    else
    {
        float m00 = mat.m0, m11 = mat.m5, m22 = mat.m10;

        if (m00 > m11 && m00 > m22)
        {
            float s = (float)sqrt(1.0f + m00 - m11 - m22) * 2.0f;
            float invS = 1.0f / s;

            result.w = (mat.m6 - mat.m9) * invS;
            result.x = s * 0.25f;
            result.y = (mat.m4 + mat.m1) * invS;
            result.z = (mat.m8 + mat.m2) * invS;
        }
        else if (m11 > m22)
        {
            float s = sqrtf(1.0f + m11 - m00 - m22) * 2.0f;
            float invS = 1.0f / s;

            result.w = (mat.m8 - mat.m2) * invS;
            result.x = (mat.m4 + mat.m1) * invS;
            result.y = s * 0.25f;
            result.z = (mat.m9 + mat.m6) * invS;
        }
        else
        {
            float s = sqrtf(1.0f + m22 - m00 - m11) * 2.0f;
            float invS = 1.0f / s;

            result.w = (mat.m1 - mat.m4) * invS;
            result.x = (mat.m8 + mat.m2) * invS;
            result.y = (mat.m9 + mat.m6) * invS;
            result.z = s * 0.25f;
        }
    }

    return result;
}
RMDEF Matrix QuaternionToMatrix(Quaternion q) {
    Matrix result = { 0 };

    float x = q.x, y = q.y, z = q.z, w = q.w;

    float x2 = x + x;
    float y2 = y + y;
    float z2 = z + z;

    float length = QuaternionLength(q);
    float lengthSquared = length * length;

    float xx = x * x2 / lengthSquared;
    float xy = x * y2 / lengthSquared;
    float xz = x * z2 / lengthSquared;

    float yy = y * y2 / lengthSquared;
    float yz = y * z2 / lengthSquared;
    float zz = z * z2 / lengthSquared;

    float wx = w * x2 / lengthSquared;
    float wy = w * y2 / lengthSquared;
    float wz = w * z2 / lengthSquared;

    result.m0 = 1.0f - (yy + zz);
    result.m1 = xy - wz;
    result.m2 = xz + wy;
    result.m3 = 0.0f;
    result.m4 = xy + wz;
    result.m5 = 1.0f - (xx + zz);
    result.m6 = yz - wx;
    result.m7 = 0.0f;
    result.m8 = xz - wy;
    result.m9 = yz + wx;
    result.m10 = 1.0f - (xx + yy);
    result.m11 = 0.0f;
    result.m12 = 0.0f;
    result.m13 = 0.0f;
    result.m14 = 0.0f;
    result.m15 = 1.0f;

    return result;
}
RMDEF Quaternion QuaternionFromAxisAngle(Vector3 axis, float angle) { return rf_quaternion_from_axis_angle(axis, angle); }
RMDEF void QuaternionToAxisAngle(Quaternion q, Vector3* outAxis, float* outAngle) { return rf_quaternion_to_axis_angle(q, outAxis, outAngle); }
RMDEF Quaternion QuaternionFromEuler(float roll, float pitch, float yaw) { return rf_quaternion_from_euler(roll, pitch, yaw); }
RMDEF Vector3 QuaternionToEuler(Quaternion q) { return rf_quaternion_to_euler(q); }
RMDEF Quaternion QuaternionTransform(Quaternion q, Matrix mat) { return rf_quaternion_transform(q, mat); }

// raylib easings
// Linear Easing functions
EASEDEF float EaseLinearNone(float t, float b, float c, float d) { return (c * t / d + b); }
EASEDEF float EaseLinearIn(float t, float b, float c, float d) { return (c * t / d + b); }
EASEDEF float EaseLinearOut(float t, float b, float c, float d) { return (c * t / d + b); }
EASEDEF float EaseLinearInOut(float t, float b, float c, float d) { return (c * t / d + b); }

// Sine Easing functions
EASEDEF float EaseSineIn(float t, float b, float c, float d) { return (-c * cosf(t / d * (PI / 2.0f)) + c + b); }
EASEDEF float EaseSineOut(float t, float b, float c, float d) { return (c * sinf(t / d * (PI / 2.0f)) + b); }
EASEDEF float EaseSineInOut(float t, float b, float c, float d) { return (-c / 2.0f * (cosf(PI * t / d) - 1.0f) + b); }

// Circular Easing functions
EASEDEF float EaseCircIn(float t, float b, float c, float d) { t /= d; return (-c * (sqrt(1.0f - t * t) - 1.0f) + b); }
EASEDEF float EaseCircOut(float t, float b, float c, float d) { t = t / d - 1.0f; return (c * sqrt(1.0f - t * t) + b); }
EASEDEF float EaseCircInOut(float t, float b, float c, float d)
{
    if ((t /= d / 2.0f) < 1.0f) return (-c / 2.0f * (sqrt(1.0f - t * t) - 1.0f) + b);
    t -= 2.0f; return (c / 2.0f * (sqrt(1.0f - t * t) + 1.0f) + b);
}

// Cubic Easing functions
EASEDEF float EaseCubicIn(float t, float b, float c, float d) { t /= d; return (c * t * t * t + b); }
EASEDEF float EaseCubicOut(float t, float b, float c, float d) { t = t / d - 1.0f; return (c * (t * t * t + 1.0f) + b); }
EASEDEF float EaseCubicInOut(float t, float b, float c, float d)
{
    if ((t /= d / 2.0f) < 1.0f) return (c / 2.0f * t * t * t + b);
    t -= 2.0f; return (c / 2.0f * (t * t * t + 2.0f) + b);
}

// Quadratic Easing functions
EASEDEF float EaseQuadIn(float t, float b, float c, float d) { t /= d; return (c * t * t + b); }
EASEDEF float EaseQuadOut(float t, float b, float c, float d) { t /= d; return (-c * t * (t - 2.0f) + b); }
EASEDEF float EaseQuadInOut(float t, float b, float c, float d)
{
    if ((t /= d / 2) < 1) return (((c / 2) * (t * t)) + b);
    return (-c / 2.0f * (((t - 1.0f) * (t - 3.0f)) - 1.0f) + b);
}

// Exponential Easing functions
EASEDEF float EaseExpoIn(float t, float b, float c, float d) { return (t == 0.0f) ? b : (c * pow(2.0f, 10.0f * (t / d - 1.0f)) + b); }
EASEDEF float EaseExpoOut(float t, float b, float c, float d) { return (t == d) ? (b + c) : (c * (-pow(2.0f, -10.0f * t / d) + 1.0f) + b); }
EASEDEF float EaseExpoInOut(float t, float b, float c, float d)
{
    if (t == 0.0f) return b;
    if (t == d) return (b + c);
    if ((t /= d / 2.0f) < 1.0f) return (c / 2.0f * pow(2.0f, 10.0f * (t - 1.0f)) + b);

    return (c / 2.0f * (-pow(2.0f, -10.0f * (t - 1.0f)) + 2.0f) + b);
}

// Back Easing functions
EASEDEF float EaseBackIn(float t, float b, float c, float d)
{
    float s = 1.70158f;
    float postFix = t /= d;
    return (c * (postFix)*t * ((s + 1.0f) * t - s) + b);
}

EASEDEF float EaseBackOut(float t, float b, float c, float d)
{
    float s = 1.70158f;
    t = t / d - 1.0f;
    return (c * (t * t * ((s + 1.0f) * t + s) + 1.0f) + b);
}

EASEDEF float EaseBackInOut(float t, float b, float c, float d)
{
    float s = 1.70158f;
    if ((t /= d / 2.0f) < 1.0f)
    {
        s *= 1.525f;
        return (c / 2.0f * (t * t * ((s + 1.0f) * t - s)) + b);
    }

    float postFix = t -= 2.0f;
    s *= 1.525f;
    return (c / 2.0f * ((postFix)*t * ((s + 1.0f) * t + s) + 2.0f) + b);
}

// Bounce Easing functions
EASEDEF float EaseBounceOut(float t, float b, float c, float d)
{
    if ((t /= d) < (1.0f / 2.75f))
    {
        return (c * (7.5625f * t * t) + b);
    }
    else if (t < (2.0f / 2.75f))
    {
        float postFix = t -= (1.5f / 2.75f);
        return (c * (7.5625f * (postFix)*t + 0.75f) + b);
    }
    else if (t < (2.5 / 2.75))
    {
        float postFix = t -= (2.25f / 2.75f);
        return (c * (7.5625f * (postFix)*t + 0.9375f) + b);
    }
    else
    {
        float postFix = t -= (2.625f / 2.75f);
        return (c * (7.5625f * (postFix)*t + 0.984375f) + b);
    }
}

EASEDEF float EaseBounceIn(float t, float b, float c, float d) { return (c - EaseBounceOut(d - t, 0.0f, c, d) + b); }
EASEDEF float EaseBounceInOut(float t, float b, float c, float d)
{
    if (t < d / 2.0f) return (EaseBounceIn(t * 2.0f, 0.0f, c, d) * 0.5f + b);
    else return (EaseBounceOut(t * 2.0f - d, 0.0f, c, d) * 0.5f + c * 0.5f + b);
}

// Elastic Easing functions
EASEDEF float EaseElasticIn(float t, float b, float c, float d)
{
    if (t == 0.0f) return b;
    if ((t /= d) == 1.0f) return (b + c);

    float p = d * 0.3f;
    float a = c;
    float s = p / 4.0f;
    float postFix = a * pow(2.0f, 10.0f * (t -= 1.0f));

    return (-(postFix * sinf((t * d - s) * (2.0f * PI) / p)) + b);
}

EASEDEF float EaseElasticOut(float t, float b, float c, float d)
{
    if (t == 0.0f) return b;
    if ((t /= d) == 1.0f) return (b + c);

    float p = d * 0.3f;
    float a = c;
    float s = p / 4.0f;

    return (a * pow(2.0f, -10.0f * t) * sinf((t * d - s) * (2.0f * PI) / p) + c + b);
}

EASEDEF float EaseElasticInOut(float t, float b, float c, float d)
{
    if (t == 0.0f) return b;
    if ((t /= d / 2.0f) == 2.0f) return (b + c);

    float p = d * (0.3f * 1.5f);
    float a = c;
    float s = p / 4.0f;

    if (t < 1.0f)
    {
        float postFix = a * pow(2.0f, 10.0f * (t -= 1.0f));
        return -0.5f * (postFix * sinf((t * d - s) * (2.0f * PI) / p)) + b;
    }

    float postFix = a * pow(2.0f, -10.0f * (t -= 1.0f));

    return (postFix * sinf((t * d - s) * (2.0f * PI) / p) * 0.5f + c + b);
}

#endif // RAYPORT_H
#pragma endregion