#include <iostream>
#include "ABBPolinomio.h"

using namespace std;

int main()
{
    Arbol abb;
    ListaParam l = NULL;
    String s, nombreNuevo;
    Polinomio p, resu, a, b;
    EnumComandos ec;
    InicializarArbol(abb);
    int x;

    printf("Ingrese comando: ");
    Scan(s);
    Parsear(s, l);
    ec = ValidarComando(l->info);
    l = l->sig;

    //Vuelvo a solicitar un comando hasta que indique que quiere salir
    while(ec != SALIR)
    {
        switch(ec)
        {
            case CREAR:
                if(l != NULL)
                {
                    if(!ExistePolinomio(abb, l->info))
                    {
                        if(EsValidoNombre(l->info))
                        {
                            Crear(p, l);
                            InsPoliABBPoli(abb, p);
                            MostrarMensaje(OK);
                        }
                        else
                        {
                            MostrarMensaje(NOMBRE_INVALIDO);
                        }
                    }
                    else
                    {
                        MostrarMensaje(YA_EXISTE);
                    }
                }
                else
                {
                    MostrarMensaje(NO_INGRESO_NOMBRE);
                }
            break;
            case SUMAR:
                if(ExistePolinomio(abb, l->info))
                {
                    a = DarPolinomio(abb, l->info);
                    l = l->sig;
                    if(ExistePolinomio(abb, l->info))
                    {
                        b = DarPolinomio(abb, l->info);
                        l = l->sig;
                        StrCop(nombreNuevo,l->info);
                        if(!ExistePolinomio(abb, nombreNuevo))
                        {
                            SumarPoli(a, b, resu, nombreNuevo);
                            InsPoliABBPoli(abb, resu);
                            MostrarMensaje(OK);
                        }
                        else
                        {
                            MostrarMensaje(YA_EXISTE);
                        }
                    }
                    else
                    {
                        MostrarMensaje(NO_EXISTE_POLINOMIO);
                    }
                }
                else
                {
                    MostrarMensaje(NO_EXISTE_POLINOMIO);
                }
                break;
            case EVALUAR:
                if(CantParametros(l) == 2)
                {
                    if(EsValidoNombre(l->info))
                    {
                        if(ExistePolinomio(abb,l->info))
                        {
                            p = DarPolinomio(abb,l->info);
                            l=l->sig;
                            if(EsValidoNumero(l->info))
                            {
                                x = ConvertirCharANumero(l->info);
                                //Reutilizo x
                                x = EvaluarPoli(p, x);
                                printf("Resultado = %d", x);
                            }
                            else
                            {
                                MostrarMensaje(NUMERO_INVALIDO);
                            }
                        }
                        else
                        {
                            MostrarMensaje(NO_EXISTE_POLINOMIO);
                        }
                    }
                    else
                    {
                        MostrarMensaje(NOMBRE_INVALIDO);
                    }
                }
                else
                {
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                }
                break;
            case MOSTRAR: MostrarABBPoli(abb);
                break;
            case SALIR:
                break;
            case MULTIPLICAR:
                if (CantParametros(l) == 3)
                {
                    if(EsValidoNombre(l->info))
                    {
                        if(!ExistePolinomio(abb,l->info))
                        {
                            StrCop(nombreNuevo,l->info);
                            l=l->sig;
                            if(EsValidoNombre(l->info))
                            {
                                if(ExistePolinomio(abb,l->info))
                                {
                                    a = DarPolinomio(abb,l->info);
                                    l=l->sig;
                                    if(EsValidoNombre(l->info))
                                    {
                                        if(ExistePolinomio(abb,l->info))
                                        {
                                            b = DarPolinomio(abb,l->info);
                                            MultiplicarPoli(a,b,resu,nombreNuevo);
                                            InsPoliABBPoli(abb, resu);
                                            MostrarMensaje(OK);
                                        }
                                        else
                                        MostrarMensaje(NO_EXISTE_POLINOMIO);
                                    }
                                    else
                                        MostrarMensaje(NOMBRE_INVALIDO);
                                }
                                else
                                    MostrarMensaje(NO_EXISTE_POLINOMIO);
                            }
                            else
                                MostrarMensaje(NOMBRE_INVALIDO);
                        }
                        else
                            MostrarMensaje(YA_EXISTE);
                    }
                    else
                        MostrarMensaje(NOMBRE_INVALIDO);
                }
                else
                    MostrarMensaje(PARAMETROS_INVALIDOS);
                break;
            default:
                MostrarMensaje(COMANDO_INVALIDO);
            break;
        }

        l = NULL;
        printf("\n\n");
        printf("Ingrese comando: ");
        Scan(s);
        Parsear(s, l);
        ec = ValidarComando(l->info);
        l = l->sig;
    }
}
