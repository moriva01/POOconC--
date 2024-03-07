#include <iostream>

using namespace std;

class usuario
{

private:
    string nombre_usuario;
    string apellido_usuario;
    string correo_usuario;
    int tipo_documento;
    int long long numero_documento;
    int long long numero_celular;
    int contrasena;

public:
    usuario(string nombre_usuario,
            string apellido_usuario,
            string correo_usuario,
            int tipo_documento,
            int long long numero_documento,
            int long long numero_celular,
            int contrasena)
    {

        this->nombre_usuario = nombre_usuario;
        this->apellido_usuario = apellido_usuario;
        this->correo_usuario = correo_usuario;
        this->tipo_documento = tipo_documento;
        this->numero_documento = numero_documento;
        this->numero_celular = numero_celular;
        this->contrasena = contrasena;
    }
};