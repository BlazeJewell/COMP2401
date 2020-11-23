#include "defs.h"


void initscr(){
    EntityType tmpOne = {NULL, 'T', 10, 35};
    RunnerType runnerOne = {tmpOne, "Timmy", 50, 0};

    EntityType tmpTwo = {NULL, 'H', 14, 35};
    RunnerType runnerTwo = {tmpTwo, "Harold", 50, 0};

    race->runners = {runnerOne, runnerTwo};             // add the runners to the race’s array of runners
                                                        // initialize the race’s semaphore,
                                                        // initialize the race winner to an empty string
                                                        // initialize the status row to row 4 on the screen;
    srand((unsigned)time(NULL));                        // seed the random number generator with the statement
                                                        // initialize the use of thencurseslibrary
                                                        // initialize the screen 

    pthread_t t1;
    runnerOne.ent.thr = pthread_create(&t1, NULL, goRunner, &runnerOne );
    runnerTwo.ent.thr = pthread_create(&t1, NULL, goRunner, &runnerTwo );
}   

void curs_set(int tmp){

}
void clear(){

}

void *goRunner(void* tmp){
    
    tmp = (RunnerType) * tmp;                 // type cast the parameter to be a RunnerType pointer
    while(tmp.dead != 1 && strcpy(race->winner, "")) {       
                                            // loop until either the runner reaches the top of the mountain at row 2, or the runner dies
        int movement = 0;                   // compute the runner’s next position, but don’t move the runner yet
        if (randm(100) < 70){               // with 70% probability, the new position will be a random number of steps, between 1 and 4,up the mountain, as the runner climbs up
            movement = randm(4);
        }
        else {
            movement = randm(3);            // with 30% probability, the new position will be a random number of steps, between 1 and 3,down the mountain, as the runner slides down
            tmp.health -= movement;         // if the runner moves up the mountain, they spend energy, which costs them as many healthpoints as the number of steps that they move; you must decrement their health points ac-cordingly, without going below zero
        }
        
        // check for collisions at the new position
        

        // check the runner’s health; 
        if(tmp.health < 1){
            tmp.dead = 1;               // heir dead flag is set to true
            tmp.ent.avatar = "+";       // dead hero’s avatar is permanently changed to "+" to mark their grave
                                        // the status bar is updated to indicate that the runner (using their name) has died
        }
        // actually move the runner to their new position and update the health bar
        else{
            
        }
        // set the runner’s current position to the new position
        usleep(250);                    // sleep for 250 000 microseconds

        // if the runner has not died, and if there is no current winner of the race, then our runner has won therace! update the race’s winner to be the runner’s name
    } 
       
}

void *goDorc(void* tmp){
    tmp = (EntityType) * tmp;                 // type cast the parameter to be a RunnerType pointer

    while() {                   // loop until the dorc reaches the bottom of the mountain at row 35; each iteration of the loop will dothe following
        int step = randm(5);    // the new position’s row will be a random number of steps, between 1 and 5, down the mountain
                                // the new position’s column will be be randomly determined 




        usleep(700);            // leep for 700 000 microseconds
    }
    tmp.ent.avatar = "";        // update the screen one last time to show blank spaces in the dorc’s final position, as they have nowreached the bottom of the mountain
}