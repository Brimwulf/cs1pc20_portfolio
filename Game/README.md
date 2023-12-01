| Module Code:                     |    CS1PC20                               |
|----------------------------------|-----------------------------------|
| Assignment report Title:         |   Portfolio                                |
| Date (when the work completed):   |  01/12/2023                                 |
| Actual hrs spent for the assignment: |  15                              |


## Analysis of effect of CoPilot on Pat's coding

| Impact                   | Positive         | Negative    |
|--------------------------|------------------------|-----------------------|
| on Learning                | One of the main positives I could identify is that at certain points the AI was able to suggest a way of writing the code that Pat may not have initially considered. Although there were a few different points where Pat seemed to disagree with the way that the AI had written the code, in general Pat seemed to use the code that Copilot had written. In a way, the fact that Pat disagreed with the AI at a few points, this could also be considered as a positive for his learning as it means that it prompted him to think about the functionality of the code on a deeper rather than just accepting whatever the AI generated. | For an experienced programmer, Copilot seemed to serve as more of an assistant than a teacher. Therefore, it likely didn't have a huge impact on Pat's "learning" exactly. It likely suggested a few ways in which he code write that particular code that he had not considered at first but Pat wouldn't likely have used the AI to help him learn about what certain parts of code do exactly. Additionally it could be argued that to a certain extent, writing comments specificying what a piece of code should do and then having it generated for you could lead to a programmer not thinking about their code too much and thus not understanding what all of it does. |
| on Productivity           | The biggest thing I can see which seemed to help Pat's productivity is that he made good use of typing a comment which Copilot took and generated code using the comment as a suggestion. This added a good flow to his work because it allowed to him specify something like "we need a way to represent the connections between the rooms let's have a datastructure that represents the connections" which Copilot then took and generated the lines for the datastructure. Additionally, Copilot also generated its own comments which helped by suggesting what to do next also. | The two biggest hindrances was firstly that occasionally Copilot added code in that Pat was able to identify a better way of writing or he disagreed with how the AI had done something. A newer programmer might not run into this issue but an experienced programmer might spend more time editing code that the AI has generated as well as writing their code. To a greater extent however, the second thing is that the AI seemed to be helpful in the writing new code phase but the debugging phase it didn't come in as useful owing to the fact that Pat had to do most of the debugging himself. It seems to me that Copilot is good at generating new code but not as good at fixing code it has written. This means that some time spent on writing is eliminated but the time spent debugging the code is mostly the same. |

## Analysis of effect of CoPilot on my programming for tasks 3 and 4

| Impact                   | Positive         | Negative    |
|--------------------------|------------------------|-----------------------|
| on Learning                | I found that using the AI was actually, in general, quite helpful for learning. Any code that the AI prouced was commented explaining what it does which meant that although some parts where AI generated, I could see how the code worked and how it should fit in to the rest. Additionally, it was helpful to be able to ask the AI questions such as "what does strtok do exactly?" | For task 3 I found that although I eventually managed to come to a solution it didn't actually help me to learn anything new, after all I was just heavily nudging the AI towards fixing the particular piece of code. In contrast, in task 4, although the AI was generating pieces of code it was down to me to figure out where the code should be implemented which required an understanding of the existing code and the code I am adding. |
| on Productivity           | Something I found quite helpful in increasing my productivity is that the AI could predict what I was going to type in certain places. Therefore instead of typing out the full line of code I could just hit the tab key and it would autofill which saved a lot of time. I also found it useful how upon typing a comment out, the AI would sometimes suggest the following bit of code.  | The biggest hindrance I encountered with using the AI was the issue that getting it to help debug existing code was extremely difficult. When asking the AI to help fix or implement a new feature it requires you to be very specific about what section you're referring to and you must include any additional files that are relevant. This requires a lot of typing sometimes which slows productivity because I would be spending a long time on explaining to the AI what I'm looking for rather than actually coding. As well as that, the AI had a habit of forgetting what it had just written so if I needed clarification on something or wanted to suggest changes to code it had generated I would often have to re-input the same prompt. |

## AI prompts used:

"Enhance this code so that it uses the connections.csv file to define the connections between rooms. Connections.csv has on each line 3 numbers seperated by commas between 0 and 9 It should only ever be 3 options each time the player moves to a new room."

"This code needs a part added to it so that it always returns 3 rooms"

"~~This code needs to be modified slightly so that returns a MAXIMUM of 3 rooms but never less than 3 rooms~~"

