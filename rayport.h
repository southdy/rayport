// Created by Rabia Alhaffar in 1/September/2020
// rayport, Awesome C99, Single Source, rayfork wrapper for raylib!
// Latest update: 12/September/2020

// rayport
#pragma region rayport
#ifndef RAYPORT_H
#define RAYPORT_H

#ifdef RAYLIB_H
#ifdef RAYFORK_H

typedef unsigned char byte;
typedef struct float3 { float v[3]; } float3;
typedef struct float16 { float v[16]; } float16;

// Type converters used by rayport
// Consider using these if you got stuck with using rayfork or raylib types
#pragma region rayport converters
// raylib type -> rayfork type
rf_color rfcolor(Color c) { return (rf_color) { c.r, c.g, c.b, c.a }; }
rf_vec2 rfvec2(Vector2 v) { return (rf_vec2) { v.x, v.y }; }
rf_vec3 rfvec3(Vector3 v) { return (rf_vec3) { v.x, v.y, v.z }; }
rf_vec4 rfvec4(Vector4 v) { return (rf_vec4) { v.x, v.y, v.z, v.w }; }
rf_camera2d rfcam2d(Camera2D c) { return (rf_camera2d) { rfvec2(c.offset), rfvec2(c.target), c.rotation, c.zoom }; }
rf_camera3d rfcam3d(Camera3D c) { 
    rf_camera3d cam = { 0 };
    cam.type = c.type;
    cam.position = rfvec3(c.position);
    cam.target = rfvec3(c.target);
    cam.up = rfvec3(c.up);
    cam.fovy = c.fovy;
    return cam;
}
rf_rec rfrec(Rectangle r) { return (rf_rec) { r.x, r.y, r.width, r.height }; }
rf_bounding_box rfbox(BoundingBox b) { return (rf_bounding_box) { rfvec3(b.min), rfvec3(b.max) }; }
rf_texture2d rftex(Texture2D t) { return (rf_texture2d) { t.id, t.width, t.height, t.mipmaps, t.format, t.valid }; }
rf_image rfimg(Image i) { return (rf_image) { i.data, i.width, i.height, i.format, i.valid }; }
rf_render_texture2d rfrtex2d(RenderTexture2D r) { return (rf_render_texture2d) { r.id, rftex(r.texture), rftex(r.depth) }; }
rf_shader rfshader(Shader s) { return (rf_shader) { s.id, s.locs }; }
rf_ray rfray(Ray r) { return (rf_ray) { rfvec3(r.position), rfvec3(r.direction) }; }
rf_glyph_info rfcharinfo(CharInfo g) { return (rf_glyph_info) { g.value, g.offsetX, g.offsetY, g.advanceX }; }
rf_font rffont(Font f) { return (rf_font) { f.baseSize, f.charsCount, &f.texture, f.recs, f.chars }; }
rf_mesh rfmesh(Mesh m) { return (rf_mesh) { m.vertexCount, m.triangleCount, m.vertices, m.texcoords, m.texcoords2, m.normals, m.colors, m.indices, m.animVertices, m.animNormals, m.boneIds, m.boneWeights, m.vaoId, m.vboId }; }
rf_material rfmaterial(Material m) { return (rf_material) { rfshader(m.shader), m.maps, m.params }; }
rf_npatch_info rfnpinfo(NPatchInfo n) { return (rf_npatch_info) { rfrec(n.sourceRec), n.left, n.right, n.top, n.bottom, n.type }; }
rf_mat rfmat(Matrix m) { return (rf_mat) { m.m0, m.m1, m.m2, m.m3, m.m4, m.m5, m.m6, m.m7, m.m8, m.m9, m.m10, m.m11, m.m12, m.m13, m.m14, m.m15 }; }
rf_model_animation rfanim(ModelAnimation a) { return (rf_model_animation) { a.boneCount, a.bones, a.frameCount, a.framePoses }; }
rf_ray_hit_info rfhitinfo(RayHitInfo r) {
    return (rf_ray_hit_info) { r.hit, r.distance, rfvec3(r.position), rfvec3(r.normal) };
}
rf_quaternion rfquat(Quaternion q) { return (rf_quaternion) { q.x, q.y, q.z, q.w }; }

// rayfork type -> raylib type
Matrix rayfork_matrix(rf_mat m) {
    return (Matrix) { m.m0, m.m1, m.m2, m.m3, m.m4, m.m5, m.m6, m.m7, m.m8, m.m9, m.m10, m.m11, m.m12, m.m13, m.m14, m.m15 };
}
Model rayfork_model(rf_model m) {
    Model mod = { 0 };
    mod.transform = rayfork_matrix(m.transform);
    mod.meshCount = m.mesh_count;
    mod.meshes = m.meshes;
    mod.materialCount = m.material_count;
    mod.materials = m.materials;
    mod.meshMaterial = m.mesh_material;
    mod.boneCount = m.bone_count;
    mod.bones = m.bones;
    mod.bindPose = m.bind_pose;
    return mod;
}
rf_model rfmodel(Model m) {
    rf_model mod = { 0 };
    mod.transform = rfmat(m.transform);
    mod.mesh_count = m.meshCount;
    mod.meshes = m.meshes;
    mod.material_count = m.materialCount;
    mod.materials = m.materials;
    mod.mesh_material = m.meshMaterial;
    mod.bone_count = m.boneCount;
    mod.bones = m.bones;
    mod.bind_pose = m.bindPose;
    return mod;
}
Mesh rayfork_mesh(rf_mesh m) {
    return (Mesh) { m.vertex_count, m.triangle_count, m.vertices, m.texcoords, m.texcoords2, m.normals, m.colors, m.indices, m.anim_vertices, m.anim_normals, m.bone_ids, m.bone_weights, m.vao_id, m.vbo_id };
}
Shader rayfork_shader(rf_shader s) { return (Shader) { s.id, s.locs }; }
Material rayfork_material(rf_material m) { return (Material) { rayfork_shader(m.shader), m.maps, m.params }; }

Texture2D rayfork_texture(rf_texture2d t) {
    return (Texture2D) { t.id, t.width, t.height, t.mipmaps, t.format, t.valid };
}
Rectangle rayfork_rectangle(rf_rec r) {
    return (Rectangle) { r.x, r.y, r.width, r.height };
}
RenderTexture2D rayfork_render_texture2d(rf_render_texture2d r) {
    return (RenderTexture2D) { r.id, rayfork_texture(r.texture), rayfork_texture(r.depth), r.depth_texture };
}
Font rayfork_font(rf_font f) {
    Font fo = { 0 };
    fo.charsCount = f.glyphs_count;
    fo.chars = f.glyphs;
    fo.baseSize = f.base_size;
    fo.texture = rayfork_texture(f.texture);
    fo.recs = &f.glyphs->rec;
    return fo;
}
Image rayfork_image(rf_image i) {
    return (Image) { i.data, i.width, i.height, i.format, i.valid };
}
Vector4 rayfork_vec4(rf_vec4 v) { return (Vector4) { v.x, v.y, v.z, v.w }; }
Vector3 rayfork_vec3(rf_vec3 v) { return (Vector3) { v.x, v.y, v.z }; }
Vector2 rayfork_vec2(rf_vec2 v) { return (Vector2) { v.x, v.y }; }
Ray rayfork_ray(rf_ray r) {
    return (Ray) { rayfork_vec3(r.position), rayfork_vec3(r.direction) };
}
Color rayfork_color(rf_color c) { return (Color) { c.r, c.g, c.b, c.a }; }
RayHitInfo rayfork_rayhitinfo(rf_ray_hit_info r) {
    return (RayHitInfo) { r.hit, r.distance, rayfork_vec3(r.position), rayfork_vec3(r.normal) };
}
BoundingBox rayfork_box(rf_bounding_box b) {
    return (BoundingBox) { rayfork_vec3(b.min), rayfork_vec3(b.max) };
}
ModelAnimation rayfork_animation(rf_model_animation a) {
    return (ModelAnimation) { a.bone_count, a.bones, a.frame_count, a.frame_poses };
}
NPatchInfo rayfork_npatch_info(rf_npatch_info n) { return (NPatchInfo) { rayfork_rectangle(n.source_rec), n.left, n.right, n.top, n.bottom, n.type }; }
Quaternion rayfork_quat(rf_quaternion q) { return (Quaternion) { q.x, q.y, q.z, q.w }; }
#pragma endregion

#pragma region Core

