#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Node structure for playlist
struct Song {
    char name[100];
    struct Song* next;
};

// Function to create a new song node
struct Song* createSong(char* name) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    return newSong;
}

// Function to add song at the end
void addSong(struct Song** head, char* name) {
    struct Song* newSong = createSong(name);
    if (*head == NULL) {
        *head = newSong;
        return;
    }
    struct Song* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newSong;
}

// Function to display playlist
void displayPlaylist(struct Song* head) {
    struct Song* temp = head;
    printf("\n🎶 Playlist Songs:\n");
    while (temp != NULL) {
        printf("→ %s\n", temp->name);
        temp = temp->next;
    }
}

// Function to make playlist circular (for repeat)
void makeCircular(struct Song* head) {
    if (head == NULL) return;
    struct Song* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;  // Connect last song to first
}

// Function to shuffle playlist
void shufflePlaylist(struct Song* head, int size) {
    if (head == NULL || size <= 1) return;

    // Copy song pointers into an array
    struct Song* songs[size];
    struct Song* temp = head;
    for (int i = 0; i < size; i++) {
        songs[i] = temp;
        temp = temp->next;
    }

    // Fisher–Yates shuffle
    srand(time(0));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap song names
        char tmp[100];
        strcpy(tmp, songs[i]->name);
        strcpy(songs[i]->name, songs[j]->name);
        strcpy(songs[j]->name, tmp);
    }

    printf("\n🔀 Playlist Shuffled Successfully!\n");
}

// Function to play songs (normal / repeat)
void playSongs(struct Song* head, int repeat, int totalSongs) {
    if (head == NULL) return;

    struct Song* temp = head;
    int count = 0;
    printf("\n▶️ Playing Songs...\n");

    do {
        printf("Now Playing: %s\n", temp->name);
        temp = temp->next;
        count++;
        if (count == totalSongs && repeat == 0)
            break;
    } while (repeat);
}

int main() {
    struct Song* playlist = NULL;
    int n, choice, repeatMode = 0;

    printf("Enter number of songs: ");
    scanf("%d", &n);
    getchar(); // consume newline

    for (int i = 0; i < n; i++) {
        char name[100];
        printf("Enter song %d name: ", i + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // remove newline
        addSong(&playlist, name);
    }

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Display Playlist\n");
        printf("2. Shuffle Playlist\n");
        printf("3. Enable Repeat Mode\n");
        printf("4. Play Songs\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPlaylist(playlist);
                break;
            case 2:
                shufflePlaylist(playlist, n);
                displayPlaylist(playlist);
                break;
            case 3:
                makeCircular(playlist);
                repeatMode = 1;
                printf("\n🔁 Repeat Mode Enabled!\n");
                break;
            case 4:
                playSongs(playlist, repeatMode, n);
                break;
            case 5:
                printf("\nExiting Playlist... 🎧\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
