# Практические занятия школы

## День 2

__Практика 1.__ Сысоев А.В. Параллельное программирование на OpenMP

  Запись трансляции: [Cсылка](http://cloud.unn.ru/s/b7rQfRHSysoYzf6)

 __Практика 2.__ Волокитин В. Профилирование и бенчмаркинг

  Презентация: [Cсылка](2.2._Volokitin_ParallelStudio.pdf)

  Запись трансляции: [Ссылка](http://cloud.unn.ru/s/CWDQkw2JaCtCHWm)

  Задание на практику:
    В папке расположен архив с исходным кодом [HPC2019-1-baseline-git.zip](HPC2019-1-baseline-git.zip). Нужно повторить действия из презентации.

  Инструкции к практике:

    Нужно установить Visual Studio 2017 или 2019, и oneAPI Base Toolkit (Classic Compiler, Vtune, Advisor) или Parallel Studio (Compiler, VTune и Advisor)



## День 3

 __Практика 1.__ Тюрин Е. Использование оптимизирующих компиляторов

  Инструкции к практике:

  Requirements:
  VS 2019 Community Edition;
  Git (>= 1.7.10);
  ~80 GB free space (preferably on SSD).

  If you’d like to follow along, it’s better to pre-build the compiler as it is a *very* time consuming process, especially on non-server desktops and laptops.
  I will be showing everything on Windows via Visual Studio, however you are free to choose your own tools and operating systems.

  1. Install the latest CMake, via following URL: https://github.com/Kitware/CMake/releases/download/v3.19.3/cmake-3.19.3-win64-x64.msi


  2. Clone the following Git repository:
  so that the local path to the repository has no spaces (!)
  git clone --config core.autocrlf=false --single-branch --branch release/11.x https://github.com/turinevgeny/llvm-project


  3. If the local VS 2019 Community Edition main executable devenv.exe is not located at:
  C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe
  change the corresponding path in the llvm-project/deploy.bat file so that it points to the local VS 2019 Community Edition devenv.exe executable.


  4. a. If you’re not very comfortable with Visual Studio:
  Run CMD, change the directory to the local llvm-project folder checked out during step 2, and run the following batch file:
  deploy.bat
  This operation will take a *lot* of time - make sure that the batch file run is completed.

  Make sure the following executables are built (llvm-project\llvm\build\Debug\bin)
  clang
  opt
  llvm-dis
  llvm-as

  4. b. If you feel like you are comfortable with Visual Studio and tools.
  You may attempt to build only the required executables (clang, opt, llvm-dis, llvm-as).
  This requires more actions, but is expected to be completed sooner than 4a.
  I haven’t tested this, but can’t imagine why it wouldn’t work (since if you’ve picked this option you should be able to fix any surprise issues).
  Open the solution file LLVM.sln (llvm-project\llvm\build), locate the aforementioned projects (clang is under “Clang executables”, opt, llvm-dis and llvm-as are under “Tools”), build them one by one.



__Практика 2.__ Новожилов М. Инструкции SIMD. Векторизация кода с использованием возможностей компиляторов

  Инструкции к практике:

  1.	Разархивируйте архив Benchmark1.zip 
  2.	Соберите проект из архива, запустите 
  3.	Рассмотрите пример автовекторизованной функции threshold1 и функции threshold2, которую компилятор автовекторизовать не может 
  4.	Обоснуйте производительность функций medianBlur3x3Vintage и medianBlur3x3 
  5.	Сравните производительность функций accumulateSqr и accumulateSqrSSE, найдите причины разницы в производительности 


## День 4

## День 5