// Misc. functions
#pragma region Misc. functions
RLAPI void SetTraceLogLevel(int logType) { rf_set_log_filter(logType); }
#define TraceLog(log_type, msg, ...) rf_log_impl(__FILE__, __LINE__, __FUNCTION__, (log_type), (msg), ##__VA_ARGS__)
RLAPI void SetTraceLogCallback(TraceLogCallback callback) { rf_set_log_callback(callback); }
#pragma endregion

// Drawing-related functions
#pragma region Drawing-related functions
RLAPI void ClearBackground(Color color) { rf_clear(rfcolor(color)); }
RLAPI void BeginDrawing(void) { rf_begin(); }
RLAPI void EndDrawing(void) { rf_end(); }
RLAPI void BeginMode2D(Camera2D camera) { rf_begin_2d(rfcam2d(camera)); }
RLAPI void EndMode2D(void) { rf_end_2d(); }
RLAPI void BeginMode3D(Camera camera) { rf_begin_3d(rfcam3d(camera)); }
RLAPI void EndMode3D(void) { rf_end_3d(); }
RLAPI void BeginTextureMode(RenderTexture2D target) { rf_begin_render_to_texture(rfrtex2d(target)); }
RLAPI void EndTextureMode(void) { rf_end_render_to_texture(); }
RLAPI void BeginScissorMode(int x, int y, int width, int height) { rf_begin_scissor_mode(x, y, width, height); }
RLAPI void EndScissorMode(void) { rf_end_scissor_mode(); }
#pragma endregion

// Screen-space-related functions
#pragma region Screen-space-related functions
RLAPI Ray GetMouseRay(Vector2 mousePosition, Camera camera, int width, int height) { return rayfork_ray(rf_get_mouse_ray((rf_sizei) { width, height }, rfvec2(mousePosition), rfcam3d(camera))); }
RLAPI Matrix GetCameraMatrix(Camera camera) { return rayfork_matrix(rf_get_camera_matrix(rfcam3d(camera))); }
RLAPI Matrix GetCameraMatrix2D(Camera2D camera) { return rayfork_matrix(rf_get_camera_matrix2d(rfcam2d(camera))); }
RLAPI Vector2 GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height) { return rayfork_vec2(rf_get_world_to_screen((rf_sizei) { width, height }, rfvec3(position), rfcam3d(camera))); }
RLAPI Vector2 GetWorldToScreen2D(Vector2 position, Camera2D camera) { return rayfork_vec2(rf_get_world_to_screen2d(rfvec2(position), rfcam2d(camera))); }
RLAPI Vector2 GetScreenToWorld2D(Vector2 position, Camera2D camera) { return rayfork_vec2(rf_get_screen_to_world2d(rfvec2(position), rfcam2d(camera))); }
#pragma endregion

// Color-related functions
#pragma region Color-related functions
RLAPI int ColorToInt(Color color) { return rf_color_to_int(rfcolor(color)); }
RLAPI Vector4 ColorNormalize(Color color) { return rayfork_vec4(rf_color_normalize(rfcolor(color))); }
RLAPI Color ColorFromNormalized(Vector4 normalized) { return rayfork_color(rf_color_from_normalized(rfvec4(normalized))); }
RLAPI Vector3 ColorToHSV(Color color) { return rayfork_vec3(rf_color_to_hsv(rfcolor(color))); }
RLAPI Color ColorFromHSV(Vector3 hsv) { return rayfork_color(rf_color_from_hsv(rfvec3(hsv))); }
RLAPI Color Fade(Color color, float alpha) { return rayfork_color(rf_fade(rfcolor(color), alpha)); }
RLAPI Color ColorAlpha(Color color, float alpha) { return rayfork_color(rf_fade(rfcolor(color), alpha)); } // Hack :)
#pragma endregion

//------------------------------------------------------------------------------------
// Camera System Functions
//------------------------------------------------------------------------------------
#pragma region Camera System Functions
RLAPI void SetCameraMode(Camera cam, int mode, rf_camera3d_state* state) { rf_set_camera3d_mode(state, rfcam3d(cam), mode); }
RLAPI void UpdateCamera(Camera cam, rf_camera3d_state* state, rf_input_state_for_update_camera input_state) { rf_update_camera3d(&cam, state, input_state); }
#pragma endregion

#pragma endregion

// Shapes
#pragma region Shapes

// Basic shapes drawing functions
#pragma region Basic shapes drawing functions
RLAPI void DrawPixel(int PosX, int PosY, Color color) { rf_draw_pixel(PosX, PosY, rfcolor(color)); }
RLAPI void DrawPixelV(Vector2 position, Color color) { rf_draw_pixel_v(rfvec2(position), rfcolor(color)); }
RLAPI void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color) { rf_draw_line(startPosX, startPosY, endPosX, endPosY, rfcolor(color)); }
RLAPI void DrawLineV(Vector2 startPos, Vector2 endPos, Color color) { rf_draw_line_v(rfvec2(startPos), rfvec2(endPos), rfcolor(color)); }
RLAPI void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color) { rf_draw_line_ex(rfvec2(startPos), rfvec2(endPos), thick, rfcolor(color)); }
RLAPI void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color) { rf_draw_line_bezier(rfvec2(startPos), rfvec2(endPos), thick, rfcolor(color)); }
RLAPI void DrawLineStrip(Vector2* points, int numPoints, Color color) { rf_draw_line_strip(points, numPoints, rfcolor(color)); }
RLAPI void DrawCircle(int centerX, int centerY, float radius, Color color) { rf_draw_circle(centerX, centerY, radius, rfcolor(color)); }
RLAPI void DrawCircleSector(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color) { rf_draw_circle_sector(rfvec2(center), radius, startAngle, endAngle, segments, rfcolor(color)); }
RLAPI void DrawCircleSectorLines(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color) { rf_draw_circle_sector_lines(rfvec2(center), radius, startAngle, endAngle, segments, rfcolor(color)); }
RLAPI void DrawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2) { rf_draw_circle_gradient(centerX, centerY, radius, rfcolor(color1), rfcolor(color2)); }
RLAPI void DrawCircleV(Vector2 center, float radius, Color color) { rf_draw_circle_v(rfvec2(center), radius, rfcolor(color)); }
RLAPI void DrawCircleLines(int centerX, int centerY, float radius, Color color) { rf_draw_circle_lines(centerX, centerY, radius, rfcolor(color)); }
RLAPI void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color)
{
    if (rf_gfx_check_buffer_limit(3 * 36)) rf_gfx_draw();

    rf_gfx_begin(RF_TRIANGLES);
    for (int i = 0; i < 360; i += 10)
    {
        rf_gfx_color4ub(color.r, color.g, color.b, color.a);
        rf_gfx_vertex2f(centerX, centerY);
        rf_gfx_vertex2f(centerX + sinf(RF_DEG2RAD * i) * radiusH, centerY + cosf(RF_DEG2RAD * i) * radiusV);
        rf_gfx_vertex2f(centerX + sinf(RF_DEG2RAD * (i + 10)) * radiusH, centerY + cosf(RF_DEG2RAD * (i + 10)) * radiusV);
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
        rf_gfx_vertex2f(centerX + sinf(RF_DEG2RAD * i) * radiusH, centerY + cosf(RF_DEG2RAD * i) * radiusV);
        rf_gfx_vertex2f(centerX + sinf(RF_DEG2RAD * (i + 10)) * radiusH, centerY + cosf(RF_DEG2RAD * (i + 10)) * radiusV);
    }
    rf_gfx_end();
}
RLAPI void DrawRing(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color) { rf_draw_ring(rfvec2(center), innerRadius, outerRadius, startAngle, endAngle, segments, rfcolor(color)); }
RLAPI void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color) { rf_draw_ring_lines(rfvec2(center), innerRadius, outerRadius, startAngle, endAngle, segments, rfcolor(color)); }
RLAPI void DrawRectangle(int posX, int posY, int width, int height, Color color) { rf_draw_rectangle(posX, posY, width, height, rfcolor(color)); }
RLAPI void DrawRectangleV(Vector2 position, Vector2 size, Color color) { rf_draw_rectangle_v(rfvec2(position), rfvec2(size), rfcolor(color)); }
RLAPI void DrawRectangleRec(Rectangle rec, Color color) { rf_draw_rectangle_rec(rfrec(rec), rfcolor(color)); }
RLAPI void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color) { rf_draw_rectangle_pro(rfrec(rec), rfvec2(origin), rotation, rfcolor(color)); }
RLAPI void DrawRectangleGradientV(int posX, int posY, int width, int height, Color color1, Color color2) { rf_draw_rectangle_gradient_v(posX, posY, width, height, rfcolor(color1), rfcolor(color2)); }
RLAPI void DrawRectangleGradientH(int posX, int posY, int width, int height, Color color1, Color color2) { rf_draw_rectangle_gradient_h(posX, posY, width, height, rfcolor(color1), rfcolor(color2)); }
RLAPI void DrawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4) { rf_draw_rectangle_gradient(rfrec(rec), rfcolor(col1), rfcolor(col2), rfcolor(col3), rfcolor(col4)); }
RLAPI void DrawRectangleLines(int posX, int posY, int width, int height, Color color) { rf_draw_rectangle_outline((rf_rec) { posX, posY, width, height }, 1, rfcolor(color)); }
RLAPI void DrawRectangleLinesEx(Rectangle rec, int lineThick, Color color) { rf_draw_rectangle_outline(rfrec(rec), lineThick, rfcolor(color)); }
RLAPI void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color) { rf_draw_rectangle_rounded(rfrec(rec), roundness, segments, rfcolor(color)); }
RLAPI void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, int lineThick, Color color) { rf_draw_rectangle_rounded_lines(rfrec(rec), roundness, segments, lineThick, rfcolor(color)); }
RLAPI void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color) { rf_draw_triangle(rfvec2(v1), rfvec2(v2), rfvec2(v3), rfcolor(color)); }
RLAPI void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color) { rf_draw_triangle_lines(rfvec2(v1), rfvec2(v2), rfvec2(v3), rfcolor(color)); }
RLAPI void DrawTriangleFan(Vector2* points, int numPoints, Color color) { rf_draw_triangle_fan(points, numPoints, rfcolor(color)); }
RLAPI void DrawTriangleStrip(Vector2* points, int pointsCount, Color color) { rf_draw_triangle_strip(points, pointsCount, rfcolor(color)); }
RLAPI void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color) { rf_draw_poly(rfvec2(center), sides, radius, rotation, rfcolor(color)); }
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
#pragma endregion

