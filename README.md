Задачи на C11 / C++20 с тестами gtest. Сборка: CMake + Ninja, ASan + UBSan.

    cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
    cmake --build build
    ctest --test-dir build --output-on-failure

| Неделя/день | Задача | Язык | Режим | Время | Заметка |
|---|---|---|---|---|---|
| 5.1 | [popcount тремя способами](w05d1_popcount/) | C11 | обычный | 30 мин | clang с -Wconversion не предупреждает о конвертации, если она не может выйти за размер числа `count += n & 1`, gcc — да |
