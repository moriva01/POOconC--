#include "../modelo/usuario.h" // importa modelo (clase usuario)
#include "../modelo/regalo.h"  // importa modelo (clase regalo)
#include <vector>              //clase vector para poder usar listas dinamicas
#include <algorithm>

vector<usuario> lista_usuario;
vector<regalo> lista_regalos;                                                                           // lista de tipo objeto para los usuarios
usuario usuario1("juan", "perez", "juan.perez@correo.com", 1, 123456789, 3227027094, 1995, 0, 0, 0, 0); // usuario que ya esta registrado

void registrar_usuario() // metodo registrar suario
{

    int tipo, contra; // pide atributos del usuario
    string nombre, apellido, correo;
    int long long n_doc, n_cel;
    cout << "elige tu tipo de documento" << endl
         << "1- Cedula de ciudadania" << endl
         << "2- cedula de extranjeria" << endl
         << "3- pasaporte" << endl;
    cin >> tipo;
    cout << "digite su numero de documento: " << endl;
    cin >> n_doc;

    for (usuario p : lista_usuario) // recorre la lista
    {

        while (n_doc == p.getNumeroDocumento()) // mira si el documento ya esta registrado
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

    for (usuario p : lista_usuario) // recorre la lista
    {

        while (n_cel == p.getNumeroCelular()) // mira si el numero celular ya esta registrado
        {
            cout << "el numero de celular ya esta registrado" << endl;
            cout << "digite su numero de celular: " << endl;
            cin >> n_cel;
        }
    }
    cout << "registre una contraseña de 4 digitos" << endl;
    cin >> contra;

    while (contra < 1000 || contra > 9999) // revisa que la contraseña tenga 4 digitos
    {
        cout << "la contraseña debe contener 4 digitos" << endl;
        cout << "registre una contraseña de 4 digitos" << endl;
        cin >> contra;
    }

    usuario aux1(nombre, apellido, correo, tipo, n_doc, n_cel, contra, 0, 0, 0, 0); // crea objeto auxiliar

    lista_usuario.push_back(aux1); // lo pasa a la lista
}

int generar_codigos()
{

    srand(time(0));
    int codigo = rand() % 900000 + 100000;

    return codigo;
}
//______________________________________________________________________________________________________

void recargar(usuario &p)
{

    int eleccion;
    cout << "seleccione la opcion con la que va a recargar su cuenta: " << endl;
    cout << "1- Efectivo" << endl;
    cout << "2- Transferencia bancaria" << endl; // tratar de conectar esto con daviplata
    cout << "3- codigo regalo" << endl;          // programar algo que genere codigos regalo
    cout << "4- salir" << endl;

    cin >> eleccion;

    switch (eleccion)
    {
    case 1:
        float aux_r;
        cout << "por favor dirijase a un punto nequi para hacer su recarga en efectivo" << endl;
        cout << "-----------Punto de recarga nequi ----------------------" << endl;
        cout << "Digite la cantidad de dinero a  recargar: " << endl;
        cin >> aux_r;
        p.setSaldo(p.getSaldo() + aux_r);

        break;
    case 2:
        int eleccion;
        cout << "Por favor seleccione su banco: " << endl;
        cout << "1- Banco de bogota" << endl;
        cout << "2- Davivienda" << endl;
        cout << "3- Bancolombia" << endl;
        cout << "4- Banco caja social" << endl;
        cout << "5- Banco AV Villas" << endl;
        cin >> eleccion;
        float aux_rr;
        cout << "Digite la cantidad de dinero a  recargar: " << endl;
        cin >> aux_rr;
        p.setSaldo(p.getSaldo() + aux_rr);
        break;
    case 3:
        int codigo_regalo;
        static float saldo_aux3 = 0;
        cout << "digite su codigo de regalo: " << endl;
        cin >> codigo_regalo;

        static auto it = find_if(lista_regalos.begin(), lista_regalos.end(),
                                 [codigo_regalo](const regalo &q)
                                 { return q.getCodigo() == codigo_regalo; });

        if (it != lista_regalos.end())
        {
            saldo_aux3 = it->getCantidad();
            p.setSaldo(p.getSaldo() + saldo_aux3);
            cout << "recarga exitosa" << endl;
            lista_regalos.erase(it);
        }
        else
        {
            cout << "El codigo de regalo no es valido o ya ha sido utilizado." << endl;
        }
        break;

    case 4:
        return;
        break;

    default:
        break;
    }
}

void enviar_plata(usuario &p, usuario &r, float monto, int eleccion)
{
    switch (eleccion)
    {
    case 1:
        if (p.getSaldo() < monto)
        {
            cout << "El saldo no es suficiente para enviar dinero" << endl;
            return;
        }

        p.setSaldo(p.getSaldo() - monto);
        r.setSaldo(r.getSaldo() + monto);

        break;
    case 2:
        static int aux22 = 0;

        if (p.getSaldo() < monto)
        {
            cout << "El saldo no es suficiente para crear codigo" << endl;
            return;
        }
        p.setSaldo(p.getSaldo() - monto);
        aux22 = generar_codigos();
        cout << "codigo generado correctamente ------------------------------------------------------------ " << aux22 << endl;
        static regalo aux(p.getNumeroDocumento(), aux22, monto);
        lista_regalos.push_back(aux);
        break;

    case 3:
        return;
        break;
    default:
        break;
    }
}

void sacar_plata(usuario &p)
{

    static int aux23 = 0;
    float aux;
    cout << "Digite la cantidad de dinero a retirar: " << endl;
    cin >> aux;

    if (p.getSaldo() < aux)
    {
        cout << "El saldo no es suficiente para crear codigo" << endl;
        return;
    }
    aux23 = generar_codigos();
    cout << "use este codigo para retirar -------------------------------------------------- " << aux23 << endl;
    p.setSaldo(p.getSaldo() - aux);
}

//______________________________________________________________________________________________________

void menu_app(int long long usuario_logeado)
{

    for (usuario &p : lista_usuario) // recorre la lista
    {

        if (p.getNumeroDocumento() == usuario_logeado)

        {
            while (true) // si esta registrado muestra el menu del usuario
            {
                int eleccion;
                cout << "----------- Hola," << p.getNombreUsuario() << " " << p.getApellidoUsuario() << endl;
                cout << "-- Saldo disponible: " << p.getSaldo() << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "--- 1- Colchon                                            ---" << endl;
                cout << "--- 2- meta                                               ---" << endl;
                cout << "--- 3- bolsillo                                           ---" << endl;
                cout << "--- 4- recarga                                            ---" << endl;
                cout << "--- 5- saca plata                                         ---" << endl;
                cout << "--- 6- enviar plata                                       ---" << endl;
                cout << "--- 7- ver movimientos                                    ---" << endl;
                cout << "--- 8- Salir                                              ---" << endl;
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
                    recargar(p);
                    break;
                case 5:
                    sacar_plata(p);
                    break;
                case 6:
                    static float auxiliar_saldo = 0;
                    static usuario *enviar = nullptr;
                    int eleccion;
                    cout << "seleccione la opcion para enviar dinero: " << endl;
                    cout << "1- A otro nequi" << endl;
                    cout << "2- Codigo de regalo" << endl;
                    cout << "3- Salir" << endl;
                    cin >> eleccion;

                    if (eleccion == 1)
                    {

                        int long long auxiliar_numero;
                        cout << "digite el numero a enviar plata: " << endl;
                        cin >> auxiliar_numero;

                        for (usuario &q : lista_usuario) // encuentra el numero celular
                        {
                            if (auxiliar_numero == q.getNumeroCelular())
                            {
                                enviar = &q;
                                break;
                            }
                        }

                        if (enviar == nullptr)
                        {
                            cout << "El usuario no se encuentra registrado" << endl;
                            return;
                        }

                        cout << "digite la cantidad de dinero a enviar: " << endl;
                        cin >> auxiliar_saldo;
                    }
                    if (eleccion == 2)
                    {
                        cout << "digite la cantidad de dinero a convertir en codigo: " << endl;
                        cin >> auxiliar_saldo;
                    }

                    enviar_plata(p, *enviar, auxiliar_saldo, eleccion);
                    break;

                case 7:
                    break;

                case 8:
                    return;
                    break;

                default:
                    cout << "opcion no valida" << endl;
                    break;
                }
            }
        }
    }
}

int long long acceder_app() // entrar a la aplicacion
{

    int long long numero, usuario_logeado = 0; // pide numero y contraseña
    int contra;
    bool bandera = false;

    cout << "digite su numero de celular: " << endl;
    cin >> numero;

    cout << "digite su contraseña: " << endl;
    cin >> contra;

    for (usuario p : lista_usuario) // recorre la lista
    {

        if (numero == p.getNumeroCelular() && contra == p.getContrasena()) // revisa si el correo y la contraseña estan registrados
        {
            usuario_logeado = p.getNumeroDocumento();
            bandera = true;
        }
    }
    if (bandera == false)
    {
        cout << "usuario no registrado" << endl;
    }

    return usuario_logeado;
}