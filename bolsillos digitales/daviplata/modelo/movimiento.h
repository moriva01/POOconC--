#include <iostream>
using namespace std;

class movimiento
{

private:
    int long long id_cliente;
    string tipo_movimiento;
    float saldo_movimiento;

public:
    movimiento() {}

    // Setters
    void setIdCliente(int long long id)
    {
        id_cliente = id;
    }

    void setTipoMovimiento(const string &tipo)
    {
        tipo_movimiento = tipo;
    }

    void setSaldoMovimiento(float saldo)
    {
        saldo_movimiento = saldo;
    }

    // Getters
    int long long getIdCliente() const
    {
        return id_cliente;
    }

    string getTipoMovimiento() const
    {
        return tipo_movimiento;
    }

    float getSaldoMovimiento() const
    {
        return saldo_movimiento;
    }
};