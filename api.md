# rayport wrapped functions

Here is list of functions wrapped by rayport from raylib and supported via rayfork!

I recommend you having some experience in C before reading this...

```c
// module: core
// Drawing-related functions
RLAPI void ClearBackground(Color color);                          // Set background color (framebuffer clear color)
RLAPI void BeginDrawing(void);                                    // Setup canvas (framebuffer) to start drawing
RLAPI void EndDrawing(void);                                      // End canvas drawing and swap buffers (double buffering)
RLAPI void BeginMode2D(Camera2D camera);                          // Initialize 2D mode with custom camera (2D)
RLAPI void EndMode2D(void);                                       // Ends 2D mode with custom camera
RLAPI void BeginMode3D(Camera3D camera);                          // Initializes 3D mode with custom camera (3D)
RLAPI void EndMode3D(void);                                       // Ends 3D mode and returns to default 2D orthographic mode
RLAPI void BeginTextureMode(RenderTexture2D target);              // Initializes render texture for drawing
RLAPI void EndTextureMode(void);                                  // Ends drawing to render texture
RLAPI void BeginScissorMode(int x, int y, int width, int height); // Begin scissor mode (define screen area for following drawing)
RLAPI void EndScissorMode(void);                                  // End scissor mode

// Screen-space-related functions
RLAPI Ray GetMouseRay(Vector2 mousePosition, Camera camera);
RLAPI Matrix GetCameraMatrix(Camera camera);                      // Returns camera transform matrix (view matrix)
RLAPI Matrix GetCameraMatrix2D(Camera2D camera);                  // Returns camera 2d transform matrix
RLAPI Vector2 GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height); // Returns size position for a 3d world space position
RLAPI Vector2 GetWorldToScreen2D(Vector2 position, Camera2D camera); // Returns the screen space position for a 2d camera world space position
RLAPI Vector2 GetScreenToWorld2D(Vector2 position, Camera2D camera); // Returns the world space position for a 2d camera screen space position

// Color-related functions
RLAPI int ColorToInt(Color color);                                // Returns hexadecimal value for a Color
RLAPI Vector4 ColorNormalize(Color color);                        // Returns color normalized as float [0..1]
RLAPI Color ColorFromNormalized(Vector4 normalized);              // Returns color from normalized values [0..1]
RLAPI Vector3 ColorToHSV(Color color);                            // Returns HSV values for a Color
RLAPI Color ColorFromHSV(Vector3 hsv);                            // Returns a Color from HSV values
RLAPI Color GetColor(int hexValue);                               // Returns a Color struct from hexadecimal value
RLAPI Color Fade(Color color, float alpha);                       // Color fade-in or fade-out, alpha goes from 0.0f to 1.0f
RLAPI void SetCameraMode(Camera cam, int mode, rf_camera3d_state* state);                // Set camera mode (multiple camera modes available)
RLAPI void UpdateCamera(Camera cam, rf_camera3d_state* state, rf_input_state_for_update_camera input_state);                          // Update camera position for selected mode

// Misc. functions
RLAPI void SetTraceLogLevel(int logType);                         // Set the current threshold (minimum) log level
RLAPI void SetTraceLogCallback(TraceLogCallback callback);        // Set a trace log callback to enable custom logging
RLAPI void TraceLog(int logType, const char *text, ...);          // Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LO
RLAPI int GetRandomValue(int min, int max);                       // Returns a random value between min and max (both included)

// Files management functions
RLAPI unsigned char *LoadFileData(const char *fileName, unsigned int *bytesRead);     // Load file data as byte array (read)
RLAPI void SaveFileData(const char *fileName, void *data, unsigned int bytesToWrite); // Save data to file from byte array (write)
RLAPI char *LoadFileText(const char *fileName);                   // Load text data from file (read), returns a '\0' terminated string
RLAPI void SaveFileText(const char *fileName, char *text);        // Save text data to file (write), string must be '\0' terminated
RLAPI bool FileExists(const char *fileName);                      // Check if file exists
RLAPI bool IsFileExtension(const char *fileName, const char *ext);// Check file extension
RLAPI const char *GetExtension(const char *fileName);             // Get pointer to extension for a filename string
RLAPI const char *GetFileName(const char *filePath);              // Get pointer to filename for a path string
RLAPI const char *GetFileNameWithoutExt(const char *filePath);    // Get filename string without extension (uses static string)
RLAPI const char *GetDirectoryPath(const char *filePath);         // Get full path for a given fileName with path (uses static string)
RLAPI const char *GetPrevDirectoryPath(const char *dirPath);      // Get previous directory path for a given path (uses static string)

// module: shapes
// Basic shapes drawing functions
RLAPI void DrawPixel(int posX, int posY, Color color);                                                   // Draw a pixel
RLAPI void DrawPixelV(Vector2 position, Color color);                                                    // Draw a pixel (Vector version)
RLAPI void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);                // Draw a line
RLAPI void DrawLineV(Vector2 startPos, Vector2 endPos, Color color);                                     // Draw a line (Vector version)
RLAPI void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);                       // Draw a line defining thickness
RLAPI void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);                   // Draw a line using cubic-bezier curves in-out
RLAPI void DrawLineStrip(Vector2 *points, int numPoints, Color color);                                   // Draw lines sequence
RLAPI void DrawCircle(int centerX, int centerY, float radius, Color color);                              // Draw a color-filled circle
RLAPI void DrawCircleSector(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color);     // Draw a piece of a circle
RLAPI void DrawCircleSectorLines(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color);    // Draw circle sector outline
RLAPI void DrawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2);       // Draw a gradient-filled circle
RLAPI void DrawCircleV(Vector2 center, float radius, Color color);                                       // Draw a color-filled circle (Vector version)
RLAPI void DrawCircleLines(int centerX, int centerY, float radius, Color color);                         // Draw circle outline
RLAPI void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color);              // Draw ellipse
RLAPI void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color);         // Draw ellipse outline
RLAPI void DrawRing(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color); // Draw ring
RLAPI void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color);    // Draw ring outline
RLAPI void DrawRectangle(int posX, int posY, int width, int height, Color color);                        // Draw a color-filled rectangle
RLAPI void DrawRectangleV(Vector2 position, Vector2 size, Color color);                                  // Draw a color-filled rectangle (Vector version)
RLAPI void DrawRectangleRec(Rectangle rec, Color color);                                                 // Draw a color-filled rectangle
RLAPI void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);                 // Draw a color-filled rectangle with pro parameters
RLAPI void DrawRectangleGradientV(int posX, int posY, int width, int height, Color color1, Color color2);// Draw a vertical-gradient-filled rectangle
RLAPI void DrawRectangleGradientH(int posX, int posY, int width, int height, Color color1, Color color2);// Draw a horizontal-gradient-filled rectangle
RLAPI void DrawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4);       // Draw a gradient-filled rectangle with custom vertex colors
RLAPI void DrawRectangleLines(int posX, int posY, int width, int height, Color color);                   // Draw rectangle outline
RLAPI void DrawRectangleLinesEx(Rectangle rec, int lineThick, Color color);                              // Draw rectangle outline with extended parameters
RLAPI void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);              // Draw rectangle with rounded edges
RLAPI void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, int lineThick, Color color); // Draw rectangle with rounded edges outline
RLAPI void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);                                // Draw a color-filled triangle (vertex in counter-clockwise order!)
RLAPI void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color);                           // Draw triangle outline (vertex in counter-clockwise order!)
RLAPI void DrawTriangleFan(Vector2 *points, int numPoints, Color color);                                 // Draw a triangle fan defined by points (first vertex is the center)
RLAPI void DrawTriangleStrip(Vector2 *points, int pointsCount, Color color);                             // Draw a triangle strip defined by points
RLAPI void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color);               // Draw a regular polygon (Vector version)
RLAPI void DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color);          // Draw a polygon outline of n sides

// Basic shapes collision detection functions
RLAPI bool CheckCollisionLineLine(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2);   // Check collision between two lines
RLAPI bool CheckCollisionLineRec(Vector2 startPos, Vector2 endPos, Rectangle rec);                           // Check collision between line and rectangle
RLAPI bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);                                               // Check collision between two rectangles
RLAPI bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);            // Check collision between two circles
RLAPI bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);                             // Check collision between circle and rectangle
RLAPI bool CheckCollisionCircleLine(Vector2 center, float radius, Vector2 startPos, Vector2 endPos);         // Check collision between circle and line
RLAPI Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2);                                             // Get collision rectangle for two rectangles collision
RLAPI bool CheckCollisionPointRec(Vector2 point, Rectangle rec);                                             // Check if point is inside rectangle
RLAPI bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius);                           // Check if point is inside circle
RLAPI bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);                   // Check if point is inside a triangle

// module: textures
// Image loading functions
// NOTE: This functions do not require GPU access
RLAPI Image LoadImage(const char *fileName);                                                             // Load image from file into CPU memory (RAM)
RLAPI void UnloadImage(Image image);                                                                     // Unload image from CPU memory (RAM)

// Image generation functions
RLAPI Image GenImageColor(int width, int height, Color color);                                           // Generate image: plain color
RLAPI Image GenImageGradientV(int width, int height, Color top, Color bottom);                           // Generate image: vertical gradient
RLAPI Image GenImageGradientH(int width, int height, Color left, Color right);                           // Generate image: horizontal gradient
RLAPI Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);      // Generate image: radial gradient
RLAPI Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);    // Generate image: checked
RLAPI Image GenImageWhiteNoise(int width, int height, float factor);                                     // Generate image: white noise
RLAPI Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);           // Generate image: perlin noise
RLAPI Image GenImageCellular(int width, int height, int tileSize);                                       // Generate image: cellular algorithm. Bigger tileSize means bigger cells
RLAPI Image GenImageColor(int width, int height, Color color);                                           // Generate image: plain color
RLAPI Image GenImageGradientV(int width, int height, Color top, Color bottom);                           // Generate image: vertical gradient
RLAPI Image GenImageGradientH(int width, int height, Color left, Color right);                           // Generate image: horizontal gradient
RLAPI Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);      // Generate image: radial gradient
RLAPI Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);    // Generate image: checked
RLAPI Image GenImageWhiteNoise(int width, int height, float factor);                                     // Generate image: white noise
RLAPI Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);           // Generate image: perlin noise
RLAPI Image GenImageCellular(int width, int height, int tileSize);                                       // Generate image: cellular algorithm. Bigger tileSize means bigger cells

// Image manipulation functions
RLAPI Image ImageCopy(Image image);                                                                      // Create an image duplicate (useful for transformations)
RLAPI void ImageFormat(Image *image, int newFormat);                                                     // Convert image data to desired format
RLAPI void ImageAlphaMask(Image *image, Image alphaMask);                                                // Apply alpha mask to image
RLAPI void ImageAlphaClear(Image *image, Color color, float threshold);                                  // Clear alpha channel to desired color
RLAPI void ImageAlphaCrop(Image *image, float threshold);                                                // Crop image depending on alpha value
RLAPI void ImageAlphaPremultiply(Image *image);                                                          // Premultiply alpha channel
RLAPI void ImageCrop(Image *image, Rectangle crop);                                                      // Crop an image to a defined rectangle
RLAPI void ImageResize(Image *image, int newWidth, int newHeight);                                       // Resize image (Bicubic scaling algorithm)
RLAPI void ImageResizeNN(Image *image, int newWidth,int newHeight);                                      // Resize image (Nearest-Neighbor scaling algorithm)
RLAPI void ImageMipmaps(Image *image);                                                                   // Generate all mipmap levels for a provided image
RLAPI void ImageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp);                            // Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
RLAPI void ImageFlipVertical(Image *image);                                                              // Flip image vertically
RLAPI void ImageFlipHorizontal(Image *image);                                                            // Flip image horizontally
RLAPI void ImageRotateCW(Image *image);                                                                  // Rotate image clockwise 90deg
RLAPI void ImageRotateCCW(Image *image);                                                                 // Rotate image counter-clockwise 90deg
RLAPI void ImageColorTint(Image *image, Color color);                                                    // Modify image color: tint
RLAPI void ImageColorInvert(Image *image);                                                               // Modify image color: invert
RLAPI void ImageColorGrayscale(Image *image);                                                            // Modify image color: grayscale
RLAPI void ImageColorContrast(Image *image, float contrast);                                             // Modify image color: contrast (-100 to 100)
RLAPI void ImageColorBrightness(Image *image, int brightness);                                           // Modify image color: brightness (-255 to 255)
RLAPI void ImageColorReplace(Image *image, Color color, Color replace);                                  // Modify image color: replace color
RLAPI Color *ImageExtractPalette(Image image, int maxPaletteSize, int *extractCount);                    // Extract color palette from image to maximum size (memory should be freed)
RLAPI Rectangle GetImageAlphaBorder(Image image, float threshold);                                       // Get image alpha border rectangle

// Image drawing functions
// NOTE: Image software-rendering functions (CPU)
RLAPI void ImageClearBackground(Image *dst, Color color);                                                // Clear image background with given color
RLAPI void ImageDrawRectangle(Image *dst, int posX, int posY, int width, int height, Color color);       // Draw rectangle within an image
RLAPI void ImageDrawRectangleV(Image *dst, Vector2 position, Vector2 size, Color color);                 // Draw rectangle within an image (Vector version)
RLAPI void ImageDrawRectangleRec(Image *dst, Rectangle rec, Color color);                                // Draw rectangle within an image 
RLAPI void ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint);             // Draw a source image within a destination image (tint applied to source)
RLAPI void ImageDrawPixel(Image *dst, int posX, int posY, Color color);                                  // Draw pixel within an image
RLAPI void ImageDrawPixelV(Image *dst, Vector2 position, Color color);                                   // Draw pixel within an image (Vector version)
RLAPI void ImageDrawLine(Image *dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color); // Draw line within an image
RLAPI void ImageDrawLineV(Image *dst, Vector2 start, Vector2 end, Color color);                          // Draw line within an image (Vector version)
RLAPI void ImageDrawCircle(Image *dst, int centerX, int centerY, int radius, Color color);               // Draw circle within an image
RLAPI void ImageDrawCircleV(Image *dst, Vector2 center, int radius, Color color);                        // Draw circle within an image (Vector version)

// Texture loading functions
// NOTE: These functions require GPU access
RLAPI Texture2D LoadTexture(const char *fileName);                                                       // Load texture from file into GPU memory (VRAM)
RLAPI Texture2D LoadTextureFromImage(Image image);                                                       // Load texture from image data
RLAPI TextureCubemap LoadTextureCubemap(Image image, int layoutType);                                    // Load cubemap from image, multiple image cubemap layouts supported
RLAPI RenderTexture2D LoadRenderTexture(int width, int height);                                          // Load texture for rendering (framebuffer)
RLAPI void UnloadTexture(Texture2D texture);                                                             // Unload texture from GPU memory (VRAM)
RLAPI void UnloadRenderTexture(RenderTexture2D target);                                                  // Unload render texture from GPU memory (VRAM)
RLAPI void UpdateTexture(Texture2D texture, const void *pixels);                                         // Update GPU texture with new data
RLAPI Image GetTextureData(Texture2D texture);                                                           // Get pixel data from GPU texture and return an Image
RLAPI Image GetScreenData(void);                                                                         // Get pixel data from screen buffer and return an Image (screenshot)

// Texture generation functions
RLAPI Texture2D GenTextureCubemap(Shader shader, Texture2D map, int size);          // Generate cubemap texture from 2D texture
RLAPI Texture2D GenTextureIrradiance(Shader shader, Texture2D cubemap, int size);   // Generate irradiance texture using cubemap data
RLAPI Texture2D GenTexturePrefilter(Shader shader, Texture2D cubemap, int size);    // Generate prefilter texture using cubemap data
RLAPI Texture2D GenTextureBRDF(Shader shader, int size);                            // Generate BRDF texture

// Texture configuration functions
RLAPI void GenTextureMipmaps(Texture2D *texture);                                                        // Generate GPU mipmaps for a texture
RLAPI void SetTextureFilter(Texture2D texture, int filterMode);                                          // Set texture scaling filter mode
RLAPI void SetTextureWrap(Texture2D texture, int wrapMode);                                              // Set texture wrapping mode

// Texture drawing functions
RLAPI void DrawTexture(Texture2D texture, int posX, int posY, Color tint);                               // Draw a Texture2D
RLAPI void DrawTextureV(Texture2D texture, Vector2 position, Color tint);                                // Draw a Texture2D with position defined as Vector2
RLAPI void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);  // Draw a Texture2D with extended parameters
RLAPI void DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint);         // Draw a part of a texture defined by a rectangle
RLAPI void DrawTexturePro(Texture2D texture, Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint);       // Draw a part of a texture defined by a rectangle with 'pro' parameters
RLAPI void DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle destRec, Vector2 origin, float rotation, Color tint);  // Draws a texture (or part of it) that stretches or shrinks nicely

// Image/Texture misc functions
RLAPI int GetPixelDataSize(int width, int height, int format);

// module: text
// Font loading/unloading functions
RLAPI Font GetFontDefault(void);                                                            // Get the default Font
RLAPI Font LoadFont(const char *fileName);                                                  // Load font from file into GPU memory (VRAM)
RLAPI Font LoadFontEx(const char *fileName, int fontSize, int *fontChars, int charsCount);  // Load font from file with extended parameters
RLAPI Font LoadFontFromImage(Image image, Color key, int firstChar);                        // Load font from Image (XNA style)
RLAPI void UnloadFont(Font font);                                                           // Unload Font from GPU memory (VRAM)

// Text drawing functions
RLAPI void DrawText(const char *text, int posX, int posY, int fontSize, Color color);       // Draw text (using default font)
RLAPI void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);                // Draw text using font and additional parameters
RLAPI void DrawTextRec(Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint);   // Draw text using font inside rectangle limits

// Text misc. functions
RLAPI int MeasureText(const char *text, int fontSize);                                      // Measure string width for default font
RLAPI Vector2 MeasureTextEx(Font font, const char *text, float fontSize, float spacing);    // Measure string size for Font
RLAPI int GetGlyphIndex(Font font, int codepoint);                                          // Get index position for a unicode character on font

// Text strings management functions (no utf8 strings, only byte chars)
// NOTE: Some strings allocate memory internally for returned strings, just be careful!
RLAPI int TextCopy(char *dst, const char *src);                                                         // Copy one string to another, returns bytes copied
RLAPI bool TextIsEqual(const char *text1, const char *text2);                                           // Check if two text string are equal
RLAPI unsigned int TextLength(const char *text);                                                        // Get text length, checks for '\0' ending
RLAPI const char *TextFormat(const char *text, ...);                                                    // Text formatting with variables (sprintf style)
RLAPI const char *TextSubtext(const char *text, int position, int length);                              // Get a piece of a text string
RLAPI char *TextReplace(char *text, const char *replace, const char *by);                               // Replace text string (memory must be freed!)
RLAPI char *TextInsert(const char *text, const char *insert, int position);                             // Insert text in a position (memory must be freed!)
RLAPI const char *TextJoin(const char **textList, int count, const char *delimiter);                    // Join text strings with delimiter
RLAPI const char **TextSplit(const char *text, char delimiter, int *count);                             // Split text into multiple strings
RLAPI void TextAppend(char *text, const char *append, int *position);                                   // Append text at specific position and move cursor!
RLAPI int TextFindIndex(const char *text, const char *find);                                            // Find first text occurrence within a string
RLAPI const char *TextToUpper(const char *text);                                                        // Get upper case version of provided string
RLAPI const char *TextToLower(const char *text);                                                        // Get lower case version of provided string
RLAPI const char *TextToPascal(const char *text);                                                       // Get Pascal case notation version of provided string
RLAPI int TextToInteger(const char *text);                                                              // Get integer value from text (negative values not supported)
RLAPI char *TextToUtf8(int *codepoints, int length);                                                    // Encode text codepoint into utf8 text (memory must be freed!)

// UTF8 text strings management functions                                                         
RLAPI int *GetCodepoints(const char *text, int *count);                                                 // Get all codepoints in a string, codepoints count returned by parameters
RLAPI int GetCodepointsCount(const char *text);                                                         // Get total number of characters (codepoints) in a UTF8 encoded string
RLAPI int GetNextCodepoint(const char *text, int *bytesProcessed);                                      // Returns next codepoint in a UTF8 encoded string; 0x3f('?') is returned on failure
RLAPI const char *CodepointToUtf8(int codepoint, int *byteLength);                                      // Encode codepoint into utf8 text (char array length returned as parameter)

// module: models
// Basic geometric 3D shapes drawing functions
RLAPI void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color);                                    // Draw a line in 3D world space
RLAPI void DrawPoint3D(Vector3 position, Color color);                                                   // Draw a point in 3D space, actually a small line
RLAPI void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color); // Draw a circle in 3D world space
RLAPI void DrawCube(Vector3 position, float width, float height, float length, Color color);             // Draw cube
RLAPI void DrawCubeV(Vector3 position, Vector3 size, Color color);                                       // Draw cube (Vector version)
RLAPI void DrawCubeWires(Vector3 position, float width, float height, float length, Color color);        // Draw cube wires
RLAPI void DrawCubeWiresV(Vector3 position, Vector3 size, Color color);                                  // Draw cube wires (Vector version)
RLAPI void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color); // Draw cube textured
RLAPI void DrawSphere(Vector3 centerPos, float radius, Color color);                                     // Draw sphere
RLAPI void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);            // Draw sphere with extended parameters
RLAPI void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);         // Draw sphere wires
RLAPI void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone
RLAPI void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone wires
RLAPI void DrawPlane(Vector3 centerPos, Vector2 size, Color color);                                      // Draw a plane XZ
RLAPI void DrawRay(Ray ray, Color color);                                                                // Draw a ray line
RLAPI void DrawGrid(int slices, float spacing);                                                          // Draw a grid (centered at (0, 0, 0))
RLAPI void DrawGizmo(Vector3 position);             

// Model loading/unloading functions
RLAPI Model LoadModel(const char *fileName);                                                            // Load model from files (meshes and materials)
RLAPI Model LoadModelFromMesh(Mesh mesh);                                                               // Load model from generated mesh (default material)
RLAPI void UnloadModel(Model model);                                                                    // Unload model from memory (RAM and/or VRAM)

// Mesh loading/unloading functions
RLAPI void UnloadMesh(Mesh mesh);                                                                       // Unload mesh from memory (RAM and/or VRAM)

// Material loading/unloading functions
RLAPI Material* LoadMaterials(const char *fileName);                                // Load materials from model file
RLAPI Material LoadMaterialDefault(void);                                                               // Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
RLAPI void UnloadMaterial(Material material);                                                           // Unload material from GPU memory (VRAM)
RLAPI void SetMaterialTexture(Material *material, int mapType, Texture2D texture);                      // Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...)
RLAPI void SetModelMeshMaterial(Model *model, int meshId, int materialId);       

// Model animations loading/unloading functions
RLAPI ModelAnimation *LoadModelAnimations(const char *fileName, int *animsCount);                       // Load model animations from file
RLAPI void UpdateModelAnimation(Model model, ModelAnimation anim, int frame);                           // Update model animation pose
RLAPI void UnloadModelAnimation(ModelAnimation anim);                                                   // Unload animation data
RLAPI bool IsModelAnimationValid(Model model, ModelAnimation anim);                                     // Check model animation skeleton match

// Mesh generation functions
RLAPI Mesh GenMeshPoly(int sides, float radius);                                                        // Generate polygonal mesh
RLAPI Mesh GenMeshPlane(float width, float length, int resX, int resZ);                                 // Generate plane mesh (with subdivisions)
RLAPI Mesh GenMeshCube(float width, float height, float length);                                        // Generate cuboid mesh
RLAPI Mesh GenMeshSphere(float radius, int rings, int slices);                                          // Generate sphere mesh (standard sphere)
RLAPI Mesh GenMeshHemiSphere(float radius, int rings, int slices);                                      // Generate half-sphere mesh (no bottom cap)
RLAPI Mesh GenMeshCylinder(float radius, float height, int slices);                                     // Generate cylinder mesh
RLAPI Mesh GenMeshTorus(float radius, float size, int radSeg, int sides);                               // Generate torus mesh
RLAPI Mesh GenMeshKnot(float radius, float size, int radSeg, int sides);                                // Generate trefoil knot mesh
RLAPI Mesh GenMeshHeightmap(Image heightmap, Vector3 size);                                             // Generate heightmap mesh from image data
RLAPI Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize);                                           // Generate cubes-based map mesh from image data

// Mesh manipulation functions
RLAPI BoundingBox MeshBoundingBox(Mesh mesh);                                                           // Compute mesh bounding box limits
RLAPI void MeshTangents(Mesh *mesh);                                                                    // Compute mesh tangents
RLAPI void MeshBinormals(Mesh *mesh);                                                                   // Compute mesh binormals

// Model drawing functions
RLAPI void DrawModel(Model model, Vector3 position, float scale, Color tint);                           // Draw a model (with texture if set)
RLAPI void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model with extended parameters
RLAPI void DrawModelWires(Model model, Vector3 position, float scale, Color tint);                      // Draw a model wires (with texture if set)
RLAPI void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model wires (with texture if set) with extended parameters
RLAPI void DrawBoundingBox(BoundingBox box, Color color);                                               // Draw bounding box (wires)
RLAPI void DrawBillboard(Camera camera, Texture2D texture, Vector3 center, float size, Color tint);     // Draw a billboard texture
RLAPI void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle sourceRec, Vector3 center, float size, Color tint); // Draw a billboard texture defined by sourceRec

// Collision detection functions
RLAPI bool CheckCollisionSpheres(Vector3 centerA, float radiusA, Vector3 centerB, float radiusB);       // Detect collision between two spheres
RLAPI bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);                                     // Detect collision between two bounding boxes
RLAPI bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);                      // Detect collision between box and sphere
RLAPI bool CheckCollisionRaySphere(Ray ray, Vector3 center, float radius);                              // Detect collision between ray and sphere
RLAPI bool CheckCollisionRaySphereEx(Ray ray, Vector3 center, float radius, Vector3 *collisionPoint);   // Detect collision between ray and sphere, returns collision point
RLAPI bool CheckCollisionRayBox(Ray ray, BoundingBox box);                                              // Detect collision between ray and box
RLAPI RayHitInfo GetCollisionRayModel(Ray ray, Model model);                                            // Get collision info between ray and model
RLAPI RayHitInfo GetCollisionRayTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);                  // Get collision info between ray and triangle
RLAPI RayHitInfo GetCollisionRayGround(Ray ray, float groundHeight);                                    // Get collision info between ray and ground plane (Y-normal plane)

// module: shaders
// Shader loading/unloading functions
RLAPI Shader LoadShaderCode(const char *vsCode, const char *fsCode);      // Load shader from code strings and bind default locations
RLAPI void UnloadShader(Shader shader);                                   // Unload shader from GPU memory (VRAM)
RLAPI Shader GetShaderDefault(void);                                      // Get default shader
RLAPI Texture2D GetTextureDefault(void);                                  // Get default texture
RLAPI Texture2D GetShapesTexture(void);                                   // Get texture to draw shapes
RLAPI Rectangle GetShapesTextureRec(void);                                // Get texture rectangle to draw shapes
RLAPI void SetShapesTexture(Texture2D texture, Rectangle source);         // Define default texture used to draw shapes

// Shader configuration functions
RLAPI int GetShaderLocation(Shader shader, const char *uniformName);      // Get shader uniform location
RLAPI void SetShaderValue(Shader shader, int uniformLoc, const void *value, int uniformType);               // Set shader uniform value
RLAPI void SetShaderValueV(Shader shader, int uniformLoc, const void *value, int uniformType, int count);   // Set shader uniform value vector
RLAPI void SetShaderValueMatrix(Shader shader, int uniformLoc, Matrix mat);         // Set shader uniform value (matrix 4x4)
RLAPI void SetShaderValueTexture(Shader shader, int uniformLoc, Texture2D texture); // Set shader uniform value for texture
RLAPI void SetMatrixProjection(Matrix proj);                              // Set a custom projection matrix (replaces internal projection matrix)
RLAPI void SetMatrixModelview(Matrix view);                               // Set a custom modelview matrix (replaces internal modelview matrix)
RLAPI Matrix GetMatrixModelview(void);                                    // Get internal modelview matrix
RLAPI Matrix GetMatrixProjection(void);                                   // Get internal projection matrix

// Shading begin/end functions
RLAPI void BeginShaderMode(Shader shader);                                // Begin custom shader drawing
RLAPI void EndShaderMode(void);                                           // End custom shader drawing (use default shader)
RLAPI void BeginBlendMode(int mode);                                      // Begin blending mode (alpha, additive, multiplied)
RLAPI void EndBlendMode(void);                                            // End blending mode (reset to default: alpha blending)

// VR module will wrapped once rayfork supports it!
// Audio module will wrapped once rayfork supports it!

// RLGL
//------------------------------------------------------------------------------------
// Functions Declaration - Matrix operations
//------------------------------------------------------------------------------------
RLAPI void rlMatrixMode(int mode);                    // Choose the current matrix to be transformed
RLAPI void rlPushMatrix(void);                        // Push the current matrix to stack
RLAPI void rlPopMatrix(void);                         // Pop lattest inserted matrix from stack
RLAPI void rlLoadIdentity(void);                      // Reset current matrix to identity matrix
RLAPI void rlTranslatef(float x, float y, float z);   // Multiply the current matrix by a translation matrix
RLAPI void rlRotatef(float angleDeg, float x, float y, float z);  // Multiply the current matrix by a rotation matrix
RLAPI void rlScalef(float x, float y, float z);       // Multiply the current matrix by a scaling matrix
RLAPI void rlMultMatrixf(float *matf);                // Multiply the current matrix by another matrix
RLAPI void rlFrustum(double left, double right, double bottom, double top, double znear, double zfar);
RLAPI void rlOrtho(double left, double right, double bottom, double top, double znear, double zfar);
RLAPI void rlViewport(int x, int y, int width, int height); // Set the viewport area
RLAPI Vector3 rlUnproject(Vector3 source, Matrix projection, Matrix view);

//------------------------------------------------------------------------------------
// Functions Declaration - Vertex level operations
//------------------------------------------------------------------------------------
RLAPI void rlBegin(int mode);                         // Initialize drawing mode (how to organize vertex)
RLAPI void rlEnd(void);                               // Finish vertex providing
RLAPI void rlVertex2i(int x, int y);                  // Define one vertex (position) - 2 int
RLAPI void rlVertex2f(float x, float y);              // Define one vertex (position) - 2 float
RLAPI void rlVertex3f(float x, float y, float z);     // Define one vertex (position) - 3 float
RLAPI void rlTexCoord2f(float x, float y);            // Define one vertex (texture coordinate) - 2 float
RLAPI void rlNormal3f(float x, float y, float z);     // Define one vertex (normal) - 3 float
RLAPI void rlColor4ub(byte r, byte g, byte b, byte a);    // Define one vertex (color) - 4 byte
RLAPI void rlColor3f(float x, float y, float z);          // Define one vertex (color) - 3 float
RLAPI void rlColor4f(float x, float y, float z, float w); // Define one vertex (color) - 4 float

//------------------------------------------------------------------------------------
// Functions Declaration - OpenGL equivalent functions (common to 1.1, 3.3+, ES2)
// NOTE: This functions are used to completely abstract raylib code from OpenGL layer
//------------------------------------------------------------------------------------
RLAPI void rlEnableTexture(unsigned int id);                  // Enable texture usage
RLAPI void rlDisableTexture(void);                            // Disable texture usage
RLAPI void rlEnableRenderTexture(unsigned int id);            // Enable render texture (fbo)
RLAPI void rlDisableRenderTexture(void);                      // Disable render texture (fbo), return to default framebuffer
RLAPI void rlEnableDepthTest(void);                           // Enable depth test
RLAPI void rlDisableDepthTest(void);                          // Disable depth test
RLAPI void rlEnableBackfaceCulling(void);                     // Enable backface culling
RLAPI void rlDisableBackfaceCulling(void);                    // Disable backface culling
RLAPI void rlEnableScissorTest(void);                         // Enable scissor test
RLAPI void rlDisableScissorTest(void);                        // Disable scissor test
RLAPI void rlScissor(int x, int y, int width, int height);    // Scissor test
RLAPI void rlEnableWireMode(void);                            // Enable wire mode
RLAPI void rlDisableWireMode(void);                           // Disable wire mode
RLAPI void rlDeleteTextures(unsigned int id);                 // Delete OpenGL texture from GPU
RLAPI void rlDeleteRenderTextures(RenderTexture2D target);    // Delete render textures (fbo) from GPU
RLAPI void rlDeleteShader(unsigned int id);                   // Delete OpenGL shader program from GPU
RLAPI void rlDeleteVertexArrays(unsigned int id);             // Unload vertex data (VAO) from GPU memory
RLAPI void rlDeleteBuffers(unsigned int id);                  // Unload vertex data (VBO) from GPU memory
RLAPI void rlClearColor(byte r, byte g, byte b, byte a);      // Clear color buffer with color
RLAPI void rlClearScreenBuffers(void);                        // Clear used screen buffers (color and depth)
RLAPI void rlUpdateBuffer(int bufferId, void *data, int dataSize); // Update GPU buffer with new data
RLAPI unsigned int rlLoadAttribBuffer(unsigned int vaoId, int shaderLoc, void *buffer, int size, bool dynamic);   // Load a new attributes buffer

//------------------------------------------------------------------------------------
// Functions Declaration - rlgl functionality
//------------------------------------------------------------------------------------
RLAPI void rlglClose(void);                           // De-inititialize rlgl (buffers, shaders, textures)
RLAPI void rlglDraw(void);                            // Update and draw default internal buffers

RLAPI bool rlCheckBufferLimit(int vCount);            // Check internal buffer overflow for a given number of vertex
RLAPI void rlSetDebugMarker(const char *text);        // Set debug marker for analysis

// Textures data management
RLAPI unsigned int rlLoadTexture(void *data, int width, int height, int format, int mipmapCount); // Load texture in GPU
RLAPI unsigned int rlLoadTextureDepth(int width, int height, int bits, bool useRenderBuffer);     // Load depth texture/renderbuffer (to be attached to fbo)
RLAPI unsigned int rlLoadTextureCubemap(void *data, int size, int format);                        // Load texture cubemap
RLAPI void rlUpdateTexture(unsigned int id, int width, int height, int format, const void *data); // Update GPU texture with new data
RLAPI void rlUnloadTexture(unsigned int id);                              // Unload texture from GPU memory

RLAPI void rlGenerateMipmaps(Texture2D *texture);                         // Generate mipmap data for selected texture
RLAPI void *rlReadTexturePixels(Texture2D texture);                       // Read texture pixel data
RLAPI unsigned char *rlReadScreenPixels(int width, int height);           // Read screen pixel data (color buffer)

// Render texture management (fbo)
RLAPI RenderTexture2D rlLoadRenderTexture(int width, int height, int format, int depthBits, bool useDepthTexture);    // Load a render texture (with color and depth attachments)
RLAPI void rlRenderTextureAttach(RenderTexture target, unsigned int id, int attachType);  // Attach texture/renderbuffer to an fbo
RLAPI bool rlRenderTextureComplete(RenderTexture target);                 // Verify render texture is complete

// Vertex data management
RLAPI void rlLoadMesh(Mesh *mesh, bool dynamic);                          // Upload vertex data into GPU and provided VAO/VBO ids
RLAPI void rlUpdateMesh(Mesh mesh, int buffer, int num);                  // Update vertex or index data on GPU (upload new data to one buffer)
RLAPI void rlUpdateMeshAt(Mesh mesh, int buffer, int num, int index);     // Update vertex or index data on GPU, at index
RLAPI void rlDrawMesh(Mesh mesh, Material material, Matrix transform);    // Draw a 3d mesh with material and transform
RLAPI void rlUnloadMesh(Mesh mesh);                                       // Unload mesh data from CPU and GPU

// raymath.h
RMDEF Vector2 Vector2Zero(void);
RMDEF Vector2 Vector2One(void);
RMDEF Vector2 Vector2Add(Vector2 v1, Vector2 v2);
RMDEF Vector2 Vector2AddValue(Vector2 v, float add);
RMDEF Vector2 Vector2Subtract(Vector2 v1, Vector2 v2);
RMDEF Vector2 Vector2SubtractValue(Vector2 v, float sub);
RMDEF float Vector2Length(Vector2 v);
RMDEF float Vector2LengthSqr(Vector2 v);
RMDEF float Vector2DotProduct(Vector2 v1, Vector2 v2);
RMDEF float Vector2Distance(Vector2 v1, Vector2 v2);
RMDEF float Vector2Angle(Vector2 v1, Vector2 v2);
RMDEF Vector2 Vector2Scale(Vector2 v, float scale);
RMDEF Vector2 Vector2Multiply(Vector2 v1, Vector2 v2);
RMDEF Vector2 Vector2Negate(Vector2 v);
RMDEF Vector2 Vector2Divide(Vector2 v1, Vector2 v2);
RMDEF Vector2 Vector2Normalize(Vector2 v);
RMDEF Vector2 Vector2Lerp(Vector2 v1, Vector2 v2, float amount);
RMDEF Vector2 Vector2Rotate(Vector2 v, float degs);
RMDEF Vector2 Vector2MoveTowards(Vector2 v, Vector2 target, float maxDistance);

RMDEF Vector3 Vector3Zero(void);
RMDEF Vector3 Vector3One(void);
RMDEF Vector3 Vector3Add(Vector3 v1, Vector3 v2);
RMDEF Vector3 Vector3AddValue(Vector3 v, float add);
RMDEF Vector3 Vector3Subtract(Vector3 v1, Vector3 v2);
RMDEF Vector3 Vector3SubtractValue(Vector3 v, float sub);
RMDEF Vector3 Vector3Scale(Vector3 v, float scalar);
RMDEF Vector3 Vector3Multiply(Vector3 v1, Vector3 v2);
RMDEF Vector3 Vector3CrossProduct(Vector3 v1, Vector3 v2);
RMDEF Vector3 Vector3Perpendicular(Vector3 v);
RMDEF float Vector3Length(const Vector3 v);
RMDEF float Vector3LengthSqr(const Vector3 v);
RMDEF float Vector3DotProduct(Vector3 v1, Vector3 v2);
RMDEF float Vector3Distance(Vector3 v1, Vector3 v2);
RMDEF Vector3 Vector3Negate(Vector3 v);
RMDEF Vector3 Vector3Divide(Vector3 v1, Vector3 v2);
RMDEF Vector3 Vector3Normalize(Vector3 v);
RMDEF void Vector3OrthoNormalize(Vector3* v1, Vector3* v2);
RMDEF Vector3 Vector3Transform(Vector3 v, Matrix mat);
RMDEF Vector3 Vector3RotateByQuaternion(Vector3 v, Quaternion q);
RMDEF Vector3 Vector3Lerp(Vector3 v1, Vector3 v2, float amount);
RMDEF Vector3 Vector3Reflect(Vector3 v, Vector3 normal);
RMDEF Vector3 Vector3Min(Vector3 v1, Vector3 v2);
RMDEF Vector3 Vector3Max(Vector3 v1, Vector3 v2);
RMDEF Vector3 Vector3Barycenter(Vector3 p, Vector3 a, Vector3 b, Vector3 c);
RMDEF float3 Vector3ToFloatV(Vector3 v);
RMDEF float* Vector3ToFloat(Vector3 vec);
RMDEF Vector3 Vector3Unproject(Vector3 source, Matrix projection, Matrix view);

RMDEF float MatrixDeterminant(Matrix mat);
RMDEF float MatrixTrace(Matrix mat);
RMDEF Matrix MatrixTranspose(Matrix mat);
RMDEF Matrix MatrixInvert(Matrix mat);
RMDEF Matrix MatrixNormalize(Matrix mat);
RMDEF Matrix MatrixIdentity(void);
RMDEF Matrix MatrixAdd(Matrix left, Matrix right);
RMDEF Matrix MatrixSubtract(Matrix left, Matrix right);
RMDEF Matrix MatrixTranslate(float x, float y, float z);
RMDEF Matrix MatrixRotate(Vector3 axis, float angle);
RMDEF Matrix MatrixRotateXYZ(Vector3 ang);
RMDEF Matrix MatrixRotateX(float angle);
RMDEF Matrix MatrixRotateY(float angle);
RMDEF Matrix MatrixRotateZ(float angle);
RMDEF Matrix MatrixScale(float x, float y, float z);
RMDEF Matrix MatrixMultiply(Matrix left, Matrix right);
RMDEF Matrix MatrixFrustum(double left, double right, double bottom, double top, double near, double far);
RMDEF Matrix MatrixPerspective(double fovy, double aspect, double near, double far);
RMDEF Matrix MatrixOrtho(double left, double right, double bottom, double top, double near, double far);
RMDEF Matrix MatrixLookAt(Vector3 eye, Vector3 target, Vector3 up);
RMDEF float16 MatrixToFloatV(Matrix mat);
RMDEF float* MatrixToFloat(Matrix mat);

RMDEF Quaternion QuaternionAdd(Quaternion q1, Quaternion q2);
RMDEF Quaternion QuaternionAddValue(Quaternion q, float add);
RMDEF Quaternion QuaternionSubtract(Quaternion q1, Quaternion q2);
RMDEF Quaternion QuaternionSubtractValue(Quaternion q, float sub);
RMDEF Quaternion QuaternionIdentity(void);
RMDEF float QuaternionLength(Quaternion q);
RMDEF Quaternion QuaternionNormalize(Quaternion q);
RMDEF Quaternion QuaternionInvert(Quaternion q);
RMDEF Quaternion QuaternionMultiply(Quaternion q1, Quaternion q2);
RMDEF Quaternion QuaternionScale(Quaternion q, float mul);
RMDEF Quaternion QuaternionDivide(Quaternion q1, Quaternion q2);
RMDEF Quaternion QuaternionLerp(Quaternion q1, Quaternion q2, float amount);
RMDEF Quaternion QuaternionNlerp(Quaternion q1, Quaternion q2, float amount);
RMDEF Quaternion QuaternionSlerp(Quaternion q1, Quaternion q2, float amount);
RMDEF Quaternion QuaternionFromVector3ToVector3(Vector3 from, Vector3 to);
RMDEF Quaternion QuaternionFromMatrix(Matrix mat);
RMDEF Matrix QuaternionToMatrix(Quaternion q);
RMDEF Quaternion QuaternionFromAxisAngle(Vector3 axis, float angle);
RMDEF void QuaternionToAxisAngle(Quaternion q, Vector3* outAxis, float* outAngle);
RMDEF Quaternion QuaternionFromEuler(float roll, float pitch, float yaw);
RMDEF Vector3 QuaternionToEuler(Quaternion q);
RMDEF Quaternion QuaternionTransform(Quaternion q, Matrix mat);
```