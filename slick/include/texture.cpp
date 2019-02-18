#include "texture.h"
void SLITexture::Set(const char filename[])
{
   strcpy(Filename, filename);
}

unsigned int SLITexture::Load()
{
    FILE* img = fopen(Filename, "rb");
    if(img == 0) return FILE_DIDNOTOPEN;
    fseek(img, 0, SEEK_SET);
    BMP data;
    if(fread(&data, 1, sizeof(BMP), img) != sizeof(BMP))
    {
        fclose(img);
        return FILE_IO;
    }
    if(data.Signature != 0x4D42 && data.Signature != 0x4349 && data.Signature != 0x5450)
    {
        fclose(img);
        return FILE_NOTBMP;
    }
    fseek(img, 0, SEEK_END);
    filesize = ftell(img);
    fseek(img, sizeof(BMP), SEEK_SET);
    if(data.Filesize != filesize || data.Reserved !=0 || data.Planecount != 1 || (data.Structsize != 40 && data.Structsize != 108 && data.Structsize != 124))
    {
        fclose(img);
        return _FILE_UNKNOWN;
    }
    if(data.Bitcount == 32)
    {
        fclose(img);
        return FILE_NOTSUPPORT;
    }
    Width = data.Width;
    Height = data.Height;
    Data = (unsigned char*)malloc(data.ImageSize);
    if(Data == 0)
    {
        fclose(img);
        return FILE_MEMORYDIDNTALLOC;
    }
    fseek(img, data.Offset, SEEK_SET);
    if(fread(Data, 1, data.ImageSize, img) != (unsigned int)data.ImageSize)
    {
        fclose(img);
        return FILE_IO;
    }
    fclose(img);
    //delete &data;
    return FILE_SUCCESSFUL;
}

unsigned int SLITexture::Bind()
{
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, Data);
    //gluBuild2DMipmaps(GL_TEXTURE_2D, 3, Width, Height, GL_BGR, GL_UNSIGNED_BYTE, Data);
    return texture;
}
