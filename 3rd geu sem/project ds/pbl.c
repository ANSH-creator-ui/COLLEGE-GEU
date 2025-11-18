#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TITLE 100
#define MAX_ARTIST 100
#define HASH_SIZE 100

// Song Structure
typedef struct Song
{
    int id;
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int duration;
    struct Song *next;
} Song;

// Playlist Node (Linked List)
typedef struct PlaylistNode
{
    Song *song;
    struct PlaylistNode *next;
} PlaylistNode;

// Queue Node for Upcoming Tracks
typedef struct QueueNode
{
    Song *song;
    struct QueueNode *next;
} QueueNode;

// Stack Node for Recently Played
typedef struct StackNode
{
    Song *song;
    struct StackNode *next;
} StackNode;

// Hash Table Node for Quick Search
typedef struct HashNode
{
    Song *song;
    struct HashNode *next;
} HashNode;

// BST Node for Sorting
typedef struct BSTNode
{
    Song *song;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// Global Variables
Song *songLibrary = NULL;
PlaylistNode *playlist = NULL;
QueueNode *queueFront = NULL;
QueueNode *queueRear = NULL;
StackNode *recentlyPlayed = NULL;
HashNode *hashTable[HASH_SIZE];
BSTNode *bstRoot = NULL;
Song *currentSong = NULL;
int songIdCounter = 1;
int isPlaying = 0;
int isPaused = 0;
int repeatMode = 0;
int shuffleMode = 0;

// Function Prototypes
void initHashTable();
int hashFunction(char *str);
Song *createSong(char *title, char *artist, int duration);
void addSongToLibrary(char *title, char *artist, int duration);
void addToPlaylist(int songId);
void displayPlaylist();
void displayLibrary();
void playNextSong();
void pauseSong();
void resumeSong();
void stopSong();
Song *searchSongByTitle(char *title);
Song *searchSongById(int id);
void enqueue(Song *song);
Song *dequeue();
void push(Song *song);
Song *pop();
void insertHashTable(Song *song);
Song *searchHashTable(char *title);
BSTNode *insertBST(BSTNode *root, Song *song);
void inorderBST(BSTNode *root);
void sortPlaylistByTitle();
void sortPlaylistByDuration();
void shufflePlaylist();
void toggleRepeat();
void toggleShuffle();
void deleteFromPlaylist(int songId);
void displayRecentlyPlayed();
void displayUpcomingQueue();
void clearPlaylist();
void freeMemory();
void displayMenu();

// Initialize Hash Table
void initHashTable()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}

// Hash Function
int hashFunction(char *str)
{
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        hash = (hash * 31 + str[i]) % HASH_SIZE;
    }
    return hash;
}

// Create a new song
Song *createSong(char *title, char *artist, int duration)
{
    Song *newSong = (Song *)malloc(sizeof(Song));
    newSong->id = songIdCounter++;
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = NULL;
    return newSong;
}

// Add song to library
void addSongToLibrary(char *title, char *artist, int duration)
{
    Song *newSong = createSong(title, artist, duration);
    newSong->next = songLibrary;
    songLibrary = newSong;
    insertHashTable(newSong);
    printf("Song '%s' by %s added to library (ID: %d)\n", title, artist, newSong->id);
}

