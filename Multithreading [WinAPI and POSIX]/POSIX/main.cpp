/* ========================================================================================== */
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
//#include <unistd.h>
#include <Windows.h>
#include <errno.h>
#include <conio.h>
/* ========================================================================================== */
#define SLEEPING_TIME           1
#define CYCLE_COUNT             1
#define THREADS_COUNT           5 //12
#define MAX_SEM_THREAD_COUNT    2
#define RESULT_STR_SIZE         100

// Для блокировки всех потоков перед инициализацией
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t tMutex;
sem_t tSemaphore;
/* ========================================================================================== */
// Переменные состояния для потоков
pthread_cond_t wait_A = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_B = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_D = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_C = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_E = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_F = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_H = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_G = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_P = PTHREAD_COND_INITIALIZER;
pthread_cond_t wait_K = PTHREAD_COND_INITIALIZER;
/* ========================================================================================== */
// Мьютексы, используемые совместно с переменными состояния
pthread_mutex_t mutex_A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_B = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_C = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_D = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_E = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_F = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_H = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_G = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_P = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_K = PTHREAD_MUTEX_INITIALIZER;
/* ========================================================================================== */
// Потоки
pthread_t Thread_A;
pthread_t Thread_B;
pthread_t Thread_C;
pthread_t Thread_D;
pthread_t Thread_E;
pthread_t Thread_F;
pthread_t Thread_G;
pthread_t Thread_H;
pthread_t Thread_P;
pthread_t Thread_K;
pthread_t Thread_M;
pthread_t Thread_N;
// Свободны ли потоки F, H, K, P?
volatile bool free_F, free_H, free_K, free_P;
/* ========================================================================================== */
char result_str[RESULT_STR_SIZE];
/* ========================================================================================== */
int view_join_status(pthread_t Thread, const char *from_func, const char *thread_name)
{
    switch(pthread_join(Thread, NULL))
    {
    case EINVAL:
        printf("\n[%s:thread(%s)] Поток не имеет атрибут PTHREAD_CREATE_JOINABLE.\n", from_func, thread_name);
        return EINVAL;
    case ESRCH:
        printf("\n[%s:thread(%s)] Hе найден поток.\n", from_func, thread_name);
        return ESRCH;
    case 0:
        return 0;
    default:
        printf("[%s:thread(%s)] Неизвестная ошибка!", from_func, thread_name);
        return -1;
    }
}

void wait_signal(pthread_cond_t &conditional, pthread_mutex_t &mute)
{
    pthread_mutex_lock(&mute);
    pthread_cond_wait(&conditional, &mute);
    pthread_mutex_unlock(&mute);
}

void wakeup_all_threads(pthread_cond_t &conditional, pthread_mutex_t &mute)
{
    pthread_mutex_lock(&mute);
    pthread_cond_broadcast(&conditional);
    pthread_mutex_unlock(&mute);
}
/* ========================================================================================== */
void *routine_A(void *)
{
    wait_signal(cond, mutex);
    //for(int i = 0; i < CYCLE_COUNT; i++)
    {
        printf("A");
        strcat(result_str, "A");
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }

    Sleep(1);
    wakeup_all_threads(wait_A, mutex_A);
    return NULL;
}

void *routine_B(void *)
{
    wait_signal(cond, mutex);

    //for(int i = 0; i < CYCLE_COUNT + 5; i++)
    {
        printf("B");
        strcat(result_str, "B");
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }

    Sleep(1);
    wakeup_all_threads(wait_B, mutex_B);
    return NULL;
}

void *routine_C(void *)
{
    wait_signal(cond, mutex);
    wait_signal(wait_A, mutex_A);

    //for(int i = 0; i < CYCLE_COUNT + 5; i++)
    {
        pthread_mutex_lock(&tMutex);
        printf("C");
        strcat(result_str, "C");
        pthread_mutex_unlock(&tMutex);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }

    //sleep(1);
    wakeup_all_threads(wait_C, mutex_C);
    return NULL;
}

void *routine_D(void *)
{
    wait_signal(cond, mutex);
    wait_signal(wait_B, mutex_B);

    //for(int i = 0; i < CYCLE_COUNT; i++)
    {
        pthread_mutex_lock(&tMutex);
        printf("D");
        strcat(result_str, "D");
        pthread_mutex_unlock(&tMutex);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }
    //pthread_detach(Thread_D);
    //sleep(1);
    wakeup_all_threads(wait_D, mutex_D);
    return NULL;
}

void *routine_E(void *)
{
    wait_signal(cond, mutex);
    wait_signal(wait_B, mutex);

    //for(int i = 0; i < CYCLE_COUNT * 2; i++)
    {
        pthread_mutex_lock(&tMutex);
        printf("E");
        strcat(result_str, "E");
        pthread_mutex_unlock(&tMutex);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }
    //sleep(1);
    wakeup_all_threads(wait_E, mutex_E);
    return NULL;
}

