#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800
#define UNITSIZE 40


#define RED 0xFF0000FF
#define BLUE 0xFFFF0000
#define GREEN 0xFF00FF00
#define WHITE 0xFFFFFFFF
#define BLACK 0xFF000000
#define GREY 0xFF303030




typedef uint32_t Colour;

static Colour image[HEIGHT][WIDTH];

void write_pixel(Colour colour, FILE *fptr);
void fill_image(Colour colour);
void save_image(const char *file);
void draw_coordinates(size_t xlen, size_t ylen);
void plot(float(*fofox)(float, float, float, float), Colour colour);
float quadratic(float x, float a, float b, float c);

int main(int argc, char *argv[])
{
  fill_image(WHITE);
  draw_coordinates(UNITSIZE, UNITSIZE);
  plot(quadratic, RED);
  save_image("Picture.ppm");
}


float quadratic(float x, float a, float b, float c)
{
  return (a * x * x) + (b * x) + c;
}

void plot(float(*fofx)(float, float, float, float), Colour colour)
{
  int xPix = 0;
  float x, y;
  while (xPix < WIDTH)
  {
    x = (xPix - WIDTH / 2) / 40.0;
    y = fofx(x, 0.25, 0.0, -2.0);

    int yPix = (int)((y * -40.0) + (HEIGHT / 2));

    if (0 <= yPix && yPix < HEIGHT)
    {
      image[yPix][xPix] = colour;
    }
    xPix++;
  }
}

void write_pixel(Colour colour, FILE *fptr)
{
  unsigned char b = (colour&0x0000FF);
  unsigned char g = (colour&0x00FF00)>>8;
  unsigned char r = (colour&0xFF0000)>>16;

  fwrite(&b, 1, 1, fptr);
  fwrite(&g, 1, 1, fptr);
  fwrite(&r, 1, 1, fptr);
}

void fill_image(Colour colour)
{
  size_t y = 0;
  while (y < HEIGHT)
  {
    size_t x = 0;
    while (x < WIDTH)
    {
      image[y][x] = colour;
      x++;
    }
    y++;
  }
}

void save_image(const char *file)
{
  FILE *fptr = fopen(file, "wb");
  fprintf(fptr, "P6\n%d %d 255\n", WIDTH, HEIGHT);
  size_t y = 0;
  while (y < HEIGHT)
  {
    size_t x = 0;
    while (x < WIDTH)
    {
      write_pixel(image[y][x], fptr);

      x++;
    }
    y++;
  }
  fclose(fptr);
}


void draw_coordinates(size_t xlen, size_t ylen)
{
  size_t y = 0;
  size_t x = 0;
  while (y < HEIGHT)
  {
    x = 0;
    while (x < WIDTH)
    {
      image[y][x] = GREY;
      x = x + xlen;
    }
    y = y + ylen;
  }
  y = 0;
  x = WIDTH / 2;
  while (y < HEIGHT)
  {
    image[y][x] = BLACK;
    y++;
  }
  x = 0;
  y = HEIGHT / 2;
  while (x < WIDTH)
  {
    image[y][x] = BLACK;
    x++;
  }
}
