Play function - moves to next song in playlist
void play(Node** head) {
    if (*head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    if (current == NULL) {
        current = *head;
    } else {
        current = current->next;
        if (current == NULL) {
            current = *head; // Loop back to start
        }
    }
    
    printf("Now playing: %s by %s\n", current->song, current->artist);
}

// Pause function - stops current playback
void pause() {
    if (current == NULL) {
        printf("No song is currently playing!\n");
        return;
    }
    printf("Paused: %s by %s\n", current->song, current->artist);
}
Ansh - Repeat and Shuffle
// Repeat function - replays current song
void repeat() {
    if (current == NULL) {
        printf("No song to repeat!\n");
        return;
    }
    printf("Repeating: %s by %s\n", current->song, current->artist);
}

// Shuffle function - randomizes playlist order
void shuffle(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("Not enough songs to shuffle!\n");
        return;
    }
    
    int count = 0;
    Node* temp = *head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    // Fisher-Yates shuffle algorithm
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        
        // Swap songs at positions i and j
        Node* node_i = *head;
        Node* node_j = *head;
        
        for (int k = 0; k < i; k++) node_i = node_i->next;
        for (int k = 0; k < j; k++) node_j = node_j->next;
        
        // Swap data
        char tempSong[100], tempArtist[100];
        strcpy(tempSong, node_i->song);
        strcpy(tempArtist, node_i->artist);
        
        strcpy(node_i->song, node_j->song);
        strcpy(node_i->artist, node_j->artist);
        
        strcpy(node_j->song, tempSong);
        strcpy(node_j->artist, tempArtist);
    }
    
    printf("Playlist shuffled!\n");
}
Akhil - Searching and Sorting
// Search function - finds song by name using hash table
void searchSong(HashTable* ht, char* songName) {
    int index = hashFunction(songName, ht->size);
    HashNode* current = ht->table[index];
    
    while (current != NULL) {
        if (strcmp(current->song, songName) == 0) {
            printf("Found: %s by %s\n", current->song, current->artist);
            return;
        }
        current = current->next;
    }
    
    printf("Song '%s' not found!\n", songName);
}

// Sort function - sorts playlist using BST/AVL tree
void sortPlaylist(Node** head) {
    if (*head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    TreeNode* root = NULL;
    Node* current = *head;
    
    // Insert all songs into BST
    while (current != NULL) {
        root = insertBST(root, current->song, current->artist);
        current = current->next;
    }
    
    // Clear original list
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    
    // Rebuild sorted list from BST (in-order traversal)
    inOrderToList(root, head);
    
    printf("Playlist sorted alphabetically!\n");
}
Anshuman - Playlist Creation, Insertion, and Deletion
// Create playlist - initializes empty linked list
Node* createPlaylist() {
    printf("New playlist created!\n");
    return NULL; // Empty playlist
}

// Insert function - adds song to playlist
void insertSong(Node** head, char* song, char* artist) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->song, song);
    strcpy(newNode->artist, artist);
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    printf("Added: %s by %s\n", song, artist);
}

// Delete function - removes song from playlist
void deleteSong(Node** head, char* song) {
    if (*head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    Node* temp = *head;
    Node* prev = NULL;
    
    // If head node needs to be deleted
    if (strcmp(temp->song, song) == 0) {
        *head = temp->next;
        printf("Deleted: %s\n", song);
        free(temp);
        return;
    }
    
    // Search for the song
    while (temp != NULL && strcmp(temp->song, song) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Song '%s' not found!\n", song);
        return;
    }
    
    prev->next = temp->next;
    printf("Deleted: %s\n", song);
    free(temp);
}