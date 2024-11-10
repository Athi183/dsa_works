#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each song node
struct Song {
    char title[100];
    struct Song* next;
};

struct Song* head = NULL;

// Function to create a new song node
struct Song* createSong(char* title) {
    struct Song* new_song = (struct Song*)malloc(sizeof(struct Song));
    strcpy(new_song->title, title);
    new_song->next = NULL;
    return new_song;
}

// Add a song to the end of the playlist
void addSong(char* title) {
    struct Song* new_song = createSong(title);
    if (head == NULL) {
        head = new_song;
    } else {
        struct Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_song;
    }
    printf("Song '%s' added to the playlist.\n", title);
}

// Remove a song by title
void removeSong(char* title) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    struct Song* temp = head;
    struct Song* prev = NULL;

    // Check if the song to remove is the first song
    if (strcmp(head->title, title) == 0) {
        head = head->next;
        free(temp);
        printf("Song '%s' removed from the playlist.\n", title);
        return;
    }

    // Search for the song in the playlist
    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If song not found
    if (temp == NULL) {
        printf("Song '%s' not found in the playlist.\n", title);
        return;
    }

    // Remove the song
    prev->next = temp->next;
    free(temp);
    printf("Song '%s' removed from the playlist.\n", title);
}

// Move a song to a new position in the playlist
void moveSong(int currentPosition, int newPosition) {
    if (head == NULL || currentPosition == newPosition) {
        printf("Invalid operation.\n");
        return;
    }

    struct Song* temp = head;
    struct Song* prev = NULL;
    struct Song* song_to_move = NULL;
    int pos = 1;

    // Find the song at currentPosition
    while (temp != NULL && pos != currentPosition) {
        prev = temp;
        temp = temp->next;
        pos++;
    }

    if (temp == NULL) {
        printf("Position %d out of range.\n", currentPosition);
        return;
    }

    song_to_move = temp;

    // If removing the head
    if (prev == NULL) {
        head = song_to_move->next;
    } else {
        prev->next = song_to_move->next;
    }

    // Insert song at newPosition
    struct Song* current = head;
    struct Song* prev_new_pos = NULL;
    pos = 1;

    while (current != NULL && pos != newPosition) {
        prev_new_pos = current;
        current = current->next;
        pos++;
    }

    // If inserting at the head
    if (newPosition == 1) {
        song_to_move->next = head;
        head = song_to_move;
    } else {
        prev_new_pos->next = song_to_move;
        song_to_move->next = current;
    }

    printf("Moved song to position %d.\n", newPosition);
}

// Display the playlist
void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Song* temp = head;
    int pos = 1;
    printf("Current Playlist:\n");
    while (temp != NULL) {
        printf("%d. %s\n", pos, temp->title);
        temp = temp->next;
        pos++;
    }
}

int main() {
    int choice, currentPosition, newPosition;
    char title[100];

    while (1) {
        printf("\n1. Add Song\n2. Remove Song\n3. Move Song\n4. Display Playlist\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline after number input

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;  // Remove newline
                addSong(title);
                break;
            case 2:
                printf("Enter song title to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;  // Remove newline
                removeSong(title);
                break;
            case 3:
                printf("Enter current position of song: ");
                scanf("%d", &currentPosition);
                printf("Enter new position of song: ");
                scanf("%d", &newPosition);
                moveSong(currentPosition, newPosition);
                break;
            case 4:
                displayPlaylist();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

