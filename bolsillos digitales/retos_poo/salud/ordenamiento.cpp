#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class cancion
{

private:
    string nombre;  // a -z
    string artista; // z-a
    float duracion; // 1 a 3 mins

public:
    cancion() {}

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
struct Node
{
    string nombre;
    string artista;
    float duracion;
    Node *next;

    Node(const string &n, const string &a, float d) : nombre(n), artista(a), duracion(d), next(nullptr) {}
};

void imprimirListaEnlazada(Node *head)
{
    cout << "Lista enlazada:" << endl;
    while (head != nullptr)
    {
        cout << "Nombre: " << head->nombre << ", Artista: " << head->artista << ", Duración: " << head->duracion << endl;
        head = head->next;
    }
}

//------------------------------------------------------------------------------

bool compararPorNombre(const cancion &c1, const cancion &c2)
{
    return c1.getNombre() < c2.getNombre();
}

bool compararPorArtistaDesc(const cancion &c1, const cancion &c2)
{
    return c1.getArtista() > c2.getArtista();
}

bool compararPorDuracionAsc(const cancion &c1, const cancion &c2)
{
    return c1.getDuracion() < c2.getDuracion();
}

// -------------------------------------------------------------------------------
void toLowerCase(string &str)
{
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
              { return tolower(c); });
}

void registrar_cancion(vector<cancion> &lista, cancion &can)
{

    for (cancion &c : lista) // revisa si la cancion esta en la lista main
    {

        string nombre1 = c.getNombre();
        string nombre2 = can.getNombre();

        toLowerCase(nombre1);
        toLowerCase(nombre2);
        string artista1 = c.getArtista();
        string artista2 = can.getArtista();
        toLowerCase(artista1);
        toLowerCase(artista2);

        if (nombre1 == nombre2 && artista1 == artista2)
        {
            return;
        }
    }

    // si no esta la agrega
    lista.push_back(can);
}

cancion crear_cancion()
{

    string b, c;
    float d;

    cancion aux;

    cout << "digite nombre cancion: " << endl;
    cin >> b;

    cout << "digite artista cancion: " << endl;
    cin >> c;

    cout << "digite duracion cancion: " << endl;
    cin >> d;

    aux.setNombre(b);
    aux.setArtista(c);
    aux.setDuracion(d);

    return aux;
}

int main()
{

    vector<cancion> lista_cancion_main;
    vector<cancion> lista_cancion_uno;
    vector<cancion> lista_cancion_dos;
    Node *listaEnlazada = nullptr;
    cancion nueva_cancion;
    bool registro;
    int eleccion;
    Node *newNode;

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

            nueva_cancion = crear_cancion();
            registrar_cancion(lista_cancion_main, nueva_cancion);
            int opcion;
            cout << "en qué lista deseas registrar la canción? (1 para lista uno, 2 para lista dos): " << endl;
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                lista_cancion_uno.push_back(nueva_cancion);
                cout << "Canción registrada" << endl;
                break;
            case 2:
                lista_cancion_dos.push_back(nueva_cancion);
                cout << "Canción registrada" << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
            }
            newNode = new Node(nueva_cancion.getNombre(), nueva_cancion.getArtista(), nueva_cancion.getDuracion());
            newNode->next = listaEnlazada;
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

                sort(lista_cancion_main.begin(), lista_cancion_main.end(), compararPorNombre);

                cout << "Canciones ordenadas por nombre de la A a la Z:" << endl;
                for (const cancion &c : lista_cancion_main)
                {
                    cout << "Nombre: " << c.getNombre() << ", Artista: " << c.getArtista() << ", Duración: " << c.getDuracion() << endl;
                }
                break;
            case 2:
                sort(lista_cancion_uno.begin(), lista_cancion_uno.end(), compararPorArtistaDesc);

                cout << "Canciones ordenadas por artista de la Z a la A:" << endl;
                for (const cancion &c : lista_cancion_uno)
                {
                    cout << "Nombre: " << c.getNombre() << ", Artista: " << c.getArtista() << ", Duración: " << c.getDuracion() << endl;
                }
                break;
            case 3:
                sort(lista_cancion_dos.begin(), lista_cancion_dos.end(), compararPorDuracionAsc);

                cout << "Canciones ordenadas por duración de 1 a 3 minutos:" << endl;
                for (const cancion &c : lista_cancion_dos)
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
            imprimirListaEnlazada(listaEnlazada);
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