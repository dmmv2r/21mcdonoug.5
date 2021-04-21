#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <sys/types.h>

using namespace std;

enum Status {CLAIM, TERM, REQ, REL};

typedef struct {
   int pid;
   Status status;

   pid_t realpid;
}Data;

struct pcbbuf {
   long mtype;
   Data data;
};

void* createshm(size_t bytes, int& key_id);

void* findshm(int key_id);
void detachshm(const void* ptr);
void destroyshm(int key_id);

int createsem(int num, int& key_id);
int findsem(int key_id);
void locksem(int semid, int semnum);
void unlocksem(int semid, int semnum);
void unlockall(int semid, int size);
void lockall(int semid, int size);
void destroysem(int semid);

void createmsg(int& key_id);
void findmsg(int key_id);
void sendmsg(int key_id);
void sendmsg(int key_id, int mtype);
void sendmsg(int key_id, pcbbuf* buf);
void getmsg(int key_id);
void getmsg(int key_id, int mtype);
void getmsg(int key_id, pcbbuf* buf);
bool getmsgb(int key_id);
bool getmsgb(int key_id, int mtype);
bool getmsgb(int key_id, pcbbuf* buf);

void ipccleanup();

#endif
