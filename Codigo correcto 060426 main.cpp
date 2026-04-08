#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class persona {
private:
    string nombre, apPaterno, apMaterno;
    int dia, mes, anio;
    
public:
    void capturar() {
        cout <<"Nombre: ";
        cin >> nombre;
        
        cout << "Apellido paterno: ";
        cin >> apPaterno;
        
        cout << "Apellido materno (si no tienes escrite X): ";
        cin >> apMaterno;
        
        cout << "Dia de nacimiento: ";
        cin >> dia;
        
        cout << "Mes de nacimiento: ";
        cin >> dia;
        
        cout << "Anio de nacimiento: ";
        cin >> anio;
    }
    
    char obtenerVocal(string palabra) {
        for (int i = 1; i < palabra.length(); i++) {
            char c = toupper(palabra[i]);
            if (c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
                return c;
            }
        }
        return 'X';
    }
    
    string generarRFC() {
        string rfc = "";
        
        // 1 y 2 
        rfc += toupper(apPaterno[0]);
        rfc += obtenerVocal(apPaterno);
        
        // 3
        if (apMaterno != "X")
            rfc += toupper(apMaterno[0]);
            else
                rfc += 'X';
                
        // 4 
        rfc += toupper(nombre[0]);
        
        // 5 y 6 (año)
        rfc += to_string(anio).substr(2,2);
        
        // 7 y 8 (mes)
        if (mes < 10) rfc += "0";
        rfc += to_string(mes);
        
        // 9 y10 (dia)
        if (dia < 10) rfc += "0";
        rfc += to_string(dia);
        
        return rfc;
        
    }
};

int main(){
    persona p;
    
    p.capturar();
    
    cout << "RFC generado: " << p.generarRFC() << endl;
    return 0;
}