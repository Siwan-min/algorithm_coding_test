#include <stdio.h>
#include <map>
#include <algorithm>
#include "windows.h"

using namespace std;

map<char*, int> stl_hash;

char input[30000][100];
int cmd[30000][2];

int my_find[30000], stl_find[30000];

const int REMOVE = 1;
const int FIND = 2;

const int PN = 23;
const int HASH_SIZE = 10000;

int name_size;
char name[30000][100];
int table[HASH_SIZE][30];

unsigned int get_key(char _name[]) {
    unsigned int key = 0, p = 1;
    for(int i = 0; _name[i] != 0; ++i) {
        key += (_name[i] * p);
        p *= PN;
    }
    return (key % HASH_SIZE);
}

int my_strcmp(char a[], char b[]) {
    int i = 0;
    while ((a[i]))
    {
        if (a[i] != b[i]) {
            break;
        }
        ++i;
    }
    return (a[i] - b[i]);
}

int contain(char _name[]) {
    unsigned int key = get_key(_name);
    int h_size = table[key][0];
    for (int i = 1; i <= h_size; ++i) {
        int n_pos = table[key][i];
        if(my_strcmp(name[n_pos], _name) == 0) {
            return n_pos;
        }
    }
    return -1;
}

void add(char _name[]) {
    int len;
    for (len = 0; _name[len] != 0; ++len){
        name[name_size][len] = _name[len];
    }
    name[name_size][len] = 0;

    unsigned int key = get_key(_name);
    int& h_size = table[key][0];
    table[key][++h_size] = name_size;

    ++name_size;
}

bool remeve(char _name[]) {
    unsigned int key = get_key(_name);
    int& h_size = table[key][0];
    for (int i = 1; i <= h_size; ++i) {
        int n_pos = table[key][i];
        if(my_strcmp(name[n_pos], _name) == 0) {
            for(int j = i + 1; i <= h_size; ++j) {
                table[key][j - 1] = table[key][j];
            }
            --h_size;
            return true;
        }
    }
    return false;
}

int make_int(int min, int max){
    return (rand() % (max - min)) + min;
}

char make_char() {
    int val = rand() % 52;
    if (val < 26) {
        return static_cast<char>('a' + val);
    }
    return static_cast<char>('A' + val - 26);
}

int main(){

    for (int i = 0; i < 30000; ++i) {
        int len = make_int(10, 100);
        for (int j = 0; j < len; ++j) {
            input[i][j] = make_char();
        }
        input[i][len] = 0;

        if ( i > 1000) {
            cmd[i][0] = rand() % 3;
            cmd[i][1] = rand() % i;
        }
    }

    int my_hash_begin = GetTickCount();
    for (int i = 0; i < 30000; ++i) {
        if (contain(input[i]) == -1) {
            add(input[i]);
        }
        if (cmd[i][0] == REMOVE) {
            if (contain(input[cmd[i][1]]) != -1) {
                remeve(input[cmd[i][1]]);
            }
        }
        if (cmd[i][0] == FIND) {
            my_find[i] = contain(input[cmd[i][1]]);
        }
    }
    int my_hash_end = GetTickCount();

    int stl_hash_begin = GetTickCount();
    for (int i = 0; i < 30000; ++i) {
        stl_hash[input[i]] = i;

        if (cmd[i][0] == REMOVE) {
            stl_hash.erase(input[cmd[i][1]]);
        }
        if (cmd[i][0] == FIND) {
            map<char*, int>::iterator iter = stl_hash.find(input[cmd[i][1]]);
            stl_find[i] = -1;
            if (iter != stl_hash.end()) {
                stl_find[i] = iter->second;
            }
        }
    }
    int stl_hash_end = GetTickCount();

    int my_hash_size = 0;
    for (int i = 0; i < HASH_SIZE; ++i) {
        my_hash_size += table[i][0];
    } 

    if (my_hash_size != stl_hash.size()) {
        printf("hash size is not same!!\n");
    } 
    for (int i = 0; i < 30000; ++i) {
        if (my_find[i] != stl_find[i]) {
            printf("hash find function is error!!\n");
        }
    }


    printf("my hash time : %d\n", (my_hash_end - my_hash_begin));
    printf("stl hash time : %d\n", (stl_hash_end - stl_hash_begin));

    return 0;
}