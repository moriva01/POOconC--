#include "persona.h" //imprtar persona.h para heredar sus metodos y atributos

class usuario : public persona // clase usuario
{

private: // atributos de la clase
    int long long numero_celular;
    int contrasena;
    float saldo;

public:
    usuario() {} // constructor vacio
    // --------------------------------------- setters--------------------------------------------------------------------

    void setNumeroCelular(long long numero)
    {
        numero_celular = numero;
    }

    void setContrasena(int contrasena)
    {
        this->contrasena = contrasena;
    }

    void setSaldo(float saldo)
    {
        this->saldo = saldo;
    }
    // ------------------------------- getters ----------------------------------------------

    long long getNumeroCelular() const
    {
        return numero_celular;
    }

    int getContrasena() const
    {
        return contrasena;
    }

    float getSaldo()
    {
        return saldo;
    }
};