// Add song to playlist
void addToPlaylist(int songId)
{
    Song *song = searchSongById(songId);
    if (song == NULL)
    {
        printf("Song with ID %d not found!\n", songId);
        return;
    }

    PlaylistNode *newNode = (PlaylistNode *)malloc(sizeof(PlaylistNode));
    newNode->song = song;
    newNode->next = NULL;

    if (playlist == NULL)
    {
        playlist = newNode;
    }
    else
    {
        PlaylistNode *temp = playlist;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    enqueue(song);
    printf("Song '%s' added to playlist\n", song->title);
}

// Display Playlist
void displayPlaylist()
{
    if (playlist == NULL)
    {
        printf("\nPlaylist is empty!\n");
        return;
    }

    printf("\n=== CURRENT PLAYLIST ===\n");
    PlaylistNode *temp = playlist;
    int count = 1;
    while (temp != NULL)
    {
        printf("%d. [ID: %d] %s - %s (%d:%02d)\n",
               count++, temp->song->id, temp->song->title,
               temp->song->artist, temp->song->duration / 60,
               temp->song->duration % 60);
        temp = temp->next;
    }
}

// Display Library
void displayLibrary()
{
    if (songLibrary == NULL)
    {
        printf("\nLibrary is empty!\n");
        return;
    }

    printf("\n=== SONG LIBRARY ===\n");
    Song *temp = songLibrary;
    while (temp != NULL)
    {
        printf("[ID: %d] %s - %s (%d:%02d)\n",
               temp->id, temp->title, temp->artist,
               temp->duration / 60, temp->duration % 60);
        temp = temp->next;
    }
}

// Play next song
void playNextSong()
{
    Song *song = dequeue();
    if (song == NULL)
    {
        printf("No more songs in queue!\n");
        currentSong = NULL;
        isPlaying = 0;
        return;
    }

    currentSong = song;
    push(song);
    isPlaying = 1;
    isPaused = 0;
    printf("\n♪ Now Playing: %s - %s (%d:%02d)\n",
           song->title, song->artist,
           song->duration / 60, song->duration % 60);
}

// Pause Song
void pauseSong()
{
    if (!isPlaying)
    {
        printf("No song is currently playing!\n");
        return;
    }
    isPaused = 1;
    printf("⏸ Paused: %s\n", currentSong->title);
}

// Resume Song
void resumeSong()
{
    if (!isPlaying || !isPaused)
    {
        printf("No paused song to resume!\n");
        return;
    }
    isPaused = 0;
    printf("▶ Resumed: %s\n", currentSong->title);
}

// Stop Song
void stopSong()
{
    if (!isPlaying)
    {
        printf("No song is currently playing!\n");
        return;
    }
    printf("⏹ Stopped: %s\n", currentSong->title);
    currentSong = NULL;
    isPlaying = 0;
    isPaused = 0;
}

// Search song by ID
Song *searchSongById(int id)
{
    Song *temp = songLibrary;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Enqueue (Add to queue)
void enqueue(Song *song)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->song = song;
    newNode->next = NULL;

    if (queueRear == NULL)
    {
        queueFront = queueRear = newNode;
    }
    else
    {
        queueRear->next = newNode;
        queueRear = newNode;
    }
}

// Dequeue (Remove from queue)
Song *dequeue()
{
    if (queueFront == NULL)
    {
        return NULL;
    }

    QueueNode *temp = queueFront;
    Song *song = temp->song;
    queueFront = queueFront->next;

    if (queueFront == NULL)
    {
        queueRear = NULL;
    }

    free(temp);
    return song;
}

// Push to stack (Recently played)
void push(Song *song)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->song = song;
    newNode->next = recentlyPlayed;
    recentlyPlayed = newNode;
}

// Pop from stack
Song *pop()
{
    if (recentlyPlayed == NULL)
    {
        return NULL;
    }

    StackNode *temp = recentlyPlayed;
    Song *song = temp->song;
    recentlyPlayed = recentlyPlayed->next;
    free(temp);
    return song;
}