// Basic shapes collision detection functions
#pragma region Basic shapes collision detection functions
RLAPI bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2) { return rf_check_collision_recs(rfrec(rec1), rfrec(rec2)); }
RLAPI bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2) { return rf_check_collision_circles(rfvec2(center1), radius1, rfvec2(center2), radius2); }
RLAPI bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec) { return rf_check_collision_circle_rec(rfvec2(center), radius, rfrec(rec)); }
RLAPI Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2) { return rayfork_rectangle(rf_get_collision_rec(rfrec(rec1), rfrec(rec2))); }
RLAPI bool CheckCollisionPointRec(Vector2 point, Rectangle rec) { return rf_check_collision_point_rec(rfvec2(point), rfrec(rec)); }
RLAPI bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius) { return rf_check_collision_point_circle(rfvec2(point), rfvec2(center), radius); }
RLAPI bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3) { return rf_check_collision_point_triangle(rfvec2(point), rfvec2(p1), rfvec2(p2), rfvec2(p3)); }
#pragma endregion

#pragma endregion

// Textures
#pragma region Textures

// Image loading functions
#pragma region Image loading functions
RLAPI Image LoadImage(const char* fileName) { return rayfork_image(rf_load_image_from_file_ez(fileName)); }
RLAPI void UnloadImage(Image image) { rf_unload_image_ez(rfimg(image)); }
#pragma endregion

// Image generation functions
#pragma region Image generation functions
RLAPI Image GenImageColor(int width, int height, Color color) { return rayfork_image(rf_gen_image_color_ez(width, height, rfcolor(color))); }
RLAPI Image GenImageGradientV(int width, int height, Color top, Color bottom) { return rayfork_image(rf_gen_image_gradient_v_ez(width, height, rfcolor(top), rfcolor(bottom))); }
RLAPI Image GenImageGradientH(int width, int height, Color left, Color right) { return rayfork_image(rf_gen_image_gradient_h_ez(width, height, rfcolor(left), rfcolor(right))); }
RLAPI Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer) { return rayfork_image(rf_gen_image_gradient_radial_ez(width, height, density, rfcolor(inner), rfcolor(outer))); }
RLAPI Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2) { return rayfork_image(rf_gen_image_checked_ez(width, height, checksX, checksY, rfcolor(col1), rfcolor(col2))); }
RLAPI Image GenImageWhiteNoise(int width, int height, float factor) { return rayfork_image(rf_gen_image_white_noise_ez(width, height, factor)); }
RLAPI Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale) { return rayfork_image(rf_gen_image_perlin_noise_ez(width, height, offsetX, offsetY, scale)); }
RLAPI Image GenImageCellular(int width, int height, int tileSize) { return rayfork_image(rf_gen_image_cellular_ez(width, height, tileSize)); }
#pragma endregion

// Image manipulation functions
#pragma region Image manipulation functions
RLAPI Image ImageCopy(Image image) { return rayfork_image(rf_image_copy_ez(rfimg(image))); }
RLAPI void ImageFormat(Image image, int newFormat) { rf_image_format_ez(rfimg(image), newFormat); }
RLAPI void ImageAlphaMask(Image image, Image alphaMask, void* dst, int dst_size) { rf_image_alpha_mask_to_buffer(rfimg(image), rfimg(alphaMask), dst, dst_size); }
RLAPI void ImageAlphaClear(Image image, Color color, float threshold) { rf_image_alpha_clear_ez(rfimg(image), rfcolor(color), threshold); }
RLAPI void ImageAlphaCrop(Image image, float threshold) { rf_image_alpha_crop_ez(rfimg(image), threshold); }
RLAPI void ImageAlphaPremultiply(Image image) { rf_image_alpha_premultiply_ez(rfimg(image)); }
RLAPI void ImageCrop(Image image, Rectangle crop) { rf_image_crop_ez(rfimg(image), rfrec(crop)); }
RLAPI void ImageResize(Image image, int newWidth, int newHeight) { rf_image_resize_ez(rfimg(image), newWidth, newHeight); }
RLAPI void ImageResizeNN(Image image, int newWidth, int newHeight) { rf_image_resize_nn_ez(rfimg(image), newWidth, newHeight); }
RLAPI void ImageMipmaps(Image image, int gen_mipmaps_count) { rf_image_gen_mipmaps_ez(rfimg(image), gen_mipmaps_count); }
RLAPI void ImageDither(Image image, int rBpp, int gBpp, int bBpp, int aBpp) { rf_image_dither_ez(rfimg(image), rBpp, gBpp, bBpp, aBpp); }
RLAPI void ImageFlipVertical(Image image) { rf_image_flip_vertical_ez(rfimg(image)); }
RLAPI void ImageFlipHorizontal(Image image) { rf_image_flip_horizontal_ez(rfimg(image)); }
RLAPI void ImageRotateCW(Image image) { rf_image_rotate_cw(rfimg(image)); }
RLAPI void ImageRotateCCW(Image image) { rf_image_rotate_ccw(rfimg(image)); }
RLAPI void ImageColorTint(Image image, Color color) { rf_image_color_tint(rfimg(image), rfcolor(color)); }
RLAPI void ImageColorInvert(Image image) { rf_image_color_invert(rfimg(image)); }
RLAPI void ImageColorGrayscale(Image image) { rf_image_color_grayscale(rfimg(image)); }
RLAPI void ImageColorContrast(Image image, float contrast) { rf_image_color_contrast(rfimg(image), contrast); }
RLAPI void ImageColorBrightness(Image image, int brightness) { rf_image_color_brightness(rfimg(image), brightness); }
RLAPI void ImageColorReplace(Image image, Color color, Color replace) { rf_image_color_replace(rfimg(image), rfcolor(color), rfcolor(replace)); }
RLAPI Color* ImageExtractPalette(Image image, int maxPaletteSize) { return rf_image_extract_palette_ez(rfimg(image), maxPaletteSize).colors; }
RLAPI Rectangle GetImageAlphaBorder(Image image, float threshold) { return rayfork_rectangle(rf_image_alpha_border(rfimg(image), threshold)); }
#pragma endregion

