# CUB3D
## Motor gráfico de raycasting
Baseado no célebre jogo (o primeiro estilo FPS) Wolfstein 3D, esse projeto trata-se de um renderizador de mapa de duas dimensões.
Você pode criar os seus mapas, escolher as texturas das paredes e das sprites, as cores do teto e do chão e o motor gráfico roda tudo para você.

<img src="https://github.com/gabrielsl96/cub3d/blob/master/Cub3d.gif " width="400">

## Uso
Primeiro clone o reposíório:
```
git clone git@github.com:gabrielsl96/cub3d
cd cub3d
```

Esse projeto usa a biblioteca [minilibx-linux](https://github.com/42Paris/minilibx-linux) e para isso precisamos configurá-la:
```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
make -C ./minilibx-linux
sudo cp minilibx-linux/libmlx.a /usr/local/lib
sudo cp minilibx-linux/mlx.h /usr/local/include
```

Após configurar a biblioteca:
```
make
```
## Configuração do mapa
É possível criar mapas. Trata-se de um arquivo com extensão ".cub" que contém os seguintes parametros:
Parâmetro | Descrição
--------- | :------
R         | Resolução do jogo;
NO        | Arquivo de imagem ".xpm" que servirá de textura para as paredes do lado Norte;
SO        | Arquivo de imagem ".xpm" que servirá de textura para as paredes do lado Sul;
WE        | Arquivo de imagem ".xpm" que servirá de textura para as paredes do lado Oeste;
EA        | Arquivo de imagem ".xpm" que servirá de textura para as parede do lado Leste;
S         | Arquivo de imagem ".xpm" que servirá de textura para as "sprites";
C         | Cor do teto em padrão RGB;
F         | Cor do chão em padrão RGB;
Mapa      | 0 - Espaço Vazio, 1 - Parede, 2 - Sprite, WSEN - Posição e Direção inicial do jogador; Obs: o mapa deve ser sempre cecado por paredes;

Veja o exemplo:
```
R 2100 720
D
NO ./images/wall_sw_1.XPM
SO ./images/wall_sw_2.XPM
WE ./images/wall_sw_3.XPM
EA ./images/wall_sw_4.XPM
S  ./images/sprite.XPM

C 0,0,0
F 90,90,230

        1111111111111111111111111
        100000000011000000S000001
        1011000001110000000000001
        1001000000000000000200001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100022012221
10000000000000001100000000001
10000000000000001101010012221
1100000111010101111101110000111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Rodar
Para iniciar o motor gráfico:
```
.cub3D .<arquivo_do_mapa.cub>
```

## Recursos
### Botões
Botão     | Ação
--------- | :------
Esc       | Encerra o programa;
W         | Movimento para frente;
S         | Movimento para trás;
D         | Movimento para a direita;
A         | Movimento para a esquerda;
E ou -►   | Giro para a direita;
Q ou ◄-   | Giro para a esquerda;
