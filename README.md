# Cub3D - Harita Mimarı (Parsing ve Validasyon) Görev Listesi

Bu belge, `.cub` uzantılı harita dosyasının okunması, içindeki verilerin doğrulanması (validasyon) ve grafik motorunun (raycaster) kullanabileceği temiz bir C `struct` yapısına dönüştürülmesi için gereken adımları içerir.

## Aşama 1: Dosya ve Argüman Kontrolü
- [ ] [cite_start]Programın tam olarak iki argümanla (`./cub3D harita.cub`) çalıştırıldığını kontrol et[cite: 107]. (Eksik veya fazlaysa hata dön).
- [ ] [cite_start]İkinci argümanın (`argv[1]`) son 4 karakterinin `.cub` olup olmadığını kontrol et[cite: 123].
- [ ] [cite_start]Dosyayı `open()` ile açmayı dene[cite: 107]. Eğer dosya yoksa veya okuma izni yoksa hata fırlat.

## Aşama 2: Ortak Veri Yapısını (Struct) Tasarlamak
Grafik tarafını yapacak kişiyle ortak kullanacağınız ana veri yapısını (`t_data` veya `t_map`) tanımla. Şunları içermelidir:
- [ ] 4 adet string (Kuzey, Güney, Doğu, Batı kaplamalarının dosya yolları).
- [ ] 2 adet tamsayı (Zemin ve Tavan RGB renklerinin birleştirilmiş int değerleri).
- [ ] 2 boyutlu `char` dizisi (`char **map`) (Haritanın kendisi).
- [ ] Haritanın satır ve sütun boyutları (Grafik çizimi için gerekli olacak).
- [ ] Oyuncunun başlangıç pozisyonu (X, Y) ve bakış yönü (N, S, E, W).

## Aşama 3: Dosyayı Okuma ve Konfigürasyonları Ayıklama
[cite_start]`get_next_line` (libft'den) kullanarak dosyayı satır satır okumaya başla[cite: 41, 107]. [cite_start]Harita içeriği her zaman dosyanın **en sonunda** olmalıdır[cite: 133].
- [ ] [cite_start]Boş satırları (sadece `\n` içeren) atla (Harita kısmı hariç)[cite: 132].
- [ ] [cite_start]Satır `NO`, `SO`, `WE`, `EA` ile başlıyorsa; yanındaki dosya yolunu al ve kaydet[cite: 141]. 
- [ ] [cite_start]Satır `F` veya `C` ile başlıyorsa; yanındaki renk değerlerini ayıklamak için ilgili fonksiyona gönder[cite: 141].
- [ ] Aynı tanımlayıcıdan (örneğin iki tane `NO`) birden fazla var mı kontrol et. Varsa hata dön.
- [ ] Tüm 6 konfigürasyon (4 kaplama, 2 renk) başarıyla okunduğunda, dosyanın geri kalanının harita olduğunu kabul et.

## Aşama 4: Renk (RGB) Doğrulaması
[cite_start]`F` ve `C` satırları `R,G,B` formatında gelecek (Örn: `220,100,0`) [cite: 158-161, 164-168].
- [ ] [cite_start]`ft_split` gibi bir fonksiyonla stringi virgüllerden böl[cite: 41, 107].
- [ ] Tam olarak 3 parça (R, G, B) olup olmadığını kontrol et. Fazla veya eksik virgül varsa hata dön.
- [ ] Her bir değerin sadece rakamlardan oluştuğunu doğrula.
- [ ] [cite_start]Değerleri `int`'e çevir ve `0 <= değer <= 255` aralığında olup olmadığını kontrol et[cite: 161, 168].
- [ ] Geçerliyse, bu 3 RGB değerini MiniLibX'in anlayacağı tek bir Hex formatına (örneğin bitwise shift `<<` kullanarak) dönüştürüp `struct`'a kaydet.

## Aşama 5: Haritayı Belleğe Alma (Parsing the Map)
Kalan satırları 2 boyutlu bir `char **` dizisine aktar.
- [ ] [cite_start]Sadece izin verilen 6 karakterin (`0`, `1`, `N`, `S`, `E`, `W`) ve boşlukların (` `) kullanıldığından emin ol[cite: 124, 136]. Farklı bir karakter varsa hata dön.
- [ ] Harita içerisinde tam olarak **1 adet** başlangıç yönü (N, S, E, W) olduğunu kontrol et. [cite_start]Yoksa veya birden fazlaysa hata dön[cite: 124].
- [ ] Haritanın sonuna kadar okumayı tamamla. Haritanın kendi içinde boş satırlar olmamasına dikkat et (genelde projede geçersiz kabul edilir).

## Aşama 6: Harita Geometrisi ve Duvar Kontrolü (En Zor Aşama)
[cite_start]Haritanın kapalı (surrounded by walls) olup olmadığını kontrol et[cite: 131]. Oyuncu veya hiçbir zemin bloğu boşluğa (` `) sızmamalıdır.
- [ ] **Algoritma Önerisi:** Haritadaki her bir `0` (ve oyuncu başlangıç noktası) için etrafındaki 8 kareyi (yukarı, aşağı, sağ, sol, çaprazlar) kontrol et.
- [ ] Eğer bir `0`'ın veya oyuncunun komşusu ` ` (boşluk) ise veya harita sınırlarının dışına (null terminator'e) denk geliyorsa, harita açık demektir (Hata dön).

