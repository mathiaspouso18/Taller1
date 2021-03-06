#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"
#include "EnumMensajes.h"
#include <stdio.h>

const int MAX = 80;
typedef char * String;

/* devuelve el largo del string s */
int StrLar (String s);

/* Convierte un char a numero */
int ConvertirCharANumero(String s);

Boolean EsValidoNombre(String s);

Boolean EsValidoNumero(String s);

Boolean EsMayor(String s1, String s2);

Boolean ExisteArchivo(String s);

Boolean EsCaracterValido(char c);

/* compara dos strings */
Boolean StrEq(String s1, String s2);

void LowerCase(String &s);

void Guardar_String (String s, FILE * f) ;

void Levantar_String (String &s, String nomArch);

void IntToString(String &s, int num);

/* imprime el string s por pantalla */
void Print (String s);

/* copia el contenido del string s2 en s1 */
void StrCop (String &s1, String s2);

/* lee el string s desde teclado */
void Scan (String &s);

/* concatena el contenido de s2 al final de s1 */
void StrCon (String &s1, String s2);

/* intercambia los contenidos de s1 y s2 */
void StrSwp (String &s1, String &s2);

/* crea un string vacío */
void StrCrear (String &s);

/* libera la memoria usada por el string */
void StrDestruir (String &s);

#endif // STRING_H_INCLUDED
