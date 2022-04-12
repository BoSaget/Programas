package com.mycompany.tutorial;
import java.util.Scanner;
/**
 *
 * @author LeonT
 */
public class Tutorial 
{
    static int Funcion(int numero)
    {
        if (numero == 0)
        {
            System.out.println("No me he ejecutado ninguna vez");
        }
        
        else if (numero == 1)
        {
            System.out.println("Me he ejecutado " + numero + " vez");
        }
        
        else
        {
            System.out.println("Me he ejecutado " + numero + " veces");
        }
        numero ++;
        return numero;
    }
    
    public static void main(String[] args) 
    {
        System.out.println("Hola Mundo");
        System.out.println("Esto es una prueba");
        
        System.out.println("Tipos de datos");
        
        int numeroEntero = 1;
        System.out.println("Impresion de un entero: " + numeroEntero);
        
        float numeroFloat = 2.8f;
        System.out.println("Este es un flotante: " + numeroFloat);
        
        double numeroDoble = 2.8;
        System.out.println("Este es un double: " + numeroDoble);
        
        char caracter = 'a';
        System.out.println("Este es un caracter: " + caracter);
        
        String palabra = "Esto es una prueba aca maciza";
        System.out.println("Esto es una cadena: " + palabra);
        
        boolean bool = true;
        System.out.println("Esto es un booelano: " + bool);
        
        System.out.println("Condicionantes!!");
        
        if (bool == true && numeroEntero == 2)
        {
            System.out.println("Entro en el if");
        }
        
        else
        {
            System.out.println("Entro en el else");
        }
        
        System.out.println("Ciclo While!!");
        
        int iteracion = 0;
        while(iteracion < 11)
        {
            System.out.println("Iteracion numero" + (iteracion + 1));
            iteracion++;
        }
        
        System.out.println("Ciclo For");
        System.out.println("Tabla 5");
        for (int i = 1; i <= 10; i++) 
        {
            System.out.println("El resultado de: " + i + "x" + "5 es: " + (i*5));
        }
        
        System.out.println("Funciones");
        int ejecucion = 0;
        for (int i = 0; i <= 5; i++) 
        {
            ejecucion = Funcion(ejecucion);
        }
        
        System.out.println("Lectura de datos!!");
        Scanner entrada = new Scanner(System.in);
        System.out.println("Cual es tu nombre? ");
        
        String nombre = entrada.nextLine();
        System.out.println("Hola, " + nombre + ". Cuantos años tienes?");
        int edad = entrada.nextInt();
        System.out.println("ohh, ya veo con que tiene " + edad + " años");
        
        char algo = System.console().readline();
        System.out.println("La letra es: " + algo);
    }
}
