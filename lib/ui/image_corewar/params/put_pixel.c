#include "corewar.h"

void put_pixel(t_data *data, int x, int y, GdkRGBA color)
{
  guchar  *pixels;
  guchar  *p;

  data->img.n_channels = gdk_pixbuf_get_n_channels(data->img.pix);
  g_assert(gdk_pixbuf_get_colorspace(data->img.pix) == GDK_COLORSPACE_RGB);
  g_assert(gdk_pixbuf_get_bits_per_sample(data->img.pix) == 8);
  g_assert(gdk_pixbuf_get_has_alpha(data->img.pix));
  g_assert(data->img.n_channels == 4);
  data->img.width = gdk_pixbuf_get_width(data->img.pix);
  data->img.height = gdk_pixbuf_get_height(data->img.pix);
  g_assert(x >= 0 && x < data->img.width);
  g_assert(y >= 0 && y < data->img.height);
  data->img.rowstride = gdk_pixbuf_get_rowstride(data->img.pix);
  pixels = gdk_pixbuf_get_pixels(data->img.pix);
  p = pixels + y * data->img.rowstride + x * data->img.n_channels;
  p[0] = color.red;
  p[1] = color.green;
  p[2] = color.blue;
  p[3] = color.alpha;
}