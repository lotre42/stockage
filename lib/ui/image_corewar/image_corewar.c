#include "corewar.h"

void	put_cell(int i, GdkRGBA color, t_data *data)
{
	int tmp_w;
	int tmp_h;
	int x;
	int y;

	x = i % 64;
	y = i / 64;
	tmp_h = 0;
	x = x * data->img.cell_width;
	y = y * data->img.cell_height;
	while (tmp_h < data->img.cell_height)
	{
		tmp_w = 0;
		while(tmp_w < data->img.cell_width)
		{
			put_pixel(data, x + tmp_w, y + tmp_h, color);
			tmp_w++;
		}
		tmp_h++;
	}
}

void	image_update(t_data *data)
{
	int i;

	data->img.pix = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, data->img.width, data->img.height);
	i = 0;
	while(i < MEM_SIZE)
	{
		put_cell(i, data->player[rand() % 3].color, data);
		i++;
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(data->img.image), data->img.pix);
}

void	image_update_size(t_data *data)
{
	GtkAllocation a;
	gtk_widget_get_allocation (data->img.box_img, &a);
	data->img.height = a.height;
	data->img.width = a.width;
	data->img.cell_width = a.width / 64;
	data->img.cell_height = a.height / 64;
}

void	image_corewar(t_data *data)
{
	data->img.box_img = gtk_event_box_new();
	data->img.pix = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, 512, 512);
	data->img.image = gtk_image_new_from_pixbuf(data->img.pix);
	gtk_widget_set_hexpand(data->img.box_img, TRUE);
	gtk_widget_set_vexpand(data->img.box_img, TRUE);
	gtk_container_add(GTK_CONTAINER(data->img.box_img), data->img.image);
	gtk_grid_attach(GTK_GRID(data->gtk.grid), data->img.box_img, 0, 1, 1, 1);
}
