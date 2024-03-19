// listas enlazadas - hacer algo de un spotify

/*#include <iostream>

using namespace std;

struct node
{

    int data;
    node *next;
    node(int val) : data(val), next(nullptr) {}
};

void insertarinicio(node *&head, int val)
{

    node *new_node = new_node(val);

    new_node->next = head;

    head = new_node;
}

void mostrar_lista(node *head)
{

    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){

node* head=nullptr;

insertarinicio(head,3);
    return 0;
}*/

#include <iostream>
#include <vector>

using namespace std;

class cancion
{

private:
    string nombre;
    string artista;
    float duracion;

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

void registrar_cancion(vector<cancion> lista){

    string b,c;
    float d;

    cancion aux;

cout<<"digite nombre cancion: "<<endl;
cin>>b;

cout<<"digite artista cancion: "<<endl;
cin>>c;

cout<<"digite duracion cancion: "<<endl;
cin>>d;

aux.setNombre(b);
aux.setArtista(c);
aux.setDuracion(d);

lista.push_back(aux);
    
}

int main(){

vector<cancion> lista_cancion_main;

registrar_cancion(lista_cancion_main);


    return 0;
}