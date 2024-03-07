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

    static persona ingresar_persona()
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
        cout << "estatura (cm): ";
        cin >> persona.estatura;
        cout << "edad: ";
        cin >> persona.edad;
        cout << "sexo: --0 para femenino"<<endl<<"--1 para masculino): ";
        cin >> persona.sexo;

        return persona;
    }
};

int main()
{

    persona persona1 = persona::ingresar_persona();

    return 0;
}