#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#define MAX_TRIES 6

char* categories[] = {"Fruits", "Animals", "Countries", "Sports", "Technology"};

char* words[][5] = {
    {"apple", "banana", "grape", "orange", "peach"},         // Fruits
    {"tiger", "elephant", "horse", "dog", "cat"},            // Animals
    {"russia", "france", "germany", "italy", "japan"},       // Countries
    {"football", "basketball", "tennis", "swimming", "boxing"}, // Sports
    {"computer", "phone", "printer", "television", "camera"}  // Technology
};

char* choose_random_word(int category) {
    srand(time(NULL));
    return words[category][rand() % 5];
}

void display_hangman(int tries_left) {
    switch (tries_left) {
        case 6:
            printf("\n\n\n\n\n");
            printf("_________\n");
            break;
        case 5:
            printf("\n |\n |\n |\n |\n");
            printf("_________\n");
            break;
        case 4:
            printf(" ________\n |/\n |\n |\n |\n");
            printf("_________\n");
            break;
        case 3:
            printf(" ________\n |/      |\n |       O\n |\n |\n");
            printf("_________\n");
            break;
        case 2:
            printf(" ________\n |/      |\n |       O\n |       |\n |\n");
            printf("_________\n");
            break;
        case 1:
            printf(" ________\n |/      |\n |       O\n |      /|\\\n |\n");
            printf("_________\n");
            break;
        case 0:
            printf(" ________\n |/      |\n |       O\n |      /|\\\n |      / \\\n");
            printf("_________\n");
            break;
    }
}

void display_progress(char* word, int* guessed) {
    printf("Word: ");
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i]) {
            printf("%c", word[i]);
        } else {
            printf("_");
        }
    }
    printf("\n");
}

void play_hangman() {
    int category;

    printf("Choose a category:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, categories[i]);
    }
    printf("Enter the category number: ");
    scanf("%d", &category);
    category -= 1;

    const char* word = choose_random_word(category);
    int word_length = strlen(word);
    int guessed[20] = {0};
    int tries_left = MAX_TRIES;
    int correct_guesses = 0;
    char guess;

    printf("Welcome to the 'Hangman' game!\n");
    printf("Guess the word from the category '%s'. You have %d attempts.\n", categories[category], MAX_TRIES);

    while (tries_left > 0 && correct_guesses < word_length) {
        display_hangman(tries_left);
        display_progress(word, guessed); 
        printf("Attempts left: %d\n", tries_left);
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = 1;
                correct_guesses++;
                found = 1;
            }
        }

        if (!found) {
            tries_left--;
            printf("Incorrect! Try again.\n");
        } else {
            printf("Correct!\n");
        }
    }

    display_hangman(tries_left);
    if (correct_guesses == word_length) {
        printf("Congratulations! You guessed the word: %s\n", word);
    } else {
        printf("Unfortunately, you lost. The word was: %s\n", word);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    play_hangman();
    return 0;
}
