#include "persona.h"

class empleado : public persona
{

private:
    string cargo;
    float valor_hora;
    int horas_trabajadas;
    string departamento;

public:
    empleado() {}

    // ------------------------------------------------------------------------------- Setters
    void setCargo(string c)
    {
        cargo = c;
    }

    void setValorHora(float v)
    {
        valor_hora = v;
    }

    void setHorasTrabajadas(int h)
    {
        horas_trabajadas = h;
    }

    void setDepartamento(string d)
    {
        departamento = d;
    }

    // --------------------------------------------------- Getters
    string getCargo()
    {
        return cargo;
    }

    float getValorHora()
    {
        return valor_hora;
    }

    int getHorasTrabajadas()
    {
        return horas_trabajadas;
    }

    string getDepartamento()
    {
        return departamento;
    }

    //----------------------------------------------------- Metodos

    float calcularHonorarios(){


        float aux= (this->horas_trabajadas*this->valor_hora);
        float reteica=(aux*0.966)/100;
        aux-=reteica;

        return aux;
    }
};