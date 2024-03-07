#include "../salud/persona.h"//agregar la clase persona con todos sus metodos y atributos



int main()//creamso el main aqui
{
    persona persona1 = persona::pedirDatos();//objeto persona1 va a ser lo que se haga en pedir datos
    persona1.mostrarPersona(persona1);//mostrar persona toma el objeto persona 1 como parametro

    return 0;
}