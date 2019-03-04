#ifndef ENUMMENSAJES_H_INCLUDED
#define ENUMMENSAJES_H_INCLUDED

typedef enum {OK, NOMBRE_INVALIDO, NUMERO_INVALIDO, COMANDO_INVALIDO, YA_EXISTE, NO_EXISTE_POLINOMIO, NO_INGRESO_NOMBRE, NO_INGRESO_TERMINO,
PARAMETROS_INVALIDOS, ABB_VACIO, CERRAR, BIENVENIDA, INGRESO, GUARDADO} TipoMensaje;

void MostrarMensaje(TipoMensaje tipo);

#endif // ENUMMENSAJES_H_INCLUDED
