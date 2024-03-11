#include "persona.h" //imprtar persona.h para heredar sus metodos y atributos

class usuario : public persona // clase usuario
{

private: // atributos de la clase
    int long long numero_celular;
    int contrasena;
    float meta[2];
    float bolsillo[3];
    float saldo;
    int colchon;

public:
    usuario() {} // constructor vacio
    // --------------------------------------- setters--------------------------------------------------------------------

    void setNumeroCelular(long long numero)
    {
        numero_celular = numero;
    }

    void setColchon(int col)
    {

        colchon = col;
    }

    void setContrasena(int contrasena)
    {
        this->contrasena = contrasena;
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

    int getColchon(){

        return colchon;
    }
};