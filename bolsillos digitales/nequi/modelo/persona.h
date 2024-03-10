#include <iostream> //metodos de entrada y salida por teclado

using namespace std; // espacio de trabajo

class persona // clase usuario
{

private: // atributos de la clase
    string nombre_usuario;
    string apellido_usuario;
    string correo_usuario;
    int tipo_documento;
    int long long numero_documento;

public:
    persona() {} // constructor vacio
    // --------------------------------------- setters--------------------------------------------------------------------
    void setNombreUsuario(const string &nombre)
    {
        nombre_usuario = nombre;
    }

    void setApellidoUsuario(const string &apellido)
    {
        apellido_usuario = apellido;
    }

    void setCorreoUsuario(const string &correo)
    {
        correo_usuario = correo;
    }

    void setTipoDocumento(int tipo)
    {
        tipo_documento = tipo;
    }

    void setNumeroDocumento(long long numero)
    {
        numero_documento = numero;
    }

    // ------------------------------- getters ----------------------------------------------
    string getNombreUsuario() const
    {
        return nombre_usuario;
    }

    string getApellidoUsuario() const
    {
        return apellido_usuario;
    }

    string getCorreoUsuario() const
    {
        return correo_usuario;
    }

    int getTipoDocumento() const
    {
        return tipo_documento;
    }

    long long getNumeroDocumento() const
    {
        return numero_documento;
    }
};