// Image drawing functions
#pragma region Image drawing functions
RLAPI void ImageClearBackground(Image* dst, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { 0, 0, dst->width, dst->height }, rfcolor(color)); }
RLAPI void ImageDrawPixel(Image* dst, int x, int y, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { x, y, 1, 1 }, rfcolor(color)); }
RLAPI void ImageDrawPixelV(Image* dst, Vector2 position, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { (int)position.x, (int)position.y, 1, 1 }, rfcolor(color)); }
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
RLAPI void ImageDrawLineV(Image* dst, Vector2 start, Vector2 end, Color color) { ImageDrawLine(dst, (int)start.x, (int)start.y, (int)end.x, (int)end.y, rayfork_color(rfcolor(color))); }
RLAPI void ImageDrawRectangle(Image* dst, int posX, int posY, int width, int height, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { posX, posY, width, height }, rfcolor(color)); }
RLAPI void ImageDrawRectangleV(Image* dst, Vector2 position, Vector2 size, Color color) { rf_image_draw_rectangle_ez(dst, (rf_rec) { position.x, position.y, size.x, size.y }, rfcolor(color)); }
RLAPI void ImageDrawRectangleRec(Image* dst, Rectangle rec, Color color) { rf_image_draw_rectangle_ez(dst, rfrec(rec), rfcolor(color)); }
RLAPI void ImageDrawRectangleLines(Image* dst, Rectangle rec, int thick, Color color) { rf_image_draw_rectangle_lines_ez(dst, rfrec(rec), thick, rfcolor(color)); }
RLAPI void ImageDraw(Image* dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint) { rf_image_draw_ez(dst, rfimg(src), rfrec(srcRec), rfrec(dstRec), rfcolor(tint)); }
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
#pragma endregion

// Texture loading functions
#pragma region Texture loading functions
RLAPI Texture2D LoadTexture(const char* fileName) { return rayfork_texture(rf_load_texture_from_file_ez(fileName)); }
RLAPI Texture2D LoadTextureFromImage(Image image) { return rayfork_texture(rf_load_texture_from_image(rfimg(image))); }
RLAPI TextureCubemap LoadTextureCubemap(Image image, int layoutType) { return rayfork_texture(rf_load_texture_cubemap_from_image_ez(rfimg(image), layoutType)); }
RLAPI RenderTexture2D LoadRenderTexture(int width, int height) { return rayfork_render_texture2d(rf_load_render_texture(width, height)); }
RLAPI void UnloadTexture(Texture2D texture) { rf_unload_texture(rftex(texture)); }
RLAPI void UnloadRenderTexture(RenderTexture2D target) { rf_unload_render_texture(rfrtex2d(target)); }
RLAPI void UpdateTexture(Texture2D texture, const void* pixels) { rf_update_texture(rftex(texture), pixels, 1); }
RLAPI Image GetScreenData(void) { return rayfork_image(rf_get_screen_data_ez()); }
#pragma endregion

// Texture configuration functions
#pragma region Texture configuration functions
RLAPI void GenTextureMipmaps(Texture2D* texture) { rf_gen_texture_mipmaps(texture); }
RLAPI void SetTextureFilter(Texture2D texture, int filterMode) { rf_set_texture_filter(rftex(texture), filterMode); }
RLAPI void SetTextureWrap(Texture2D texture, int wrapMode) { rf_set_texture_wrap(rftex(texture), wrapMode); }
#pragma endregion

// Texture drawing functions
#pragma region Texture drawing functions
RLAPI void DrawTexture(Texture2D texture, int posX, int posY, Color tint) { rf_draw_texture(rftex(texture), posX, posY, rfcolor(tint)); }
RLAPI void DrawTextureV(Texture2D texture, Vector2 position, Color tint) { rf_draw_texture(rftex(texture), position.x, position.y, rfcolor(tint)); }
RLAPI void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint) { rf_draw_texture_ex(rftex(texture), position.x, position.y, texture.width* scale, texture.height* scale, rotation, rfcolor(tint)); }
RLAPI void DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint) { rf_draw_texture_region(rftex(texture), rfrec(sourceRec), (rf_rec) { position.x, position.y, sourceRec.width, sourceRec.height }, (rf_vec2) { 0, 0 }, 0, rfcolor(tint)); }
RLAPI void DrawTextureQuad(Texture2D texture, Vector2 tiling, Vector2 offset, Rectangle quad, Color tint)
{
    rf_rec source = { offset.x * texture.width, offset.y * texture.height, tiling.x * texture.width, tiling.y * texture.height };
    rf_vec2 origin = { 0.0f, 0.0f };

    rf_draw_texture_region(rftex(texture), source, rfrec(quad), origin, 0.0f, rfcolor(tint));
}
RLAPI void DrawTexturePro(Texture2D texture, Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint) { rf_draw_texture_region(rftex(texture), rfrec(sourceRec), rfrec(destRec), rfvec2(origin), rotation, rfcolor(tint)); }
RLAPI void DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle destRec, Vector2 origin, float rotation, Color tint) { rf_draw_texture_npatch(rftex(texture), rfnpinfo(nPatchInfo), rfrec(destRec), rfvec2(origin), rotation, rfcolor(tint)); }
#pragma endregion

// Image/Texture misc functions
#pragma region Image/Texture misc functions
RLAPI int GetPixelDataSize(int width, int height, int format) { return rf_pixel_buffer_size(width, height, format); }
#pragma endregion

#pragma endregion

// Text
#pragma region Text

// Font loading/unloading functions
#pragma region Font loading/unloading functions
RLAPI Font GetFontDefault(void) { return rayfork_font(rf_get_default_font()); }
RLAPI Font LoadFont(const char* fileName) { return rayfork_font(rf_load_ttf_font_from_file_ez(fileName, RF_DEFAULT_FONT_SIZE, RF_FONT_ANTIALIAS)); }
RLAPI Font LoadFontEx(const char* fileName, int fontSize, int* fontChars, int charsCount) { return rayfork_font(rf_load_ttf_font_from_data_ez(fileName, fontSize, RF_FONT_ANTIALIAS, fontChars, charsCount)); }
RLAPI Font LoadFontFromImage(Image image, Color key, int firstChar) { return rayfork_font(rf_load_image_font_ez(rfimg(image), rfcolor(key))); }
RLAPI void UnloadFont(Font font) { rf_unload_font_ez((rf_font) { font.baseSize, rftex(font.texture), font.chars, font.charsCount }); }
#pragma endregion

// Text drawing functions
#pragma region Text drawing functions
RLAPI void DrawText(const char* text, int posX, int posY, int fontSize, Color color) { rf_draw_text(text, posX, posY, fontSize, rfcolor(color)); }
RLAPI void DrawTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint) { rf_draw_text_ex(rffont(font), text, rfvec2(position), fontSize, spacing, rfcolor(tint)); }
RLAPI void DrawTextRec(Font font, const char* text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint) { rf_draw_text_rec(rffont(font), text, rfrec(rec), fontSize, spacing, wordWrap, rfcolor(tint)); }
#pragma endregion

// Text misc. functions
#pragma region Text misc. functions
RLAPI int MeasureText(const char* text, int fontSize) { return rf_measure_text(rf_get_default_font(), text, fontSize, 0.0f).width; }
RLAPI Vector2 MeasureTextEx(Font font, const char* text, float fontSize, float spacing) { return rayfork_vec2((rf_vec2) { rf_measure_text(rffont(font), text, fontSize, spacing).width, rf_measure_text(rffont(font), text, fontSize, spacing).height }); }
RLAPI int GetGlyphIndex(Font font, int codepoint) { return rf_get_glyph_index(rffont(font), codepoint); }
#pragma endregion

#pragma endregion

// Models
#pragma region Models

