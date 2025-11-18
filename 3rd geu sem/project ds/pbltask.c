#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TITLE 100
#define MAX_ARTIST 100
#define HASH_SIZE 100

// Song Structure
typedef struct Song {
    int id;
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int duration;
    struct Song* next;
} Song;

// Playlist Node (Linked List)
typedef struct PlaylistNode {
    Song* song;
    struct PlaylistNode* next;
} PlaylistNode;

// Stack Node for Recently Played
typedef struct StackNode {
    Song* song;
    struct StackNode* next;
} StackNode;

// Hash Table Node for Quick Search
typedef struct HashNode {
    Song* song;
    struct HashNode* next;
} HashNode;

// BST Node for Sorting
typedef struct BSTNode {
    Song* song;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Global Variables
Song* songLibrary = NULL;
PlaylistNode* playlist = NULL;
StackNode* recentlyPlayed = NULL;
HashNode* hashTable[HASH_SIZE];
BSTNode* bstRoot = NULL;
Song* currentSong = NULL;
int songIdCounter = 1;
int isPlaying = 0;
int isPaused = 0;
int repeatMode = 0;
int shuffleMode = 0;

// Function Prototypes - Tasks Completed
void initHashTable();
int hashFunction(char* str);
Song* createSong(char* title, char* artist, int duration);
void addSongToLibrary(char* title, char* artist, int duration);
void addToPlaylist(int songId);
void displayPlaylist();
void displayLibrary();
void playSong();
void pauseSong();
void resumeSong();
Song* searchSongByTitle(char* title);
Song* searchSongById(int id);
void push(Song* song);
Song* pop();
void insertHashTable(Song* song);
Song* searchHashTable(char* title);
BSTNode* insertBST(BSTNode* root, Song* song);
void inorderBST(BSTNode* root);
void sortPlaylistByTitle();
void sortPlaylistByDuration();
void shufflePlaylist();
void toggleRepeat();
void deleteFromPlaylist(int songId);
void displayMenu();

// Initialize Hash Table
void initHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Hash Function
int hashFunction(char* str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % HASH_SIZE;
    }
    return hash;
}

// Create a new song
Song* createSong(char* title, char* artist, int duration) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    newSong->id = songIdCounter++;
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = NULL;
    return newSong;
}

// Add song to library
void addSongToLibrary(char* title, char* artist, int duration) {
    Song* newSong = createSong(title, artist, duration);
    newSong->next = songLibrary;
    songLibrary = newSong;
    insertHashTable(newSong);
    printf("Song '%s' by %s added to library (ID: %d)\n", title, artist, newSong->id);
}