## Aşama 7: Hata Yönetimi (Error Handling) ve Bellek Temizliği
[cite_start]Proje kuralları gereği hata yönetimi çok katıdır[cite: 34].
- [ ] [cite_start]Herhangi bir aşamada kural ihlali bulunursa program anında `Error\n` yazdırıp hemen altına mantıklı bir hata mesajı yazdırarak kapanmalıdır (Örn: `Error\nHarita duvarlarla kapalı değil.`)[cite: 190].
- [ ] [cite_start]Kapanmadan önce o ana kadar `malloc` ile ayrılmış tüm bellekleri (kaplama yolları, harita dizisi vb.) eksiksiz şekilde `free` yap[cite: 34]. [cite_start]Memory leak (bellek sızıntısı) toleransı sıfırdır[cite: 34].
- [ ] [cite_start]Dosya tanımlayıcıyı (fd) `close()` ile kapatmayı unutma[cite: 107].






















```
cube3d/
│
├── Makefile
├── README.md
│
├── maps/
│   └── test.cub
│
├── includes/
│   ├── cube3d/
│   │   ├── cube3d.h
│   │   ├── map.h
│   │   ├── player.h
│   │   └── img.h
│   │
│   ├── get_next_line/
│   └── libft/
│
└── sources/
    ├── main.c
    │
    ├── parsing/
    │   ├── parser/
    │   ├── checker/
    │   └── utils/
    │
    ├── mlx/
    ├── rendering/
    ├── raycasting/
    ├── events/
    └── utils/
```
```
Yapılması gereken validasyonlar:

1. Harita etrafının duvarla çevrili olması (EN ÖNEMLİ):
Haritanın en üst, en alt, en sol ve en sağ sınırları 1 olmalı

Oyuncu (N/S/E/W) ve boş alanlar (0) asla sınıra temas etmemeli

2. Geçersiz karakter kontrolü:
Sadece 0, 1, N, S, E, W, boşluk () ve newline (\n) kabul edilmeli

3. Tek bir oyuncu kontrolü:
Sadece 1 tane N, S, E veya W olmalı (zaten var)

4. Haritanın dikdörtgen olması:
Tüm satırlar aynı uzunlukta olmalı (boşluklarla tamamlanabilir)

5. .cub dosyası formatı:
Identifier'lar (NO, SO, WE, EA, F, C) haritadan ÖNCE gelmeli

Geçersiz satırlar olmamalı
```