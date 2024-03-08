//                 se cambia a .h para poder importardesde otros paquetes

#include <iostream> //el iostream de toda la vida

using namespace std; // lo mismo el espacio de trabajo

class usuario // clase usuario
{

private: // atributos de la clase
    string nombre_usuario;
    string apellido_usuario;
    string correo_usuario;
    int tipo_documento;
    int long long numero_documento;
    int long long numero_celular;
    int contrasena;
    float colchon;
    float meta;
    float bolsillo;
    float saldo;

public:
    usuario(string nombre_usuario, // constructor no vacio de la clase
            string apellido_usuario,
            string correo_usuario,
            int tipo_documento,
            int long long numero_documento,
            int long long numero_celular,
            int contrasena,
            float colchon,
            float meta,
            float bolsillo,
            float saldo)
    {

        this->nombre_usuario = nombre_usuario;
        this->apellido_usuario = apellido_usuario;
        this->correo_usuario = correo_usuario;
        this->tipo_documento = tipo_documento;
        this->numero_documento = numero_documento;
        this->numero_celular = numero_celular;
        this->contrasena = contrasena;
        this->colchon = colchon;
        this->meta = meta;
        this->bolsillo = bolsillo;
        this->saldo = saldo;
    }

    usuario() {} // constructor vacio
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

    void setNumeroCelular(long long numero)
    {
        numero_celular = numero;
    }

    void setContrasena(int contrasena)
    {
        this->contrasena = contrasena;
    }

    void setColchon(float colchon)
    {
        this->colchon = colchon;
    }

    void setMeta(float meta)
    {
        this->meta = meta;
    }

    void setBolsillo(float bolsillo)
    {
        this->bolsillo = bolsillo;
    }

    void setSaldo(float saldo)
    {
        this->saldo = saldo;
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

    long long getNumeroCelular() const
    {
        return numero_celular;
    }

    int getContrasena() const
    {
        return contrasena;
    }

    float getColchon() const
    {
        return colchon;
    }
    float getMeta() const
    {
        return meta;
    }
    float getBolsillo() const
    {
        return bolsillo;
    }
    float getSaldo() const
    {
        return saldo;
    }
};