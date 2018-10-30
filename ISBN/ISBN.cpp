//  A01381334 Jose Antonio Hernández Hernández
//  main.cpp
//  ISBN
//  Algoritmo
//  Declara variables string para los nueve digitos que proporcionaran y el isbn completo, char para respuesta s/n y digito de control, e int para calcular el digito de control
//  Hacer un ciclo do while mientras la respuesta sea s ya que hace antes de la verificacion s/n donde pida al usuario 9 digitos isbn
//  Recibir los nueve digitos y hacer un contador de 0 a 8 por ser 9 chars en el arreglo string
//  Dentro del conteo transformar el valor char a int restandole 48 ir sumando a la vez que se le suma el numero de espacio real que se utiliza ejemplo (*1, *2, *3....,*9)
//  Al haber sumado los nueve digitos multiplicados cada uno por su posicion conseguir el residuo de dicho numero si se dividiera entre 11 (%11)
//  Se cosigue asi el digito de control ahora transformarlo a char para poder concatenarlo la transformacion se realiza con un switch y en caso del residuo ser 10 transforma a X
//  Concatenar el parcial de 9 digitos isbn mas un guion mas el digito de control, desplegarlo al usuario
//  Desplegar letrero preguntando si necesita otro numero isbn
//  CASOS DE PRUEBA
//  Teclea el número de 9 dígitos 842053211
//  El ISBN es 842053211-8 Otro? S
//  Teclea el número de 9 dígitos 032130332
//  El ISBN es 032130332-6 Otro? S
//  Teclea el número de 9 dígitos 043935806
//  El ISBN es 043935806-X Otro? N
//  Created by Jose Antonio on 11/01/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    // declaracion de variables...
    int iTotal, iControl;
    char cRespuesta, cControl;
    string sParcial, sISBN;
    // ciclo do while...
    do{
        iTotal=0;
        cout << "Teclea el número de 9 dígitos" << endl; // pregunta al usuario los primeros 9 digitos del isbn
        cin >> sParcial; // consigue ese parcial
        for(int i=0; i<9; i++){ // ciclo for que suma cada char como int
            iTotal+= (sParcial[i] - 48)*(i+1); //funcion que transforma de char a int y va sumando tales digitos multiplicados por su posicion real en el arreglo
        }
        iControl=iTotal%11; // funcion que consigue el residuo despues de dividir entre 11
        // condicional que transforma el int al char correspondiente dada por la funcion del digito de control para poder concatenar el isbn final...
        switch (iControl){
            case 0: cControl='0';
                break;
            case 1: cControl='1';
                break;
            case 2: cControl='2';
                break;
            case 3: cControl='3';
                break;
            case 4: cControl='4';
                break;
            case 5: cControl='5';
                break;
            case 6: cControl='6';
                break;
            case 7: cControl='7';
                break;
            case 8: cControl='8';
                break;
            case 9: cControl='9';
                break;
            default: cControl='X';
                break;
        }
        // concatena isbn parcial con guion y digito de control
        sISBN=sParcial + "-" + cControl;
        cout << sISBN << endl; // despliega isbn final
        cout << "Otro?" << endl; // pregunta al usuario si seguir o continuar
        cin >> cRespuesta; // recibe la respuesta del usuario
    } while (cRespuesta == 's'); // estatuto que segun la respuesta termina o repite el ciclo do while
    return 0;
}

