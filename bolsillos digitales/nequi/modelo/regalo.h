class regalo
{

private:
    int long long id_comprador;
    int codigo;
    float cantidad;

public:
    regalo(int long long id_comprador,
           int codigo, float cantidad)
    {

        this->id_comprador = id_comprador;
        this->codigo = codigo;
        this->cantidad = cantidad;
    }

    regalo() {}

    void setId_comprador(const long long comprador)
    {
        id_comprador = comprador;
    }

    void setCantidad(const long long cant)
    {
        cantidad = cant;
    }

    void setCodigo(const int code)
    {
        codigo = code;
    }

    long long getId_comprador() const
    {
        return id_comprador;
    }

    float getCantidad() const
    {
        return cantidad;
    }

    int getCodigo() const
    {
        return codigo;
    }
};