"~~The code needs to be changed so that it never outputs more than 3 rooms. And it never outputs the same room more than once.~~"

"~~This code causes an error where realloc(): invalid next size~~"

"~~This code needs to be modify so that it always returns exactly 3 rooms and does not return the same room more than once.~~"

"~~This code needs to be modified so that after a new room is moved into, every room is allowed to be moved into again.~~"

"Modify this code so that it always outputs 3 rooms exactly"

"Modify this code so that it never outputs more than 3 rooms and never less than 3 rooms"

"Modify this part to add a value k that will act as the value set to room3 of the connection"

"Modify this code so that it solves the malloc(): invalid size (unsorted) error."

"Modify the code so that when the user selects move to another room it, the room they're in connects to 3 other rooms instead of 2"

"Fix this code so that it no longer gives the error free(): double free detected in tcache 2"

"Can you debug maingame.c"

## at this stage I actually ended up discarding everything I had done up to this point and starting over using the next prompts:

"from lines 159 to 180 in @maingame.c I need to replace the random rooms selection with code that reads from the @connections.csv file and sets the three exits from each room to be the rooms for the equivalent row in the @connections.csv file. Please help me to replace the randomising code with the improved code with the requirements I've specified."

"Can you please debug this code"

"from lines 159 to 180 in @maingame.c I need to replace the random rooms selection with code that reads from the @connections.csv file and sets the three exits from each room to be the rooms for the equivalent row in the @connections.csv file. Please help me to replace the randomising code with the improved code with the requirements I've specified."

## at this point I moved on to task 4

"in @maingame.c I want to implement a feature where when the player enters a room a random number is generated between 1 and 4. If the number generated is 4, it triggers an "encounter". The encounter is defined using the @encounters.csv file. The function should read the line in @encounters.csv corresponding to the room number that the player is currently in. The first item on the line in @encounters.csv is the name of the creature in the encounter. The next item is the description that should be printed when the encounter is triggered, and the last item is the armour class which should be stored in a variable to use later. The player should be given 3 options: Attack, check and flee. If the player chooses attack, generate a random number between 1 and 20. If the number generated is larger than or equal to the armour class the player wins and should be taken to the move rooms menu. If it the generated number is lower than armour class, the player is moved to a random room except the room they are currently in. If the player chooses the check option, it prints the armour class for the encounter. If the player chooses flee then it moves the player to a random room except the room they are currently in."

"Modify this function so that when a player moves to a new room it calls the triggerRandomEncounter function and then add code to free the encounters after the game loop"

"If the integer in the file is two digit, would that make it formatted incorrectly?
Can you re-explain the incorrect delimiters problem but break it down so it's as easy to understand as possible as I think that might be where the problem lies.
The characters are seperated by commas so why is it not tokenising properly?"

"In @encounters.csv creature and description is contained in quotation marks but armour class is not contained in quotation marks. Therefore the code needs to be modified so that it tokenises the lines within the csv file correctly.
For the files @encounters.csv and @maingame.c it seems like whenever I try parsing the armor class it always fails."

"I've refactored the code in @maingame.c so that now instead of reading creature, description and armour class from the @encounters.csvencounters file there is now a seperate @AC.csv file that has all the armour class values necessary. I'm hoping this will fix the parsing problem. But now I need to change the code so that it reads armour class from the new AC file, making sure that the line numbers still match between @AC.csv and @encounters.csv"

"I've refactored the code in @maingame.c so that now instead of reading creature, description and armour class from the @encounters.csvencounters file there is now a seperate @AC.csv file that has all the armour class values necessary. I'm hoping this will fix the parsing problem. But now I need to change the code so that it reads armour class from the new AC file, making sure that the line numbers still match between @AC.csv and @encounters.csv. It's important that the line read from @AC.csv and @encounters.csv  corresponds to the room number the player is in from @rooms.csv.  After the player enters a new room, the code needs to generate a random number from 1 to 4 and if the number generated is 4 it triggers an encounter. The encounter will then use the put together creature from @encounters.csv and @AC.csv. Then the player will have three options: 1. Attack, wherein a random number from 1 to 20 will be generated and if the generated number is greater than or equal to the creature's armour class it counts as a hit and the encounter is defeated and the player is returned to the move menu, and if it doesn't beat the creature's armour class it moves the player to a random room. 2. Check, where the code will output the creature's armour class and lastly 3. Flee, where the player will be moved to a random room."
