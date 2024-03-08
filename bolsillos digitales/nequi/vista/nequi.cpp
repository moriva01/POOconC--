//                          Ivan David Moreno Vargas

#include "../controlador/registros.h"//importa el controlador (clase registros)

int main()
{
    lista_usuario.push_back(usuario1); // mete el usuario principal que damos por hecho que ya existe

    int eleccion;

    while (true)//menu inicial nequi
    {

        cout << "-------------------Nequi-------------------------------------" << endl;
        cout << "--- 1- Crea tu Nequi                                      ---" << endl;
        cout << "--- 2- Entra                                              ---" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            registrar_usuario();//registrar usuarios
            break;

        case 2:
            acceder_app();//ingresar al nequi
            break;

        default:
            cout << "Opcion no valida" << endl;//sale del sistema
            return 0;
            break;
        }
    }

    return 0;
}