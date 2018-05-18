#include "lane.hpp"

Lane::Lane(){
    head = nullptr;
    tail = nullptr;
}

void Lane::enqueue(int ID, int arrivalTime, int serviceTime){
    if(!head){
        head = new Customer(ID, arrivalTime, serviceTime);
        tail = head;
    }else{
        tail->SetNext(new Customer(ID, arrivalTime, serviceTime));
        tail = tail->GetNext();
    }
}

Customer* Lane::dequeue(){
    if(head){
        Customer *temp = head;
        head = head->GetNext();
        return temp;
    }
    std::cout << "Queue is empty!" << std::endl;
    return nullptr;
}

Customer* Lane::peek(){
    if(head){
        return head;
    }
    return nullptr;
}

int Lane::getTotalTime(){
    if(!head){
        return 0;
    }

    Customer *temp = head;
    int totalServiceTime = 0;
    while(temp){
        totalServiceTime += temp->serviceTime;
        temp = temp->GetNext();
    }
    return totalServiceTime;
}

void Lane::updateTimes(){
    if(!head){
        return;
    }
    Customer *temp = head;
    --temp->serviceTime;
}

int Lane::getSize(){
    if(!head){
        return 0;
    }

    Customer *temp = head;
    int total = 0;
    while(temp){
        ++total;
        temp = temp->GetNext();
    }
    return total;
}
