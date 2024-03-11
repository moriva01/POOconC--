//                                                           ivan david moreno vargas

// #include "../salud/persona.h"  //agregar la clase persona con todos sus metodos y atributos
#include "../salud/empleado.h" //agregar la clase empleado con todos sus metodos y atributos

int main() // creamso el main aqui
{
    cout << "datos persona:  " << endl;
    persona persona1 = persona::pedirDatos(); // objeto persona1 va a ser lo que se haga en pedir datos
                                              // empleado empleado1("cc",987654321,"juan","perez",45.0,1.50,25,false,"operario",8000,36,"IT");
    cout << "------------------------------------------------------------------------------------- datos persona:" << endl;
    persona1.mostrarPersona(persona1); // mostrar persona toma el objeto persona 1 como parametro

    static float peso_final = persona1.calcularmc(persona1.getPeso(), persona1.getEstatura()); // toma el valor de retorno del metodo calcularmc

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
    cout << "----------------------------------------------------------------------------------- datos empleado:" << endl;
    cout << "datos empleado:  " << endl;
    empleado empleado1 = empleado ::pedirDatos();
    empleado1.mostrarPersona(empleado1);
    int a, b;
    cout << "digite su año de nacimiento: " << endl;
    cin >> a;
    cout << "digite el año actual: " << endl;
    cin >> b;
    static int anio = empleado1.mayorEdad(a, b);

    if (anio >= 18) // revias sea mayor de edad
    {

        cout << "--- mayor de edad" << endl;
    }
    else
    {

        cout << "--- menor de edad" << endl;
    }

    cout<<"Honorarios de la semana: "<<empleado1.calcularHonorarios();

    return 0;
}