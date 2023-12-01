// we need the include files io and stdlib and string and stdbool and time
// we need to define a constant for the number of rooms
// we need to define a constant for the maximum number of connections per room
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
// we want to write a text based game that is a little bit like a choose your own adventure book
// each turn we will present the player with a choice of actions
// the player will choose an action and we will carry it out
// the player can look at the room, or move to another room

// we will need to keep track of the current room
// we need a way to represent the rooms
// we need a way to represent the connections between the rooms
// let's have a datastructure that represents the rooms
// room has connections and connections have rooms so we need to define connection first but we can't because room needs it
// we can use a forward declaration to tell the compiler that connection is a struct that will be defined later
typedef struct connection connection;
typedef struct room {
  char* name;
  char* description;
  connection* connections;
  int numConnections;
} room;

// we need a way to represent the connections between the rooms
// let's have a datastructure that represents the connections
typedef struct connection {
  room* room1;
  room* room2;
} connection;

// we need a way to represent the player
// let's have a datastructure that represents the player
typedef struct player {
  room* currentRoom;
} player;

// we need a way to represent the game
// let's have a datastructure that represents the game
typedef struct game {
  room* rooms;
  int numRooms;
  player* player;
} game;

// adding an encounter struct
typedef struct encounter {
  char* creature;
  char* description;
  int armorClass;
} encounter;

// let's have a function to print a menu and get user choice, return the choice
int getMenuChoice() {
  int choice;
  printf("What would you like to do?\n");
  printf("1. Look around\n");
  printf("2. Move to another room\n");
  printf("3. Quit\n");
  scanf("%d", &choice);
  // we need to check that the choice is valid
  while (choice < 1 || choice > 3) {
    printf("Invalid choice, please try again\n");
    scanf("%d", &choice);
  }
  return choice;
}

// let's have a function to print the room description
void printRoomDescription(room* room) {
  printf("You are in the %s.\n", room->name);
  printf("%s\n", room->description);
}

// Function to move the player to a random room except current
void movePlayerToRandomRoom(player* player, room* rooms, int numRooms) {
  int currentRoomIndex = player->currentRoom - rooms;
  int randomIndex = currentRoomIndex;
  while(randomIndex == currentRoomIndex) {
    randomIndex = rand() % numRooms;
  }
  player->currentRoom = &rooms[randomIndex];
  printRoomDescription(player->currentRoom);
}

// Commenting out this function and replacing it with a function with error checks for now
// Function to load encounters from the encounters.csv file
//encounter* loadEncounters(int numRooms) {
  //encounter* encounters = malloc(sizeof(encounter) * numRooms);
  //FILE* file = fopen("encounters.csv", "r");
  //if (file == NULL) {
    //printf("Error opening encounters file\n");
    //exit(1);
  //}
  //char line[500];
  //for (int i = 0; i < numRooms; i++) {
    //fgets(line, sizeof(line), file);
    // Parsing the csv line and storing the values
    //char* creature = strtok(line, "\",\"");
    //char* description = strtok(NULL, "\",\"");
    //int armorClass;
    //sscanf(strtok(NULL, ","), "%d", &armorClass);
    // Storing the encounter details
    //encounters[i].creature = malloc(strlen(creature) + 1);
    //strcpy(encounters[i].creature, creature);
    //encounters[i].description = malloc(strlen(description) + 1);
    //strcpy(encounters[i].description, description);
    //encounters[i].armorClass = armorClass;
  //}
  //fclose(file);
  //return encounters;
//}

