// Para poder exportar variables o funciones desde este archivo se debe utilizar con 'export'.

export const nombreArchivo = "Archivo de Prueba 1";

export const mensaje = () => {console.log("Este mensaje se ha impreso gracias a '01-export.js'.")};

export const sumarNumeros = (x,y) => {return x+y};

export const restarNumeros = (x,y) => {return x-y};

// Si no se añade 'export' a alguna variable, no se podra importar en otro archivo.

const otraVariable = "Esta variable no esta exportada";

// Para exportar un elemento por defecto, se debe utilizar la palabra 'default' antes de 'export'.

export default function funcionDefecto() {console.log("Elemento por defecto.")};

// Solo se puede exportar un unico elemento por defecto, por archivo.

// Si se desea importar el elemento por defecto, no se debe usar llaves '{}'.
// Tampoco se puede hacer referencia por nombre al elemento exportado por defecto.
