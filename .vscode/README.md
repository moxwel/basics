# Utilidad para depuración en VSCode

- `extensions.json` : Extensiones requeridas

- `tasks.json` : Tareas de compilación

- `launch.json` : Instrucciones de depuración

## Tasks.json

Aqui se dejan las instrucciones de compilacion para los archivos. Es necesario compilar el codigo antes de depurarlo.

Actualmente solo se tienen instrucciones para compilar en un entorno Linux.

## Launch.json

Aqui se dejan las instrucciones de depuracion para los archivos. Trabaja junto con `tasks.json`, y es el responsable de ejecutar el depurador.

---

## Instalación

Arrastra la carpeta `.vscode` a la carpeta raiz de tu proyecto. Luego, en la seccion *"Ejecutar"* de VSCode, puedes ver las opciones de depuración disponibles.

> ⚠ Asegurate de tener la extension de C/C++ instalada. Es necesario para poder depurar codigo.

---

## Solución de problemas

Si al intentar depurar resulta en errores, prueba a reinstalar GCC y GDB:

- `sudo apt install gcc`
- `sudo apt install gdb`