encounter* loadEncounters(int numRooms) {
  encounter* encounters = malloc(sizeof(encounter) * numRooms);
  if (encounters == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  FILE* file = fopen("encounters.csv", "r");
  if (file == NULL) {
    perror("Error opening encounters file");
    exit(1);
  }

  char line[500];
  for (int i = 0; i < numRooms; i++) {
    if (fgets(line, sizeof(line), file) == NULL) {
      printf("Error or end of file reached before the expected number of rooms\n");
      break;  // can also exit if this is considered fatal
    }

    // Skip leading quotation mark
    char* creature = strtok(line, "\",\"");
    char* description = strtok(NULL, "\",\"");
    if (creature == NULL || description == NULL) {
      printf("Parsing error in line %d\n", i + 1);
      break;  // or handle the error as appropriate
    }

    int armorClass;
    // Get the armorClass directly after the second quotation mark
    char* armorClassStr = strtok(NULL, "\", ");
    if (armorClassStr == NULL || sscanf(armorClassStr, "%d", &armorClass) != 1) {
      printf("Parsing armor class failed in line %d\n", i + 1);
      break;  // or handle as appropriate
    }

    // Allocate memory and store the encounter details, skipping quotation marks
    encounters[i].creature = malloc(strlen(creature) + 1);
    encounters[i].description = malloc(strlen(description) + 1);
    if (encounters[i].creature == NULL || encounters[i].description == NULL) {
      printf("Memory allocation failed for encounter details in line %d\n", i + 1);
      break;  // handle memory allocation failure
    }
    strcpy(encounters[i].creature, creature);
    strcpy(encounters[i].description, description);
    encounters[i].armorClass = armorClass;
  }

  fclose(file);
  return encounters;
}

// Function to handle an encounter
void handleEncounter(player* player, encounter* encounter, room* rooms, int numRooms) {
  printf("%s\n", encounter->description);
  int choice;
  bool encounterComplete = false;
  while(!encounterComplete) {
    printf("What would you like to do?\n");
    printf("1. Attack\n");
    printf("2. Check\n");
    //printf("3. Flee\n");
    scanf("%d", &choice);
    switch(choice) {
      case 1: { // Attack option
        printf("You attack the %s!\n", encounter->creature);
        int attackRoll = (rand() % 20) + 1;
        printf("You rolled a %d\n", attackRoll);
        if (attackRoll >= encounter->armorClass) {
          printf("You defeated the %s!\n", encounter->creature);
          encounterComplete = true;
        } else {
          printf("Your attack missed and you are forced to flee!\n");
          //movePlayerToRandomRoom(player, rooms, numRooms);
          encounterComplete = true;
        }
        break;
      }
      case 2: // Check option
        printf("You check the %s\n", encounter->creature);
        printf("The armor class of the %s is %d\n", encounter->creature, encounter->armorClass);
        break;
      //case 3: // Flee option
        //printf("You flee from the %s\n", encounter->creature);
        //printf("You flee to a random room.\n");
        //movePlayerToRandomRoom(player, rooms, numRooms);
        //encounterComplete = true;
        //break;
      //commenting this out because when choosing the flee option it seems to stop the code rather than moving to a random room.
      default:
        printf("Invalid choice, please try again\n");
    }
  }
}

// Function to trigger an encounter if random number is 4
void triggerRandomEncounter(player* player, room* rooms, int numRooms, encounter* encounters) {
  int randomEvent = (rand() % 4) + 1;
  if (randomEvent == 4) {
    int roomIndex = player->currentRoom - rooms; // Get current room index
    handleEncounter(player, &encounters[roomIndex], rooms, numRooms);
  }
}

// a function to get user choice of room to move to
int getRoomChoice(room* currentRoom) {
  int choice;
  printf("Which room would you like to move to?\n");
  for (int i = 0; i < currentRoom->numConnections; i++) {
    printf("%d. %s\n", i+1, currentRoom->connections[i].room2->name);
  }
  scanf("%d", &choice);
  // we need to check that the choice is valid
  while (choice < 1 || choice > currentRoom->numConnections) {
    printf("Invalid choice, please try again\n");
    scanf("%d", &choice);
  }
  return choice;
}

// a function to move the player to another room, and describe it to the user
//void movePlayer(player* player, int choice) {
  //player->currentRoom = player->currentRoom->connections[choice-1].room2;
  //printRoomDescription(player->currentRoom);
//}

// a function to load the rooms from a file
// the file is called rooms.csv, and has a room name and room description on each line
// the function returns an array of rooms
room* loadRooms() {
  // open the file
  FILE* file = fopen("rooms.csv", "r");
  // we need to check that the file opened successfully
  if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  // we need to count the number of lines in the file
  int numLines = 0;
  char line[500];
  while (fgets(line, 500, file) != NULL) {
    numLines++;
  }
  // we need to rewind the file
  rewind(file);
  // we need to allocate memory for the rooms
  room* rooms = malloc(sizeof(room) * numLines);
  // we need to read the rooms from the file
  for (int i = 0; i < numLines; i++) {
    // we need to read the line
    fgets(line, 500, file);
    // we need to remove the newline character
    line[strlen(line)-1] = '\0';
    // we need to split the line into the name and description
    // the strings are in quotation marks, and the two quoted strings are separated by a comma
    // we need to split the line on ", " (the four characters)
    //everything between the first and second " is the name
    //everything between the third and fourth " is the description
    // we need to find the first "
    char* name = strtok(line, "\"");
    // we need to find the second " and record where it is so we can null terminate the string
    char* endofname=strtok(NULL, "\"");


    // we need to find the third "
    char* description = strtok(NULL, "\"");
    // we need to find the fourth "
    char* endofdesc=strtok(NULL, "\0");
    //we need to be sure that name and description are null terminated strings
    name[endofname-name]='\0';
    //description[endofdesc-description]='\0';
    // we need to create a room
    room room;
    //we need to copy the string into the room name
    room.name = malloc(sizeof(char) * strlen(name) + 1);
    strcpy(room.name, name);
    //we need to copy the string into the room description
    room.description = malloc(sizeof(char) * strlen(description) + 1);
    strcpy(room.description, description);
    room.connections = NULL;
    room.numConnections = 0;
    // we need to add the room to the array
    rooms[i] = room;
  }
  // we need to close the file
  fclose(file);

  // we need to create a maze like set of connections between the rooms
  // we need to loop through the rooms
  //let's pick a number between 1 and 3 for the number of connections for each room
  srand(time(NULL));
  // ... previous code remains unchanged ...
  // we need to create a maze like set of connections between the rooms
  // Instead of randomly generating connections, load them from connections.csv file
  FILE* connectionsFile = fopen("connections.csv", "r");
  if (connectionsFile == NULL) {
    printf("Error opening connections file\n");
    exit(1);
  }
  char connectionsLine[500];
  int currentRoomIndex = 0;
  while (fgets(connectionsLine, sizeof(connectionsLine), connectionsFile)) {
    if (currentRoomIndex >= numLines) {
      break; // make sure we don't exceed the number of rooms
    }
    // Assume the CSV is formatted as: roomIndex,roomIndex,roomIndex where each roomIndex is an int
    int connectionIndices[3]; // since we're expecting 3 connections per room
    sscanf(connectionsLine, "%d,%d,%d", &connectionIndices[0], &connectionIndices[1], &connectionIndices[2]);
    rooms[currentRoomIndex].connections = realloc(rooms[currentRoomIndex].connections, sizeof(connection) * 3);
    for (int j = 0; j < 3; j++) {
      rooms[currentRoomIndex].connections[j].room1 = &rooms[currentRoomIndex];
      rooms[currentRoomIndex].connections[j].room2 = &rooms[connectionIndices[j]];
    }
    rooms[currentRoomIndex].numConnections = 3;
    currentRoomIndex++;
  }
  fclose(connectionsFile);
  // ... following code remains unchanged ...
  // we need to return the array of rooms
  return rooms;
}

// let's have a function to create a player
player* createPlayer(room* currentRoom) {
  // we need to allocate memory for the player
  player* player = malloc(sizeof(player));
  // we need to set the current room
  player->currentRoom = currentRoom;
  // we need to return the player
  return player;
}

// let's have a function to create a game
game* createGame() {
  // we need to allocate memory for the game
  game* game = malloc(sizeof(game));
  // we need to load the rooms
  printf("debug - about to load rooms\n");
  game->rooms = loadRooms();
  printf("debug - rooms loaded\n");
  // we need to set the number of rooms
  game->numRooms = 10;
  // we need to create the player
  game->player = createPlayer(&game->rooms[0]);
  // we need to return the game
  return game;
}

// let's have a function to play the game which is the main function
void playGame() {
  // we need to create the game
  printf("Welcome to the game\n");
  game* game = createGame();
  encounter* encounters = loadEncounters(game->numRooms); //There seems to be a problem with this function.
  // srand(time(NULL));
  // we need to print the room description
  printRoomDescription(game->player->currentRoom);
  // we need to loop until the user quits
  bool quit = false;
  while (!quit) {
    // we need to print the menu and get the user choice
    int choice = getMenuChoice();
    // we need to carry out the user choice
    if (choice == 1) {
      // we need to print the room description
      printRoomDescription(game->player->currentRoom);
    } else if (choice == 2) {
      // we need to get the user choice of room to move to
      int roomChoice = getRoomChoice(game->player->currentRoom);
      // we need to move the player to the room
      movePlayer(game->player, roomChoice);
      // Trigger a random encounter after moving to a new room
      triggerRandomEncounter(game->player, game->rooms, game->numRooms, encounters);
    } else if (choice == 3) {
      // we need to quit
      quit = true;
    }
  }
}

// let's have a main function to call the playGame function
int main() {
  playGame();
  return 0;
}
