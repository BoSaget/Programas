#include <cstdio>
#include "bitmap/bitmap_image.hpp"

using namespace std;

int main()
{
   bitmap_image image("input.bmp");

   if (!image)
   {
      printf("Error - Failed to open: input.bmp\n");
      return 1;
   }

   unsigned int total_number_of_pixels = 0;

   const unsigned int height = image.height();
   const unsigned int width  = image.width();

   for (size_t y = 0; y < height; ++y)
   {
      for (size_t x = 0; x < width; ++x)
      {
         rgb_t colour;

         image.get_pixel(x, y, colour);

         if (colour.red >= 111)
            total_number_of_pixels++;
      }
   }

   printf("Number of pixels with red >= 111: %d\n",total_number_of_pixels);

   return 0;
}