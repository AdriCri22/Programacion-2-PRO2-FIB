# Programacion-2-PRO2-FIB
Encuentra las prácticas de laboratorio sobre la asignatura de Programación II (PRO2) de la Facultad de Ingeniería Informática (FIB) de la Universidad Politécnica de Catalunya (UPC).

Para comprimir archivos el .tar:
  - En Linux:
  
      Para comprimir archivos concretos:
              
        tar -cvf archivo.tar archivo.hh archivo.cc
                
      Para comprimir todos los archivos con la extensión .cc
      
        tar -cvf archivo.tar *.cc
                
  - En Windows descargar el programa 7-Zip.
  
  Para tener un ejemplo del Makefile consultad la práctica del trabajo final https://github.com/AdriCri22/Programacion-2-PRO2-FIB/tree/main/Trabajo%20Final.
  
Para compilar y ejecutar programas:    
  - En Linux:
       
        g++ -O2 -Wall -std=c++11 -o PROGRAM_NAME PROGRAM_NAME.cc
        ./PROGRAM_NAME
        
  - En Windows: 
        
        g++ -c PROGRAM_NAME.cc
        g++ -o program.exe PROGRAM_NAME.o
        program.exe
  
  Para compilar todos los archivos de una misma extensión se puede usar:
      
       *.cc
   En este caso compilamos todos los .cc
