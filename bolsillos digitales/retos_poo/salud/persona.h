//                                                           ivan david moreno vargas

// cambiamos a .h para poder importar en la otra clase
#include <iostream> //uso de cin y cout

using namespace std; // espacio std para poder ingresar datos

class persona // clase persona
{

private: // atributos que pedia el ejercicio
    string tipo_doc;
    long long documento;
    string nombre;
    string apellido;
    float peso;
    float estatura;
    int edad;
    bool sexo;

public:
    persona() {} // constructor vacio de los objetos

    //--------------------------------------------------------------- getters

    string getTipoDoc() const
    {
        return tipo_doc;
    }

    long long getDocumento() const
    {
        return documento;
    }

    string getNombre() const
    {
        return nombre;
    }

    string getApellido() const
    {
        return apellido;
    }

    float getPeso() const
    {
        return peso;
    }

    float getEstatura() const
    {
        return estatura;
    }

    int getEdad() const
    {
        return edad;
    }

    bool getSexo() const
    {
        return sexo;
    }

    //----------------------------------------------------------------- setters

    void setTipoDoc(const string &tipo_doc)
    {
        this->tipo_doc = tipo_doc;
    }

    void setDocumento(long long documento)
    {
        this->documento = documento;
    }

    void setNombre(const string &nombre)
    {
        this->nombre = nombre;
    }

    void setApellido(const string &apellido)
    {
        this->apellido = apellido;
    }

    void setPeso(float peso)
    {
        this->peso = peso;
    }

    void setEstatura(float estatura)
    {
        this->estatura = estatura;
    }

    void setEdad(int edad)
    {
        this->edad = edad;
    }

    void setSexo(bool sexo)
    {
        this->sexo = sexo;
    }

    static persona pedirDatos() // metodo que pide datos
    {
        persona persona; // inicializa objeto auxiliar
        cout << "tipo de documento: ";
        cin >> persona.tipo_doc; // pide los datos
        cout << "numero de documento: ";
        cin >> persona.documento;
        cout << "nombre: ";
        cin >> persona.nombre;
        cout << "apellido: ";
        cin >> persona.apellido;
        cout << "peso (kg): ";
        cin >> persona.peso;
        cout << "estatura (m): ";
        cin >> persona.estatura;
        cout << "edad: ";
        cin >> persona.edad;
        cout << "sexo" << endl
             << " --0 para femenino" << endl
             << "--1 para masculino ";
        cin >> persona.sexo;

        return persona; // retorna el objeto
    }

    float calcularmc(float peso, float estatura) // calcula masa corporal pasan peso y estatura como parametros
    {

        float peso_final = peso / (estatura * estatura); // calcula masa corporal
        return peso_final;

        
    }

    void mayorEdad(int edad) // metodo saber si es mayor de edad entra edad como parametro
    {

        if (edad >= 18) // revias sea mayor de edad
        {

            cout << "--- mayor de edad" << endl;
        }
        else
        {

            cout << "--- menor de edad" << endl;
        }
    }

    void mostrarPersona(persona aux) // metodo mostrar persona, entra objeto persona como parametro
    {

        cout << "-------------------------------------------------- " << endl; // imprime todo eso
        cout << "------------- tipo de documento: " << aux.tipo_doc << endl;
        cout << "------------- numero de documento: " << aux.documento << endl;
        cout << "------------- nombre: " << aux.nombre << endl;
        cout << "------------- apellido: " << aux.apellido << endl;
        cout << "------------- peso (kg): " << aux.peso << endl;
        cout << "------------- estatura (m) " << aux.estatura << endl;
        cout << "------------- edad: " << aux.edad << endl;

        if (aux.sexo == 0) // revisa si es masculino o femenino
        {
            cout << "------------- sexo: Femenino " << endl;
        }
        else
        {

            cout << "------------- sexo: Masculino " << endl;
        }

        cout << "-------------------------------------------------- " << endl;
      //  cout << "------------- segun su masa corporal:" << endl;

       // aux.calcularmc(aux.peso, aux.estatura); // instancia el metodo de masa corporal

        cout << "------------- segun su edad:" << endl;
        aux.mayorEdad(aux.edad); // instancia metodo de la mayoria de edad
    }
};

/*int main()//este era el main pero se paso para la clase del otro paquete como decia el punto 2
{

    persona persona1 = persona::pedirDatos();

    persona1.mostrarPersona(persona1);

    return 0;
}*/