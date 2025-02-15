# Документация проекта: Игра "Виселица"

## Оглавление
1. [Введение](#введение)
2. [Функциональность](#функциональность)
3. [Структура проекта](#структура-проекта)
   - [Основные функции](#основные-функции)
   - [Структура данных](#структура-данных)
4. [Описание работы игры](#описание-работы-игры)
   - [Выбор категории](#выбор-категории)
   - [Игровой процесс](#игровой-процесс)
   - [Завершение игры](#завершение-игры)
5. [Пример использования](#пример-использования)
6. [Заключение](#заключение)

---

## Введение

Игра "Виселица" — это классическая игра, в которой игроку необходимо угадать слово, выбирая буквы. В данном проекте реализована версия игры на языке C, где игрок может выбрать категорию слов и угадывать слово из выбранной категории. Проект включает в себя функции для выбора случайного слова, отображения текущего состояния игры и обработки ввода пользователя.

---

## Функциональность

- **Выбор категории:** Игрок может выбрать одну из пяти категорий слов.
- **Случайное слово:** Игра выбирает случайное слово из выбранной категории.
- **Отображение прогресса:** Игрок видит текущее состояние угаданного слова и количество оставшихся попыток.
- **Визуализация виселицы:** Игра отображает виселицу, которая "строится" с каждой ошибкой.
- **Завершение игры:** Игра завершается, когда игрок угадывает слово или исчерпывает все попытки.

---

## Структура проекта

### Основные функции

1. **`choose_random_word(category)`**  
   Выбирает случайное слово из указанной категории.

2. **`display_hangman(tries_left)`**  
   Отображает текущее состояние виселицы в зависимости от количества оставшихся попыток.

3. **`display_progress(word, guessed)`**  
   Отображает текущее состояние угаданного слова, показывая угаданные буквы и скрывая неугаданные.

4. **`play_hangman()`**  
   Основная функция, управляющая игровым процессом.

---

### Структура данных

1. **Категории и слова:**
   - Массив `categories` содержит названия категорий.
   - Массив `words` содержит слова для каждой категории.

2. **Состояние игры:**
   - `guessed` — массив, указывающий, какие буквы слова уже угаданы.
   - `tries_left` — количество оставшихся попыток.
   - `correct_guesses` — количество правильно угаданных букв.

---

## Описание работы игры

### Выбор категории

1. Игроку предлагается выбрать одну из пяти категорий:
   - Фрукты.
   - Животные.
   - Страны.
   - Спорт.
   - Технологии.

2. После выбора категории игра случайным образом выбирает слово из этой категории.

---

### Игровой процесс

1. Игроку показывается текущее состояние угаданного слова (например, `_ _ _ _ _`).
2. Игрок вводит букву.
3. Если буква есть в слове, она отображается на своих позициях.
4. Если буквы нет в слове, количество оставшихся попыток уменьшается, и отображается новая часть виселицы.
5. Игра продолжается до тех пор, пока игрок не угадает слово или не исчерпает все попытки.

---

### Завершение игры

1. **Победа:** Если игрок угадывает все буквы слова, игра завершается с сообщением о победе.
2. **Поражение:** Если игрок исчерпывает все попытки, игра завершается с сообщением о поражении и показывает загаданное слово.

---

## Заключение

Проект "Виселица" представляет собой классическую игру, реализованную на языке C. Игра проста в использовании и может быть расширена за счет добавления новых категорий, слов или улучшения интерфейса. Проект подходит для обучения основам программирования и работы с массивами, строками и функциями.
