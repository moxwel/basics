# txtdb (mysql)

Un front-end para manejar una base de datos en MySQL.

Hecho en PHP usando XAMPP para probar unas cosas.

---

La pagina principal se encuentra en: `/page/home.php`. De todas formas `index.php` te va a redireccionar al inicio.

Por defecto, necesita poseer MySQL en `localhost`, usando `root` sin contraseña. El nombre de la base de datos es `txtdb`, con una tabla `datos`.

Puedes cambiar esos datos en `include/db.php`.

---

Si usas phpMyAdmin, puedes importar la estructura SQL usando el archivo `txtdb.sql`.
