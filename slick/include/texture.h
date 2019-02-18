#ifndef TEXTURE_H
#define TEXTURE_H
#include <cstdio>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define FILE_SUCCESSFUL 0
#define FILE_DIDNOTOPEN 1
#define FILE_IO 2
#define FILE_NOTBMP 3
#define _FILE_UNKNOWN 4
#define FILE_MEMORYDIDNTALLOC 5
#define FILE_NOTSUPPORT 6

struct ColorMap
{
    char Blue;
    char Green;
    char Red;
    char Reserved;
};
#pragma pack(push)
#pragma pack(1)
struct BMP//Структура BMP файла
{
    uint16_t Signature;
    int Filesize;
    int Reserved;
    int Offset;
    int Structsize;
    int Width;
    int Height;
    uint16_t Planecount;
    uint16_t Bitcount;
    int Compression;
    int ImageSize;
    int Xpixels;
    int Ypixels;
    int Colorcount;
    int Importantcolor;
};
#pragma pack(pop)
class SLITexture
{
    private:
    char Filename[64];
    int filesize;
    public:
    unsigned int Width;
    unsigned int Height;
    unsigned char* Data;
    void Set(const char filename[]);
    unsigned int Bind();
    unsigned int Load();
    unsigned int texture;
};
#endif