// Basic geometric 3D shapes drawing functions
#pragma region Basic geometric third-dimension shapes drawing functions
RLAPI void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color) { rf_draw_line3d(rfvec3(startPos), rfvec3(endPos), rfcolor(color)); }
RLAPI void DrawPoint3D(Vector3 position, Color color)
{
    if (rf_gfx_check_buffer_limit(8)) rf_gfx_draw();

    rf_gfx_push_matrix();
    rf_gfx_translatef(position.x, position.y, position.z);
    rf_gfx_begin(RF_LINES);
    rf_gfx_color4ub(color.r, color.g, color.b, color.a);
    rf_gfx_vertex3f(0.0f, 0.0f, 0.0f);
    rf_gfx_vertex3f(0.0f, 0.0f, 0.1f);
    rf_gfx_end();
    rf_gfx_pop_matrix();
}
RLAPI void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color) { rf_draw_circle3d(rfvec3(center), radius, rfvec3(rotationAxis), rotationAngle, rfcolor(color)); }
RLAPI void DrawCube(Vector3 position, float width, float height, float length, Color color) { rf_draw_cube(rfvec3(position), width, height, length, rfcolor(color)); }
RLAPI void DrawCubeV(Vector3 position, Vector3 size, Color color) { rf_draw_cube(rfvec3(position), size.x, size.y, size.z, rfcolor(color)); }
RLAPI void DrawCubeWires(Vector3 position, float width, float height, float length, Color color) { rf_draw_cube_wires(rfvec3(position), width, height, length, rfcolor(color)); }
RLAPI void DrawCubeWiresV(Vector3 position, Vector3 size, Color color) { rf_draw_cube_wires(rfvec3(position), size.x, size.y, size.z, rfcolor(color)); }
RLAPI void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color) { rf_draw_cube_texture(rftex(texture), rfvec3(position), width, height, length, rfcolor(color)); }
RLAPI void DrawSphere(Vector3 centerPos, float radius, Color color) { rf_draw_sphere(rfvec3(centerPos), radius, rfcolor(color)); }
RLAPI void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color) { rf_draw_sphere_ex(rfvec3(centerPos), radius, rings, slices, rfcolor(color)); }
RLAPI void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color) { rf_draw_sphere_wires(rfvec3(centerPos), radius, rings, slices, rfcolor(color)); }
RLAPI void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) { rf_draw_cylinder(rfvec3(position), radiusTop, radiusBottom, height, slices, rfcolor(color)); }
RLAPI void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) { rf_draw_cylinder_wires(rfvec3(position), radiusTop, radiusBottom, height, slices, rfcolor(color)); }
RLAPI void DrawPlane(Vector3 centerPos, Vector2 size, Color color) { rf_draw_plane(rfvec3(centerPos), rfvec2(size), rfcolor(color)); }
RLAPI void DrawRay(Ray ray, Color color) { rf_draw_ray(rfray(ray), rfcolor(color)); }
RLAPI void DrawGrid(int slices, float spacing) { rf_draw_grid(slices, spacing); }
RLAPI void DrawGizmo(Vector3 position) { rf_draw_gizmo(rfvec3(position)); }
#pragma endregion

// Model loading/unloading functions
#pragma region Model loading/unloading functions
RLAPI Model LoadModel(const char* fileName) { return rayfork_model(rf_load_model_ez(fileName)); }
RLAPI Model LoadModelFromMesh(Mesh mesh) { return rayfork_model(rf_load_model_from_mesh_ez(rfmesh(mesh))); }
RLAPI void UnloadModel(Model model) { rf_unload_model_ez(rfmodel(model)); }
#pragma endregion

// Mesh loading/unloading functions
#pragma region Mesh loading/unloading functions
RLAPI void UnloadMesh(Mesh mesh) { rf_unload_mesh_ez(rfmesh(mesh)); }
#pragma endregion

// Material loading/unloading functions
#pragma region Material loading/unloading functions
RLAPI Material LoadMaterialDefault(void) { return rayfork_material(rf_load_default_material_ez()); }
RLAPI Material* LoadMaterials(const char* fileName) { rf_load_materials_from_mtl_ez(fileName); }
RLAPI void UnloadMaterial(Material material) { rf_unload_material_ez(rfmaterial(material)); }
RLAPI void SetMaterialTexture(Material* material, int mapType, Texture2D texture) { material->maps[mapType].texture = texture; }
RLAPI void SetModelMeshMaterial(Model* model, int meshId, int materialId) {
    if (!(meshId >= model->meshCount) && !(materialId >= model->materialCount)) model->meshMaterial[meshId] = materialId;
}
#pragma endregion
// Model animations loading/unloading functions
#pragma region Model animations loading/unloading functions
RLAPI ModelAnimation* LoadModelAnimations(const char* fileName, int* animsCount) { rf_load_model_animations_from_iqm_ez(fileName, animsCount); }
RLAPI void UpdateModelAnimation(Model model, ModelAnimation anim, int frame) { rf_update_model_animation(rfmodel(model), rfanim(anim), frame); }
RLAPI void UnloadModelAnimation(ModelAnimation anim) { rf_unload_model_animation_ez(rfanim(anim)); }
RLAPI bool IsModelAnimationValid(Model model, ModelAnimation anim) { return rf_is_model_animation_valid(rfmodel(model), rfanim(anim)); }
#pragma endregion

// Mesh generation functions
#pragma region Mesh generation functions
RLAPI Mesh GenMeshPoly(int sides, float radius) { return rayfork_mesh(rf_gen_mesh_poly_ez(sides, radius)); }
RLAPI Mesh GenMeshPlane(float width, float length, int resX, int resZ) { return rayfork_mesh(rf_gen_mesh_plane_ez(width, length, resX, resZ)); }
RLAPI Mesh GenMeshCube(float width, float height, float length) { return rayfork_mesh(rf_gen_mesh_cube_ez(width, height, length)); }
RLAPI Mesh GenMeshSphere(float radius, int rings, int slices) { return rayfork_mesh(rf_gen_mesh_sphere_ez(radius, rings, slices)); }
RLAPI Mesh GenMeshHemiSphere(float radius, int rings, int slices) { return rayfork_mesh(rf_gen_mesh_hemi_sphere_ez(radius, rings, slices)); }
RLAPI Mesh GenMeshCylinder(float radius, float height, int slices) { return rayfork_mesh(rf_gen_mesh_cylinder_ez(radius, height, slices)); }
RLAPI Mesh GenMeshTorus(float radius, float size, int radSeg, int sides) { return rayfork_mesh(rf_gen_mesh_torus_ez(radius, size, radSeg, sides)); }
RLAPI Mesh GenMeshKnot(float radius, float size, int radSeg, int sides) { return rayfork_mesh(rf_gen_mesh_knot_ez(radius, size, radSeg, sides)); }
RLAPI Mesh GenMeshHeightmap(Image heightmap, Vector3 size) { return rayfork_mesh(rf_gen_mesh_heightmap_ez(rfimg(heightmap), rfvec3(size))); }
RLAPI Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize) { return rayfork_mesh(rf_gen_mesh_cubicmap_ez(rfimg(cubicmap), rfvec3(cubeSize))); }
#pragma endregion

// Mesh manipulation functions
#pragma region Mesh manipulation functions
RLAPI BoundingBox MeshBoundingBox(Mesh mesh) {
    return rayfork_box(rf_mesh_bounding_box(rfmesh(mesh)));
}
RLAPI void MeshTangents(Mesh* mesh) { rf_mesh_compute_tangents_ez(mesh); }
RLAPI void MeshBinormals(Mesh* mesh) { rf_mesh_compute_binormals(mesh); }
#pragma endregion

// Model drawing functions
#pragma region Model drawing functions
RLAPI void DrawModel(Model model, Vector3 position, float scale, Color tint) { rf_draw_model(rfmodel(model), rfvec3(position), scale, rfcolor(tint)); }
RLAPI void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) { rf_draw_model_ex(rfmodel(model), rfvec3(position), rfvec3(rotationAxis), rotationAngle, rfvec3(scale), rfcolor(tint)); }
RLAPI void DrawModelWires(Model model, Vector3 position, float scale, Color tint) { rf_draw_model_wires(rfmodel(model), rfvec3(position), (rf_vec3) { 0, 0, 0 }, 0, (rf_vec3) { scale, scale, scale }, rfcolor(tint)); }
RLAPI void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) { rf_draw_model_wires(rfmodel(model), rfvec3(position), rfvec3(rotationAxis), rotationAngle, rfvec3(scale), rfcolor(tint)); }
RLAPI void DrawBoundingBox(BoundingBox box, Color color) { rf_draw_bounding_box(rfbox(box), rfcolor(color)); }
RLAPI void DrawBillboard(Camera camera, Texture2D texture, Vector3 center, float size, Color tint) { rf_draw_billboard(rfcam3d(camera), rftex(texture), rfvec3(center), size, rfcolor(tint)); }
RLAPI void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle sourceRec, Vector3 center, float size, Color tint) { rf_draw_billboard_rec(rfcam3d(camera), rftex(texture), rfrec(sourceRec), rfvec3(center), size, rfcolor(tint)); }
#pragma endregion

