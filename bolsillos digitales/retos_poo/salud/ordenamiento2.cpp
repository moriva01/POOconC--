#include <iostream> //entrada y salida de datos por teclado
#include <vector> //para poder usar lista
#include <algorithm> //para poder organizar y desorganizar cosas dentro de las listas
#include <random> //generar poscisiones aleatorias


using namespace std;//espacio de trabajo 

class poker
{

private://atributos de la clase
    string valor;
    string pinta;

public:
    poker(string newValor, string newPinta)//constructor con parametros de cartas
    {
        valor = newValor;
        pinta = newPinta;
    }

    string getValor()//getters y setters
    {
        return valor;
    }

    void setValor(string newValor)
    {
        valor = newValor;
    }

    string getPinta()
    {
        return pinta;
    }

    void setPinta(string newPinta)
    {
        pinta = newPinta;
    }

    bool operator<(const poker &other) const//metodo ordenar las cartas
    {

        if (pinta == other.pinta)//revisa que la pinta sea igual para cada carta
        {
            return valor < other.valor;//las organiza segun su valor
        }//retorna todas las cartas ordenadas por su valor

        static const vector<string> orden = {"picas", "diamantes", "corazones", "treboles"};//lista con el orden que le quiero dar a las cartas
        return find(orden.begin(), orden.end(), pinta) < std::find(orden.begin(), orden.end(), other.pinta);//retorna las cartas ordenadas por pinta (previamente ordenadas por valor)
    }//retorna un booleano
};

void crear_cartas(vector<poker> &lista)//metodo que crea cartas
{
    string valores[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};//valores de las cartas
    string pintas[] = {"corazones", "diamantes", "treboles", "picas"};//pintas de las cartas

    for (int i = 0; i < 4; i++) // bucle de las pintas
    {
        for (int j = 0; j < 13; j++) // bucle de los valores
        {
            poker nueva_carta(valores[j], pintas[i]);//genera todas las cartas de una pinta
            lista.push_back(nueva_carta);//las mete en la lista
        }
    }
}

int main()
{
    vector<poker> lista_cartas;//lista de cartas
    crear_cartas(lista_cartas);//crear las cartas
    //------------------- desordenar las cartas xq el metodo las crea en orden
    random_device rd;//crea poscisiones random
    mt19937 g(rd());//crea la secuencia de nuemors segun el ramdom de poscision
    shuffle(lista_cartas.begin(), lista_cartas.end(), g);//revuelve las cartas segun esas poscisiones aleatorias

    cout << "------- cartas sin ordenar: " << endl;

    for (poker p : lista_cartas) // recorre la lista desordenada
    {
        cout << "--> " << p.getPinta() << " - " << p.getValor() << endl;
    }

    sort(begin(lista_cartas), end(lista_cartas));//ordena la lista segun el metodo creado para ordenarlas

    cout << "------- cartas ordenadas: " << endl;

    for (poker p : lista_cartas) // recorre la lista ordenada
    {
        cout << "--> " << p.getPinta() << " - " << p.getValor() << endl;
    }

    return 0;
}