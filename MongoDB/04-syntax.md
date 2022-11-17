# 04 - Sintaxis

La sintaxis que utilizan las consultas de MongoDB son muy similares a Javascript.

De hecho, la consola de Mongosh es un interpete de Javascript, puede ejecutar comandos
basicos y realizar operaciones numericas, definir variables, etc.

## Comandos

Para obtener ayuda con los comandos de MongoDB, se puede utilizar el metodo `help()`.

Los comandos que aparecen en esa lista son **exclusivos** de MongoDB, son para utilizarse en
un shell de Mongo.

## Objetos

En la consola de Mongosh, siempre existira un objeto (o clase) llamado `db`, que posee atributos
y otros objetos, como tambien metodos. Es como si se tratase de un objeto Javascript, y se manipula
de la misma manera.

> **NOTA**: Prueba a poner `db.help()` en consola. Obtendras todos los metodos asociados al
objeto `db`. De hecho, ahora mismo estas usando el metodo `help()` del objeto `db`.

En escencia, `db` representa la base de datos que actualmente estemos usando.

## Consola

¿Notas que en la entrada de la consola dice `test>`? Alli se muestra la base de datos que estas utilizando
ahora mismo; en este caso, estas ubicado en la base de datos llamado `test`. Este es el por defecto cuando
creas MongoDB por primera vez.
