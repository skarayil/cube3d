/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:25:58 by skarayil          #+#    #+#             */
/*   Updated: 2026/06/28 14:26:44 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_img
{
    void    *img_ptr;     // MLX image pointer'ı
    char    *addr;        // Görüntünün hafızadaki başlangıç adresi
    int     bpp;          // Bits Per Pixel (Piksel başına bit)
    int     line_length;  // Bir satırın bellekteki uzunluğu
    int     endian;       // Bellek okuma yönü (Little/Big Endian)
} t_img;