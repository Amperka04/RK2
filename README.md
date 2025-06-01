#RK_2
##(Краткий отчет)
**Студента группы ИУ8-21, Барш Иван**

Репозиторий рк2: https://github.com/Amperka04/RK2.git

**Задание**
1. Добиться, если вдруг это не так, чтобы данный код собирался локально.
2. вынести все классы, которые используются в шаблоне проектирования в отдельный файл или файлы, чтобы они могли быть протестированы.
3. Сделать сборочный файл CMakeLists.txt, которой сделает статическую библиотеку с классами шаблона, а также исполняемый файл, как он и представлен в коде.
4. Написать хотя бы один тест для каждого конкретного класса.
5. Добавить этот тест в сборочный файл CMakeLists.txt, чтобы тест также собирался.
6. Написать скрипт github action, чтобы весь код и тесты собирались удаленно на github. Также собранные файлы нужно в пакет исполняемых файлов deb на ubuntu-latest.
7. Собранный пакет прикрепить в виде Release к проекту.



**Начало**
1. Скопировали нужный файлик *webpage_button.cpp* по заданию по ссылке ![Ссылка](https://github.com/taeguk/GoF-Design-Patterns/tree/master/Behavioral/Command)

2. Отвязали (на всякий) и привязали репозиторий снова. Добавили файл, закоммитили и запушили.
```sh
git add webpage_button.cpp
git commit -m "first commit"
git push origin master
```

3. В папке проекта RK2/ подключили гуглы
```sh
mkdir third-party
git submodule add https://github.com/google/googletest third-party/gtest
git add third-party/gtest
git commit -m"added gtest framework"
```

4. После этого разбили начальный файл на файлики с классами, а также прописали CMakLists.txt, и тесты (см папки **include, src, tests** и их содержимое в репозитории)

5. Собрали makefile в новосозданной отдельной папке /RK2/build
```sh
mkdir build && cd build
cmake ..
```
Вывод после команды:
```
-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE  
-- Configuring done (0.3s)
-- Generating done (0.0s)
-- Build files have been written to: /home/bivan/Amperka04/workspace/projects/RK2/build
```

6. Собрали проект командой *make* и получили следующий вывод:
```
[  5%] Building CXX object CMakeFiles/Patterns.dir/src/WebPageManager.cpp.o
[ 10%] Building CXX object CMakeFiles/Patterns.dir/src/ChangeWebPageCommand.cpp.o
[ 15%] Building CXX object CMakeFiles/Patterns.dir/src/Button.cpp.o
[ 21%] Linking CXX static library libPatterns.a
[ 21%] Built target Patterns
[ 26%] Building CXX object CMakeFiles/main_exe.dir/src/main.cpp.o
[ 31%] Linking CXX executable main_exe
[ 31%] Built target main_exe
[ 36%] Building CXX object third-party/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 42%] Linking CXX static library ../../../lib/libgtest.a
[ 42%] Built target gtest
[ 47%] Building CXX object third-party/gtest/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 52%] Linking CXX static library ../../../lib/libgtest_main.a
[ 52%] Built target gtest_main
[ 57%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 63%] Linking CXX static library ../../../lib/libgmock.a
[ 63%] Built target gmock
[ 68%] Building CXX object CMakeFiles/tests.dir/tests/WebPageManagerTest.cpp.o
[ 73%] Building CXX object CMakeFiles/tests.dir/tests/ChangeWebPageCommandTest.cpp.o
[ 78%] Building CXX object CMakeFiles/tests.dir/tests/GenericCommandTest.cpp.o
[ 84%] Building CXX object CMakeFiles/tests.dir/tests/ButtonTest.cpp.o
[ 89%] Linking CXX executable tests
[ 89%] Built target tests
[ 94%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
```
ура победа

7. Все в той же build запустили появившиеся файлы для проверки работоспособности проекта
```sh ./main_exe ```

Вывод:
```Change web page to http://taeguk.me.
This is generic command.
```


```sh ./tests ```

Вывод:
```
Running main() from /home/bivan/Amperka04/workspace/projects/RK2/third-party/gtest/googletest/src/gtest_main.cc
[==========] Running 5 tests from 4 test suites.
[----------] Global test environment set-up.
[----------] 1 test from WebPageManagerTest
[ RUN      ] WebPageManagerTest.ChangeWebPage
[       OK ] WebPageManagerTest.ChangeWebPage (0 ms)
[----------] 1 test from WebPageManagerTest (0 ms total)

[----------] 1 test from ChangeWebPageCommandTest
[ RUN      ] ChangeWebPageCommandTest.Execute
[       OK ] ChangeWebPageCommandTest.Execute (0 ms)
[----------] 1 test from ChangeWebPageCommandTest (0 ms total)

[----------] 1 test from GenericCommandTest
[ RUN      ] GenericCommandTest.Execute
[       OK ] GenericCommandTest.Execute (0 ms)
[----------] 1 test from GenericCommandTest (0 ms total)

[----------] 2 tests from ButtonTest
[ RUN      ] ButtonTest.Click
[       OK ] ButtonTest.Click (0 ms)
[ RUN      ] ButtonTest.ChangeCommand
[       OK ] ButtonTest.ChangeCommand (0 ms)
[----------] 2 tests from ButtonTest (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 4 test suites ran. (0 ms total)
[  PASSED  ] 5 tests.
```
ура победа2 

8. Далее на всякий случай закоммитим проделанную работу перед пунктами 6-7
```sh
git add .
git commit -m "Completed steps 1-5: code refactoring, CMake, tests"
```

9. Переходим к GitHub Actions. Создали папку и .yml файл со следующим содержанием
```sh
mkdir -p .github/workflows
nano .github/workflows/ci.yml
```

```
name: CI

on:
  push:
    branches: [ master ]
  pull_request:
    branches: [ master ]

jobs:
  build_and_test:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout repository
      uses: actions/checkout@v3
      with:
        submodules: 'recursive'  

    - name: Install dependencies
      run: |
        sudo apt-get update
        sudo apt-get install -y build-essential cmake

    - name: Create build directory
      run: mkdir build

    - name: Configure CMake
      working-directory: ./build
      run: cmake ..

    - name: Build project
      working-directory: ./build
      run: cmake --build . --config Release

    - name: Run tests
      working-directory: ./build
      run: ./tests

```

10. Добавили workflow в репозиторий
```sh
git add .github/workflows/ci.yml
git commit -m "Add GitHub Actions CI workflow"
git push origin master
```

11. Проверили Actions

12. 

13. 

14. 
