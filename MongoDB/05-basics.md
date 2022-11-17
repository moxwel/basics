# 05 - Comandos basicos

## Listar bases de datos

Utiliza el comando `show databases` o `show dbs` para listar todas las bases de datos disponibles.

```
test> show databases

admin     40.00 KiB
config    72.00 KiB
local     72.00 KiB
```

Notese que la base de datos `test` en la que supuestamente estamos ubicados no aparece. MongoDB automaticamente ignora las bases de datos que estan vacías (es
decir, sin colecciones ni documentos).

## Usar otra base de datos

Para utilizar otra base de datos, usamos el comando `use <nombreDB>`.

```
test> use miTienda

switched to db miTienda

miTienda>
```

## Listar colecciones

Para ver la lista de colecciones de una base de datos, se debe usar el comando `show collections` o `show tables`.
