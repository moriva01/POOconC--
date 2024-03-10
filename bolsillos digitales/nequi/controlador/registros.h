#include "../modelo/usuario.h" // importa modelo (clase usuario)
#include "../modelo/regalo.h"  // importa modelo (clase regalo)
#include <vector>              //clase vector para poder usar listas dinamicas
#include <algorithm>           // clase algotirmo para poder obtener id de una lista y luego borrarlo

vector<usuario> lista_usuario; // lista de tipo objeto de los usuarios
vector<regalo> lista_regalos; // lista de tipo objeto para los regalos

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
    aux1.setColchon(0);
    aux1.setMeta(0, 0);
    aux1.setBolsillo(0, 0, 0);
    aux1.setSaldo(0);

    lista_usuario.push_back(aux1); // lo pasa a la lista
}

int generar_codigos()//metodo que genera codigos aleatorios de 6 digitos
{

    srand(time(0));
    int codigo = rand() % 900000 + 100000;

    return codigo;
}
//______________________________________________________________________________________________________

void recargar(usuario &p)//metodo para recargar la cuenta del usuario
{

    int eleccion;
    cout << "seleccione la opcion con la que va a recargar su cuenta: " << endl;
    cout << "1- Efectivo" << endl;
    cout << "2- Transferencia bancaria" << endl; // tratar de conectar esto con daviplata (eso para el proximo sprint jajaaj)
    cout << "3- codigo regalo" << endl;          
    cout << "4- salir" << endl;

    cin >> eleccion;

    switch (eleccion)
    {
    case 1:// recargar en efectivo
        float aux_r;
        cout << "por favor dirijase a un punto nequi para hacer su recarga en efectivo" << endl;
        cout << "-----------Punto de recarga nequi ----------------------" << endl;
        cout << "Digite la cantidad de dinero a  recargar: " << endl;
        cin >> aux_r;//pide el dinero para hacer la recarga
        p.setSaldo(p.getSaldo() + aux_r);//lo actualiza en el saldo

        break;
    case 2://trasferencia bancaria
        int eleccion;
        cout << "Por favor seleccione su banco: " << endl;
        cout << "1- Banco de bogota" << endl;
        cout << "2- Davivienda" << endl;
        cout << "3- Bancolombia" << endl;
        cout << "4- Banco caja social" << endl;
        cout << "5- Banco AV Villas" << endl;//escojer un banco para hacer la recarga
        cin >> eleccion;
        float aux_rr;
        cout << "Digite la cantidad de dinero a  recargar: " << endl;
        cin >> aux_rr;//pide la cantidad para recargar
        p.setSaldo(p.getSaldo() + aux_rr);//actualiza el saldo
        break;
    case 3://codigo regalo
        int codigo_regalo;
        static float saldo_aux3 = 0;
        cout << "digite su codigo de regalo: " << endl;
        cin >> codigo_regalo;//pide el codigo de regalo

        static auto it = find_if(lista_regalos.begin(), lista_regalos.end(),//obtiene la poscision del codigo dentro de la lista
                                 [codigo_regalo](const regalo &q)
                                 { return q.getCodigo() == codigo_regalo; });//revisa que el codigo exista en la lista de codigos para ser valido

        if (it != lista_regalos.end())
        {
            saldo_aux3 = it->getCantidad();
            p.setSaldo(p.getSaldo() + saldo_aux3);//hace la recarga y actualiza el saldo
            cout << "recarga exitosa" << endl;
            lista_regalos.erase(it);//borra el codigo de la lista asi no se puede volver a usar
        }
        else
        {
            cout << "El codigo de regalo no es valido o ya ha sido utilizado." << endl;//dice si el codigo es invalido o ya se uso
        }
        break;

    case 4:
        return;
        break;

    default:
        break;
    }
}

void enviar_plata(usuario &p, usuario &r, float monto, int eleccion)//metodo enviar plata a otros nequi
{
    switch (eleccion)
    {
    case 1://envia a otro nequi
        if (p.getSaldo() < monto)
        {
            cout << "El saldo no es suficiente para enviar dinero" << endl;//revisa si el monto es valido para poderlo pasar
            return;
        }

        p.setSaldo(p.getSaldo() - monto);//lo saca de la cuneta saliente
        r.setSaldo(r.getSaldo() + monto);// lo pasa a la cuenta entrante

        break;
    case 2://genera los codigos para recargar
        static int aux22 = 0;//guarda el codigo

        if (p.getSaldo() < monto)//revisa si el monto es valido
        {
            cout << "El saldo no es suficiente para crear codigo" << endl;
            return;
        }
        p.setSaldo(p.getSaldo() - monto);//saca el monto del saldo
        aux22 = generar_codigos();//genera el codigo aleatorio y lo guarda en la variable
        cout << "codigo generado correctamente ------------------------------------------------------------ " << aux22 << endl;
        static regalo aux(p.getNumeroDocumento(), aux22, monto);//crea el objeto regalo
        lista_regalos.push_back(aux);//lo pasa a la lista
        break;

    case 3:
        return;
        break;
    default:
        break;
    }
}

