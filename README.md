Задачи на C11 / C++20 с тестами gtest. Сборка: CMake + Ninja, ASan + UBSan.

    cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
    cmake --build build
    ctest --test-dir build --output-on-failure

| Неделя/день | Задача | Язык | Режим | Время | Заметка |
|---|---|---|---|---|---|