#include "persona.h"

class usuario : public persona // clase usuario
{

private: // atributos de la clase
    int long long numero_celular;
    int contrasena;
    float colchon;
    float meta;
    float bolsillo;
    float saldo;

public:
    /*usuario(

        int long long numero_celular, // constructor con parametros de la clase
        int contrasena,
        float colchon,
        float meta,
        float bolsillo,
        float saldo)
    {

        this->numero_celular = numero_celular;
        this->contrasena = contrasena;
        this->colchon = colchon;
        this->meta = meta;
        this->bolsillo = bolsillo;
        this->saldo = saldo;
    }*/

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
    float getSaldo()
    {
        return saldo;
    }
};