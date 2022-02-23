// Pic2Ascii.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <iostream>
#include "Graffiti.h"
#include "FileSys.h"

int main()
{
    FileSys* fSys = new FileSys;
    fSys->get_current_path(); // valid files
    for (fs::path p : fSys->matches)
    {
        Graffiti* graffiti = new Graffiti(p.string());
        std::cout << p << '\n';
        graffiti->print();
        
        delete graffiti;
    }
    delete fSys;

   
    

    
    


    return 0;
}