// Collision detection functions
#pragma region Collision detection functions
RLAPI bool CheckCollisionSpheres(Vector3 centerA, float radiusA, Vector3 centerB, float radiusB) { return rf_check_collision_spheres(rfvec3(centerA), radiusA, rfvec3(centerB), radiusB); }
RLAPI bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2) { return rf_check_collision_boxes(rfbox(box1), rfbox(box2)); }
RLAPI bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius) { return rf_check_collision_box_sphere(rfbox(box), rfvec3(center), radius); }
RLAPI bool CheckCollisionRaySphere(Ray ray, Vector3 center, float radius) { return rf_check_collision_ray_sphere(rfray(ray), rfvec3(center), radius); }
RLAPI bool CheckCollisionRaySphereEx(Ray ray, Vector3 center, float radius, Vector3* collisionPoint) { return rf_check_collision_ray_sphere_ex(rfray(ray), rfvec3(center), radius, collisionPoint); }
RLAPI bool CheckCollisionRayBox(Ray ray, BoundingBox box) { return rf_check_collision_ray_box(rfray(ray), rfbox(box)); }
RLAPI RayHitInfo GetCollisionRayModel(Ray ray, Model model) { return rayfork_rayhitinfo(rf_collision_ray_model(rfray(ray), rfmodel(model))); }
RLAPI RayHitInfo GetCollisionRayTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3) { return rayfork_rayhitinfo(rf_collision_ray_triangle(rfray(ray), rfvec3(p1), rfvec3(p2), rfvec3(p3))); }
RLAPI RayHitInfo GetCollisionRayGround(Ray ray, float groundHeight) { return rayfork_rayhitinfo(rf_collision_ray_ground(rfray(ray), groundHeight)); }
#pragma endregion

#pragma endregion

// Shaders
#pragma region Shaders

// Shader loading/unloading functions
#pragma region Shader loading/unloading functions
RLAPI Shader LoadShaderCode(char* vsCode, char* fsCode) { return rayfork_shader(rf_gfx_load_shader(vsCode, fsCode)); }
RLAPI void UnloadShader(Shader shader) { rf_gfx_unload_shader(rfshader(shader)); }
RLAPI Shader GetShaderDefault(void) { return rayfork_shader(rf_get_default_shader()); }
RLAPI Texture2D GetTextureDefault(void) { return rayfork_texture(rf_get_default_texture()); }
RLAPI Texture2D GetShapesTexture(void) { return rayfork_texture(rf_get_context()->tex_shapes); }
RLAPI Rectangle GetShapesTextureRec(void) { return rayfork_rectangle(rf_get_context()->rec_tex_shapes); }
RLAPI void SetShapesTexture(Texture2D texture, Rectangle source) { rf_set_shapes_texture(rftex(texture), rfrec(source)); }
#pragma endregion

// Shader configuration functions
#pragma region Shader configuration functions
RLAPI int GetShaderLocation(Shader shader, const char* uniformName) { return rf_gfx_get_shader_location(rfshader(shader), uniformName); }
RLAPI void SetShaderValue(Shader shader, int uniformLoc, const void* value, int uniformType) { rf_gfx_set_shader_value(rfshader(shader), uniformLoc, value, uniformType); }
RLAPI void SetShaderValueV(Shader shader, int uniformLoc, const void* value, int uniformType, int count) { rf_gfx_set_shader_value_v(rfshader(shader), uniformLoc, value, uniformType, count); }
RLAPI void SetShaderValueMatrix(Shader shader, int uniformLoc, Matrix mat) { rf_gfx_set_shader_value_matrix(rfshader(shader), uniformLoc,rfmat(mat)); }
RLAPI void SetShaderValueTexture(Shader shader, int uniformLoc, Texture2D texture) { rf_gfx_set_shader_value_texture(rfshader(shader), uniformLoc, rftex(texture)); }
RLAPI void SetMatrixProjection(Matrix proj) { rf_gfx_set_matrix_projection(rfmat(proj)); }
RLAPI void SetMatrixModelview(Matrix view) { rf_gfx_set_matrix_modelview(rfmat(view)); }
RLAPI Matrix GetMatrixModelview(void) { return rayfork_matrix(rf_gfx_get_matrix_modelview()); }
RLAPI Matrix GetMatrixProjection(void) { return rayfork_matrix(rf_gfx_get_matrix_projection()); }
#pragma endregion

// Texture maps generation (PBR)
#pragma region Texture maps generation (PBR)
RLAPI Texture2D GenTextureCubemap(Shader shader, Texture2D map, int size) { return rayfork_texture(rf_gen_texture_cubemap(rfshader(shader), rftex(map), size)); }
RLAPI Texture2D GenTextureIrradiance(Shader shader, Texture2D cubemap, int size) { return rayfork_texture(rf_gen_texture_irradiance(rfshader(shader), rftex(cubemap), size)); }
RLAPI Texture2D GenTexturePrefilter(Shader shader, Texture2D cubemap, int size) { return rayfork_texture(rf_gen_texture_prefilter(rfshader(shader), rftex(cubemap), size)); }
RLAPI Texture2D GenTextureBRDF(Shader shader, int size) { return rayfork_texture(rf_gen_texture_brdf(rfshader(shader), size)); }
#pragma endregion

// Shading begin/end functions
#pragma region Shading begin/end functions
RLAPI void BeginShaderMode(Shader shader) { rf_begin_shader(rfshader(shader)); }
RLAPI void EndShaderMode(void) { rf_end_shader(); }
RLAPI void BeginBlendMode(int mode) { rf_gfx_blend_mode(mode); }
RLAPI void EndBlendMode(void) { rf_end_blend_mode(); }
#pragma endregion

#pragma endregion
#endif

// rlgl.h
#pragma region RLGL
#ifndef RLGL_H

//------------------------------------------------------------------------------------
// Functions Declaration - Matrix operations
//------------------------------------------------------------------------------------
#pragma region Functions Declaration - Matrix operations
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
#pragma endregion

//------------------------------------------------------------------------------------
// Functions Declaration - Vertex level operations
//------------------------------------------------------------------------------------
#pragma region Functions Declaration - Vertex level operations
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
RLAPI Vector3 rlUnproject(Vector3 source, Matrix projection, Matrix view) { return rayfork_vec3(rf_unproject(rfvec3(source), rfmat(projection), rfmat(view))); }
#pragma endregion

//------------------------------------------------------------------------------------
// Functions Declaration - OpenGL equivalent functions (common to 1.1, 3.3+, ES2)
//------------------------------------------------------------------------------------
#pragma region Functions Declaration - OpenGL equivalent functions (common to 1.1, 3.3+, ES2)
RLAPI void rlEnableTexture(unsigned int id) { rf_gfx_enable_texture(id); }
RLAPI void rlDisableTexture(void) { rf_gfx_disable_texture(); }
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
RLAPI void rlDeleteRenderTextures(RenderTexture2D target) { rf_gfx_delete_render_textures(rfrtex2d(target)); }
RLAPI void rlDeleteShader(unsigned int id) { rf_gfx_delete_shader(id); }
RLAPI void rlDeleteVertexArrays(unsigned int id) { rf_gfx_delete_vertex_arrays(id); }
RLAPI void rlDeleteBuffers(unsigned int id) { rf_gfx_delete_buffers(id); }
RLAPI void rlClearColor(byte r, byte g, byte b, byte a) { rf_gfx_clear_color(r, g, b, a); }
RLAPI void rlClearScreenBuffers(void) { rf_gfx_clear_screen_buffers(); }
RLAPI void rlUpdateBuffer(int bufferId, void* data, int dataSize) { rf_gfx_update_buffer(bufferId, data, dataSize); }
RLAPI unsigned int rlLoadAttribBuffer(unsigned int vaoId, int shaderLoc, void* buffer, int size, bool dynamic) { return rf_gfx_load_attrib_buffer(vaoId, shaderLoc, buffer, size, dynamic); }
#pragma endregion

//------------------------------------------------------------------------------------
// Functions Declaration - rlgl functionality
//------------------------------------------------------------------------------------
#pragma region Functions Declaration - rlgl functionality
RLAPI void rlglClose(void) { rf_gfx_close(); }
RLAPI void rlglDraw(void) { rf_gfx_draw(); }

RLAPI bool rlCheckBufferLimit(int vCount) { return rf_gfx_check_buffer_limit(vCount); }
RLAPI void rlSetDebugMarker(const char* text) { rf_gfx_set_debug_marker(text); }

// Textures data management
#pragma region Textures data management
RLAPI unsigned int rlLoadTexture(void* data, int width, int height, int format, int mipmapCount) { return rf_gfx_load_texture(data, width, height, format, mipmapCount); }
RLAPI unsigned int rlLoadTextureDepth(int width, int height, int bits, bool useRenderBuffer) { return rf_gfx_load_texture_depth(width, height, bits, useRenderBuffer); }
RLAPI unsigned int rlLoadTextureCubemap(void* data, int size, int format) { return rf_gfx_load_texture_cubemap(data, size, format); }
RLAPI void rlUpdateTexture(unsigned int id, int offsetX, int offsetY, int width, int height, int format, const void* data) { rf_gfx_update_texture(id, offsetX, offsetY, width, height, format, data); }
RLAPI void rlUnloadTexture(unsigned int id) { rf_gfx_unload_texture(id); }

