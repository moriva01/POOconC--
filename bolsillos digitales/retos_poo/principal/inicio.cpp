//                                                           ivan david moreno vargas

#include "../salud/persona.h"  //agregar la clase persona con todos sus metodos y atributos
#include "../salud/empleado.h" //agregar la clase empleado con todos sus metodos y atributos

int main() // creamso el main aqui
{
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
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;

    empleado empleado1;
    empleado1.setTipoDoc("cc");
    empleado1.setDocumento(987654321);
    empleado1.setNombre("juan andres");
    empleado1.setApellido("perez gomez");
    empleado1.setCargo("operario");
    empleado1.setHorasTrabajadas(36);
    empleado1.setValorHora(8500);

    cout<<"empelado -----------------------"<<endl;
    cout<<"-- "<<empleado1.getTipoDoc()<<"       - "<<empleado1.getDocumento()<<endl;
    cout<<"-- Nombre: "<<empleado1.getNombre()<<" "<<empleado1.getApellido()<<endl;
    cout<<"-- Cargo: "<<empleado1.getCargo()<<"     -- Horas trabajadas: "<<empleado1.getHorasTrabajadas()<<"    --Valor por hora: "<<empleado1.getValorHora()<<endl;
    cout<<"-- Total a pagar: "<<empleado1.calcularHonorarios()<<endl;



    return 0;
}