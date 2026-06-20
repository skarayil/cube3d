typedef struct s_map
{
    char    **grid;       // Haritanın 2 boyutlu char dizisi (Zorunlu) [cite: 124]
    int     width;        // Haritanın en geniş satırının uzunluğu
    int     height;       // Haritanın toplam satır sayısı
    char    *no_path;     // Kuzey dokusunun dosya yolu [cite: 142-145]
    char    *so_path;     // Güney dokusunun dosya yolu [cite: 146-149]
    char    *we_path;     // Batı dokusunun dosya yolu [cite: 150-153]
    char    *ea_path;     // Doğu dokusunun dosya yolu [cite: 154-157]
    int     floor_color;  // Zemin RGB değerinin bitwise (Hex) hali [cite: 158-161]
    int     ceil_color;   // Tavan RGB değerinin bitwise (Hex) hali [cite: 164-168]
} t_map;

typedef struct s_img
{
    void    *img_ptr;     // MLX image pointer'ı
    char    *addr;        // Görüntünün hafızadaki başlangıç adresi
    int     bpp;          // Bits Per Pixel (Piksel başına bit)
    int     line_length;  // Bir satırın bellekteki uzunluğu
    int     endian;       // Bellek okuma yönü (Little/Big Endian)
} t_img;

typedef struct s_player
{
    double  pos_x;      // Oyuncunun X koordinatı (Örn: 5.5)
    double  pos_y;      // Oyuncunun Y koordinatı
    double  dir_x;      // Bakış yönü vektörü X (Örn: Kuzey için 0)
    double  dir_y;      // Bakış yönü vektörü Y (Örn: Kuzey için -1)
    double  plane_x;    // Kamera düzlemi X (Görüş açısı - FOV için)
    double  plane_y;    // Kamera düzlemi Y
} t_player;

typedef struct s_data
{
    void        *mlx_ptr;     // MLX bağlantı pointer'ı
    void        *win_ptr;     // MLX pencere pointer'ı
    t_map       map;          // Senin parsing verilerin
    t_player    player;       // Oyuncu verileri
    t_img       buffer;       // Ekrana basılacak ana görüntü
    t_img       textures[4];  // Yüklenmiş 4 duvar dokusu (N, S, E, W)
} t_data;