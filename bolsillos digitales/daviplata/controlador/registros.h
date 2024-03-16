#include "../modelo/usuario.h"    // importa modelo (clase usuario)
#include "../modelo/movimiento.h" // importa modelo (clase movimiento)
#include <vector>                 //clase vector para poder usar listas dinamicas
#include <algorithm>              // clase algotirmo para poder obtener id de una lista y luego borrarlo
#include <string>

vector<usuario> lista_usuario;        // lista de tipo objeto de los usuarios
vector<movimiento> lista_movimientos; // lista de tipo objeto para los colchones

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

    usuario aux1; //(nombre, apellido, correo, tipo, n_doc, n_cel, contra, 0, 0, 0, 0); // crea objeto auxiliar
    aux1.setNombreUsuario(nombre);
    aux1.setApellidoUsuario(apellido);
    aux1.setCorreoUsuario(correo);
    aux1.setTipoDocumento(tipo);
    aux1.setNumeroDocumento(n_doc);
    aux1.setNumeroCelular(n_cel);
    aux1.setContrasena(contra);
    aux1.setSaldo(0);

    lista_usuario.push_back(aux1); // lo pasa a la lista
}

//-------------------------------------------------------------------------------------------------------------------------------------

void generar_movimiento(int long long a, string b, float c) // genera los objetos de movimiento que agrega luego a la lista
{

    movimiento auxiliar_movs; // objeto auxiliar
    auxiliar_movs.setIdCliente(a);
    auxiliar_movs.setTipoMovimiento(b); // pide los datos
    auxiliar_movs.setSaldoMovimiento(c);

    lista_movimientos.push_back(auxiliar_movs); // lo agrega a la lista
}

void recargar(usuario &p) // metodo para recargar la cuenta del usuario
{

    int eleccion;
    cout << "seleccione la opcion con la que va a recargar su cuenta: " << endl;
    cout << "1- Efectivo" << endl;
    cout << "2- Transferencia bancaria" << endl; // tratar de conectar esto con daviplata (eso para el proximo sprint jajaaj)
    cout << "3- salir" << endl;

    cin >> eleccion;

    switch (eleccion)
    {
    case 1: // recargar en efectivo
        float aux_r;
        cout << "por favor dirijase a un punto nequi para hacer su recarga en efectivo" << endl;
        cout << "-----------Punto de recarga nequi ----------------------" << endl;
        cout << "Digite la cantidad de dinero a  recargar: " << endl;
        cin >> aux_r;                     // pide el dinero para hacer la recarga
        p.setSaldo(p.getSaldo() + aux_r); // lo actualiza en el saldo
        generar_movimiento(p.getNumeroDocumento(), "recarga en efectivo (debito)", aux_r);
        break;
    case 2: // trasferencia bancaria
        int eleccion;
        cout << "Por favor seleccione su banco: " << endl;
        cout << "1- Banco de bogota" << endl;
        cout << "2- Davivienda" << endl;
        cout << "3- Bancolombia" << endl;
        cout << "4- Banco caja social" << endl;
        cout << "5- Banco AV Villas" << endl; // escojer un banco para hacer la recarga
        cin >> eleccion;
        float aux_rr;
        cout << "Digite la cantidad de dinero a  recargar: " << endl;
        cin >> aux_rr;                     // pide la cantidad para recargar
        p.setSaldo(p.getSaldo() + aux_rr); // actualiza el saldo
        generar_movimiento(p.getNumeroDocumento(), "trasferencia bancaria (debito)", aux_rr);
        break;
    case 3:
        return;
        break;

    default:
        break;
    }
}

void lista_movimiento(usuario &p)
{
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "-------  movimiento --------------------------------------- valor movimiento -------------------" << endl;

    for (movimiento &q : lista_movimientos)
    {

        if (p.getNumeroDocumento() == q.getIdCliente())
        {

            cout << " -- " << q.getTipoMovimiento() << " -- " << q.getSaldoMovimiento() << " -- " << endl;
        }
    }

    cout << "------------------------------------------------------------------------------------------------" << endl;
}

void pagos(usuario &p)
{
    int eleccion;
    cout << "seleccione el servicio que quiere pagar: " << endl;
    cout << "1- servicio de electricidad" << endl
         << "2- television" << endl
         << "3- salud y donaciones" << endl
         << "4- salir" << endl;
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
        return;
        break;

    default:
        break;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------

void menu_app(int long long usuario_logeado) // metodo del menu del aplicativo
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
                cout << "--- 1- recargar daviplata                                 ---" << endl;
                cout << "--- 2- pago de servicios                                  ---" << endl;
                cout << "--- 3- recarga movil                                      ---" << endl;
                cout << "--- 4- ver movimientos                                    ---" << endl;
                cout << "--- 5- salir                                              ---" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cin >> eleccion; // selecciona la opcion
                switch (eleccion)
                {
                case 1:
                    recargar(p);
                    break;
                case 2:

                    break;

                case 3:

                    break;
                case 4:
                    lista_movimiento(p);
                    break;
                case 5:
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
            usuario_logeado = p.getNumeroDocumento(); // guarda nuemro de documeto usuario loggeado
            bandera = true;
        }
    }
    if (bandera == false)
    {
        cout << "usuario no registrado" << endl;
    }

    return usuario_logeado; // retorna ese numero de documento
}