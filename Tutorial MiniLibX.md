<a href="https://github.com/erivero-p/42-Tutorials/blob/master/About%20MiniLibX/Cómo%20y%20para%20qué%20usar%20MiniLibx.md">
✨ Tutorial hecho por la grandísima erivero-p ✨
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
`void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);`

Permite cargar una imagen en formato XPM desde un archivo y crear una estructura de imagen en memoria (XPM es un formato de imagen en texto plano que se utiliza comúnmente en aplicaciones gráficas). 

Recibe el puntero `mlx_ptr`, una cadena de caracteres `filename` con la ruta y el nombre del archivo .xpm, y dos punteros a int donde se almacenarán las dimensiones de la imagen cargada.

Una vez ha cargado la imagen en nuestra memoria, devuelve un puntero al área de memoria deonde la ha cargado.

### *mlx_put_image_to_window*
`int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);`

Una vez que hemos pasado el *sprite* que teníamos en .xpm a imagen, la función anterior no cara la imagen en la ventana. Para hacerlo, debemos llamar a mlx_put_image_to_window.

Esta función recibe, además del puntero `mlx_ptr`, y el puntero a la ventana `win_ptr`, el puntero a la imagen `img_ptr` que resulta de usar la función anterior, y dos enteros: x e y con las coordenadas en las que colocar la imagen.

Hay que tener en cuenta el orden en que colocamos las imágenes en la ventana, considerando que van a mostrarse de abajo a arriba en orden de procesador.

### *Otras*
- **mlx_new_image**: Crea una imagen en memoria con un tamaño específico.
- **mlx_get_data_addr**: Obtiene un puntero a los datos de la imagen. Permite acceder y modificar los píxeles directamente en la memoria.
- **mlx_destroy_image**: Libera la mempria utilizada por una imagen creada con `mlx_new_image`.

## Funciones de manejo de eventos de teclado y ratón

### *mlx_loop*
`int mlx_loop(void *mlx_ptr);`

Se utiliza para iniciar el bucle principal de eventos. Esta función es responsable de procesar y gestionar los eventos de la ventana, como interacciones del usuario, teclas pulsadas, eventos de ratón, redibujado de la ventana, entre otros.

Generalmente se llama después de haber configurado la ventana, los eventos y otros elementos necesarios para la aplicación gráfica. Una vez llamada, el bucle de eventos se inicia y se ejecuta de forma continua hasta que se produzca una acción que detenga la ejecución del programa, como cerrar la ventana.

### *mlx_key_hook*
`int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);`

Permite asignar una función de control de eventos a una acción específica del teclado.

Es decir, es la función con la que indicaremos qué hay que hacer cuando, mientras nuestro programa esté en ejecución, y por tanto la ventana esté abierta, se pulse una tecla.

Recibe como parámetro el `win_ptr`, la función de control de eventos `funct_ptr` que se tiene que ejecutar, y un puntero `param` a un parámetro adicional y opcional.

`int funct_ptr(int keycode, void *param);`

La función de control de eventos, a su vez, recibe un entero con el KEY CODE de la tecla presionada, y un puntero al parámetro adicional `param`.

- Las Keycodes de MacOs

    ![Untitled](https://eastmanreference.com/img/complete-list-of-applescript-key-codes-t.png)