RLAPI void rlGenerateMipmaps(Texture2D* texture) { rf_gfx_generate_mipmaps(texture); }
RLAPI Image rlReadTexturePixels(Texture2D texture) { return rayfork_image(rf_gfx_read_texture_pixels_ez(rftex(texture))); }
RLAPI void rlReadScreenPixels(int width, int height, Color* dstColor) { rf_gfx_read_screen_pixels(dstColor, width, height); }
#pragma endregion

// Render texture management (fbo)
#pragma region Render texture management (fbo)
RLAPI RenderTexture2D rlLoadRenderTexture(int width, int height, int format, int depthBits, bool useDepthTexture) { return rayfork_render_texture2d(rf_gfx_load_render_texture(width, height, format, depthBits, useDepthTexture)); }
RLAPI void rlRenderTextureAttach(RenderTexture target, unsigned int id, int attachType) { rf_gfx_render_texture_attach(rfrtex2d(target), id, attachType); }
RLAPI bool rlRenderTextureComplete(RenderTexture target) { return rf_gfx_render_texture_complete(rfrtex2d(target)); }
#pragma endregion

// Vertex data management
#pragma Vertex data management
RLAPI void rlLoadMesh(Mesh* mesh, bool dynamic) { rf_gfx_load_mesh(mesh, dynamic); }
RLAPI void rlUpdateMesh(Mesh mesh, int buffer, int count) { rf_gfx_update_mesh(rfmesh(mesh), buffer, count); }
RLAPI void rlUpdateMeshAt(Mesh mesh, int buffer, int count, int index) { rf_gfx_update_mesh_at(rfmesh(mesh), buffer, count, index); }
RLAPI void rlDrawMesh(Mesh mesh, Material material, Matrix transform) { rf_gfx_draw_mesh(rfmesh(mesh), rfmaterial(material), rfmat(transform)); }
RLAPI void rlUnloadMesh(Mesh mesh) { rf_gfx_unload_mesh(rfmesh(mesh)); }
#pragma endregion

#endif
#pragma endregion

// raymath.h
#pragma region raymath
#ifndef RAYMATH_H
//----------------------------------------------------------------------------------
// Module Functions Definition - Utils math
//----------------------------------------------------------------------------------
#pragma region Module Functions Definition - Utils math
float Clamp(float value, float min, float max) { return rf_clamp(value, min, max); }
float Lerp(float start, float end, float amount) { return rf_lerp(start, end, amount); }
#pragma endregion

