#ifndef _IMAGEHEADERS_H
#define _IMAGEHEADERS_H
struct Point {
int x;
int y;
} typedef Point;

struct Cluster{
int r;
int g;
int b;
Point* members;
int size;
} typedef Cluster;

extern int* readImage();

extern Cluster* kmeans(int* img, int k); //list of k clusters

extern int* kmeansChangeImage(int* img, int k); //list of k r,g,b sets for img[i][k][0]

extern void appendBits(unsigned long n, int b); //least significant b bits of n

extern unsigned long getBits(int b);

extern void compressWithPolygons(int b, int* img); //b is # of bits left

extern int* decompressWithPolygons(); //list of256*256*3 int, RGB

#endif

