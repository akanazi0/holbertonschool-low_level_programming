#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{
    unsigned long checksum;
    
    /* C89 Rule: All timing variables must be declared at the top! */
    clock_t total_start, total_end;
    clock_t phase_start, phase_end;
    
    double total_time;
    double build_time;
    double process_time;
    double reduce_time;

    /* Start the overarching total timer */
    total_start = clock();

    /* Phase 1: Build Dataset */
    phase_start = clock();
    build_dataset();
    phase_end = clock();
    build_time = (double)(phase_end - phase_start) / CLOCKS_PER_SEC;

    /* Phase 2: Process Dataset */
    phase_start = clock();
    process_dataset();
    phase_end = clock();
    process_time = (double)(phase_end - phase_start) / CLOCKS_PER_SEC;

    /* Phase 3: Reduce Checksum */
    phase_start = clock();
    checksum = reduce_checksum();
    phase_end = clock();
    reduce_time = (double)(phase_end - phase_start) / CLOCKS_PER_SEC;

    /* End the overarching total timer */
    total_end = clock();
    total_time = (double)(total_end - total_start) / CLOCKS_PER_SEC;

    /* Silent check provided by the curriculum */
    if (checksum == 0ul)
        printf("impossible\n");

    /* Strict Output Contract (No extra text or lines permitted) */
    printf("TOTAL seconds: %.6f\n", total_time);
    printf("BUILD_DATA seconds: %.6f\n", build_time);
    printf("PROCESS seconds: %.6f\n", process_time);
    printf("REDUCE seconds: %.6f\n", reduce_time);

    return 0;
}
