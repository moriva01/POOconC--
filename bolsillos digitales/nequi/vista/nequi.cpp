#include "../controlador/registros.h"

int main()
{
    lista_usuario.push_back(usuario1); // mete el usuario principal que damos por hecho que ya existe

    int eleccion;

    while (true)
    {

        cout << "-------------------Nequi-------------------------------------" << endl;
        cout << "--- 1- Crea tu Nequi                                      ---" << endl;
        cout << "--- 2- Entra                                              ---" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            registrar_usuario();
            break;

        case 2:
            acceder_app();
            break;

        default:
            cout << "Opcion no valida" << endl;
            return 0;
            break;
        }
    }

    return 0;
}