void sacar_plata(usuario &p)//metodo sacar plata
{

    static int aux23 = 0;
    float aux;
    cout << "Digite la cantidad de dinero a retirar: " << endl;
    cin >> aux;//pide el dinero para retirar

    if (p.getSaldo() < aux)//valida si el monto es viable para sacar
    {
        cout << "El saldo no es suficiente para crear codigo" << endl;
        return;
    }
    aux23 = generar_codigos();//genera un codigo para retirar
    cout << "use este codigo para retirar -------------------------------------------------- " << aux23 << endl;
    p.setSaldo(p.getSaldo() - aux);//actualiza el saldo
}

void bolsillo(usuario &p)//metodo bolsillo
{

    cout << "-------------- saldo en bolsillos: " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "bolsillo[" << i + 1 << "]: " << p.getBolsillo(i) << endl;//muesta lo que hay en los 3 bolsillos
    }
    int eleccion;
    cout << "que desea hacer?: " << endl;
    cout << "1- agregar dinero a los bolsillos" << endl;
    cout << "2- retirar dinero de los bolsillos" << endl;
    cout << "3- salir" << endl;
    cin >> eleccion;

    switch (eleccion)
    {
    case 1://agregar dinero a los bolsiloos
        float bolsillo_dinero;
        cout << "Digite el valor de dinero que desea pasar al bolsillo: " << endl;
        cin >> bolsillo_dinero;//saca el dinero del saldo

        if (p.getSaldo() < bolsillo_dinero)
        {//valida que el monto sea valido
            cout << "El saldo no es suficiente para pasar dienro al bolsillo" << endl;
            return;
        }
        p.setSaldo(p.getSaldo() - bolsillo_dinero);//actualiza el saldo

        int eleccion_2;
        cout << "seleccione el bolsillo al que quiere pasar la plata: " << endl;
        cout << "1- bolsillo 1" << endl
             << "2- bolsillo 2" << endl
             << "3- bolsillo 3" << endl;
        cin >> eleccion_2;//selecciona alguno de los 3 bolsillos
        switch (eleccion_2)
        {
        case 1:
            p.setBolsillo(bolsillo_dinero, p.getBolsillo(1), p.getBolsillo(2));//hace recarga bolsillo 1
            break;

        case 2:
            p.setBolsillo(p.getBolsillo(0), bolsillo_dinero, p.getBolsillo(2));//hace recarga bolsillo 2
            break;

        case 3:
            p.setBolsillo(p.getBolsillo(0), p.getBolsillo(1), bolsillo_dinero);//hace recarga bolsillo 3
            break;

        default:
            break;
        }
        break;
    case 2://retira la plata - la pasa al saldo

        int eleccion_3;
        cout << "seleccione el bolsillo del que quiere sacar la plata: " << endl;
        cout << "1- bolsillo 1" << endl
             << "2- bolsillo 2" << endl
             << "3- bolsillo 3" << endl;
        cin >> eleccion_3;//selecciona el bolsillo del que quiere sacar la plata

        switch (eleccion_3)
        {

        case 1:
            p.setSaldo(p.getSaldo() + p.getBolsillo(0));//actualiza el saldo
            p.setBolsillo(0, p.getBolsillo(1), p.getBolsillo(2));//saca la plata bolsillo 1
            cout << "la plata ya fue devuelta al saldo de tu cuenta" << endl;
            break;

        case 2:
            p.setSaldo(p.getSaldo() + p.getBolsillo(1));//actualiza el saldo
            p.setBolsillo(p.getBolsillo(0), 0, p.getBolsillo(2));//saca la plata bolsillo 2
            cout << "la plata ya fue devuelta al saldo de tu cuenta" << endl;
            break;

        case 3:
            p.setSaldo(p.getSaldo() + p.getBolsillo(2));//actualiza el saldo
            p.setBolsillo(p.getBolsillo(0), p.getBolsillo(1), 0);//saca la plata bolsillo 3
            cout << "la plata ya fue devuelta al saldo de tu cuenta" << endl;
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
}

void meta(usuario &p)//metodo meta de ahorro
{

    cout << "--------------- meta actual: " << p.getMeta(0) << endl;//ver la meta
    cout << "-------- ahorro actual: " << p.getMeta(1) << endl;// ver ahorro en la meta
    int eleccion;
    cout << "que deseas hacer? " << endl;
    cout << "1- cambiar meta" << endl
         << "2- agregar dinero a la meta" << endl
         << "3- retirar dinero de la meta" << endl
         << "4- salir" << endl;
    cin >> eleccion;

    switch (eleccion)
    {
    case 1://actualioza la meta de ahorro
        float aux1;
        cout << "Digite la nueva meta de ahorro: " << endl;
        cin >> aux1;

        if (p.getMeta(0) > aux1)//nueva meta no puede ser menor a anterior meta
        {

            cout << "la nueva meta no puede ser menor a la meta antigua" << endl;
            return;
        }

        p.setMeta(aux1, p.getMeta(1));//actualiza meta
        cout << "meta actualizada correctamente" << endl;
        break;
    case 2:
//pasa dienro al ahorro de la meta
        float aux2;
        cout << "Digite cuanto dinero vas a pasar: " << endl;
        cin >> aux2;

        if (p.getSaldo() < aux2)//valida el saldo si s epuede sacar el dinero
        {

            cout << "El saldo no es suficiente para pasar a la meta" << endl;
            return;
        }

        p.setSaldo(p.getSaldo() - aux2);//actualiza saldo
        p.setMeta(p.getMeta(0), (p.getMeta(1) + aux2));//actualiza ahorro en la meta

        cout << "se paso la plata al la meta" << endl;

        break;

    case 3://retirar de la meta

        if (p.getMeta(0) != p.getMeta(1))//solo si la meta y el ahorro son iguales
        {
            cout << "error, aun no se ha cumplido la meta " << endl;
        }

        p.setSaldo(p.getSaldo() + p.getMeta(1));//pasa el dienro al saldo
        p.setMeta(0, 0);//pone la meta de nuevo en 0
        cout << "la plata ya fue devuelta al saldo de tu cuenta " << endl;

        break;
    case 4:
        return;
        break;

    default:
        break;
    }
}
//______________________________________________________________________________________________________

void menu_app(int long long usuario_logeado)//metodo del menu del aplicativo
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
                cin >> eleccion;//selecciona la opcion 
                switch (eleccion)
                {
                case 1:
                    break;
                case 2:
                    meta(p);//meta de ahorro
                    break;
                case 3:
                    bolsillo(p);//bolsillos de ahorro
                    break;
                case 4:
                    recargar(p);//recargar cuenta
                    break;
                case 5:
                    sacar_plata(p);//sacar plata
                    break;
                case 6://pasar plata a otro nequi
                    static float auxiliar_saldo = 0;
                    static usuario *enviar = nullptr;//objeto auxiliar otro nequi
                    int eleccion;
                    cout << "seleccione la opcion para enviar dinero: " << endl;
                    cout << "1- A otro nequi" << endl;
                    cout << "2- Codigo de regalo" << endl;
                    cout << "3- Salir" << endl;
                    cin >> eleccion;//selecciona la opcion del menu

                    if (eleccion == 1)
                    {//pasar a otro nequi

                        int long long auxiliar_numero;
                        cout << "digite el numero a enviar plata: " << endl;
                        cin >> auxiliar_numero;//pide el numero de celular

                        for (usuario &q : lista_usuario) // encuentra el numero celular
                        {
                            if (auxiliar_numero == q.getNumeroCelular())
                            {
                                enviar = &q;//devuelve la poscision en la lsita
                                break;
                            }
                        }

                        if (enviar == nullptr)
                        {//si no existe usuario
                            cout << "El usuario no se encuentra registrado" << endl;
                            return;
                        }

                        cout << "digite la cantidad de dinero a enviar: " << endl;
                        cin >> auxiliar_saldo;//pide el dinero a pasar
                    }
                    if (eleccion == 2)
                    {//generar codigo para regargar
                        cout << "digite la cantidad de dinero a convertir en codigo: " << endl;
                        cin >> auxiliar_saldo;//pide saldo
                    }

                    enviar_plata(p, *enviar, auxiliar_saldo, eleccion);//metodo para enviar plata
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
            usuario_logeado = p.getNumeroDocumento();//guarda nuemro de documeto usuario loggeado
            bandera = true;
        }
    }
    if (bandera == false)
    {
        cout << "usuario no registrado" << endl;
    }

    return usuario_logeado;//retorna ese numero de documento
}