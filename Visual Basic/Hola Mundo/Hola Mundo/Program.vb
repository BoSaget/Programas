Imports System
Imports System.Collections.Specialized

Module Program
    Sub Main(args As String())

        'NOTA:   Para aplicar un color a todo del fondo de la consola se debe utilizar Console.Clear() antes de todo el codigo
        Console.BackgroundColor = ConsoleColor.DarkYellow
        Console.Clear()

        'Aqui se debería de ver un texto de color blanco
        Console.WriteLine("Hola Mundo de color blanco")

        'Aqui se debería de ver un texto de color cyan
        Console.ForegroundColor = ConsoleColor.Cyan
        Console.WriteLine("Hola mundo pero de color bonito")

        Console.ForegroundColor = ConsoleColor.DarkRed

    End Sub
End Module
