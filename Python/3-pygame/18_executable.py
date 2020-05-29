#Primero hay que importar el modulo de cx_Freeze
import cx_Freeze
import os
os.environ['TCL_LIBRARY'] = "C:\\Python37\\tcl\\tcl8.6"
os.environ['TK_LIBRARY'] = "C:\\Python37\\tcl\\tk8.6"
#NOTA: para que al cerrar el programa no de errores, se recomienda usar el modulo "sys" (import sys) y usar el comando sys.exit() para salir del programa.

#Estas variables son las que puedes modificar para poder compilar un programa. El resto lo haran los comandos mas abajo. Por ahora, puedes utilizar este script como plantilla para compilar otros programas.

#El archivo python que se quiere compilar
archivo_py      = "SnakeByMox.py"
#El nombre del archivo ejecutable
nombre_exe      = "SerpienteMox"
#El numero de version
version_exe     = "1.0"
#Una descripcion
descripcion_exe = "Descripcion shida"
#La base del sistema a la que se va a compilar el ejecutable
base_exe        = "Win32GUI"
#Los paquetes (o modulos) externos que se utilizaron
paquetes        = ["pygame"]
#Los archivos que se utilizan en el programa, hay que nombrarlos todos por su direccion relativa
archivos        = ["apple.ogg","apple2.ogg","apple3.ogg","crash.ogg","crash2.ogg","determination.ttf","fondo.png","fondo2.png","fondo3.png","fondo4.png","game_over.png","intro.ogg","keys.png","music.ogg","pause.png","snake_icon.gif"]

#Aqui comienza la maquina que compila todo.
executables_options = [
    cx_Freeze.Executable(
        archivo_py,
        base = base_exe
        )
]

build_exe_options = {
    "packages"      : paquetes,
    "include_files" : archivos
}

cx_Freeze.setup(
    name        = nombre_exe,
    version     = version_exe,
    description = descripcion_exe,
    options     = {"build_exe": build_exe_options},
    executables = executables_options
)