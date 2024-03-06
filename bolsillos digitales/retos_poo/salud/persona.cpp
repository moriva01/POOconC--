#include <iostream>
#include <string>

using namespace std;

class persona
{

private:
    string tipo_doc;
    int long long documento;
    string nombre;
    string apellido;
    float peso;
    float estatura;
    int edad;
    bool sexo;

public:
    persona() {}

    void pedir_dato()
    {
        string aux_a;
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

    void peso_actual(float peso, float estatura)
    {
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
        float a = aux.estatura;
        float b = aux.peso;

        cout << "tipo documento " << aux.tipo_doc << endl;
        cout << "documento " << aux.documento << endl;
        cout << "nombre " << aux.nombre << endl;
        cout << "apellido " << aux.apellido << endl;
        cout << "peso " << b << endl;
        cout << "estatura " << a << endl;
        cout << "edad " << aux.edad << endl;
        cout << "sexo " << aux.sexo << endl;
        aux.peso_actual(b, a);
    }
};

int main()
{

    persona persona1;
    persona1.pedir_dato();
    persona1.mostrar_persona(persona1);

    return 0;
}