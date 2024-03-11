#include <iostream> //metodos de entrada y salida por teclado

using namespace std; // espacio de trabajo

class colchon
{

private:
    int long long id_cliente;
    float saldo;
    int proteccion;
    string pregunta;
    string respuesta;

public:
    colchon() {}

    // ------------------------------------ setters

    void setRespuesta(string r)
    {
        respuesta = r;
    }

    void setPregunta(string q)
    {
        pregunta = q;
    }

    void setProteccion(long long p)
    {
        proteccion = p;
    }

    void setSaldo(float s)
    {
        saldo = s;
    }

    void setIdCliente(int id)
    {
        id_cliente = id;
    }

    // --------------------------------------- getters

    string getRespuesta()
    {
        return respuesta;
    }

    string getPregunta()
    {
        return pregunta;
    }

    long long getProteccion()
    {
        return proteccion;
    }

    float getSaldo()
    {
        return saldo;
    }

    int getIdCliente()
    {
        return id_cliente;
    }
};