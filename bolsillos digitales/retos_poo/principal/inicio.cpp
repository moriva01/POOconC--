#include "salud/persona.exe"

using namespace std;

int main()
{
    persona persona1 = persona::pedirDatos();
    persona1.mostrarPersona(persona1);

    return 0;
}