// Insert into hash table
void insertHashTable(Song *song)
{
    int index = hashFunction(song->title);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->song = song;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search in hash table
Song *searchHashTable(char *title)
{
    int index = hashFunction(title);
    HashNode *temp = hashTable[index];

    while (temp != NULL)
    {
        if (strcmp(temp->song->title, title) == 0)
        {
            return temp->song;
        }
        temp = temp->next;
    }
    return NULL;
}

// Insert into BST
BSTNode *insertBST(BSTNode *root, Song *song)
{
    if (root == NULL)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->song = song;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (strcmp(song->title, root->song->title) < 0)
    {
        root->left = insertBST(root->left, song);
    }
    else
    {
        root->right = insertBST(root->right, song);
    }

    return root;
}

// Inorder traversal of BST
void inorderBST(BSTNode *root)
{
    if (root != NULL)
    {
        inorderBST(root->left);
        printf("[ID: %d] %s - %s (%d:%02d)\n",
               root->song->id, root->song->title,
               root->song->artist, root->song->duration / 60,
               root->song->duration % 60);
        inorderBST(root->right);
    }
}

// Sort playlist by title (using BST)
void sortPlaylistByTitle()
{
    if (playlist == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    BSTNode *tempRoot = NULL;
    PlaylistNode *temp = playlist;

    while (temp != NULL)
    {
        tempRoot = insertBST(tempRoot, temp->song);
        temp = temp->next;
    }

    printf("\n=== PLAYLIST SORTED BY TITLE ===\n");
    inorderBST(tempRoot);
}

// Sort playlist by duration
void sortPlaylistByDuration()
{
    if (playlist == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    // Simple bubble sort for linked list
    int swapped;
    PlaylistNode *ptr;
    PlaylistNode *last = NULL;

    do
    {
        swapped = 0;
        ptr = playlist;

        while (ptr->next != last)
        {
            if (ptr->song->duration > ptr->next->song->duration)
            {
                Song *temp = ptr->song;
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

// Shuffle playlist
void shufflePlaylist()
{
    if (playlist == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    // Count songs
    int count = 0;
    PlaylistNode *temp = playlist;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Fisher-Yates shuffle algorithm
    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        int j = rand() % count;

        // Swap songs at positions i and j
        PlaylistNode *node1 = playlist;
        PlaylistNode *node2 = playlist;

        for (int k = 0; k < i; k++)
            node1 = node1->next;
        for (int k = 0; k < j; k++)
            node2 = node2->next;

        Song *tempSong = node1->song;
        node1->song = node2->song;
        node2->song = tempSong;
    }

    shuffleMode = 1;
    printf("Playlist shuffled!\n");
    displayPlaylist();
}

// Toggle repeat mode
void toggleRepeat()
{
    repeatMode = !repeatMode;
    printf("Repeat mode: %s\n", repeatMode ? "ON" : "OFF");
}

// Toggle shuffle mode
void toggleShuffle()
{
    shuffleMode = !shuffleMode;
    printf("Shuffle mode: %s\n", shuffleMode ? "ON" : "OFF");
    if (shuffleMode)
    {
        shufflePlaylist();

    }
}

// Delete from playlist
void deleteFromPlaylist(int songId)
{
    if (playlist == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    PlaylistNode *temp = playlist;
    PlaylistNode *prev = NULL;

    while (temp != NULL && temp->song->id != songId)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Song not found in playlist!\n");
        return;
    }

    if (prev == NULL)
    {
        playlist = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    printf("Song '%s' removed from playlist\n", temp->song->title);
    free(temp);
}

// Display recently played
void displayRecentlyPlayed()
{
    if (recentlyPlayed == NULL)
    {
        printf("\nNo recently played songs!\n");
        return;
    }

    printf("\n=== RECENTLY PLAYED ===\n");
    StackNode *temp = recentlyPlayed;
    int count = 1;
    while (temp != NULL && count <= 10)
    {
        printf("%d. %s - %s\n", count++, temp->song->title, temp->song->artist);
        temp = temp->next;
    }
}

// Display upcoming queue
void displayUpcomingQueue()
{
    if (queueFront == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\n=== UPCOMING QUEUE ===\n");
    QueueNode *temp = queueFront;
    int count = 1;
    while (temp != NULL)
    {
        printf("%d. %s - %s\n", count++, temp->song->title, temp->song->artist);
        temp = temp->next;
    }
}

// Clear playlist
void clearPlaylist()
{
    PlaylistNode *temp;
    while (playlist != NULL)
    {
        temp = playlist;
        playlist = playlist->next;
        free(temp);
    }
    printf("Playlist cleared!\n");
}

// Display menu
void displayMenu()
{
    printf("    MUSIC PLAYLIST MANAGER - MENU       \n");
    printf(" 1.  Add song to library                \n");
    printf(" 2.  Display library                    \n");
    printf(" 3.  Add song to playlist               \n");
    printf(" 4.  Display playlist                   \n");
    printf(" 5.  Play next song                     \n");
    printf(" 6.  Pause                              \n");
    printf(" 7.  Resume                             \n");
    printf(" 8.  Stop                               \n");
    printf(" 9.  Search song by title               \n");
    printf(" 10. Sort playlist by title             \n");
    printf(" 11. Sort playlist by duration          \n");
    printf(" 12. Shuffle playlist                   \n");
    printf(" 13. Toggle repeat                      \n");
    printf(" 14. Delete from playlist               \n");
    printf(" 15. Show recently played               \n");
    printf(" 16. Show upcoming queue                \n");
    printf(" 17. Clear playlist                     \n");
    printf(" 0.  Exit                               \n");
    printf("Enter choice: ");
}

// Main function
int main()
{
    initHashTable();
    int choice, songId, duration;
    char title[MAX_TITLE], artist[MAX_ARTIST];

    // Add sample songs
    addSongToLibrary("Bohemian Rhapsody", "Queen", 354);
    addSongToLibrary("Stairway to Heaven", "Led Zeppelin", 482);
    addSongToLibrary("Hotel California", "Eagles", 391);
    addSongToLibrary("Imagine", "John Lennon", 183);
    addSongToLibrary("Smells Like Teen Spirit", "Nirvana", 301);

    printf("\n Welcome to Music Playlist Manager!\n");

    while (1)
    {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice)
        {
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
            playNextSong();
            break;

        case 6:
            pauseSong();
            break;

        case 7:
            resumeSong();
            break;

        case 8:
            stopSong();
            break;

        case 9:
            printf("Enter song title to search: ");
            fgets(title, MAX_TITLE, stdin);
            title[strcspn(title, "\n")] = 0;
            Song *found = searchHashTable(title);
            if (found)
            {
                printf("Found: [ID: %d] %s - %s (%d:%02d)\n",
                       found->id, found->title, found->artist,
                       found->duration / 60, found->duration % 60);
            }
            else
            {
                printf("Song not found!\n");
            }
            break;

        case 10:
            sortPlaylistByTitle();
            break;

        case 11:
            sortPlaylistByDuration();
            break;

        case 12:
            shufflePlaylist();
            break;

        case 13:
            toggleRepeat();
            break;

        case 14:
            printf("Enter song ID to delete: ");
            scanf("%d", &songId);
            deleteFromPlaylist(songId);
            break;

        case 15:
            displayRecentlyPlayed();
            break;

        case 16:
            displayUpcomingQueue();
            break;

        case 17:
            clearPlaylist();
            break;

        case 0:
            printf("\nThank you for using Music Playlist Manager!\n");
            freeMemory();
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Free all allocated memory
void freeMemory()
{
    // Free song library
    Song *tempSong;
    while (songLibrary != NULL)
    {
        tempSong = songLibrary;
        songLibrary = songLibrary->next;
        free(tempSong);
    }

    // Free playlist
    PlaylistNode *tempPlaylist;
    while (playlist != NULL)
    {
        tempPlaylist = playlist;
        playlist = playlist->next;
        free(tempPlaylist);
    }

    // Free queue
    QueueNode *tempQueue;
    while (queueFront != NULL)
    {
        tempQueue = queueFront;
        queueFront = queueFront->next;
        free(tempQueue);
    }

    // Free stack
    StackNode *tempStack;
    while (recentlyPlayed != NULL)
    {
        tempStack = recentlyPlayed;
        recentlyPlayed = recentlyPlayed->next;
        free(tempStack);
    }
}