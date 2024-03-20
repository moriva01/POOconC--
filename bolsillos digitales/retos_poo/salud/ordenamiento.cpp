#include <iostream>// parametodos de entrada y salida por teclado
#include <vector> //para las lista
#include <algorithm> //para poder hacer cosas con el lower (como si fuera el equalignorecase de java)

using namespace std;//espacio de trabajo

class cancion//clase cancion
{

private://atributos de la clase
    string nombre;  // a -z
    string artista; // z-a
    float duracion; // 1 a 3 mins

public:
    cancion() {}//constructor vacio

    // Setter para nombre
    void setNombre(const string &n)
    {
        nombre = n;
    }

    // Getter para nombre
    string getNombre() const
    {
        return nombre;
    }

    // Setter para artista
    void setArtista(const string &a)
    {
        artista = a;
    }

    // Getter para artista
    string getArtista() const
    {
        return artista;
    }

    // Setter para duracion
    void setDuracion(float d)
    {
        duracion = d;
    }

    // Getter para duracion
    float getDuracion() const
    {
        return duracion;
    }
};

//------------------------------------------------------------------------------
struct Node//nodo lista enlazada
{
    string nombre;
    string artista;
    float duracion;
    Node *next;

    Node(const string &n, const string &a, float d) : nombre(n), artista(a), duracion(d), next(nullptr) {}
};

void imprimir_lista_enlazada(Node *head)//imprimir la lista enlazada
{
    cout << "Lista JAM Spotify:" << endl;
    while (head != nullptr)
    {
        cout << "Nombre: " << head->nombre << ", Artista: " << head->artista << ", Duración: " << head->duracion << endl;
        head = head->next;
    }
}

//------------------------------------------------------------------------------

bool comparar_nombre(const cancion &c1, const cancion &c2) //compara por nombre ordenamiento
{
    return c1.getNombre() < c2.getNombre();
}

bool comparar_artista(const cancion &c1, const cancion &c2)//compara por artista ordenamiento
{
    return c1.getArtista() > c2.getArtista();
}

bool comparar_duracion(const cancion &c1, const cancion &c2)//compara por duracion ordenamiento
{
    return c1.getDuracion() < c2.getDuracion();
}

// -------------------------------------------------------------------------------
void lower_case(string &str)//combierte todo en minusculas (para jhacer comparacion tipo equalignorecase de java)
{
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
              { return tolower(c); });
}

void registrar_cancion(vector<cancion> &lista, cancion &can)//registrar canciones
{

    for (cancion &c : lista) // revisa si la cancion esta en la lista main
    {

        string nombre1 = c.getNombre();//toma los valores de la lista y el objeto
        string nombre2 = can.getNombre();

        lower_case(nombre1);//los pasa a minusculas
        lower_case(nombre2);
        string artista1 = c.getArtista();
        string artista2 = can.getArtista();
        lower_case(artista1);
        lower_case(artista2);

        if (nombre1 == nombre2 && artista1 == artista2)
        {
            return;//revisa si ya esta en la lsita main y no lo coloca
        }
    }

    // si no esta la agrega
    lista.push_back(can);
}

cancion crear_cancion()//crear un objeto cancion
{

    string b, c;
    float d;

    cancion aux;//objeto auxiliar

    cout << "digite nombre cancion: " << endl;
    cin >> b;//pide los datos de la cancion

    cout << "digite artista cancion: " << endl;
    cin >> c;

    cout << "digite duracion cancion: " << endl;
    cin >> d;

    aux.setNombre(b);//los pasa al objeto
    aux.setArtista(c);
    aux.setDuracion(d);

    return aux;//retorna el objeto
}

int main()
{

    vector<cancion> lista_cancion_main;//listas de las canciones
    vector<cancion> lista_cancion_uno;
    vector<cancion> lista_cancion_dos;
    Node *listaEnlazada = nullptr;//lista enlazada
    cancion nueva_cancion;//auxiliar de nueva canicon
    bool registro;
    int eleccion;
    Node *newNode;//nodos de la lista enlazada

    while (true)
    {

        cout << "------------Spotify--------------------" << endl;
        cout << "1- registrar canciones en las listas" << endl;
        cout << "2- ver las listas" << endl;
        cout << "3- spotify JAM" << endl;
        cout << "4- salir" << endl;
        cin >> eleccion;
        switch (eleccion)
        {
        case 1:

            nueva_cancion = crear_cancion();//crea la cancion con el metodo de crear
            registrar_cancion(lista_cancion_main, nueva_cancion);//lo pasa a registrar en el main
            int opcion;
            cout << "en qué lista deseas registrar la canción? (1 para lista uno, 2 para lista dos): " << endl;
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                lista_cancion_uno.push_back(nueva_cancion);//registra lista 1
                cout << "Canción registrada" << endl;
                break;
            case 2:
                lista_cancion_dos.push_back(nueva_cancion);//registra lista 2
                cout << "Canción registrada" << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
            }
            newNode = new Node(nueva_cancion.getNombre(), nueva_cancion.getArtista(), nueva_cancion.getDuracion());
            newNode->next = listaEnlazada;//registra lista enlazada
            listaEnlazada = newNode;
            break;
        case 2:
            int opt2;
            cout << "seleccione la lista que quiere ver:" << endl;
            cout << "1- lista main" << endl
                 << "2- lista uno" << endl
                 << "3- lista dos" << endl
                 << "4- salir" << endl;
            cin >> opt2;

            switch (opt2)
            {
            case 1:

                sort(lista_cancion_main.begin(), lista_cancion_main.end(), comparar_nombre);//organiza por nombre

                cout << "Canciones ordenadas por nombre de la A a la Z:" << endl;
                for (const cancion &c : lista_cancion_main)//imprime la lista
                {
                    cout << "Nombre: " << c.getNombre() << ", Artista: " << c.getArtista() << ", Duración: " << c.getDuracion() << endl;
                }
                break;
            case 2:
                sort(lista_cancion_uno.begin(), lista_cancion_uno.end(), comparar_artista);//organiza por artista

                cout << "Canciones ordenadas por artista de la Z a la A:" << endl;
                for (const cancion &c : lista_cancion_uno)//imprime la lista
                {
                    cout << "Nombre: " << c.getNombre() << ", Artista: " << c.getArtista() << ", Duración: " << c.getDuracion() << endl;
                }
                break;
            case 3:
                sort(lista_cancion_dos.begin(), lista_cancion_dos.end(), comparar_duracion);//organiza por duracion

                cout << "Canciones ordenadas por duración de 1 a 3 minutos:" << endl;
                for (const cancion &c : lista_cancion_dos)//imprime la lsita
                {
                    cout << "Nombre: " << c.getNombre() << ", Artista: " << c.getArtista() << ", Duración: " << c.getDuracion() << endl;
                }
                break;
            case 4:
                return 0;
                break;

            default:
                break;
            }
            break;
        case 3:
            imprimir_lista_enlazada(listaEnlazada);//imprime lista JAM

            Node *temp;
            while (listaEnlazada != nullptr)//limpia el espacio de memoria
            {
                temp = listaEnlazada;
                listaEnlazada = listaEnlazada->next;
                delete temp;
            }
            break;
        case 4:
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}