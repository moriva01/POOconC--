//                          Ivan David Moreno Vargas

#include "../controlador/registros.h" //importa el controlador (clase registros)

int main()
{

    usuario usuario1; //("juan", "perez", "juan.perez@correo.com", 1, 123456789, 3227027094, 1995, 0, 0, 0, 0);
    usuario1.setNombreUsuario("juan");
    usuario1.setApellidoUsuario("perez");
    usuario1.setCorreoUsuario("juan.perez@correo.com");
    usuario1.setTipoDocumento(1);
    usuario1.setNumeroDocumento(123456789);
    usuario1.setNumeroCelular(3227027094);
    usuario1.setContrasena(1995);
    usuario1.setSaldo(0);

    lista_usuario.push_back(usuario1); // mete el usuario principal que damos por hecho que ya existe
    int long long log = 0;
    int eleccion;

    while (true) // menu inicial nequi
    {

        cout << "-------------------Daviplata---------------------------------" << endl;
        cout << "--- 1- Crea tu Daviplata                                  ---" << endl;
        cout << "--- 2- Entra                                              ---" << endl;
        cout << "--- 3- Salir                                              ---" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            registrar_usuario(); // registrar usuarios
            break;

        case 2:
            log = acceder_app(); // ingresar al nequi
            menu_app(log);
            break;

        case 3:
            return 0;
            break;

        default:
            cout << "Opcion no valida" << endl; // sale del sistema
            return 0;
            break;
        }
    }

    return 0;
}