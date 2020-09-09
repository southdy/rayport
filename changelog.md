# rayport changelog

> NOTE: In addition to read the changelog, I recommend you reading the [API](https://github.com/Rabios/rayport/blob/master/api.md) to see list of functions!

# 9/September/2020

- From now if rayfork defined rayport will defined (So no errors cause of `rayfork.h` include will happen)!

# 4/September/2020

- More functions wrapped!

```c
RLAPI void DrawPoint3D(Vector3 position, Color color);
RLAPI Texture2D GetShapesTexture(void);
RLAPI Rectangle GetShapesTextureRec(void);
RLAPI Vector3 rlUnproject(Vector3 source, Matrix projection, Matrix view);
RMDEF Vector3 Vector3Unproject(Vector3 source, Matrix projection, Matrix view);
```

# 3/September/2020

### Additions

- Wrapped more image and drawing functions!
- Added raylib easings for more compatibility!

# 2/September/2020

First version!
