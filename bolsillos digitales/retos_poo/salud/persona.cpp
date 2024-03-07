#include <iostream>

using namespace std;

class persona
{

private:
    string tipo_doc;
    long long documento;
    string nombre;
    string apellido;
    float peso;
    float estatura;
    int edad;
    bool sexo;

public:
    persona() {}

    static persona pedirDatos()
    {
        persona persona;
        cout << "tipo de documento: ";
        cin >> persona.tipo_doc;
        cout << "numero de documento: ";
        cin >> persona.documento;
        cout << "nombre: ";
        cin >> persona.nombre;
        cout << "apellido: ";
        cin >> persona.apellido;
        cout << "peso (kg): ";
        cin >> persona.peso;
        cout << "estatura (m): ";
        cin >> persona.estatura;
        cout << "edad: ";
        cin >> persona.edad;
        cout << "sexo" << endl
             << " --0 para femenino" << endl
             << "--1 para masculino ";
        cin >> persona.sexo;

        return persona;
    }

    void calcularmc(float peso, float estatura)
    {

        float peso_final = peso / (estatura * estatura);

        if (peso_final < 20)
        {
            cout << "peso debajo de lo ideal" << endl;
        }
        else if (peso_final <= 25 && peso_final > 20)
        {
            cout << "peso es ideal" << endl;
        }
        else
        {
            cout << "sobre peso" << endl;
        }
    }

    void mayorEdad(int edad)
    {

        if (edad >= 18)
        {

            cout << "--- mayor de edad" << endl;
        }
        else
        {

            cout << "--- menor de edad" << endl;
        }
    }

    void mostrarPersona(persona aux)
    {

        cout << "-------------------------------------------------- " << endl;
        cout << "------------- tipo de documento: " << aux.tipo_doc << endl;
        cout << "------------- numero de documento: " << aux.documento << endl;
        cout << "------------- nombre: " << aux.nombre << endl;
        cout << "------------- apellido: " << aux.apellido << endl;
        cout << "------------- peso (kg): " << aux.peso << endl;
        cout << "------------- estatura (m) " << aux.estatura << endl;
        cout << "------------- edad: " << aux.edad << endl;

        if (aux.sexo == 0)
        {
            cout << "------------- sexo: Femenino " << endl;
        }
        else
        {

            cout << "------------- sexo: Masculino " << endl;
        }

        cout << "-------------------------------------------------- " << endl;
        cout << "segun su masa corporal:" << endl;

        aux.calcularmc(aux.peso, aux.estatura);
        aux.mayorEdad(aux.edad);
    }
};

int main()
{

    persona persona1 = persona::pedirDatos();

    persona1.mostrarPersona(persona1);

    return 0;
}