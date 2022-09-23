//Esto es solo para dar el formato de texto que requiere intelisis, posteriormente se agregará a un archivo

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string pedido, cliente, mensaje;
    cin >> pedido;
    cin >> cliente;
    
    getline(cin, mensaje);

    cout << "Pedido: " << pedido << endl; 
    cout << "Cliente: " << cliente << endl; 
    cout << "Mensaje: " << mensaje << endl;

return 0;
}