//                                                           ivan david moreno vargas


#include "../salud/persona.h"//agregar la clase persona con todos sus metodos y atributos



int main()//creamso el main aqui
{
    persona persona1 = persona::pedirDatos();//objeto persona1 va a ser lo que se haga en pedir datos
    persona1.mostrarPersona(persona1);//mostrar persona toma el objeto persona 1 como parametro

    static float peso_final=persona1.calcularmc(persona1.getPeso(),persona1.getEstatura());//toma el valor de retorno del metodo calcularmc

    if (peso_final < 20) // hace el analisis del peso
        {
            cout << "peso bajo" << endl;
        }
        else if (peso_final <= 25 && peso_final > 20)
        {
            cout << "peso ideal" << endl;
        }
        else
        {
            cout << "sobrepeso" << endl;
        }

    return 0;
}