#include "persona.h"

class usuario : public persona // clase usuario
{

private: // atributos de la clase
    int long long numero_celular;
    int contrasena;
    float colchon;
    float meta[2];
    float bolsillo[3];
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

    void setMeta(float m1, float m2)
    {
        meta[0] = m1;
        meta[1] = m2;
    }

    void setBolsillo(float b1, float b2, float b3)
    {
        bolsillo[0] = b1;
        bolsillo[1] = b2;
        bolsillo[2] = b3;
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
    float getMeta(int i) const
    {
        return meta[i];
        
    }
    float getBolsillo(int i)
    {
        return bolsillo[i];
    }
    float getSaldo()
    {
        return saldo;
    }
};