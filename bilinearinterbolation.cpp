
#include <vector>
template<typename T>
T bilinear(
   const T &tx, 
   const T &ty, 
   const T &c00, 
   const T &c10,
   const T &c01,
   const T &c11)
{
#if 1
    T a = c00 * (T(1) - tx) + c10 * tx;
    T b = c01 * (T(1) - tx) + c11 * tx;
    return a * (T(1) - ty) + b * ty;
#else
    return (T(1) - tx) * (T(1) - ty) * c00 + 
        tx * (T(1) - ty) * c10 +
        (T(1) - tx) * ty * c01 +
        tx * ty * c11;
#endif
}
 
template<typename T>
void testBilinearInterpolation()
{
    // testing bilinear interpolation
    int imageWidth = 512;
    int gridSizeX = 9, gridSizeY = 9;
    Vec3<T> *grid2d = new Vec3<T>[(gridSizeX + 1) * (gridSizeY + 1)]; // lattices
    // fill grid with random colors
    for (int j = 0, k = 0; j <= gridSizeY; ++j) {
        for (int i = 0; i <= gridSizeX; ++i, ++k) {
            grid2d[j * (gridSizeX + 1) + i] = Vec3<T>(drand48(), drand48(), drand48());
        }
    }
    // now compute our final image using bilinear interpolation
    Vec3<T> *imageData = new Vec3<T>[imageWidth*imageWidth], *pixel = imageData;
    for (int j = 0; j < imageWidth; ++j) {
        for (int i = 0; i < imageWidth; ++i) {
            // convert i,j to grid coordinates
            T gx = i / T(imageWidth) * gridSizeX; // be careful to interpolate boundaries
            T gy = j / T(imageWidth) * gridSizeY; // be careful to interpolate boundaries
            int gxi = int(gx);
            int gyi = int(gy);
            const Vec3<T> & c00 = grid2d[gyi * (gridSizeX + 1) + gxi];
            const Vec3<T> & c10 = grid2d[gyi * (gridSizeX + 1) + (gxi + 1)];
            const Vec3<T> & c01 = grid2d[(gyi + 1) * (gridSizeX + 1) + gxi];
            const Vec3<T> & c11 = grid2d[(gyi + 1) * (gridSizeX + 1) + (gxi + 1)];
            *(pixel++) = bilinear<Vec3<T> >(gx - gxi, gy - gyi, c00, c10, c01, c11);
        }
    }
    saveToPPM<T>("./bilinear.ppm", imageData, imageWidth, imageWidth);
    delete [] imageData;    
}
