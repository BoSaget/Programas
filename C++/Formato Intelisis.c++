//Esto es solo para dar el formato de texto que requiere intelisis, posteriormente se agregará a un archivo

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
    string pedido, cliente, mensaje, movid;
    cin >> pedido;
    cin >> cliente;

    getline(cin, mensaje);

    cout << "Pedido: " << pedido << endl; 
    cout << "Cliente: " << cliente << endl;
    cout << "Mensaje: ";
    for(int i = 1; i < mensaje.size(); i++)
    {
        cout << mensaje[i];
    }
    cout << endl;

return 0;
}