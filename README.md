# Instalación y Ejecución de Pruebas con Google Test (GTest)

Google Test, también conocido como GTest, es un marco de pruebas C++ ampliamente utilizado que facilita la escritura y ejecución de pruebas unitarias. Este tutorial te guiará a través del proceso de instalación y ejecución de pruebas utilizando Google Test en C++. Para más informacion visitar la [Documentación de Google Test](https://google.github.io/googletest/)

## Introducción

Google Test es una biblioteca de pruebas unitarias que se utiliza para evaluar el comportamiento de las funciones y componentes de un programa C++. Las pruebas unitarias son esenciales para asegurar que tu código funcione correctamente. Google Test proporciona un entorno de pruebas flexible y poderoso para ayudarte a escribir y ejecutar pruebas de manera efectiva.

## Requisitos

Antes de continuar, asegúrate de tener instalados los siguientes componentes en tu sistema:

- C++
- CMake

A continuación, te guiaré a través de los pasos necesarios para instalar Google Test y ejecutar pruebas en tu entorno de desarrollo C++.

## Índice

- [Instalación MSYS2 con GCC, G++, GDB y Make en Windows](#instalación-msys2-con-gcc-g-gdb-y-make-en-windows)
- [Instalación de CMake en Windows](#instalación-de-cmake-en-windows)
- [Instalación de Google Test en Windows](#instalación-de-google-test-en-windows)
- [Ejecutar Casos de Prueba con Google Test en C++](#ejecutar-casos-de-prueba-con-google-test)

## Instalación MSYS2 con GCC, G++, GDB y Make en Windows

Sigue estos pasos para instalar MSYS2 con todas las herramientas necesarias:

1. **Descargar MSYS2:**

   - Ve al [sitio web oficial de MSYS2](https://www.msys2.org/) y descarga el instalador adecuado para tu sistema (32 o 64 bits).

2. **Instalar MSYS2:**

   - Ejecuta el instalador que descargaste y sigue las instrucciones del asistente de instalación. Asegúrate de seleccionar la ruta de instalación y las opciones adecuadas según tus preferencias.

3. **Abrir MSYS2:**

   - Una vez instalado, ejecuta "MSYS2 MSYS" desde el menú de inicio. Esto abrirá la terminal de MSYS2.

4. **Actualizar el sistema:**

   - En la terminal de MSYS2, actualiza el sistema y los paquetes a las últimas versiones con los siguientes comandos:

   ```bash
    pacman -Syu
   ```

5. **Instalar GCC y G++:**

   - Para instalar GCC (el compilador de C) y G++ (el compilador de C++), utiliza el siguiente comando:

   ```bash
    pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gcc-c++
   ```

6. **Instalar GDB:**

   - Para instalar GDB (el depurador de GNU), ejecuta el siguiente comando:

   ```bash
    pacman -S mingw-w64-x86_64-gdb
   ```

7. **Instalar Make:**

   - Para instalar Make, utiliza el siguiente comando:

   ```bash
    pacman -S make
   ```

8. **Agregar MSYS2 al PATH:**

   - Para utilizar MSYS2 desde el símbolo del sistema de Windows o desde otras aplicaciones, debes agregar MSYS2 al PATH. Para ello, encuentra la ruta de instalación de MSYS2 (por ejemplo, **C:\Program Files\msys64\mingw64\bin**) y agrega esta carpeta al PATH de Windows. Puedes hacerlo desde la configuración avanzada del sistema en Windows en la ventana variables de entorno.

9. **Verificar la instalación:**

   - Puedes verificar que GCC, G++, GDB y Make estén instalados correctamente ejecutando los siguientes comandos en la terminal de MSYS2:

   ```bash
    gcc --version
    g++ --version
    gdb --version
    mingw32-make --version
   ```

## Instalación de CMake en Windows

CMake es una herramienta ampliamente utilizada para la construcción y gestión de proyectos de software en Windows. Sigue estos pasos para instalar CMake en tu sistema:

1. Descargar el instalador

   - Ve al [sitio web oficial de CMake](https://cmake.org/download/). En la sección "Latest Release," busca la Distribución Binaria de la última versión estable para Windows x64 ZIP. Descarga el archivo ZIP en tu computadora.

2. Ejecutar el instalador

   - Descomprime el archivo ZIP que descargaste. Y copia la carpeta resultante a una ubicación en tu sistema. Por ejemplo, puedes copiarla a `D:\Program Files\CMake`.

3. Configurar la instalación

   - Para agregar CMake al PATH del Sistema, copia la dirección de la carpeta "bin" en la que se encuentra el ejecutable de CMake. La dirección podría ser algo similar a: `D:\Program Files\CMake\cmake-3.28.0-rc3-windows-x86_64\bin`

4. Verificar la instalación

   - Abre una ventana de línea de comandos, como el Símbolo del Sistema o PowerShell. Y ejecuta el siguiente comando para verificar que CMake se ha instalado correctamente:

   ```bash
   cmake --version
   ```

   - Esto mostrará la versión de CMake que has instalado en tu sistema.

## Instalación de Google Test en Windows

Sigue estos pasos para instalar Google Test en Windows:

1. **Clonar el repositorio de Google Test:**

   - Abre una terminal (por ejemplo, MSYS2 o Git Bash).
   - Ejecuta el siguiente comando para clonar el repositorio de Google Test desde GitHub:

     ```bash
     git clone https://github.com/google/googletest.git
     ```

2. **Crear una carpeta de compilación:**

   - En la carpeta recién clonada, crea una carpeta llamada "build". Esto es donde generaremos los archivos de compilación.

3. **Acceder a la carpeta de compilación:**

   - Abre una terminal y navega hasta la carpeta de compilación que acabas de crear:

     ```bash
     cd ruta/a/tu/carpeta/googletest/build
     ```

4. **Generar archivos de compilación:**

   - En la terminal, ejecuta el siguiente comando para configurar los archivos de compilación con CMake y MinGW Makefiles:

     ```bash
     cmake -G "MinGW Makefiles" ..
     ```

5. **Compilar Google Test:**

   - A continuación, compila Google Test ejecutando el siguiente comando:

     ```bash
     make
     ```

   - Si el comando anterior no funciona, intenta con el siguiente comando:

     ```bash
     mingw32-make
     ```

6. **Copiar archivos y carpetas:**

   - Copia los archivos de la ruta `..\googletest\build\lib` y pégalos en `..\msys64\mingw64\lib`.

   - Copia las carpetas `..\googletest\googletest\include\gtest` y `..\googletest\googlemock\include\gmock` y pégalas en `..\msys64\mingw64\include`.

Con estos pasos, habrás instalado Google Test en tu entorno de desarrollo C++ en Windows. Ahora puedes utilizar Google Test para realizar pruebas unitarias en tus proyectos C++.

## Ejecutar Casos de Prueba con Google Test

Para ejecutar los casos de prueba incluidos en el archivo `main.cpp`, sigue estos pasos:

1. **Compilar el archivo de prueba:**

   - Abre una terminal en la ubicación del archivo `main.cpp`.

   - Ejecuta el siguiente comando para compilar el archivo y generar un ejecutable llamado `main.exe`, enlazando con la biblioteca Google Test (`-lgtest`):

     ```bash
     g++ main.cpp -o main -lgtest
     ```

2. **Ejecutar el programa de prueba:**

   - Una vez que se ha generado el ejecutable, puedes ejecutarlo utilizando el siguiente comando:

     ```bash
     ./main.exe
     ```

3. **Resultado esperado:**

   - Tras ejecutar el programa, deberías obtener un resultado similar al siguiente:

     ![Resultado de la ejecución de los casos de prueba](execution.png)

   - Esto mostrará los resultados de los casos de prueba, indicando si pasaron correctamente o si se encontraron errores.

Con estos pasos, habrás ejecutado con éxito los casos de prueba utilizando Google Test en C++. El archivo `main.cpp` contiene casos de prueba para calcular el factorial. Puedes utilizar este flujo para probar tus propios programas y comprobar su comportamiento bajo diferentes condiciones.
