#include "hashTable.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

person_t* hashTableArray[TABLE_SIZE];

unsigned int hash(char* _name){
    // if (_name==NULL){
    //     return -1;
    // }
    int length = strnlen(_name, MAX_SIZE);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += _name[i];
        hash_value = (hash_value*_name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void initHashTable(){
    for(int i=0;i<TABLE_SIZE;i++){
        hashTableArray[i] = NULL;
    }
}

void printHashTable(){
    printf("Start\n");
    for(int i=0;i<TABLE_SIZE;i++){
        if(hashTableArray[i] == NULL){
            printf("\t%i\t---\n", i);
        }
        else{
            printf("\t%i\t%s\n", i, hashTableArray[i]->name);
        }
    }
    printf("End\n");
}

bool htInsert(person_t* _person){
    if (_person==NULL){
        return false;
    }
    unsigned int index = hash(_person->name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if(hashTableArray[try] == NULL) {
            hashTableArray[try] = _person;
            return true;
        }
    }
    return false;
}

person_t* htSearchPerson(char* _name){
    unsigned int indx = hash(_name);
    if (hashTableArray[indx]!=NULL && strncmp(hashTableArray[indx]->name, _name, TABLE_SIZE)==0){
        return hashTableArray[indx];
    }
    else{
        return NULL;
    }
}

person_t* htDeletePerson(char* _name){
    unsigned int indx = hash(_name);
    if (hashTableArray[indx]!=NULL && strncmp(hashTableArray[indx]->name, _name, TABLE_SIZE)==0){
        person_t* tmp = hashTableArray[indx];
        hashTableArray[indx] = NULL;
        return tmp;
    }
    else{
        return NULL;
    }
}