void *routine_F(void *)
{
    wait_signal(cond, mutex);
    wait_signal(wait_D, mutex_D);

    //for(int i = 0; i < CYCLE_COUNT * 2; i++)
    {
        sem_wait(&tSemaphore);
        strcat(result_str, "F");
        printf("F");
        sem_post(&tSemaphore);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }
    //sleep(1);
    free_F = true;
    wakeup_all_threads(wait_F, mutex_F);
    return NULL;
}

void *routine_G(void *)
{
    wait_signal(cond, mutex);
    wait_signal(wait_E, mutex_E);

    //for(int i = 0; i < CYCLE_COUNT + 5; i++)
    {
        sem_wait(&tSemaphore);
        strcat(result_str, "G");
        printf("G");
        sem_post(&tSemaphore);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }
    //sleep(1);
    wakeup_all_threads(wait_G, mutex_G);
    return NULL;
}

void *routine_H(void *)
{
    wait_signal(cond, mutex);
    wait_signal(wait_G, mutex_G);

    //for(int i = 0; i < CYCLE_COUNT / 2.0 + 2; i++)
    {
        sem_wait(&tSemaphore);
        strcat(result_str, "H");
        printf("H");
        sem_post(&tSemaphore);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }
    //sleep(1);
    free_H = true;
    wakeup_all_threads(wait_H, mutex_H);
    return NULL;
}

void *routine_P(void *)
{
    wait_signal(cond, mutex);
    wait_signal(wait_G, mutex_G);

    //for(int i = 0; i < CYCLE_COUNT - 5; i++)
    {
        sem_wait(&tSemaphore);
        strcat(result_str, "P");
        printf("P");
        sem_post(&tSemaphore);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }
    //sleep(1);
    free_P = true;
    wakeup_all_threads(wait_P, mutex_P);
    return NULL;
}

void *routine_K(void *)
{
    wait_signal(cond, mutex);
    if (!free_H) wait_signal(wait_H, mutex_H);
    if (!free_F) wait_signal(wait_F, mutex_F);

    //for(int i = 0; i < CYCLE_COUNT; i++)
    {
        sem_wait(&tSemaphore);
        strcat(result_str, "K");
        printf("K");
        sem_post(&tSemaphore);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }
    //sleep(1);
    free_K = true;
    wakeup_all_threads(wait_K, mutex_K);
    return NULL;
}

void *routine_M(void *)
{
    wait_signal(cond, mutex);
    if (!free_H) wait_signal(wait_H, mutex_H);
    if (!free_F) wait_signal(wait_F, mutex_F);

    //for(int i = 0; i < CYCLE_COUNT * 3; i++)
    {
        sem_wait(&tSemaphore);
        strcat(result_str, "M");
        printf("M");
        sem_post(&tSemaphore);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }

    return NULL;
}

void *routine_N(void *)
{
    wait_signal(cond, mutex);
    if (!free_P) wait_signal(wait_P, mutex_P);
    if (!free_K) wait_signal(wait_K, mutex_K);

    //for(int i = 0; i < CYCLE_COUNT * 2; i++)
    {
        sem_wait(&tSemaphore);
        strcat(result_str, "N");
        printf("N");
        sem_post(&tSemaphore);
        //QTest::qSleep(SLEEPING_TIME);
        //usleep(SLEEPING_TIME);
    }

    return NULL;
}
/* ========================================================================================== */
/*
 * not sync: A, B
 * sync by mutex: C, D, E
 * sync by semaphore: F, G, H, P, K, M, N
 */
