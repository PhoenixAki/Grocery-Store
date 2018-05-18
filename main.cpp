#include <iostream>
#include "customer.hpp"
#include "lane.hpp"
#include <time.h>

int main() {
    //Initialize random seed to time(NULL) to guarantee randomness each time the simulation is ran.
    srand(time(NULL));
    Lane *laneOne = new Lane(), *laneTwo = new Lane(), *laneThree = new Lane();
    int currentTime = 1, nextArrival = ((rand() % 4) + 2), serviceTime = ((rand() % 4) + 2), customerCount = 0;
    int laneOneMax = 0, laneTwoMax = 0, laneThreeMax = 0;

    while(currentTime <= 720){
        std::cout << "MINUTE " << currentTime << std::endl << "----------" << std::endl;
		
        laneOne->updateTimes();
        laneTwo->updateTimes();
        laneThree->updateTimes();

        //Pointers to first customer in each line
        Customer *oneFirst = laneOne->peek(), *twoFirst = laneTwo->peek(), *threeFirst = laneThree->peek();

        //Checking each lane for customer exits
        if(laneOne->getSize() != 0 && oneFirst->serviceTime == 0){
            std::cout << "Customer " << oneFirst->ID << " --- exited lane 1 after spending " << currentTime - oneFirst->arrivalTime << " minutes in the lane." << std::endl;
            laneOne->dequeue();
        }
        if(laneTwo->getSize() != 0 && twoFirst->serviceTime == 0){
            std::cout << "Customer " << twoFirst->ID << " --- exited lane 2 after spending " << currentTime - twoFirst->arrivalTime << " minutes in the lane." << std::endl;
            laneTwo->dequeue();
        }
        if(laneThree->getSize() != 0 && threeFirst->serviceTime == 0){
            std::cout << "Customer " << threeFirst->ID << " --- exited lane 3 after spending " << currentTime - threeFirst->arrivalTime << " minutes in the lane." << std::endl;
            laneThree->dequeue();
        }

        if(currentTime == nextArrival){
            ++customerCount;
            serviceTime = ((rand() % 4) + 2);
            std::cout << "Customer " << customerCount << " --- has arrived at time " << currentTime << "." << std::endl;

			//Enqueues new customer into ideal lane (shortest total service time)
            if(laneOne->getTotalTime() + serviceTime <= laneTwo->getTotalTime() + serviceTime && laneOne->getTotalTime() + serviceTime <= laneThree->getTotalTime() + serviceTime){
                laneOne->enqueue(customerCount, nextArrival, serviceTime);
                std::cout << "Customer " << customerCount << " --- entered lane one at " << currentTime << " with a service time of " << serviceTime << " minutes." << std::endl;
            }else if(laneTwo->getTotalTime() + serviceTime <= laneOne->getTotalTime() + serviceTime && laneTwo->getTotalTime() + serviceTime <= laneThree->getTotalTime() + serviceTime){
                laneTwo->enqueue(customerCount, nextArrival, serviceTime);
                std::cout << "Customer " << customerCount << " --- entered lane two at " << currentTime << " with a service time of " << serviceTime <<  " minutes." << std::endl;
            }else if(laneThree->getTotalTime() + serviceTime <= laneOne->getTotalTime() + serviceTime && laneThree->getTotalTime() + serviceTime <= laneTwo->getTotalTime() + serviceTime){
                laneThree->enqueue(customerCount, nextArrival, serviceTime);
                std::cout << "Customer " << customerCount << " --- entered lane three at " << currentTime << " with a service time of " << serviceTime << " minutes." << std::endl;
            }
            nextArrival = ((rand() % 4) + 2) + currentTime;
        }
		
		//Update maximums
        if(laneOne->getSize() > laneOneMax){
            laneOneMax = laneOne->getSize();
        }
        if(laneTwo->getSize() > laneTwoMax){
            laneTwoMax = laneTwo->getSize();
        }
        if(laneThree->getSize() > laneThreeMax){
            laneThreeMax = laneThree->getSize();
        }

        std::cout << std::endl;
        ++currentTime;
    }
    std::cout << "Maximum number of customers in lane 1 at a time: " << laneOneMax << std::endl;
    std::cout << "Maximum number of customers in lane 2 at a time: " << laneTwoMax << std::endl;
    std::cout << "Maximum number of customers in lane 3 at a time: " << laneThreeMax << std::endl;
}