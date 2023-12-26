<a href="https://github.com/erivero-p/42-Tutorials/blob/master/About%20MiniLibX/Cómo%20y%20para%20qué%20usar%20MiniLibx.md">
✨ Tutorial hecho por la grandísima erviro-p ✨
</a>

# MiniLibX

### *¿Cómo usar MiniLibX?*
En la intra se nos da acceso a diferentes carpetas comprimidas con diferentes versiones de la librería. Cada una tiene su makefile, así que deberemos usar el comando make para compilarlas antes de usarlas.

Para usarla en mac, al compilar nuestros archivos deberemos usar las siguientes flags:

`-Lmlc -lmlx -framework OpenGL -framework Appkit`

## Funciones MLX

### *mlx_init*
`mlx_init();`
Iniciliza una conexión con el servidor gráfico y crea una estructura de datos necesaria para el uso de miniLibX.

Será nuestra primera función a utilizar. Se usa sobre un `void *` y devuelve la dirección donde la librería va a estar almacenando las cosas de nuestro mlx.

### *mlx_new_window*

`void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);`

Crea una nueva ventana en la pantalla con un tamaño y posición específicos.

Recibe: el puntero `mlx_ptr` de conexión con el servidor gráfico, que es el que hemos creado al llamar a init, los tamaños de los ejes x e y, y el título que tendrá la ventana. Devuelve un puntero a la dirección donde se encuentra la ventana a crear.

### *mlx_loop*

`int mlx_loop(void *mlx_ptr);`

Inicia el bucle principal de eventos, que permite que la ventana sea interactiva y responda a las acciones del usuario.

## Funciones de manejo de imágenes

### *mlx_xpm_file_to_image*