/* ========================================================================================== */
int main()
{
    /* ================================================================ */
    pthread_attr_t attrs;
    pthread_attr_init(&attrs);
    pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_JOINABLE);

    pthread_mutex_init(&tMutex, NULL);
    sem_init(&tSemaphore, NULL, MAX_SEM_THREAD_COUNT);

    free_F = free_H = free_K = free_P = false;
    /* ================================================================ */
   /* if (pthread_create(&Thread_A, &attrs, routine_A, NULL))
        printf("[main] error creating thread A.\n");

    if (pthread_create(&Thread_B, &attrs, routine_B, NULL))
        printf("[main] error creating thread B.\n");

    if (pthread_create(&Thread_C, &attrs, routine_C, NULL))
        printf("[main] error creating thread C.\n");

    if (pthread_create(&Thread_E, &attrs, routine_E, NULL))
        printf("[main] error creating thread E.\n");

    if (pthread_create(&Thread_D, &attrs, routine_D, NULL))
        printf("[main] error creating thread D.\n");

    if (pthread_create(&Thread_F, &attrs, routine_F, NULL))
        printf("[main] error creating thread F.\n");

    if (pthread_create(&Thread_G, &attrs, routine_G, NULL))
        printf("[main] error creating thread G.\n");

    if (pthread_create(&Thread_H, &attrs, routine_H, NULL))
        printf("[main] error creating thread H.\n");

    if (pthread_create(&Thread_P, &attrs, routine_P, NULL))
        printf("[main] error creating thread P.\n");

    if (pthread_create(&Thread_K, &attrs, routine_K, NULL))
        printf("[main] error creating thread K.\n");

    if (pthread_create(&Thread_N, &attrs, routine_N, NULL))
        printf("[main] error creating thread N.\n");

    if (pthread_create(&Thread_M, &attrs, routine_M, NULL))
        printf("[main] error creating thread M.\n");
/**/
	if (pthread_create(&Thread_P, &attrs, routine_P, NULL))
        printf("[main] error creating thread P.\n");

    if (pthread_create(&Thread_E, &attrs, routine_E, NULL))
        printf("[main] error creating thread E.\n");

    if (pthread_create(&Thread_H, &attrs, routine_H, NULL))
        printf("[main] error creating thread H.\n");

    if (pthread_create(&Thread_B, &attrs, routine_B, NULL))
        printf("[main] error creating thread B.\n");

    if (pthread_create(&Thread_K, &attrs, routine_K, NULL))
        printf("[main] error creating thread K.\n");

    if (pthread_create(&Thread_C, &attrs, routine_C, NULL))
        printf("[main] error creating thread C.\n");

    if (pthread_create(&Thread_A, &attrs, routine_A, NULL))
        printf("[main] error creating thread A.\n");

    if (pthread_create(&Thread_F, &attrs, routine_F, NULL))
        printf("[main] error creating thread F.\n");

    if (pthread_create(&Thread_M, &attrs, routine_M, NULL))
        printf("[main] error creating thread M.\n");

    if (pthread_create(&Thread_G, &attrs, routine_G, NULL))
        printf("[main] error creating thread G.\n");

    if (pthread_create(&Thread_D, &attrs, routine_D, NULL))
        printf("[main] error creating thread D.\n");

    if (pthread_create(&Thread_N, &attrs, routine_N, NULL))
        printf("[main] error creating thread N.\n");
    /* ================================================================ */
    Sleep(5);
    wakeup_all_threads(cond, mutex);
    /* ================================================================ */
    view_join_status(Thread_A, "main", "A");
    view_join_status(Thread_B, "main", "B");
    view_join_status(Thread_C, "main", "C");
    view_join_status(Thread_D, "main", "D");
    view_join_status(Thread_E, "main", "E");
    view_join_status(Thread_F, "main", "F");
    view_join_status(Thread_G, "main", "G");
    view_join_status(Thread_H, "main", "H");
    view_join_status(Thread_K, "main", "K");
    view_join_status(Thread_M, "main", "M");
    view_join_status(Thread_N, "main", "N");
    /* ================================================================ */
    strcat(result_str, "\0");
    printf("\n\"%s\"\n", result_str);

    pthread_mutex_destroy(&tMutex);
    /* ========================================== */
    printf("\nHello, world!\n");
	_getch();
    return 0;
}
/*
    if (pthread_create(&Thread_A, &attrs, routine_A, NULL))
        printf("[main] error creating thread A.\n");

    if (pthread_create(&Thread_B, &attrs, routine_B, NULL))
        printf("[main] error creating thread B.\n");

    if (pthread_create(&Thread_C, &attrs, routine_C, NULL))
        printf("[main] error creating thread C.\n");

    if (pthread_create(&Thread_E, &attrs, routine_E, NULL))
        printf("[main] error creating thread E.\n");

    if (pthread_create(&Thread_D, &attrs, routine_D, NULL))
        printf("[main] error creating thread D.\n");

    if (pthread_create(&Thread_F, &attrs, routine_F, NULL))
        printf("[main] error creating thread F.\n");

    if (pthread_create(&Thread_G, &attrs, routine_G, NULL))
        printf("[main] error creating thread G.\n");

    if (pthread_create(&Thread_H, &attrs, routine_H, NULL))
        printf("[main] error creating thread H.\n");

    if (pthread_create(&Thread_P, &attrs, routine_P, NULL))
        printf("[main] error creating thread P.\n");

    if (pthread_create(&Thread_K, &attrs, routine_K, NULL))
        printf("[main] error creating thread K.\n");

    if (pthread_create(&Thread_N, &attrs, routine_N, NULL))
        printf("[main] error creating thread N.\n");

    if (pthread_create(&Thread_M, &attrs, routine_M, NULL))
        printf("[main] error creating thread M.\n");
*/
