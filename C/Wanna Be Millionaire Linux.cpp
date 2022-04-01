#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void Answers (char ans, int question)
{
	bool correct = false;
	string answers = "vvfvfvvvvv";
	
	if (ans == answers[question])
	{
		correct = true;
	}
	
	system ("clear");
	if (correct == false)
	{
		cout << "Lo sentimos, mejor suerte para la proxima \nGAME OVER";
		cin >> ans;
		exit(0);
	}
	
	else
	{
		cout << "Respuesta correcta \n";
		cin >> ans;
	}
}

int Game(string name)
{
	int points;
	points = 0;
	char ans;
	
	//Primera pregunta
	system ("clear");
	cout << "Empecemos " << name <<"\tPuntos: "<< points << "\nPrimera pregunta... \n" << "1 Newton es lo mismo que 1kg*m/(s^2)? \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 0);
	
	points += 100;
	
	//Segunda pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nSegunda pregunta... \n" << "A los cables de red tambien se les dice cables Ethernet, esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 1);
	
	points += 100;
	
	//Tercera pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nTercera pregunta... \n" << "Un año luz es una medida de tiempo, esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 2);
	
	points += 100;
	
	//Cuarta pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nCuarta pregunta... \n" << "Las siglas TLC significan Tratado de Libre Comercio, esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 3);
	
	points += 100;
	
	//Quinta pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nQuinta pregunta... \n" << "El Helio es el elemento mas ligero, esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 4);
	
	points += 100;
	
	//Sexta pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nSexta pregunta... \n" << "Los 3 colores primarios en pintura son Rojo, Azul y Amarillo, esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 5);
	
	points += 100;
	
	//Septima pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nSeptima pregunta... \n" << "El logo de Apple hace referencia a Alan Turing, esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 6);
	
	points += 100;
	
	//Octava pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nOctava pregunta... \n" << "En el ajedrez la reina es la posicion mas poderosa, esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 7);
	
	points += 100;
	
	//Novena pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nNovena pregunta... \n" << "El Latin es la lengua madre de los lenguajes Italiano, Frances, etc... Esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 8);
	
	points += 100;
	
	//Decima pregunta
	system ("clear");
	cout <<"Puntos: "<< points << "\nDecima pregunta... \n" << "El aire caliente tiende a subir, esto es... \n";
	cout << "Verdadero (v) o Falso (f) \n";
	cin >> ans;
	Answers(ans, 9);
	
	points += 100;
	
	system ("clear");
	cout << "El codigo de tu premio es: 28102016 \n";
	cout << "Felicidades, llegaste hasta el final, pero por contestar todas las preguntas correctamente tienes una oportunidad de multiplicar tus puntos por 1000!!! \n";
	cout << "Lo unico que tienes que hacer es contestar una ultima pero muy complicada pregunta, si estas lista presiona (y) \n";
	cin >> ans;
	
	if (ans == 'y')
	{
		system ("clear");
		cout << "Puntos : " << points << "\nPregunta de Bonus: EL orden del arccoiris es Rojo, Naranja, Amarillo, Verde, Azu, Violeta, Verdadero(v) o Falso(f) \n";
		cin >> ans;
		
		if(ans == 'f')
		{
			cout << "Respuesta incorrecta \n GAME OVER";
			cin >> ans;
			exit (0);
		}
		
		else
		{
			points = points * 1000;
		}
	}
	
	if (points == 1000000)
	{
		system ("clear");
		cout << "Felicidades!!!\n" << "Tienes un codigo extra: 29102000 \n";
		cin >> ans;
	}
	
	
return 0;
}



void Codes (string name)
{
	int code;
	char ans;
	
	system("clear");
	cout << "Hola, "<< name << " te damos la bienvenida a la zona del canjeo de codigos, por favor ingresa un codigo: \n";
	cin  >> code;
	
	if(code == 29102000)
	{
		cout << "Felicidades, desbloqueaste un paquete de 50 hojas para InstaxMini \n";
	}
	
	else if (code == 28102016)
	{
		cout << "Felicidades, ganaste una instax mini 9 \n";
	}
	
	else
	{
		cout << "Codigo invalida, revisa bien tus codigos \n";
	}
	
	cout << "Tienes algun otro codigo, de ser asi presiona (y) \n";
	cin >> ans;
	
	if (ans == 'y')
	{
		Codes(name);
	}
}

int main (void)
{
	string name;
	char ans;
	int code;
	
	cout << "Hola!! \n" << "Cual es tu nombre \n";
	cin >>name;
	system ("clear");
	
	cout << "Hola, " << name << "\nBienvenida a la version pirateda de...Quisuera ser millonario!!! \n" << "Si quieres jugar presiona (y) \n";
	cin >> ans;
	
	if (ans == 'y')
	{
		system ("clear");
		cout << "Perfecto!! \nAntes que nada, " << name << "Queremos decirte que no es por dinero lo que vas a jugar, te daremos un codigo que despues tendras que insertar para saber tu premio \nEstas lista? (y) \n";
		cin >> ans;
		
		if (ans == 'y')
		{
			Game(name);
			Codes(name);
		
			system("clear");
			cout << "Te amo gordi Boli, espero que te gustara, y espero que ouedas tomar muchas fotos";
			cin >> ans;
		}
	}
	
return 0;
}
