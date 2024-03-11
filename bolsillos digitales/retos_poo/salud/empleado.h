#include "persona.h"

class empleado : public persona
{

private:
    string cargo;
    float valor_hora;
    int horas_trabajadas;
    string departamento;

public:
    empleado() {}

    // ------------------------------------------------------------------------------- Setters
    void setCargo(string c)
    {
        cargo = c;
    }

    void setValorHora(float v)
    {
        valor_hora = v;
    }

    void setHorasTrabajadas(int h)
    {
        horas_trabajadas = h;
    }

    void setDepartamento(string d)
    {
        departamento = d;
    }

    // --------------------------------------------------- Getters
    string getCargo()
    {
        return cargo;
    }

    float getValorHora()
    {
        return valor_hora;
    }

    int getHorasTrabajadas()
    {
        return horas_trabajadas;
    }

    string getDepartamento()
    {
        return departamento;
    }

    //----------------------------------------------------- Metodos

    float calcularHonorarios()
    {

        float aux = (this->horas_trabajadas * this->valor_hora);
        float reteica = (aux * 0.966) / 100;
        aux -= reteica;

        return aux;
    }

    static empleado pedirDatos() // metodo que pide datos
    {
        empleado empleado; // inicializa objeto auxiliar
        cout << "tipo de documento: ";
        string aux1;
        cin >> aux1;
        empleado.setTipoDoc(aux1); // pide los datos
        cout << "numero de documento: ";
        int long long aux2;
        cin >> aux2;
        empleado.setDocumento(aux2);
        cout << "nombre: ";
        string aux3;
        cin >> aux3;
        empleado.setNombre(aux3);
        cout << "apellido: ";
        string aux4;
        cin >> aux4;
        empleado.setApellido(aux4);
        cout << "peso (kg): ";
        float aux5;
        cin >> aux5;
        empleado.setPeso(aux5);
        cout << "estatura (m): ";
        float aux6;
        cin >> aux6;
        empleado.setEstatura(aux6);

        cout << "edad: ";
        int aux7;
        cin >> aux7;
        empleado.setEdad(aux7);
        cout << "sexo" << endl
             << " --0 para femenino" << endl
             << "--1 para masculino ";
        bool aux8;
        cin >> aux8;
        empleado.setSexo(aux8);

        cout << "cargo: ";
        string aux9;
        cin >> aux9;
        empleado.setCargo(aux9);
        cout << "valor hora: ";
        float aux11;
        cin >> aux11;
        empleado.setValorHora(aux11);

        cout << "horas trabajadas: ";
        int aux10;
        cin >> aux10;
        empleado.setHorasTrabajadas(aux10);
        cout << "departamento: ";
        string aux12;
        cin >> aux12;
        empleado.setDepartamento(aux12);

        return empleado; // retorna el objeto
    }

       int mayorEdad(int an1, int an2) // metodo saber si es mayor de edad entra edad como parametro
    {
        int edad=an2-an1;

        /*if (edad >= 18) // revias sea mayor de edad
        {

            cout << "--- mayor de edad" << endl;
        }
        else
        {

            cout << "--- menor de edad" << endl;
        }*/
        return edad;
    }

    void mostrarPersona(empleado aux) // metodo mostrar persona, entra objeto persona como parametro
    {

        cout << "-------------------------------------------------- " << endl; // imprime todo eso
        cout << "------------- tipo de documento: " << aux.getTipoDoc() << endl;
        cout << "------------- numero de documento: " << aux.getDocumento() << endl;
        cout << "------------- nombre: " << aux.getNombre() << endl;
        cout << "------------- apellido: " << aux.getApellido() << endl;
        cout << "------------- peso (kg): " << aux.getPeso() << endl;
        cout << "------------- estatura (m) " << aux.getEstatura() << endl;
        cout << "------------- edad: " << aux.getEdad() << endl;

        if (aux.getSexo() == 0) // revisa si es masculino o femenino
        {
            cout << "------------- sexo: Femenino " << endl;
        }
        else
        {

            cout << "------------- sexo: Masculino " << endl;
        }

        cout << "------------- cargo: " << aux.getCargo() << endl;
        cout << "------------- valor hora: " << aux.getValorHora() << endl;
        cout << "------------- horas trabajadas: " << aux.getHorasTrabajadas() << endl;
        cout << "------------- departamento: " << aux.getDepartamento() << endl;

        cout << "-------------------------------------------------- " << endl;
      //  cout << "------------- segun su masa corporal:" << endl;

       // aux.calcularmc(aux.peso, aux.estatura); // instancia el metodo de masa corporal

        //cout << "------------- segun su edad:" << endl;
        //aux.mayorEdad(aux.getEdad()); // instancia metodo de la mayoria de edad
    }
};