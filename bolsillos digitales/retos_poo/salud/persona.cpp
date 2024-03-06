#include <iostream>
#include <string>

using namespace std;

class persona
{

private:
    char tipo_doc;
    int long long documento;
    string nombre;
    string apellido;
    float peso;
    float estatura;
    int edad;
    bool sexo;

public:
    /*persona(char a, int long long b, string c, string d, float e, float f, int g, bool h)
    {
        tipo_doc = a;
        documento = b;
        nombre = c;
        apellido = d;
        peso = e;
        estatura = f;
        edad = g;
        sexo = h;
    }*/

    void pedir_dato()
    {
        char aux_a;
        int long long aux_b;
        string aux_c;
        string aux_d;
        float aux_e;
        float aux_f;
        int aux_g;
        bool aux_h;

        cout << "tipo documento" << endl;
        cin >> aux_a;
        cout << "documento" << endl;
        cin >> aux_b;
        cout << "nombre" << endl;
        cin >> aux_c;
        cout << "apellido" << endl;
        cin >> aux_d;
        cout << "peso" << endl;
        cin >> aux_e;
        cout << "estatura" << endl;
        cin >> aux_f;
        cout << "edad" << endl;
        cin >> aux_g;
        cout << "sexo" << endl;
        cin >> aux_h;

        persona aux_obj(char aux_a, int long long aux_b, string aux_c, string aux_d, float aux_e, float aux_f, int aux_g, bool aux_h);
    }

    void peso_actual(persona aux)
    {

        float peso = aux.peso;
        float estatura = aux.estatura;
        float peso_final = peso / estatura;

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

    void mostrar_persona(persona aux)
    {

        cout << "tipo documento " << aux[i].tipo_doc << endl;
        cout << "documento " << aux[i].documento << endl;
        cout << "nombre " << aux[i].nombre << endl;
        cout << "apellido " << aux[i].apellido << endl;
        cout << "peso " << aux[i].peso << endl;
        cout << "estatura " << aux[i].estatura << endl;
        cout << "edad " << aux[i].edad << endl;
        cout << "sexo " << aux[i].sexo << endl;

        aux[i].peso_actual(aux[i].peso, aux[i].estatura);
    }
};

int main()
{

    persona persona1;

    persona1.pedir_dato;
    persona1.mostrar_persona;

    return 0;
}