<a href="https://github.com/erivero-p/42-Tutorials/blob/master/About%20MiniLibX/Cómo%20y%20para%20qué%20usar%20MiniLibx.md">
✨ Tutorial hecho por la grandísima erviro-p ✨
</a>

#MiniLibX

### *¿Cómo usar MiniLibX?*
En la intra se nos da acceso a diferentes carpetas comprimidas con diferentes versiones de la librería. Cada una tiene su makefile, así que deberemos usar el comando make para compilarlas antes de usarlas.

Para usarla en mac, al compilar nuestros archivos deberemos usar las siguientes flags:

`-Lmlc -lmlx -framework OpenGL -framework Appkit`

##Funciones MLX

### *mlx_init*
Iniciliza una conexión con el servidor gráfico y crea una estructura de datos necesaria para el uso de miniLibX.

Será nuestra primera función a utilizar. Se usa sobre un `void *` y devuelve la dirección donde la librería va a estar almacenando las cosas de nuestro mlx.

### *mlx_new_window*
