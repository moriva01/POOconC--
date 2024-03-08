#include "../modelo/usuario.h"// importa modelo (clase usuario)
#include <vector>//clase vector para poder usar listas dinamicas

vector<usuario> lista_usuario;//lista de tipo objeto para los usuarios
usuario usuario1("juan", "perez", "juan.perez@correo.com", 1, 123456789, 3227027094, 1995, 0, 0, 0, 0);//usuario que ya esta registrado

void registrar_usuario()//metodo registrar suario
{

    int tipo, contra;//pide atributos del usuario
    string nombre, apellido, correo;
    int long long n_doc, n_cel;
    cout << "elige tu tipo de documento" << endl
         << "1- Cedula de ciudadania" << endl
         << "2- cedula de extranjeria" << endl
         << "3- pasaporte" << endl;
    cin >> tipo;
    cout << "digite su numero de documento: " << endl;
    cin >> n_doc;

    for (usuario p : lista_usuario)//recorre la lista
    {

        while (n_doc == p.getNumeroDocumento())//mira si el documento ya esta registrado
        {
            cout << "el numero de documento ya esta registrado" << endl;
            cout << "digite su numero de documento: " << endl;
            cin >> n_doc;
        }
    }

    cout << "digite su nombre: " << endl;
    cin >> nombre;
    cout << "digite su apellido: " << endl;
    cin >> apellido;
    cout << "digite su correo electronico: " << endl;
    cin >> correo;
    cout << "digite su numero de celular: " << endl;
    cin >> n_cel;

    for (usuario p : lista_usuario)//recorre la lista
    {

        while (n_cel == p.getNumeroCelular())//mira si el numero celular ya esta registrado
        {
            cout << "el numero de celular ya esta registrado" << endl;
            cout << "digite su numero de celular: " << endl;
            cin >> n_cel;
        }
    }
    cout << "registre una contraseña de 4 digitos" << endl;
    cin >> contra;

    while (contra < 1000 || contra > 9999)//revisa que la contraseña tenga 4 digitos
    {
        cout << "la contraseña debe contener 4 digitos" << endl;
        cout << "registre una contraseña de 4 digitos" << endl;
        cin >> contra;
    }

    usuario aux1(nombre, apellido, correo, tipo, n_doc, n_cel, contra, 0, 0, 0, 0);//crea objeto auxiliar

    lista_usuario.push_back(aux1);//lo pasa a la lista
}

void acceder_app()//entrar a la aplicacion
{

    int long long numero, codigo = 0;//pide numero y contraseña
    int contra;
    bool bandera = false;//por si el user no esta registrado

    cout << "digite su numero de celular: " << endl;
    cin >> numero;

    cout << "digite su contraseña: " << endl;
    cin >> contra;

    for (usuario p : lista_usuario)//recorre la lista
    {

        if (numero == p.getNumeroCelular() && contra == p.getContrasena())//revisa si el correo y la contraseña estan registrados
        {
            bandera = true;

            int eleccion;

            while (true)//si esta registrado muestra el menu del usuario
            {

                cout << "----------- Hola," << p.getNombreUsuario() << " " << p.getApellidoUsuario() << endl;
                cout << "-- Saldo disponible: " << p.getSaldo() << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "--- 1- Colchon                                            ---" << endl;
                cout << "--- 2- meta                                               ---" << endl;
                cout << "--- 3- bolsillo                                           ---" << endl;
                cout << "--- 4- recarga                                            ---" << endl;
                cout << "--- 5- saca plata                                         ---" << endl;
                cout << "--- 6- ver movimientos                                    ---" << endl;
                cout << "--- 7- Salir                                              ---" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cin >> eleccion;
                switch (eleccion)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;

                case 7:
                    return;
                    break;

                default:
                    cout << "opcion no valida" << endl;
                    break;
                }
            }
        }
    }

    if (bandera = false)//si el usuario no esta registrado
    {

        cout << "el usuario no existe, debe registarse!" << endl;
    }
}