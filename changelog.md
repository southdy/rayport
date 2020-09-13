# rayport changelog

> NOTE: In addition to read the changelog, I recommend you reading the [API](https://github.com/Rabios/rayport/blob/master/api.md) to see list of functions!

## 12/September/2020

### Improvements

- Readded raymath again (You don't need to include raymath header as wrapped from rayfork!)
- Wrapped a bunch of core functions!
- Wrapped strings management functions!

> CAUTION: You still need to include raylib easings header to use easings!

## 11/September/2020

### Improvements

- Now you need to include `raylib.h` and rayfork to work with rayport.
- Removed easings and raymath from rayport (You should use `easings.h` and `raymath.h` from now).
- Offered internal type converters for better wrapping!
- New logo!
- Made a modified version of `raylib.h` (Not modified but add stuff to structs) for compatibility with rayfork!

> CAUTION: You shouldn't use external `rlgl.h`, That's to stick with rayfork!

## 9/September/2020

### Improvements

- From now if rayfork defined rayport will defined (So no errors cause of `rayfork.h` include will happen)!
- Organized code via `#pragma region` and `#pragma endregion` for better code!
- Made header checks, So you can use external (Or custom) `easings.h` and `raymath.h` if you don't want to use those defined by rayport (You can still use ones defined by rayport).

## 4/September/2020

### Additions

- More functions wrapped!

```c
RLAPI void DrawPoint3D(Vector3 position, Color color);
RLAPI Texture2D GetShapesTexture(void);
RLAPI Rectangle GetShapesTextureRec(void);
RLAPI Vector3 rlUnproject(Vector3 source, Matrix projection, Matrix view);
RMDEF Vector3 Vector3Unproject(Vector3 source, Matrix projection, Matrix view);
```

## 3/September/2020

### Additions

- Wrapped more image and drawing functions!
- Added raylib easings for more compatibility!

## 2/September/2020

First version!
