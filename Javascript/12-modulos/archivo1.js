// Para poder exportar variables o funciones desde este archivo se debe utilizar con 'export'.
export const nombreArchivo = "Archivo de Prueba 1";

export const mensaje = () => {console.log("Este mensaje se ha impreso gracias a 'archivo1.js'.")};

export const sumarNumeros = (x,y) => {return x+y};

// Si no se añade 'export' a alguna variable, no se podra importar en otro archivo.

const otraVariable = "Esta variable no esta exportada";
