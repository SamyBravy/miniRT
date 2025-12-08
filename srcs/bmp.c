/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <agent@ai>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2024/10/24 12:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "minirt_bonus.h"

// BMP Header Structure (simplified)
#pragma pack(push, 1)
typedef struct s_bmp_header {
	uint16_t type;             // Magic identifier: "BM"
	uint32_t size;             // File size in bytes
	uint16_t reserved1;        // Not used
	uint16_t reserved2;        // Not used
	uint32_t offset;           // Offset to image data in bytes
	uint32_t dib_header_size;  // DIB Header size (40 bytes)
	int32_t  width_px;         // Width of the image
	int32_t  height_px;        // Height of image
	uint16_t num_planes;       // Number of color planes
	uint16_t bits_per_pixel;   // Bits per pixel
	uint32_t compression;      // Compression type
	uint32_t image_size_bytes; // Image size in bytes
	int32_t  x_resolution_ppm; // Pixels per meter
	int32_t  y_resolution_ppm; // Pixels per meter
	uint32_t num_colors;       // Number of colors
	uint32_t important_colors; // Important colors
} t_bmp_header;
#pragma pack(pop)

void	save_bmp(t_data *data, char *filename)
{
	int				fd;
	t_bmp_header	header;
	int				x;
	int				y;
	unsigned int	color;
	char			*pixel_ptr;
	int				pad;
	char			*full_name;

	// Append .bmp if not present
	full_name = malloc(ft_strlen(filename) + 5);
	if (!full_name)
		return ;
	ft_strlcpy(full_name, filename, ft_strlen(filename) + 5);
	if (!ft_strnstr(filename, ".bmp", ft_strlen(filename)))
		ft_strlcat(full_name, ".bmp", ft_strlen(filename) + 5);

	fd = open(full_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		printf("Error: Could not create BMP file %s\n", full_name);
		free(full_name);
		return ;
	}

	pad = (4 - (WIDTH * 3) % 4) % 4; // Scanlines must be 4-byte aligned

	ft_bzero(&header, sizeof(t_bmp_header));
	header.type = 0x4D42; // "BM"
	header.size = sizeof(t_bmp_header) + (WIDTH * 3 + pad) * HEIGHT;
	header.offset = sizeof(t_bmp_header);
	header.dib_header_size = 40;
	header.width_px = WIDTH;
	header.height_px = -HEIGHT; // Top-down
	header.num_planes = 1;
	header.bits_per_pixel = 24; // RGB

	if (write(fd, &header, sizeof(t_bmp_header))) {}

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// MLX uses ARGB or BGRA depending on endianness. Usually little endian -> BGRA
			// But we can get pixel valid color from the address.
			// Assuming 32 bpp buffer from mlx_get_data_addr
			t_img *img = &data->mlx_struct->img;
			pixel_ptr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
			color = *(unsigned int *)pixel_ptr;
			
			// BMP expects BGR (3 bytes)
			unsigned char r = (color >> 16) & 0xFF;
			unsigned char g = (color >> 8) & 0xFF;
			unsigned char b = (color) & 0xFF;

			if (write(fd, &b, 1)) {}
			if (write(fd, &g, 1)) {}
			if (write(fd, &r, 1)) {}
			x++;
		}
		if (write(fd, "\0\0\0", pad)) {}
		y++;
	}

	close(fd);
	printf("Screenshot saved to %s\n", full_name);
	free(full_name);
}
