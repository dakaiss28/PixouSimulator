# PixouSimulator

Pixou loves coins ! he found himself stuck in a room with coins randomly falling from the ceiling.   
Now he wants to collect the maximum amount of coins he can.   

## Game Logic
Pixou Simulator is a 2D game developped with C++ and SFML library.      

Pixou can do 3 actions : go to the left, to the right or stay still.  
For each reward earned, Pixou gets 5 points. He also loses 5 points if the reward touches the floor.   

### Random Pixou version
In the virst version, Pixou only does random actions. He performs really poorly.

### Q-learning version
To collect as many coins as possible, Pixou is trained by reinforcement, with the Q learning algorithm. 

### States
A state gives the positions of the coins and pixou. The reduce the number of cells, the screen is divided in a grid. For each game element, we store in the state the id of the grid the element is into.  

### Q learning algorithm
  
The Q-table is dynamic, we add a line every time we have a state never seen before.   
The algorithm uses an epsilon-greed method to fill in the Q table.   
At the beginning of the game, Pixou will do a lot of random actions to discover it's environment. Later on, Pixou uses the Q-table to find the best action to do.   