// TASK: Add song to playlist (Jaywardhan Chauhan)
void addToPlaylist(int songId) {
    Song* song = searchSongById(songId);
    if (song == NULL) {
        printf("Song with ID %d not found!\n", songId);
        return;
    }
    
    PlaylistNode* newNode = (PlaylistNode*)malloc(sizeof(PlaylistNode));
    newNode->song = song;
    newNode->next = NULL;
    
    if (playlist == NULL) {
        playlist = newNode;
    } else {
        PlaylistNode* temp = playlist;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Song '%s' added to playlist\n", song->title);
}

// Display Playlist
void displayPlaylist() {
    if (playlist == NULL) {
        printf("\nPlaylist is empty!\n");
        return;
    }
    
    printf("\n=== CURRENT PLAYLIST ===\n");
    PlaylistNode* temp = playlist;
    int count = 1;
    while (temp != NULL) {
        printf("%d. [ID: %d] %s - %s (%d:%02d)\n", 
               count++, temp->song->id, temp->song->title, 
               temp->song->artist, temp->song->duration / 60, 
               temp->song->duration % 60);
        temp = temp->next;
    }
}

// Display Library
void displayLibrary() {
    if (songLibrary == NULL) {
        printf("\nLibrary is empty!\n");
        return;
    }
    
    printf("\n=== SONG LIBRARY ===\n");
    Song* temp = songLibrary;
    while (temp != NULL) {
        printf("[ID: %d] %s - %s (%d:%02d)\n", 
               temp->id, temp->title, temp->artist, 
               temp->duration / 60, temp->duration % 60);
        temp = temp->next;
    }
}

// TASK: Play Function (Jaywardhan Chauhan)
void playSong() {
    if (playlist == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    currentSong = playlist->song;
    push(currentSong);
    isPlaying = 1;
    isPaused = 0;
    printf("\n♪ Now Playing: %s - %s (%d:%02d)\n", 
           currentSong->title, currentSong->artist, 
           currentSong->duration / 60, currentSong->duration % 60);
}

// TASK: Pause Function (Jaywardhan Chauhan)
void pauseSong() {
    if (!isPlaying) {
        printf("No song is currently playing!\n");
        return;
    }
    isPaused = 1;
    printf("⏸ Paused: %s\n", currentSong->title);
}

// TASK: Resume/Play Function (Jaywardhan Chauhan)
void resumeSong() {
    if (!isPlaying || !isPaused) {
        printf("No paused song to resume!\n");
        return;
    }
    isPaused = 0;
    printf("▶ Resumed: %s\n", currentSong->title);
}

// Search song by ID
Song* searchSongById(int id) {
    Song* temp = songLibrary;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// TASK: Push to stack - Recently played (Ansh)
void push(Song* song) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->song = song;
    newNode->next = recentlyPlayed;
    recentlyPlayed = newNode;
}

// Pop from stack
Song* pop() {
    if (recentlyPlayed == NULL) {
        return NULL;
    }
    
    StackNode* temp = recentlyPlayed;
    Song* song = temp->song;
    recentlyPlayed = recentlyPlayed->next;
    free(temp);
    return song;
}

// TASK: Insert into hash table - Quick Search (Akhil)
void insertHashTable(Song* song) {
    int index = hashFunction(song->title);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->song = song;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// TASK: Search in hash table (Akhil)
Song* searchHashTable(char* title) {
    int index = hashFunction(title);
    HashNode* temp = hashTable[index];
    
    while (temp != NULL) {
        if (strcmp(temp->song->title, title) == 0) {
            return temp->song;
        }
        temp = temp->next;
    }
    return NULL;
}

// TASK: Insert into BST for sorting (Akhil)
BSTNode* insertBST(BSTNode* root, Song* song) {
    if (root == NULL) {
        BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
        newNode->song = song;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    if (strcmp(song->title, root->song->title) < 0) {
        root->left = insertBST(root->left, song);
    } else {
        root->right = insertBST(root->right, song);
    }
    
    return root;
}

// TASK: Inorder traversal of BST (Akhil)
void inorderBST(BSTNode* root) {
    if (root != NULL) {
        inorderBST(root->left);
        printf("[ID: %d] %s - %s (%d:%02d)\n", 
               root->song->id, root->song->title, 
               root->song->artist, root->song->duration / 60, 
               root->song->duration % 60);
        inorderBST(root->right);
    }
}

// TASK: Sort playlist by title using BST (Akhil)
void sortPlaylistByTitle() {
    if (playlist == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    BSTNode* tempRoot = NULL;
    PlaylistNode* temp = playlist;
    
    while (temp != NULL) {
        tempRoot = insertBST(tempRoot, temp->song);
        temp = temp->next;
    }
    
    printf("\n=== PLAYLIST SORTED BY TITLE ===\n");
    inorderBST(tempRoot);
}

// Sort playlist by duration
void sortPlaylistByDuration() {
    if (playlist == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    // Simple bubble sort for linked list
    int swapped;
    PlaylistNode* ptr;
    PlaylistNode* last = NULL;
    
    do {
        swapped = 0;
        ptr = playlist;
        
        while (ptr->next != last) {
            if (ptr->song->duration > ptr->next->song->duration) {
                Song* temp = ptr->song;
                ptr->song = ptr->next->song;
                ptr->next->song = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
    
    printf("Playlist sorted by duration!\n");
    displayPlaylist();
}

// TASK: Shuffle playlist (Ansh)
void shufflePlaylist() {
    if (playlist == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    // Count songs
    int count = 0;
    PlaylistNode* temp = playlist;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    // Fisher-Yates shuffle algorithm
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int j = rand() % count;
        
        // Swap songs at positions i and j
        PlaylistNode* node1 = playlist;
        PlaylistNode* node2 = playlist;
        
        for (int k = 0; k < i; k++) node1 = node1->next;
        for (int k = 0; k < j; k++) node2 = node2->next;
        
        Song* tempSong = node1->song;
        node1->song = node2->song;
        node2->song = tempSong;
    }
    
    shuffleMode = 1;
    printf("Playlist shuffled!\n");
    displayPlaylist();
}

// TASK: Toggle repeat mode (Ansh)
void toggleRepeat() {
    repeatMode = !repeatMode;
    printf("Repeat mode: %s\n", repeatMode ? "ON" : "OFF");
}

// TASK: Delete from playlist (Anshuman)
void deleteFromPlaylist(int songId) {
    if (playlist == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    PlaylistNode* temp = playlist;
    PlaylistNode* prev = NULL;
    
    while (temp != NULL && temp->song->id != songId) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Song not found in playlist!\n");
        return;
    }
    
    if (prev == NULL) {
        playlist = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    printf("Song '%s' removed from playlist\n", temp->song->title);
    free(temp);
}

// TASK: Creation of playlist (Anshuman) - Already implemented in addToPlaylist
// TASK: Insertion of songs (Anshuman) - Already implemented in addSongToLibrary

// Display menu
void displayMenu() {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║  MUSIC PLAYLIST MANAGER - TASKS DEMO  ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ COMPLETED TASKS:                       ║\n");
    printf("║                                        ║\n");
    printf("║ 1.  Add song to library [Anshuman]    ║\n");
    printf("║ 2.  Display library                    ║\n");
    printf("║ 3.  Add to playlist [Jaywardhan/Ansh] ║\n");
    printf("║ 4.  Display playlist                   ║\n");
    printf("║ 5.  Play song [Jaywardhan]             ║\n");
    printf("║ 6.  Pause [Jaywardhan]                 ║\n");
    printf("║ 7.  Resume [Jaywardhan]                ║\n");
    printf("║ 8.  Search song [Akhil]                ║\n");
    printf("║ 9.  Sort by title [Akhil]              ║\n");
    printf("║ 10. Sort by duration [Akhil]           ║\n");
    printf("║ 11. Shuffle playlist [Ansh]            ║\n");
    printf("║ 12. Toggle repeat [Ansh]               ║\n");
    printf("║ 13. Delete from playlist [Anshuman]    ║\n");
    printf("║ 14. Show recently played (Stack)       ║\n");
    printf("║ 0.  Exit                               ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("Enter choice: ");
}

// Display recently played
void displayRecentlyPlayed() {
    if (recentlyPlayed == NULL) {
        printf("\nNo recently played songs!\n");
        return;
    }
    
    printf("\n=== RECENTLY PLAYED (Stack - LIFO) ===\n");
    StackNode* temp = recentlyPlayed;
    int count = 1;
    while (temp != NULL && count <= 10) {
        printf("%d. %s - %s\n", count++, temp->song->title, temp->song->artist);
        temp = temp->next;
    }
}

// Main function
int main() {
    initHashTable();
    int choice, songId, duration;
    char title[MAX_TITLE], artist[MAX_ARTIST];
    
    // Add sample songs
    addSongToLibrary("Bohemian Rhapsody", "Queen", 354);
    addSongToLibrary("Stairway to Heaven", "Led Zeppelin", 482);
    addSongToLibrary("Hotel California", "Eagles", 391);
    addSongToLibrary("Imagine", "John Lennon", 183);
    addSongToLibrary("Smells Like Teen Spirit", "Nirvana", 301);
    
    printf("\n★ Welcome to Music Playlist Manager - Tasks Completed Demo! ★\n");
    printf("\nTeam Members:\n");
    printf("• Jaywardhan Chauhan - Play/Pause Functions\n");
    printf("• Ansh - Repeat/Shuffle Functions\n");
    printf("• Akhil - Search/Sort Functions\n");
    printf("• Anshuman - Playlist Creation/Deletion\n\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0;
                printf("Enter artist name: ");
                fgets(artist, MAX_ARTIST, stdin);
                artist[strcspn(artist, "\n")] = 0;
                printf("Enter duration (in seconds): ");
                scanf("%d", &duration);
                addSongToLibrary(title, artist, duration);
                break;
            
            case 2:
                displayLibrary();
                break;
            
            case 3:
                printf("Enter song ID to add to playlist: ");
                scanf("%d", &songId);
                addToPlaylist(songId);
                break;
            
            case 4:
                displayPlaylist();
                break;
            
            case 5:
                playSong();
                break;
            
            case 6:
                pauseSong();
                break;
            
            case 7:
                resumeSong();
                break;
            
            case 8:
                printf("Enter song title to search: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0;
                Song* found = searchHashTable(title);
                if (found) {
                    printf("✓ Found: [ID: %d] %s - %s (%d:%02d)\n", 
                           found->id, found->title, found->artist,
                           found->duration / 60, found->duration % 60);
                } else {
                    printf("✗ Song not found!\n");
                }
                break;
            
            case 9:
                sortPlaylistByTitle();
                break;
            
            case 10:
                sortPlaylistByDuration();
                break;
            
            case 11:
                shufflePlaylist();
                break;
            
            case 12:
                toggleRepeat();
                break;
            
            case 13:
                printf("Enter song ID to delete: ");
                scanf("%d", &songId);
                deleteFromPlaylist(songId);
                break;
            
            case 14:
                displayRecentlyPlayed();
                break;
            
            case 0:
                printf("\n✓ All tasks demonstrated successfully!\n");
                printf("Thank you for using Music Playlist Manager!\n");
                return 0;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}