//----------------------------------------------------------------------------------
// Module Functions Definition - Vector2 math
//----------------------------------------------------------------------------------
#pragma region Module Functions Definition - Vector2 math
Vector2 Vector2Zero(void) { return (Vector2) { 0, 0 }; }
Vector2 Vector2One(void) { return (Vector2) { 1, 1 }; }
Vector2 Vector2Add(Vector2 v1, Vector2 v2) { return rayfork_vec2(rf_vec2_add(rfvec2(v1), rfvec2(v2))); }
Vector2 Vector2AddValue(Vector2 v, float add) { return (Vector2) { v.x + add, v.y + add }; }
Vector2 Vector2Subtract(Vector2 v1, Vector2 v2) { return rayfork_vec2(rf_vec2_sub(rfvec2(v1), rfvec2(v2))); }
Vector2 Vector2SubtractValue(Vector2 v, float sub) { return (Vector2) { v.x - sub, v.y - sub }; }
float Vector2Length(Vector2 v) { return rf_vec2_len(rfvec2(v)); }
float Vector2LengthSqr(Vector2 v) { return sqrtf(rf_vec2_len(rfvec2(v))); }
float Vector2DotProduct(Vector2 v1, Vector2 v2) { return rf_vec2_dot_product(rfvec2(v1), rfvec2(v2)); }
float Vector2Distance(Vector2 v1, Vector2 v2) { return rf_vec2_distance(rfvec2(v1), rfvec2(v2)); }
float Vector2Angle(Vector2 v1, Vector2 v2) { return rf_vec2_angle(rfvec2(v1), rfvec2(v2)); }
Vector2 Vector2Scale(Vector2 v, float scale) { return rayfork_vec2(rf_vec2_scale(rfvec2(v), scale)); }
Vector2 Vector2Multiply(Vector2 v1, Vector2 v2) { return rayfork_vec2(rf_vec2_mul_v(rfvec2(v1), rfvec2(v2))); }
Vector2 Vector2Negate(Vector2 v) { return rayfork_vec2(rf_vec2_negate(rfvec2(v))); }
Vector2 Vector2Divide(Vector2 v1, Vector2 v2) { return rayfork_vec2(rf_vec2_div_v(rfvec2(v1), rfvec2(v2))); }
Vector2 Vector2Normalize(Vector2 v) { return rayfork_vec2(rf_vec2_normalize(rfvec2(v))); }
Vector2 Vector2Lerp(Vector2 v1, Vector2 v2, float amount) { return rayfork_vec2(rf_vec2_lerp(rfvec2(v1), rfvec2(v2), amount)); }
Vector2 Vector2Rotate(Vector2 v, float degs) {
    float rads = degs * DEG2RAD;
    Vector2 result = { v.x * cosf(rads) - v.y * sinf(rads) , v.x * sinf(rads) + v.y * cosf(rads) };
    return result;
}
Vector2 Vector2MoveTowards(Vector2 v, Vector2 target, float maxDistance) {
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
#pragma endregion

//----------------------------------------------------------------------------------
// Module Functions Definition - Vector3 math
//----------------------------------------------------------------------------------
#pragma region Module Functions Definition - Vector3 math
Vector3 Vector3Zero(void) { return (Vector3) { 0, 0, 0 }; }
Vector3 Vector3One(void) { return (Vector3) { 1, 1, 1 }; }
Vector3 Vector3Add(Vector3 v1, Vector3 v2) { return rayfork_vec3(rf_vec3_add(rfvec3(v1), rfvec3(v2))); }
Vector3 Vector3AddValue(Vector3 v, float add) { return (Vector3) { v.x + add, v.y + add, v.z + add }; }
Vector3 Vector3Subtract(Vector3 v1, Vector3 v2) { return rayfork_vec3(rf_vec3_sub(rfvec3(v1), rfvec3(v2))); }
Vector3 Vector3SubtractValue(Vector3 v, float sub) { return (Vector3) { v.x - sub, v.y - sub, v.z - sub }; }
Vector3 Vector3Scale(Vector3 v, float scalar) { return rayfork_vec3(rf_vec3_scale(rfvec3(v), scalar)); }
Vector3 Vector3Multiply(Vector3 v1, Vector3 v2) { return rayfork_vec3(rf_vec3_mul_v(rfvec3(v1), rfvec3(v2))); }
Vector3 Vector3CrossProduct(Vector3 v1, Vector3 v2) { return rayfork_vec3(rf_vec3_cross_product(rfvec3(v1), rfvec3(v2))); }
Vector3 Vector3Perpendicular(Vector3 v) { return rayfork_vec3(rf_vec3_perpendicular(rfvec3(v))); }
float Vector3Length(const Vector3 v) { return rf_vec3_len(rfvec3(v)); }
float Vector3LengthSqr(const Vector3 v) { return sqrtf(rf_vec3_len(rfvec3(v))); }
float Vector3DotProduct(Vector3 v1, Vector3 v2) { return rf_vec3_dot_product(rfvec3(v1), rfvec3(v2)); }
float Vector3Distance(Vector3 v1, Vector3 v2) { return rf_vec3_distance(rfvec3(v1), rfvec3(v2)); }
Vector3 Vector3Negate(Vector3 v) { return rayfork_vec3(rf_vec3_negate(rfvec3(v))); }
Vector3 Vector3Divide(Vector3 v1, Vector3 v2) { return rayfork_vec3(rf_vec3_div_v(rfvec3(v1), rfvec3(v2))); }
Vector3 Vector3Normalize(Vector3 v) { return rayfork_vec3(rf_vec3_normalize(rfvec3(v))); }
void Vector3OrthoNormalize(Vector3* v1, Vector3* v2)
{
    *v1 = Vector3Normalize(*v1);
    Vector3 vn = Vector3CrossProduct(*v1, *v2);
    vn = Vector3Normalize(vn);
    *v2 = Vector3CrossProduct(vn, *v1);
}

Vector3 Vector3Transform(Vector3 v, Matrix mat) { return rayfork_vec3(rf_vec3_transform(rfvec3(v), rfmat(mat))); }
Vector3 Vector3RotateByQuaternion(Vector3 v, Quaternion q) { return rayfork_vec3(rf_vec3_rotate_by_quaternion(rfvec3(v), rfquat(q))); }
Vector3 Vector3Lerp(Vector3 v1, Vector3 v2, float amount) { return rayfork_vec3(rf_vec3_lerp(rfvec3(v1), rfvec3(v2), amount)); }
Vector3 Vector3Reflect(Vector3 v, Vector3 normal) { return rayfork_vec3(rf_vec3_reflect(rfvec3(v), rfvec3(normal))); }
Vector3 Vector3Min(Vector3 v1, Vector3 v2) { return rayfork_vec3(rf_vec3_min(rfvec3(v1), rfvec3(v2))); }
Vector3 Vector3Max(Vector3 v1, Vector3 v2) { return rayfork_vec3(rf_vec3_max(rfvec3(v1), rfvec3(v2))); }
Vector3 Vector3Barycenter(Vector3 p, Vector3 a, Vector3 b, Vector3 c) { return rayfork_vec3(rf_vec3_barycenter(rfvec3(p), rfvec3(a), rfvec3(b), rfvec3(c))); }
float3 Vector3ToFloatV(Vector3 v) {
    float3 buffer = { 0 };

    buffer.v[0] = v.x;
    buffer.v[1] = v.y;
    buffer.v[2] = v.z;

    return buffer;
}
float* Vector3ToFloat(Vector3 vec) { return Vector3ToFloatV(vec).v; };
Vector3 Vector3Unproject(Vector3 source, Matrix projection, Matrix view) { return rayfork_vec3(rf_unproject(rfvec3(source), rfmat(projection), rfmat(view))); }
#pragma endregion

//----------------------------------------------------------------------------------
// Module Functions Definition - Matrix math
//----------------------------------------------------------------------------------
#pragma region Module Functions Definition - Matrix math
float MatrixDeterminant(Matrix mat) { return rf_mat_determinant(rfmat(mat)); }
float MatrixTrace(Matrix mat) { return rf_mat_trace(rfmat(mat)); }
Matrix MatrixTranspose(Matrix mat) { return rayfork_matrix(rf_mat_transpose(rfmat(mat))); }
Matrix MatrixInvert(Matrix mat) { return rayfork_matrix(rf_mat_invert(rfmat(mat))); }
Matrix MatrixNormalize(Matrix mat) { return rayfork_matrix(rf_mat_normalize(rfmat(mat))); }
Matrix MatrixIdentity(void) { return rayfork_matrix(rf_mat_identity()); }
Matrix MatrixAdd(Matrix left, Matrix right) { return rayfork_matrix(rf_mat_add(rfmat(left), rfmat(right))); }
Matrix MatrixSubtract(Matrix left, Matrix right) { return rayfork_matrix(rf_mat_sub(rfmat(left), rfmat(right))); }
Matrix MatrixTranslate(float x, float y, float z) { return rayfork_matrix(rf_mat_translate(x, y, z)); }
Matrix MatrixRotate(Vector3 axis, float angle) { return rayfork_matrix(rf_mat_rotate(rfvec3(axis), angle)); }
Matrix MatrixRotateXYZ(Vector3 ang) { return rayfork_matrix(rf_mat_rotate_xyz(rfvec3(ang))); }
Matrix MatrixRotateX(float angle) { return rayfork_matrix(rf_mat_rotate_x(angle)); }
Matrix MatrixRotateY(float angle) { return rayfork_matrix(rf_mat_rotate_y(angle)); }
Matrix MatrixRotateZ(float angle) { return rayfork_matrix(rf_mat_rotate_z(angle)); }
Matrix MatrixScale(float x, float y, float z) { return rayfork_matrix(rf_mat_scale(x, y, z)); }
Matrix MatrixMultiply(Matrix left, Matrix right) { return rayfork_matrix(rf_mat_mul(rfmat(left), rfmat(right))); }
Matrix MatrixFrustum(double left, double right, double bottom, double top, double near, double far) { return rayfork_matrix(rf_mat_frustum(left, right, bottom, top, near, far)); }
Matrix MatrixPerspective(double fovy, double aspect, double near, double far) { return rayfork_matrix(rf_mat_perspective(fovy, aspect, near, far)); }
Matrix MatrixOrtho(double left, double right, double bottom, double top, double near, double far) { return rayfork_matrix(rf_mat_ortho(left, right, bottom, top, near, far)); }
Matrix MatrixLookAt(Vector3 eye, Vector3 target, Vector3 up) { return rayfork_matrix(rf_mat_look_at(rfvec3(eye), rfvec3(target), rfvec3(up))); }
float16 MatrixToFloatV(Matrix mat) {
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
float* MatrixToFloat(Matrix mat) { return MatrixToFloatV(mat).v; }
#pragma endregion

//----------------------------------------------------------------------------------
// Module Functions Definition - Quaternion math
//----------------------------------------------------------------------------------
#pragma region Module Functions Definition - Quaternion math
Quaternion QuaternionAdd(Quaternion q1, Quaternion q2) {
    Quaternion result = { q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w };
    return result;
}
Quaternion QuaternionAddValue(Quaternion q, float add) {
    Quaternion result = { q.x + add, q.y + add, q.z + add, q.w + add };
    return result;
}
Quaternion QuaternionSubtract(Quaternion q1, Quaternion q2) {
    Quaternion result = { q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w };
    return result;
}
Quaternion QuaternionSubtractValue(Quaternion q, float sub) {
    Quaternion result = { q.x - sub, q.y - sub, q.z - sub, q.w - sub };
    return result;
}
Quaternion QuaternionIdentity(void) { return rayfork_quat(rf_quaternion_identity()); }
float QuaternionLength(Quaternion q) { return rf_quaternion_len(rfquat(q)); }
Quaternion QuaternionNormalize(Quaternion q) { return rayfork_quat(rf_quaternion_normalize(rfquat(q))); }
Quaternion QuaternionInvert(Quaternion q) { return rayfork_quat(rf_quaternion_invert(rfquat(q))); }
Quaternion QuaternionMultiply(Quaternion q1, Quaternion q2) { return rayfork_quat(rf_quaternion_mul(rfquat(q1), rfquat(q2))); }
Quaternion QuaternionScale(Quaternion q, float mul) {
    Quaternion result = { 0 };

    float qax = q.x, qay = q.y, qaz = q.z, qaw = q.w;

    result.x = qax * mul + qaw * mul + qay * mul - qaz * mul;
    result.y = qay * mul + qaw * mul + qaz * mul - qax * mul;
    result.z = qaz * mul + qaw * mul + qax * mul - qay * mul;
    result.w = qaw * mul - qax * mul - qay * mul - qaz * mul;

    return result;
}
Quaternion QuaternionDivide(Quaternion q1, Quaternion q2) {
    Quaternion result = { q1.x / q2.x, q1.y / q2.y, q1.z / q2.z, q1.w / q2.w };
    return result;
}
Quaternion QuaternionLerp(Quaternion q1, Quaternion q2, float amount) { return rayfork_quat(rf_quaternion_lerp(rfquat(q1), rfquat(q2), amount)); }
Quaternion QuaternionNlerp(Quaternion q1, Quaternion q2, float amount) { return rayfork_quat(rf_quaternion_nlerp(rfquat(q1), rfquat(q2), amount)); }
Quaternion QuaternionSlerp(Quaternion q1, Quaternion q2, float amount) { return rayfork_quat(rf_quaternion_slerp(rfquat(q1), rfquat(q2), amount)); }
Quaternion QuaternionFromVector3ToVector3(Vector3 from, Vector3 to) {
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
Quaternion QuaternionFromMatrix(Matrix mat) {
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
Matrix QuaternionToMatrix(Quaternion q) {
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
Quaternion QuaternionFromAxisAngle(Vector3 axis, float angle) { return rayfork_quat(rf_quaternion_from_axis_angle(rfvec3(axis), angle)); }
void QuaternionToAxisAngle(Quaternion q, Vector3* outAxis, float* outAngle) { rf_quaternion_to_axis_angle(rfquat(q), outAxis, outAngle); }
Quaternion QuaternionFromEuler(float roll, float pitch, float yaw) { return rayfork_quat(rf_quaternion_from_euler(roll, pitch, yaw)); }
Vector3 QuaternionToEuler(Quaternion q) { return rayfork_vec3(rf_quaternion_to_euler(rfquat(q))); }
Quaternion QuaternionTransform(Quaternion q, Matrix mat) { return rayfork_quat(rf_quaternion_transform(rfquat(q), rfmat(mat))); }
#pragma endregion

#pragma endregion
#endif

#endif
#endif
#pragma endregion